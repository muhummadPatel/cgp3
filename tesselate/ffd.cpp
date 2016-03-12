//
// ffd
//

#include "ffd.h"
#include <stdio.h>
#include <math.h>

using namespace std;

GLfloat defaultLatCol[] = {0.2f, 0.2f, 0.2f, 1.0f};
GLfloat highlightLatCol[] = {1.0f, 0.176f, 0.176f, 1.0f};
int maxbezorder = 4;

void ffd::alloc()
{
    // allocate memory for a 3D array of control points and highlighting switches
    if(dimx > 1 && dimy > 1 && dimz > 1 && dimx <= maxbezorder && dimy <= maxbezorder && dimz <= maxbezorder)
    {
        cp = new cgp::Point **[dimx];
        highlight = new bool **[dimx];
        for (int i = 0; i < dimx; i++)
        {
            cp[i] = new cgp::Point *[dimy];
            highlight[i] = new bool *[dimy];

            for (int j = 0; j < dimy; j++)
            {
                cp[i][j] = new cgp::Point[dimz];
                highlight[i][j] = new bool[dimz];
            }
        }
        deactivateAllCP();
    }
}

void ffd::dealloc()
{
    // deallocate 3D array of control points and boolean highlighting switches
    for (int i = 0; i < dimx; i++)
    {
        for (int j = 0; j < dimy; j++)
        {
            delete [] cp[i][j];
            delete [] highlight[i][j];
        }

        delete [] cp[i];
        delete [] highlight[i];
    }
    delete [] cp;
    delete [] highlight;
    cp = NULL;
}

bool ffd::inCPBounds(int i, int j, int k)
{
    return (i >= 0 && j >= 0 && k >= 0 && i < dimx && j < dimy && k < dimz);
}

ffd::ffd()
{
    dimx = dimy = dimz = 0;
    setFrame(cgp::Point(0.0f, 0.0f, 0.0f), cgp::Vector(0.0f, 0.0f, 0.0f));
    cp = NULL;
    highlight = NULL;
}

ffd::ffd(int xnum, int ynum, int znum, cgp::Point corner, cgp::Vector diag)
{
    dimx = xnum;
    dimy = ynum;
    dimz = znum;
    setFrame(corner, diag);
    alloc();
}

void ffd::reset()
{
    cgp::Vector uniS(diagonal.i, 0.0f, 0.0f);
    cgp::Vector uniT(0.0f, diagonal.j, 0.0f);
    cgp::Vector uniU(0.0f, 0.0f, diagonal.k);

    float l = dimx-1;
    float m = dimy-1;
    float n = dimz-1;
    for(int k = 0; k < dimz; k++)
    for(int j = 0; j < dimy; j++)
    for(int i = 0; i < dimx; i++){
        cp[i][j][k] = origin;
        cp[i][j][k].x += ((i/l) * uniS.i) + ((j/m) * uniT.i) + ((k/n) * uniU.i);
        cp[i][j][k].y += ((i/l) * uniS.j) + ((j/m) * uniT.j) + ((k/n) * uniU.j);
        cp[i][j][k].z += ((i/l) * uniS.k) + ((j/m) * uniT.k) + ((k/n) * uniU.k);
    }
}

void ffd::getDim(int &numx, int &numy, int &numz)
{
    numx = dimx; numy = dimy; numz = dimz;
}

void ffd::setDim(int numx, int numy, int numz)
{
    dimx = numx; dimy = numy; dimz = numz;
    alloc();
    reset();
}

void ffd::getFrame(cgp::Point &corner, cgp::Vector &diag)
{
    corner = origin;
    diag = diagonal;
}

void ffd::setFrame(cgp::Point corner, cgp::Vector diag)
{
    origin = corner;
    diagonal = diag;
    reset();
}

void ffd::activateCP(int i, int j, int k)
{
    if(inCPBounds(i,j,k))
        highlight[i][j][k] = true;
}

void ffd::deactivateCP(int i, int j, int k)
{
    if(inCPBounds(i,j,k))
        highlight[i][j][k] = false;
}

void ffd::deactivateAllCP()
{
    for(int i = 0; i < dimx; i++)
        for(int j = 0; j < dimy; j++)
            for(int k = 0; k < dimz; k++)
                highlight[i][j][k] = false;
}

bool ffd::bindGeometry(View * view, ShapeDrawData &sdd, bool active)
{
    int i, j, k;
    glm::mat4 tfm, idt;
    glm::vec3 trs;
    cgp::Point pnt;
    bool draw;

    if(active)
    {
        activegeom.clear();
        activegeom.setColour(highlightLatCol);
    }
    else
    {
        geom.clear();
        geom.setColour(defaultLatCol);
    }

    idt = glm::mat4(1.0f); // identity matrix

    // place a sphere at non-active control point positions with appropriate colour
    for(i = 0; i < dimx; i++)
        for(j = 0; j < dimy; j++)
            for(k = 0; k < dimz; k++)
            {
                if(active) // only draw those control points that match active flag
                    draw = highlight[i][j][k];
                else
                    draw = !highlight[i][j][k];

                if(draw)
                {
                    pnt = cp[i][j][k];
                    trs = glm::vec3(pnt.x, pnt.y, pnt.z);
                    tfm = glm::translate(idt, trs);
                    if(active)
                        activegeom.genSphere(0.4, 10, 10, tfm);
                    else
                        geom.genSphere(0.4, 10, 10, tfm);
                }
            }

    // bind geometry to buffers and return drawing parameters, if possible
    if(active)
    {
        if(activegeom.bindBuffers(view))
        {
            sdd = activegeom.getDrawParameters();
            return true;
        }
        else
            return false;
    }
    else
    {
        if(geom.bindBuffers(view))
        {
            sdd = geom.getDrawParameters();
            return true;
        }
        else
            return false;
    }
}

cgp::Point ffd::getCP(int i, int j, int k)
{
    if(inCPBounds(i,j,k))
    {
        return cp[i][j][k];
    }
    else
    {
        cerr << "Error ffd::getCP: out of bounds access to lattice" << endl;
        return cgp::Point(0.0f, 0.0f, 0.0f);
    }
}

void ffd::setCP(int i, int j, int k, cgp::Point pnt)
{
    if(inCPBounds(i,j,k))
        cp[i][j][k] = pnt;
}

int choose(int n, int k){
    if(k == 0)
        return 1;

    return (n * choose(n - 1, k - 1)) / k;
}

void ffd::deform(cgp::Point & pnt)
{
    cgp::Vector uniS(diagonal.i, 0.0f, 0.0f);
    cgp::Vector uniT(0.0f, diagonal.j, 0.0f);
    cgp::Vector uniU(0.0f, 0.0f, diagonal.k);

    cgp::Vector XminX0;
    XminX0.diff(origin, pnt);

    cgp::Vector TcrossU;
    TcrossU.cross(uniT, uniU);
    float s = (TcrossU.dot(XminX0)) / (TcrossU.dot(uniS));

    cgp::Vector ScrossU;
    ScrossU.cross(uniS, uniU);
    float t = (ScrossU.dot(XminX0)) / (ScrossU.dot(uniT));

    cgp::Vector ScrossT;
    ScrossT.cross(uniS, uniT);
    float u = (ScrossT.dot(XminX0)) / (ScrossT.dot(uniU));

    cgp::Point xSum(0.0f, 0.0f, 0.0f);
    for(int x = 0; x < dimx; x++){
        cgp::Point ySum(0.0f, 0.0f, 0.0f);
        for(int y = 0; y < dimy; y++){
            cgp::Point zSum(0.0f, 0.0f, 0.0f);
            for(int z = 0; z < dimz; z++){
                float zfact = choose(dimz-1, z) * pow((1 - u), ((dimz-1) - z)) * pow(u, z);

                zSum.x += zfact * cp[x][y][z].x;
                zSum.y += zfact * cp[x][y][z].y;
                zSum.z += zfact * cp[x][y][z].z;
            }

            float yfact = choose(dimy-1, y) * pow((1 - t), ((dimy-1) - y)) * pow(t, y);

            ySum.x += yfact * zSum.x;
            ySum.y += yfact * zSum.y;
            ySum.z += yfact * zSum.z;
        }

        float xfact = choose(dimx-1, x) * pow((1 - s), ((dimx-1) - x)) * pow(s, x);

        xSum.x += xfact * ySum.x;
        xSum.y += xfact * ySum.y;
        xSum.z += xfact * ySum.z;
    }

    pnt = xSum;
}

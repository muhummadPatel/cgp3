#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <test/testutil.h>
#include "test_mesh.h"
#include <stdio.h>
#include <cstdint>
#include <sstream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

void TestMesh::setUp()
{
    mesh = new Mesh();
}

void TestMesh::tearDown()
{
    delete mesh;
}

void TestMesh::testMeshing()
{

    mesh->readSTL("../meshes/bunny.stl");
    CPPUNIT_ASSERT(mesh->basicValidity());
    CPPUNIT_ASSERT(!mesh->manifoldValidity()); // bunny has known holes in the bottom
    cerr << "BUNNY TEST PASSED" << endl << endl;

    // test simple valid 2-manifold
    mesh->validTetTest();
    CPPUNIT_ASSERT(mesh->basicValidity());
    CPPUNIT_ASSERT(mesh->manifoldValidity());
    cerr << "SIMPLE VALIDITY TEST PASSED" << endl << endl;

    // test for duplicate vertices, dangling vertices and out of bounds on vertex indices
    mesh->basicBreakTest();
    CPPUNIT_ASSERT(!mesh->basicValidity());
    cerr << "BASIC INVALID MESH DETECTED CORRECTLY" << endl << endl;

    // test for 2-manifold with boundary
    mesh->openTetTest();
    CPPUNIT_ASSERT(mesh->basicValidity());
    CPPUNIT_ASSERT(!mesh->manifoldValidity());
    cerr << "INVALID MESH WITH BOUNDARY DETECTED CORRECTLY" << endl << endl;

    // test for non 2-manifold failure where surfaces touch at a single vertex
    mesh->touchTetsTest();
    CPPUNIT_ASSERT(mesh->basicValidity());
    CPPUNIT_ASSERT(!mesh->manifoldValidity());
    cerr << "INVALID PINCHED SURFACE TEST PASSED" << endl << endl;

    // test for non 2-manifold overlapping triangles
    mesh->overlapTetTest();
    CPPUNIT_ASSERT(mesh->basicValidity());
    CPPUNIT_ASSERT(!mesh->manifoldValidity());
    cerr << "INVALID NON-2-MANIFOLD DETECTED CORRECTLY" << endl << endl;

}

void TestMesh::testSmoothing(){
    std::vector<cgp::Point> expected_smoothed_verts = {
        cgp::Point(0.5f, 0.5f, 0.33f),
        cgp::Point(0.5f, 0.5f, 0.33f),
        cgp::Point(0.5f, 0.5f, 0.33f),
        cgp::Point(0.5f, 0.5f, 0.33f)
    };

    mesh->validTetTest();

    mesh->laplacianSmooth(6, 1);

    for(int i = 0; i < mesh->verts.size(); i++){
        CPPUNIT_ASSERT_DOUBLES_EQUAL(expected_smoothed_verts[i].x, mesh->verts[i].x, 0.01f);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(expected_smoothed_verts[i].y, mesh->verts[i].y, 0.01f);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(expected_smoothed_verts[i].z, mesh->verts[i].z, 0.01f);
    }

    cerr << "MESH SMOOTHING PASSED" << endl << endl;
}

void TestMesh::testMarchingCubes(){
    float voxlen = 5.0f;
    cgp::Vector voldiag(10.0f, 10.0f, 10.0f);
    int xdim = ceil(voldiag.i / voxlen)+2; // needs a 1 voxel border to ensure a closed mesh
    int ydim = ceil(voldiag.j / voxlen)+2;
    int zdim = ceil(voldiag.k / voxlen)+2;
    cgp::Vector voxdiag = cgp::Vector((float) xdim * voxlen, (float) ydim * voxlen, (float) zdim * voxlen);
    cgp::Point voxorigin = cgp::Point(-0.5f*voxdiag.i, -0.5f*voxdiag.j, -0.5f*voxdiag.k);

    VoxelVolume* vox = new VoxelVolume();
    vox->setDim(xdim, ydim, zdim);
    vox->setFrame(voxorigin, voxdiag);
    vox->fill(false);
    vox->set(0, 0, 0, true);

    mesh->marchingCubes(*vox);

    CPPUNIT_ASSERT(mesh->verts.size() == 1);
    CPPUNIT_ASSERT(mesh->tris.size() == 1);

    cerr << "MESH MARCHING CUBES PASSED" << endl << endl;
}

//#if 0 /* Disabled since it crashes the whole test suite */
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestMesh, TestSet::perBuild());
//#endif

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <test/testutil.h>
#include "test_ffd.h"
#include <stdio.h>
#include <cstdint>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

void TestFFD::setUp()
{
    lat = new ffd();
    lat->setDim(3,3,3);
    lat->setFrame(cgp::Point(-10.0f, -10.0f, -10.0f), cgp::Vector(20.0f, 20.0f, 20.0f));
    lat->activateCP(0,0,0);
    lat->reset();
}

void TestFFD::tearDown()
{
    delete lat;
}

void TestFFD::testApplyUndeformedLattice(){
    // point to be deformed
    cgp::Point pnt(1.0f, 1.0f, 1.0f);

    // try to deform the point without having touched any control points in the lattice
    lat->deform(pnt);

    // the point should now be at the same position it started in (1, 1, 1)
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0f, pnt.x, 0.0001f);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0f, pnt.y, 0.0001f);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.0f, pnt.z, 0.0001f);

    cerr << "FFD APPLY UNDEFORMED LATTICE PASSED" << endl << endl;
}

void TestFFD::testApplyDeformedLattice(){
    // point to be deformed
    cgp::Point pnt(1.0f, 1.0f, 1.0f);

    // move a control point and apply tho deformation
    cgp::Point cp1 = lat->getCP(0, 0, 0);
    cp1.x += 15;
    cp1.y += 15;
    cp1.z += 15;
    lat->setCP(0, 0, 0, cp1);
    lat->deform(pnt);

    // the point should be in it's correct new deformed position
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.125f, pnt.x, 0.001f);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.125f, pnt.y, 0.001f);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(1.125f, pnt.z, 0.001f);

    cerr << "FFD APPLY DEFORMED LATTICE PASSED" << endl << endl;
}

//#if 0 /* Disabled since it crashes the whole test suite */
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestFFD, TestSet::perBuild());
//#endif

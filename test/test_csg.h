#ifndef TILER_TEST_CSG_H
#define TILER_TEST_CSG_H


#include <string>
#include <cppunit/extensions/HelperMacros.h>
#include "tesselate/csg.h"

/// Test code for @ref VoxelVolume
class TestCSG : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestCSG);
    CPPUNIT_TEST(testSimpleCSG);
    CPPUNIT_TEST_SUITE_END();

private:
    Scene * csg;

public:

    /// Initialization before unit tests
    void setUp();

    /// Tidying up after unit tests
    void tearDown();

    /** 
     * Run simple set and get validity tests on voxels
     */
    void testSimpleCSG();
};

#endif /* !TILER_TEST_CSG_H */

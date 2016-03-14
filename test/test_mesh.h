#ifndef TILER_TEST_MESH_H
#define TILER_TEST_MESH_H


#include <string>
#include <cppunit/extensions/HelperMacros.h>

#define private public
#include "tesselate/mesh.h"
#define private private

/// Test code for @ref Mesh
class TestMesh : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestMesh);
    CPPUNIT_TEST(testMeshing);
    CPPUNIT_TEST(testSmoothing);
    CPPUNIT_TEST(testMarchingCubes);
    CPPUNIT_TEST_SUITE_END();

private:
    Mesh * mesh;

public:

    /// Initialization before unit tests
    void setUp();

    /// Tidying up after unit tests
    void tearDown();

    /**
     * Run standard validity tests on bunny mesh
     * @pre bunny.stl must be located in the project root directory
     */
    void testMeshing();

    void testSmoothing();

    void testMarchingCubes();
};

#endif /* !TILER_TEST_MESH_H */

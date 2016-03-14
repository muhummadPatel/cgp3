#ifndef TILER_TEST_FFD_H
#define TILER_TEST_FFD_H


#include <string>
#include <cppunit/extensions/HelperMacros.h>
#include "tesselate/ffd.h"

/// Test code for @ref ffd
class TestFFD : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestFFD);
    CPPUNIT_TEST(testApplyUndeformedLattice);
    CPPUNIT_TEST(testApplyDeformedLattice);
    CPPUNIT_TEST_SUITE_END();

private:
    ffd* lat;

public:

    /// Initialization before unit tests
    void setUp();

    /// Tidying up after unit tests
    void tearDown();

    /**
     * Tests that applying the undeformed lattice doesn't move the point
     */
    void testApplyUndeformedLattice();

    /**
     * Tests that applying a deformed lattice moves the point correctly
     */
    void testApplyDeformedLattice();
};

#endif /* !TILER_TEST_FFD_H */

/* 
 * File:   PfadSucherTest.h
 * Author: stadie
 *
 * Created on 6. Oktober 2015, 13:54
 */

#ifndef PFADSUCHERTEST_H
#define	PFADSUCHERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class PfadSucherTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PfadSucherTest);
    CPPUNIT_TEST(testKoordinaten);
    CPPUNIT_TEST(testKoordinate2);
    CPPUNIT_TEST_SUITE_END();

public:
    PfadSucherTest();
    virtual ~PfadSucherTest();
    void setUp();
    void tearDown();

private:
    int *example;
    void testKoordinaten();
    void testKoordinate2();
};

#endif	/* PFADSUCHERTEST_H */


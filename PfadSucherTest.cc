/* 
 * File:   PfadSucherTest.cc
 * Author: stadie
 * 
 * Created on 6. Oktober 2015, 13:54
 */

#include "PfadSucherTest.h"
#include "Koordinate.hh"

CPPUNIT_TEST_SUITE_REGISTRATION(PfadSucherTest);

PfadSucherTest::PfadSucherTest() {
}

PfadSucherTest::~PfadSucherTest() {
}

void PfadSucherTest::setUp() {
    this->example = new int(1);
}

void PfadSucherTest::tearDown() {
    delete this->example;
}

void PfadSucherTest::testKoordinaten() {
    Koordinate k12(1,2);
    CPPUNIT_ASSERT(k12 == k12);
}

void PfadSucherTest::testKoordinate2() {
	Koordinate k12(1,2);
    CPPUNIT_ASSERT(!(k12 != k12));
}

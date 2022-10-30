/**************************************************************************\
* Copyright (c) Kongsberg Oil & Gas Technologies AS
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#define BOOST_TEST_NO_LIB 1
#include <boost/test/unit_test.hpp>
#include <boost/intrusive_ptr.hpp>
#include <cassert>
#include <cstdio>
#include <iostream>
#include "TestSuiteUtils.h"
#include "TestSuiteMisc.h"
using namespace SIM::Coin3D::Coin;
using namespace SIM::Coin3D::Coin::TestSuite;



#include <Inventor/SbRotation.h>
#include <Inventor/SbTypeInfo.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/SbVec4f.h>
#include <boost/lexical_cast.hpp>
#include <cassert>
#include <cstdio>
BOOST_AUTO_TEST_SUITE(SbRotation_TestSuite);


typedef SbRotation ToTest;
BOOST_AUTO_TEST_CASE(operatorBrackets)
{
  const int FLOAT_SENSITIVITY = 1;
  const float SQRT2 = sqrt(2.f)/2.f;
  SbRotation rot(0,-SQRT2,0,SQRT2);

  for (int i=0;i<4;++i) {
    int premultiply = ((i&0x1)*((i&0x2)-1));
    float testVal = premultiply*SQRT2;
    BOOST_CHECK_MESSAGE(
                        floatEquals(testVal,rot[i],FLOAT_SENSITIVITY),
                        std::string("Wrong value when trying to access value #")
                        + boost::lexical_cast<std::string>(i)
                        + ": "
                        + boost::lexical_cast<std::string>(rot[i]) +
                        " == "
                        + boost::lexical_cast<std::string>(testVal)
                        );
  }
}

BOOST_AUTO_TEST_CASE(toString) {
  ToTest val(SbVec3f(0, -1, 0),  1);
  SbString str("0 -1 0  1");
  SbVec4f expected(0.f, -1.f, 0.f, 1.f), actual;
  sscanf(val.toString().getString(), "%f %f %f  %f", &actual[0], &actual[1], &actual[2], &actual[3]);
  BOOST_CHECK_MESSAGE(actual.equals(expected, 0.000001f),
                      std::string("Mismatch between ") +  val.toString().getString() + " and control string " + str.getString());

}

BOOST_AUTO_TEST_CASE(fromString) {
  ToTest foo;
  SbString test = "0 -1 0 1";
  ToTest trueVal(SbVec3f(0, -1, 0),  1);
  SbBool conversionOk = foo.fromString(test);
  BOOST_CHECK_MESSAGE(conversionOk && trueVal == foo,
                      std::string("Mismatch between ") +  foo.toString().getString() + " and control " + trueVal.toString().getString());
}

BOOST_AUTO_TEST_CASE(fromInvalidString) {
  ToTest foo;
  SbString test = "2.- 2 3 4";
  ToTest trueVal(1,2,3,4);
  SbBool conversionOk = foo.fromString(test);
  BOOST_CHECK_MESSAGE(conversionOk == FALSE,
                      std::string("Able to convert from ") + test.getString() + " which is not a valid " + SbTypeInfo<ToTest>::getTypeName() + " representation");
}


BOOST_AUTO_TEST_SUITE_END();

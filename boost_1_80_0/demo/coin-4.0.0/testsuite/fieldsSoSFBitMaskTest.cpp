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


#include <Inventor/fields/SoSFBitMask.h>
#include <Inventor/SbName.h>
BOOST_AUTO_TEST_SUITE(SoSFBitMask_TestSuite);


BOOST_AUTO_TEST_CASE(initialized)
{
  SoSFBitMask field;
  BOOST_CHECK_MESSAGE(SoSFBitMask::getClassTypeId() != SoType::badType(),
                      "SoSFBitMask class not initialized");
  BOOST_CHECK_MESSAGE(field.getTypeId() != SoType::badType(),
                      "SoSFBitMask class not initialized");
}

// BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(textinput, 1)

BOOST_AUTO_TEST_CASE(textinput)
{
  enum Values { VALUE1 = 0x01, VALUE2 = 0x02, VALUE3 = 0x04 };
  enum Other { OTHER1 = 0x01, OTHER2 = 0x02, OTHER3 = 0x04 };

  SbBool ok;

  SbName names1[3] = { SbName("VALUE1"), SbName("VALUE2"), SbName("VALUE3") };
  int values1[3] = { 0x01, 0x02, 0x04 };

  SbName names2[3] = { SbName("OTHER1"), SbName("OTHER2"), SbName("OTHER3") };
  int values2[3] = { 0x01, 0x02, 0x04 };

  SoSFBitMask field1, field2, field3;

  field1.setEnums(3, values1, names1);
  field2.setEnums(3, values1, names1);
  field3.setEnums(3, values2, names2);

  TestSuite::ResetReadErrorCount();
  static const char * filters[] = { "Unknown SoSFBitMask bit mask value", NULL };
  TestSuite::PushMessageSuppressFilters(filters);
  ok = field1.set("OTHER1"); // should output error
  BOOST_CHECK_MESSAGE(ok == FALSE, "accepted 'OTHER1' erroneously");
  TestSuite::PopMessageSuppressFilters();
  BOOST_CHECK_EQUAL(TestSuite::GetReadErrorCount(), 1);
  TestSuite::ResetReadErrorCount();

  ok = field1.set("VALUE2");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'VALUE2'");
  ok = field2.set("VALUE2");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'VALUE2'");
  BOOST_CHECK_EQUAL(field1.getValue(), field2.getValue());
  BOOST_CHECK_MESSAGE(field1.isSame(field2), "SoSFBitmask.isSame() problem");

  ok = field1.set("VALUE2");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'VALUE2'");
  ok = field2.set("(VALUE1|VALUE3)");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept '(VALUE1|VALUE3)'");
  BOOST_CHECK_EQUAL(field2.getValue(), VALUE1|VALUE3);
  BOOST_CHECK_MESSAGE(!field2.isSame(field1), "SoSFBitmask.isSame() problem");

  // failing test, but unclear if it is required to work
  ok = field2.set("VALUE1|VALUE3"); // this ought to work too, right?
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'VALUE1|VALUE2'");
  //BOOST_CHECK_EQUAL(field2.getValue(), VALUE1|VALUE3);

  // FIXME: try to read the same from a file?
  // Solving this would go into the math-parsing problem?

  ok = field1.set("VALUE2");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'VALUE2'");
  ok = field3.set("OTHER2");
  BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept 'OTHER2'");
  BOOST_CHECK_EQUAL(field1.getValue(), field3.getValue());
  BOOST_CHECK_MESSAGE(!field1.isSame(field3), "SoSFBitmask.isSame() false positive");

  // Numeric values don't work.
  //ok = field1.set("0");
  //BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept '0'");
  //BOOST_CHECK_MESSAGE(field1.getValue() == 0, "did not set value to 0");
  //ok = field1.set("1");
  //BOOST_CHECK_MESSAGE(ok == TRUE, "did not accept '1'");
  //BOOST_CHECK_MESSAGE(field1.getValue() == 1, "did not set value to 1");
}


BOOST_AUTO_TEST_SUITE_END();

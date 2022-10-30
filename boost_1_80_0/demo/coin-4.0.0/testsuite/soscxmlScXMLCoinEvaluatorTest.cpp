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


#include <Inventor/scxml/ScXMLCoinEvaluator.h>
#include <cmath>
#include <cfloat>
#include <boost/scoped_ptr.hpp>
#include <Inventor/scxml/ScXMLStateMachine.h>
BOOST_AUTO_TEST_SUITE(ScXMLCoinEvaluator_TestSuite);


// FIXME: this is no longer possible in the MinimumEvaluator - move testcase to
// the CoinEvaluator.

template<class EXPECTED_TYPE>
struct DataObjDemangler {
};

template<>
struct DataObjDemangler<ScXMLRealDataObj> {
  typedef double RET_VAL;
  static RET_VAL getValue(ScXMLRealDataObj * obj) {
    return obj->getReal();
  }
};

template<>
struct DataObjDemangler<ScXMLBoolDataObj> {
  typedef bool RET_VAL;
  static RET_VAL getValue(ScXMLBoolDataObj * obj) {
    return obj->getBool();
  }
};

#define COIN_REQUIRE_MESSAGE( P , M) \
  BOOST_REQUIRE_MESSAGE(P , M);      \
  if (!(P))                          \
    return false;


template <class EXPECTED_TYPE>
bool
TestReturnValue(const std::string & evaluationString, typename DataObjDemangler< EXPECTED_TYPE >::RET_VAL retVal, boost::scoped_ptr<ScXMLEvaluator> & evaluator)
{
  ScXMLDataObj * res = NULL;


  res = evaluator->evaluate(evaluationString.c_str());
  COIN_REQUIRE_MESSAGE(res != NULL, std::string("Evaluation returned nothing for expression: ") + evaluationString);
  //FIXME: Should really remember to delete res before returning from this point on,
  //but don't bother about a memory leak when there are bigger fish to
  //fry. 20090613 BFG
  COIN_REQUIRE_MESSAGE(res->getTypeId() == EXPECTED_TYPE::getClassTypeId(), std::string("The type returned was incorrect for expression: ") + evaluationString);
  EXPECTED_TYPE * obj = static_cast<EXPECTED_TYPE *>(res);
  COIN_REQUIRE_MESSAGE(DataObjDemangler<EXPECTED_TYPE>::getValue(obj) == retVal, std::string("Return value mismatch for expression: ") + evaluationString);

  delete res;
  return true;
}


BOOST_AUTO_TEST_CASE(BasicExpressions)
{
  boost::scoped_ptr<ScXMLStateMachine> sm(new ScXMLStateMachine);
  boost::scoped_ptr<ScXMLEvaluator> evaluator(new ScXMLCoinEvaluator);
  evaluator->setStateMachine(sm.get());

  TestReturnValue<ScXMLRealDataObj>("M_PI",M_PI,evaluator);
  TestReturnValue<ScXMLRealDataObj>("5.0",5.0,evaluator);
  TestReturnValue<ScXMLRealDataObj>("5 + 5",10.0,evaluator);
  TestReturnValue<ScXMLRealDataObj>("5 - 4",1.0,evaluator);
  TestReturnValue<ScXMLRealDataObj>("5 * 4",20.0,evaluator);
  TestReturnValue<ScXMLRealDataObj>("5 / 4",1.25,evaluator);
  TestReturnValue<ScXMLRealDataObj>("-5",-5.0,evaluator);

  TestReturnValue<ScXMLBoolDataObj>("True",TRUE,evaluator);
  TestReturnValue<ScXMLBoolDataObj>("false",FALSE,evaluator);
  TestReturnValue<ScXMLBoolDataObj>("!false",TRUE,evaluator);
  TestReturnValue<ScXMLBoolDataObj>("M_PI != M_LN2",TRUE,evaluator);
  TestReturnValue<ScXMLBoolDataObj>("M_PI == M_LN2",FALSE,evaluator);
  TestReturnValue<ScXMLBoolDataObj>("false && !false",FALSE,evaluator);
}


BOOST_AUTO_TEST_SUITE_END();

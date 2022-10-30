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

#include <Inventor/SoType.h>
#include <Inventor/SoType.h>
#include <Inventor/SbName.h>
#include <Inventor/nodes/SoNode.h>
BOOST_AUTO_TEST_SUITE(SoType_TestSuite);


static void * createInstance(void)
{
  return (void *)0x1234;
}

BOOST_AUTO_TEST_CASE(testRemoveType)
{
  BOOST_CHECK_MESSAGE(SoType::fromName(SbName("MyClass")) == SoType::badType(),
                      "Type didn't init to badType");
  SoType newtype = SoType::createType(SoNode::getClassTypeId(), SbName("MyClass"), createInstance, 0);
  BOOST_CHECK_MESSAGE(SoType::fromName(SbName("MyClass")) != SoType::badType(),
                      "Type didn't init correctly");
  bool success = SoType::removeType(SbName("MyClass"));
  BOOST_CHECK_MESSAGE(success,
                      "removeType() failed");
  BOOST_CHECK_MESSAGE(SoType::fromName(SbName("MyClass")) == SoType::badType(),
                      "Type didn't deregister correctly");
}


BOOST_AUTO_TEST_SUITE_END();

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


#include <Inventor/fields/SoMFNode.h>
#include <Inventor/errors/SoReadError.h>
#include <Inventor/SoInput.h>

BOOST_AUTO_TEST_SUITE(SoMFNode_TestSuite);


// Do-nothing error handler for ignoring read errors while testing.
static void
readErrorHandler(const SoError * error, void * data)
{
}

BOOST_AUTO_TEST_CASE(initialized)
{
  SoMFNode field;
  BOOST_CHECK_MESSAGE(field.getTypeId() != SoType::badType(),
                      "missing class initialization");
  BOOST_CHECK_EQUAL(field.getNum(), 0);
}

BOOST_AUTO_TEST_CASE(NULLreading)
{
  // FIXME: We are forced to restore the global state before terminating,
  // or independent tests could fail. (sveinung 20071108)
  SoErrorCB * prevErrorCB = SoReadError::getHandlerCallback();
  SoReadError::setHandlerCallback(readErrorHandler, NULL);

  const char file[] =
    "[ DEF mycube Cube {} USE mycube ]";
  SoInput in;
  in.setBuffer(reinterpret_cast<const void *>(file), sizeof(file));
  SoMFNode field;
  BOOST_CHECK_MESSAGE(field.read(&in, SbName("test")),
                      "DEF/USE reading in SoMFNode is broken");

  SoReadError::setHandlerCallback(prevErrorCB, NULL);
}


BOOST_AUTO_TEST_SUITE_END();

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


#include <Inventor/actions/SoWriteAction.h>
#include <Inventor/SoDB.h>
#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/fields/SoSFTime.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoText2.h>
#include <Inventor/C/tidbits.h>
BOOST_AUTO_TEST_SUITE(SoWriteAction_TestSuite);


// check that the realTime GlobalField is written if it has any
// forward connections.

BOOST_AUTO_TEST_CASE(GlobalField)
{
  SoDB::init();

  //Store away the state before we mess with the global realTime field
  SoSFTime * realtime = static_cast<SoSFTime *>(SoDB::getGlobalField("realTime"));
  assert(realtime);
  SbTime realTimeStorage = realtime->getValue();

  static const char inlinescenegraph[] =
    "#Inventor V2.1 ascii\n"
    "\n"
    "\n"
    "Separator {\n"
    "\n"
    "  Text2 { \n"
    "    string \"\" = GlobalField { \n"
    "      type \"SFTime\" realTime 0 \n"
    "\n"
    "    } . realTime \n"
    "  }\n"
    "}\n";

  // read scene
  SoInput in;
  in.setBuffer((void *) inlinescenegraph, strlen(inlinescenegraph));
  SoSeparator * top = SoDB::readAll(&in);
  BOOST_REQUIRE(top);
  top->ref();

  // write scene
  SoOutput out;
  const int buffer_size = 1024;
  char * buffer = (char *)malloc(buffer_size);
  out.setBuffer(buffer, buffer_size, NULL);

  SoWriteAction wa(&out);
  wa.apply((SoNode *)top);

  top->unref();
  top = NULL;

  // read scene again to check if realTime field was written
  in.setBuffer((void *)buffer, strlen(buffer));
  top = SoDB::readAll(&in);
  BOOST_REQUIRE(top);
  top->ref();

  SoText2 * text = (SoText2 *)top->getChild(0);
  BOOST_REQUIRE(text);

  SoField * string = text->getField("string");
  BOOST_REQUIRE(string);
  BOOST_CHECK_MESSAGE(string->isConnected(), "String field not connected to realTime field in written scene graph");

  free(buffer);

  top->unref();

  //Restore state
  realtime->setValue(realTimeStorage);

}


BOOST_AUTO_TEST_SUITE_END();

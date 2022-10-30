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

#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/nodes/SoSwitch.h>
#include <Inventor/nodes/SoCube.h>
BOOST_AUTO_TEST_SUITE(SoCallbackAction_TestSuite);


static SoCallbackAction::Response
preCB(void * userdata, SoCallbackAction *, const SoNode * node)
{
  SbString *str = (SbString *)userdata;
  (*str) += node->getName();
  return SoCallbackAction::CONTINUE;
}

BOOST_AUTO_TEST_CASE(callbackall)
{
  SbString str;
  SoSwitch * sw = new SoSwitch;
  sw->setName("switch");
  SoCube * cube = new SoCube;
  cube->setName("cube"); 
  sw->addChild(cube);
  sw->ref();

  SoCallbackAction cba;
  cba.addPreCallback(SoNode::getClassTypeId(), preCB, &str);
  cba.apply(sw);
  BOOST_CHECK_MESSAGE(str == "switch", "Should not traverse under switch node");

  str = "";
  cba.setCallbackAll(true);
  cba.apply(sw);
  BOOST_CHECK_MESSAGE(str == "switchcube", "Should traverse under switch node");

  sw->unref();
}


BOOST_AUTO_TEST_SUITE_END();

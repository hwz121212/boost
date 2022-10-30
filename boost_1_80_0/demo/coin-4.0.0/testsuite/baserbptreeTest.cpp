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

#include <Inventor/C/base/rbptree.h>
#include <cmath>
#include <Inventor/lists/SbList.h>
BOOST_AUTO_TEST_SUITE(rbptree_TestSuite);


#define FILL_TIMES (50)
#define FILL_COUNT (10000)

BOOST_AUTO_TEST_CASE(rbptree_stress)
{
  srand(123);
  cc_rbptree tree;
  cc_rbptree_init(&tree);

  int i;
  for (int c = 0; c < FILL_TIMES; ++c) {
    SbList<void *> values;
    for (i = 0; i < FILL_COUNT; ++i) {
      void * entry = reinterpret_cast<void *>(static_cast<uintptr_t>(rand()));
      cc_rbptree_insert(&tree, entry, NULL);
      values.append(entry);
    }
    BOOST_ASSERT(cc_rbptree_size(&tree) == FILL_COUNT);

    if ((c & 1) == 0) {
      for (i = (FILL_COUNT - 1); i >= 0; --i) cc_rbptree_remove(&tree, values[i]);
    } else {
      for (i = 0; i < FILL_COUNT; ++i) cc_rbptree_remove(&tree, values[i]);
    }
    BOOST_ASSERT(cc_rbptree_size(&tree) == 0);
  }

  for (int c = 0; c < FILL_TIMES; ++c) {
    SbList<void *> values;
    for (i = 0; i < FILL_COUNT; ++i) {
      void * entry = reinterpret_cast<void *>(static_cast<uintptr_t>(((c & 2) == 0) ? i : (FILL_COUNT - i)));
      cc_rbptree_insert(&tree, entry, NULL);
      values.append(entry);
    }
    BOOST_ASSERT(cc_rbptree_size(&tree) == FILL_COUNT);

    if ((c & 1) == 0) {
      for (i = (FILL_COUNT - 1); i >= 0; --i) cc_rbptree_remove(&tree, values[i]);
    } else {
      for (i = 0; i < FILL_COUNT; ++i) cc_rbptree_remove(&tree, values[i]);
    }
    BOOST_ASSERT(cc_rbptree_size(&tree) == 0);

  }


  cc_rbptree_clean(&tree);
}


BOOST_AUTO_TEST_SUITE_END();

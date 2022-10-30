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


#include <Inventor/C/XML/document.h>
#include <boost/scoped_array.hpp>
#include <Inventor/C/XML/parser.h>
#include <Inventor/C/XML/path.h>
BOOST_AUTO_TEST_SUITE(document_TestSuite);


BOOST_AUTO_TEST_CASE(bufread)
{
  const char * buffer =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\n"
"<test value=\"one\" compact=\"\">\n"
"  <b>hei</b>\n"
"</test>\n";
  cc_xml_doc * doc1 = cc_xml_read_buffer(buffer);
  BOOST_CHECK_MESSAGE(doc1 != NULL, "cc_xml_doc_read_buffer() failed");

  boost::scoped_array<char> buffer2;
  size_t bytecount = 0;
  {
    char * bufptr = NULL;
    cc_xml_doc_write_to_buffer(doc1, bufptr, bytecount);
    buffer2.reset(bufptr);
  }

  cc_xml_doc * doc2 = cc_xml_read_buffer(buffer2.get());

  cc_xml_path * diffpath = cc_xml_doc_diff(doc1, doc2);
  BOOST_CHECK_MESSAGE(diffpath == NULL, "document read->write->read DOM differences");

  cc_xml_doc_delete_x(doc1);
  cc_xml_doc_delete_x(doc2);
}


BOOST_AUTO_TEST_SUITE_END();

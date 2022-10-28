#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

// Copyright (c) 2015
// Author: Chrono Law
#include <sstream>
#include <iostream>
using namespace std;

#include <boost/progress.hpp>
using namespace boost;

#define BOOST_THREAD_VERSION 4
#include <boost/ref.hpp>
#include <boost/thread.hpp>

#include <boost/chrono.hpp>
using namespace boost::chrono;

//////////////////////////////////////////

int main()
{
    {
        boost::progress_timer t;

    }
    {
        boost::progress_timer t;
    }

    stringstream ss;
    {
        progress_timer t(ss);
		this_thread::sleep_for(milliseconds(600));
    }
    cout << ss.str();
}



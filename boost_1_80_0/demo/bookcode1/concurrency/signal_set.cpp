#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

// Copyright (c) 2015
// Author: Chrono Law
#include <iostream>
using namespace std;

#define BOOST_ASIO_DISABLE_STD_CHRONO
#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#include <boost/function.hpp>
#include <boost/asio.hpp>
using namespace boost::asio;
using namespace boost::system;

// kill -10 xxxx

#define SIGUSR1 1

int main()
{
    io_service io;
    //io_service::work w(io);

    signal_set sig(io, SIGINT, SIGUSR1);
    cout << "add:" << SIGINT << "," << SIGUSR1 << endl;

    //sig.add(SIGINT);
    //sig.add(SIGUSR1);

    auto handler1 =
        [&](const boost::system::error_code& ec, int n)
        {
            //cout << "enter sigint" << endl;
            if(ec)
            {
                cout << ec.message() << endl;
                return;
            }

            if(n != SIGINT)
            {
                return;
            }

            cout << "handler1 recv = " << n << endl;
            cout << "do something" << endl;
            //w.~work();
        };

    typedef void(handler_type)(const boost::system::error_code&, int);
    function<handler_type>
        handler2 =
        [&](const boost::system::error_code& ec, int n)
        {
            if(n != SIGUSR1)
            {
                return;
            }

            cout << "handler2 recv = " << n << endl;

            sig.async_wait(handler1);
            sig.async_wait(handler2);
        };

    sig.async_wait(handler1);
    sig.async_wait(handler2);

    io.run();
    cout << "io stoped" << endl;
}

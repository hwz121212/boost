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
//#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
#include <boost/function.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

using namespace boost::asio;
using namespace boost::system;

#ifdef _DEBUG
#pragma comment(lib, "libboost_context-vc141-mt-gd-x64-1_79.lib")
#else
#pragma comment(lib, "libboost_context-vc141-mt-x64-1_79.lib")
#endif

#ifdef _DEBUG
#pragma comment(lib, "libboost_coroutine-vc141-mt-gd-x64-1_79.lib")
#else
#pragma comment(lib, "libboost_coroutine-vc141-mt-x64-1_79.lib")
#endif

//////////////////////////////////////////

int main()
{
    typedef ip::tcp::acceptor acceptor_type;
    typedef ip::tcp::endpoint endpoint_type;
    typedef ip::tcp::socket socket_type;

    io_service io;

    spawn(io,
        [&](yield_context yield)
        {
            acceptor_type acceptor(io,
                endpoint_type(ip::tcp::v4(), 6688));

            for(;;)
            {
                socket_type sock(io);
				boost::system::error_code ec;

                acceptor.async_accept(sock, yield[ec]);

                if(ec)
                {
                    return;
                }

                auto len = sock.async_write_some(
                    buffer("hello coroutine"), yield);
                cout << "send " << len << " bytes" << endl;
            }
        }
    );

    io.run();
}

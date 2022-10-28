// Copyright (c) 2015
// Author: Chrono Law
#include <iostream>
using namespace std;

#include <boost/serialization/singleton.hpp>
using boost::serialization::singleton;




#ifdef _DEBUG
#pragma comment(lib, "libboost_serialization-vc141-mt-gd-x64-1_79.lib")
#else
#pragma comment(lib, "libboost_serialization-vc141-mt-x64-1_79.lib")
#endif



//////////////////////////////////////////
class point : public singleton<point>
{
    int x, y, z;
public:
    point(int a=0, int b=0, int c=0):x(a),y(b),z(c)
    {   cout << "point ctor" << endl;}

    ~point()
    {   cout << "point dtor" << endl;}

    void print()const
    {       cout << x <<","<< y <<","<< z << endl;  }

};

typedef singleton<point> origin;

//////////////////////////////////////////

int main()
{
    cout << "main() start" << endl;

    origin::get_const_instance().print();
    origin::get_mutable_instance().print();

    point::get_const_instance().print();
    point::get_mutable_instance().print();

    cout << "main() finish" << endl;
}


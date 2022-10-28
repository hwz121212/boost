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

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost::property_tree;

//一、读增删改（root1的修改）
struct STRCONF
{
	std::wstring A;
	std::wstring B;
	std::wstring C;
};

std::wstring fileName = L"property_tree1.xml";

//1.读取
void case1()
{
	try
	{
		std::wifstream file(fileName);
		boost::property_tree::wptree pt;
		boost::property_tree::xml_parser::read_xml(file, pt);
		auto root1 = pt.get_child(L"root.root1");
		//读取
		//<root11 A="Tcp" B="" C=""/>
		//<root11 A="Tcp" B="" C=""/>
		for (auto it = root1.begin(); it != root1.end(); ++it)
		{
			auto& node = it->second;
			STRCONF conf;
			conf.A = node.get<std::wstring>(L"<xmlattr>.A", L"");
			conf.B = node.get<std::wstring>(L"<xmlattr>.B", L"");
			conf.C = node.get<std::wstring>(L"<xmlattr>.C", L"");
		}
	}
	catch (...)
	{

	}
}


//2.增加
void case2()
{
	try
	{
		std::wifstream file(fileName);
		boost::property_tree::xml_writer_settings<wstring> settings =
			boost::property_tree::xml_writer_make_settings<wstring>('\t', 1);
		boost::property_tree::wptree ptUi;
		boost::property_tree::xml_parser::read_xml(file, ptUi, boost::property_tree::xml_parser::trim_whitespace);
		boost::property_tree::wptree pt;
		pt.add(L"<xmlattr>.A", L"new");
		pt.add(L"<xmlattr>.B", L"new");
		pt.add(L"<xmlattr>.C", L"new");
		ptUi.add_child(L"root.root1.root11", pt);
		//<root1>下增加一条<root11 A="new" B="new" C="new"/>

		std::wofstream file1(fileName);
		boost::property_tree::xml_parser::write_xml(file1, ptUi, settings);
	}
	catch (...)
	{

	}
}

//3.删除第0个
void case3()
{
	try
	{
		std::wifstream file(fileName);
		boost::property_tree::xml_writer_settings<wstring> settings =
			boost::property_tree::xml_writer_make_settings<wstring>('\t', 1);
		boost::property_tree::wptree ptSer;		
		boost::property_tree::xml_parser::read_xml(file, ptSer, boost::property_tree::xml_parser::trim_whitespace);
		auto root1 = ptSer.get_child(L"root.root1");
		int i = 0;
		//删除这一条<root11 A="Tcp" B="" C=""/>
		for (auto it = root1.begin(); it != root1.end(); ++it)
		{
			auto& node = it->second;
			if (i == 0)
			{
				root1.erase(it);
				break;
			}
			i++;
		}

		std::wofstream file1(fileName);
		boost::property_tree::xml_parser::write_xml(file1, ptSer, settings);
	}
	catch (...)
	{

	}
}

//4.修改
void case4()
{
	try
	{
		std::wifstream file(fileName);
		boost::property_tree::xml_writer_settings<wstring> settings =
			boost::property_tree::xml_writer_make_settings<wstring>('\t', 1);
		boost::property_tree::wptree ptSer;
		boost::property_tree::xml_parser::read_xml(file, ptSer, boost::property_tree::xml_parser::trim_whitespace);
		auto root = ptSer.get_child(L"root.root1");
		int i = 0;
		//<root11 A="Tcp" B="" C=""/>修改为<root11 A="11111111111" B="11111111111" C="11111111111"/>
		for (auto it = root.begin(); it != root.end(); ++it)
		{
			auto& node = it->second;
			if (i == 0)
			{
				node.put<std::wstring>(L"<xmlattr>.A", L"11111111111");
				node.put<std::wstring>(L"<xmlattr>.B", L"11111111111");
				node.put<std::wstring>(L"<xmlattr>.C", L"11111111111");
				break;
			}
			i++;
		}

		std::wofstream file1(fileName);
		boost::property_tree::xml_parser::write_xml(file1, ptSer, settings);
	}
	catch (...)
	{

	}
}

//二、读增删改（root3的修改）
//1.读取root3
void case5()
{
	std::wifstream file(fileName);
	boost::property_tree::wptree pt;
	boost::property_tree::xml_parser::read_xml(file, pt);
	auto root3 = pt.get_child(L"root.root3");
	int i = 0;
	//读取        
	//<root31>123456789</root31>
	//<root32>4444</root32>
	for (auto it = root3.begin(); it != root3.end(); ++it)
	{
		auto& node = it->second;
		if (i == 0)
		{
			std::wstring temp00 = node.get<std::wstring>(L"", L"");
		}
		else if (i == 1)
		{
			std::wstring  temp01 = node.get<std::wstring>(L"", L"");
		}
		i++;
	}	
}


void case6()
{
	//4.修改
		//修改
			//<root31>123456789</root31>
			//<root32>4444</root32>
			//为
			//<root31>11111</root31>
			//<root32>11111</root32>
	boost::property_tree::xml_writer_settings<wstring> settings =
		boost::property_tree::xml_writer_make_settings<wstring>('\t', 1);

	try
	{
		std::wifstream file(fileName);
		boost::property_tree::wptree pt;
		boost::property_tree::xml_parser::read_xml(file, pt, boost::property_tree::xml_parser::trim_whitespace);
		pt.put(L"root.root3.root31", L"11111");
		pt.put(L"root.root3.root32", L"11111");

		std::wofstream file1(fileName);
		boost::property_tree::xml_parser::write_xml(file1, pt, settings);
	}
	catch (...)
	{
	}
}


int main()
{
	case1();
	case2();
	case3();
	case4();
	case5();
	case6();
}

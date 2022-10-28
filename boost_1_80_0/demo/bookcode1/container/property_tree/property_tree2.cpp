#include <iostream>
#include <string>
#include <boost/typeof/typeof.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using namespace boost::property_tree;

int main(void)
{
	char szXmlFile[] = "property_tree2.xml";

	string strTmp;

	ptree pt;
	boost::property_tree::read_xml(szXmlFile, pt, boost::property_tree::xml_parser::trim_whitespace);


	BOOST_AUTO(file_childs, pt.get_child("config.file"));
	//serch(child,0);
	for (BOOST_AUTO(file_childs_iter, file_childs.begin()); file_childs_iter != file_childs.end(); ++file_childs_iter)//file
	{
		strTmp.clear();
		if ("<xmlattr>" == file_childs_iter->first)
		{
			//�˽ڵ��first��xmlattr��second�ڵ�ʱpair,����key,value��ȡֵ��key��·��
			strTmp = file_childs_iter->second.get<string>("title");		// �����windows
			cout << file_childs_iter->first << ",  title: " << strTmp << "\n";

			strTmp = file_childs_iter->second.get<string>("size");		// �����10Mb
			cout << file_childs_iter->first << ",  size: " << strTmp << "\n";

			strTmp = file_childs_iter->second.get<string>("not exits", "This is default");
			cout << file_childs_iter->first << ",  not exist:" << strTmp << endl;  // �����This is default
		}
		else if ("<xmlcomment>" == file_childs_iter->first)
		{
			strTmp = file_childs_iter->second.get_value<string>();		// ��һ�������File First Comment
			cout << file_childs_iter->first << ",  comment: " << strTmp << "\n";		// �ڶ��������File Second Comment
		}
		else//paths
		{
			BOOST_AUTO(paths_childs, file_childs_iter->second.get_child(""));
			for (BOOST_AUTO(paths_childs_iter, paths_childs.begin()); paths_childs_iter != paths_childs.end(); ++paths_childs_iter)//paths
			{
				strTmp.clear();
				if ("<xmlattr>" == paths_childs_iter->first)
				{
					cout << file_childs_iter->first << " ";
					//�˽ڵ��first��xmlattr��second�ڵ�ʱpair,����key,value��ȡֵ��key��·��
					strTmp = paths_childs_iter->second.get<string>("attr");
					cout << paths_childs_iter->first << ",  attr: " << strTmp << "\n";
				}
				else if ("<xmlcomment>" == paths_childs_iter->first)
				{
					cout << file_childs_iter->first << " ";
					strTmp = paths_childs_iter->second.get_value<string>();
					cout << paths_childs_iter->first << ",  comment: " << strTmp << "\n";
				}
				else//pathname
				{
					cout << file_childs_iter->first << " ";
					strTmp = paths_childs_iter->second.get<string>("<xmlattr>.title");
					cout << paths_childs_iter->first << "  title: " << strTmp << " content:" << paths_childs_iter->second.data() << "\n";
				
					paths_childs_iter->second.put_value("123456");
				
				}
			}
		}
	}

	//��ӣ�׷�ӣ�config.tempԪ��
// 	pt.add("config.temp", "wwwww");
// 	pt.add("config.temp.<xmlattr>.AAA", "AAA");


	//ɾ�����е�config.tempԪ��
	ptree& config_childs = pt.get_child("config");
	for (BOOST_AUTO(config_childs_iter, config_childs.begin()); config_childs_iter != config_childs.end(); )
	{
		if ("temp" == config_childs_iter->first)
		{
			string strAttrValue = config_childs_iter->second.get<string>("<xmlattr>.AAA");
			if (strAttrValue.compare("111") == 0)
			{
				config_childs_iter->second.put_value("44444444444444444");
			}
			else if (strAttrValue.compare("222") == 0)
			{
				config_childs_iter->second.put_value("55555555555555555");
			}
		}
		
		++config_childs_iter;

// 		if ("temp" == config_childs_iter->first)
// 		{
// 			BOOST_AUTO(config_childs_iter_temp, config_childs_iter);
// 			++config_childs_iter;
// 			config_childs.erase(config_childs_iter_temp);
// 		}
// 		else
// 		{
// 			++config_childs_iter;
// 		}
	}

	boost::property_tree::xml_writer_settings<string> settings =
		boost::property_tree::xml_writer_make_settings<string>('\t', 1, "utf8");
	write_xml(szXmlFile, pt, std::locale(), settings);


	return 0;
}


//�����������������п��Կ�����BOOST��װ��RapidXml��Դ�⣬�ǽ�XML�ļ����ݽ���Ϊһ����״�ṹ������˵������ʹ�õĽڵ㡰config.file������������ӽڵ㣺һ�������ӽڵ㡢����ע���ӽڵ㡢���������ӽڵ㣬��˳��Ϊ���ԡ�ע�͡����ݡ�
//�������ӽڵ㣺
//ÿ���ڵ�ֻ��һ�������ӽڵ㣬��һ�Զ��ϵ����һ�������ӽڵ��Ӧ������ԣ�
//"if ("<xmlattr>" == pos->first)"��Ȼ���ȡ���Ե�ֵ��Ϊ��pos->second.get<string>("title")���͡�pos->second.get<string>("size")����ע�������ȡ���ԣ�������"<xmlattr>.title"����Ϊ��ʱpos�Ѿ�ָ�򱾽ڵ㣬������Ҫ��"<xmlattr>"���Ƶ������ӽڵ㣡
//��ע���ӽڵ㣺�ڵ�����ж�������ӽڵ㣬��һ��һ��ϵ������
//��if("<xmlcomment>" == pos->first)������ȡ������pos->second.data()��������iter->second.get_value<string>()
//�������ӽڵ㣺���ֽڵ��ֿ������¿�����һ���ڵ㣬������Ӧ�����ӽڵ㡢ע���ӽڵ㡢�����ӽڵ㡣��ע�⡰pos->second.get_child("")���Ƿ��ص�ǰ�ڵ�������ӽڵ㣨�������ԡ�ע�͡����ݣ�������pt.get_child("config.file")���Ƿ���file�ڵ������нڵ㣨�������ԡ�ע�͡����ݣ���
//��������������������������������


//��ȡ�ı����ݣ�pt.get<string>("confi.theme");//<theme>this is the result</theme>
//��ȡ��ǰ�ڵ���ı����ݣ�pt.get<string>();//<theme>this is the result</theme>�����ҽ�����ǰ�ڵ�ʱtheme
//��ȡע�����ݣ�pt.get < string("conf.<xmlcomment>");//<conf><!-- this is the result --></conf>
//��ȡ�������ݣ�pt.get<long>("conf.theme.<xmlattr>.id");//<theme id="123456"></theme>,id is 123456��������������������������������

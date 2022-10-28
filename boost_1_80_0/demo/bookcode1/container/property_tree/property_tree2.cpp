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
			//此节点的first是xmlattr，second节点时pair,按照key,value来取值，key是路径
			strTmp = file_childs_iter->second.get<string>("title");		// 输出：windows
			cout << file_childs_iter->first << ",  title: " << strTmp << "\n";

			strTmp = file_childs_iter->second.get<string>("size");		// 输出：10Mb
			cout << file_childs_iter->first << ",  size: " << strTmp << "\n";

			strTmp = file_childs_iter->second.get<string>("not exits", "This is default");
			cout << file_childs_iter->first << ",  not exist:" << strTmp << endl;  // 输出：This is default
		}
		else if ("<xmlcomment>" == file_childs_iter->first)
		{
			strTmp = file_childs_iter->second.get_value<string>();		// 第一次输出：File First Comment
			cout << file_childs_iter->first << ",  comment: " << strTmp << "\n";		// 第二次输出：File Second Comment
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
					//此节点的first是xmlattr，second节点时pair,按照key,value来取值，key是路径
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

	//添加（追加）config.temp元素
// 	pt.add("config.temp", "wwwww");
// 	pt.add("config.temp.<xmlattr>.AAA", "AAA");


	//删除所有的config.temp元素
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


//分析：从上述测试中可以看出，BOOST封装的RapidXml开源库，是将XML文件内容解析为一个树状结构。比如说本例中使用的节点“config.file”，具有五个子节点：一个属性子节点、两个注释子节点、两个数据子节点，且顺序为属性→注释→数据。
//①属性子节点：
//每个节点只有一个属性子节点，是一对多关系，即一个属性子节点对应多个属性！
//"if ("<xmlattr>" == pos->first)"，然后获取属性的值则为“pos->second.get<string>("title")”和“pos->second.get<string>("size")”。注意这里获取属性，不再是"<xmlattr>.title"，因为此时pos已经指向本节点，不再需要用"<xmlattr>"递推到属性子节点！
//②注释子节点：节点可以有多个属性子节点，是一对一关系！！！
//”if("<xmlcomment>" == pos->first)“，获取属性则“pos->second.data()”；或者iter->second.get_value<string>()
//③数据子节点：这种节点又可以重新看做是一个节点，下面会对应属性子节点、注释子节点、数据子节点。但注意“pos->second.get_child("")”是返回当前节点的所有子节点（包含属性、注释、数据），而“pt.get_child("config.file")“是返回file节点下所有节点（包含属性、注释、数据）。
//————————————————


//获取文本内容：pt.get<string>("confi.theme");//<theme>this is the result</theme>
//获取当前节点的文本内容：pt.get<string>();//<theme>this is the result</theme>，当且仅当当前节点时theme
//获取注释内容：pt.get < string("conf.<xmlcomment>");//<conf><!-- this is the result --></conf>
//获取属性内容：pt.get<long>("conf.theme.<xmlattr>.id");//<theme id="123456"></theme>,id is 123456————————————————

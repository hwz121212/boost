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

#include <boost/typeof/typeof.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost::property_tree;


std::string fileName = "zlib.vcxproj.filters";

bool Vcxproj_Open(const string& strFileName, ptree& pt)
{
	bool bReturn = true;
	try
	{
		boost::property_tree::read_xml(strFileName, pt, boost::property_tree::xml_parser::trim_whitespace);
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

bool Vcxproj_Save(const string& strFileName, const ptree& pt)
{
	bool bReturn = true;
	try
	{
		boost::property_tree::xml_writer_settings<string> settings =
			boost::property_tree::xml_writer_make_settings<string>(' ', 2, "utf-8");

		//boost::property_tree::xml_writer_make_settings<std::string>('\t', 1));
		//boost::property_tree::xml_parser::xml_writer_settings<ptree::key_type> settings('\t', 1, "GB2312");	

		write_xml(strFileName, pt, std::locale(), settings);
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}



//ªÒ»°≈‰÷√¿‡–Õ°ædll°¢exe°¢lib°ø
enum enumConfigurationType
{
	enumConfigurationType_unknown = 0,
	enumConfigurationType_lib,
	enumConfigurationType_dll,
	enumConfigurationType_exe
};

enumConfigurationType GetConfigurationType(ptree& pt)
{
	enumConfigurationType enumReturn = enumConfigurationType_unknown;
	try
	{		
		ptree& Project_childs = pt.get_child("Project");		
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				ptree& PropertyGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(PropertyGroup_childs_iter, PropertyGroup_childs.begin());
					PropertyGroup_childs_iter != PropertyGroup_childs.end();
					++PropertyGroup_childs_iter)
				{
					if ("ConfigurationType" == PropertyGroup_childs_iter->first)
					{
						string strConfigurationType = PropertyGroup_childs_iter->second.data();
						if (strConfigurationType.compare("DynamicLibrary") == 0)
						{
							enumReturn = enumConfigurationType_dll;							
						}
						else if (strConfigurationType.compare("Application") == 0)
						{
							enumReturn = enumConfigurationType_exe;
						}
						else if (strConfigurationType.compare("StaticLibrary") == 0)
						{
							enumReturn = enumConfigurationType_lib;
						}
						goto tag_return;
					}
				}
			}
		}	
	}
	catch (...)
	{
		enumReturn = enumConfigurationType_unknown;
	}

	tag_return:
	return enumReturn;
}

//<OutDir Condition = "'$(Configuration)|$(Platform)'=='Debug|x64'">$(SolutionDir)bin\$(Configuration)\< / OutDir>
bool OutDir_dll_exe(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				ptree& PropertyGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(PropertyGroup_childs_iter, PropertyGroup_childs.begin());
					PropertyGroup_childs_iter != PropertyGroup_childs.end();
					++PropertyGroup_childs_iter)
				{
					if ("OutDir" == PropertyGroup_childs_iter->first)
					{
						string strTemp = "$(SolutionDir)bin\\$(Configuration)\\";
						PropertyGroup_childs_iter->second.put_value(strTemp);
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<OutDir>$(SolutionDir)lib\$(Configuration)\</OutDir>
bool OutDir_lib(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				ptree& PropertyGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(PropertyGroup_childs_iter, PropertyGroup_childs.begin());
					PropertyGroup_childs_iter != PropertyGroup_childs.end();
					++PropertyGroup_childs_iter)
				{
					if ("OutDir" == PropertyGroup_childs_iter->first)
					{
						string strTemp = "$(SolutionDir)lib\\$(Configuration)\\";
						PropertyGroup_childs_iter->second.put_value(strTemp);
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}




//<IntDir>$(SolutionDir)..\Temp\$(SolutionName)\$(ProjectName)\$(Configuration)</IntDir>
bool IntDir(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				ptree& PropertyGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(PropertyGroup_childs_iter, PropertyGroup_childs.begin());
					PropertyGroup_childs_iter != PropertyGroup_childs.end();
					++PropertyGroup_childs_iter)
				{
					if ("IntDir" == PropertyGroup_childs_iter->first)
					{
						string strTemp = "$(SolutionDir)..\\Temp\\$(SolutionName)\\$(ProjectName)\\$(Configuration)";
						PropertyGroup_childs_iter->second.put_value(strTemp);
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}


//<TargetName Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">zlibd</TargetName>
bool TargetName(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				Project_childs_iter->second.erase("TargetName");
				bReturn = true;
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<TargetExt Condition="&apos;$(Configuration)|$(Platform)&apos;==&apos;Debug|x64&apos;">.dll</TargetExt>
bool TargetExt(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("PropertyGroup" == Project_childs_iter->first)
			{
				Project_childs_iter->second.erase("TargetExt");
				bReturn = true;
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}


//AdditionalIncludeDirectories
//.;..;$(SolutionDir)include;$(SolutionDir)thirdparty;%(AdditionalIncludeDirectories)
bool AdditionalIncludeDirectories(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemDefinitionGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					string strTemp = ".;..;$(SolutionDir)include;$(SolutionDir)thirdparty;%(AdditionalIncludeDirectories)";
					if ("ClCompile" == ItemDefinitionGroup_childs_iter->first
						|| "ResourceCompile" == ItemDefinitionGroup_childs_iter->first
						|| "Midl" == ItemDefinitionGroup_childs_iter->first)
					{						
						ItemDefinitionGroup_childs_iter->second.put("AdditionalIncludeDirectories", strTemp);
						bReturn = true;
					}					
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<AssemblerListingLocation>$(IntDir)</AssemblerListingLocation>
bool AssemblerListingLocation(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemDefinitionGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					if ("ClCompile" == ItemDefinitionGroup_childs_iter->first)
					{
						ItemDefinitionGroup_childs_iter->second.erase("AssemblerListingLocation");
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<ObjectFileName>$(IntDir)</ObjectFileName>
bool ObjectFileName(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemDefinitionGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					if ("ClCompile" == ItemDefinitionGroup_childs_iter->first)
					{
						ItemDefinitionGroup_childs_iter->second.erase("ObjectFileName");
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<ProgramDataBaseFile>D:/hanwenzhi_code/zlib/backup/zlib-1.2.12/Debug/zlibd.pdb</ProgramDataBaseFile>
bool ProgramDataBaseFile(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemDefinitionGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					if ("Link" == ItemDefinitionGroup_childs_iter->first)
					{
						ItemDefinitionGroup_childs_iter->second.erase("ProgramDataBaseFile");
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<ImportLibrary>$(SolutionDir)lib\$(Configuration)\$(TargetName).lib</ImportLibrary>
bool ImportLibrary_dll(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemDefinitionGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					string strTemp = "$(SolutionDir)lib\\$(Configuration)\\$(TargetName).lib";
					if ("Link" == ItemDefinitionGroup_childs_iter->first)
					{
						ItemDefinitionGroup_childs_iter->second.put("ImportLibrary", strTemp);
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<CustomBuild Include="D:\hanwenzhi_code\zlib\backup\zlib-1.2.12\CMakeLists.txt"></CustomBuild>
bool CustomBuild_CMakeLists(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					if ("CustomBuild" == ItemDefinitionGroup_childs_iter->first)
					{
						string strInclude = ItemDefinitionGroup_childs_iter->second.get<string>("<xmlattr>.Include");
						if (strInclude.find("CMakeLists.txt") != -1)
						{
							ItemDefinitionGroup_childs_iter->second.clear();
							bReturn = true;
						}						
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//<ProjectReference Include="D:\hanwenzhi_code\zlib\backup\zlib-1.2.12\ZERO_CHECK.vcxproj"></ProjectReference>
bool ProjectReference(ptree& pt)
{
	bool bReturn = false;
	try
	{
		ptree& Project_childs = pt.get_child("Project");
		for (BOOST_AUTO(Project_childs_iter, Project_childs.begin());
			Project_childs_iter != Project_childs.end();
			++Project_childs_iter)
		{
			if ("ItemGroup" == Project_childs_iter->first)
			{
				ptree& ItemDefinitionGroup_childs = Project_childs_iter->second.get_child("");
				for (BOOST_AUTO(ItemDefinitionGroup_childs_iter, ItemDefinitionGroup_childs.begin());
					ItemDefinitionGroup_childs_iter != ItemDefinitionGroup_childs.end();
					++ItemDefinitionGroup_childs_iter)
				{
					if ("ProjectReference" == ItemDefinitionGroup_childs_iter->first)
					{
						ItemDefinitionGroup_childs_iter->second.clear();
						bReturn = true;
					}
				}
			}
		}
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//ÃÊªª.vcxproj.filtersµƒ≈‰÷√
bool Vcxproj_unknown(ptree& pt)
{
	bool bReturn = true;
	try
	{
		CustomBuild_CMakeLists(pt);
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}

//ÃÊªªdllµƒ≈‰÷√
bool Vcxproj_dll(ptree& pt)
{
	bool bReturn = true;
	try
	{
		OutDir_dll_exe(pt);
		IntDir(pt);
		TargetName(pt);
		TargetExt(pt);

		AdditionalIncludeDirectories(pt);
		AssemblerListingLocation(pt);
		ObjectFileName(pt);
		ProgramDataBaseFile(pt);

		ImportLibrary_dll(pt);	//dllÃÿ”–

		CustomBuild_CMakeLists(pt);
		ProjectReference(pt);
		
	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}


//ÃÊªªexeµƒ≈‰÷√
bool Vcxproj_exe(ptree& pt)
{
	bool bReturn = true;
	try
	{
		OutDir_dll_exe(pt);
		IntDir(pt);
		TargetName(pt);
		TargetExt(pt);

		AdditionalIncludeDirectories(pt);
		AssemblerListingLocation(pt);
		ObjectFileName(pt);
		ProgramDataBaseFile(pt);

		CustomBuild_CMakeLists(pt);
		ProjectReference(pt);

	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}



//ÃÊªªlibµƒ≈‰÷√
bool Vcxproj_lib(ptree& pt)
{
	bool bReturn = true;
	try
	{
		OutDir_lib(pt);
		IntDir(pt);
		TargetName(pt);
		TargetExt(pt);

		AdditionalIncludeDirectories(pt);
		AssemblerListingLocation(pt);
		ObjectFileName(pt);
		ProgramDataBaseFile(pt);

		CustomBuild_CMakeLists(pt);
		ProjectReference(pt);

	}
	catch (...)
	{
		bReturn = false;
	}
	return bReturn;
}


int main()
{
	ptree pt;
	Vcxproj_Open(fileName, pt);

	enumConfigurationType enumType = GetConfigurationType(pt);
	switch (enumType)
	{
	case enumConfigurationType_unknown:
		Vcxproj_unknown(pt);
		break;
	case enumConfigurationType_lib:
		Vcxproj_lib(pt);
		break;
	case enumConfigurationType_dll:
		Vcxproj_dll(pt);
		break;
	case enumConfigurationType_exe:
		Vcxproj_exe(pt);
		break;
	default:
		break;
	}

	
	Vcxproj_Save(fileName, pt);

	//ÃÊªª&apos;Œ™'

}

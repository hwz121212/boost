官网：https://www.boost.org/

1.  boost_1_80_0.zip 是从 https://www.boost.org/users/history/version_1_80_0.html 下载而来的。下载时间【北京时间2022-10-28】
2. boost_1_80_0 目录下的代码是由 boost_1_80_0.zip 重构而来的，重构时间【北京时间2022-10-28】


备注：
1. 修改boost_1_80_0\thirdparty\boost_1_80_0\boost\config\auto_link.hpp文件，屏蔽了导入lib库的代码。
2. 使用vs2017可以编译出boost的lib库，好处时按需编译，不必拷贝占用空间巨大的lib文件。（有mpi和python相关的lib暂时尚未配置）
3. Boost程序库完全开发指南.sln里面的demo链接的就是boost_1_80_0.sln编译出的lib文件，可以作为参考。

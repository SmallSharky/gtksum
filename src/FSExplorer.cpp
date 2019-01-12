#include "FSExplorer.hpp"

#include <string>
// #include <filesystem>
#include <experimental/filesystem>
#include <iostream>

using namespace std;
using namespace std::experimental;
// using namespace std::filesystem;


string getExecutablePath()
{
//     string ret;
    filesystem::path ExeLink("/proc/self/exe");
    return filesystem::absolute(filesystem::read_symlink(ExeLink)).string();
//     return filesystem::absolute(ExeLink).string();
//     return ret;
}
string getRootPath()
{
//     string ret;
    //считаем, что исполняемый файл находится в директории bin относительно установочного каталога
    filesystem::path ExePath(getExecutablePath());
    ExePath = ExePath.parent_path().parent_path();
//     cout<<ExePath.string()<<"\n";
    return ExePath.string();
}



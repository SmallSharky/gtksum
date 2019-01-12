#pragma once

#include <string>

// Путь к каталогу, относительно которого располагаются файлы программы
// Например: /usr/local
std::string getRootPath();
// Путь к исполняемому файлу программы
// Например, /usr/local/bin/executable
std::string getExecutablePath();

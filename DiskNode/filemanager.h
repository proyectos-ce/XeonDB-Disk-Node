#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <string>
#include "table.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
//#include <boost/filesystem.hpp>

#define MasterRecord "master.record"

namespace FileManager
{
    Table loadTableFromDisk(std::string filename);
    bool saveTableToDisk(Table table);
    bool existsOnDisk(std::string name);
    std::vector<std::string> tablesOnDisk();
}

#endif // FILEMANAGER_H

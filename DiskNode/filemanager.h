#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <string>
#include "table.h"
#include <iostream>
class FileManager
{
public:
    FileManager();
    Table loadTableFromDisk(std::string name);
    bool saveTableToDisk(Table table);
    bool existsOnDisk(std::string name);
    std::vector<std::string> tablesOnDisk();
private:
     FILE *filePTR;
};

#endif // FILEMANAGER_H

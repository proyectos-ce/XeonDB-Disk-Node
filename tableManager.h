//
// Created by Ignacio Mora on 6/16/17.
//

#ifndef DISKNODE_TABLEMANAGER_H
#define DISKNODE_TABLEMANAGER_H


#include <vector>

#include "table.h"

class TableManager {
public:
    TableManager();
    Table getTable(std::string name);
    bool exists(std::string name);
    bool addTable(Table table);
    std::vector<Table> tableList;
    int deleteTable(std::string name);

private:


};


#endif //DISKNODE_TABLEMANAGER_H

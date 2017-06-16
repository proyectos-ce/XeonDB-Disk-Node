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
    Table* getTable(std::string name);
    Row* getRowFromTable(std::string name, int row);
    bool addTable(std::string name);

private:
    std::vector<Table*> tableList;

};


#endif //DISKNODE_TABLEMANAGER_H

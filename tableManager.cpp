//
// Created by Ignacio Mora on 6/16/17.
//

#include <iostream>
#include "tableManager.h"

TableManager::TableManager() {

}

Table TableManager::getTable(std::string name) {
    int i;
    for (i = 0; i < tableList.size(); i++){
        if (tableList[i].getName() == name)
            return tableList[i];
    }
    return Table();
}

bool TableManager::addTable(Table table) {
    if (!isTable(table.getName())) {
        tableList.push_back(table);
        return true;
    }
    return false;
}

bool TableManager::isTable(std::string name) {
    int i;
    for (i = 0; i < tableList.size(); i++){
        if (tableList[i].getName() == name)
            return true;
    }
    return false;
}


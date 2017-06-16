//
// Created by Ignacio Mora on 6/16/17.
//

#include "tableManager.h"

TableManager::TableManager() {

}

Table* TableManager::getTable(std::string name) {
    int i;
    for (i = 0; i < tableList.size(); i++){
        if (tableList[i]->getName() == name)
            return tableList[i];
    }
    return nullptr;
}

bool TableManager::addTable(std::string name) {
    if (getTable(name) == nullptr) {
        tableList.push_back(new Table(name));
        return true;
    }
    return false;
}


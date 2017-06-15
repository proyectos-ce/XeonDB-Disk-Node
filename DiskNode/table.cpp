#include "table.h"

Table::Table()
{


}

bool Table::insertColumn(std::string name, int type)
{
    bool result = false;
    if (!checkIfRowExists(name)){
        rowsProperties.push_back(RowProperties(name, type));
        for (int i = 0; i < rows.size(); ++i) {
            rows[i].insertColumn(NULL, type);
        }
        result= true;
    }
    return result;
}

bool Table::removeRow(int index)
{
    int result = false;
    if(index < rowsProperties.size()){

    }
}

bool Table::checkIfRowExists(std::string name)
{
    return getRowIndex(name) != -1;
}

int Table::getRowIndex(std::string name)
{
    result = -1;
    for (int i = 0; i < rowsProperties.size(); ++i) {
        if(rowsProperties[i].getName() == name){
            result = i;
            break;
        }
    }
    return result;
}

RowProperties::RowProperties(std::string name, int type)
{
    this->name =name;
    this->type=type;
}

std::string RowProperties::getName() const
{
    return name;
}

void RowProperties::setName(const std::string &value)
{
    name = value;
}

int RowProperties::getType() const
{
    return type;
}

void RowProperties::setType(int value)
{
    type = value;
}

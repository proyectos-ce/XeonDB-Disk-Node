#include "table.h"

Table::Table()
{

}

Table::Table(std::string name) {
    this->name = name;
}

bool Table::insertColumn(std::string name, int type)
{
    bool result = false;
    if (!checkIfColumnExists(name)){
        columnProperties.push_back(ColumnProperties(name, type));
        for (int i = 0; i < rows.size(); ++i) {
            rows[i].insertColumn(NULL);
        }
        result= true;
    }
    return result;
}

bool Table::insertRow(Row row)
{
    rows.push_back(row);
}

bool Table::insertRow(std::vector<std::string> dataRow)
{
    bool result = true;
    Row newRow;
    if(dataRow.size() == columnProperties.size()){
        for (int i = 0; i < dataRow.size(); ++i) {
            if(!newRow.insertColumn(dataRow[i])){
                //result = false;
                return false;
            }
        }
        this->insertRow(newRow);
        //result = true;
    }

    return result;
}

bool Table::removeColumn(int index)
{
    bool result=false;
    if(index<columnProperties.size()){
        for (int i = 0; i < rows.size(); ++i) {
            rows[i].deleteColumn(index);
        }
        columnProperties.erase(columnProperties.begin()+index);
        result = true;
    }
    return result;
}

bool Table::removeRow(int index)
{
    int result = false;
    if(index < columnProperties.size()){
        rows.erase(rows.begin()+index);
        result = true;
    }
    return result;
}

Row Table::getRow(int index) const
{
    Row result;
    if(index < rows.size()){
        result = rows[index];
        result.setIndex(index);
    }
    return result;
}

std::vector<Row> Table::getRows(std::vector<int> rowsIndexes) const
{
    std::vector<Row> result;
    for (int i = 0; i < rowsIndexes.size(); ++i) {
        if(rowsIndexes[i]<rows.size()){
            result.push_back(getRow(i));
        }
    }
    return result;
}

std::vector<Row> Table::getRows() const
{
    return rows;
}


bool Table::updateRow(Row row)
{
    rows[row.getIndex()] = row;
}

std::string Table::getName() const
{
    return name;
}

void Table::setName(const std::string &value)
{
    name = value;
}

std::vector<std::vector<std::string> > Table::getTableAsMatrix()
{
    std::vector<std::vector< std::string> > result;
    std::vector<std::string> newRow;
    for(const ColumnProperties& property : columnProperties){
        newRow.push_back(property.getName());
    }
    result.push_back(newRow);
    newRow.clear();

    for(const Row &row:rows){
        for(const std::string &column:row.getContents()){
            newRow.push_back(column);
        }
        result.push_back(newRow);
        newRow.clear();
    }
    return result;

    //       for(const auto& i : ints)
}

std::string Table::toString()
{
    std::string result;
    std::string newRow= " | ";
    for(const ColumnProperties& property : columnProperties){
        newRow.append(property.getName()+" | ");
    }
    result.append(newRow + "\n");
    newRow= " | ";
    for(const Row &row:rows){
        for(const std::string &column:row.getContents()){
            newRow.append(column + " | ");
        }
        result.append(newRow + "\n");
        newRow= " | ";
    }
    return result;
}

bool Table::setColumnType(int index, int type)
{
    bool result = false;
    if(index<columnProperties.size()){
        columnProperties[index].setType(type);
        result= true;
    }
    return result;
}

int Table::getTotalRows() const
{
    return rows.size();
}

int Table::getTotalColumns() const
{
    return columnProperties.size();
}

std::vector<ColumnProperties> Table::getColumnProperties() const
{
    return columnProperties;
}

void Table::setColumnProperties(const std::vector<ColumnProperties> &value)
{
    columnProperties = value;
}

std::string Table::getPrimaryKey() const
{
    return primaryKey;
}

void Table::setPrimaryKey(const std::string &value)
{
    primaryKey = value;
}

int Table::getPrimaryKeyIndex()
{
    return getColumnIndex(primaryKey);
}

bool Table::checkIfColumnExists(std::string name)
{
    return getColumnIndex(name) != -1;
}

int Table::getColumnIndex(std::string name)
{
    int result = -1;
    for (int i = 0; i < columnProperties.size(); ++i) {
        if(columnProperties[i].getName() == name){
            result = i;
            break;
        }
    }
    return result;
}



ColumnProperties::ColumnProperties(std::string name, int type)
{
    this->name =name;
    this->type=type;
}

std::string ColumnProperties::getName() const
{
    return name;
}

void ColumnProperties::setName(const std::string &value)
{
    name = value;
}

int ColumnProperties::getType() const
{
    return type;
}

void ColumnProperties::setType(int value)
{
    type = value;
}


Row::Row()
{

}

Row::Row(std::vector<std::string> row)
{
    for (const auto &column:row) {
        insertColumn(column);
    }
}

bool Row::updateColumn(int index, std::string data)
{
    bool result = false;
    if(validateColumn(index)){
        contents[index]=data;
        result = true;

    }
    return result;
}

std::string Row::getColumn(int index)
{
    return contents[index];
}

bool Row::insertColumn(std::string data)
{
    contents.push_back(data);
    return true;
}

bool Row::deleteColumn(int index)
{
    int result = false;
    if(index < contents.size()){
        contents.erase(contents.begin()+index);
        result = true;
    }
    return result;
}

std::string Row::toString()
{
    std::string result= "";
    for (int i = 0; i < contents.size(); ++i) {
        result.append("|" + contents[i]);
    }
    result.append("|");
    return result;
}

bool Row::validateColumn(int index)
{
    bool result = index >=0 && index < contents.size();
    if (!result){
        1+1;
        //throw std::out_of_range;
    }
    return result;

}

int Row::getIndex() const
{
    return index;
}

void Row::setIndex(int value)
{
    index = value;
}

std::vector<std::string> Row::getContents() const
{
    return contents;
}

void Row::reset()
{
    index=-1;
    contents.clear();
}

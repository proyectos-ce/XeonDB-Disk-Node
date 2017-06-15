#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include "row.h"



class ColumnProperties
{
public:
    ColumnProperties();
    ColumnProperties(std::string name, int type);
    std::string getName() const;
    void setName(const std::string &value);
    int getType() const;
    void setType(int value);

private:
    std::string name;
    int type;


};



class Table
{
public:
    Table();
    bool insertColumn(std::string name, int type);
    bool insertRow(Row row);
    bool insertRow(std::vector<std::string> dataRow);
    //bool removeColumn(std::string name);
    //bool removeColumn(int index);
    bool removeRow(int index);
    Row getRow(int index);
    std::vector<Row> getRows(std::vector<int> rowsIndexes);
    bool updateRow(Row row);
    std::string getName() const;
    void setName(const std::string &value);

private:
    std::string name;
    std::vector<Row> rows;
    std::vector<ColumnProperties> columnProperties;
    bool checkIfColumnExists(std::string name);
    int getColumnIndex(std::string name);

};



#endif // TABLE_H

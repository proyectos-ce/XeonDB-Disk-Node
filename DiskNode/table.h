#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include "row.h"
class Table
{
public:
    Table();
    bool insertColumn(std::string name, int type);
    bool insertRow(std::vector<std::string> dataRow);
    bool removeColumn(std::string name);
    bool removeColumn(int index);
    bool removeRow(int index);
    std::vector<std::string>
private:
    std::vector<Row> rows;
    std::vector<RowProperties> rowsProperties;
    bool checkIfRowExists(std::string name);
    int getRowIndex(std::string name);

};

class RowProperties
{
public:
    RowProperties();
    RowProperties(std::string name, int type);
    std::string getName() const;
    void setName(const std::string &value);
    int getType() const;
    void setType(int value);

private:
    std::string name;
    int type;

};

#endif // TABLE_H

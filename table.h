#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
//#include "row.h"


class Row
{
public:
    Row();
    Row(std::vector<std::string> row);
    bool updateColumn(int index, std::string data);
    std::string getColumn(int index);
    bool insertColumn(std::string data);
    bool deleteColumn(int index);
    std::string toString();
    int getIndex() const;
    void setIndex(int value);
    std::vector<std::string> getContents() const;
    void reset();
private:
    std::vector<std::string> contents;
    bool validateColumn(int index);
    int index = -1;
};



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
    Table(std::string name);
    bool insertColumn(std::string name, int type=-1);
    bool insertRow(Row row);
    bool insertRow(std::vector<std::string> dataRow);
    //bool removeColumn(std::string name);
    bool removeColumn(int index);
    bool removeRow(int index);
    Row getRow(int index) const;
    std::vector<Row> getRows(std::vector<int> rowsIndexes) const;
    std::vector<Row> getRows() const;
    bool updateRow(Row row);
    std::string getName() const;
    void setName(const std::string &value);
    std::vector<std::vector<std::string> > getTableAsMatrix();
    std::string toString();
    bool setColumnType(int index, int type);
    int getTotalRows()const;
    int getTotalColumns()const;


    std::vector<ColumnProperties> getColumnProperties() const;
    void setColumnProperties(const std::vector<ColumnProperties> &value);

private:
    std::string name;
    std::vector<Row> rows;
    std::vector<ColumnProperties> columnProperties;
    bool checkIfColumnExists(std::string name);
    int getColumnIndex(std::string name);

};

enum{
    INT,
    STRING,
    DOUBLE
};


#endif // TABLE_H

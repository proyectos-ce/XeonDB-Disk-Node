#ifndef ROW_H
#define ROW_H
#include <vector>
#include <string>
#include "datacontainer.h"

class Row
{
public:
    Row();
    //std::string& operator[](int column);
    bool updateColumn(int index, std::string data, int type=-1);
    std::string getColumn(int index);
    int getColumnType(int index);
    bool insertColumn(std::string data, int type);
    std::string toString();
private:
    std::vector<DataContainer> contents;
    bool validateColumn(int index);
};

#endif // ROW_H

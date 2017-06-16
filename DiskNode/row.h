#ifndef ROW_H
#define ROW_H
#include <vector>
#include <string>

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

#endif // ROW_H

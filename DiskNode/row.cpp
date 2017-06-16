#include "row.h"

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

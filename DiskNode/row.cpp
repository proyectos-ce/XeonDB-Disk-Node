#include "row.h"

Row::Row()
{

}

bool Row::updateColumn(int index, std::string data, int type)
{
    bool result = false;
    if(validateColumn(index)){

        contents[index].setData(data);
        if(type != -1){
            contents[index].setType(type);
        }
        result = true;

    }
    return result;
}

std::string Row::getColumn(int index)
{

}
/*
std::string &Row::operator[](int index)
{
    if(validateColumn(index)){
        return contents[index].getData();
    }
}
*/

int Row::getColumnType(int index)
{
    if(validateColumn(index)){
        return contents[index].getType();
    }
}

bool Row::insertColumn(std::string data, int type)
{
    contents.push_back(DataContainer(data,type));
    return true;
}

std::string Row::toString()
{
    std::string result= "";
    for (int i = 0; i < contents.size(); ++i) {
        result.append("|" + contents[i].getData());
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

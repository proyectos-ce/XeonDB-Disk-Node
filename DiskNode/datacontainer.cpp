#include "datacontainer.h"

DataContainer::DataContainer()
{

}

DataContainer::DataContainer(std::string data, int type)
{
    this->data=data;
    this->type=type;
}

int DataContainer::getType() const
{
    return type;
}

void DataContainer::setType(int value)
{
    type = value;
}

std::string DataContainer::getData() const
{
    return data;
}

void DataContainer::setData(const std::string &value)
{
    data = value;
}


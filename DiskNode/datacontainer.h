#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <boost/any.hpp>
#include <string>

class DataContainer
{
public:
    DataContainer();
    DataContainer(std::string data, int type);
    int getType() const;
    void setType(int value);


    std::string getData() const;
    void setData(const std::string &value);

private:
    int type = -1;
    std::string data;
};

enum{
    STRING,
    INT,
    DOUBLE
};

#endif // DATACONTAINER_H

#include <boost/any.hpp>
#include <iostream>
#include "row.h"
int main()
{
  boost::any a = 1;
  std::cout << boost::any_cast<int>(a)<<" type:  " << a.type().name()<< '\n';
  a = 3.14;
  std::cout << boost::any_cast<double>(a) <<" type:  " << a.type().name()<< '\n';
  a = true;
  std::cout << std::boolalpha << boost::any_cast<bool>(a) <<" type:  " << a.type().name()<< '\n';

  a = std::string{"Boost"};
  std::cout<< boost::any_cast<std::string>(a) <<" type:  " << a.type().name()<< '\n';

  Row myRow;
  myRow.insertColumn("asdasd", STRING);
  myRow.insertColumn("2", STRING);
  myRow.insertColumn("3", INT);
  myRow.insertColumn("4.45", DOUBLE);
  std::cout<< myRow.toString()<<std::endl;


  myRow.updateColumn(0,"casa1");
  myRow.updateColumn(1,"casa2");
  myRow.updateColumn(2,"casa3");
  myRow.updateColumn(3,"casa4");
  std::cout<< myRow.toString()<<std::endl;


}

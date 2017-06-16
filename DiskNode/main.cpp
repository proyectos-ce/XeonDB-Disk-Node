#include <boost/any.hpp>
#include <iostream>
#include "table.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "filemanager.h"

int main()
{
    Table myTable;
    myTable.insertColumn("id", INT );
    myTable.insertColumn("nombre", STRING );
    myTable.insertColumn("altura", DOUBLE );
    std::cout << myTable.toString();
    Row newRow;
    newRow.insertColumn("1");
    newRow.insertColumn("Tavo");
    newRow.insertColumn("170.1");
    myTable.insertRow(newRow);
    newRow.reset();
    newRow.insertColumn("2");
    newRow.insertColumn("Daniel");
    newRow.insertColumn("170.2");
    myTable.insertRow(newRow);
    newRow.reset();
    newRow.insertColumn("3");
    newRow.insertColumn("Jimena");
    newRow.insertColumn("170.3");
    myTable.insertRow(newRow);
    newRow.reset();
    std::cout << myTable.toString()<<"\n";

    myTable.removeColumn(1);
    std::cout << myTable.toString()<<"\n";


    myTable.removeRow(1);
    std::cout << myTable.toString()<<"\n";
    FileManager myFilemanager;
    myFilemanager.loadTableFromDisk("test");



}


/*
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

*/


/*

class Something
{
public:
    int weight;
    int size;
    std::string name;
    std::vector<int> list;
    // Insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Something& s)
    {
        // write out individual members of s with an end of line between each one
        os << s.weight << '\n';
        os << s.size;
        os << s.name;
        //os << s.list;
        return os;
    }

    // Extraction operator
    friend std::istream& operator>>(std::istream& is, Something& s)
    {
        // read in individual members of s
        is >> s.weight >> s.size>>s.name;
        return is;
    }
};



int main()
{
    Something s1;
    Something s2;

    s1.weight = 4;
    s1.size = 9;
    s1.name = "name1";
    s1.list.push_back(4);
    s1.list.push_back(3);
    s1.list.push_back(2);
    s1.list.push_back(1);

    std::ofstream ofs("saved.txt");

    ofs << s1; // store the object to file
    ofs.close();

    std::ifstream ifs("saved.txt");

    // read the object back in
    if(ifs >> s2)
    {
        // read was successful therefore s2 is valid
        std::cout << s2 << '\n'; // print s2 to console
        //int a[] = {1,2,3,4,5,6,7,8};
        //std::cout << a << '\n'; // print s2 to console
    }

    return 0;
}
 */

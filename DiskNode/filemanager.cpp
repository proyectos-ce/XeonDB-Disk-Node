#include "filemanager.h"

FileManager::FileManager()
{

}

Table FileManager::loadTableFromDisk(std::string filename)
{
    Table result;
    std::ifstream txtFileStream;
    filename.append(".table");
    std::string tempString="999";
    int cols,rows;
    txtFileStream.open(filename);
    if(txtFileStream.is_open()){
        getline(txtFileStream,tempString,'\n');

        std::vector<std::string> tableAttributes;
        for (int i = 0; i < 2; i++) {
            std::string parameter =tempString.substr(0,tempString.find_first_of("|"));
            tempString.erase(0, parameter.size()+1);                            //std::cout << enemyFile;
            tableAttributes.push_back(parameter);
        }
        cols = std::stoi(tableAttributes[0]);
        rows = std::stoi(tableAttributes[1]);
        std::cout<<"cols: "<<cols<<"rows:  "<<rows<<"\n";



        //std::vector<std::string> columNames;
        getline(txtFileStream,tempString,'\n');
        for (int col = 0; col < cols; ++col) {
            std::string parameter = tempString.substr(0,tempString.find_first_of("|"));
            tempString.erase(0, parameter.size()+1);                            //std::cout << enemyFile;
            //tableAttributes.push_back(parameter);
            result.insertColumn(parameter);
        }

        getline(txtFileStream,tempString,'\n');
        for (int col = 0; col < cols; ++col) {
            std::string parameter = tempString.substr(0,tempString.find_first_of("|"));
            tempString.erase(0, parameter.size()+1);                            //std::cout << enemyFile;
            //tableAttributes.push_back(parameter);
            result.setColumnType(col, std::stoi(parameter));
        }
        for (int row = 0; row < rows; ++row) {
            getline(txtFileStream,tempString,'\n');
            std::vector<std::string> contents;
            for (int i = 0; i < cols; i++) {
                std::string parameter = tempString.substr(0,tempString.find_first_of("|"));
                tempString.erase(0, parameter.size()+1);                            //std::cout << enemyFile;
                contents.push_back(parameter);
                std::cout <<"param"<<parameter<<"\n";
            }
            std::cout <<"result insert: " <<result.insertRow(contents)<<std::endl;
        }
    }
    std::cout<<result.toString()<<std::endl;
    txtFileStream.close();
    return result;



    /*
ifstream txtFileStream;
    txtFileStream.open(txtFile);
    int array[2];
    int size = 0;
    string tempString="999";
    while (getline(txtFileStream,tempString,',')){
        //cout<<tempString<<"    ";
       size++;
    }
    size--;
    txtFileStream.close();

    txtFileStream.open(txtFile);
    int i=0;
    for (int i = 0; i < size; ++i) {
        getline(txtFileStream,tempString,',');
        fseek(binFile, sizeof(int)*i ,SEEK_SET);
        //cout<<"-"<<tempString<<"-";
        array[0]=stoi(tempString);
        fwrite(array , sizeof(int) , 1 , binFile );
    }
    return size;

    */

}

bool FileManager::saveTableToDisk(Table table)
{



    /*
     *ofstream txtFileStream;
    txtFileStream.open(txtFile);
     int array[size];
     fseek(binFile, sizeof(int)*0 ,SEEK_SET);
     for (int i = 0; i < size; ++i) {
         //fseek(binFile, sizeof(int)*i ,SEEK_SET);
         fread( array, sizeof(int), 1, binFile);
         txtFileStream<<to_string(array[0])<<" ,";
     }
*/
}

bool FileManager::existsOnDisk(std::string name)
{

}

std::vector<std::string> FileManager::tablesOnDisk()
{

}

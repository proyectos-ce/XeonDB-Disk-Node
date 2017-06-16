#include "jsonutils.h"



json JSONutils::tableToJson(Table table)
{
    json result;
    result["name"] =  table.getName();
    json rows;
    for(const Row &row : table.getRows()) {
        json column;
        for(const std::string content : row.getContents()){
            column.push_back(content);
        }
        rows.push_back(column);
    }
    //json columnNames;
    std::vector<std::string> columnNames;
    std::vector<int> columnTypes;
    for(const ColumnProperties &property : table.getColumnProperties()) {
        //std::cout<<property.getName()<<"\n";
        columnNames.push_back(property.getName());
        columnTypes.push_back(property.getType());
    }    
    result["columnNames"]= columnNames;
    result["columnTypes"]= columnTypes;
    result["rows"]= rows;
    //std::cout<<"JSON:  " <<result.dump()<<std::endl;
    //json *result2 = new json;
    //result2 = result;
    return result;
}

Table JSONutils::jsonToTable(json inputJson)
{
    //std::vector<int> *test;
    //test->operator []();
    //std::cout <<"input: ------------------------------\n "<<inputJson.dump()<<"\n-------------------------------------------\n";
    //json test;
    //test = json::parse(inputJson);
    inputJson["name"]="jose";
    //inputJson["name"].get<std::string>();
    //json::get(test.);
    Table result;
    //result.setName(inputJson.get()["name"]);

    //for (int i = 0; i < inputJson["columnNames"].size(); ++i) {
    //    result.insertColumn(inputJson["columnNames"][i],inputJson["columnTypes"][i] );
   //}
    /*for (const auto &row : inputJson["rows"] ) {
        std::vector<std::string> newRow = row;
        //for(const auto &content : row){

        //}
        result.insertRow(Row(newRow));
    }*/
    return result;



}


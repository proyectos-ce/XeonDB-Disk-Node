//
// Created by Ignacio Mora on 6/15/17.
//

#include <arpa/inet.h>
#include <zconf.h>
#include <string>
#include <fstream>
#include "connectionManager.h"

ConnectionManager::ConnectionManager(std::string ip, int port) {
    tables = new TableManager();


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");

    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");

    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    while (true) {
        readFromSocket();
    }
}

void ConnectionManager::readFromSocket() {
    valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    remove("myFile.json");
    std::ofstream jsonFile("myFile.json", std::ofstream::trunc);
    jsonFile << buffer;
    jsonFile.close();
    actFromJSONFile();

}

void ConnectionManager::actFromJSONFile() {
    std::ifstream jsonFile("myFile.json");
    json j;
    jsonFile >> j;
    jsonFile.close();
    std::cout << j.dump() << std::endl;
    if (j["command"] == "identify_yourself"){
        identify();
    } else if (j["command"] == "create_table"){
        if(tables->addTable(JSONutils::jsonToTable(j))){
            std::cout << tables->getTable(j["name"]).toString() << std::endl;
        } else{
            std::cout << "srry, couldnt create table" << std::endl;
        }

    } else if (j["command"] == "update_table"){
        if (tables->isTable(j["name"])){
            int i;
            for (i = 0; i < tables->tableList.size(); i++){
                if (tables->tableList[i].getName() == j["name"])
                    tables->tableList[i] = JSONutils::jsonToTable(j);
            }
        }
    } else if (j["command"] == "get_table"){
        sendTable(j["name"]);
    }

}

void ConnectionManager::identify() {
    json identityJSON;
    identityJSON["command"] = "identifying";
    identityJSON["identity"] = "diskNode";
    std::string identityString = identityJSON.dump();
    send(sock, identityString.c_str(), identityString.size(), 0);
}

void ConnectionManager::sendTable(std::string name) {
    json answer;
    if (!tables->isTable(name)){
        answer["command"] = "answer";
        answer["found"] = false;
    } else{
        answer = JSONutils::tableToJson(tables->getTable(name));
    }
    std::string answerString = answer.dump();
    send(sock, answerString.c_str(), answerString.size(), 0);


}


//
// Created by Ignacio Mora on 6/15/17.
//

#include <arpa/inet.h>
#include <zconf.h>
#include <string>
#include <fstream>
#include "connectionManager.h"

ConnectionManager::ConnectionManager(std::string ip, int port) {

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
    readFromSocket();
//    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
}

void ConnectionManager::readFromSocket() {
    valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    std::ofstream jsonFile("myFile.json");
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
    }

}

void ConnectionManager::identify() {
    json identityJSON;
    identityJSON["command"] = "identifying";
    identityJSON["identity"] = "diskNode";
    std::string identityString = identityJSON.dump();
    send(sock, identityString.c_str(), identityString.size(), 0);
}

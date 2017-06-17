//
// Created by Ignacio Mora on 6/15/17.
//

#ifndef DISKNODE_CONNECTIONMANAGER_H
#define DISKNODE_CONNECTIONMANAGER_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#include "JSON Library/json.hpp"
#include "tableManager.h"
#include "jsonutils.h"

#define PORT 8888

using json = nlohmann::json;

class ConnectionManager {
public:
    ConnectionManager(std::string ip, int port);
    void readFromSocket();
    void actFromJSONFile();
    void identify();
    void sendTable(std::string name);

private:
    TableManager* tables;
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    //char *hello = "Hello from client";
    char buffer[1024] = {0};

};


#endif //DISKNODE_CONNECTIONMANAGER_H

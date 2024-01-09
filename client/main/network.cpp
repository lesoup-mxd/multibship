#include "network.h"
#include "connect.h"
#include "gamefield.h"
#include "settings.h"
Network::Network(const char *ip, int port)
{
    sockfd = ConnectToServer(ip, port);
}

Network::~Network()
{
    DisconnectFromServer(sockfd);
}

void Network::SendSettings(const Settings& settings) {
   std::string settingsStr = Settings::toString(); // Assuming Settings class has a toString method
   sendData(settingsStr);
}

void Network::SendGameField() {
   std::string gameFieldStr = GameField::serialize(3); // Assuming GameField class has a toString method
   sendData(gameFieldStr);
}
}

std::string Network::receiveData()
{
    // Implement receiving data from the network
}
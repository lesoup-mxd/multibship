#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <vector>

class Settings; // Forward declaration
class GameField; // Forward declaration

class Network {
public:
  Network(const char *ip, int port);
  ~Network();

  void SendSettings(const Settings& settings);
  void SendGameField();

private:
  int sockfd;
};

#endif // NETWORK_H

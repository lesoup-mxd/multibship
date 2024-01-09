#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include <string>
#include "network.h"

class GameField {
public:
 GameField(int dimensions);
 ~GameField();

 void placeShip(const std::vector<int>& coordinates, int length);
 bool hit(const std::vector<int>& coordinates);
 bool isAllShipsSunk();

 std::string serialize(int dimensions);
 static GameField deserialize(const std::string& data, int dimensions);

private:
 std::vector<std::vector<bool>> field;
 Network* network;
};

#endif // GAMEFIELD_H

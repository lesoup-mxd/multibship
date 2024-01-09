#include "gamefield.h"
#include "network.h"
#include "settings.h"

GameField::GameField(int dimensions) : field(dimensions, std::vector<bool>(dimensions, false)), network(
    new Network(Settings::getInstance().getIp().c_str(), Settings::getInstance().getPort()
    )) {}

GameField::~GameField()
{
    delete network;
}

std::string GameField::serialize(int dimensions)
{
    // Serialize logic here
    // For example, you could convert the field to a string representation
    std::string serializedField;
    for (auto row : field)
    {
        for (auto cell : row)
        {
            serializedField += cell ? "1" : "0";
        }
    }
    return serializedField;
}

GameField GameField::deserialize(const std::string &data, int dimensions)
{
    // Deserialize logic here
    // For example, you could convert the string back to a field
    GameField gameField(dimensions);
    for (int i = 0; i < data.size(); ++i)
    {
        gameField.field[i / dimensions][i % dimensions] = data[i] == '1';
    }
    return gameField;
}
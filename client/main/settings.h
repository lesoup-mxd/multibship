#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <json/json.h>

class Settings {
public:
 static Settings& getInstance() {
  static Settings instance;
  return instance;
 }

 void saveSettings(Json::Value &receivedSettings);
 int getPort();
 int getDimension();
 int getDisconnectTimeout();
 int getUID();

private:
 Settings();
 int port;
 int dimension;
 int disconnectTimeout;
 int uid;
};

#endif // SETTINGS_H
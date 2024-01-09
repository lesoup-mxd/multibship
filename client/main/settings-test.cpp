#include "settings.h"
#include <iostream>

int main() {
   // Get singleton instance
   Settings& settings = Settings::getInstance();

   // Print initial settings
   std::cout << "Initial settings:\n";
   std::cout << "Port: " << settings.getPort() << "\n";
   std::cout << "Dimension: " << settings.getDimension() << "\n";
   std::cout << "Disconnect Timeout: " << settings.getDisconnectTimeout() << "\n";
   std::cout << "UID: " << settings.getUID() << "\n";

   // Modify settings
   Json::Value modifiedSettings;
   modifiedSettings["port"] = settings.getPort() + 1;

   // Save modified settings
   settings.saveSettings(modifiedSettings);

   // Reload settings
   Settings& reloadedSettings = Settings::getInstance();

   // Check if modification was successful
   if (reloadedSettings.getPort() != settings.getPort() + 1) {
       std::cerr << "Test failed: Port was not correctly saved and loaded.\n";
       return 1;
   }

   std::cout << "Test passed: Port was correctly saved and loaded.\n";
   return 0;
}
#include "settings.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distr(1, 1000000);

Settings::Settings() {
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> const reader(builder.newCharReader());
    std::ifstream file("../settings.json");
    std::string errs;
    // Ensure the existence of settings file
    if (!file.is_open()) {
        std::ofstream newFile("../settings.json");
        // Default settings
        newFile << "{ \"port\": 8080, \"dimension\": 10, \"disconnectTimeout\": 30, \"uid\": 0 }";
        newFile.close();
    } else {
        std::stringstream buffer;
        buffer << file.rdbuf();
        // Parse the settings file
        if (!reader->parse(buffer.str().c_str(), buffer.str().c_str() + buffer.str().size(), &root, &errs)) {
            throw std::runtime_error("Failed to parse settings.json: " + errs);
        }
        file.close();
    }
    // Initialize settings
    port = root.get("port", 8080).asInt();
    dimension = root.get("dimension", 2).asInt();
    disconnectTimeout = root.get("disconnectTimeout", 30).asInt();
    uid = root.get("uid", 0).asInt();
}

void Settings::saveSettings(Json::Value &updatedSettings) {
    Json::Value currentSettings;
    Json::CharReaderBuilder builder;
    std::unique_ptr<Json::CharReader> const reader(builder.newCharReader());
    std::ifstream inFile("../settings.json");
    std::string errs;
    // Read existing settings
    if (inFile.is_open()) {
        std::stringstream buffer;
        buffer << inFile.rdbuf();
        // Parse existing settings
        if (!reader->parse(buffer.str().c_str(), buffer.str().c_str() + buffer.str().size(), &currentSettings, &errs)) {
            throw std::runtime_error("Failed to parse settings.json: " + errs);
        }
        inFile.close();
    }
    // Update settings with new values
    for (const auto &key : updatedSettings.getMemberNames()) {
        currentSettings[key] = updatedSettings[key];
    }
    // Write updated settings back to file
    std::ofstream outFile("../settings.json");
    Json::StreamWriterBuilder writerBuilder;
    std::unique_ptr<Json::StreamWriter> writer(writerBuilder.newStreamWriter());
    writer->write(currentSettings, &outFile);
    outFile.close();
}


int Settings::getPort() {
    return port;
}

int Settings::getDimension() {
    return dimension;
}

int Settings::getDisconnectTimeout() {
    return disconnectTimeout;
}

int Settings::getUID() {
    if (uid == 0) {
        uid = distr(gen);
        // Save newly generated UID
        Json::Value newUidSetting;
        newUidSetting["uid"] = uid;
        saveSettings(newUidSetting);
    }
    return uid;
}


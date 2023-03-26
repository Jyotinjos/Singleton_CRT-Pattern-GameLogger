#include "GameLogger.h"
#include<iostream>


namespace Game {
    GameLogger::GameLogger() {
        GameManager::getLogfile().open("game.log");
        if (!GameManager::getLogfile().is_open()) {
            std::cerr << "Error opening log file" << std::endl;
        }
    }

    GameLogger::~GameLogger() {
        if (GameManager::getLogfile().is_open()) {
            GameManager::getLogfile().close();
        }
    }

    void GameLogger::startGame() {
        std::ostringstream ss;
        ss << "JO Sports Presenting you live broadcast! Lets Football [18:00]" << std::endl;
        writeLog(ss.str());
    }

    void GameLogger::endGame() {
        std::ostringstream ss;
        ss << "Thanks for watching JO football ..|^|.." << std::endl;
        writeLog(ss.str());
    }

    void GameLogger::log(const std::string& message) {
        std::ostringstream ss;
        ss << message << std::endl;
        writeLog(ss.str());
    }

    void GameLogger::writeLog(const std::string& message) {
        if (GameManager::getLogfile().is_open()) {
            GameManager::getLogfile() << message;
        }
    }
}

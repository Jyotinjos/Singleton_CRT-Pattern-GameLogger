#include "FootballManager.h"
#include<iostream>
#include<mutex>

namespace Game 
{
    void FootballManager::startGame() {
  
    }

    void FootballManager::endGame() {
        
    }

    void FootballManager::footallManagerTagComments(const std::string& s) {
        std::unique_lock<std::mutex> lock(fileMutex_);
        GameManager::getLogfile().open("manager.log", std::ios::app);
        if (!GameManager::getLogfile().is_open()) {
            throw std::runtime_error("Failed to log manager comments!");
        }
        GameManager::getLogfile() << s << std::endl;
        GameManager::getLogfile().close();
    }

}

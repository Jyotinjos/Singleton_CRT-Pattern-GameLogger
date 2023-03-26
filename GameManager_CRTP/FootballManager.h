#pragma once
#include <string>
#include "GameManager.h"
#include "GameLogger.h"
#include<thread>
#include<mutex>


namespace Game {
    class FootballManager : public GameManager<FootballManager>
    {
    private:
        friend class GameManager<FootballManager>;
        FootballManager() = default;
    public:
        std::mutex fileMutex_;
        void startGame() override;
        void endGame() override;
        void footallManagerTagComments(const std::string &s);
    };
}

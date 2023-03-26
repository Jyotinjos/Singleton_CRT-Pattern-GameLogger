#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "GameManager.h"

namespace Game 
{
    class GameLogger : public GameManager<GameLogger> 
    {
    private:
        GameLogger();
        friend class GameManager<GameLogger>;
        ~GameLogger();
    public:
        void startGame() override;
        void endGame() override;
        void log(const std::string& message);
        void writeLog(const std::string& message);  
    };
}

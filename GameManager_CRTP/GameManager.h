#pragma once
#define TRY_ME 3

namespace Game 
{
    template<typename T>
    class GameManager 
    {
    private:
        std::ofstream logFile;
    protected:
        GameManager() = default;
        GameManager(const GameManager&) = delete;
        GameManager& operator=(const GameManager&) = delete;
    public:
        static T& getInstance() {  //meyer's singleton
            static T instance;
            return instance;
        }
        std::ofstream& getLogfile();
        virtual void startGame() = 0;
        virtual void endGame() = 0;
        
    };
    template<typename T>
    inline std::ofstream& GameManager<T>::getLogfile()
    {
        return logFile;
    }
}


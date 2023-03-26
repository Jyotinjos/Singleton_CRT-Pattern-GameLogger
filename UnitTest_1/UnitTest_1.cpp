#include "pch.h"
#include "CppUnitTest.h"
#include "../../GameManager_CRTP/GameManager_CRTP/GameManager.h"
#include "../GameManager_CRTP/GameLogger.h"
#include "../GameManager_CRTP/FootballManager.h"
#include<CppUnitTestAssert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace GameTests
{

    TEST_CLASS(GameManagerTest)
    {
    public:
        TEST_METHOD(TestGetInstance)
        {
            auto& instance1 = Game::GameLogger::getInstance();
            auto& instance2 = Game::GameLogger::getInstance();
            Assert::AreEqual(&instance1, &instance2, L"Instances are not equal");
        }

        TEST_METHOD(TestGetLogFile)
        {
            auto& instance = Game::GameLogger::getInstance();
            auto& logFile = instance.getLogfile();
            Assert::IsTrue(logFile.is_open(), L"Log file is not open");
        }
    };
    

    TEST_CLASS(GameLoggerTests)
    {
    public:
        TEST_METHOD(TestGameLoggerGetInstance)
        {
            auto& logger1 = Game::GameLogger::getInstance();
            auto& logger2 = Game::GameLogger::getInstance();
            Assert::AreEqual(&logger1, &logger2);
        }

        TEST_METHOD(TestGameLoggerLog)
        {
            auto& logger = Game::GameLogger::getInstance();
            logger.log("Test log message");
            //  Check if log was written to file
        }
    };

    TEST_CLASS(FootballManagerTests)
    {
    public:
        TEST_METHOD(TestFootballManagerTagComments)
        {
            // Arrange
            auto& manager = Game::FootballManager::getInstance();
            std::string message = "Manager comment";

            // Act
            manager.footallManagerTagComments(message);

            // Assert
            std::ifstream file("manager.log");
            std::string line;
            bool found = false;
            while (std::getline(file, line)) {
                if (line == message) {
                    found = true;
                    break;
                }
            }
            Assert::IsTrue(found);
        }
    };
}

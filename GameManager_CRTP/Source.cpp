#include <iostream>
#include <thread>
#include "GameLogger.h"
#include "FootballManager.h"

int main() {
    // Get the game logger instance
    auto& logger = Game::GameLogger::getInstance();

    // Log some messages
    logger.log("Starting game");
    logger.log("Initializing football manager");

    
    auto& manager = Game::FootballManager::getInstance(); // Get the football manager instance

    
    std::mutex file_mutex;
    // Create two threads to that logs manager's comments from his microphone
    std::thread t1{ [&file_mutex]() {
        auto& manager = Game::FootballManager::getInstance(); // Get the football manager instance
        std::lock_guard<std::mutex> lock(file_mutex);
        manager.footallManagerTagComments("Relax, Messi! Go for it");
    } };

    std::thread t2{ [&file_mutex]() {
        auto& manager = Game::FootballManager::getInstance(); // Get the football manager instance
        std::lock_guard<std::mutex> lock(file_mutex);
        manager.footallManagerTagComments("Hey, Di Mario! Brother focus!");
    } };

    // Wait for the threads to finish playing the game
    t1.join();
    t2.join();

    // Log some more messages
    logger.log("Game over");
    logger.log("Closing game logger");

    return 0;
}


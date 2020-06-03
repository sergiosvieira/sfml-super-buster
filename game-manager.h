#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "game-header.h"
#include "game-state.h"
#include "level.h"

/**
 * @brief The Manager class
 */
class Manager {
public:
    /**
     * @brief Manager
     * @param state
     */
    Manager(State state = State::kLicensed);
    /**
     * @brief loop
     * @param window
     */
    void loop(sf::RenderWindow& window);
    /**
     * @brief addLevel
     * @param level
     */
    void addLevel(const Level& level);
    /**
     * @brief addPlayer
     * @param player
     */
    void addPlayer(ObjectPtr player);
protected:
    ObjectPtr player = nullptr;
    QueueOfEventPtr queue;
    VectorOfEventPtr activatedEvents;
    unsigned short currentLevelIndex = 0;
    VectorOfLevel levels;
    State state = State::kLicensed;
    bool running = true;
    void update(VectorOfObjectPtr v, float dt);
    void render(VectorOfObjectPtr v, sf::RenderWindow& rw);
};

#endif // GAME_H

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "game-header.h"

class EventManager {
    sf::Clock clock;
    sf::Time elapsed;
    QueueOfEventPtr queue;
    VectorOfObjectPtr activatedObjects;
    void checkTimeUp();
    void clean();
public:
    /**
     * @brief EventManager
     */
    EventManager();
    /**
     * @brief update
     */
    void update();
    const VectorOfObjectPtr &getObjects() const;
};

#endif // EVENTMANAGER_H

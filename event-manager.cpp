#include "event-manager.h"
#include "event.h"
#include "object.h"

EventManager::EventManager() {

}

void EventManager::checkTimeUp() {
    EventPtr event = queue.front();
    if (event != nullptr
            && elapsed > event->wait) {
        if (queue.size() > 0) {
            if (event->type != EventType::None) {
                //ObjectPtr object = process(queue.front());
                ObjectPtr object = nullptr;
                if (object != nullptr) activatedObjects.push_back(object);
            }
            elapsed -= event->wait;
            queue.pop_front();
        }
    }
}

void EventManager::clean() {
    auto lambda = [](const ObjectPtr& object){
        return object->isAlive();
    };
    auto remove = std::remove_if(activatedObjects.begin(),
                                 activatedObjects.end(),
                                 lambda);
    activatedObjects.erase(remove);
}

void EventManager::update() {
    checkTimeUp();
    clean();
}

const VectorOfObjectPtr &EventManager::getObjects() const
{
    return activatedObjects;
}

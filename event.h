#ifndef EVENT_H
#define EVENT_H

#include <SFML/System/Time.hpp>

enum class EventType {None, Ball, Enemy1, Item1};

using Event = struct {
    EventType type = EventType::None;
    sf::Time wait = sf::seconds(0);
};

#endif // EVENT_H

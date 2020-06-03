#ifndef GAMEHEADER_H
#define GAMEHEADER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include "event.h"

/** Forwarding declarations **/
class Frame;
class Object;

// Smart Pointers
using ObjectPtr = std::shared_ptr<Object>;
using TexturePtr = std::shared_ptr<sf::Texture>;
using SpritePtr = std::shared_ptr<sf::Sprite>;
using FramePtr = std::shared_ptr<Frame>;
using EventPtr = std::shared_ptr<Event>;
// STL Data Structures
using VectorOfEventPtr = std::vector<EventPtr>;
using VectorOfObjectPtr = std::vector<ObjectPtr>;
using QueueOfEventPtr = std::deque<EventPtr>;

#endif // GAMEHEADER_H

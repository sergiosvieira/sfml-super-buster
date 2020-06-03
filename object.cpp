#include "object.h"
#include "frame.h"

Object::Object(FramePtr frame):
                frame(frame) {

}

void Object::render(sf::RenderWindow &rw)
{
    if (frame != nullptr) {
        frame->render(rw);
    }
}

bool Object::isAlive() const {
    return alive;
}

void Object::setAlive(bool value)
{
    alive = value;
}

void Object::setPosition(const sf::Vector2f& pos) {
    this->pos = pos;
}

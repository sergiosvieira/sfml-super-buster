#include "frame.h"

Frame::Frame(TexturePtr texture,
      const sf::IntRect& rect):
        texture(texture),
        rect(rect) {
    if (texture != nullptr) sprite.setTexture(*this->texture);
}

void Frame::setPosition(const sf::Vector2f &pos) {
    sprite.setPosition(pos);
}

void Frame::setFreeze(bool value) {
    this->freeze = value;
}

bool Frame::isFroozen() const {
    return this->freeze;
};

sf::IntRect Frame::getRect() const {
    sf::IntRect result = {
        control.current * rect.width,
        0,
        rect.width,
        rect.height
    };
    return result;
}

void Frame::updateFrame() {
    if (!isFroozen()) {
        elapsed += clock.restart();
        while (elapsed > update) {
            if (control.current + 1 > control.last) {
                control.current = control.first;
            } else {
                ++control.current;
            }
            elapsed -= update;
        }
    }
}

void Frame::render(sf::RenderWindow &rw) {
    sprite.setTextureRect(getRect());
    rw.draw(sprite);
}

void Frame::setControl(const Control &control) {
 this->control = control;
}

void Frame::setFPS(float fps) {
    if (fps > 0.0) this->update = sf::seconds(1.f/fps);
}

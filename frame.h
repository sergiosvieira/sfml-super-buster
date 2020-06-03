#ifndef FRAME_H
#define FRAME_H

#include "game-header.h"

/**
 * @brief The Frame class
 */
class Frame
{
    sf::Clock clock;
    sf::Time update = sf::seconds(1.f/10.f);
    sf::Time elapsed = clock.restart();
protected:
    TexturePtr texture = nullptr;
    sf::Sprite sprite;
    bool freeze = false;
    sf::IntRect rect = {};
    using Control = struct {
        unsigned short first = 0;
        unsigned short last = 0;
        unsigned short current = 0;
    };
    Control control = {0, 0, 0};
public:
    /**
     * @brief Frame
     * @param texture
     * @param rect
     */
    Frame(TexturePtr texture,
          const sf::IntRect& rect);
    /**
     * @brief setControl
     * @param control
     */
    void setControl(const Control& control);
    /**
     * @brief setPosition
     * @param pos
     */
    void setPosition(const sf::Vector2f& pos);
    /**
     * @brief setFreeze
     * @param value
     */
    void setFreeze(bool value);
    /**
     * @brief isFroozen
     */
    bool isFroozen() const;
    /**
     * @brief getRect
     * @return
     */
    sf::IntRect getRect() const;
    /**
     * @brief updateFrame
     */
    void updateFrame();
    /**
     * @brief render
     * @param rw
     */
    void render(sf::RenderWindow& rw);
    void setFPS(float fps);
};

#endif // FRAME_H

#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include "game-header.h"

/**
 * @brief The Object class
 */
class Object {
protected:
    bool alive = true;
    FramePtr frame = nullptr;
    sf::Vector2f pos = {};
public:
    /**
     * @brief Object
     * @param frame
     * @param pos
     */
    Object(FramePtr frame);
    /**
     * @brief update
     * @param dt
     */
    virtual void update(float dt) = 0;
    /**
     * @brief render
     * @param rw
     */
    virtual void render(sf::RenderWindow& rw);
    /**
     * @brief isAlive
     * @return
     */
    bool isAlive() const;
    /**
     * @brief setAlive
     * @param value
     */
    void setAlive(bool value);
    /**
     * @brief setPosition
     * @param pos
     */
    void setPosition(const sf::Vector2f& pos);
    /**
     * @brief getFrame
     * @return
     */
    FramePtr getFrame() const {
        return frame;
    }
};

#endif // OBJECT_H

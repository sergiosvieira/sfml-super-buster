#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

/**
 * @brief The Player class
 */
class Player: public Object {
    FramePtr frame = nullptr;
    TexturePtr texture = nullptr;
    enum class Direction {
      kLeft,
      kRight
    };
    enum class State {
      kIdle,
      kWalking,
      kJumping,
      kShooting,
      kDead
    };
    Direction direction = Direction::kRight;
    State state = State::kIdle;
public:
    /**
     * @brief Player
     */
    Player(FramePtr frame);
    /**
     * @brief update
     * @param dt
     */
    void update(float dt) override;
};

#endif // PLAYER_H

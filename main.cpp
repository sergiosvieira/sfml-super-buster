#include "game-header.h"
#include "game-consts.h"
#include "game-manager.h"
#include "frame.h"
#include "player.h"

ObjectPtr makePlayer() {
    TexturePtr texture = TexturePtr(new sf::Texture());
    texture->loadFromFile("idle.png");
    FramePtr frame = FramePtr(new Frame(texture, {0, 0, 32, 32}));
    frame->setControl({0, 3, 0});
    ObjectPtr result = ObjectPtr(new Player(frame));
    return result;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(kWidth, kHeight), "Super Buster Clone");
    Manager m;
    m.addPlayer(makePlayer());
    m.loop(window);
    return 0;
}

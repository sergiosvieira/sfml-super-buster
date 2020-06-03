#include "game-manager.h"
#include "game-consts.h"
#include "frame.h"

Manager::Manager(State state): state(state) {
}

void Manager::loop(sf::RenderWindow &window) {
    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                //if (map[LoopState::kKeyPressed] != nullptr) keypressed(event.key);
            } else if (event.type == sf::Event::KeyReleased) {
                //if (keyreleased != nullptr) keyreleased();
            }
        }
        elapsed += clock.restart();
        while (elapsed >= kUpdateMs) {
            if (levels.size() > 0) {
                update(levels[currentLevelIndex].map, kUpdateMs.asSeconds());
                update(levels[currentLevelIndex].elements, kUpdateMs.asSeconds());
            }
            if (player != nullptr) player->update(kUpdateMs.asSeconds());
            elapsed -= kUpdateMs;
        }
        window.clear(sf::Color::Black);
        if (levels.size() > 0) {
            render(levels[currentLevelIndex].map, window);
            render(levels[currentLevelIndex].elements, window);
        }
        if (player != nullptr
                && player->getFrame() != nullptr) {
            player->render(window);
            FramePtr frame = player->getFrame();
            frame->updateFrame();
        }
        window.display();
    }
}

void Manager::addLevel(const Level& level) {
    levels.push_back(level);
}

void Manager::update(VectorOfObjectPtr v, float dt) {
    for (auto e: v) {
        e->update(dt);
    }
}

void Manager::render(VectorOfObjectPtr v, sf::RenderWindow& rw) {
    for (auto e: v) {
        e->render(rw);
    }
}
void Manager::addPlayer(ObjectPtr player) {
    this->player = player;
}

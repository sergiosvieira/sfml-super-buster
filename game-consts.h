#ifndef GAMECONSTS_H
#define GAMECONSTS_H

#include <SFML/System/Time.hpp>

static const int kWidth = 600;
static const int kHeight = 480;
static const int kFPS = 30;
static const sf::Time kUpdateMs = sf::seconds(1.f/static_cast<float>(kFPS));

#endif // GAMECONSTS_H

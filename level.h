#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "object.h"

using VectorOfObjectPtr = std::vector<ObjectPtr>;

struct Level {
    VectorOfObjectPtr map;
    VectorOfObjectPtr elements;
    VectorOfEventPtr events;
};

using VectorOfLevel = std::vector<Level>;

#endif // LEVEL_H

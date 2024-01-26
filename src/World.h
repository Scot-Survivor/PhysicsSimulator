//
// Created by jkshi on 22/01/2024.
//

#ifndef PHYSICSSIMULATOR_WORLD_H
#define PHYSICSSIMULATOR_WORLD_H


#include <cmath>

class World {
public:
    constexpr const static float minBodySize = 0.1f * 0.1f;
    constexpr const static float maxBodySize = 64.0f * 64.0f;

    constexpr const static float minDensity = 0.2f;  // g/cm^3
    constexpr const static float maxDensity = 21.4f; // 1000000000000000.0f; // g/cm^3

    World();
    ~World() = default;
};


#endif //PHYSICSSIMULATOR_WORLD_H

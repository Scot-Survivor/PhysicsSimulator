//
// Created by jkshi on 22/01/2024.
//

#ifndef PHYSICSSIMULATOR_VECTORMATH_H
#define PHYSICSSIMULATOR_VECTORMATH_H
#include "imgui.h"
//
// Created by jkshi on 22/01/2024.
//

#include <cmath>
#include "VectorMath.h"
namespace ImGui {
    float static length(ImVec2 vec) {
        return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
    }
    float static magnitude(ImVec2 vec) {
        return length(vec);
    }

    float static distance(ImVec2 a, ImVec2 b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return (float) std::sqrt(
                std::pow(dx, 2) + std::pow(dy, 2)
        );
    }
    void static normalise(ImVec2* vec) {
        auto length = (float) ImGui::length(*vec);
        float x = vec->x / length;
        float y = vec->y / length;
        vec->x = x;
        vec->y = y;
    }
    float static dot(ImVec2 a, ImVec2 b) {
        return a.x * b.x + a.y * a.y;
    }
    float static crossProduct(ImVec2 a, ImVec2 b) {
        return a.x * b.y - a.y * b.x;
    }

    ImVec2 static mul(float a, ImVec2 b) {
        return {a * b.x, a * b.y};
    }

    ImVec2 static add(ImVec2 a, ImVec2 b) {
        return {a.x + b.x, a.y + b.y};
    }
}
#endif //PHYSICSSIMULATOR_VECTORMATH_H

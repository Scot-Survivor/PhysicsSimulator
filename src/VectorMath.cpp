//
// Created by jkshi on 22/01/2024.
//
/*
#include <cmath>
#include "VectorMath.h"
namespace ImGui {
    double static length(ImVec2 vec) {
        return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
    }
    double static magnitude(ImVec2 vec) {
        return length(vec);
    }

    double static distance(ImVec2 a, ImVec2 b) {
        float dx = a.x - b.x;
        float dy = a.y - b.y;
        return std::sqrt(
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
    double static dot(ImVec2 a, ImVec2 b) {
        return a.x * b.x + a.y * a.y;
    }
    double static crossProduct(ImVec2 a, ImVec2 b) {
        return a.x * b.y - a.y * b.x;
    }

    ImVec2 static mul(double a, ImVec2 b) {
        return ImVec2(a * b.x, a * b.y);
    }

    ImVec2 static add(ImVec2 a, ImVec2 b) {
        return {a.x + b.x, a.y + b.y};
    }
} */
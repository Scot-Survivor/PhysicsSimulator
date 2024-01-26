//
// Created by jkshi on 22/01/2024.
//

#ifndef PHYSICSSIMULATOR_RIGIDBODY_H
#define PHYSICSSIMULATOR_RIGIDBODY_H


#include <string>
#include "imgui.h"

enum ShapeType {
    CIRCLE = 0,
    BOX = 1
};

class RigidBody {
private:
    ImVec2 m_pos;
    ImVec2 m_linearVelocity;
    float m_rotation;
    float m_rotationalVelocity;

    float m_mass;
    float m_density;
    float m_restitution;
    float m_area;

    bool m_isStatic;

    float m_radius;
    float m_width;
    float m_height;

    ShapeType m_shapeType;
public:

    RigidBody(ImVec2 p_pos, float p_mass, float p_density, float p_restitution, bool p_isStatic, float p_radius);
    RigidBody(ImVec2 p_pos, float p_mass, float p_density, float p_restitution,
              bool p_isStatic, float p_width, float p_height);
    ~RigidBody() = default;

    std::string checkInternalValues();

    void draw(ImDrawList *drawList);
    void physicsTick();

    void set_position(ImVec2 p_pos);
    void set_rotation(float p_rotation);
    void set_linear_velocity(ImVec2 p_linearVelocity);
    void set_rotational_velocity(float p_rotationalVelocity);
};


#endif //PHYSICSSIMULATOR_RIGIDBODY_H

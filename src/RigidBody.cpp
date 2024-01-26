//
// Created by jkshi on 22/01/2024.
//
#define _USE_MATH_DEFINES

#include <algorithm>
#include "RigidBody.h"
#include "VectorMath.h"
#include "World.h"

RigidBody::RigidBody(ImVec2 p_pos, float p_mass, float p_density, float p_restitution, bool p_isStatic, float p_radius) {
    m_pos = p_pos;
    m_linearVelocity = ImVec2(0.0, 0.0);
    m_rotation = 0.0;
    m_rotationalVelocity = 0.0;
    m_mass = p_mass;
    m_density = p_density;
    m_restitution = std::clamp(p_restitution, 0.0f, 1.0f);
    m_isStatic = p_isStatic;
    m_radius = p_radius;
    m_shapeType = CIRCLE;
}

RigidBody::RigidBody(ImVec2 p_pos, float p_mass, float p_density, float p_restitution, bool p_isStatic,
                     float p_width, float p_height) {
    m_pos = p_pos;
    m_linearVelocity = ImVec2(0.0, 0.0);
    m_rotation = 0.0f;
    m_rotationalVelocity = 0.0f;
    m_mass = p_mass;
    m_density = p_density;
    m_restitution = std::clamp(p_restitution, 0.0f, 1.0f);
    m_isStatic = p_isStatic;
    m_width = p_width;
    m_height = p_height;
    m_shapeType = BOX;
}

std::string RigidBody::checkInternalValues() {
    if (this->m_density < World::minDensity) {
        return "Density is too small.";
    } else if (this->m_density > World::maxDensity) {
        return "Density is too big.";
    }
    float area;
    if (this->m_shapeType == CIRCLE) {
        area = m_radius * m_radius * M_PI;
    } else {
        area = m_width * m_height;
    }
    if (area < World::minBodySize) {
        return "This body is too small.";
    } else if (area > World::maxBodySize) {
        return "This body is too large.";
    }
    return "";
}

void RigidBody::draw(ImDrawList *drawList) {
    if (m_shapeType == CIRCLE) {
        drawList->AddCircleFilled(m_pos, m_radius, IM_COL32(255, 255, 255, 255));
    } else {
        // Generate where m_pos is the middle
        ImVec2 topLeft = ImVec2(m_pos.x - m_width / 2, m_pos.y - m_height / 2);
        ImVec2 bottomRight = ImVec2(m_pos.x + m_width / 2, m_pos.y + m_height / 2);
        drawList->AddRectFilled(topLeft, bottomRight, IM_COL32(255, 255, 255, 255));
        // drawList->AddRectFilled(m_pos, ImVec2(m_pos.x + m_width, m_pos.y + m_height), IM_COL32(255, 255, 255, 255));
    }
}

void RigidBody::physicsTick() {
    if (m_isStatic) return;
    /* m_pos.x += m_linearVelocity.x;
    m_pos.y += m_linearVelocity.y; */
    m_pos = ImGui::add(m_pos, m_linearVelocity);
    m_rotation += m_rotationalVelocity;
}

void RigidBody::set_position(ImVec2 p_pos) {
    m_pos = p_pos;
}

void RigidBody::set_rotation(float p_rotation) {
    m_rotation = p_rotation;
}

void RigidBody::set_linear_velocity(ImVec2 p_linearVelocity) {
    m_linearVelocity = p_linearVelocity;
}

void RigidBody::set_rotational_velocity(float p_rotationalVelocity) {
    m_rotationalVelocity = p_rotationalVelocity;
}

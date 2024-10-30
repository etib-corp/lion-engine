/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** PatternComponent
*/

#ifndef PATTERNCOMPONENT_HPP_
#define PATTERNCOMPONENT_HPP_

#include "Maths/Vector3.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include <functional>

/**
 * @brief Enum for the end of a pattern
 *
 * LOOP: The pattern will loop
 * STAY: The pattern will stay at the end position
 * HIDE: The pattern will hide at the end position
 * DESTROY: The pattern will be destroyed at the end position
 */
enum PatternEnd
{
    LOOP,   // The pattern will loop
    STAY,   // The pattern will stay at the end position
    HIDE,   // The pattern will hide at the end position
    DESTROY // The pattern will be destroyed at the end position
};

struct PatternComponent
{
    LE::Vector3<float> velocity; // The velocity of the entity
    std::string pattern_name;    // The name of the pattern
    LE::Vector3<float> end_pos;  // The end position of the pattern
    double speed;                // The speed of the pattern
    double seek;                 // The seek of the pattern
    PatternEnd end;              // The end of the pattern
};

/**
 * @brief Create a pattern component
 *
 * @param pattern_name The name of the pattern
 * @param end_pos The end position of the pattern
 * @param speed The speed of the pattern
 * @param end The end of the pattern
 * @return PatternComponent The pattern component
 */
std::ostream &operator<<(std::ostream &os, const PatternComponent &pattern);

/**
 * @brief Create a pattern component
 *
 * @param pattern_name The name of the pattern
 * @param end_pos The end position of the pattern
 * @param speed The speed of the pattern
 * @param end The end of the pattern
 * @return PatternComponent The pattern component
 */
PatternComponent createPatternComponent(std::string pattern_name, LE::Vector3<float> end_pos, double speed, PatternEnd end);

#endif /* !PATTERNCOMPONENT_HPP_ */

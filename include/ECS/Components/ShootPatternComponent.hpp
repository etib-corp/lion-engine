/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ShootPatternComponent
*/

#pragma once
#include <string>

enum ShootPatternEnd
{
    LLOOP, ///< The pattern will loop
    TIME,  ///< The pattern will stay at the end position
};

struct ShootPatternComponent
{
    std::string pattern_name; ///< The name of the pattern
    double speed;             ///< The speed of the pattern
    ShootPatternEnd end;      ///< The end of the pattern
    double time;              ///< The time of the pattern
    double currentTime;       ///< The current time of the pattern
};

/**
 * @brief Create a shoot pattern component
 *
 * @param pattern_name The name of the pattern
 * @param speed The speed of the pattern
 * @param end The end of the pattern
 * @param time The time of the pattern
 * @return ShootPatternComponent The shoot pattern component
 */
ShootPatternComponent createShootPatternComponent(std::string pattern_name, double speed, ShootPatternEnd end, double time);
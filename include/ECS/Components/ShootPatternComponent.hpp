/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ShootPatternComponent
*/

#pragma once
#include <string>

enum ShootPatternEnd {
    LLOOP,
    TIME,
};

struct ShootPatternComponent {
    std::string pattern_name;
    double speed;
    ShootPatternEnd end;
    double time;
    double currentTime;
};

ShootPatternComponent createShootPatternComponent(std::string pattern_name, double speed, ShootPatternEnd end, double time);
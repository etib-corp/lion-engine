/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** PaternSystem
*/

#ifndef PATTERNSYSTEM_HPP_
#define PATTERNSYSTEM_HPP_

#include "ECS/SystemManager.hpp"
#include <functional>
#include <map>
#include "ECS/Components/PatternComponent.hpp"

/**
 * @class PatternSystem
 * @brief The PatternSystem class is responsible for handling patterns
 */
class PatternSystem : public System
{
public:
    /**
     * @brief Construct a new PatternSystem object
     */
    PatternSystem();

    /**
     * @brief Destroy the PatternSystem object
     */
    ~PatternSystem();

    /**
     * @brief Update the system
     * This function will be used to update the system
     */
    void update(LE::Ecs *ecs, float dt) override;

    /**
     * @brief Add a pattern
     * This function will be used to add a pattern
     *
     * @param name The name of the pattern
     * @param pattern The pattern to add
     * @return bool True if the pattern was added
     */
    bool addPattern(const std::string &name, std::function<void(PatternComponent &pattern, TransformComponent &transform)> pattern)
    {
        _patterns[name] = pattern;
        return true;
    }

protected:
private:
    std::map<std::string, std::function<void(PatternComponent &pattern, TransformComponent &transform)>> _patterns; ///< The patterns
};

#endif /* !PATTERNSYSTEM_HPP_ */

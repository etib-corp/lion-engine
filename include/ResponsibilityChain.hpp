/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ResponsibilityChain
*/

#ifndef RESPONSIBILITYCHAIN_HPP_
#define RESPONSIBILITYCHAIN_HPP_

#include <iostream>
#include <vector>

#include "PackUnpack.hpp"
#include "ECS/Ecs.hpp"
#include "Logger.hpp"

namespace LE
{

    using CallBackFunc = std::function<bool(const Request &, std::shared_ptr<Ecs> &)>;

    class ResponsibilityChain
    {
    public:
        void setActionCallback(char action, const std::vector<CallBackFunc> &callbacks)
        {
            _actionCallbacks[action] = callbacks;
        }

        void addActionCallback(char action, const CallBackFunc &callback)
        {
            _actionCallbacks[action].push_back(callback);
        }

        [[nodiscard]] std::vector<CallBackFunc> getActionCallbacks(char action) const
        {
            auto it = _actionCallbacks.find(action);
            if (it != _actionCallbacks.end())
            {
                return it->second;
            }
            return {};
        }

        void clearActionCallbacks(char action)
        {
            _actionCallbacks.erase(action);
        }

        void excuteCallBacks(const Request &req, std::shared_ptr<Ecs> &ecs)
        {
            auto callbacks = getActionCallbacks(req.header.Action);
            
            for (const auto& callback : callbacks)
            {
                std::cout << req.header.Action << std::endl;
                if (callback(req, ecs)) {
                    break;
                }
            }
        }

    private:
        std::unordered_map<char, std::vector<CallBackFunc>> _actionCallbacks;
    };

} // namespace LE

#endif /* !RESPONSIBILITYCHAIN_HPP_ */

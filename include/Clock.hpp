/*
** EPITECH PROJECT, 2024
** graphical
** File description:
** Clock
*/

#pragma once

#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>


/**
 * @namespace LE
 * @brief Namespace for the Lion Engine
 */
namespace LE {
    /**
     * @class Clock
     *
     * @brief A class to manage the game clock
     */
    class Clock {
        public:
            using Callback = std::function<void()>;     ///< Callback type

            /**
             * @brief Construct a new Game Clock object
             */
            Clock() : running_(false) {}

            /**
             * @brief Destroy the Game Clock object
             */
            ~Clock()
            {
                stop();
            }

            /**
             * @brief Add a callback to the clock
             *
             * @param cb The callback to add
             * @param intervalMs The interval in milliseconds
             */
            void addCallback(Callback cb, int intervalMs)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                callbacks_.emplace_back(cb, intervalMs, std::chrono::steady_clock::now());
            }

            /**
             * @brief Start the clock
             */
            void start()
            {
                running_ = true;
                clockThread_ = std::thread([this]() { this->run(); });
            }

            /**
             * @brief Stop the clock
             */
            void stop()
            {
                running_ = false;
                if (clockThread_.joinable())
                {
                    clockThread_.join();
                }
            }

            /**
             * @brief Restart the clock
             *
             * @return std::size_t The elapsed time since the last restart
             * @note This funciton has no impact on the callback execution or the callback interval
             */
            std::size_t restart()
            {
                auto now = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastFrame).count();
                _lastFrame = now;
                return elapsed;
            }

            /**
             * @brief Get the elapsed time
             *
             * @return std::size_t The elapsed time since the last restart
             * @note This funciton has no impact on the callback execution or the callback interval
             */
            std::size_t getElapsedTime() const
            {
                auto now = std::chrono::high_resolution_clock::now();
                return std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastFrame).count();
            }

        private:
            /**
             * @struct TimedCallback
             *
             * @brief A struct to store a callback with a time interval
             */
            struct TimedCallback {
                Callback cb;
                int intervalMs;
                std::chrono::steady_clock::time_point lastExecution;

                TimedCallback(Callback c, int interval, std::chrono::steady_clock::time_point lastExec)
                    : cb(c), intervalMs(interval), lastExecution(lastExec) {}
            };

            std::vector<TimedCallback> callbacks_;                          ///< The list of callbacks
            std::mutex mutex_;                                              ///< The mutex
            std::thread clockThread_;                                       ///< The clock thread
            bool running_;                                                  ///< The running state
            std::chrono::high_resolution_clock::time_point _lastFrame;      ///< The last frame time


            /**
             * @brief Run the clock
             * @note This function is called by the clock thread
             */
            void run()
            {
                while (running_) {
                    auto now = std::chrono::steady_clock::now();

                    std::lock_guard<std::mutex> lock(mutex_);
                    for (auto& callback : callbacks_)
                    {
                        auto durationSinceLastExecution = std::chrono::duration_cast<std::chrono::milliseconds>(now - callback.lastExecution);
                        if (durationSinceLastExecution.count() >= callback.intervalMs)
                        {
                            callback.cb();
                            callback.lastExecution = now;
                        }
                    }
                }
            }
    };

}

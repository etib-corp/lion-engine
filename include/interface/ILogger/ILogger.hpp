/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ILogger
*/

#ifndef ILOGGER_HPP_
#define ILOGGER_HPP_

#include <string>
#include <ostream>

#if __cplusplus >= 202002L
#include <format>
using std::make_format_args;
using std::vformat;
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
// #include <fmt/core.h>
// using fmt::vformat;
// using fmt::make_format_args;
#include <format>
using std::make_format_args;
using std::vformat;
#endif

class ILoggable
{
public:
    /**
     * @brief Destroy the ILoggable object
     *
     * This is a virtual destructor
     */
    virtual ~ILoggable() = default;

    /**
     * @brief logError
     *
     * This function is used to log an error message
     * @param message The message to log
     * @param forcedStream The stream to log to
     */
    virtual void logInfo(const std::string &message, std::ostream *forcedStream = nullptr) = 0;

    /**
     * @brief logError
     *
     * This function is used to log an error message
     * @param message The message to log
     * @param forcedStream The stream to log to
     */
    virtual void logError(const std::string &message, std::ostream *forcedStream = nullptr) = 0;

    /**
     * @brief logWarning
     *
     * This function is used to log a warning message
     * @param message The message to log
     * @param forcedStream The stream to log to
     */
    virtual void logWarning(const std::string &message, std::ostream *forcedStream = nullptr) = 0;

    /**
     * @brief logDebug
     *
     * This function is used to log a debug message
     * @param message The message to log
     * @param forcedStream The stream to log to
     */
    virtual void logDebug(const std::string &message, std::ostream *forcedStream = nullptr) = 0;

    /**
     * @brief logCritical
     *
     * This function is used to log a critical message
     * @param message The message to log
     * @param forcedStream The stream to log to
     */
    virtual void logCritical(const std::string &message, std::ostream *forcedStream = nullptr) = 0;
};

#endif /* !ILOGGER_HPP_ */

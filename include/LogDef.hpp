/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** LogDef
*/

#ifndef LOG_DEF_HPP_
#define LOG_DEF_HPP_

enum class LogOutput
{
    STDOUT = 0, ///< Standard output
    STDERR = 1, ///< Standard error
    FILE = 2 ///< File
};

enum class LogType
{
    INFO = 0, ///< Information
    ERR = 1, ///< Error
    WARN = 2, ///< Warning
    DEBUG = 3, ///< Debug
    CRITICAL = 4 ///< Critical
};

#endif /* !LOG_DEF_HPP_ */

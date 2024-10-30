/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IError
*/

#pragma once

#include <exception>
#include <string>

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */
namespace LE
{
    /**
     * @class IError
     * @brief Interface for error handling.
     *
     * The IError interface provides a way to handle errors in the engine.
     */
    class IError : public std::exception
    {
    public:
        /**
         * @brief Constructor for IError.
         *
         * @param title The title of the error.
         * @param details The details of the error.
         * @param help The help message for the error.
         */
        IError(const std::string &title = "", const std::string &details = "", const std::string &help = "")
        {
            if (title.empty())
                _title = "An error as occured.";
            if (details.empty())
                _details = "No more details were given.";
            if (help.empty())
                _help = "Try to get better.";
        }

        /**
         * @brief Destructor for IError.
         */
        ~IError() = default;

        /**
         * @brief Returns the error message.
         *
         * @return The error message.
         */
        const char *what() const noexcept override
        {
            std::string error = "ERROR: " + _title + "\n" +
                                "DETAILS: " + _details + "\n"
                                                         "HELP: " +
                                _help + "\n";
            return error.c_str();
        }

    protected:
        std::string _title;   ///< The title of the error.
        std::string _details; ///< The details of the error.
        std::string _help;    ///< The help message for the error.
    };
}
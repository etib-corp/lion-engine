/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IError
*/

#pragma once

#include <exception>
#include <string>

namespace LE {
    class IError : public std::exception {
        public:
            IError(const std::string &title = "An error as occured.", const std::string& details = "No more details were given.", const std::string& help = "try to get better.") : _title(title), _details(details), _help(help)
            {
            }
            ~IError() = default;

            const char *what() const noexcept override
            {
                std::string error = "ERROR: " + _title + "\n" +
                                    "DETAILS: " + _details + "\n"
                                    "HELP: " + _help + "\n";
            }

        protected:
            std::string _title;
            std::string _details;
            std::string _help;
    };
}
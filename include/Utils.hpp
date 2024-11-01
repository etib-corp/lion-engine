/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "interface/IError.hpp"

/**
 * @brief Convert an enumeration value to a char
 *
 * @tparam Enumeration The enumeration type
 * @param value The enumeration value
 * @return The char value
 */
template <typename Enumeration>
auto asChar(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

/**
 * @class Utils
 * @brief A utility class that provides various helper functions.
 */
class Utils {
    public:
        /**
         * @class IsDirectoryException
         * @brief Exception class thrown when attempting to parse a directory.
         * @extends LE::IError
         */
        class IsDirectoryException : public LE::IError {
            public:
                /**
                 * @brief Constructs an IsDirectoryException object with the given error message.
                 * @param path The path of the directory.
                 */
                IsDirectoryException(const std::string& path) : IError("You are trying to parse a directory as a file", "directory: " + path, "Please modify or check if you are using the good path") {}
        };

        /**
         * @class FileNotFoundException
         * @brief Exception class for file not found errors.
         * @extends LE::IError
         */
        class FileNotFoundException : public LE::IError {
            public:
                /**
                 * @brief Constructs a FileNotFoundException object with the default error message.
                 * The default error message is "File not found".
                 *
                 * @param path The path of the file that was not found.
                */
                FileNotFoundException(const std::string &path) : IError("File not found", "Can not find " + path, "Please correct the path to the file.") {};
        };

        /**
         * @class InvalidArgumentsException
         * @brief Exception class for invalid arguments.
         * @extends LE::IError
         *
         * This exception is thrown when invalid arguments are provided.
         */
        class InvalidArgumentsException : public LE::IError {
            public:
                /**
                 * @brief Constructs an InvalidArgumentsException object with the given error message.
                 *
                 * @param expected The expected arguments.
                 * @param received The received arguments.
                 * @param help The help message for the error.
                 */
                InvalidArgumentsException(const std::string& expected, const std::string &received, const std::string &help = "") : IError("Invalid arguments", "Expected: " + expected + "\nBut got: " + received, help) {}
        };

        /**
         * @brief Splits a string into a vector of substrings based on a delimiter.
         *
         * @param str The string to be split.
         * @return std::vector<std::string> A vector containing the substrings.
         */
        static std::vector<std::string> split(const std::string &str);

        /**
         * @brief Splits a string into a vector of substrings based on a separator character.
         *
         * @param str The string to be split.
         * @param sep The separator character.
         * @return std::vector<std::string> A vector containing the substrings.
         */
        static std::vector<std::string> split(const std::string &str, char sep);

        /**
         * @brief Retrieves the content of a file.
         *
         * @param filename The name of the file to read.
         * @return The content of the file as a string.
         */
        static std::string getFileContent(const std::string &filename);

        /**
         * @brief Writes content to a file.
         *
         * @param filename The name of the file to write to.
         * @param content The content to write to the file.
         * @param append If true, the content will be appended to the file. Otherwise, the file will be overwritten.
         * @throws std::exception if the file cannot be opened.
        */
        static void setFileContent(const std::string &filename, const std::string &content, bool append = false);

        /**
         * @brief Converts a vector of strings to a single string.
         *
         * @param container The vector of strings to be converted.
         * @return The concatenated string.
         */
        static std::string vectorToString(const std::vector<std::string> &container);

        /**
         * @brief Retrieves the files in a directory.
         *
         * @param directory The directory path.
         * @return std::vector<std::string> A vector containing the names of the files in the directory.
         */
        static std::vector<std::string> getDirectoryFiles(const std::string &directory);

        /**
         * @brief Retrieves the files in a directory with a specific extension.
         *
         * @param directory The directory path.
         * @param extension The file extension to filter by.
         * @return std::vector<std::string> A vector containing the names of the files with the specified extension in the directory.
         */
        static std::vector<std::string> getDirectoryFiles(const std::string &directory, const std::string &extension);

        /**
         * @brief Retrieves the subdirectories in a directory.
         *
         * @param directory The directory path.
         * @return std::vector<std::string> A vector containing the names of the subdirectories in the directory.
         */
        static std::vector<std::string> getDirectorySubDirectories(const std::string &directory);

        /**
         * @brief Retrieves the content of a directory (files and subdirectories).
         *
         * @param directory The directory path.
         * @return std::vector<std::string> A vector containing the names of the files and subdirectories in the directory.
         */
        static std::vector<std::string> getDirectoryContent(const std::string &directory);
};

#endif /* !UTILS_HPP_ */

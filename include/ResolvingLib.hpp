/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ResolvingLib
*/

#ifndef RESOLVELIBS_HPP_
#define RESOLVELIBS_HPP_
#include <iostream>

/**
 * @brief Check if the OS is Windows
 *
 * @return true if the OS is Windows
 * @return false if the OS is not Windows
 */
bool isWindows(void);

/**
 * @brief Check if the OS is MacOS
 *
 * @return true if the OS is MacOS
 * @return false if the OS is not MacOS
 */
bool isMacOS(void);

/**
 * @brief Check if the OS is Linux
 *
 * @return true if the OS is Linux
 * @return false if the OS is not Linux
 */
bool isLinux(void);

/**
 * @brief Get the extension of the dynamic library
 *
 * @return std::string The extension of the dynamic library
 */
std::string getExtensionKernel(void);

/**
 * @brief Get the extension of the dynamic library
 *
 * @return std::string The extension of the dynamic library
 */
std::string getPathOfNetworkDynLib(void);

#endif /* !RESOLVELIBS_HPP_ */

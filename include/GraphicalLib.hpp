/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** GraphicalLib
*/

#ifndef GRAPHICALLIB_HPP_
    #define GRAPHICALLIB_HPP_


#include "interface/IEngine.hpp"
#include <dlfcn.h>

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */
namespace LE {
    /**
     * @class GraphicalLib
     * @brief Interface for the Graphical Library.
     *
     * The GraphicalLib interface provides a method to create an engine.
     * The GraphicalLib is a shared library loader that provides the engine to the game.
     */
    class GraphicalLib {
        public:
            GraphicalLib(const std::string& path);
            GraphicalLib();
            ~GraphicalLib();

            std::shared_ptr<IEngine> createEngine();
        private:
            void *_handle;
            std::shared_ptr<IEngine> (*_createEngine)();
    };
}

#endif /* !GRAPHICALLIB_HPP_ */

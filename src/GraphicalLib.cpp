/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

LE::GraphicalLib::GraphicalLib()
{
    _handle = dlopen("./build/liblion-engine.so", RTLD_LAZY);
    if (!_handle)
        throw LE::IEngineError("GraphicalLib", "Failed to load the graphical library", dlerror());
    _createEngine = reinterpret_cast<std::shared_ptr<LE::IEngine>(*)()>(dlsym(_handle, "createEngine"));
}

LE::GraphicalLib::~GraphicalLib()
{
    dlclose(_handle);
}

std::shared_ptr<LE::IEngine> LE::GraphicalLib::createEngine()
{
    if (!_createEngine)
        throw LE::IEngineError("GraphicalLib", "Failed to load the createEngine function", dlerror());
    return _createEngine();
}
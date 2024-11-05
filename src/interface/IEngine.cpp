/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IEngine
*/

#include "IEngine.hpp"
#include "GraphicalLib.hpp"
#include "interface/GUI/ITextField.hpp"
#include "luacpp/luacpp.h"
#include <iostream>
#include <string>
#include <vector>

void LE::IEngine::init(const std::string &networkModulePath)
{
    _window = createWindow(800, 600, "Lion Engine");
    _clock = std::make_unique<LE::Clock>();
    _networkLoaderLib = std::make_unique<NetworkLoaderLib>(networkModulePath.c_str());
    _networkLoaderLib->LoadModule();
    _networkModule = _networkLoaderLib->createNetworkModule();
    _assetManager = std::make_shared<AssetManager>();
    _assetLoader = std::make_unique<AssetLoader>(_assetManager, "./assets");
    _assetLoader->loadAssets();
    _soundDevice = std::make_shared<LE::Sound::Device>();
}

std::unique_ptr<NetworkLoaderLib> &LE::IEngine::getNetworkLoaderLib()
{
    return _networkLoaderLib;
}

INetworkModule *LE::IEngine::getNetworkModule()
{
    return _networkModule;
}

void LE::IEngine::run(bool throwError)
{
    _throwError = throwError;

    if (_configFunc) {
        _configFunc();
        std::cout << "Config function called" << std::endl;
    }
    // Color color;
    // color._a = 255.0f;
    // color._r = 255.0f;
    // color._g = 255.0f;
    // color._b = 255.0f;
    // _window->setClearColor(color);
    while (_window->isOpen()) {
        if (_loopFunc) {
            _loopFunc();
        }
        _game->update();
        _dt = _clock->getElapsedTime();
        if (_clock->getElapsedTime() < (1000.0f / _framerateLimit))
            continue;
        _clock->restart();
        _window->render(_game->getSceneManager()->getCurrentScene());
    }
}

void LE::IEngine::throwError(const LE::IError &error)
{
    if (_throwError) {
        throw error;
    } else {
        std::cerr << error.what() << std::endl;
    }
}

void LE::IEngine::setConfig(std::function<void()> func)
{
    _configFunc = func;
}

void LE::IEngine::setLoop(std::function<void()> func)
{
    _loopFunc = func;
}

void LE::IEngine::setFramerateLimit(std::size_t limit)
{
    _framerateLimit = limit;
}

std::size_t LE::IEngine::getWindowWidth() const
{
    return _window->getWidth();
}

std::size_t LE::IEngine::getWindowHeight() const
{
    return _window->getHeight();
}

float LE::IEngine::getDeltaTime() const
{
    return _dt;
}

void LE::IEngine::restartClock()
{
    _clock->restart();
}

std::shared_ptr<AssetManager> LE::IEngine::getAssetManager()
{
    return _assetManager;
}

static bool isValidFile(const std::string& path) {
    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

static void checkFileConf(luacpp::LuaTable servConf)
{
    bool hasEnginePath = false;
    bool hasNetworkModulePath = false;
    bool hasFramerateLimit = false;
    bool hasDebug = false;

    if (servConf.GetType() == 0)
    {
        std::cerr << "Error in Lua configuration" << std::endl;
        exit(84);
    }

    servConf.ForEach([&](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        if (::strcmp(key.ToString(), "gameEnginePath") == 0)
            hasEnginePath = true;
        if (::strcmp(key.ToString(), "networkModulePath") == 0)
            hasNetworkModulePath = true;
        if (::strcmp(key.ToString(), "FramerateLimit") == 0)
            hasFramerateLimit = true;
        if (::strcmp(key.ToString(), "Debug") == 0)
            hasDebug = true;
        return true;
    });
    if (!hasEnginePath || !hasNetworkModulePath || !hasFramerateLimit || !hasDebug)
    {
        std::cerr << "Error in Lua configuration" << std::endl;
        exit(84);
    }
}

std::shared_ptr<LE::IEngine> instanciateEngine(void)
{
    std::string rGraphicalLibPath;
    std::string networkModulePath;
    bool isDebugger = false;
    std::shared_ptr<LE::IEngine> r_g_engine;

    int rFramerateLimit = 0;
    luacpp::LuaState l(luaL_newstate(), true);
    bool isLoaded = l.DoFile("serv.conf.lua");

    if (!isLoaded)
    {
        std::cerr << "Failed to load Lua script." << std::endl;
        return nullptr;
    }
    luacpp::LuaTable servConf = l.Get("servConfiguration");

    checkFileConf(servConf);

    servConf.ForEach([&](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        if (::strcmp(key.ToString(), "gameEnginePath") == 0)
            rGraphicalLibPath.assign(value.ToString(), ::strlen(value.ToString()));
        if (::strcmp(key.ToString(), "networkModulePath") == 0)
            networkModulePath.assign(value.ToString(), ::strlen(value.ToString()));
        if (::strcmp(key.ToString(), "FramerateLimit") == 0)
            rFramerateLimit = value.ToInteger();
        if (::strcmp(key.ToString(), "Debug") == 0)
            isDebugger = value.ToBool();
        return true;
    });

    if (!isValidFile(rGraphicalLibPath) || !isValidFile(networkModulePath))
    {
        std::cerr << "Bad path" << std::endl;
        exit(84);
    }

    void *_handle = dlopen(rGraphicalLibPath.c_str(), RTLD_LAZY);
    if (!_handle)
        throw LE::IEngineError("GraphicalLib", "Failed to load the graphical library", dlerror());
    std::shared_ptr<LE::IEngine> (*_createEngine)() = reinterpret_cast<std::shared_ptr<LE::IEngine>(*)()>(dlsym(_handle, "createEngine"));

    r_g_engine = _createEngine();
    r_g_engine->init(networkModulePath);
    r_g_engine->setFramerateLimit(rFramerateLimit);
    r_g_engine->_hasDebugger = isDebugger;
    return r_g_engine;
}

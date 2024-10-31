/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IEngine
*/

#include "IEngine.hpp"

void LE::IEngine::init()
{
    _window = createWindow(800, 600, "Lion Engine");
    _clock = std::make_unique<LE::Clock>();
    _networkLoaderLib = std::make_unique<NetworkLoaderLib>("./build/lib/NetworkModule/libNetworkModule.so");
    _networkLoaderLib->LoadModule();
    _networkModule = _networkLoaderLib->createNetworkModule();
    _assetManager = std::make_shared<AssetManager>();
    _assetLoader = std::make_unique<AssetLoader>(_assetManager, "./assets");
    _assetLoader->loadAssets();
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

void LE::IEngine::throwError(const LE::Error &error)
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
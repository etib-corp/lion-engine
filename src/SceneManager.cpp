/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include "interface/IEngine.hpp"

LE::SceneManager::SceneManager(LE::IEngine &engine) : _engine(engine)
{
    _currentScene = nullptr;
    _currentSceneName = "";
    _previousScene = nullptr;
    _previousSceneName = "";
}

LE::SceneManager::~SceneManager()
{
}

void LE::SceneManager::play()
{
    if (_currentScene == nullptr)
        throw SceneManagerError("No scene selected to play.");
    _currentSceneName = _scenes.begin()->first;
    _currentScene = _scenes.begin()->second;
}

void LE::SceneManager::play(const std::string& sceneName)
{
    if (_scenes.find(sceneName) == _scenes.end())
        throw SceneManagerError("Scene not found.");
    _currentSceneName = sceneName;
    _currentScene = _scenes[sceneName];
}

void LE::SceneManager::stop()
{
    _previousSceneName = _currentSceneName;
    _previousScene = _currentScene;
    _currentSceneName = "";
    _currentScene = nullptr;
}

std::shared_ptr<LE::Scene> LE::SceneManager::getCurrentScene() const
{
    return _currentScene;
}

std::shared_ptr<LE::Scene> LE::SceneManager::getPreviousScene() const
{
    return _previousScene;
}

void LE::SceneManager::addScene(std::shared_ptr<LE::Scene> scene, const std::string &name)
{
    if (_scenes.find(name) != _scenes.end())
        throw SceneManagerError("Scene already exists.");
    _scenes[name] = scene;
}

void LE::SceneManager::removeScene(const std::string &sceneName)
{
    if (_scenes.find(sceneName) == _scenes.end())
        throw SceneManagerError("Scene not found.");
    _scenes.erase(sceneName);
}

void LE::SceneManager::selectScene(const std::string &sceneName)
{
    auto it = _scenes.find(sceneName);
    if (it != _scenes.end()) {
        if (_currentScene) {
            _previousScene = _currentScene;
            _previousSceneName = _currentSceneName;
            // _currentScene->stop();
        }
        _currentScene = it->second;
        _currentSceneName = sceneName;
    } else {
        throw SceneManagerError("Scene not found: " + sceneName);
    }
}

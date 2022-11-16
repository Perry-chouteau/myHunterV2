/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** User
*/

#include "UserManager.hpp"

void User::UserManager::InitSystem(Registry_ref _ecs, Window_ref window, SpriteManager_ref<std::string> _sm, AudioManager_ref<std::string> _am, MusicManager_ref<std::string> _mm)
{
    _mm.setVolume(50);
    _mm.setLoop("music");
    _mm.play("music");

    window.setMouseCursorVisible(false);

    sf::Vector2f bgScale = {static_cast<float>(sf::VideoMode::getDesktopMode().width) / 1502,
                        static_cast<float>(sf::VideoMode::getDesktopMode().height) / 844};

    std::cout << bgScale.x  << " " << bgScale.y << std::endl;

    entity_t bg = _ecs.spawn_entity();
    _ecs.add_component<position>(bg, {0, 0});
    _ecs.add_component<drawable>(bg, {_sm.Get("background")});
    _ecs.add_component<resizable>(bg, {static_cast<float>(sf::VideoMode::getDesktopMode().width) / 1502,
                                        static_cast<float>(sf::VideoMode::getDesktopMode().height) / 844});

    entity_t target3 = _ecs.spawn_entity();
    _ecs.add_component<position>(target3, {600, 385});
    _ecs.add_component<velocity>(target3, {2, 0});
    _ecs.add_component<targetable>(target3, {500, 1200, false});
    _ecs.add_component<drawable>(target3, {_sm.Get("target")});
    _ecs.add_component<clickable>(target3, {});
    _ecs.add_component<clickable_sfx>(target3, {"hit"});
    _ecs.add_component<resizable>(target3, {0.35, 0.35});

    entity_t target2 = _ecs.spawn_entity();
    _ecs.add_component<position>(target2, {800, 325});
    _ecs.add_component<velocity>(target2, {3.5, 0});
    _ecs.add_component<targetable>(target2, {400, 1400, true});
    _ecs.add_component<drawable>(target2, {_sm.Get("target")});
    _ecs.add_component<clickable>(target2, {});
    _ecs.add_component<clickable_sfx>(target2, {"hit"});
    _ecs.add_component<resizable>(target2, {0.60, 0.60});

    entity_t target = _ecs.spawn_entity();
    _ecs.add_component<position>(target, {1500, 225});
    _ecs.add_component<velocity>(target, {5, 0});
    _ecs.add_component<targetable>(target, {300, 1600, true});
    _ecs.add_component<drawable>(target, {_sm.Get("target")});
    _ecs.add_component<clickable>(target, {});
    _ecs.add_component<clickable_sfx>(target, {"hit"});
    _ecs.add_component<resizable>(target, {1, 1});

    entity_t crosshair = _ecs.spawn_entity();
    _ecs.add_component<position>(crosshair, {0, 0});
    _ecs.add_component<drawable>(crosshair, {_sm.Get("crosshair")});
    _ecs.add_component<controlable>(crosshair, {});
    _ecs.add_component<resizable>(crosshair, {1, 1});

    entity_t weapon = _ecs.spawn_entity();
    _ecs.add_component<position>(weapon, {1050, 470});
    _ecs.add_component<drawable>(weapon, {_sm.Get("weapon")});
    _ecs.add_component<clickable_sfx>(weapon, {"shoot"});
    _ecs.add_component<animation_adaptative>(weapon, {sf::IntRect(0, 0, 587, 427), 600, 1200});
    _ecs.add_component<resizable>(weapon, {1.5, 1.3});

}

void User::UserManager::UpdateSystem(Registry_ref _ecs, Window_ref _window)
{
    moveTargetSystem(_ecs, _window);
    //score
    scoreSystem(_ecs, hitScore);
}

void User::UserManager::EventSystem(Registry_ref _ecs, Event_ref _event, Window_ref _window, SpriteManager_ref<std::string> _sm, AudioManager_ref<std::string> _am)
{
    moveScopeSystem(_ecs, _event, _window);
    clickSystem(_ecs, _event, _window, _sm, _am);
}

void User::UserManager::DisplaySystem(Registry_ref _ecs, Window_ref _window)
{
    displaySystem(_ecs, _window);
}
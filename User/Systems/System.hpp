/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_

    #include "Ecs.hpp"

    #include "SpriteManager.hpp"
    #include "AudioManager.hpp"

    #include "UserComponent.hpp"

    #include "SfmlRef.hpp"

//! Namespace for all game related content, here systems
namespace User {
    //void defaultEventSystem(Registry_ref reg, Event_ref event, Window_ref window, SpriteManager_ref<std::string> _spriteManager, AudioManager_ref<std::string> am, MusicManager_ref<std::string> mm);
    void moveTargetSystem(Registry_ref reg, Window_ref window);
    void scoreSystem(Registry_ref reg, int score);

    void moveScopeSystem(Registry_ref reg, Event_ref event, Window_ref window);
    void clickSystem(Registry_ref reg, Event_ref event, Window_ref window, SpriteManager_ref<std::string> _spriteManager, AudioManager_ref<std::string> am);
    void killTargetSystem(Registry_ref reg, Event_ref event, Window_ref window, SpriteManager_ref<std::string> _spriteManager, AudioManager_ref<std::string> am);
    void respawnTargetSystem(Registry_ref reg, SpriteManager_ref<std::string> sm, position pos, targetable targ, resizable res );

    void displaySystem(Registry_ref reg, Window_ref window);

}

#endif /* !SYSTEM_HPP_ */

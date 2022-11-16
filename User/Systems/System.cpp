/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** PositionSystem
*/

#include "System.hpp"

//static int save(int *a)
//{
//    static int b = 0;
//
//    b = (a != NULL) ? *a : b;
//    return b;
//}

namespace User {

    void moveTargetSystem(Registry_ref reg, Window_ref window)
    {
        auto &target = reg.get_components<targetable>();
        auto &pos = reg.get_components<position>();
        auto &vel = reg.get_components<velocity>();

        for (int i = 0; i < pos.size() && i < vel.size() && i < target.size(); i++) {
            if (pos[i] && vel[i] && target[i]) {
                if (pos[i]->x < target[i]->max_left)
                    target[i]->direction = true;
                if (pos[i]->x > target[i]->max_right)
                    target[i]->direction = false;
                (target[i]->direction) ? pos[i]->x += vel[i]->x : pos[i]->x -= vel[i]->x;
            }
        }
    }

    void scoreSystem(Registry_ref reg, int score)
    {

    }

    void moveScopeSystem(Registry_ref reg, Event_ref event, Window_ref window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        auto &pos = reg.get_components<position>();
        auto &control = reg.get_components<controlable>();

        for (int i = 0; i < control.size(); i++) {
            if (control[i]) {
                if (i < pos.size() && pos[i]) {
                    pos[i]->x = static_cast<float>(mousePos.x);
                    pos[i]->y = static_cast<float>(mousePos.y);
                }
            }
        }
    }
    void clickSystem(Registry_ref reg, Event_ref event, Window_ref window, SpriteManager_ref<std::string> sm, AudioManager_ref<std::string> am)
    {
        //weapon
        auto &anim = reg.get_components<animation_adaptative>();
        //target
        auto &target = reg.get_components<targetable>();
        auto &control = reg.get_components<controlable>();
        auto &draw = reg.get_components<drawable>();
        //both
        auto &click_sfx = reg.get_components<clickable_sfx>();
        for (int i = 0; i < anim.size(); i++) {
            if (anim[i])
                anim[i]->rect.left = 0;
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            for (int i = 0; i < anim.size(); i++) {
                if (anim[i]) {
                    anim[i]->rect.left += anim[i]->offset;
                    if (i < click_sfx.size() && click_sfx[i])
                        am.play(click_sfx[i]->key);
                }
                killTargetSystem(reg, event, window, sm, am);
            }
        }
    }

    void killTargetSystem(Registry_ref reg, Event_ref event, Window_ref window, SpriteManager_ref<std::string> sm, AudioManager_ref<std::string> am)
    {
        auto &target = reg.get_components<targetable>();
        auto &control = reg.get_components<controlable>();
        auto &draw = reg.get_components<drawable>();
        auto &click_sfx = reg.get_components<clickable_sfx>();

        for (int i = 0; i < control.size() ; ++i) {
            for (int j = 0; j < target.size() ; ++j) {
                if (control[i] && target[j]) {
                    if (j < draw.size() && draw[i] && draw[j])
                        if (draw[i]->sprite.getGlobalBounds().intersects(draw[j]->sprite.getGlobalBounds())) {
                            if (j < click_sfx.size() && click_sfx[j])
                                am.play(click_sfx[j]->key);
                            position tmpPos = {static_cast<float>(reg.get_components<targetable>()[j]->max_left + (rand() % static_cast<int>(reg.get_components<targetable>()[j]->max_right))), reg.get_components<position>()[j]->y};
                            targetable tmpTarget = {reg.get_components<targetable>()[j]->max_left, reg.get_components<targetable>()[j]->max_right, false};
                            resizable tmpResize = {reg.get_components<resizable>()[j]->x, reg.get_components<resizable>()[j]->y};
                            reg.kill_entity(reg.entity_from_index(j));
                            respawnTargetSystem(reg, sm, tmpPos, tmpTarget, tmpResize);
                        }
                }
            }
        }
    }

    void respawnTargetSystem(Registry_ref reg, SpriteManager_ref<std::string> sm, position pos, targetable targ, resizable res)
    {
        entity_t newTarget = reg.spawn_entity();
//        entity
        reg.add_component<position>(newTarget, {pos.x, pos.y});
        reg.add_component<velocity>(newTarget, {2, 0});
        reg.add_component<targetable>(newTarget, {targ.max_left, targ.max_right, targ.direction});
        reg.add_component<drawable>(newTarget, {sm.Get("target")});
        reg.add_component<clickable>(newTarget, {});
        reg.add_component<clickable_sfx>(newTarget, {"hit"});
        reg.add_component<resizable>(newTarget, {res.x, res.y});
    }

    void displaySystem(Registry_ref reg, Window_ref window)
    {
        auto &draw = reg.get_components<drawable>();
        auto &pos = reg.get_components<position>();
        auto &res = reg.get_components<resizable>();
        auto &anim = reg.get_components<animation_adaptative>();

        for (int i = 0; i < draw.size(); ++i) {
            if (draw[i]) {
                if (i < pos.size() && pos[i])
                    draw[i]->sprite.setPosition(pos[i]->x, pos[i]->y);
                if (i < res.size() && res[i])
                    draw[i]->sprite.setScale(res[i]->x, res[i]->y);
//                    draw[i]->sprite.set
                if (i < anim.size() && anim[i]) {
                    draw[i]->sprite.setTextureRect(anim[i]->rect);
                }
                window.draw(draw[i]->sprite);
            }
        }
    }
};
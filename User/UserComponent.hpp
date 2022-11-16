/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** Component
*/

#ifndef USER_COMPONENT_HPP_
    #define USER_COMPONENT_HPP_

    #include "SFML/Window.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/Audio.hpp"
    #include "SFML/System.hpp"

    #include <functional>

//utilisateur

/**
 * @struct position
 *
 */
struct position {
    float x;
    float y;
};

struct targetable {
    float max_left;
    float max_right;
    bool direction;
};

/**
 * @struct velocity
 *
 * @brief velocity of the entity
 *
 */
struct velocity {
    float x;
    float y;
};

/**
 * @struct drawable
 *
 * @brief drawable of the entity
 */
struct drawable {
    sf::Sprite sprite;
};

/**
 * @struct controlable
 *
 * @brief controlable of the entity
 */
struct controlable {
};

/**
 * @struct animation_adaptative
 *
 * @brief Component animation adaptative contain the animation of the entity in order to animate it remotely
 *
 */
struct animation_adaptative {
    sf::IntRect rect;
    int offset;
    int mx_v;
};

/**
 * @struct resizable
 *
 * @brief Component resizable contain the scale of the entity
 *
 */
struct resizable {
    float x;
    float y;
};

/**
 * @struct death_sfx
 *
 * @brief Component death_sfx in order to handle the death sound of the entity
 *
 */
struct death_sfx {
    std::string key;
};

/**
 * @struct clickable
 *
 * @brief Component clickable in order to handle the click of the entity (button)
 *
 */
struct clickable {

};

/**
 * @struct clickable sfx
 *
 * @brief Component clickable_sfx in order to handle the sound of the click of the entity (button)
 */
struct clickable_sfx {
    std::string key;
};

/**
 * @brief Component value_score so that the player earn points when the entity is killed
 *
 */
struct value_score {
    int value;
};

/**
 * @brief Component text in order to handle the text of the entity
 *
 */
struct text {
    std::string text_str;
};

/**
 * @brief Component is_score in order to handle the score of the player
 *
 */
struct is_score {
};

#endif /* !USER_COMPONENT_HPP_ */

/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** SpriteManager
*/

#ifndef SPRITE_MANAGER_HPP_
    #define SPRITE_MANAGER_HPP_

    #include "SFML/Window.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/System.hpp"
    #include <map>

/*!
 *  \addtogroup StorageManager
 *  @{
 */

/**
 * @brief Image structure that can associate a Texture and a Sprite
 *
 * @author perry.chouteau@epitech.eu
 */
struct Image {
    sf::Texture texture;
    sf::Sprite sprite;
};

/**
 * @brief SpriteManager
 *
 * @tparam T
 * @tparam Value
 */
template<typename Key/*, typename Value*/>
class SpriteManager {
    public:
        using TStorage = std::map<Key, Image>;

    /**
     * @brief Add
     *
     * @param t
     * @param v
     */
    void Add(Key k, Image &v)
    {
        _storage.insert(std::pair<Key, Image>(k, v));
    };

    /**
     * @brief Add
     *
     * @param t
     * @param texture
     * @param f
     */
    void Add(Key k, std::string path)
    {
        _storage[k].texture.loadFromFile(path);
        _storage[k].sprite.setTexture(_storage[k].texture);
    };

    /**
     * @brief Get
     *
     * @param t
     * @return sf::Sprite
     */
    sf::Sprite &Get(Key k)
    {
        return _storage[k].sprite;
    };

    private:
        TStorage _storage;
};

template<typename Key/*, typename Value*/>
using SpriteManager_ref = SpriteManager<Key> &;

#endif /* !SPRITE_MANAGER_HPP_ */

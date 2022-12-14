/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** SpriteManager
*/

#ifndef AUDIO_MANAGER_HPP_
    #define AUDIO_MANAGER_HPP_

    #include "SFMLAudioModule.hpp"
    #include <map>

/*!
 *  \addtogroup StorageManager
 *  @{
 */

/**
 * @brief AudioManager
 *
 * @tparam T
 * @tparam Value
 */
template<typename Key/*, typename Value*/>
class AudioManager {
    public:
        using AStorage = std::map<Key, modules::SFMLAudioModule>;

        /**
         * @brief Add
         *
         * @param t
         * @param v
         */
        void Add(Key k, modules::SFMLAudioModule &v)
        {
            _storage.insert(std::pair<Key, modules::SFMLAudioModule>(k, v));
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
            _storage[k].setSource(path);
        };

        /**
         * @brief Get
         *
         * @param t
         * @return modules::SFMLAudioModule&
         */
        modules::SFMLAudioModule &Get(Key k)
        {
            return _storage[k];
        };

        /**
         * @brief play the sound at the given key
         *
         * @param key
         */
        void play(Key k)
        {
            _storage[k].play();
        };

        /**
         * @brief stop the sound at the given key
         *
         * @param key
         */
        void stop(Key k)
        {
            _storage[k].stop();
        };

        /**
         * @brief pause the sound at the given key
         *
         * @param key
         */
        void pause(Key k)
        {
            _storage[k].pause();
        };

        /**
         * @brief Stop every sound
         *
         */
        void stopAll()
        {
            for (auto &it : _storage)
                it.second.stop();
        };

        /**
         * @brief set volume
         *
         */
        void setVolume(float volume)
        {
            _volume = volume;
            updateVolume();
        };

        /**
         * @brief get volume
         *
         */
        float getVolume()
        {
            return _volume;
        }

        /**
         * @brief update the volume of the sound
         *
         */
        void updateVolume()
        {
            for (auto &it : _storage)
                it.second.setVolume(_volume);
        }

        /**
         * @brief Get the Status object
         *
         * @param key
         * @return sf::Sound::Status
         */
        modules::MusicStatus getStatus(Key k)
        {
            return _storage[k].getStatus();
        };

    private:
        float _volume = 50;
        AStorage _storage;
};

template<typename Key>
using AudioManager_ref = AudioManager<Key> &;

#endif /* !AUDIO_MANAGER_HPP_ */

/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** ProjectManager
*/

#ifndef USER_PROJECT_MANAGER_HPP_
    #define USER_PROJECT_MANAGER_HPP_

    #include <fstream>
    //Std
    #include <tuple>
    #include <type_traits> //std::is_same_v
    #include <iostream>

    //sfml
    #include "SFML/Window.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/Audio.hpp"
    #include "SFML/System.hpp"

    //ProjectManager
    #include "ProjectManager.hpp"
    #include "Ecs.hpp"

    //Manager
    #include "SpriteManager.hpp"
    #include "MusicManager.hpp"
    #include "AudioManager.hpp"

    //User
    #include "UserManager.hpp"
    #include "UserComponentManager.hpp"

/**
 * @namespace Project
 *
 * @author perry.chouteau@epitech.eu
 */
namespace User {

    using Window_ref = sf::RenderWindow &;
    using Event_ref = sf::Event &;
    using Music_ref = sf::Music &;
    using Sound_ref = sf::Sound &;

    /**
     * @brief UserProjectManager
     *
     * @author perry.chouteau@epitech.eu
     */
    class UserProjectManager final : public Project::ProjectManager {
        public:

            /**
             * @brief Construct a Project Manager using c++ inheritance folowing User needs !
             *
             * @param jsonfile
             */
            UserProjectManager()
            : ProjectManager(), _sm(), _mm(), _am(), _window(CreateMyWindow()), _userManager()
            {                //User
                config_extractor<user_config::components_list>::function(_ecs); //user

                InitWindow();
                InitSprites();
                InitSounds();
            }

            /**
             * @brief Destroy the User Project Manager
             *
             */
            ~UserProjectManager() = default;

            /**
             * @brief Start our Client
             *
             * @param ip
             * @param port
             * @return int
             */
            int Start()
            {
                _userManager.InitSystem(_ecs, _window, _sm, _am, _mm);
                while (_window.isOpen()) {
                    _userManager.UpdateSystem(_ecs, _window);
                    while (_window.pollEvent(_event)) {
                        if (_event.type == sf::Event::Closed) {
                            _window.close();
                            break;
                        }
                    _userManager.EventSystem(_ecs, _event, _window, _sm, _am);
                    }
                    _userManager.DisplaySystem(_ecs, _window);
                    _window.display();
                    _window.clear();
                }
                return 0;
            };

////////////////////////////////////////////////////////////////////////////////////////////////

        private:

            /**
             * @brief Create Window from json file
             *
             * @param jsonfile
             * @return sf::RenderWindow
             */
            sf::RenderWindow CreateMyWindow()
            {
                    return sf::RenderWindow(sf::VideoMode(1900, 1080),
                            std::string("my_hunter"));
            }

            void InitWindow()
            {
                _window.setFramerateLimit(60);
            }

            void InitSprites()
            {
                _sm.Add("background", "../assets/img/background.png");
                _sm.Add("crosshair", "../assets/img/crosshair.png");
                _sm.Add("target", "../assets/img/target.png");
                _sm.Add("weapon", "../assets/img/weapon.png");
            }

            void InitSounds()
            {
                _mm.Add("music", "../assets/sound/music.ogg");
                _am.Add("hit", "../assets/sound/hit.wav");
                _am.Add("shoot", "../assets/sound/shoot.wav");
            }

        private:
            User::UserManager _userManager;

            //sfml
            sf::RenderWindow _window;
            sf::Event _event;

            //manager
            SpriteManager<std::string> _sm;
            MusicManager<std::string> _mm;
            AudioManager<std::string> _am;
    };

};

#endif /* !USER_PROJECT_MANAGER_HPP_ */

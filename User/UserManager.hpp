/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** UserManager
*/

#ifndef CLIENT_MANAGER_HPP_
    #define CLIENT_MANAGER_HPP_

    #include "SpriteManager.hpp" // add init scene deprecated cause shouldn't be used
    #include "MusicManager.hpp"
    #include "AudioManager.hpp"

    #include "System.hpp"

    #include "UserComponent.hpp"

    #include "SfmlRef.hpp"


/**
 * @brief namespace User
 *
 * @author perry.chouteau@epitech.eu
 */
namespace User {

    /**
     * @class UserManager
     *
     * @brief class used to manage user
     *
     * @author perry.chouteau@epitech.eu
     */
    class UserManager final {
        public:

            void InitSystem(Registry_ref _ecs, Window_ref _window, SpriteManager_ref<std::string> _sm, AudioManager_ref<std::string> _am, MusicManager_ref<std::string> _mm);
            void UpdateSystem(Registry_ref _ecs, Window_ref _window);
            void EventSystem(Registry_ref _ecs, Event_ref _event, Window_ref _window, SpriteManager_ref<std::string> _sm, AudioManager_ref<std::string> _am);
            void DisplaySystem(Registry_ref _ecs, Window_ref _window);

        private:
           int hitScore;

   };

}

#endif /* !CLIENT_MANAGER_HPP_ */

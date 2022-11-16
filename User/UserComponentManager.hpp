/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-zacharie.lawson
** File description:
** SpriteManager
*/

#ifndef CLIENT_COMPONENT_MANAGER_HPP_
    #define CLIENT_COMPONENT_MANAGER_HPP_

    #include "UserComponent.hpp"
    #include <tuple>

namespace User {

    /**
     * @brief user config listing all components used by user
     *
     */
    struct user_config {
        using components_list = std::tuple<position,
                                            velocity,
                                            drawable,
                                            controlable,
                                            targetable,
                                            animation_adaptative,
                                            resizable,
                                            death_sfx,
                                            clickable,
                                            clickable_sfx,
                                            value_score,
                                            text,
                                            is_score>;
    };

}

#endif /* !CLIENT_COMPONENT_MANAGER_HPP_ */
/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main of the client
*/

#include <cctype>
#include "../User/UserProjectManager.hpp"

/**
 * @brief Main function of the client
 *
 * @param ac
 * @param av
 * @return int
 */
int main(int ac, char const * const av[])
{
    User::UserProjectManager upm;
    return upm.Start();
}
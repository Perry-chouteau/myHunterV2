cmake_minimum_required(VERSION 3.17)
project(pmj-my_hunter)

#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 11)

set(GRAPHICS GRAPHICS_API_OPENGL_43)
set(OpenGL_GL_PREFERENCE GLVND)

include(FindLib/FindSfmlLib.cmake)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)

if (WIN32)
    add_compile_options(/W4)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "./")
    #set_target_properties (rtype.exe PROPERTIES PREFIX "./build/")
endif(WIN32)

include_directories(

        # Module
            Module/
            Module/ProjectManager/
            Module/SoundManager/
            Module/SpriteManager/

        # User
            User/
            User/Systems/

        # App
            App/
)

set(SYSTEM_SRC
        User/Systems/System.cpp
)

set(USER_SRC
        User/UserManager.cpp
)

set(APP_SRC
        App/main.cpp
        )

add_executable(${PROJECT_NAME}
        ${SYSTEM_SRC}
        ${USER_SRC}
        ${APP_SRC}
        )

target_link_libraries(${PROJECT_NAME}
        # SFML
            sfml-window
            sfml-graphics
            sfml-audio
            sfml-system
)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-build/lib/Debug/sfml-window-d-2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            COMMAND_EXPAND_LISTS
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-build/lib/Debug/sfml-system-d-2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            COMMAND_EXPAND_LISTS
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-build/lib/Debug/sfml-graphics-d-2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            COMMAND_EXPAND_LISTS
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-build/lib/Debug/sfml-audio-d-2.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            COMMAND_EXPAND_LISTS
    )
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${FETCHCONTENT_BASE_DIR}/sfml-src/extlibs/bin/x64/openal32.dll ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            COMMAND_EXPAND_LISTS
    )
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
include(CPack)
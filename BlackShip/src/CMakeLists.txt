
# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités

cmake_minimum_required(VERSION 3.18.4)

# Ici on définit le répertoire qui contiendra l'exécutable

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)

# Création librairie

add_library(network network.c)
target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/header)

add_library(game game.c)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/header)

# Création exécutable

add_executable(client client.c)
target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/header)
target_link_libraries(client PRIVATE network)
target_link_libraries(client PRIVATE game)
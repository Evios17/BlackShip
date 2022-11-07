
# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités

cmake_minimum_required(VERSION 3.7.2)

# Ici on définit le répertoire qui contiendra l'exécutable

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/)

add_library(network network.c)
target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/header)

add_library(game game.c)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/header)

add_executable(client client.c)
target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/header)
target_link_libraries(client PRIVATE network)
target_link_libraries(client PRIVATE game)


#add_library(network network.c)
#target_include_directories(network PUBLIC ${CMAKE_SOURCE_DIR}/header)

#add_executable(client client.c)
#target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/header)
#target_link_libraries(client PRIVATE network)
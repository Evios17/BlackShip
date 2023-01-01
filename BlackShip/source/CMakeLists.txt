
# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités

cmake_minimum_required(VERSION 3.18.4)

# Ici on définit le répertoire qui contiendra l'exécutable

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/executables/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/librairies/)

# Création librairie

add_library(client client.c)
target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/entete)

add_library(serveur serveur.c)
target_include_directories(serveur PUBLIC ${CMAKE_SOURCE_DIR}/entete)

add_library(solo solo.c)
target_include_directories(solo PUBLIC ${CMAKE_SOURCE_DIR}/entete)

add_library(jeu jeu/jeu-affichage.c jeu/jeu-controleur.c jeu/jeu-E-S.c)
target_include_directories(jeu PUBLIC ${CMAKE_SOURCE_DIR}/entete)

# Création exécutable

add_executable(Blackship principal.c)
target_include_directories(Blackship PUBLIC ${CMAKE_SOURCE_DIR}/entete)
target_link_libraries(Blackship PRIVATE jeu)
target_link_libraries(Blackship PRIVATE client)
target_link_libraries(Blackship PRIVATE serveur)
target_link_libraries(Blackship PRIVATE solo)

# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.7.2)

# Ici on définit le répertoire qui contiendra l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/)


file( GLOB APP_SOURCES ${CMAKE_HOME_DIRECTORY}/src/*.c )
foreach( testsourcefile ${APP_SOURCES} )
    # get_filename_component, to cut off .c
  	get_filename_component(testname ${testsourcefile} NAME_WE) 
    add_executable(${testname}  ${testsourcefile})
        
    # Pour compiler avec des options spécifiques
    # target_compile_options(${testname} PUBLIC -Wall -pedantic -Werror -Wextra)

    # Si vous voulez rajouter une bibliothèque
    target_link_libraries( ${testname} -lm )    

    # cible install ... pour copier le programme dans /usr/local/bin
    # install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${testname}
    # DESTINATION bin
    # RENAME ${CMAKE_PROJECT_NAME}-${testname})
endforeach ()

#######################################################
### Command line parser                             ###
#######################################################
FetchContent_Declare(argh GIT_REPOSITORY https://github.com/adishavit/argh.git GIT_TAG v1.3.1)
FetchContent_MakeAvailable(argh)

#######################################################
### Standalone executable                           ###
#######################################################
add_executable(nutrition-cli
        # Static optimization_model
        run_model.h
        run_model.cpp

        # Standalone
        main.cpp
)

target_link_libraries(nutrition-cli PRIVATE nutrition argh)
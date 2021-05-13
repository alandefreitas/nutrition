#######################################################
### Library                                         ###
#######################################################
add_library(nutrition-solver
        # Nutrition Facts for Foods
        nutrition/nutrition_facts.cpp
        nutrition/nutrition_facts.h

        # Database with nutrition facts
        nutrition/food_database.cpp
        nutrition/food_database.h

        # User diet preferences
        nutrition/user_preferences.cpp
        nutrition/user_preferences.h

#        # Data base of user preferences for all users
#        nutrition/user_preference_database.cpp
#        nutrition/user_preference_database.h
#
#        # The optimization problem
#        nutrition/user_targets.cpp
#        nutrition/user_targets.h
#
#        # A candidate solution to the problem
#        nutrition/user_diet.cpp
#        nutrition/user_diet.h
#
#        # Evolutionary algorithm
#        nutrition/evolutionary_algorithm.h
#        nutrition/evolutionary_algorithm.cpp
#
#        # Dynamic
#        nutrition/dynamic_optimization.cpp
#        nutrition/dynamic_optimization.h
)
target_include_directories(nutrition-solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nutrition-solver PUBLIC ${CMAKE_BINARY_DIR}/_deps/cereal-src/include)
target_include_directories(nutrition-solver PUBLIC ${CMAKE_BINARY_DIR}/_deps/csv-parser-src/include)
target_link_libraries(nutrition-solver PUBLIC matplot cereal csv)

get_target_property(INCLUDE_DIRS nutrition-solver INCLUDE_DIRECTORIES)
message("nutrition-solver include dirs=${INCLUDE_DIRS}")

#######################################################
### Nutrition Facts                                 ###
#######################################################
# LOCAL_PATH is unfortunately hard-coded for now
set(RESOURCES_PATH "${MODERN_NUTRITION_ROOT}/resources/")
target_compile_definitions(nutrition-solver PRIVATE -DRESOURCES_PATH=\"${RESOURCES_PATH}\")
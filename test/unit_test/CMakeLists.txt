#add_executable(dinamic-tests dinamicTests.cpp)
#target_link_libraries(dinamic-tests PUBLIC modern-nutrition-solver)
#
#add_executable(prediction-tests predictionsTests.cpp)
#target_link_libraries(prediction-tests PUBLIC modern-nutrition-solver)
#
#add_executable(evaluation-tests evaluationTests.cpp)
#target_link_libraries(evaluation-tests PUBLIC modern-nutrition-solver)

add_executable(test-nutrition-facts test_nutrition_facts.cpp)
target_link_libraries(test-nutrition-facts PUBLIC nutrition-solver)

if(CMAKE_BUILD_TYPE MATCHES "(Debug|DEBUG|debug)")
    add_executable(test-food-database test_food_database.cpp)
    target_link_libraries(test-food-database PUBLIC nutrition-solver -fprofile-arcs)
else()
    add_executable(test-food-database test_food_database.cpp)
    target_link_libraries(test-food-database PUBLIC nutrition-solver)
endif()
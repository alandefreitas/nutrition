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

add_executable(test-food-database test_food_database.cpp test_user_preference.cpp)
add_executable(test-user-preference test_user_preference.cpp)
if(CMAKE_BUILD_TYPE MATCHES "(Debug|DEBUG|debug)")
    target_link_libraries(test-food-database PUBLIC nutrition-solver -fprofile-arcs)
    target_link_libraries(test-user-preference PUBLIC nutrition-solver -fprofile-arcs)
else()
    target_link_libraries(test-food-database PUBLIC nutrition-solver)
    target_link_libraries(test-user-preference PUBLIC nutrition-solver)
endif()



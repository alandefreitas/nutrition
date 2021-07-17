//
// Created by Glauber on 6/14/21.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "nutrition/user_preferences.h"

TEST_CASE( "Get food preferences matrix test" ) {
    nutrition::food_database tfd;
    size_t number_of_meals = 6;

    nutrition::user_preferences tup(tfd,number_of_meals);
    std::vector<nutrition::user_preferences::preference_matrix> pt = tup.get_food_preferences();

    REQUIRE_FALSE(pt.empty());
}

TEST_CASE( "Mock preferences values test" ) {
    nutrition::food_database tfd;
    size_t number_of_meals = 6;

    nutrition::user_preferences tup(tfd,number_of_meals);
    std::vector<nutrition::user_preferences::preference_matrix> pt = tup.get_food_preferences();

    if(pt[0][0][0].has_value()){
        REQUIRE(pt[0][0][0]>=0);
        REQUIRE(pt[0][0][0]<=10);
    }
}

TEST_CASE( "Category mock preferences test" ) {
    // TODO
}
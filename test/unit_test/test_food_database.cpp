//
// Created by glaubers on 23/04/2021.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "nutrition/food_database.h"
#include "nutrition/nutrition_facts.h"

TEST_CASE( "Database Load size test" ) {
    nutrition::food_database tfd;
    REQUIRE(tfd.size() > 0);
}

TEST_CASE( "Calories and name load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // General
    REQUIRE(_tfoods[0].calories == 307);
    REQUIRE(_tfoods[14163].calories == 892);
    REQUIRE(_tfoods[0].name == "Pillsbury Golden Layer Buttermilk Biscuits Artificial Flavor Refrigerated Dough");
    REQUIRE(_tfoods[14163].name == "Industrial Oil As Ingredient In Food");
    // REQUIRE(_tfoods[0].group == "Baked Foods");
    // REQUIRE(_tfoods[14163].group == "");
}

TEST_CASE( "Serving Weight load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // Serving size (in grams)
    REQUIRE(_tfoods[0].serving_weight == 34);
    REQUIRE(_tfoods[14163].serving_weight == 0);
}

TEST_CASE( "Basic facts values load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // Basic Facts
    REQUIRE(_tfoods[0].protein == 5.88);
    REQUIRE(_tfoods[0].fat == 13.24);
    REQUIRE(_tfoods[0].carbohydrates == 41.18);
    REQUIRE(_tfoods[0].sugars == 5.88);
    REQUIRE(_tfoods[0].fiber == 1.2);
    REQUIRE(_tfoods[0].cholesterol == 0);
    REQUIRE(_tfoods[0].saturated_fats == 2.941);
    REQUIRE(_tfoods[14163].protein == 0);
    REQUIRE(_tfoods[14163].fat == 100);
    REQUIRE(_tfoods[14163].carbohydrates == 0);
    REQUIRE(_tfoods[14163].sugars == 0);
    REQUIRE(_tfoods[14163].fiber == 0);
    REQUIRE(_tfoods[14163].cholesterol == 0);
    REQUIRE(_tfoods[14163].saturated_fats == 32.672);
}

TEST_CASE( "Vitamins values load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // Vitamins
    REQUIRE(_tfoods[0].calcium == 0);
    REQUIRE(_tfoods[0].iron == 2.12);
    REQUIRE(_tfoods[0].potassium == 0);
    REQUIRE(_tfoods[0].magnesium == 0);
    REQUIRE(_tfoods[0].vitamin_a == 0);
    REQUIRE(_tfoods[0].vitamin_c == 0);
    REQUIRE(_tfoods[0].vitamin_b_12 == 0);
    REQUIRE(_tfoods[0].vitamin_d == 0);
    REQUIRE(_tfoods[0].vitamin_e == 0);
    REQUIRE(_tfoods[0].omega_3 == 0);
    REQUIRE(_tfoods[0].omega_6 == 0);
    REQUIRE(_tfoods[0].lactose == 0);
    REQUIRE(_tfoods[0].phosphorus == 0);
    REQUIRE(_tfoods[0].sodium == 1059);
    REQUIRE(_tfoods[0].zinc == 0);
    REQUIRE(_tfoods[0].copper == 0);
    REQUIRE(_tfoods[0].manganese == 0);
    REQUIRE(_tfoods[0].selenium == 0);
    REQUIRE(_tfoods[0].carotene == 0);
    REQUIRE(_tfoods[14163].calcium == 0);
    REQUIRE(_tfoods[14163].iron == 0.04);
    REQUIRE(_tfoods[14163].potassium == 0);
    REQUIRE(_tfoods[14163].magnesium == 0);
    REQUIRE(_tfoods[14163].vitamin_a == 0);
    REQUIRE(_tfoods[14163].vitamin_c == 0);
    REQUIRE(_tfoods[14163].vitamin_b_12 == 0);
    REQUIRE(_tfoods[14163].vitamin_d == 0);
    REQUIRE(_tfoods[14163].vitamin_e == 10.5);
    REQUIRE(_tfoods[14163].omega_3 == 1698);
    REQUIRE(_tfoods[14163].omega_6 == 30114);
    REQUIRE(_tfoods[14163].lactose == 0);
    REQUIRE(_tfoods[14163].phosphorus == 0);
    REQUIRE(_tfoods[14163].sodium == 0);
    REQUIRE(_tfoods[14163].zinc == 0.01);
    REQUIRE(_tfoods[14163].copper == 0);
    REQUIRE(_tfoods[14163].manganese == 0);
    REQUIRE(_tfoods[14163].selenium == 0);
    REQUIRE(_tfoods[14163].carotene == 0);
}
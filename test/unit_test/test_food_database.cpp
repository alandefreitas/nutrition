//
// Created by glaubers on 23/04/2021.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "nutrition/food_database.h"
#include "nutrition/nutrition_facts.h"

TEST_CASE( "Database Load test" ) {
    nutrition::food_database tfd;
    const std::vector<nutrition::nutrition_facts>& _tfoods = tfd.foods();
    REQUIRE(!_tfoods.empty());
}

TEST_CASE( "Calories and name load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // General
    REQUIRE(_tfoods[0].calories == Approx(307));
    REQUIRE(_tfoods[14163].calories == Approx(892));
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
    REQUIRE(_tfoods[0].serving_weight == Approx(34));
    REQUIRE(_tfoods[14163].serving_weight == Approx(0));
}

TEST_CASE( "Basic facts values load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // Basic Facts
    REQUIRE(_tfoods[0].protein == Approx(5.88));
    REQUIRE(_tfoods[0].fat == Approx(13.24));
    REQUIRE(_tfoods[0].carbohydrates == Approx(41.18));
    REQUIRE(_tfoods[0].sugars == Approx(5.88));
    REQUIRE(_tfoods[0].fiber == Approx(1.2));
    REQUIRE(_tfoods[0].cholesterol == Approx(0));
    REQUIRE(_tfoods[0].saturated_fats == Approx(2.941));
    REQUIRE(_tfoods[14163].protein == Approx(0));
    REQUIRE(_tfoods[14163].fat == Approx(100));
    REQUIRE(_tfoods[14163].carbohydrates == Approx(0));
    REQUIRE(_tfoods[14163].sugars == Approx(0));
    REQUIRE(_tfoods[14163].fiber == Approx(0));
    REQUIRE(_tfoods[14163].cholesterol == Approx(0));
    REQUIRE(_tfoods[14163].saturated_fats == Approx(32.672));
}

TEST_CASE( "Vitamins values correct load test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    // Vitamins
    REQUIRE(_tfoods[0].calcium == Approx(0));
    REQUIRE(_tfoods[0].iron == Approx(2.12));
    REQUIRE(_tfoods[0].potassium == Approx(0));
    REQUIRE(_tfoods[0].magnesium == Approx(0));
    REQUIRE(_tfoods[0].vitamin_a == Approx(0));
    REQUIRE(_tfoods[0].vitamin_c == Approx(0));
    REQUIRE(_tfoods[0].vitamin_b_12 == Approx(0));
    REQUIRE(_tfoods[0].vitamin_d == Approx(0));
    REQUIRE(_tfoods[0].vitamin_e == Approx(0));
    REQUIRE(_tfoods[0].omega_3 == Approx(0));
    REQUIRE(_tfoods[0].omega_6 == Approx(0));
    REQUIRE(_tfoods[0].lactose == Approx(0));
    REQUIRE(_tfoods[0].phosphorus == Approx(0));
    REQUIRE(_tfoods[0].sodium == Approx(1059));
    REQUIRE(_tfoods[0].zinc == Approx(0));
    REQUIRE(_tfoods[0].copper == Approx(0));
    REQUIRE(_tfoods[0].manganese == Approx(0));
    REQUIRE(_tfoods[0].selenium == Approx(0));
    REQUIRE(_tfoods[0].carotene == Approx(0));
    REQUIRE(_tfoods[14163].calcium == Approx(0));
    REQUIRE(_tfoods[14163].iron == Approx(0.04));
    REQUIRE(_tfoods[14163].potassium == Approx(0));
    REQUIRE(_tfoods[14163].magnesium == Approx(0));
    REQUIRE(_tfoods[14163].vitamin_a == Approx(0));
    REQUIRE(_tfoods[14163].vitamin_c == Approx(0));
    REQUIRE(_tfoods[14163].vitamin_b_12 == Approx(0));
    REQUIRE(_tfoods[14163].vitamin_d == Approx(0));
    REQUIRE(_tfoods[14163].vitamin_e == Approx(10.5));
    REQUIRE(_tfoods[14163].omega_3 == Approx(1698));
    REQUIRE(_tfoods[14163].omega_6 == Approx(30114));
    REQUIRE(_tfoods[14163].lactose == Approx(0));
    REQUIRE(_tfoods[14163].phosphorus == Approx(0));
    REQUIRE(_tfoods[14163].sodium == Approx(0));
    REQUIRE(_tfoods[14163].zinc == Approx(0.01));
    REQUIRE(_tfoods[14163].copper == Approx(0));
    REQUIRE(_tfoods[14163].manganese == Approx(0));
    REQUIRE(_tfoods[14163].selenium == Approx(0));
    REQUIRE(_tfoods[14163].carotene == Approx(0));
}

TEST_CASE( "Database DELETE manipulation test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods;
    _tfoods = tfd.foods();

    size_t before_size = _tfoods.size();
    std::string before_food_name = _tfoods[before_size-1].name;

    tfd.delete_food(_tfoods.size()-1);

    _tfoods = tfd.foods();

    //Verification
    REQUIRE(_tfoods.size() == before_size-1);
    REQUIRE(_tfoods[_tfoods.size()-1].name != before_food_name);
}

// Insert data
TEST_CASE( "Database INSERT manipulation test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods = tfd.foods();

    size_t before_size = _tfoods.size();
    std::string before_food_name = _tfoods[before_size-1].name;

    nutrition::nutrition_facts new_nf;
    tfd.insert_food(new_nf);

    _tfoods = tfd.foods();

    // Verification
    REQUIRE(_tfoods.size() == before_size+1);
    REQUIRE(_tfoods.end()->name != before_food_name);
}

// Update data (SETTERS)
TEST_CASE( "Database UPDATE (set) manipulation test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods = tfd.foods();

    size_t before_size = _tfoods.size();
    std::string before_food_name = _tfoods[before_size-1].name;

    nutrition::nutrition_facts new_nf;
    new_nf.name = "Test";

    tfd.update_food(0,new_nf);
    _tfoods = tfd.foods();

    // Verification
    REQUIRE(_tfoods[0].name == "Test");
    REQUIRE(_tfoods[before_size-1].name == before_food_name);
    REQUIRE(_tfoods.size() == before_size);
}

// Delete data
TEST_CASE( "Database SELECT (get) manipulation test" ) {
    nutrition::food_database tfd;
    std::vector<nutrition::nutrition_facts> _tfoods = tfd.foods();

    size_t before_size = _tfoods.size();
    std::string before_food_name = _tfoods[before_size-1].name;

    nutrition::nutrition_facts nutrition_fact_test = tfd.select_food(before_size-1);

    // Verification
    REQUIRE(nutrition_fact_test.name == _tfoods[before_size-1].name);
    REQUIRE(_tfoods.size() == before_size);
}
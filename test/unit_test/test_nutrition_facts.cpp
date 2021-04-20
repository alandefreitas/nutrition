//
// Created by glauber on 20/04/2021.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "nutrition/nutrition_facts.h"

nutrition::nutrition_facts tnfacts;
nutrition::nutrition_facts tnfacts_other;

TEST_CASE( "Operator +=" ) {
    tnfacts.serving_weight = 10;
    tnfacts_other.serving_weight = 20;

    tnfacts.calories = 1;
    tnfacts_other.calories = 2;

    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    tnfacts.operator+=(tnfacts_other);
    REQUIRE(tnfacts.calories == (tnfacts_before_c + tnfacts_other.calories));
    REQUIRE(tnfacts.serving_weight == (tnfacts_before_sw + tnfacts_other.serving_weight));

    double tnfacts_other_before_sw = tnfacts_other.serving_weight;
    double tnfacts_other_before_c = tnfacts_other.calories;

    tnfacts_other.operator+=(tnfacts_other);
    REQUIRE(tnfacts_other_before_sw == (tnfacts_other.serving_weight/2));
    REQUIRE(tnfacts_other_before_c == (tnfacts_other.calories/2));
}

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

TEST_CASE( "Operator -=" ) {
    tnfacts.serving_weight = 30;
    tnfacts_other.serving_weight = 20;
    tnfacts.calories = 3;
    tnfacts_other.calories = 2;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;
    tnfacts.operator-=(tnfacts_other);
    REQUIRE(tnfacts.calories == (tnfacts_before_c - tnfacts_other.calories));
    REQUIRE(tnfacts.serving_weight == (tnfacts_before_sw - tnfacts_other.serving_weight));
}

TEST_CASE( "Operator /=" ) {
    // Set no zero values avoiding ASSERT invariants error
    tnfacts.serving_weight++;
    // General
    tnfacts.calories++;
    // Basic Facts
    tnfacts.protein++;
    tnfacts.fat++;
    tnfacts.carbohydrates++;
    tnfacts.sugars++;
    tnfacts.fiber++;
    tnfacts.cholesterol++;
    tnfacts.saturated_fats++;
    // Vitamins
    tnfacts.calcium++;
    tnfacts.iron++;
    tnfacts.potassium++;
    tnfacts.magnesium++;
    tnfacts.vitamin_a++;
    tnfacts.vitamin_c++;
    tnfacts.vitamin_b_12++;
    tnfacts.vitamin_d++;
    tnfacts.vitamin_e++;
    tnfacts.omega_3++;
    tnfacts.omega_6++;
    tnfacts.lactose++;
    tnfacts.phosphorus++;
    tnfacts.sodium++;
    tnfacts.zinc++;
    tnfacts.copper++;
    tnfacts.manganese++;
    tnfacts.selenium++;
    tnfacts.carotene++;

    double tnfacts_other_before_sw = tnfacts_other.serving_weight;
    double tnfacts_other_before_c = tnfacts_other.calories;

    tnfacts_other.operator/=(tnfacts);
    REQUIRE(tnfacts_other.calories == (tnfacts_other_before_c / tnfacts.calories));
    REQUIRE(tnfacts_other.serving_weight == (tnfacts_other_before_sw / tnfacts.serving_weight));

}

TEST_CASE( "Operator *=" ) {
    tnfacts.serving_weight = 5;
    tnfacts_other.serving_weight = 6;
    tnfacts.calories = 10;
    tnfacts_other.calories = 20;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    tnfacts.operator*=(tnfacts_other);
    REQUIRE(tnfacts.calories == (tnfacts_before_c * tnfacts_other.calories));
    REQUIRE(tnfacts.serving_weight == (tnfacts_before_sw * tnfacts_other.serving_weight));
}

/// Scalar Operator test
TEST_CASE( "Scalar Operator *=" ) {
    double scalar_change = 5;
    tnfacts.serving_weight = 5;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    tnfacts.operator*=(scalar_change);
    REQUIRE(tnfacts.calories == (tnfacts_before_c * scalar_change));
    REQUIRE(tnfacts.serving_weight == (tnfacts_before_sw * scalar_change));
}

TEST_CASE( "Scalar Operator /=" ) {
    double scalar_change = 2;

    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    tnfacts.operator/=(scalar_change);
    REQUIRE(tnfacts.calories == (tnfacts_before_c / scalar_change));
    REQUIRE(tnfacts.serving_weight == (tnfacts_before_sw / scalar_change));
}

TEST_CASE( "Scalar Operator /" ) {
    double scalar_change = 2;
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator/(scalar_change);
    REQUIRE(t.calories == (tnfacts_before_c / scalar_change));
    REQUIRE(t.serving_weight == (tnfacts_before_sw / scalar_change));
}

TEST_CASE( "Scalar Operator *" ) {
    double scalar_change = 2;
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator*(scalar_change);
    REQUIRE(t.calories == (tnfacts_before_c * scalar_change));
    REQUIRE(t.serving_weight == (tnfacts_before_sw * scalar_change));
}

TEST_CASE( "Operator *" ) {
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator*(tnfacts);
    REQUIRE(t.calories == (tnfacts_before_c * tnfacts_before_c));
    REQUIRE(t.serving_weight == (tnfacts_before_sw * tnfacts_before_sw));
}

TEST_CASE( "Operator +" ) {
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator+(tnfacts);
    REQUIRE(t.calories == (tnfacts_before_c + tnfacts_before_c));
    REQUIRE(t.serving_weight == (tnfacts_before_sw + tnfacts_before_sw));
}

TEST_CASE( "Operator -" ) {
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator-(tnfacts);
    REQUIRE(t.calories == (tnfacts_before_c - tnfacts_before_c));
    REQUIRE(t.serving_weight == (tnfacts_before_sw - tnfacts_before_sw));
}

TEST_CASE( "Operator /" ) {
    // Set no zero values avoiding ASSERT invariants error
    tnfacts.serving_weight++;
    // General
    tnfacts.calories++;
    // Basic Facts
    tnfacts.protein++;
    tnfacts.fat++;
    tnfacts.carbohydrates++;
    tnfacts.sugars++;
    tnfacts.fiber++;
    tnfacts.cholesterol++;
    tnfacts.saturated_fats++;
    // Vitamins
    tnfacts.calcium++;
    tnfacts.iron++;
    tnfacts.potassium++;
    tnfacts.magnesium++;
    tnfacts.vitamin_a++;
    tnfacts.vitamin_c++;
    tnfacts.vitamin_b_12++;
    tnfacts.vitamin_d++;
    tnfacts.vitamin_e++;
    tnfacts.omega_3++;
    tnfacts.omega_6++;
    tnfacts.lactose++;
    tnfacts.phosphorus++;
    tnfacts.sodium++;
    tnfacts.zinc++;
    tnfacts.copper++;
    tnfacts.manganese++;
    tnfacts.selenium++;
    tnfacts.carotene++;

    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    nutrition::nutrition_facts t = tnfacts.operator/(tnfacts);
    REQUIRE(t.calories == (tnfacts_before_c / tnfacts.calories));
    REQUIRE(t.serving_weight == (tnfacts_before_sw / tnfacts.serving_weight));
}
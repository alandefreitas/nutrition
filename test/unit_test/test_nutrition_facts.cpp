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

    // no negative test
    tnfacts.serving_weight = 30;
    tnfacts_other.serving_weight = 35;
    tnfacts.calories = 3;
    tnfacts_other.calories = 4;
    tnfacts.operator-=(tnfacts_other);
    REQUIRE(tnfacts.calories == 0);
    REQUIRE(tnfacts.serving_weight == 0);
}

TEST_CASE( "Operator /=" ) {
    tnfacts.serving_weight = 50;
    tnfacts_other.serving_weight = 25;
    tnfacts.calories = 10;
    tnfacts_other.calories = 3;

    // Zero denominator
    tnfacts.operator/=(tnfacts_other);
    REQUIRE(tnfacts.calories == tnfacts.calories);
    REQUIRE(tnfacts.serving_weight == tnfacts.serving_weight);

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
    double scalar_change = 3;
    tnfacts.serving_weight = 5;
    tnfacts.calories = 10;
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
    tnfacts.serving_weight = 6;
    tnfacts.calories = 10;
    double tnfacts_before_sw = tnfacts.serving_weight;
    double tnfacts_before_c = tnfacts.calories;

    // Zero denominator
    nutrition::nutrition_facts t = tnfacts.operator/(tnfacts);
    REQUIRE(t.calories == (tnfacts_before_c));
    REQUIRE(t.serving_weight == (tnfacts_before_sw));
}
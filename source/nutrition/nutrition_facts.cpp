//
// Created by Alan Freitas on 4/8/21.
//

#include "nutrition_facts.h"

namespace nutrition {
    std::ostream &operator<<(std::ostream &os,
                          const nutrition::nutrition_facts &facts) {
        os << "===============================\n";
        os << "NUTRITION FACTS" << facts.name << '\n';
        os << facts.name << '(' << facts.serving_weight << " g per serving)\n";
        os << "===============================\n";
        os << "===============================\n";
        os << "Calories: " << facts.calories << '\n';
        os << "===============================\n";
        os << "Protein (g): " << facts.protein << '\n';
        os << "Fat (g): " << facts.fat << '\n';
        os << "Carbohydrate (g): " << facts.carbohydrates << '\n';
        os << "Sugars (g): " << facts.sugars << '\n';
        os << "Fiber (g): " << facts.fiber << '\n';
        os << "Cholesterol (mg): " << facts.cholesterol << '\n';
        os << "Saturated Fats (g): " << facts.saturated_fats << '\n';
        os << "===============================\n";
        os << "Calcium (mg): " << facts.calcium << '\n';
        os << "Iron, Fe (mg): " << facts.iron << '\n';
        os << "Potassium, K (mg): " << facts.potassium << '\n';
        os << "Magnesium (mg): " << facts.magnesium << '\n';
        os << "Vitamin A, IU (IU): " << facts.vitamin_a << '\n';
        os << "Vitamin C (mg): " << facts.vitamin_c << '\n';
        os << "Vitamin B-12 (mcg): " << facts.vitamin_b_12 << '\n';
        os << "Vitamin D (mcg): " << facts.vitamin_d << '\n';
        os << "Vitamin E (Alpha-Tocopherol) (mg): " << facts.vitamin_e << '\n';
        os << "Omega 3s (mg): " << facts.omega_3 << '\n';
        os << "Omega 6s (mg): " << facts.omega_6 << '\n';
        os << "Lactose (g): " << facts.lactose << '\n';
        os << "Phosphorus, P (mg): " << facts.phosphorus << '\n';
        os << "Sodium (mg): " << facts.sodium << '\n';
        os << "Zinc, Zn (mg): " << facts.zinc << '\n';
        os << "Copper, Cu (mg): " << facts.copper << '\n';
        os << "Manganese (mg): " << facts.manganese << '\n';
        os << "Selenium, Se (mcg): " << facts.selenium << '\n';
        os << "Carotene, beta (mcg): " << facts.carotene << '\n';
        os << "===============================\n";

        return os;
    }

    nutrition_facts nutrition_facts::operator+(const nutrition_facts& other) const {
        nutrition_facts c(*this);
        c += other;
        return c;
    }

    nutrition_facts nutrition_facts::operator-(const nutrition_facts& other) const {
        nutrition_facts c(*this);
        c -= other;
        return c;
    }

    nutrition_facts nutrition_facts::operator*(const nutrition_facts& other) const {
        nutrition_facts c(*this);
        c *= other;
        return c;
    }

    nutrition_facts nutrition_facts::operator/(const nutrition_facts& other) const {
        nutrition_facts c(*this);
        c /= other;
        return c;
    }

    nutrition_facts& nutrition_facts::operator+=(const nutrition_facts& other) {
        // General
        calories += other.calories;

        // Serving size (in grams)
        serving_weight += other.serving_weight;

        // Basic Facts
        protein += other.protein;
        fat += other.fat;
        carbohydrates += other.carbohydrates;
        sugars += other.sugars;
        fiber += other.fiber;
        cholesterol += other.cholesterol;
        saturated_fats += other.saturated_fats;

        // Vitamins
        calcium += other.calcium;
        iron += other.iron;
        potassium += other.potassium;
        magnesium += other.magnesium;
        vitamin_a += other.vitamin_a;
        vitamin_c += other.vitamin_c;
        vitamin_b_12 += other.vitamin_b_12;
        vitamin_d += other.vitamin_d;
        vitamin_e += other.vitamin_e;
        omega_3 += other.omega_3;
        omega_6 += other.omega_6;
        lactose += other.lactose;
        phosphorus += other.phosphorus;
        sodium += other.sodium;
        zinc += other.zinc;
        copper += other.copper;
        manganese += other.manganese;
        selenium += other.selenium;
        carotene += other.carotene;

        return *this;
    }


    nutrition_facts& nutrition_facts::operator-=(const nutrition_facts& other) {
        // General
        calories -= other.calories;

        // Serving size (in grams)
        serving_weight -= other.serving_weight;

        // Basic Facts
        protein -= other.protein;
        fat -= other.fat;
        carbohydrates -= other.carbohydrates;
        sugars -= other.sugars;
        fiber -= other.fiber;
        cholesterol -= other.cholesterol;
        saturated_fats -= other.saturated_fats;

        // Vitamins
        calcium -= other.calcium;
        iron -= other.iron;
        potassium -= other.potassium;
        magnesium -= other.magnesium;
        vitamin_a -= other.vitamin_a;
        vitamin_c -= other.vitamin_c;
        vitamin_b_12 -= other.vitamin_b_12;
        vitamin_d -= other.vitamin_d;
        vitamin_e -= other.vitamin_e;
        omega_3 -= other.omega_3;
        omega_6 -= other.omega_6;
        lactose -= other.lactose;
        phosphorus -= other.phosphorus;
        sodium -= other.sodium;
        zinc -= other.zinc;
        copper -= other.copper;
        manganese -= other.manganese;
        selenium -= other.selenium;
        carotene -= other.carotene;

        return *this;
    }


    nutrition_facts& nutrition_facts::operator*=(const nutrition_facts& other) {
        // General
        calories *= other.calories;

        // Serving size (in grams)
        serving_weight *= other.serving_weight;

        // Basic Facts
        protein *= other.protein;
        fat *= other.fat;
        carbohydrates *= other.carbohydrates;
        sugars *= other.sugars;
        fiber *= other.fiber;
        cholesterol *= other.cholesterol;
        saturated_fats *= other.saturated_fats;

        // Vitamins
        calcium *= other.calcium;
        iron *= other.iron;
        potassium *= other.potassium;
        magnesium *= other.magnesium;
        vitamin_a *= other.vitamin_a;
        vitamin_c *= other.vitamin_c;
        vitamin_b_12 *= other.vitamin_b_12;
        vitamin_d *= other.vitamin_d;
        vitamin_e *= other.vitamin_e;
        omega_3 *= other.omega_3;
        omega_6 *= other.omega_6;
        lactose *= other.lactose;
        phosphorus *= other.phosphorus;
        sodium *= other.sodium;
        zinc *= other.zinc;
        copper *= other.copper;
        manganese *= other.manganese;
        selenium *= other.selenium;
        carotene *= other.carotene;

        return *this;
    }


    nutrition_facts& nutrition_facts::operator/=(const nutrition_facts& other) {
        // General
        calories /= other.calories;

        // Serving size (in grams)
        serving_weight /= other.serving_weight;

        // Basic Facts
        protein /= other.protein;
        fat /= other.fat;
        carbohydrates /= other.carbohydrates;
        sugars /= other.sugars;
        fiber /= other.fiber;
        cholesterol /= other.cholesterol;
        saturated_fats /= other.saturated_fats;

        // Vitamins
        calcium /= other.calcium;
        iron /= other.iron;
        potassium /= other.potassium;
        magnesium /= other.magnesium;
        vitamin_a /= other.vitamin_a;
        vitamin_c /= other.vitamin_c;
        vitamin_b_12 /= other.vitamin_b_12;
        vitamin_d /= other.vitamin_d;
        vitamin_e /= other.vitamin_e;
        omega_3 /= other.omega_3;
        omega_6 /= other.omega_6;
        lactose /= other.lactose;
        phosphorus /= other.phosphorus;
        sodium /= other.sodium;
        zinc /= other.zinc;
        copper /= other.copper;
        manganese /= other.manganese;
        selenium /= other.selenium;
        carotene /= other.carotene;

        return *this;
    }

    nutrition_facts nutrition_facts::operator*(double scalar) const {
        nutrition_facts c(*this);
        c *= scalar;
        return c;
    }

    nutrition_facts nutrition_facts::operator/(double scalar) const {
        nutrition_facts c(*this);
        c /= scalar;
        return c;
    }

    nutrition_facts& nutrition_facts::operator*=(double scalar) {
        // General
        calories *= scalar;

        // Serving size (in grams)
        serving_weight *= scalar;

        // Basic Facts
        protein *= scalar;
        fat *= scalar;
        carbohydrates *= scalar;
        sugars *= scalar;
        fiber *= scalar;
        cholesterol *= scalar;
        saturated_fats *= scalar;

        // Vitamins
        calcium *= scalar;
        iron *= scalar;
        potassium *= scalar;
        magnesium *= scalar;
        vitamin_a *= scalar;
        vitamin_c *= scalar;
        vitamin_b_12 *= scalar;
        vitamin_d *= scalar;
        vitamin_e *= scalar;
        omega_3 *= scalar;
        omega_6 *= scalar;
        lactose *= scalar;
        phosphorus *= scalar;
        sodium *= scalar;
        zinc *= scalar;
        copper *= scalar;
        manganese *= scalar;
        selenium *= scalar;
        carotene *= scalar;

        return *this;
    }

    nutrition_facts& nutrition_facts::operator/=(double scalar) {
        // General
        calories /= scalar;

        // Serving size (in grams)
        serving_weight /= scalar;

        // Basic Facts
        protein /= scalar;
        fat /= scalar;
        carbohydrates /= scalar;
        sugars /= scalar;
        fiber /= scalar;
        cholesterol /= scalar;
        saturated_fats /= scalar;

        // Vitamins
        calcium /= scalar;
        iron /= scalar;
        potassium /= scalar;
        magnesium /= scalar;
        vitamin_a /= scalar;
        vitamin_c /= scalar;
        vitamin_b_12 /= scalar;
        vitamin_d /= scalar;
        vitamin_e /= scalar;
        omega_3 /= scalar;
        omega_6 /= scalar;
        lactose /= scalar;
        phosphorus /= scalar;
        sodium /= scalar;
        zinc /= scalar;
        copper /= scalar;
        manganese /= scalar;
        selenium /= scalar;
        carotene /= scalar;

        return *this;
    }

}
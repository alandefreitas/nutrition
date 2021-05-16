//
// Created by Alan Freitas on 4/8/21.
//

#include "nutrition_facts.h"
#include <cassert>
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

    nutrition_facts& nutrition_facts::operator+=(const nutrition_facts& other) {
        // General
        calories += other.calories;
        assert(this->invariants());

        // Serving size (in grams)
        serving_weight += other.serving_weight;
        assert(this->invariants());

        // Basic Facts
        protein += other.protein;
        assert(this->invariants());
        fat += other.fat;
        assert(this->invariants());
        carbohydrates += other.carbohydrates;
        assert(this->invariants());
        sugars += other.sugars;
        assert(this->invariants());
        fiber += other.fiber;
        assert(this->invariants());
        cholesterol += other.cholesterol;
        assert(this->invariants());
        saturated_fats += other.saturated_fats;
        assert(this->invariants());

        // Vitamins
        calcium += other.calcium;
        assert(this->invariants());
        iron += other.iron;
        assert(this->invariants());
        potassium += other.potassium;
        assert(this->invariants());
        magnesium += other.magnesium;
        assert(this->invariants());
        vitamin_a += other.vitamin_a;
        assert(this->invariants());
        vitamin_c += other.vitamin_c;
        assert(this->invariants());
        vitamin_b_12 += other.vitamin_b_12;
        assert(this->invariants());
        vitamin_d += other.vitamin_d;
        assert(this->invariants());
        vitamin_e += other.vitamin_e;
        assert(this->invariants());
        omega_3 += other.omega_3;
        assert(this->invariants());
        omega_6 += other.omega_6;
        assert(this->invariants());
        lactose += other.lactose;
        assert(this->invariants());
        phosphorus += other.phosphorus;
        assert(this->invariants());
        sodium += other.sodium;
        assert(this->invariants());
        zinc += other.zinc;
        assert(this->invariants());
        copper += other.copper;
        assert(this->invariants());
        manganese += other.manganese;
        assert(this->invariants());
        selenium += other.selenium;
        assert(this->invariants());
        carotene += other.carotene;
        assert(this->invariants());

        return *this;
    }

    nutrition_facts& nutrition_facts::operator-=(const nutrition_facts& other) {

        // Serving size (in grams)
        serving_weight -= other.serving_weight;
        assert(this->invariants());
        // General
        calories -= other.calories;
        assert(this->invariants());

        // Basic Facts
        protein -= other.protein;
        assert(this->invariants());
        fat -= other.fat;
        assert(this->invariants());
        carbohydrates -= other.carbohydrates;
        assert(this->invariants());
        sugars -= other.sugars;
        assert(this->invariants());
        fiber -= other.fiber;
        assert(this->invariants());
        cholesterol -= other.cholesterol;
        assert(this->invariants());
        saturated_fats -= other.saturated_fats;
        assert(this->invariants());

        // Vitamins
        calcium -= other.calcium;
        assert(this->invariants());
        iron -= other.iron;
        assert(this->invariants());
        potassium -= other.potassium;
        assert(this->invariants());
        magnesium -= other.magnesium;
        assert(this->invariants());
        vitamin_a -= other.vitamin_a;
        assert(this->invariants());
        vitamin_c -= other.vitamin_c;
        assert(this->invariants());
        vitamin_b_12 -= other.vitamin_b_12;
        assert(this->invariants());
        vitamin_d -= other.vitamin_d;
        assert(this->invariants());
        vitamin_e -= other.vitamin_e;
        assert(this->invariants());
        omega_3 -= other.omega_3;
        assert(this->invariants());
        omega_6 -= other.omega_6;
        assert(this->invariants());
        lactose -= other.lactose;
        assert(this->invariants());
        phosphorus -= other.phosphorus;
        assert(this->invariants());
        sodium -= other.sodium;
        assert(this->invariants());
        zinc -= other.zinc;
        assert(this->invariants());
        copper -= other.copper;
        assert(this->invariants());
        manganese -= other.manganese;
        assert(this->invariants());
        selenium -= other.selenium;
        assert(this->invariants());
        carotene -= other.carotene;
        assert(this->invariants());

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
        assert(this->invariants());

        // Serving size (in grams)
        serving_weight *= scalar;
        assert(this->invariants());

        // Basic Facts
        protein *= scalar;
        assert(this->invariants());
        fat *= scalar;
        assert(this->invariants());
        carbohydrates *= scalar;
        assert(this->invariants());
        sugars *= scalar;
        assert(this->invariants());
        fiber *= scalar;
        assert(this->invariants());
        cholesterol *= scalar;
        assert(this->invariants());
        saturated_fats *= scalar;
        assert(this->invariants());

        // Vitamins
        calcium *= scalar;
        assert(this->invariants());
        iron *= scalar;
        assert(this->invariants());
        potassium *= scalar;
        assert(this->invariants());
        magnesium *= scalar;
        assert(this->invariants());
        vitamin_a *= scalar;
        assert(this->invariants());
        vitamin_c *= scalar;
        assert(this->invariants());
        vitamin_b_12 *= scalar;
        assert(this->invariants());
        vitamin_d *= scalar;
        assert(this->invariants());
        vitamin_e *= scalar;
        assert(this->invariants());
        omega_3 *= scalar;
        assert(this->invariants());
        omega_6 *= scalar;
        assert(this->invariants());
        lactose *= scalar;
        assert(this->invariants());
        phosphorus *= scalar;
        assert(this->invariants());
        sodium *= scalar;
        assert(this->invariants());
        zinc *= scalar;
        assert(this->invariants());
        copper *= scalar;
        assert(this->invariants());
        manganese *= scalar;
        assert(this->invariants());
        selenium *= scalar;
        assert(this->invariants());
        carotene *= scalar;
        assert(this->invariants());

        return *this;
    }

    nutrition_facts& nutrition_facts::operator/=(double scalar) {

        // General
        calories /= scalar;
        assert(this->invariants());

        // Serving size (in grams)
        serving_weight /= scalar;
        assert(this->invariants());

        // Basic Facts
        protein /= scalar;
        assert(this->invariants());
        fat /= scalar;
        assert(this->invariants());
        carbohydrates /= scalar;
        assert(this->invariants());
        sugars /= scalar;
        assert(this->invariants());
        fiber /= scalar;
        assert(this->invariants());
        cholesterol /= scalar;
        assert(this->invariants());
        saturated_fats /= scalar;
        assert(this->invariants());

        // Vitamins
        calcium /= scalar;
        assert(this->invariants());
        iron /= scalar;
        assert(this->invariants());
        potassium /= scalar;
        assert(this->invariants());
        magnesium /= scalar;
        assert(this->invariants());
        vitamin_a /= scalar;
        assert(this->invariants());
        vitamin_c /= scalar;
        assert(this->invariants());
        vitamin_b_12 /= scalar;
        assert(this->invariants());
        vitamin_d /= scalar;
        assert(this->invariants());
        vitamin_e /= scalar;
        assert(this->invariants());
        omega_3 /= scalar;
        assert(this->invariants());
        omega_6 /= scalar;
        assert(this->invariants());
        lactose /= scalar;
        assert(this->invariants());
        phosphorus /= scalar;
        assert(this->invariants());
        sodium /= scalar;
        assert(this->invariants());
        zinc /= scalar;
        assert(this->invariants());
        copper /= scalar;
        assert(this->invariants());
        manganese /= scalar;
        assert(this->invariants());
        selenium /= scalar;
        assert(this->invariants());
        carotene /= scalar;
        assert(this->invariants());

        return *this;
    }

    // Invariant check
    bool nutrition_facts::invariants() const{
        // Check for invalid result value of each nutrient
        if (this->serving_weight <0) return false;
        if (this->calories < 0) return false;
        if (this->protein <0) return false;
        if (this->fat <0) return false;
        if (this->carbohydrates <0)return false;
        if (this->sugars <0) return false;
        if (this->fiber <0) return false;
        if (this->cholesterol <0)return false;
        if (this->saturated_fats <0) return false;
        if (this->calcium <0) return false;
        if (this->iron <0) return false;
        if (this->potassium <0) return false;
        if (this->magnesium <0)return false;
        if (this->vitamin_a <0) return false;
        if (this->vitamin_b_12 <0) return false;
        if (this->vitamin_c <0) return false;
        if (this->vitamin_d <0) return false;
        if (this->vitamin_e <0) return false;
        if (this->omega_3 <0) return false;
        if (this->omega_6 <0) return false;
        if (this->lactose <0) return false;
        if (this->phosphorus <0) return false;
        if (this->sodium <0) return false;
        if (this->zinc <0) return false;
        if (this->copper <0) return false;
        if (this->manganese <0) return false;
        if (this->selenium <0) return false;
        if (this->carotene <0) return false;

        return true;
    }
}
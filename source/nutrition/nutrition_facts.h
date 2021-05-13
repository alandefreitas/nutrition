//
// Created by Alan Freitas on 4/8/21.
//

#ifndef MODERN_NUTRITION_NUTRITION_FACTS_H
#define MODERN_NUTRITION_NUTRITION_FACTS_H

#include <ostream>
#include <string>

namespace nutrition {
    /// \brief Nutrition facts for one type of food
    struct nutrition_facts {
        // Food name
        std::string name;

        // General
        double calories;

        // Serving size (in grams)
        double serving_weight;

        // Basic Facts
        double protein;
        double fat;
        double carbohydrates;
        double sugars;
        double fiber;
        double cholesterol;
        double saturated_fats;

        // Vitamins
        double calcium;
        double iron;
        double potassium;
        double magnesium;
        double vitamin_a;
        double vitamin_c;
        double vitamin_b_12;
        double vitamin_d;
        double vitamin_e;
        double omega_3;
        double omega_6;
        double lactose;
        double phosphorus;
        double sodium;
        double zinc;
        double copper;
        double manganese;
        double selenium;
        double carotene;

        // Stream operator
        friend std::ostream &operator<<(std::ostream &os,
                                       const nutrition_facts &facts);

        // Convenience operator +
        nutrition_facts operator+(const nutrition_facts& other) const;

        // Convenience operator -
        nutrition_facts operator-(const nutrition_facts& other) const;

        // Convenience operator +=
        nutrition_facts& operator+=(const nutrition_facts& other);

        // Convenience operator -=
        nutrition_facts& operator-=(const nutrition_facts& other);

        // Convenience operator *
        nutrition_facts operator*(double scalar) const;

        // Convenience operator /
        nutrition_facts operator/(double scalar) const;

        // Convenience operator *=
        nutrition_facts& operator*=(double scalar);

        // Convenience operator /=
        nutrition_facts& operator/=(double scalar);

      private:
        /// Invariants
        // No zero and negative for operator/=
        void invariant_no_zero_and_negative(const nutrition_facts& other_to_check);
        bool invariant_no_zero_and_negative(double scalar);
        // No negative value for operator*= (allow zeros)
        bool invariant_no_negative_only(double value);
        void invariant_no_negative_only(const nutrition_facts& other_to_check);
        // No negative result value for operator-=
        void invariant_no_negative_result_only(const nutrition_facts& result);

    };

}

#endif // MODERN_NUTRITION_NUTRITION_FACTS_H

//
// Created by Alan Freitas on 4/8/21.
//

#include "food_database.h"
#include <fstream>
#include <csv.hpp>

namespace nutrition {

    food_database::food_database() : food_database(RESOURCES_PATH "/nutrition-facts.csv") {}

    food_database::food_database(const std::string &filename) {
        load(filename);
    }

    void food_database::load(const std::string &filename) {
        // Open File from
        // https://tools.myfooddata.com/nutrition-facts-database-spreadsheet.php
        std::ifstream fin(filename);

        if (fin.is_open()) {
            csv::CSVReader reader(fin);
            for (auto &row : reader) {
                nutrition_facts tmp;

                // Name
                tmp.name = row["Name"].get<std::string>();

                auto double_or_zero = [](csv::CSVField field) -> double {
                  if (field.is_num()) {
                      return field.get<double>();
                  } else {
                      return 0.0;
                  }
                };

                // General
                tmp.calories = row["Calories"].get<double>();

                // Serving size (in grams)
                tmp.serving_weight = double_or_zero(row["Serving Weight 1 (g)"]);

                // Basic Facts
                tmp.protein = double_or_zero(row["Protein (g)"]);
                tmp.fat = double_or_zero(row["Fat (g)"]);
                tmp.carbohydrates = double_or_zero(row["Carbohydrate (g)"]);
                tmp.sugars = double_or_zero(row["Sugars (g)"]);
                tmp.fiber = double_or_zero(row["Fiber (g)"]);
                tmp.cholesterol = double_or_zero(row["Cholesterol (mg)"]);
                tmp.saturated_fats = double_or_zero(row["Saturated Fats (g)"]);

                // Vitamins
                tmp.calcium = double_or_zero(row["Calcium (mg)"]);
                tmp.iron = double_or_zero(row["Iron, Fe (mg)"]);
                tmp.potassium = double_or_zero(row["Potassium, K (mg)"]);
                tmp.magnesium = double_or_zero(row["Magnesium (mg)"]);
                tmp.vitamin_a = double_or_zero(row["Vitamin A, IU (IU)"]);
                tmp.vitamin_c = double_or_zero(row["Vitamin C (mg)"]);
                tmp.vitamin_b_12 = double_or_zero(row["Vitamin B-12 (mcg)"]);
                tmp.vitamin_d = double_or_zero(row["Vitamin D (mcg)"]);
                tmp.vitamin_e = double_or_zero(row["Vitamin E (Alpha-Tocopherol) (mg)"]);
                tmp.omega_3 = double_or_zero(row["Omega 3s (mg)"]);
                tmp.omega_6 = double_or_zero(row["Omega 6s (mg)"]);
                tmp.lactose = double_or_zero(row["Lactose (g)"]);
                tmp.phosphorus = double_or_zero(row["Phosphorus, P (mg)"]);
                tmp.sodium = double_or_zero(row["Sodium (mg)"]);
                tmp.zinc = double_or_zero(row["Zinc, Zn (mg)"]);
                tmp.copper = double_or_zero(row["Copper, Cu (mg)"]);
                tmp.manganese = double_or_zero(row["Manganese (mg)"]);
                tmp.selenium = double_or_zero(row["Selenium, Se (mcg)"]);
                tmp.carotene = double_or_zero(row["Carotene, beta (mcg)"]);

                (void)foods_.emplace_back(tmp);
            }
        } else {
            throw std::runtime_error("serialization::load_nutrition_facts: "
                                     "can't load nutrition facts");
        }
    }
    const std::vector<nutrition_facts> &food_database::foods() const { return foods_; }
    void food_database::foods(const std::vector<nutrition_facts> &foods) { foods_ = foods; }
    size_t food_database::size() const { return foods_.size(); }

    void food_database::delete_food(int food_index){foods_.begin() + food_index;}
    void food_database::update_food(int food_index, nutrition_facts new_food){
        foods_[food_index] = new_food;
    }

}
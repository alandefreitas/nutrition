#include "user_targets.h"
#include <algorithm>
#include <cstring>
#include <csv.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

namespace nutrition {
    user_targets::user_targets(const nutrition_facts &nutrition_targets, std::vector<int> meal_times)
        : meal_times_(meal_times.empty() ? std::vector<int>({12}) : std::move(meal_times)) {
        meal_targets_.resize(meal_times_.size());
        if (meal_targets_.size() == 6) {
            // Create 6 meals if user has not provided the meals
            meal_targets_[0] = nutrition_targets * 0.2;
            meal_targets_[1] = nutrition_targets * 0.1;
            meal_targets_[2] = nutrition_targets * 0.3;
            meal_targets_[3] = nutrition_targets * 0.1;
            meal_targets_[4] = nutrition_targets * 0.2;
            meal_targets_[5] = nutrition_targets * 0.1;
        } else {
            // Distribute targets equally otherwise
            for (auto &target : meal_targets_) {
                target = nutrition_targets / meal_targets_.size();
            }
        }

        // Get nutrition facts from a text file
        load_nutrition_facts();

        // Generate a food history representing a fictional past behavior
        // from the user for the preference matrices
        generate_mock_preference();
    }

    std::string user_targets::get_meal_name(size_t idx) const {
        if (meal_targets_.size() == 1) {
            return "Single mean a day";
        }
        if (meal_targets_.size() > 6) {
            return std::string("Meal ") + std::to_string(idx);
        }
        if (idx == 0) {
            return "Breakfast";
        }
        if (idx == 1) {
            return meal_targets_.size() <= 4 ? "Lunch" : "Snack";
        }
        if (idx == 2) {
            if (meal_targets_.size() == 3) {
                return "Dinner";
            } else if (meal_targets_.size() == 4) {
                return "Snack";
            } else if (meal_targets_.size() >= 5) {
                return "Lunch";
            }
        }
        if (idx == 3) {
            if (meal_targets_.size() == 3) {
                return "Dinner";
            } else if (meal_targets_.size() == 4) {
                return "Snack";
            } else if (meal_targets_.size() >= 5) {
                return "Lunch";
            }
        }
        if (idx == 4) {
            return "Dinner";
        }
        return "Snack";
    }

    std::ostream &operator<<(std::ostream &os, const user_targets &instance) {
        os << "Nutrition problem (" << instance.foods_.size() << " foods)\n";
        for (int i = 0; i < instance.meal_targets_.size(); ++i) {
            os << "User targets for " << instance.get_meal_name(i) << '\n';
            os << instance.meal_targets_[0] << '\n';
        }
        return os;
    }

    // Prints the instance
    void user_targets::print() const {
        std::cout << *this;
    }

    // Save on file the instance
    void user_targets::print_to_file(std::ofstream &fout) const {
        fout << *this;
    }

    const std::vector<nutrition_facts> &user_targets::meal_targets() const { return meal_targets_; }
    void user_targets::meal_targets(const std::vector<nutrition_facts> &meal_targets) {
        meal_targets_ = meal_targets;
    }

} // namespace nutrition

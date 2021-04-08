#include "nutrition_facts.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#ifndef ComEvoGlauber_opnP_H
#define ComEvoGlauber_opnP_H

#include <optional>
#include <vector>

namespace nutrition {
    /// \class This class describes the problem
    /// It contains the nutrition facts for each food
    /// and the preference tables for each of them.
    class user_targets {
      public /* types */:
        enum class optimization_model {
            // Only check number of targets per day.
            // static optimization_model refers to equations 3.1 and 3.2 on page 24
            STATIC,
            // Check distance to targets for each meal.
            // static optimization_model with meal_time refers to equations 3.3 - 3.6 on page
            // 26
            STATIC_MEALTIME,
            // No preferences. Update problem dynamically.
            // dynamic optimization_model without preferences refers to equations 3.7 - 3.9
            // on page 27
            DYNAMIC_ONLY,
            // Update preferences.
            // dynamic optimization_model considering preferences refers to equations 3.7
            // - 3.9 on page 27
            DYNAMIC_PREFERENCES_PREDICTION
        };

      public:
        /// \brief Creates the problem based on the instances
        /// This is a mock problem where the nutrition facts
        /// come from a text file but the preferences are
        /// inferred from an stochastically fictional history
        /// \param nutrition_targets Nutrition targets for the user
        /// \param user_meal_times Time of each meal
        user_targets(const nutrition_facts &nutrition_targets, std::vector<int> user_meal_times);

      public /* convenience functions */:
        /// \brief Prints the relevant problem information
        void print() const;

        /// \brief Prints the relevant problem information in a file (not serialized)
        void print_to_file(std::ofstream &fout) const;

        /// \brief Get the direction of the FO (max or min)
        constexpr static inline bool is_minimization() { return true; };

      public /* getters and setters */:
        /// Get meal_targets
        [[nodiscard]] const std::vector<nutrition_facts> &meal_targets() const;

        /// Set meal_targets
        void meal_targets(const std::vector<nutrition_facts> &meal_targets);

        /// Get meal_times
        [[nodiscard]] const std::vector<int> &meal_times() const;

        /// Set meal_times
        void meal_times(const std::vector<int> &meal_times);

        /// Get model
        [[nodiscard]] optimization_model model() const;

        /// Set model
        void model(enum optimization_model model);

      public /* convenience */:
        friend std::ostream &operator<<(std::ostream &os, const user_targets &targets);

      private:
        /// \brief Get a representative name for a meal with index idx in the day
        [[nodiscard]] std::string get_meal_name(size_t idx) const;

      private:
        /// \brief Targets for each nutrition fact
        std::vector<nutrition_facts> meal_targets_;

        /// \brief The type of optimization_model we want to optimize
        optimization_model model_;

        /// \brief A preference table for each meal
        // std::vector<preference_matrix> food_preference_;

        /// \brief Time of each meal
        // std::vector<int> meal_times_;
    };

} // namespace nutrition

#endif // ComEvoGlauber_opnP_HH
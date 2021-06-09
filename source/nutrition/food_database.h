//
// Created by Alan Freitas on 4/8/21.
//

#ifndef MODERN_NUTRITION_FOOD_DATABASE_H
#define MODERN_NUTRITION_FOOD_DATABASE_H

#include "nutrition_facts.h"
#include <optional>
#include <vector>

namespace nutrition {
    /// \brief Food database
    /// The database will load the food nutrition facts from a csv file
    class food_database {
      public:
        /// \brief Create a food database
        /// If no file is provided, we open a file from
        /// https://tools.myfooddata.com/nutrition-facts-database-spreadsheet.php
        food_database();

        /// \brief Create a food database from this file
        explicit food_database(const std::string &filename);

        /// \brief Load a file
        void load(const std::string &filename);

      public /* getters and setters */:

        [[nodiscard]] const std::vector<nutrition_facts> &foods() const;
        void foods(const std::vector<nutrition_facts> &foods);

        [[nodiscard]] size_t size() const;

        void erase(unsigned food_index);

        void update(unsigned food_index, nutrition_facts food_to_update);

        void insert(const nutrition_facts& new_food);

        [[nodiscard]] const nutrition_facts& at(unsigned index) const;

        nutrition_facts& at(unsigned index);

        nutrition_facts& operator[](unsigned index);

        bool empty();

      private:
        /// \brief Nutrition facts for each food
        std::vector<nutrition_facts> foods_;
    };

} // namespace nutrition

#endif // MODERN_NUTRITION_FOOD_DATABASE_H

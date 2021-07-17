#ifndef NUTRITION_PREFERENCES_H
#define NUTRITION_PREFERENCES_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <unordered_set>
#include <vector>

#include "food_database.h"

namespace nutrition {

    /// \brief The preferences a user has for each meal
    class user_preferences {
      public:
        /// \brief Table type with food preferences for each meal
        using preference_matrix = std::vector<std::vector<std::optional<double>>>;

        /// \brief Tuple with food category range used for preferences calculation
        std::vector<std::tuple<std::string,size_t,size_t>> ranged_preferences(const food_database& db);

        /// \brief Category range build
        std::vector<std::pair<size_t, size_t>> construct(std::vector<std::string> _category_range, const food_database& db);

      public:
        /// \brief Construct a mock preference table
        explicit user_preferences(const food_database& db, size_t n_meals);

        std::vector<preference_matrix>& get_food_preferences();

      private:
        /// \brief Construct random mock preferences internally
        void generate_mock_preferences(const food_database& db, size_t n_meals);

        /// \brief Construct a mock preferences based on food categories and mealstime
        void generate_category_mock_preferences(const food_database& db, size_t n_meals);

        /// \brief Read external food database preference
        // void get_external_preferences(const food_database& db, size_t n_meals);

      private:
        /// Food preference for each meal
        std::vector<preference_matrix> food_preferences_;

//        /// Getters
//        // item-item collaborative filter
//        std::vector<std::vector<double>>
//        normalize(std::vector<std::vector<int>> _preferencesMatrix,
//                  std::vector<std::vector<int>> _portionsPreferences);
//
//        std::vector<double>
//        euclidean_distance(std::vector<std::vector<int>> _preferencesMatrix,
//                           std::vector<std::vector<double>> _normalizedRank,
//                           size_t size);
//
//        std::vector<std::vector<double>>
//        similarity_cosines(std::vector<std::vector<double>> _normalizedRank,
//                           std::vector<std::vector<int>> _idsMatrix,
//                           std::vector<double> l2, size_t size);
//        std::vector<double>
//        score_calc(std::vector<std::vector<double>> _normalizedRank,
//                   std::vector<std::vector<double>> _itensMatrix,
//                   std::vector<std::vector<int>> _idsMatrix, int user, size_t size);
//        ///Search for itens consume similarity
//        int searchSimilarItensToBreakfast(
//            int userSimilarity, std::vector<int> _localBreakfastPreferences,
//            std::vector<std::vector<int>> __breakfastPreferencesMatrix);
//        int snack1SimilaritySearch(
//            int similarUser, std::vector<int> _localBreakfastPreferences,
//            std::vector<std::vector<int>> _breakfastPreferencesMatrix,
//            std::vector<int> _localSnack1Preferences,
//            std::vector<std::vector<int>> _snack1PreferencesMatrix);
//        int lunchSimilaritySearch(
//            int usuarioSemelhante, std::vector<int> _localBreakfastPreferences,
//            std::vector<std::vector<int>> _matrizPreferenciasDesjejum,
//            std::vector<int> _localSnack1Preferences,
//            std::vector<std::vector<int>> _matrizPreferenciasLanche1,
//            std::vector<int> _localLunchPreferences,
//            std::vector<std::vector<int>> _matrizPreferenciasAlmoco);
//        int snack2SimilaritySearch(
//            int usuarioSemelhante, std::vector<int> _localBreakfastPreferences,
//            std::vector<std::vector<int>> _breakfastPreferenceMatrix,
//            std::vector<int> _localSnack1Preferences,
//            std::vector<std::vector<int>> _matrizPreferenciasLanche1,
//            std::vector<int> _localLunchPreferences,
//            std::vector<std::vector<int>> _matrizPreferenciasAlmoco,
//            std::vector<int> _localSnack2Preferences,
//            std::vector<std::vector<int>> _matrizPreferenciasLanche2);
//        int dinnerSimilaritySearch(
//            int similarUser, std::vector<int> _localBreakfastPreferences,
//            std::vector<std::vector<int>> _breakfastPreferenceMatrix,
//            std::vector<int> _localSnack1Preferences,
//            std::vector<std::vector<int>> __snack1PreferencesMatrix,
//            std::vector<int> _localLunchPreferences,
//            std::vector<std::vector<int>> __lunchPreferencesMatrix,
//            std::vector<int> _localSnack2Preferences,
//            std::vector<std::vector<int>> __snack2PreferencesMatrix,
//            std::vector<int> _localDinnerPreferences,
//            std::vector<std::vector<int>> __dinnerPreferencesMatrix);
//        //Print considered user
//        void printScreenUser(const predictions::user_preferences& u);
//        void printScreenFile(const predictions::user_preferences& u, std::ofstream &fout);
//        [[nodiscard]] int getAge() const;
//        [[nodiscard]] std::string getName() const;
//        [[nodiscard]] double getWeight() const;
//        [[nodiscard]] double getHigh() const;
//        [[nodiscard]] int getCaloriesBurn() const;
//        [[nodiscard]] std::vector<std::string> getHobbies() const;
//        [[nodiscard]] std::string getHobbie(int i) const;
//        [[nodiscard]] double getImc() const;
//        [[nodiscard]] std::vector<int> getMealsTime() const;
//        [[nodiscard]] int getMealstimeHour(int i) const;
//        [[nodiscard]] int getNumberOfMealsTime() const;
//        [[nodiscard]] double getTarget() const;
//        [[nodiscard]] int getGender() const;
//        [[nodiscard]] std::vector<int> getBreakfastPreferences() const;
//        [[nodiscard]] std::vector<int> getBreakfastPreferencesPortions() const;
//        [[nodiscard]] std::vector<int> getSnack1Preferences() const;
//        [[nodiscard]] std::vector<int> getSnack1PortionPreferences() const;
//        [[nodiscard]] std::vector<int> getLunchPreferences() const;
//        [[nodiscard]] std::vector<int> getLunchPortionsPreferences() const;
//        [[nodiscard]] std::vector<int> getSnack2Preferences() const;
//        [[nodiscard]] std::vector<int> getSnack2PreferencesPortions() const;
//        [[nodiscard]] std::vector<int> getDinnerPreferences() const;
//        [[nodiscard]] std::vector<int> getDinnerPreferencesPortions() const;
//        [[nodiscard]] std::vector<int> getPreferenciasCeia() const;
//        [[nodiscard]] std::vector<int> getPorcaoPreferenciasCeia() const;

      private:
//        int gender;
//        int caloriesBurn;
//        float weight;
//        double high;
//        double target;
//        std::string name;
//        std::vector<int> _mealsTime;
//        std::vector<std::string> _hobbies;
//        std::vector<int> _breakfastPreferences;
//        std::vector<int> _breakfastPreferencesPortions;
//        std::vector<int> _snack1Preferences;
//        std::vector<int> _snack1PreferencesPortions;
//        std::vector<int> _lunchPreferences;
//        std::vector<int> _lunchPreferencesPortions;
//        std::vector<int> _snack2Preferences;
//        std::vector<int> _snack2PreferencesPortions;
//        std::vector<int> _dinnerPreferences;
//        std::vector<int> _dinnerPreferencesPortions;
//        std::vector<int> _supperPreferences;
//        std::vector<int> _supperPreferencesPortions;
    };

}

/// prints the final diet on the screen and in the file
//void printMenu(const predictions::user_preferences &u);

#endif // NUTRITION_PREFERENCES_H

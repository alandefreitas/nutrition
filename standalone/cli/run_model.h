

#ifndef MNUTRITION_STATIC_MODEL_H
#define MNUTRITION_STATIC_MODEL_H

#include <string>

void run_static_model(const std::string& file_output);
void run_static_mealstime_model(const std::string& file_output);
void run_dynamic_preferences_prediction_model(size_t problem_size, const std::string& file_output);
void run_dynamic_model(const std::string& file_output);

#endif //MNUTRITION_STATIC_MODEL_H

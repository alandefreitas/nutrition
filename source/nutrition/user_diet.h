
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "user_targets.h"

#ifndef ComEvoGlauber_opn_H
#define ComEvoGlauber_opn_H

class user_diet {
  public:

    double _crossover_probability = 0.7;
    double _mutation_strength = 0.3;

    /// generates a random initial solution (individual)
    explicit user_diet(nutrition_problem &p);

    /// prints solution
    std::vector<int> disp(nutrition_problem &p, std::ofstream &fout);
    //std::vector<int> porcao(user_targets &p,const std::vector<int>& _solucaoPorcao,std::ofstream &fout);

    /// evaluates the solution
    double evaluate(nutrition_problem &p);
    double deviation_calc(double total_calories,double current_meta);
    double penalty_calculation(double aux,double limit,double proportionality,double penalizing_factor);
    void preferences_inclusion_limit(nutrition_problem &p);

    /// applies a mutation to the individual according to the mutation strenght
    void mutation(double mutation_strength);

    /// combines two individuals to generate a third
    user_diet crossover(nutrition_problem &p, user_diet &rhs);

    /// improve GA search capability by hamming
    double distance(nutrition_problem &p, user_diet &rhs,
                    double max_dist = std::numeric_limits<double>::max());
    double fx{};
    double fitness{};

    ///getters and setters
    void setPortion(int id, int quantity);
    int getPortion(int id);

  private:
    std::vector<int> _portions;
    static std::mt19937 _generator;
};

#endif // ComEvoGlauber_opn_H
# Modern Nutrition

> Dynamic Preference-Based Diet Optimization 

<p align="center">
  <img src="https://github.com/alandefreitas/nutrition/raw/master/documentation/images/model-fluxogram.png" height="350" width="auto" />
</p>

<br/>

- Since the classic diet planning problem, several mathematical models and programming techniques have been shown to generate menus following several constraints. 
- However, an approach focused on nutritional counseling proves to be more effective than common restrictive diets, by adapting to the habits and preferences of users. 
- In this project we propose a new dynamic optimization optimization_model considering preferences predictions.

<br/>

[![Build Status](https://img.shields.io/github/workflow/status/glauberss2007/modern-nutrition/modern-nutrition?event=push&label=Build&logo=Github-Actions)](https://github.com/glauberss2007/modern-nutrition/actions?query=workflow%3Amodern-nutrition+event%3Apush)

## Quick Start

> Work in Progress...

## TODO list

- Unit tests for nutrition facts
- Unit tests for nutrition database
- User preferences class and unit tests
- User preference database and unit tests
- User targets and unit tests
- User diet and unit tests
- User EA and unit tests
- Benchmarks

## Model

### Adjusting the optimization_model to your needs

- Change the enum Model (.../test/benchmark/main.cpp) replacing by one of current available.

### Static Caloric Deviation

- nutritional facts based on TACO (http://www.nepa.unicamp.br/taco/contar/taco_4_edicao_ampliada_e_revisada.pdf?arquivo=taco_4_versao_ampliada_e_revisada.pdf)
- objective function: minimize caloric difference against target:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/caloric-deviation.png" height="60" width="auto" />
</p>

- nutritional deviation values:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/nutritional-table.png" height="160" width="auto" />
</p>

- nutrition facts separated by categories with different portion size:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/taco-food-categories.png" height="200" width="auto" />
</p>

- penalties applied according to nutritional deviations intensity:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/penalties-static-optimization_model.png" height="90" width="auto" />
</p>

- result: a list of foods to be eat freely during the day.

### Static Mealtime Caloric Deviation

- separate dayle recommendation menu into 6 different mealtimes:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/mealstime-division.png" height="150" width="auto" />
</p>

- penalties formulation applied according to nutritional deviations proportionally to mealtime (the penalties are applied according to mealstime caloric target percentage of total):

<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/mealstime-penalties.png" height="100" width="auto" />
</p>

- result: a list of food considering mealtimes proportional (caloric and nutrients).

### Dynamic Only Caloric Deviation

- user interactions after each mealtime inputting.caloric deviation consume
     difference of user consume input and mealtime menu recommended calculation:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/caloric-diference-calculation.png" height="60" width="auto" />
</p>

- compensatory system to equilibrate/recalculate further mealtimes considering current user consume:
<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/compensatory-calculation.png" height="60" width="auto" />
</p>

- result: dynamic menu that changes/recalculate according to user input on each mealtime

### Dynamic Preferences Prediction Caloric Deviation

- prediction instance (consume history database) based on mealtime category preferences instance generation rule:

<p align="center">
  <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/prediction-instance.png" height="110" width="auto" />
</p>

PS: The category preference was used due a limitation provided due no real consume database availability actually. It is necessary to create a real food consume per mealtime database in ten future...
    
- item-item score matrix created using collaborative filtering

    magnitude calculation:
    <p align="center">
    <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/prediction-magnitude.png" height="60" width="auto" />
    </p>
    
    item importance:
    <p align="center">
    <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/food-importance.png" height="60" width="auto" />
    </p>
    
    cosine similarity calculation:
    <p align="center">
    <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/prediction-similarity-cosseno-calculation.png" height="90" width="auto" />
    </p>
    
    final vector score of items in a specific mealtimes for an user:
    <p align="center">
    <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/food-score-based-on-item-mealstime-user.png" height="80" width="auto" />
    </p>

- first-fit algorithm to include high scored items limited on 50% of mealtimes caloric target.

### Dynamic preferences prediction cost minimization

- populate TACO DB with prices based on ENAPE.
- (on going) change the objective function to maximizing and evaluation function to cost minimization + nutritional deviation:

<p align="center">
    <img src="https://github.com/glauberss2007/modern-nutrition/blob/master/.github/workflows/images/cost-fitness-function.png" height="60" width="auto" />
    </p>

- caloric value as a nutrient range like others using 1600-2400 for women and 2000-3000 for men.

## Solver algorithm 

### Genetic

- initial random population
- pattern select scale/strategy: windows/tournament
- child select scale/strategy: windows/tournament
- mutation type: flip resetting
- mutation_strength: 0.4
- crossover_probability: 0.6

## Coming soon

- expand the capacity of the caloric compensation mechanism by adding physical exercises for cases in which there is an excess caloric intake where it is not possible to compensate.
- easy database change using cereal lib for txt/csv nutrition facts serialize or sql DB connection for MYSQL relational db query
- dynamic minimization cost considering
- different solvers

## References

- Dissertation available on http:// 

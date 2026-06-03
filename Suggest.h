// Created by Juliana Suarez

#ifndef SUGGEST_H
#define SUGGEST_H

#include <string>

//name and the score calculated by the heuristic
struct Suggest {
    std::string name;
    int score;
};

//compare heap with higher priority option = higher score
struct SuggestComparator {
    bool operator()(const Suggest& a, const Suggest& b) const {
        return a.score > b.score;
    }
};

#endif //SUGGEST_H

// connects the names list, the heuristic, and the heap
// Coordinates the heap and heuristic.
// Receives a query and returns the top ten suggestions.
// This is your "brain" class.
// Created by Juliana Suarez

#ifndef SUGGESTENGINE_H
#define SUGGESTENGINE_H

#include <string>
#include <vector>
#include "NameHeuristic.h"

class SuggestEngine {
private:
    //store names from txt
    std::vector<std::string> names;
    //score names based in the matches
    NameHeuristic heuristic;

public:
    //receive names from fileloader
    void loadNames(const std::vector<std::string>& loadedNames);
    //return 10 suggestions
    std::vector<std::string> topTen(const std::string& query);
};

#endif //SUGGESTENGINE_H

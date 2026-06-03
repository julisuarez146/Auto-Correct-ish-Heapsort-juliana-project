// Created by Juliana Suarez

#include "NameHeuristic.h"
#include <algorithm>

//convert string to lowercase to avoid errors
std::string NameHeuristic::toLower(const std::string& text) const {
    std::string result = text;

    std::transform(result.begin(), result.end(), result.begin(),[](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

//return the name that best matches
//suggest engine use it to score to rank names
int NameHeuristic::score(const std::string& query, const std::string& options) const {
    if (query.empty())
        return 0;

    //covert lowercase
    std::string q = toLower(query);
    std::string name = toLower(options);

    int points = 0; //numeric priority

    //exact match
    if (name == q)
        points += 1000;
    //prefix match
    if (name.rfind(q, 0) == 0)
        points += 500;
    //partial match
    if (name.find(q) != std::string::npos)
        points += 200;

    int qIndex = 0;
    int consecutive = 0;
    int bestConsecutive = 0;

    //flexible matches, query appear in order within the name
    for (char c : name) {
        if (qIndex < q.size() && c == q[qIndex]) {
            points += 20;
            qIndex++;
            consecutive++; //consecutive matching char
            bestConsecutive = std::max(bestConsecutive, consecutive); //store best sequence
        } else {
            consecutive = 0; //reset
        }
    }

    points += bestConsecutive * 10; //consecutive get points

    //Preferring shorter names when multiple names match equally well
    points -= static_cast<int>(name.size());
    return points;
}

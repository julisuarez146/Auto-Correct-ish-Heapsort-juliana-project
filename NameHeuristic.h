// Scoring function.
// Given a query string and a candidate name, it returns a numeric priority.
// Isolated so it can be tested and swapped independently.
// Created by Juliana Suarez


#ifndef NAMEHEURISTIC_H
#define NAMEHEURISTIC_H

#include <string>

class NameHeuristic {
public:
    //see how well the name options match what the user is looking for.
    int score(const std::string& query, const std::string& options) const;

private:
    //convert to lowercase, avoid errors
    std::string toLower(const std::string& text) const;
};
#endif //NAMEHEURISTIC_H

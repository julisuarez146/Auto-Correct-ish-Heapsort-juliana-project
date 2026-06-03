// Created by Juliana Suarez

#include "SuggestEngine.h"
#include "Heap.h"
#include "Suggest.h"

//store names in engine
void SuggestEngine::loadNames(const std::vector<std::string>& loadedNames) {
    names = loadedNames;
}

//return 10 best match
std::vector<std::string> SuggestEngine::topTen(const std::string& query) {
    std::vector<std::string> results;

    //user didnt inquery, no return
    if (query.empty())
        return results;
    //heap of suggestions, best score in the top
    Heap<Suggest, SuggestComparator> heap;
    // score names using heuristic
    for (const std::string& name : names) {
        int score = heuristic.score(query, name);
        //positive score
        if (score > 0) {
            heap.insert({name, score});
        }
    }

    int count = 0;

    //use 10 best suggestions from heap
    while (!heap.empty() && count < 10) {
        results.push_back(heap.extractTop().name);
        count++;
    }

    return results;
}

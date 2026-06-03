// Created by Juliana Suarez

#include "FileLoader.h"
#include <fstream>

//open file and load names into a vector
std::vector<std::string> FileLoader::loadNames(const std::string& filename) const {
    std::vector<std::string> names; //vector
    std::ifstream file(filename); //open file

    std::string line;

    //read file
    while (std::getline(file, line)) {
        if (!line.empty())
            names.push_back(line);
    }

    return names;
}

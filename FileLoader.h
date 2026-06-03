// Responsible for reading the names file from disk and providing the names to the rest of the system.
// Created by Juliana Suarez

#ifndef FILELOADER_H
#define FILELOADER_H

#include <string>
#include <vector>

// read names from a file
class FileLoader {
public:
    std::vector<std::string> loadNames(const std::string& filename) const;
};

#endif //FILELOADER_H

// Created by Juliana Suarez

#ifndef MALENASUGGESTAPP_H
#define MALENASUGGESTAPP_H

#include <Malena/Engine/App/Application.h>
#include <Malena/Graphics/Text/Text.h>
#include <Malena/Graphics/Text/TextInput.h>

#include "SuggestEngine.h"

//malena interface
class MalenaSuggestApp : public ml::Application {
private:
    ml::Text title; //display title
    ml::TextInput input; //input box
    ml::Text suggestionsText; //display suggestions

    //engine manages the heap and the heuristic logic
    SuggestEngine engine;
    //update suggest list with the user input
    void updateSuggestions(const std::string& query);

public:
    //create malena
    MalenaSuggestApp();
    //set UI and load txt
    void initialization();
};

#endif //MALENASUGGESTAPP_H

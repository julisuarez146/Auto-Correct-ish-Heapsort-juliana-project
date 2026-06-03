// Created by Juliana Suarez

#include "MalenaSuggestApp.h"
#include "FileLoader.h"

// malena app window
MalenaSuggestApp::MalenaSuggestApp()
    : ml::Application(800, 600, 32,"Auto correct-ish project") {
}

//setup application
void MalenaSuggestApp::initialization() {
    FileLoader loader;
    engine.loadNames(loader.loadNames("names.txt"));

    //title text
    title.setString("Name Auto Suggest");
    title.setPosition({80, 50});
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::White);
    //text input
    input.setPosition({80, 120});
    input.setSize({500, 40});
    input.setFillColor(sf::Color::White);
    //text suggestions
    suggestionsText.setPosition({80, 190});
    suggestionsText.setCharacterSize(24);
    suggestionsText.setFillColor(sf::Color::White);

    //update suggestions every time user type
    input.onChange([this](const std::string& text) {
        updateSuggestions(text);
    });

    //UI components
    addComponent(title);
    addComponent(input);
    addComponent(suggestionsText);
}

//get suggestions from engine
void MalenaSuggestApp::updateSuggestions(const std::string& query) {
    std::vector<std::string> suggestions = engine.topTen(query); //top ten

    std::string display; //each suggest on a new line

    for (const std::string& name : suggestions) {
        display += name + "\n";
    }
    //show suggest
    suggestionsText.setString(display);
}

#pragma once

#include "GameState.h"
#include "Button.h"
#include "HighScore.h"
#include "GenreState.h"

class MainMenuState :
    public State
{
private:
    Entity player;

    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    //function
    void initFonts();


public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    //function
 
    void initButtons();
    void updateButtons();
    void renderButtons(sf::RenderTarget* target);
    void endstate();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

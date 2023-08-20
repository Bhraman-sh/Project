#pragma once
#include "State.h"
#include "Button.h"
#include<iostream>
#include<fstream>


class GenreState :
    public  State
{
private:
    sf::Font font;
    std::map<std::string, Button*> buttons;
    sf::Text text1;
    sf::Text text2;
    std::fstream file;
  

    //sf::RectangleShape background;
    
    void initFonts();

protected:
   
public:
    GenreState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GenreState();

    //file


    //functions

    void initButtons();
    void updateButtons();
    void renderButtons(sf::RenderTarget* target);
    void initText();
    void renderText(sf::RenderTarget *target);
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};



#pragma once
#include "State.h"
class HighScore :
    public State
{
private:
    sf::Text text;
    sf::Text text1, text2, text3, text4, text5, text6;
    sf::Font font;
    
    std::fstream file;
    std::string allgenre, tech, history;
    

public:
    HighScore(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~HighScore();

    //feature functoins
    void initText();
    void loadHighscore();
    void renderText(sf::RenderTarget *target);

    //update and renders function
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

};


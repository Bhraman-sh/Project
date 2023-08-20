#pragma once
#include "State.h"
#include<sstream>
class FinishState :
    public State
{
private:
    sf::Text text, text1, text2, text3;
    std::stringstream s;
    std::string content;
    std::fstream file;
    sf::Font font;
public:
    FinishState(sf::RenderWindow *window, std::stack<State*> *states);
    ~FinishState();

    void initText();
    void renderText(sf::RenderTarget *target);
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};


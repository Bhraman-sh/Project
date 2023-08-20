#pragma once
#include "State.h"
#include "Button.h"
#include "Question.h"

class FeedbackState :
    public State
{
private:
    Question q;
    char c_opt, u_opt;
    std::string genre;
    int question_num;

    std::map<std::string, Button*> buttons;
    sf::Font font;

    sf::Text text1, correct_option, feedback, correct;
public:
    FeedbackState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~FeedbackState();

    void initButtons();
    void updateButtons();
    void renderButtons(sf::RenderTarget *target);

    void loadData();

    //text
    void initCorrectOptionText();
    void initInCorrectOptionText();
    void renderText(sf::RenderTarget *target);
    void loadText();

    void update(const float& dt);
    void updateInput(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};


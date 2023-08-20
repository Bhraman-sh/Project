#pragma once
#include "State.h"
#include "Button.h"
#include "Question.h"
#include "FinishState.h"
#include "FeedbackState.h"
#include "ScoreCompare.h"

class GameState :
    public State
{
protected:
    sf::Text text, text1;
    sf::Font font;

    sf::Texture brainTex;
    sf::Sprite brain;

    sf::RectangleShape background;


    std::map<std::string, Button*> buttons;

    //Question related variables
    char opt;
    char uo[10];
    std::string question, opta, optb, optc, optd;
    std::fstream file;
    std::string str;
    Question q;
    int i;
    int j;

    //function

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    //function

    //buttons
    void initButtons();
    void updateButtons();
    void renderButtons(sf::RenderTarget* target);
    void deleteButtons();
    
    //text
    void initText(); 
    void renderText(sf::RenderTarget* target);
    void initGui();
    
    //gui
    void renderGui(sf::RenderTarget* target);
    void endstate();

    //question
    void askQuestion(std::fstream &file, Question &q);
    void setQuestionPos();
    void verifyAnswer(std::fstream& file, Question& q);
    int getQnNumber();
    void setQnNumber();
    void setOption();
    
    //engine
    void updateInput(const float& dt);
    void update(const float &dt);
    void render(sf::RenderTarget *target = NULL);
};


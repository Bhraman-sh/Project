#pragma once
 
#include"MainMenuState.h"

class Game 
{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//initialization function
	void initWindows();
	void initStates();

	
public:
	//Constructors and destructors
	Game();
	virtual  ~Game();

	//Function
	void updatedt();
	void updateSFMLevents();
	void update();
	void render();
	void run();

};


#pragma once

#include"Entity.h"


class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;

	bool quit;

	//Resources
	std::vector<sf::Texture> textures;

	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2i mousePosScreen;
	sf::Vector2f mousePosView;

	//Functions
	 //Each state should be able to use the suported keys to perform different functionality

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	// Functions

	const bool& getQuit() const;

	 void checkForQuit();

	 virtual void updateInput(const float & dt) = 0;
	 virtual void updateMousePosition();
	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;

};


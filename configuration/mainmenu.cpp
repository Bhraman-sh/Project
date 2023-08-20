#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	//if (!this->font.loadFromFile("Fonts/ALGER.ttf"));
	//{
	//	throw("ERROR::COULD NOT LOAD FONTS");
	//}
}

MainMenuState::MainMenuState(sf::RenderWindow* window)
	: State(window)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
	this->gamestate_btn = new Button(100, 100, 150, 50, &this->font, "Start game", sf::Color::Red,
		sf::Color::Blue, sf::Color::White);
}


MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}



void MainMenuState::endstate()
{
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();


	////update inputs of player
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	//{
	//	this->player.move(dt, -0.1f, 0.f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//{
	//	this->player.move(dt, 0.f, -0.1f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//{
	//	this->player.move(dt, 0.f, 0.1f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	//{
	//	this->player.move(dt, 0.1f, 0.f);
	//}
}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);
	this->player.update(dt);
	this->updateMousePosition();

	this->gamestate_btn->update(this->mousePosView);


	//std::cout << this->mousePosWindow.x << " " << mousePosWindow.y << std::endl;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = (this->window);

	target->draw(this->background);

	this->gamestate_btn->render(target);
	
}

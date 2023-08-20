#include "HighScore.h"


HighScore::HighScore(sf::RenderWindow* window, std::stack<State*>* states)
	: State( window , states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->loadHighscore();
	this->initText();
}

HighScore::~HighScore()
{

}

void HighScore::initText()
{
	this->text2.setFont(this->font);
	this->text2.setString("The Allgenre HighScore is:");
	this->text2.setCharacterSize(30);
	this->text2.setFillColor(sf::Color::White);
	this->text2.setPosition(110, 250);

	this->text.setFont(this->font);
	this->text.setString(allgenre);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(600, 250);

	this->text3.setFont(this->font);
	this->text3.setString("The Technology HighScore is:");
	this->text3.setCharacterSize(30);
	this->text3.setFillColor(sf::Color::White);
	this->text3.setPosition(110, 290);

	this->text4.setFont(this->font);
	this->text4.setString(tech);
	this->text4.setCharacterSize(30);
	this->text4.setFillColor(sf::Color::White);
	this->text4.setPosition(600, 290);

	this->text5.setFont(this->font);
	this->text5.setString("The History HighScore is:");
	this->text5.setCharacterSize(30);
	this->text5.setFillColor(sf::Color::White);
	this->text5.setPosition(110, 330);

	this->text6.setFont(this->font);
	this->text6.setString(history);
	this->text6.setCharacterSize(30);
	this->text6.setFillColor(sf::Color::White);
	this->text6.setPosition(600, 330);

	this->text1.setFont(this->font);
	this->text1.setString("Press Escape to exit");
	this->text1.setCharacterSize(15);
	this->text1.setFillColor(sf::Color::White);
	this->text1.setPosition(10, 10);
}

void HighScore::loadHighscore()
{
	file.open("Highscore/allgenrehighscore.txt", std::ios::in);
	if (!file)
	{
		std::cerr << "error!";
	}
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		allgenre = buffer.str();
		file.close();
	}
	file.open("Highscore/techhighscore.txt", std::ios::in);
	if (!file)
	{
		std::cerr << "error!";
	}
	if (file)
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		tech = buffer.str();
		file.close();
	}
	file.open("Highscore/historyhighscore.txt", std::ios::in);
	if (!file)
	{
		std::cerr << "error!";
	}
	if (file)
	{

		std::stringstream buffer;
		buffer << file.rdbuf();
		history = buffer.str();
		file.close();
	}


}

void HighScore::renderText(sf::RenderTarget * target)
{
	this->window->draw(this->text);
	this->window->draw(this->text1);
	this->window->draw(this->text2);
	this->window->draw(this->text3);
	this->window->draw(this->text4);
	this->window->draw(this->text5);
	this->window->draw(this->text6);
}

void HighScore::endState()
{
}

void HighScore::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->states->pop();
	}
}

void HighScore::update(const float& dt)
{
	this->updateInput(dt);
}

void HighScore::render(sf::RenderTarget* target)
{
	this->renderText(target);
}

#include "FinishState.h"

FinishState::FinishState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	this->font.loadFromFile("Fonts/ALGER.ttf");
	this->initText();
}

FinishState::~FinishState()
{
}

void FinishState::initText()
{
	this->text.setFont(this->font);
	this->text.setString("Quiz completed");
	this->text.setCharacterSize(30);
	this->text.setPosition(200, 300);
	this->text.setFillColor(sf::Color::White);

	file.open("ProgramFile/Score.dat", std::ios::in);
	if (file)
	{
		s << file.rdbuf();
		content = s.str();
	}
	this->text1.setFont(this->font);
	this->text1.setString("Your Score is");
	this->text1.setCharacterSize(30);
	this->text1.setPosition(200, 330);
	this->text1.setFillColor(sf::Color::White);

	this->text2.setFont(this->font);
	this->text2.setString(content);
	this->text2.setCharacterSize(30);
	this->text2.setPosition(420, 330);
	this->text2.setFillColor(sf::Color::White);

	this->text3.setFont(this->font);
	this->text3.setString("  / 10");
	this->text3.setCharacterSize(30);
	this->text3.setPosition(430, 330);
	this->text3.setFillColor(sf::Color::White);

}

void FinishState::renderText(sf::RenderTarget *target)
{
	target->draw(this->text);
	target->draw(this->text1);
	target->draw(this->text2);
	target->draw(this->text3);
}

void FinishState::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->states->pop();
	}
}

void FinishState::update(const float& dt)
{
	this->updateInput(dt);
}

void FinishState::render(sf::RenderTarget* target)
{
	if (!target)
		target = (this->window);

	this->renderText(target);
}

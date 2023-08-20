#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font,
	std::string text, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor)
{
	this->buttonState = BTN_IDLE;
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	
	this->font = font; 
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(15);

	sf::FloatRect textr = this->text.getLocalBounds();
	//std::cout << " \n " << textr.width << " " << textr.height << std::endl;
	this->text.setOrigin(textr.width / 2, textr.height * 0.75);
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width/2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height/2.f
	);

	this->hoverColor = hoverColor;
	this->idleColor = idleColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);


}

Button::~Button()
{

}

//accessor

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_PRESSED)
		return true;
	else
		return false;	
}

//functions

void Button::update(const sf::Vector2f mousePos)
{
	this->buttonState = BTN_IDLE;		//intially the button is always idle

	/* Update the booleans for hover and pressed */

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;
		if ( sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
				this->buttonState = BTN_PRESSED;
		}
	}

	switch (buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(hoverColor);
		break;

	case BTN_PRESSED:
		this->shape.setFillColor(activeColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}



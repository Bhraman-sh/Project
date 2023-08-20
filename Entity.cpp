#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->movementSpeed = 1000.f;
}

Entity::~Entity()
{
}

void Entity::move(const float &dt, const float x, const float y)
{
	this->shape.move(x * movementSpeed * dt, y * movementSpeed * dt);
}

void Entity::update(const float& dt)
{
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

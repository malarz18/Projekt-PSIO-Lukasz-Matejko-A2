#include "ball.h"
#include "rectangle.h"
#include <iostream>


using namespace sf;
using namespace std;

ball::ball(float t_x, float t_y)
{
	shape.setPosition(t_x, t_y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(Color::Red);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

void ball::update()
{
	shape.move(this->velocity);
	if (this->left() < 0) {
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800) {
		velocity.x = -ballVelocity;
	}

	if (this->top() < 0) {
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600) {
		velocity.y = -ballVelocity;
	}
	
	

	
}

float ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this-> shape, state);
}



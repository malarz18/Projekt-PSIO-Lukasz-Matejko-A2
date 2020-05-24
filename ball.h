#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ball : public sf::Drawable
{
public:
	ball(float t_x, float t_y);
	ball()=delete;
	~ball()=default;
	CircleShape shape;
	float ballRadius{ 10.0f };
	float ballVelocity{ 1.0f };
	Vector2f velocity{ ballVelocity, ballVelocity };
	

	float left();
	float right();
	float top();
	float bottom();

	void update();
private:
	
	
	void draw(RenderTarget& target, RenderStates state) const override;//nadpisanie metody draw z klasy Drawable
};


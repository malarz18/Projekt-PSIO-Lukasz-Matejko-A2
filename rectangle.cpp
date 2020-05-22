#include "rectangle.h"
using namespace sf;
rectangle::rectangle(float r_x, float r_y)
{
	prostokat.setSize(Vector2f(100, 50));
	prostokat.setPosition(r_x, r_y);
	prostokat.setFillColor(Color::Red);
}

void rectangle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->prostokat, state);
}

void rectangle::poruszanie()
{
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->prostokat.move(10, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->prostokat.move(-10, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->prostokat.move(0, -10);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->prostokat.move(0, 10);
	}

}

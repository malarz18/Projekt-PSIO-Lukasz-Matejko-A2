#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class rectangle : public RectangleShape
{
	public:
	rectangle(float r_x, float r_y);
	rectangle() = delete;
	~rectangle() = default;
	void poruszanie();
	RectangleShape prostokat;

private:
	
	void draw(RenderTarget& target, RenderStates state) const override;//nadpisanie metody draw z klasy Drawable
	
};


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "rectangle.h"
#include <iostream>

using namespace sf;
using namespace std;

void kolizja(const CircleShape shape,const RectangleShape prostokat, Vector2f velocity)
{
	Vector2f pozycja_kulki = shape.getPosition();
	cout << pozycja_kulki.x << endl;
	cout << pozycja_kulki.y << endl;
	cout << velocity.x << endl;
	Vector2f pozycja_prostokata= prostokat.getPosition();
	cout << pozycja_prostokata.x << endl;
	cout << pozycja_prostokata.y << endl;
	if (pozycja_kulki.x == prostokat.getLocalBounds().top)
	{
		velocity.x = -abs(velocity.x);
		velocity.y = -abs(velocity.y);
	}
	

}

int main() {
	ball ball(400, 300);
	rectangle rectangle(400, 500);
	RenderWindow window{ VideoMode{800,600}, "Projekt PSIO" };
	window.setFramerateLimit(60);
	Event event;
	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		ball.update(rectangle.prostokat);
		rectangle.rectangle::poruszanie();
		window.draw(rectangle);
		window.draw(ball);
		window.display();
		//kolizja(ball.shape,rectangle.prostokat, ball.velocity);
		
		
		
	}
	return 0;
}
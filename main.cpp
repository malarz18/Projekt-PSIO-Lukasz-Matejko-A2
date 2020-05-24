#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "rectangle.h"
#include <iostream>

using namespace sf;
using namespace std;





class bounds_kula
{
	
public:
	float left_bound = 0;
	float right_bound = 0;
	float top_bound = 0;
	float bottom_bound = 0;
	bounds_kula(ball ball)
	{
		left_bound= ball.shape.getPosition().x - ball.shape.getRadius();
			right_bound= ball.shape.getPosition().x + ball.shape.getRadius();
			top_bound= ball.shape.getPosition().y - ball.shape.getRadius();
			bottom_bound= ball.shape.getPosition().y + ball.shape.getRadius();
	};
	~bounds_kula()=default;
};


class bounds_prostokat
{
public:
	float left_bound=0;
	float right_bound=0;
	float top_bound=0;
	float bottom_bound=0;
	bounds_prostokat(rectangle prostokat)
	{
		/*left_bound = prostokat.prostokat.getGlobalBounds().top;
		right_bound = prostokat.prostokat.getGlobalBounds().top + prostokat.prostokat.getGlobalBounds().width;
		top_bound = prostokat.prostokat.getGlobalBounds().top;
		bottom_bound = prostokat.prostokat.getGlobalBounds().top + prostokat.prostokat.getGlobalBounds().height;*/
		left_bound = prostokat.prostokat.getPosition().x;
		right_bound = prostokat.prostokat.getPosition().x + 100;
		top_bound = prostokat.prostokat.getPosition().y;
		bottom_bound = prostokat.prostokat.getPosition().y + 50;
	};
	~bounds_prostokat()=default;

};

void kolizje(Vector2f& velocity, const rectangle prostokat, const ball ball)
{

	bounds_kula granice_kuli(ball);//granice kuli
	bounds_prostokat granice_prostokata(prostokat);
	if (granice_kuli.bottom_bound == granice_prostokata.top_bound) {
		if (granice_kuli.left_bound <= granice_prostokata.right_bound && granice_kuli.right_bound >= granice_prostokata.left_bound) {
				velocity.y = -velocity.y;
				cout << "zamiana" << endl;
		}
	}


}

//void kolizja(const CircleShape shape,const RectangleShape prostokat, Vector2f velocity)
//{
//	Vector2f pozycja_kulki = shape.getPosition();
//	cout << pozycja_kulki.x << endl;
//	cout << pozycja_kulki.y << endl;
//	cout << velocity.x << endl;
//	Vector2f pozycja_prostokata= prostokat.getPosition();
//	cout << pozycja_prostokata.x << endl;
//	cout << pozycja_prostokata.y << endl;
//	if (pozycja_kulki.x == prostokat.getLocalBounds().top)
//	{
//		velocity.x = -abs(velocity.x);
//		velocity.y = -abs(velocity.y);
//	}
//	
//
//}

int main() {
	ball ball(400, 300);
	rectangle rectangle(400, 500);
	RenderWindow window{ VideoMode{800,600}, "Projekt PSIO" };
	window.setFramerateLimit(60);
	Event event;
	while (true)
	{
		//EVENTS
		
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		
		//LOGIC
		rectangle.rectangle::poruszanie();
		kolizje(ball.velocity, rectangle, ball);
		ball.shape.move(ball.velocity);
		ball.update();
		
		

		//DRAW
		//clear the window
		window.clear(Color::Black);
		window.draw(rectangle);
		window.draw(ball);
		

		//end the current frame
		window.display();
		
		/*ball.update();*/
		//kolizja(ball.shape,rectangle.prostokat, ball.velocity);
		
		
		
	}
	return 0;
}



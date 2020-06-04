#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "rectangle.h"
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;


std::vector <rectangle> klocki_zbijanie(int wiersze, int kolumny)
{
	std::vector <rectangle> plansza;//na razie jeden wiersz
	int x = 0;
	int y = 0;
	for (int i = 0; i < wiersze; i++)
		x = 0;
	{
		for (int i = 0; i < kolumny; i++) {
			y = 0;
			plansza.emplace_back(rectangle(x,y));
			x += 110;
		}
		y += 60;
	}
	return plansza;
}


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

void kolizje(Vector2f& velocity, rectangle& prostokat, const ball ball)
{

	bounds_kula granice_kuli(ball);//granice kuli
	bounds_prostokat granice_prostokata(prostokat);
	if (granice_kuli.bottom_bound == granice_prostokata.top_bound) {
		if (granice_kuli.left_bound <= granice_prostokata.right_bound && granice_kuli.right_bound >= granice_prostokata.left_bound) {
				velocity.y = -abs(ball.ballVelocity);
				cout << "zamiana" << endl;
		}
	}

	if (granice_kuli.left_bound == granice_prostokata.right_bound || granice_kuli.right_bound == granice_prostokata.left_bound) {
		if (granice_kuli.bottom_bound >= granice_prostokata.top_bound && granice_kuli.top_bound <= granice_prostokata.bottom_bound) {
			velocity.y = -abs(ball.ballVelocity);
			velocity.x = -abs(ball.ballVelocity);
			cout << "zamiana" << endl;
		}
	}

	if (granice_kuli.top_bound == granice_prostokata.bottom_bound) {
		if (granice_kuli.left_bound >= granice_prostokata.left_bound && granice_kuli.right_bound <= granice_prostokata.right_bound) {
			velocity.y = abs(ball.ballVelocity);
			cout << "zbicie" << endl;
			prostokat.prostokat.setSize(Vector2f(0, 0));
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
	rectangle rectangleg(400, 500);
	std::vector <rectangle> klocki = klocki_zbijanie(0, 7);
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
		kolizje(ball.velocity, rectangleg, ball);
		rectangleg.rectangle::poruszanie();
		ball.shape.move(ball.velocity);
		ball.update();
		
		for (int i = 0; i < klocki.size(); i++)
		{
			kolizje(ball.velocity, klocki[i], ball);
		}
		
		

		//DRAW
		//clear the window
		window.clear(Color::Black);
		window.draw(ball);
		window.draw(rectangleg);
		for (int i = 0; i < klocki.size(); i++)
		{
			window.draw(klocki[i]);
		}
		
		

		//end the current frame
		window.display();
		
		/*ball.update();*/
		//kolizja(ball.shape,rectangle.prostokat, ball.velocity);
		
		
		
	}
	return 0;
}



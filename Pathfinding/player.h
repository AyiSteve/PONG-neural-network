#pragma once

#include<SFML/Graphics.hpp>
#include "global.h"
#include "random.h"


class Player
{


	
private:
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	
	int score;
	Velocity Speed;


public:

	Player(float position_x, float position_y);
	sf::RectangleShape return_shape()
	{
		return rectangle;
	};
	void draw_method(sf::RenderWindow& window) { window.draw(rectangle); };
	sf::Vector2f return_position() { return position; };
	void update_up();
	void update_down();
	int return_score() { return score; };
	void score_update() { score++; };
	void set_default(float position_x, float position_y);

	
};
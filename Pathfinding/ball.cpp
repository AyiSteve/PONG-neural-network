
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "global.h"


ball::ball(float position_x,float position_y):Speed(ball_speed, ball_speed), position(position_x, position_y),circle(ball_size)
{
	circle.setOrigin(ball_size/2, ball_size/2);
	circle.setPosition(position.x,position.y);
	circle.setFillColor(sf::Color::Red);


}

void ball::update()
{
	if (time_bounces % 5 == 0)
	{
		Speed.x = ball_speed + 0.5*(time_bounces / 5 + 1);
		time_bounces++;
	}
	position.x += Speed.x;
	position.y += Speed.y;

	circle.setPosition(position.x, position.y);
}

void ball::rebound_player()
{
	Speed.x *= -1;
}

void ball::rebound_boarder()
{
	Speed.y *= -1;
}
#pragma once

#include <SFML/Graphics.hpp>
#include "global.h"
#include "player.h"

class ball
{
private:

	sf::CircleShape circle;
	sf::Vector2f position;
	int time_bounces;
	Velocity Speed;
	int restart_time;

public:
	ball(float position_x, float position_y);
	sf::CircleShape return_circle()
	{
		return circle;
	}
	sf::Vector2f return_position()
	{
		return position;
	}
	Velocity return_Speed()
	{
		return Speed;
	}
	int return_bounce() { return time_bounces; };
	void update_bounce() { time_bounces++; };

	void update();
	void rebound_player();
	void rebound_boarder();
	void reset_default() { position.x = map_width / 2; position.y = map_length / 2; Speed.x = ball_speed; Speed.y = ball_speed; update_time(); };

	void update_time() { restart_time++; };
	int return_generation() { return restart_time; };
};
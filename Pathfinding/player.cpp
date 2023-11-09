#include "player.h"
#include "global.h"
#include <iostream>


Player::Player(float position_x, float position_y) : rectangle(sf::Vector2f(Board_width, Board_length)), Speed(gamer_speed, gamer_speed), position(position_x, position_y), score(0)
{
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(position.x, position.y);
	rectangle.setOrigin(rectangle.getSize().x / 2.0f, rectangle.getSize().y / 2.0f);




}


void Player::update_up()
{
	position.y -= Speed.y;
	rectangle.setPosition(position.x, position.y);

}
void Player::update_down()
{
	position.y += Speed.y;
	rectangle.setPosition(position.x, position.y);

}

void Player::set_default(float position_x, float position_y)
{
	position.y = position_y;
	position.x = position_x;

	score = 0;
}





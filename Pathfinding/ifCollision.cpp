#include "ifCollision.h"
#include <iostream>
void collision(Player& player1, Player& player2, ball& ball1)
{
	bool iscollision{ false };

	if (ball1.return_position().y + ball1.return_Speed().y <= 0 + ball_size/2  || ball1.return_position().y + ball1.return_Speed().y >= map_length-25)
	{
		ball1.rebound_boarder();
		iscollision = true;
	}

	else if (ball1.return_position().x + ball1.return_Speed().x  <= player1.return_position().x + (Board_width / 2) + (ball_size / 2) && ball1.return_position().x + ball1.return_Speed().x >= player1.return_position().x - (Board_width / 2) - (ball_size / 2))
	{
		if (ball1.return_position().y + ball1.return_Speed().y < player1.return_position().y + (Board_length / 2) && ball1.return_position().y + ball1.return_Speed().y > player1.return_position().y - (Board_length / 2))
		{   
			player1.score_update();
			ball1.update_bounce();
			ball1.rebound_player();
			iscollision = true;
		}
	}

	else if (ball1.return_position().x + ball1.return_Speed().x  >= player2.return_position().x - (Board_width / 2) - (25) && ball1.return_position().x + ball1.return_Speed().x <= player2.return_position().x + (Board_width / 2) + (25))
	{

		if (ball1.return_position().y + ball1.return_Speed().y < player2.return_position().y + (Board_length / 2) && ball1.return_position().y + ball1.return_Speed().y > player2.return_position().y - (Board_length / 2))
		{
			player2.score_update();

			ball1.update_bounce();

			ball1.rebound_player();
			iscollision = true;
		}
	}

}
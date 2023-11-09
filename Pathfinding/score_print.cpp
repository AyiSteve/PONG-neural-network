#include "score_print.h"

void score_printing(int player1_score, int player2_score, sf::RenderWindow& window, sf::Vector2f player1_position, sf::Vector2f player2_position)
{
	sf::Texture texture;
	sf::Sprite text;
	sf::IntRect textureRect;
	text.setOrigin(0, 5 * ratio_text);

	texture.loadFromFile("score.png");
	text.setTexture(texture);


	score_letters(window, player1_position, textureRect, text,0);
	score_number(window, (player1_score%100)/10, textureRect, text, player1_position, text_width * ratio_text);
	score_number(window, player1_score%10, textureRect, text, player1_position, text_width * ratio_text + number_width*ratio_text+2);


	score_letters(window, player2_position, textureRect, text, ( - text_width * ratio_text) - (number_width * ratio_text*2));
	score_number(window, (player2_score % 100) / 10, textureRect, text, player2_position, (-number_width * ratio_text*2));
	score_number(window, player2_score % 10, textureRect, text, player2_position, (-number_width * ratio_text * 2) + number_width * ratio_text + 2);

}

void score_number(sf::RenderWindow& window, int player_score, sf::IntRect textureRect, sf::Sprite text, sf::Vector2f player_position, int adjustment)
{
	//print score
	textureRect.top = text_height * ratio_text * 1;
	textureRect.left = 50 / 10 * ratio_text * player_score;
	textureRect.width = ratio_text * number_width;
	textureRect.height = text_height * ratio_text;
	text.setTextureRect(textureRect);

	text.setPosition(player_position.x + adjustment, map_length);

	window.draw(text);
}

void score_letters(sf::RenderWindow& window, sf::Vector2f player_position, sf::IntRect textureRect, sf::Sprite text, int adjustment)
{
	textureRect.left = 0; 
	textureRect.top = 0; 
	textureRect.width = text_width * ratio_text; 
	textureRect.height = 5 * ratio_text; 

	text.setTextureRect(textureRect);
	text.setPosition(player_position.x + adjustment, map_length);
	window.draw(text);
}
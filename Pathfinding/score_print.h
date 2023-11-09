#pragma once
#include<SFML/Graphics.hpp>
#include"global.h"
#include "player.h"

void score_printing(int player1_score, int player2_score, sf::RenderWindow& window, sf::Vector2f player1_position, sf::Vector2f player2_position);

void score_number(sf::RenderWindow& window, int player_score, sf::IntRect textureRect, sf::Sprite text, sf::Vector2f player_position, int adjustment);


void score_letters(sf::RenderWindow& window, sf::Vector2f player_position, sf::IntRect textureRect, sf::Sprite text, int adjustment);

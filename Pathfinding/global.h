#pragma once


constexpr float Board_length = 100;
constexpr float Board_width = 14;
constexpr float ball_size = 16;
constexpr float gamer_speed = 10;
constexpr float ball_speed = 8;


constexpr float text_width = 27;
constexpr float number_width = 4;

constexpr float text_height = 6;
constexpr float ratio_text = 6;

//map weight
constexpr unsigned int map_length = 700;
constexpr unsigned int map_width = 1000;


struct Velocity
{
	float x;
	float y;

	Velocity(float initialX, float initialY):x(initialX),y(initialY){}
};

struct Weight
{
	float b_x;
	float b_y;
	float p_y;
	float v_x;
	float v_y;

	Weight(float initialX, float initialY, float initialp_y, float initialv_x, float initialv_y) :b_x(initialX), b_y(initialY), p_y(initialp_y), v_x(initialv_x),v_y(initialv_y){}

};

struct Weight_d
{
	float x;
	float y;
	float z;

	Weight_d(float initialX, float initialY, float initialZ) :x(initialX), y(initialY),z(initialZ) {}


};

struct Input
{
	float b_x;
	float b_y;
	float p_y;
	float v_x;
	float v_y;

	Input(float initialX, float initialY, float initialp_y, float initialv_x, float initialv_y) :b_x(initialX), b_y(initialY), p_y(initialp_y), v_x(initialv_x), v_y(initialv_y) {}

};
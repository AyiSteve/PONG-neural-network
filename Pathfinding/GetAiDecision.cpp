#include "GetAiDecision.h"
#include <math.h>
int GetDecision(std::vector <Weight> ai, Input input, Weight_d hidden_weight)
{

	std::cout << "Cell 1" << std::endl;
	std::cout << input.b_x << "," << input.b_y << "," << input.p_y << "," << input.v_x << "," << input.v_x << std::endl;

	std::cout << "Weight 1" << std::endl;
	std::cout << ai[0].b_x << "," << ai[0].b_y << "," << ai[0].p_y << "," << ai[0].v_x << "," << ai[0].v_x << std::endl;

	std::cout << "Weight 2" << std::endl;
	std::cout << ai[1].b_x << "," << ai[1].b_y << "," << ai[1].p_y << "," << ai[1].v_x << "," << ai[1].v_x << std::endl;

	std::cout << "Weight 3" << std::endl;
	std::cout << ai[2].b_x << "," << ai[2].b_y << "," << ai[2].p_y << "," << ai[2].v_x << "," << ai[2].v_x << std::endl;

	float h_cell1 = (ai[0].b_x*input.b_x)+ (ai[0].b_y * input.b_y) + (ai[0].p_y * input.p_y) + (ai[0].v_x * input.v_x) + (ai[0].v_y * input.v_y) ;
	float h_cell2 = (ai[1].b_x * input.b_x) + (ai[1].b_y * input.b_y) + (ai[1].p_y * input.p_y) + (ai[1].v_x * input.v_x) + (ai[1].v_y * input.v_y);
	float h_cell3 = (ai[2].b_x * input.b_x) + (ai[2].b_y * input.b_y) + (ai[2].p_y * input.p_y) + (ai[2].v_x * input.v_x) + (ai[2].v_y * input.v_y);

	std::cout << "Hidden Cell 1: " << h_cell1 <<std::endl;
	std::cout << "Hidden Cell 2: " << h_cell2 << std::endl;
	std::cout << "Hidden Cell 3: " << h_cell3 << std::endl;

	float o_cell4 = (hidden_weight.x * h_cell1) + (hidden_weight.y * h_cell2) + (hidden_weight.z * h_cell3);
	//activation function

	int output = 1 / (1 + std::exp(o_cell4));

	std::cout << "Out: " << output << std::endl;

	return output;
}


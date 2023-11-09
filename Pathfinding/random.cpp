#include "random.h"

float Random()
{ // Create a random number generator engine
    std::random_device rd;
    std::mt19937 mt(rd());

    // Define a distribution for random numbers (e.g., integers between 1 and 100)
    std::uniform_int_distribution<int> dist(-1, 1);

    // Generate random numbers
    int random_number = dist(mt);

    return random_number;
}

int Random_five()
{
    std::random_device rd;
    std::mt19937 mt(rd());

    // Define a distribution for random numbers (e.g., integers between 1 and 100)
    std::uniform_int_distribution<int> dist(0, 4);

    // Generate random numbers
    int random_number = dist(mt);

    return random_number;
}

int Ramdom_three()
{
    std::random_device rd;
    std::mt19937 mt(rd());

    // Define a distribution for random numbers (e.g., integers between 1 and 100)
    std::uniform_int_distribution<int> dist(0, 2);

    // Generate random numbers
    int random_number = dist(mt);

    return random_number;
}
//complete the aiinput 

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>

#include <iostream>
#include "global.h"
#include "player.h"
#include "ball.h"
#include "ifCollision.h"
#include "score_print.h"
#include "random.h"
#include "GetAiDecision.h"


bool isalive(ball& ball1, Player& player1, Player& player2, int& check_new)
{
    if (ball1.return_position().x <= 0)
    {
        ball1.reset_default();

        player2.set_default(map_width - Board_width / 2, map_length / 2);
        player1.set_default(Board_width / 2, map_length / 2);

    }

    else if (ball1.return_position().x >= map_width)
    {
        ball1.reset_default();


       check_new = player2.return_score();


        player2.set_default(map_width - Board_width / 2, map_length / 2);
        player1.set_default(Board_width / 2, map_length / 2);
        return false;
    }

    return true;

}
void update(Player &Player1, Player &Player2, int output)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Player1.update_down();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Player1.update_up();

    }

    if (output == 1)
    {
        Player2.update_down();

    }

    if (output == 0)
    {
        Player2.update_up();

    }
}

int main()
{
    float Player_width = Board_width;
    float Player_height = Board_length;
    

    sf::RenderWindow window(sf::VideoMode(map_width, map_length), "SFML works!");
    window.setFramerateLimit(60);


    Player player1 (Board_width/2, map_length / 2);
    Player player2(map_width - Player_width/2, map_length/2);

    ball ball1(map_width / 2, map_length / 2);

    //turn this to false to rerun the nerual network
    bool is_alive{ true };
    
    //initialize

    int output = 0;
    int highest_fittness = 0;
    int check_new{0};

        std::vector <Weight> ai;
        std::vector <Weight> default_ai;

       // for (int x = 0; x < 3; x++)
       // {
       //     Weight aiWeight(Random(), Random(), Random(), Random(), Random());


       //     ai.push_back(aiWeight);
      //  }

      //  Weight_d hiddent_ai(Random(), Random(), Random());

        //input finalize weight for the ai
        Weight aiWeight(0, 1, -1, 1, 1);
        ai.push_back(aiWeight);
        Weight aWeight(0, -1, 1, 0, 1);
        ai.push_back(aWeight);
        Weight iWeight(0, -1, 0, -1, 1);

        ai.push_back(iWeight);
        Weight_d hiddent_ai(-1, 0, 0);
       default_ai = ai;


    while (window.isOpen())
    {

        
        sf::Event event {};


        while (window.pollEvent(event))
        {

            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();

                    
                break;

            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            std::ofstream fw("D:\\Desktop\\SFML\\Pathfinding\\Pathfinding\\weight_save.txt", std::ofstream::out);

            if (fw.is_open())
            {
                fw << "Check New" << check_new << std::endl;

                fw << "Generation: " << ball1.return_generation() << std::endl;

                for (int i = 0; i < 3; i++)
                {
                    fw << "Weight " << i << " b_x:" << ai[i].b_x <<  " b_y:" << ai[i].b_y << " p_y:" << ai[i].p_y << " v_x:" << ai[i].v_x << " b_y:" << ai[i].v_y << std::endl;
                }

                fw << "Weight for hiddent layer" << " x:" << hiddent_ai.x << " y:" << hiddent_ai.y << " z:" << hiddent_ai.z << std::endl;
                std::cout << "Check New" << check_new << std::endl;

                fw.close();

            }
            else
            {
                std::cout << "Not working";
            }
        }

        window.clear();

        //regenerate a weight after a death had happen
        if (is_alive == false)
        {

            std::cout << "\n \nGeneration: " << ball1.return_generation() << std::endl;

            if (check_new > highest_fittness)
            {
                highest_fittness = check_new;
                default_ai = ai;
            }

            else
            {
                ai = default_ai;
            }

            //if it 0 then restart over
            if (highest_fittness == 0)
            {
                //check if it improves; if child don't input we had parents give birth again


                for (int x = 0; x < 3; x++)
                {
                    ai[x].b_x = Random();

                    ai[x].b_y = Random();

                    ai[x].p_y = Random();

                    ai[x].v_x = Random();

                    ai[x].v_y = Random();

                }

                hiddent_ai.x = Random();
                hiddent_ai.y = Random();
                hiddent_ai.z = Random();
                
            }

            //if it's not zero; we built next generation after
            else 
            {


                
                //three weight for the input
                for (int x = 0; x < 3; x++)
                {
                    for (int i = 0; i < 2; i++)
                    {
                        switch (Random_five())
                        {
                        case 0:
                            ai[x].b_x = Random();

                            break;
                        case 1:
                            ai[x].b_y = Random();

                            break;
                        case 2:
                            ai[x].p_y = Random();

                            break;
                        case 3:
                            ai[x].v_x = Random();

                            break;
                        case 4:
                            ai[x].v_y = Random();

                            break;
                        }
                    }
                }

                //weight for hiddent layer
                switch (Ramdom_three())
                {
                case 0:
                    hiddent_ai.x = Random();
                    break;
                case 1:
                    hiddent_ai.y = Random();
                    break;
                case 2:
                    hiddent_ai.z = Random();
                    break;

                }

            }
        }

        //get input again
        Input aiinput(ball1.return_position().x, ball1.return_position().y, player2.return_position().y, ball1.return_Speed().x, ball1.return_Speed().y);

        //throw to the alogorithm to find output
        output = GetDecision(ai, aiinput, hiddent_ai);

        //all kind of update
        update(player1, player2, output);
        collision(player1, player2, ball1);
        ball1.update();
        is_alive = isalive(ball1, player1, player2, check_new);
        
        //draw them out
        window.draw(ball1.return_circle());
        window.draw(player1.return_shape());
        window.draw(player2.return_shape());

        //draw score out
        score_printing(player1.return_score(), player2.return_score(), window, player1.return_position(), player2.return_position());

        window.display();
    }

    return 0;
}
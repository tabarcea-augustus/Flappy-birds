#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "../headers/Conducte.h"
#include "../headers/bird.h"
using namespace std;

Conducte::Conducte(float x_tzeava)
{
    x =x_tzeava;
}

int Conducte::load_file()
{
    if (!texture_up_pipe.loadFromFile("img/pipe_up.png"))
        return -1;
    pipe_up.setTexture(texture_up_pipe);

    if (!texture_down_pipe.loadFromFile("img/pipe_down.png"))
        return -1;
    pipe_down.setTexture(texture_down_pipe);
    return 1;
}

void Conducte::rand_chimneys()
{
    y_up = (std::rand() % (150+free_space)) - (150+free_space);
    y_down = y_up + pipe_len + free_space;

}
void Conducte::move_chimneys()
{
    x-=speed;
    pipe_up.setPosition(x, y_up);
    pipe_down.setPosition(x, y_down);
}


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "../headers/bird.h"
#include "../headers/Conducte.h"
using namespace std;

int Bird::load_file()
{
    if (!yellow_bird_texture.loadFromFile("img/flappy.png"))
        return -1;

    bird.setTexture(yellow_bird_texture);

    if (!blue_bird_texture.loadFromFile("img/flappy2.png"))
        return -1;

    if (!get_point_buffer.loadFromFile("sounds/get_point.ogg"))
        return -1;

    get_point.setBuffer(get_point_buffer);

    if (!go_up_buffer.loadFromFile("sounds/go_up.ogg"))
        return -1;

    go_up.setBuffer(go_up_buffer);

    if (!die_buffer.loadFromFile("sounds/die.ogg"))
        return -1;

    die.setBuffer(die_buffer);

    return 1;
}

void Bird::move_bird()
{   if(direction>201.9999) bird.setRotation(45);
    else bird.setRotation(0);
    y+=speed;
    bird.setPosition(x, y);
}

string Bird::return_points()
{
    std::stringstream points_ss;
    points_ss << points;
    std::string points_to_view = points_ss.str();
    return points_to_view;
}

bool Bird::check_collision(Conducte pipes)
{

    if ((y < pipes.y_up+pipes.pipe_len && y > pipes.y_up) ||
            (y < pipes.y_down+pipes.pipe_len && y > pipes.y_down) ||
            (y+length < pipes.y_up+pipes.pipe_len && y + length > pipes.y_up) ||
            (y+length < pipes.y_down+pipes.pipe_len && y + length > pipes.y_down))
    {
        if (x + width > pipes.x && x + width < pipes.x + pipes.pipe_width)
            return true;

        if (y <= -40 || y >= 500)
            return true;
    }
    return false;
}

bool Bird::over_chimney(Conducte &pipe)
{
    if (pipe.x <= -200)
    {
        pipe.x = 800;
        points ++;
        pipe.rand_chimneys();

        srand(time(NULL));
        ranus=(rand()%50+1)%7;

        if(ranus==1)
        {
            pipe.speed*=4;
            k1=0;
            k1++;
        }
        if(ranus==2)
        {
            pipe.speed*=0.2;
            k2=0;
            k2++;
        }
        if(ranus==3)
        {
            activ_coliz=0;
            k3=0;
            k3++;
        }
        if(k1>0) k1++;
        if(k2>0) k2++;
        if(k3>0) k3++;
        if(k1==2) {pipe.speed/=4;k1=0;}
        if(k2==2) {pipe.speed/=0.2;k2=0;}
        if(k3==4) {activ_coliz=1;k3=0;}
        return true;
    }

    else
    {
        return false;
    }


}

void Bird::reset_bird()
{
    speed = 3.5;
    y = 300;
    x = 30;
    length = 50;
    width = 50;
    points = 0;
}

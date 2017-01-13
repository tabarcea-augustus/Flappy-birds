#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
using namespace std;
class Bird;
class Conducte: public sf::Transformable
{
public:
    sf::Texture texture_down_pipe;
    sf::Texture texture_up_pipe;
    sf::Sprite pipe_down;
    sf::Sprite pipe_up;
    int free_space = 150;
    float x = 800;
    float y_up = 100;
    float y_down = 100;
    float pipe_len = 375;
    float pipe_width = 150;
    float speed = 4.5;

    Conducte(float x_tzeava);

    int load_file();

    void rand_chimneys();

    void move_chimneys();


};

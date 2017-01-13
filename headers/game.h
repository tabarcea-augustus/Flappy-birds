#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
using namespace std;


class Game:public sf::Transformable
{
private:
    sf::RenderWindow window;
    enum GameState {MENU, GAME, SCORE, OPTIONS, GAME_OVER, END};
    GameState state;
    Results results;
    Bird bird;
    sf::Font font;
    sf::Text text;
    sf::Text error;
    sf::Texture background;
    sf::Texture floor;
    sf::Sprite background_sprite;
    sf::Sprite floor_sprite;
    bool sounds;
public:
    Game();

    void runGame();

    void menu();

    void single();

    void score();

    void options();

};

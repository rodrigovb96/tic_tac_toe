#pragma once 


#include <SFML/Graphics.hpp>
#include <chrono> 
#include "computer_ai.cpp"


// for every function or object of SFML
using namespace sf;

class General_Handler
{
    public:
        General_Handler();
        void game_setup();
        void main_loop();
        void input_handler(Event);
        void ai_input_handler(int);
        void clear_graphics();
        void winning_animation(std::vector<int>); // TODO

    private:

        std::array<Sprite,9> sprite_board; // all the marks
        Sprite background;
        Texture bg_texture;
        std::map<char,Texture> textures;

        std::array<Keyboard::Key,9> input_key;	// all the input_keys

        Font font;
        Text init_txt;

        RenderWindow window;
        GameState board;	
        ComputerAI computer;

        char mark_in_board = ' ';

        bool init = true;
        bool ready = false;
        bool game_over = false;
};



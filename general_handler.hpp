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
	void game_loop();
	void input_handler(Event);
	void ai_input_handler(int);
	void clear_graphics();
	void winning_animation(); // TODO

private:

	Sprite sprite_board[9]; // all the marks
	Sprite background;

	Texture bg_texture;

	std::map<char,Texture> textures;

	std::array<Keyboard::Key,9> input_key;	

	Font font;

	Text init_txt;

	RenderWindow window;

	GameState board;	

	ComputerAI computer;

	bool init_flag = false;
};



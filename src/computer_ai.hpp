#pragma once 

#include "gamestate.cpp"
#include <algorithm> 
#include <tuple>
#include <map>



using move = int;
using score = int;

class ComputerAI
{ 
public:
	ComputerAI() = default; 
	int  operator() (GameState);

private:
	std::vector<int> possible_moves(GameState);
	std::pair<move,score> mini_max(GameState,int);

	std::pair<move,score> move_score;
};




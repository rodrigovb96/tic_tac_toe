#pragma once 

#include "gamestate.cpp"
#include <algorithm> 
#include <tuple>
#include <map>



class ComputerAI
{ 
public:
	ComputerAI() = default; 
	int  operator() (GameState);

private:
	std::vector<int,int> score(GameState,int);	
	std::vector<int> possible_moves(GameState);
	std::pair<int,int> mini_max(GameState,int);

	std::pair<int,int> move_score;
};




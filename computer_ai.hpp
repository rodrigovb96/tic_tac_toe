#pragma once 

#include "hash.hpp"
#include <algorithm> 
#include <tuple>
#include <map>



class ComputerAI
{ 
public:
	ComputerAI() = default; 
	
	
	int  operator() (Hash);
	std::vector<int,int> score(Hash,int);	
	std::vector<int> possible_moves(Hash);
	std::pair<int,int> minimax(Hash,int);
private:
	std::pair<int,int> move_score;
};



#include "computer_ai.cpp"

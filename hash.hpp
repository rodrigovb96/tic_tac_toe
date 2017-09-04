#pragma once

#include <string> 
#include <vector>
#include "player.hpp"


class Hash
{
public:
	enum class Game { HAS_WINNER, DRAW, NO_WINNER };

	Hash(); 

	Game verify();// verify the state of the game	

	Player winner();

	bool is_pos_used(unsigned int);	
	char put_in_pos(unsigned int);
	void clear_hash(); 
	void remove_from_pos(unsigned int);
	void set_player_mark(const char);
	char turn(); // return the player's mark in the turn
	void undo_turn();
	bool p2_turn();
	char p2_mark();
	void debugger();			

private:
	int pTurn; // stores the player turn
	int counter; // counts how many plays were made

	std::vector<char> board;
	std::vector<Player> players;	

	Player winner_;	
};

#include "hash.cpp"

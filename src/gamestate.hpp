#pragma once

#include <string> 
#include <vector>
#include "player.cpp"


class GameState 
{
public:
	enum class Game { HAS_WINNER, DRAW, NO_WINNER };

	GameState(); 

	Game verify_state();// verify the state of the game	

	Player winner();

	bool is_pos_used(unsigned int);// verify if a pos is used
	char put_in_pos(unsigned int);
	void clear_hash(); 
	void remove_from_pos(unsigned int);
	void set_player_mark(const char);
	char turn(); // return the player's mark in the turn
	void undo_turn(); 
	bool p2_turn() const; // verify if it is the p2 turn
	char p2_mark() const;
	void debugger(); // temporary function

private:
	int player_turn = 1; // stores the player turn
	int counter = 0; // counts how many plays were made

	std::array<char,9> board;
	std::vector<Player> players;	

	Player winner_;	
};


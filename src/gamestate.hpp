#pragma once

#include <string> 
#include <vector>
#include "player.cpp"


class GameState 
{
public:
	enum class Game { HAS_WINNER, DRAW, NO_WINNER };
	enum class Mode { PVP_GAME, PVC_GAME };

	GameState(); 


	Game verify_state();// verify the state of the game	
	bool game_over();// verify if the game is over

	Player winner() const;
	bool is_pos_used(unsigned int) const;// verify if a pos is used
	char put_in_pos(unsigned int);
	void clear_board(); 
	void remove_from_pos(unsigned int);
	void set_player2_mark(const char);
	char turn(); // return the player's mark in the turn
	void undo_turn(); 
	bool p2_turn() const; // verify if it is the p2 turn
	char p2_mark() const;
	Mode game_mode() const;
	void set_game_mode(Mode _game_mode);

	std::vector<int> winner_pos() const;
	void debugger(); 

private:
	int player_turn = 1; // stores the player turn
	int counter = 0; // counts how many plays were made

	std::array<char,9> board;
	std::array<Player,2> players;	

	Mode _game_mode;

	Player winner_;	
	std::vector<int> winning_pos;
};


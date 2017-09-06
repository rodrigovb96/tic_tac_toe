#include "gamestate.hpp"

GameState::GameState()
{
	board.resize(9,' ');

	players.push_back(Player("P2",' ',true)); // init the second player as a computer ( HARD CODED by Now)
}

// check if the game has a winner or it is a draw
GameState::Game GameState::verify_state()
{
	
	// diagonal checks
	{
		if(board[0] != ' ' &&  board[0] == board[4] && board[4] == board[8])
			return Game::HAS_WINNER;

		if( board[6] != ' ' && board[6] == board[4] && board[4] == board[2])
			return Game::HAS_WINNER;	
	}

	// horizontal checks
	{
		if( board[0] != ' ' && board[0] == board[1] && board[1] == board[2])	
			return Game::HAS_WINNER;		
		
		if( board[3] != ' ' && board[3] == board[4] && board[4] == board[5])	
			return Game::HAS_WINNER;		
		
		if( board[6] != ' ' && board[6] == board[7] && board[7] == board[8])	
			return Game::HAS_WINNER;		
	}

	// vertical checks
	{
		if( board[0] != ' ' && board[0] == board[3] && board[3] == board[6])	
			return Game::HAS_WINNER;		

		if( board[1] != ' ' && board[1] == board[4] && board[4] == board[7])	
			return Game::HAS_WINNER;		

		if( board[2] != ' ' && board[2] == board[5] && board[5] == board[8])	
			return Game::HAS_WINNER;		
	}

	if(counter == 9)
		return Game::DRAW;

	return Game::NO_WINNER;
}

// returns the  winner
Player GameState::winner()
{
	return winner_;
}

// verify if a pos is used
bool GameState::is_pos_used(unsigned int pos)
{
	return board[pos] != ' ';
}

// yer's input the mark in the given pos
// and return the mark
char GameState::put_in_pos(unsigned int pos)
{
	board[pos] = turn();

	// counts( for draw checking)
	counter++;
	
	if(verify_state() == GameState::Game::HAS_WINNER)
	{
		winner_.set_name( players[player_turn - 2].player_name());
		winner_.set_mark( players[player_turn - 2].player_mark());
	}	


	return board[pos];
}

// clear all the values in the table
//  and reset all the flags 
void GameState::clear_hash() 
{
	for(char& val : board)
		val = ' ';	

	counter = 0;
	player_turn = 1;
}

// clear the given pos
void GameState::remove_from_pos(unsigned int pos) 
{ 
	board[pos] = ' '; 
	counter--;
	
}

// set the second player mark given the first player mark
void GameState::set_player_mark(const char mark)
{
	players.insert(players.begin(), Player("P1",mark,false) );
	
	players[1].set_mark( (mark == 'o' ? 'x' : 'o' ) ) ;		
}

// do the turn 
char GameState::turn()
{
	player_turn = (player_turn%2) != 0 ? 1 : 2;		
	return players[(player_turn++)-1].player_mark();	
}

void GameState::undo_turn() { player_turn--; } 

// check if it is the p2 turn
bool GameState::p2_turn() const { return players[player_turn-1].player_mark() == players[1].player_mark(); }

//return the p2 mark
char GameState::p2_mark() const { return players[1].player_mark(); } 

void GameState::debugger()
{
		
	std::cout << std::string(100,'\n');
	std::cout << "++++ DEBUGGER ++++" << '\n';		

	std::cout << "P1: " << players[0].player_mark() << '\n';	
	std::cout << "P2: " << players[1].player_mark() << '\n' << '\n';
	

	std::cout << "---" << '\n';
	
	for(int i = 0; i < 9; i++)
	{
		std::cout << board[i];
		
		if(!((i+1)%3) )
			std::cout << '\n';
	}
	std::cout << "---" << '\n';
	
	std::cout << "State: "; 
	
	
	GameState::Game state = verify_state();
	
	if( state == GameState::Game::HAS_WINNER)
	{ 
		std::cout << "HAS_WINNER" << '\n';
		std::cout << "Winner:\n";
		std::cout <<" -" <<winner_.player_name() << '\n';
		std::cout <<" -"<< winner_.player_mark() << '\n';
	} 
	else if( state == GameState::Game::NO_WINNER)
		std::cout << "NO_WINNER" << '\n'; 
	else
		std::cout << "DRAW" << '\n';
	std::cout << "+++===      ===+++" << '\n';

}

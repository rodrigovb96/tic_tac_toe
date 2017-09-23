#include "gamestate.hpp"

GameState::GameState() : winning_pos{3}
{
	board.fill(' ');


	players.at(1) = Player("P2",' ',true); // init the second player as a computer ( HARD CODED by Now)

	_game_mode = GameState::Mode::PVC_GAME;
}

// check if the game has a winner or it is a draw
GameState::Game GameState::verify_state()
{
	
	// diagonal checks
	{
		if(board[0] != ' ' &&  board[0] == board[4] && board[4] == board[8])
		{
			winning_pos[0] = 0;
			winning_pos[1] = 4;
			winning_pos[2] = 8;
			return Game::HAS_WINNER;
		}

		if( board[6] != ' ' && board[6] == board[4] && board[4] == board[2])
		{
			winning_pos[0] = 6;
			winning_pos[1] = 4;
			winning_pos[2] = 2;

			return Game::HAS_WINNER;	
		}
	}

	// horizontal checks
	{
		if( board[0] != ' ' && board[0] == board[1] && board[1] == board[2])	
		{
			winning_pos[0] = 0;
			winning_pos[1] = 1;
			winning_pos[2] = 2;
			return Game::HAS_WINNER;		
		}
		
		if( board[3] != ' ' && board[3] == board[4] && board[4] == board[5])	
		{
			winning_pos[0] = 3;
			winning_pos[1] = 4;
			winning_pos[2] = 5;
			return Game::HAS_WINNER;		
		}
		
		if( board[6] != ' ' && board[6] == board[7] && board[7] == board[8])	
		{
			winning_pos[0] = 6;
			winning_pos[1] = 7;
			winning_pos[2] = 8;
			return Game::HAS_WINNER;		
		}
	}

	// vertical checks
	{
		if( board[0] != ' ' && board[0] == board[3] && board[3] == board[6])	
		{
			winning_pos[0] = 0;
			winning_pos[1] = 3;
			winning_pos[2] = 6;
			return Game::HAS_WINNER;		
		}

		if( board[1] != ' ' && board[1] == board[4] && board[4] == board[7])	
		{
			winning_pos[0] = 1;
			winning_pos[1] = 4;
			winning_pos[2] = 7;
			return Game::HAS_WINNER;		
		}

		if( board[2] != ' ' && board[2] == board[5] && board[5] == board[8])	
		{
			winning_pos[0] = 2;
			winning_pos[1] = 5;
			winning_pos[2] = 8;
			return Game::HAS_WINNER;		
		}
	}

	if(counter == 9)
		return Game::DRAW;

	return Game::NO_WINNER;
}

bool GameState::game_over() 
{
	GameState::Game game_state = verify_state();
	return game_state == GameState::Game::HAS_WINNER ||  game_state == GameState::Game::DRAW;
}
// returns the  winner
Player GameState::winner() const { return winner_; }

// verify if a pos is used
bool GameState::is_pos_used(unsigned int pos) const{ return board[pos] != ' '; }

// input the mark in the given pos
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
void GameState::clear_board() 
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
void GameState::set_player2_mark(const char mark)
{
	
	players.at(0) =  Player("P1",mark,false );

	players[1].set_mark( (mark == 'o' ? 'x' : 'o' ) ) ;		
	
	// if player 2 is not a computer set it's computer flag to false
	if(_game_mode == Mode::PVP_GAME)
		players[1].set_computer_flag(false);
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

//set the game type to pvp
GameState::Mode GameState::game_mode() const  { return  _game_mode; } 

void GameState::set_game_mode(Mode _game_mode) { this->_game_mode = _game_mode; }

std::vector<int> GameState::winner_pos() const { return winning_pos; }

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

Hash::Hash()
{
	board.resize(9,' ');

	players.push_back(Player("P2",' ',true)); // init the second player as a computer ( HARD CODED by Now)
	
}

// check if the game has a winner or it is a draw
Hash::Game Hash::verify()
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
Player Hash::winner()
{
	return winner_;
}

// verify if a pos is used
bool Hash::is_pos_used(unsigned int pos)
{
	return board[pos] != ' ';
}

// put the mark in the given pos
// and return the mark
char Hash::put_in_pos(unsigned int pos)
{
	board[pos] = turn();

	// counts( for draw checking)
	counter++;
	
	if(verify() == Hash::Game::HAS_WINNER)
	{
		winner_.setName( players[pTurn - 2].pName());
		winner_.setMark( players[pTurn - 2].pMark());
	}	


	return board[pos];
}

// clear all the values in the table
//  and reset all the flags 
void Hash::clear_hash() 
{
	for(char& val : board)
		val = ' ';	

	counter = 0;
	pTurn = 1;
}

// clear the given pos
void Hash::remove_from_pos(unsigned int pos) 
{ 
	board[pos] = ' '; 
	counter--;
	
}

// set the second player mark given the first player mark
void Hash::set_player_mark(const char mark)
{
	players.insert(players.begin(), Player("P1",mark,false) );
	
	players[1].setMark( (mark == 'o' ? 'x' : 'o' ) ) ;		
}

// do the turn 
char Hash::turn()
{
	pTurn = (pTurn%2) != 0 ? 1 : 2;		
	return players[(pTurn++)-1].pMark();	
}

void Hash::undo_turn() { pTurn--; } 

// check if it is the p2 turn
bool Hash::p2_turn() { return players[pTurn-1].pMark() == players[1].pMark(); }

//return the p2 mark
char Hash::p2_mark() { return players[1].pMark(); } 

void Hash::debugger()
{
		
	std::cout << std::string(100,'\n');
	std::cout << "++++ DEBUGGER ++++" << '\n';		

	std::cout << "P1: " << players[0].pMark() << '\n';	
	std::cout << "P2: " << players[1].pMark() << '\n' << '\n';
	

	std::cout << "---" << '\n';
	
	for(int i = 0; i < 9; i++)
	{
		std::cout << board[i];
		
		if(!((i+1)%3) )
			std::cout << '\n';
	}
	std::cout << "---" << '\n';
	
	std::cout << "State: "; 
	
	
	Hash::Game state = verify();
	
	if( state == Hash::Game::HAS_WINNER)
	{ 
		std::cout << "HAS_WINNER" << '\n';
		std::cout << "Winner:\n";
		std::cout <<" -" <<winner_.pName() << '\n';
		std::cout <<" -"<< winner_.pMark() << '\n';
	} 
	else if( state == Hash::Game::NO_WINNER)
		std::cout << "NO_WINNER" << '\n'; 
	else
		std::cout << "DRAW" << '\n';
	std::cout << "+++===      ===+++" << '\n';
	
}

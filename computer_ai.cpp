int ComputerAI::operator() (Hash game)
{	
	move_score  = minimax(game,0);	
	return move_score.first;
} 



// return all the possible moves
std::vector<int> ComputerAI::possible_moves(Hash game)
{ 
	std::vector<int> temp; 
	
	for(int i = 0; i < 9; i++)
		if( !game.is_pos_used(i) )
			temp.push_back(i);	


	return temp;
} 

// evalute the ai play
// minimax algorithm
std::pair<int,int> ComputerAI::minimax(Hash game,int depth)
{
	//base case 
	if(game.verify() == Hash::Game::HAS_WINNER)
	{
		if(game.winner().pMark() == game.p2_mark() ) 
			return std::make_pair(0,10 - depth);
		else
			return std::make_pair(0,depth -10 );	
	
	}
	else if( game.verify() == Hash::Game::DRAW)
		return std::make_pair(0,0); // Same as a null return

	depth++;	
	
	// std::map<move,score>
	std::map<int,int> score_per_move;

	std::vector<int> moves = possible_moves(game);

	// for every possible move
	for(auto move : moves)
	{ 
		game.put_in_pos(move);
		score_per_move[move] =  minimax(game,depth).second;
		game.remove_from_pos(move);
		game.undo_turn();
	}
	
	
	std::map<int,int>::iterator best_move;

	if( game.p2_turn() ) // max
		best_move = std::max_element(score_per_move.begin(),score_per_move.end(), [] (auto a /* c++14 */, auto b) { return a.second < b.second; });
	else // min
		best_move = std::min_element(score_per_move.begin(),score_per_move.end(), [] (auto a /* c++14 */, auto b) { return a.second < b.second; });
	
	return std::make_pair(best_move->first,best_move->second );
	
}

#include "computer_ai.hpp"

int ComputerAI::operator() (GameState game)
{	
    move_score  = mini_max(game,0);	
    return move_score.first;
} 



// return all the possible moves
std::vector<int> ComputerAI::possible_moves(GameState game)
{ 
    std::vector<int> temp; 

    for(int i = 0; i < 9; i++)
        if( !game.is_pos_used(i) )
            temp.emplace_back(i);	


    return temp;
} 


// evalute the ai play
// mini_max algorithm
std::pair<move,score> ComputerAI::mini_max(GameState game,int depth)
{
    //base case 
    if(game.verify_state() == GameState::Game::HAS_WINNER)
    {
        if(game.winner().player_mark() == game.p2_mark() ) 
            return std::make_pair(0,10 - depth);
        else
            return std::make_pair(0,depth -10 );	

    }
    else if( game.verify_state() == GameState::Game::DRAW)
        return std::make_pair(0,0); // Same as a null return

    depth++;	


    std::vector<int> moves{possible_moves(game)};


    std::map<move,score> score_per_move;

    // for every possible move
    for(auto m : moves)
    { 
        game.debugger();
        game.put_in_pos(m);
        score_per_move[m] =  mini_max(game,depth).second;
        game.remove_from_pos(m);
        game.undo_turn();
    }


    std::map<move,score>::iterator best_move;

    if( game.p2_turn() ) // max
        best_move = std::max_element(score_per_move.begin(),score_per_move.end(), [] (auto a /* c++14 */, auto b) { return a.second < b.second; });
    else // min
        best_move = std::min_element(score_per_move.begin(),score_per_move.end(), [] (auto a /* c++14 */, auto b) { return a.second < b.second; });

    return *best_move;
}

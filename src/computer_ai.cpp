#include "computer_ai.hpp"

int ComputerAI::operator() (GameState game)
{	
    auto [ next_move, ai_score ] = min_max(game,0);	

    return next_move;

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


// evalute the AI play
// min_max algorithm
std::tuple<move,score> ComputerAI::min_max(GameState game,int depth)
{
    //base case 
    if(game.verify_state() == GameState::Game::HAS_WINNER)
    {
        if(game.winner().player_mark() == game.p2_mark() ) 
            return {0,10 - depth};
        else
            return {0,depth -10};

    }
    else if( game.verify_state() == GameState::Game::DRAW)
        return {0,0} ;

    depth++;	


    std::vector<int> moves{possible_moves(game)};


    std::map<move,score> score_per_move;

    // for every possible move
    for(auto m : moves)
    { 
        game.put_in_pos(m);
        game.debugger();
        score_per_move[m] =  std::get<1>( min_max(game,depth));
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

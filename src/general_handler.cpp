#include "general_handler.hpp"

General_Handler::General_Handler()
{
    // Window setup 
    window.create(VideoMode(600,600),"Tic-Tac-Toe AI",Style::Close);
    window.setFramerateLimit(30);

    // loading text font	
    if(!font.loadFromFile("files/font.TTF"))
        std::cerr << "ERROR LOADING TEXT FONT!" << '\n';
    else
        init_txt.setFont(font);	


    init_txt.setString("\t\tTIC-TAC-TOE AI!!\nChoose your mark('X'or'O'):");
    init_txt.setCharacterSize(18);

	init_txt.setColor(Color::Red);

#ifdef NEW_VERSION 
    init_txt.setFillColor(Color::Red);
#endif 

    init_txt.setOrigin(-100,-100);
    init_txt.setPosition(50,10);



    // Loading input keys	
    input_key[0] = Keyboard::Q;
    input_key[1] = Keyboard::W;
    input_key[2] = Keyboard::E;
    input_key[3] = Keyboard::A;
    input_key[4] = Keyboard::S;
    input_key[5] = Keyboard::D;
    input_key[6] = Keyboard::Z;
    input_key[7] = Keyboard::X;
    input_key[8] = Keyboard::C;


    // Positions of the sprites(s) in the table 	
    /* 
           s|s|s
           s|s|s
           s|s|s
    */       
    sprite_board[0].setOrigin(10,10);
    sprite_board[0].setPosition(20,10);

    sprite_board[1].setOrigin(-100,10);
    sprite_board[1].setPosition(115,10);

    sprite_board[2].setOrigin(-200,10);
    sprite_board[2].setPosition(215,10);

    sprite_board[3].setOrigin(10,-100);
    sprite_board[3].setPosition(10,110);

    sprite_board[4].setOrigin(-100,-100);
    sprite_board[4].setPosition(115,110);

    sprite_board[5].setOrigin(-200,-100);
    sprite_board[5].setPosition(215,110);

    sprite_board[6].setOrigin(10,-200);
    sprite_board[6].setPosition(10,210);

    sprite_board[7].setOrigin(-100,-200);
    sprite_board[7].setPosition(115,210);

    sprite_board[8].setOrigin(-200,-200);
    sprite_board[8].setPosition(215,210);


}

void General_Handler::game_setup()
{
    if(!bg_texture.loadFromFile("files/images/background.png"))
        std::cerr << "ERROR LOADING BACKGROUND IMAGE!" << '\n';
    else
        background.setTexture(bg_texture);

    // Loading all the necessary textures
    textures['x'].loadFromFile("files/images/x_mark.png");	
    textures['o'].loadFromFile("files/images/o_mark.png");	
    textures[' '].loadFromFile("files/images/clear_img.png");
}

// while the window is open all the process is made
// input and output 
void General_Handler::main_loop()
{
    while(window.isOpen())
    {

        Event evt;
        while(window.pollEvent(evt))
        {

            //close the window if escape key was pressed
            if(evt.type == Event::Closed || (evt.type == Event::KeyPressed && (evt.key.code == Keyboard::Escape)))
                window.close();


            if(init)
            {	
                if(evt.type == Event::KeyPressed)
                {	
                    if(evt.key.code == Keyboard::Num1)	
                        board.set_game_mode(GameState::Mode::PVP_GAME);

                    // choosing the player's mark
                    if(evt.key.code == Keyboard::X)
                    { 
                        init = false;
                        board.set_player_mark('x');
                    }
                    else if(evt.key.code == Keyboard::O)
                    { 
                        init = false;
                        board.set_player_mark('o');
                    }


                }	

            }	
            else
            {
                // if the game is not over(has no winner and it's not a draw) 
                if((!board.game_over() && !board.p2_turn() ) || (!board.game_over() &&  board.game_mode() == GameState::Mode::PVP_GAME )) 
                    input_handler(evt);
                else if( !board.game_over() && board.p2_turn())
                    ai_input_handler(computer(board));
                else if(evt.type == Event::KeyPressed && evt.key.code == Keyboard::Num2)
                {// reset the game
                    board.clear_board();
                    clear_graphics();


                    board.set_game_mode(GameState::Mode::PVC_GAME);
                    init = true;
                    game_over = false;
                }
                else
                    game_over = true;



            }

        }

        window.clear();		

        if(init)
        {
            window.draw(init_txt);
        }
        else 
        {
            if(!ready)
            {
                ready = true;
                game_setup();
            }


            window.draw(background);

            for(auto& sprite : sprite_board)  
                window.draw(sprite); 

        }


        window.display();	

    }
}

// handles all the user inputs
void General_Handler::input_handler(Event input_evt)
{
    if(input_evt.type == Event::KeyPressed)
    {
        for(unsigned int i = 0; i < input_key.size(); i++) 
            if(input_evt.key.code == input_key[i] && !board.is_pos_used(i))
            {
                mark_in_board = board.put_in_pos(i);
                sprite_board[i].setTexture(textures[mark_in_board]);

            }
    }
}

// handle all the AI inputs
void General_Handler::ai_input_handler(int pos)
{
    mark_in_board = ' ';

    mark_in_board =	board.put_in_pos(pos);
    sprite_board[pos].setTexture(textures[mark_in_board]);

}

// clear all the graphics in the sprite_board 
void General_Handler::clear_graphics()
{
    for(int i = 0; i < 9; i++)
        sprite_board[i].setTexture(textures[' ']);
}

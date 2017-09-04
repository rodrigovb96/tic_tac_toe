General_Handler::General_Handler()
{
	window.create(VideoMode(600,600),"Tic-Tac-Toe AI",Style::Close);
	window.setFramerateLimit(30);
	
	// loading text font	
	if(!font.loadFromFile("font.TTF"))
		std::cerr << "ERROR LOADING TEXT FONT!" << '\n';
	else
		init_txt.setFont(font);	

	if(!bg_texture.loadFromFile("images/background.png"))
		std::cerr << "ERROR LOADING BACKGROUND IMAGE!" << '\n';
	else
		background.setTexture(bg_texture);
	
	// Initial Text
	// =====
		init_txt.setString("\t\tTIC-TAC-TOE AI!\nChoose your mark('X'or'O'):");
		init_txt.setCharacterSize(18);
		init_txt.setColor(Color::Red); // SFML < 2.3 (DEPRECATED)
		//init_txt.setFillColor(Color::Red); <- SFML 2.4.2
		init_txt.setOrigin(-100,-100);
		init_txt.setPosition(50,10);
	// =====


	// Loading all the necessary textures
	textures['x'].loadFromFile("images/x_mark.png");	
	textures['o'].loadFromFile("images/o_mark.png");	
	textures[' '].loadFromFile("images/clear_img.png");


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

	// flag for initial options	
	init_flag = false;	

}

// while the window is open all the process is made
// input and output 
// 
void General_Handler::game_loop()
{
	while(window.isOpen())
	{
		
		board.debugger();
		Event evt;
		while(window.pollEvent(evt))
		{

			//close the window if escape key is pressed
			if(evt.type == Event::Closed || (evt.type == Event::KeyPressed && (evt.key.code == Keyboard::Escape)))
				window.close();
				

			if(!init_flag)
			{	
				
				if(evt.type == Event::KeyPressed)
				{ 

					// choosing the player's mark
					if(evt.key.code == Keyboard::X)
					{ 
						init_flag = true;
						board.set_player_mark('x');
					}
					else if(evt.key.code == Keyboard::O)
					{ 
						init_flag = true;
						board.set_player_mark('o');
					}


				}	

			}	
			else
			{
				// if the game is not over(has no winner and its not a draw) 
				if( board.verify() != Hash::Game::HAS_WINNER && board.verify() != Hash::Game::DRAW && !board.p2_turn())
					input_handler(evt);
				else if( board.verify() != Hash::Game::HAS_WINNER && board.verify() != Hash::Game::DRAW)
					ai_input_handler(computer(board));
				else if(evt.type == Event::KeyPressed && evt.key.code == Keyboard::Num2)
				{// reset the game
					board.clear_hash();
					clear_graphics();

				}
					


			}
	
		}
	
		window.clear();		

		if(!init_flag)
		{
			window.draw(init_txt);
		}
		else 
		{

			window.draw(background);

			{
				window.draw(sprite_board[0]);
				window.draw(sprite_board[1]);
				window.draw(sprite_board[2]);
				window.draw(sprite_board[3]);
				window.draw(sprite_board[4]);
				window.draw(sprite_board[5]);
				window.draw(sprite_board[6]);
				window.draw(sprite_board[7]);
				window.draw(sprite_board[8]);
			}

		
		}


		window.display();	
		
	}
}

// handles all the user inputs
void General_Handler::input_handler(Event input_evt)
{
	char mark_in_board = ' ';

	
	if(input_evt.type == Event::KeyPressed)
	{
		if(input_evt.key.code == Keyboard::Q && !board.is_pos_used(0) )
		{
			mark_in_board =	board.put_in_pos(0);
			sprite_board[0].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::W && !board.is_pos_used(1) )
		{
			mark_in_board = board.put_in_pos(1);
			sprite_board[1].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::E && !board.is_pos_used(2) )
		{
			mark_in_board = board.put_in_pos(2);
			sprite_board[2].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::A && !board.is_pos_used(3) )
		{
			mark_in_board = board.put_in_pos(3);
			sprite_board[3].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::S && !board.is_pos_used(4) )
		{
			mark_in_board =	board.put_in_pos(4);
			sprite_board[4].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::D && !board.is_pos_used(5) )
		{
			mark_in_board = board.put_in_pos(5);	
			sprite_board[5].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::Z && !board.is_pos_used(6) )
		{
			mark_in_board = board.put_in_pos(6);
			sprite_board[6].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::X && !board.is_pos_used(7) )
		{
			mark_in_board = board.put_in_pos(7);
			sprite_board[7].setTexture(textures[mark_in_board]);
		}
		else if(input_evt.key.code == Keyboard::C && !board.is_pos_used(8) )
		{
			mark_in_board = board.put_in_pos(8);
			sprite_board[8].setTexture(textures[mark_in_board]);
		}
	}
	

	
		
}

// handle all the AI inputs
void General_Handler::ai_input_handler(int pos)
{
	char mark_in_board = ' ';

	mark_in_board =	board.put_in_pos(pos);
	sprite_board[pos].setTexture(textures[mark_in_board]);

}

// clear all the graphics in the sprite_board 
void General_Handler::clear_graphics()
{
	for(int i = 0; i < 9; i++)
		sprite_board[i].setTexture(textures[' ']);
}


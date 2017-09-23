#pragma once

#include <string> 

class Player
{
public:
	Player(std::string _name,char _mark,bool computer=false) 
	: name{_name}, mark{_mark}, is_computer_flag{computer} {}

	Player();	

	std::string player_name() const;
	char player_mark() const; 
	bool is_computer() const; 	
	void set_computer_flag(bool flag);
	void set_name(const std::string);
	void set_mark(const char);

private:
	std::string name;

	char mark; 

	bool is_computer_flag;
};


#pragma once

#include <string> 

class Player
{
public:
	Player(std::string _name,char _mark,bool isComputer=false) : name{_name}, mark{_mark}, is_computer{isComputer} {}
	Player();	

	std::string pName(); 
	char pMark(); 
	bool isComputer(); 	
	

	void setName(const std::string);
	void setMark(const char);

private:
	std::string name;

	char mark; 

	bool is_computer;
};

#include "player.cpp"

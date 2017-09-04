
Player::Player(){ is_computer = false; }

std::string Player::pName()
{
	return name;
}


char Player::pMark()
{
	return mark;
}

// true if the player is a computer
bool Player::isComputer()
{
	return is_computer;
}


void Player::setName(const std::string str)
{
	name = str;
}

void Player::setMark(const char mark_)
{
	mark = mark_;
}

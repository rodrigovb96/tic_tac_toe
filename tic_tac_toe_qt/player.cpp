#include "player.h"

Player::Player(){ is_computer_flag = false; }

std::string Player::player_name() const { return name; }

char Player::player_mark() const { return mark; }

bool Player::is_computer() const { return is_computer_flag; }

void Player::set_computer_flag(bool flag) { is_computer_flag = flag; } 

void Player::set_name(const std::string str) { name = str; }

void Player::set_mark(const char mark_) { mark = mark_; }

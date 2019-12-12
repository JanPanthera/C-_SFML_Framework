#include "SnakeGameLogic/Game.hpp"

int main() {
	jp::LogToFile::setLogAttention(jp::LogToFile::LogAttention::DEBUG, true);
	jp::Game _Game{};
	return _Game.onRun();
}
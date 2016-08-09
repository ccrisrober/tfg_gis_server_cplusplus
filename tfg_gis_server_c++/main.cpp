#include "Server.h"
#include <iostream>

int main() {
	std::cout << "Select Server Mode (S/s) Game Mode / (_) Test Mode" << std::endl;
	char isGame;
	std::cin >> isGame;
	bool playGame = false;
	if (tolower(isGame) == 's') {
		playGame = true;
	}
	if (playGame) {
		std::cout << "Open in Game Mode";
	}
	else {
		std::cout << "Open in Test Mode";
	}
	std::cout << std::endl;
	Server s(8090, playGame);
	s.run();
	return 0;
}
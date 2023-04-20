#include "GameSelector.h"
#include "path.h"
#include <iostream>
std::filesystem::path exePath;
int main(int argc, char** argv) {
	 //get path to executable
	exePath = std::filesystem::absolute(std::filesystem::path(argv[0]));
	GameSelector gameSelector;
	while (true) {
		gameSelector.start(gameSelector.select());
	}
	
}
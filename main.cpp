#include "GameSelector.h"
#include "path.h"
#include <iostream>
int main(int argc, char** argv) {
	std::filesystem::path exePath = std::filesystem::absolute(std::filesystem::path(argv[0])); //get path to executable
	GameSelector gameSelector;
	while (true) {
		gameSelector.start(gameSelector.select());
	}
	

}
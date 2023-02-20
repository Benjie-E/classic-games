#include "GameSelector.h"
int main() {
	GameSelector gameSelector;
	while (true) {
		gameSelector.start(gameSelector.select());
	}
	

}
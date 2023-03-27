#pragma once
#include <Windows.h>
namespace HangmanNS {
	class ScreenManager
	{
	public:
		ScreenManager();
		~ScreenManager();
		void updateHangedMan(int phase);
		void reset();
		int letterToIndex(char letter);
		void updateLetter(char letter);
		void start(int length);
		void updateWord(int index, char letter);
		void win();
		void lose();
		POINT hangmanPos;
		POINT letterPos;
		POINT wordPos;
	};
}
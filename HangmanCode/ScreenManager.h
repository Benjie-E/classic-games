#pragma once
#include "../common/Location.h"
#include <string>
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
		void win(std::string word);
		void lose(std::string word);
		Location hangmanPos;
		Location letterPos;
		Location wordPos;
	};
}
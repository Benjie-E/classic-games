#pragma once
#include <Windows.h>
class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();
	int currentPhase;
	void updateHangedMan();
	void reset();
	void updateLetter(char letter);
	
	POINT hangmanPos;
	POINT letterPos;
};


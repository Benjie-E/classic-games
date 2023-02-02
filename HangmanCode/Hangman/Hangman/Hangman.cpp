// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//char getInput() {
//    char input;
//    std::cin >> input;
//    return input;
//}
#include <iostream>
#include <stdio.h>
#include <Windows.h>


static char bar[] = "======================================="
"======================================>";
int main() {
    int i;
    for (i = 77; i >= 0; i--) {
        printf("[%s]\r", &bar[i]);
        fflush(stdout);
        Sleep(100);
    }
    printf("\n");
    return 0;
}

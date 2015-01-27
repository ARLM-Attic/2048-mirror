/*
File:Menu.h
Authur:Nauman Mustafa
Description:Provides Menu APIs for Building 2048 Game
*/

//										Includes
#include "2048.h"
//For Standard I/O
#include <stdio.h>
//For console I/O
#include <conio.h>
//C Standard library
#include <cstdlib>

/*Selected menu id
0) Continue
1) New Game
2) Instructions
3) High Scores
4) Exit
*/
int selid = 1;


//Draw menu on screen
void draw_menu()
{
	//Clear Screen
	system("cls");

	//Draw Game copyright info
	printf("(c) All Rights Reserved\n\n");

	//Draw menu

	for (int i = 0; i < 5; i++){

		//If Selected menu is now being drawn then show selection mark
		if (i == selid)
			printf("# %c", 16);

		//otherwise just print space
		else
			printf("#  ");

		//Check menu ID
		switch (i)
		{

		case 0:		//If Not paused then print Continue
			if (is_paused())
				printf("Continue");
			else
				selid = 1;

			break;

		case 1:		//New Game Menu
			printf("New Game");

			break;

		case 2:		//Instructions
			printf("Instructions");

			break;
		case 3:		//High Scores
			printf("High Scores");

			break;
		case 4:		//Exit
			printf("Exit");

			break;

		default:	//Error Menu
			printf("Error Menu");

		}

		//Move to next line
		printf("\n");
	}

	//Draw Game Basic Instructions
	printf("\nHelp:\nPress 'W' to move Cursor up \nPress 'S' to move Cursor down \nPress 'D' to select menu");
}

/*
Update menu and returns selected menu
0) Continue
1) New Game
2) Instructions
3) High Scores
4) Exit
*/
int update_menu(char input)
{
	switch (input)
	{
	case UP1: case UP2:
		if (!(selid == !is_paused()))
			selid--;
		break;
	case DOWN1: case DOWN2:
		if (!(selid == MENUMAX))
			selid++;
		break;
	}
	return selid;
} 

//Draw Instruction
void draw_instructions()
{
	system("cls");
	const char* instr =
		"HOW TO PLAY:\n\
		Use your 'A' 'S' 'D' 'W' to move the tiles.\n\
		When two tiles with the same number\n\
		touch, they merge into one!\n\
		You have to create a tile of 2048 number\n\
		\n\
		Press any key to continue..."
		;
	printf(instr);
	_getch();
}

//Print Highest scores
void draw_scores()
{
	system("cls");
	printf(
		"Highest Scores:%d\n\
		\n\
		Press any key to continue...",
		get_high_scores());
	_getch();
}


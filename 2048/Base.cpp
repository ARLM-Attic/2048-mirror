#include "2048.h"
//										Variables
//Game Table
static int table[SIZE];
//Check if game is paused or not
int haspaused = 0;
//High Scores
int high_scores = 0;
//Score File Name
const char* score_file = "scores.txt";

//										Functions
//Initialize table
void clear_table()
{

	for (int i = 0; i < SIZE; i++){
		table[i] = 0;
	}

}

/*
Gets the number in table at given position
i: Horizontal or x component
j: Vertical or y component
*/
int get(int i, int j)
{
	if (i<1 || i>XMAX || j<1 || j>YMAX)
		return -1;
	return table[(j - 1)*HEIGHT + (i - 1)];
}

/*
set the number in table at given position
i: Horizontal or x component
j: Vertical or y component
value: The value to be set
*/
void set(int i, int j, int value)
{
	if (i<1 || i>XMAX || j<1 || j>YMAX)
		return;
	table[(j - 1)*HEIGHT + (i - 1)] = value;
}

//Retruns if game has been paused or not
int is_paused()
{
	return haspaused;
}

//Load High Scores
void load_scores()
{
	FILE* f;
	f = fopen(score_file, "r");
	if (!(f == NULL))
	{
		fscanf_s(f, "%d", &high_scores);
		fclose(f);
	}
}

//Save High Scores
void save_scores()
{
	FILE* f;
	f = fopen(score_file, "w");
	if (!(f == NULL))
	{
		fprintf(f, "%d", high_scores);
		fclose(f);
	}
}

int get_high_scores()
{
	return high_scores;
}

void set_high_scores(int scores)
{
	high_scores = scores;
}

void game_mode()
{
	char input;

	int result = 0;
	do
	{ 
		system("cls");
		draw_grid();
		printf("\nPressy any key to start game\nPress 'A' 'S' 'W' 'D' to move blocks\nPress escape to pause game");
		if (result != 0)
			printf("\n\nYou have %s the game\nPress any key to continue...\n\n", result == 1 ? "won" : "lost");

		if (result == -1)
			set_current_scores(0);

		printf("\n\nYour Current Scores: %d", get_current_scores());
		printf("\nHigh Scores Scores: %d", get_high_scores());

		input = _getch();
		//Game over / won
		if (result == -1 || result == 1)
			break;
		result = update_grid(input);
	} while (input != '\x1b');

	if (get_current_scores() > get_high_scores())
		set_high_scores(get_current_scores());

	if (result == 0){
		haspaused = true;
	}
	else{
		haspaused = false;
		save_scores();
	}
}


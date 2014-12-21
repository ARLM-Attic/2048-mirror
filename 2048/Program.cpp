#include "2048.h"


void main()
{
	
	//Load scores from high score files
	load_scores(); 

	//Create input variable
	int input = 0;

	//start loop
	do{

		//draw menu
		draw_menu();

		//get input
		input = _getch();

		//update menu
		int sel = update_menu(input);

		//if any menu selected
		if (input == 'd' || input == 'D')

			//check which menu selected
			switch (sel)
		{
			case 0:			//Continue
				game_mode();
				break;

			case 1:			//New Game Menu
				clear_table();
				game_mode();
				break;
			case 2:			//Draw instructions
				draw_instructions();
				break;
			case 3:			//Draw scores
				draw_scores();
				break;
			case 4:			//Exit
				input = '\x1b';
		}
	} while (input != '\x1b');

	//Save scores in files
	save_scores();

}
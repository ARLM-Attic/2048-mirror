
/*
this file contains Functions to be implemented
*/

#include <stdio.h>
#include <time.h>
#include "2048.h"

//the score variable to be set if scores added
int scores = 0;

//already implemented

int get_current_scores()
{ 
	return scores; 
}

void set_current_scores(int s)
{
	scores = s;
}

/*
draw the game grid example:

|-----|-----|-----|-----|
|2    |32   |512  |8192 |
|4    |64   |1024 |.....|
|8    |128  |2048 |.....|
|16   |256  |4096 |     |
|-----|-----|-----|-----|
*/

void draw_grid()
{
	//Implement code here

	printf("|-----|-----|-----|-----|\n");
	for (int j = 1; j <= 4; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			int v = get(i, j);
			if (v == 0)
				printf("|     ");

			if (v >= 2 && v <= 8)
				printf("|%d    ", v);

			if (v >= 16 && v <= 64)
				printf("|%d   ", v);

			if (v >= 128 && v <= 512)
				printf("|%d  ", v);

			if (v >= 1024 && v <= 8192)
				printf("|%d ", v);

		}
		printf("|\n");
	}

	printf("|-----|-----|-----|-----|\n");

}

//This will generate random tile

void generate_random_tile()
{

	srand(time(NULL));
	int v, i, j, t;
	do{
		i = rand() % 4 + 1;
		j = rand() % 4 + 1;
		v = get(i, j);
	} while (v == 0);
	t = (rand() % 2 + 1) * 2;
	set(i, j, t);
} 

//Check if we can move blocks or not 1 for true and 0 for false

int can_move()
{
	//Implement code here

	//delete this line at the end
	return 0;
}

//move blocks in certain direction
//if direction==UP1||direction==UP2 etc	to check for up press
//DOWN1 DOWN2
//LEFT1 LEFT2
//RIGHT1 Right2
//use get(i,j) function to get (i,j)th element from grid 
//set(i,j,value) to set (i,j)th element to value
//where (1,1)<=(i,j)<=(4,4)

void move(char direction)
{
	//Implement code here


}

//Return 0 if done
//Retrun -1 if game over
//Return 1 if game won

int update_grid(char input)
{
	//Implement code here


	//delete this line at the end
	return 0;
}
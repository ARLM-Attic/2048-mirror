
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
	} while (v != 0);
	t = (rand() % 2 + 1) * 2;
	set(i, j, t);
} 



//move blocks in certain direction
//if direction==UP1||direction==UP2 etc	to check for up press
//DOWN1 DOWN2
//LEFT1 LEFT2
//RIGHT1 Right2
//use get(i,j) function to get (i,j)th element from grid 
//set(i,j,value) to set (i,j)th element to value
//where (1,1)<=(i,j)<=(4,4)

//Return 1 if any movement occurs 0 if no movement occured
int move(char direction)
{
	int moved = 0;
	//Implement code here

	switch (direction)
	{
		case UP1:
		case UP2:

			for (int i = 1; i <= 4; i++)
				for (int j = 1; j <= 4; j++)
					while (move_tile(direction, i, j))
					{
						moved++; 
						j--; 
					}

			break;
		case DOWN1:
		case DOWN2:

			for (int i = 1; i <= 4; i++)
				for (int j = 4; j >= 1; j--)
					while (move_tile(direction, i, j))
					{
						moved++;
						j++;
					}

			break;
		case LEFT1:
		case LEFT2:

			for (int j = 1; j <= 4; j++)
				for (int i = 1; i <= 4; i++)
					while (move_tile(direction, i, j))
					{
						moved++;
						i--;
					}

			break;
		case RIGHT1:
		case RIGHT2:

			for (int j = 1; j <= 4; j++)
				for (int i = 4; i >= 1; i--)
					while (move_tile(direction, i, j))
					{
						moved++;
						i++;
					}


			break;
		default:
			break;
	}

	if (moved == 0)
		return 0;
	else
		return 1;

	//No movement occur checker
	return -1;

}


//Check if there exists any 2048 tile
int has_won()
{
	for (int j = 1; j <= 4; j++)
		for (int i = 1; i <= 4; i++)
			if (get(i, j) == 2048)
				return 1;
	return 0;
}

int has_lost()
{
	for (int j = 1; j <= 4; j++)
		for (int i = 1; i <= 4; i++)
			if (get(i, j) == 0)
				return 0;
	return 1;
}

//Return 0 if done
//Retrun -1 if game over
//Return 1 if game won

int update_grid(char input)
{
	//Implement code here
	

	int out = move(input);

	if (out == -1)
		if (!has_won())
			return -1;
	if (has_won())
		return 1;

	if (has_lost())
		return -1;

	generate_random_tile();

	//delete this line at the end
	return 0;
}


//Move a single tile return 1 if done else 0

int move_tile(char dir, int i, int j)
{
	int pre, cur;
	//Implement code here
	switch (dir)
	{
		case UP1:
		case UP2:

			if (j == 1)
				return 0;

			pre = get(i, j - 1);
			cur = get(i, j);

			if (cur != 0)
			{
				if (pre == 0)
				{
					set(i, j - 1, cur);
					set(i, j, 0);
					return 1;
				}
				if (pre == cur)
				{
					set(i, j - 1, 2 * cur);
					set(i, j, 0);
					set_current_scores(get_current_scores() + 2 * cur);
					return 1;
				}
			}
			break;

		case DOWN1:
		case DOWN2:

			if (j == 4)
				return 0;

			pre = get(i, j + 1);
			cur = get(i, j);

			if (cur != 0)
			{
				if (pre == 0)
				{
					set(i, j + 1, cur);
					set(i, j, 0);
					return 1;
				} 
				if (pre == cur)
				{
					set(i, j + 1, 2 * cur);
					set(i, j, 0);
					set_current_scores(get_current_scores() + 2 * cur);
					return 1;
				}
			}
			break;

		case LEFT1:
		case LEFT2:

			if (i == 1)
				return 0;

			pre = get(i - 1, j);
			cur = get(i, j);

			if (cur != 0)
			{
				if (pre == 0)
				{
					set(i - 1, j, cur);
					set(i, j, 0);
					return 1;
				} 
				if (pre == cur)
				{
					set(i - 1, j, 2 * cur);
					set(i, j, 0);
					set_current_scores(get_current_scores() + 2 * cur);
					return 1;
				}
			}
			break;

		case RIGHT1:
		case RIGHT2:

			if (i == 4)
				return 0;

			pre = get(i + 1, j);
			cur = get(i, j);

			if (cur != 0)
			{
				if (pre == 0)
				{
					set(i + 1, j, cur);
					set(i, j, 0);
					return 1;
				} 
				if (pre == cur)
				{
					set(i + 1, j, 2 * cur);
					set(i, j, 0);
					set_current_scores(get_current_scores() + 2 * cur);
					return 1;
				}
			}
			break;

	}
	return 0;
}
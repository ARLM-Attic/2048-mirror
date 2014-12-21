
/*
this file contains Functions to be implemented
*/


//the score variable to be set if scores added
int scores = 0;

//already implemented

int get_current_scores()
{ 
	return scores; 
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



}

//This will generate random tile

void generate_random_tile()
{

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
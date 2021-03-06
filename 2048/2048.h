/*
File:2048.h
Authur:Nauman Mustafa
Description:Provides Basic for Building 2048 Game
*/

#pragma once

//										Includes
//For Standard I/O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//For console I/O
#include <conio.h>
//C Standard library
#include <cstdlib>

//										Basic Definations
//Width of table
#define WIDTH 4
//Height of table
#define HEIGHT 4
//Size of Table
#define SIZE 16
////Maximum value of table
#define MAX 15
//Maximum X value of table
#define XMAX 4
//Maximum Y value of table
#define YMAX 4

//Left Key
#define LEFT1 'a'
#define LEFT2 'A'
//Right Key
#define RIGHT1 'd'
#define RIGHT2 'D'
//Up KeyS
//Up Key 1
#define UP1 'w' 
//Up Key 2
#define UP2 'W'
//Down Keys
//Down Key 1
#define DOWN1 's'
//Down Key 2
#define DOWN2 'S'
//Maximim Menu ID
#define MENUMAX 4


//										Functions
//Initialize table
void clear_table();

/*
Gets the number in table at given position
i: Horizontal or x component
j: Vertical or y component
*/
int get(int i, int j);

/*
set the number in table at given position
i: Horizontal or x component
j: Vertical or y component
value: The value to be set
*/
void set(int i, int j, int value);

//Retruns if game has been paused or not
int is_paused();

//Load High Scores
void load_scores();

//Save High Scores
void save_scores();

//returns high scores
int get_high_scores();

//sets high scores
void set_high_scores(int scores);

//Draw menu on screen
void draw_menu();

/*
Update menu and returns selected menu
0) Continue
1) New Game
2) Instructions
3) High Scores
4) Exit
*/
int update_menu(char input);

//Draw Instruction
void draw_instructions();

//Print Highest scores
void draw_scores();



//Draw game grid
void draw_grid();

//update game grid
int update_grid(char input);

//Game mode
void game_mode();

//move blocks in specific direction
int move(char direction);

//Returns current scores
int get_current_scores();

//Set current scores
void set_current_scores(int s);

//Generate random tile 
void generate_random_tile();

//return 1 if player has won else 0
int has_won();

//return 1 if moved
int move_tile(char dir, int i, int j);

//Returns 1 if lost else 0
int has_lost();
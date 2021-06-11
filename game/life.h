/**
 * @file life.h
 * Header file for our project containing macros and functions prototypes
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<SDL/SDL.h>
#define RESET   "\033[0m"       ///<Reset color to default
#define RED     "\033[31m"      ///< Red color 
#define GREEN   "\033[32m"      ///< Green color 
#define YELLOW  "\033[33m"      ///< Yellow color 
#define BLUE    "\033[34m"      ///< Blue color 

/* size of the screen */

#define SCREEN_WIDTH 25
#define SCREEN_HEIGHT 15

void create2dtable (int arr[][SCREEN_HEIGHT]);
int columnCorrection (int , int ); 
int rowCorrection (int , int ); 
int neighbourCheck (int arr[][SCREEN_HEIGHT] , int , int );
void startGeneration (int[][SCREEN_HEIGHT]);
void print (int[][SCREEN_HEIGHT]);
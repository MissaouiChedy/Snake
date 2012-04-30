#include "Snake.h"
#include "Window.h"
#include <assert.h>
#include <stdio.h>
Snake snake;
int ScreenHeight=100;
int ScreenWidth=100;
void setup();
void tearDown();
void testCreateSnake() ;

void testDisplaySnake();

void testEat();

void testOpposite();

void testSetDirection();

void testMoveSnake() ;

void testDestroySnake();

int main(int argc, char *argv[]){
	setup();
	testEat();
	testOpposite();
	testSetDirection();
	testMoveSnake();
	tearDown();
    printf("OK!\n");
}
void testCreateSnake() {}

void setup(){
   snake=createSnake(6);
}

void tearDown(){
   destroySnake(snake);  
}

void testDisplaySnake(){}

void testEat(){
 
}

void testOpposite(){}

void testSetDirection(){}

void testMoveSnake() {}

void testDestroySnake(){}

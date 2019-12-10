#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_FRAME_SIZE 7
#define MAX_STRING_SIZE 5

int LRU(int frame[],int inputString[],int size){
	
}

int FIFO(int frame[],int inputString[],int size){
	
}

void main(){
	
	srand(time(NULL));
	
	int frame[MAX_FRAME_SIZE];
	int inputString[MAX_STRING_SIZE];

	for(size_t i = 0; i < MAX_FRAME_SIZE; i++){
		int num = rand() % 10;
		frame[i] = num;
	}
	for(size_t i = 0; i < MAX_STRING_SIZE; i++){
		int num = rand() % 10;
		inputString[i] = num;
	}
}

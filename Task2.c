#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_FRAME_SIZE 7
#define MAX_STRING_SIZE 30

struct LRUObj{
	int id;
	int ref;
};

int findInArray(struct LRUObj frame[],int id){
	int foundIndex = 0;
	int found = 0;
	for(size_t i = 0; i < MAX_FRAME_SIZE; i++){
		if(id == frame[i].id){
			frame[i].ref = 1;
			found = 1;
			break;
		}
	}
	return found;	
}

void leftRotateOne(struct LRUObj arr[]){
	
	int head = 0;
	struct LRUObj temp;

	temp.id = arr[head].id;
	temp.ref = 0;
	
	size_t i =  0;
	for(i = 0; i < MAX_FRAME_SIZE - 1; i++){
		arr[i].id = arr[i+1].id;
		arr[i].ref = arr[i+1].ref;
	}	
	arr[i].id = temp.id;
	arr[i].ref = temp.ref;
}

int LRU(int frame[],int inputString[]){

	int pageFault = 0;
	struct LRUObj arr[MAX_FRAME_SIZE];

	//Init Struct for FRAME Struct
	for(size_t i=0;i<MAX_FRAME_SIZE;i++){
		arr[i].id = frame[i];
		arr[i].ref = 0;
	}
	
	for(size_t i=0;i < MAX_STRING_SIZE ;i++){
		
		int found = findInArray(arr,inputString[i]);
		
		//Already Exists in Array
		if(found){
			continue;
		}
		
		//Page Fault Occurs
		pageFault++;
		int tail = MAX_FRAME_SIZE - 1;
		int head = 0;
		
		while(arr[head].ref != 0){
			leftRotateOne(arr);			
		}
		
		arr[head].id = inputString[i];
		arr[head].ref = 1;
	}
	
	printf("\nPageFaults:%d\n",pageFault);
}

void printArray(int arr[],int size){
	printf("\n");
	for(size_t i = 0; i<size; i++){
		printf("%d ",arr[i]);
	}
}


int main(){
	srand(time(NULL));
	
	int inputString[MAX_STRING_SIZE];
	int frame[MAX_FRAME_SIZE];
	
	for(size_t i = 0; i < MAX_FRAME_SIZE; i++){
		int num = rand() % 10;
		frame[i] = num;
	}

	for(size_t i = 0; i < MAX_STRING_SIZE; i++){
		int num = rand() % 10;
		inputString[i] = num;
	}
	
	printf("\nFrame State");
	printArray(frame,MAX_FRAME_SIZE);
	
	printf("\nInput String");
	printArray(inputString,MAX_STRING_SIZE);
	
	printf("\n");
	LRU(frame,inputString);

	return 0;
}




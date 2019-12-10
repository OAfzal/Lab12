#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_FRAME_SIZE 7 // redundant - pls nuke
#define MAX_STRING_SIZE 5



void FIFO(int reference_string[MAX_STRING_SIZE], int frames)
{
	int page_faults = 0;
	int temp[frames];
	int m, s, n;
	for(m = 0; m < frames; m++)
	{
		temp[m] = -1;
	}
	printf("FIFO Gantt chart (-1 represents unallocated frame):\n");
	for(m = 0; m < MAX_STRING_SIZE; m++)
	{
		s = 0;
		for(n = 0; n < frames; n++)
		{
			if(reference_string[m] == temp[n])
			{
				s++;
				page_faults--;
			}
		}
		page_faults++;
		if((page_faults <= frames) && (s == 0))
		{
			temp[m] = reference_string[m];
		}
		else if(s == 0)
		{
			temp[(page_faults - 1) % frames] = reference_string[m];
		}
		printf("\n");
		for(n = 0; n < frames; n++)
        {     
            printf("%d\t", temp[n]);
        }
	}
	printf("\n\nTotal Page Faults in this FIFO run: %d\n", page_faults);

}

int main(){
	
	srand(time(NULL));
	int inputString[MAX_STRING_SIZE];
	int frames = (rand() % (7 - 1 + 1)) + 1;
	for(size_t i = 0; i < MAX_STRING_SIZE; i++){
		int num = rand() % 10;
		inputString[i] = num;
	}
	// FIFO
	FIFO(inputString, frames);

	return 0;
}

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

int updateArr(struct LRUObj frame[], int head, int tail){
	struct LRUObj temp;
	for(size_t i = 0; i < MAX_FRAME_SIZE; i++){
		temp.id = arr[tail].id;
		temp.ref = a
	}
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
		int tail = MAX_FRAME_SIZE - 1;
		int head = 0;
		
		while(arr[head].ref != 0){
		
			
		}
		
		if(arr[head].ref == 0){
			arr[j].id == inputString[i];
			arr[j].ref = 1;
			break;
		}
		
		for(size_t j = 0; j < MAX_FRAME_SIZE; j++){
		
			
			for(size_t k = 0;k < MAX_FRAME_SIZE; k++){
				if
			}
		}
	}
}

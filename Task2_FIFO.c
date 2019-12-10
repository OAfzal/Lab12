#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 5

// defines FIFO page replacement algorithm

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

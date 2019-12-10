#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned long page;
	unsigned long offset;
	long long int address;
	char *eptr;

	address= strtoul(argv[1], &eptr, 10);
	page = address >> 12; /* Since page size is 4KB => 12 bits holding the virtual address*/
	offset = address & 0xfff;

	printf("The address %llu contains: \n", address);
	printf("page number = %lu\n",page);
	printf("offset = %lu\n", offset);
	return 0;
}
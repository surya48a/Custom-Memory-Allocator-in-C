#include "header.h"

void myFree(void *p)
{

	if(p != NULL) {
		printf("In free p = %lu\n",p);
		BlockHeader * del = (BlockHeader *)p - 1;

		del -> isFree = true;
		printf("In free we are making true and address = %lu\n" , (unsigned long)del);
	}

}

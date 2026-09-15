#include "header.h"
#include<stdlib.h>

BlockHeader * head = NULL;
BlockHeader * last = NULL;

void check(void) {
	BlockHeader * visit = head;

	while(visit != NULL) {
		printf("Sizeof block = %d and isFree = %s\n",visit -> size , (visit -> isFree) == true ? "true" : "false");
		printf("Address = %lu\n",(unsigned long)visit);
		visit = visit -> next;
	}

}

int main()
{
	atexit(check);

	printf("Hello world\n");

	printf("Sizeof blockHeader = %ld\n", sizeof(BlockHeader));
	//printf("Current sbrk : %lu\n",(unsigned long )sbrk(0));

	int *p = (int *)myMalloc(5 * sizeof(int));
	int *kk = (int *)myMalloc(10 * sizeof(int));

	printf("Enter array elements : ");
	for(int i = 0 ; i < 5 ; i++) {
		scanf("%d",p + i);
	}

	printf("Array elements are : ");
	for(int i = 0 ;  i < 5 ; i++) {
		printf("%d ", p[i]);
	}

	printf("\n");
	void *c = myMalloc(100);
	//	printf("Current sbrk : %lu\n",(unsigned long )sbrk(0));

	myFree(kk);


	BlockHeader * visit = head;

	while(visit != NULL) {
		printf("visit = %lu\n",(unsigned long)visit);
		visit = visit -> next;
	}

	char * s = (char *)myCalloc( 10 , sizeof(char));

	for(int i = 0 ; i < 10 ; i++) {
		printf("%hhd ",s[i]);
	}

	printf("\n");

	return 0;
}

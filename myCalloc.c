#include "header.h"

void * myCalloc(size_t n , size_t size)
{

	if(head == NULL) {
		BlockHeader * new = (BlockHeader *)sbrk((n * size) + sizeof(BlockHeader));

		if(new == (void *)-1) {
			perror("sbrk");
			return NULL;
		}

		new -> size = n * size;
		new -> isFree = false;
		new -> next = NULL;
		new -> prev = NULL;

		head = new;
		last = head;

		memset(new + 1 , 0 , n * size);

		return (BlockHeader *)new + 1;
	}
	else {
		BlockHeader * check = head;
		BlockHeader * isThere = NULL;
		size_t maxFit = INT_MAX;

		while(check != NULL) {
			if(check -> isFree == true && check -> size <= n) {

				if(maxFit > check -> size) {
					isThere = check;
					maxFit = check -> size;
				}
			}
			check = check -> next;
		}

		if(isThere == NULL) {
			BlockHeader * new = (BlockHeader *)sbrk((n * size) + sizeof(BlockHeader));
			if(new == (void *)-1) {
				perror("sbrk");
				return NULL;
			}

			last -> next = new;
			new -> next = NULL;
			new -> prev = last;

			new -> size = n * size;
			new -> isFree = false;

			last = new;

			memset(new + 1 , 0 , n * size);

			return new + 1;
		}
		else {
			size_t diff = n - maxFit;

			if(diff <= 20) {
				isThere -> isFree = false;
				return isThere + 1;
			}
			else {
				BlockHeader * new = (BlockHeader *)sbrk((n * size) + sizeof(BlockHeader));
				if(new == (void *)-1) {
					perror("sbrk");
					return NULL;
				}

				last -> next = new;
				new -> prev = last;
				new -> next = NULL;

				new -> size = n * size;
				new -> isFree = false;

				last = new;

				memset(new + 1 , 0 , n * size);

				return new + 1;
			}
		}
	}
}

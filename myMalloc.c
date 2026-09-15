#include "header.h"

void * myMalloc(size_t n)
{
	if(head == NULL) {
		BlockHeader * new = (BlockHeader *)sbrk(sizeof(BlockHeader) + n);
		if(new == (void *)-1) {
			perror("Sbrk");
			return NULL;
		}
		new -> prev = NULL;
		new -> next = NULL;

		new -> size = n;
		new -> isFree = false;

		head = new;
		last = new;

		return new + 1;
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
			BlockHeader * new = (BlockHeader *)sbrk(sizeof(BlockHeader) + n);
			if(new == (void *)-1) {
				perror("Sbrk");
				return NULL;
			}

			last -> next = new;
			new -> prev = last;
			new -> next = NULL;

			new -> size = n;
			new -> isFree = false;

			last = new;

			return new + 1;
		}
		else {
			size_t diff = n - maxFit;

			if(diff <= 20) {
				isThere -> isFree = false;
				return isThere + 1;
			}
			else {
				BlockHeader * new = (BlockHeader *)sbrk(sizeof(BlockHeader) + n);
				if(new == (void *)-1) {
					perror("sbrk");
					return NULL;
				}

				last -> next = new;
				new -> prev = last;
				new -> next = NULL;

				new -> size = n;
				new -> isFree = false;

				last = new;

				return new + 1;
			}
		}
	}
}

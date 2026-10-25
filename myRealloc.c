#include "header.h"

void * myRealloc(void *p , size_t n)
{

	if(p == NULL) {
		if(head == NULL) {
			BlockHeader * new = (BlockHeader *)sbrk(n);

			if(new == (void *)-1) {
				perror("sbrk");
				return NULL;
			}

			new -> next = NULL;
			new -> prev = NULL;

			new -> size = n;
			new -> isFree = false;

			head = new;
			last = new;

			return new + 1;
		}
		else {
			BlockHeader * visit = head;
			BlockHeader * isThere = NULL;

			size_t maxFit = INT_MIN;

while(visit != NULL && visit -> size <= n) {
if(maxFit <= n) {
maxFit = n;
isThere = visit;
}
visit = visit -> next;
}

if(isThere == NULL) {

BlockHeader * new = (BlockHeader *)sbrk(n);

if(new == (void *)-1) {
perror("sbrk");
exit(1);
}

last -> next = new;
new -> next = NULL;
new -> prev = last;

new -> size = n;
new -> isFree = false;

return new + 1;
}
else {

memcpy(isThere , p , n);



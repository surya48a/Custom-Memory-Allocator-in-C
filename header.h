#ifndef ALLOCATOR_H
#define ALLOCATOR_H


#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<limits.h>


typedef struct BlockHeader
{
size_t size;
bool isFree;
struct BlockHeader * next;
struct BlockHeader * prev;
} BlockHeader;

void * myMalloc(size_t);
void * myCalloc(size_t , size_t);
void * myRealloc(void * , size_t);
void myFree(void *);

extern BlockHeader * head;
extern BlockHeader * last;

#endif

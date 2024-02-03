#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 256

struct set {
	int size;
	int elements[MAXSIZE];
};

void printUnion(struct set s1, struct set s2);

void printIntersection(struct set s1, struct set s2);

void printDifference(struct set s1, struct set s2);

bool isSubset(struct set s1, struct set s2);

bool isIn(struct set s, int x);

bool isEmpty(struct set s);

int size(struct set s);

void printSort(struct set s);

void printSet(struct set s);
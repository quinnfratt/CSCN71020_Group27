#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define MAXLENOFTRITYPE 30
typedef struct triangle {
	int side1;
	int side2;
	int side3;
	int triangleTypeID;
	char triangleType[MAXLENOFTRITYPE];
}TRI;

TRI GetTriangleSides();
void AnalyzeTriangle(TRI*);
int* FindAngles(TRI t);
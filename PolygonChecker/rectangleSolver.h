#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "rectanglesolver.h"
#include <stdlib.h>
#include <string.h>
#define MAXSTRINGLEN 25
typedef struct corner{
    int xcoord;
    int ycoord;
}Point;
typedef struct rectangle {
	Point topL;
	Point topR;
	Point bottomL;
	Point bottomR;
}REC;

bool testCoord(char*);
Point getPoint(int);
REC* createRectangle();
char* analyzeRectangle(REC*);
bool assignRectanglePoints(REC*, Point, Point, Point, Point);
void setRecPt(Point*, Point);
Point* returnOrder(Point, Point, Point, Point);
Point* YOrder(Point, Point, Point, Point);
bool largestX(Point, Point);
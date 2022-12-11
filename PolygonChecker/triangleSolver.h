#pragma once

typedef struct triangle {
	int side1;
	int side2;
	int side3;
	
}TRI;

TRI GetTriangleSides();
void AnalyzeTriangle(TRI);
int* FindAngles(TRI t);
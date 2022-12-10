#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

TRI GetTriangleSides() {
	TRI t;
	printf("Enter 3 Side Lengths: ");

	while (1) {
		if (scanf("%d %d %d", &t.side1, &t.side2, &t.side3) != 3) {
			printf("Error: Must be 3 values");

		}
			else 
			{
			break;
			}
	}
	return t;
}
void AnalyzeTriangle(TRI t) {
	if (t.side1 <= 0 || t.side2 <= 0 || t.side3 <= 0) {
		printf("Not a triangle");
	}
	else if (t.side1 == t.side2 && t.side1 == t.side3) {
		printf("Equilateral triangle");
	}
	else if ((t.side1 == t.side2 && t.side1 != t.side3) || 
		(t.side1 == t.side3 && t.side1 != t.side2))
	{
		printf("Isosceles triangle");
	}
	else {
		printf("Scalene triangle");
	}
	printf("\n");
}
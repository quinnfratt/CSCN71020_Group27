#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
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

int* FindAngles(TRI t)
{
	int* angles = malloc(sizeof(int)*3);
	if (angles == NULL)
		printf("Error allocating memory");
	double R, s, pi, area;
	pi = acos(-1);

	
	s = ((double)(t.side1) + (double)(t.side2) + (double)(t.side3)) / 2;
	area = sqrt(s * (s - (double)(t.side1)) * (s - (double)(t.side2)) * (s - (double)(t.side3)));

	R = ((double)(t.side1) * (double)(t.side2) * (double)(t.side3)) / (4 * area);

	double angle1 = (180 / pi) * asin((double)(t.side1) / (2 * R));
	double angle2 = (180 / pi) * asin((double)(t.side2) / (2 * R));
	double angle3 = (180 / pi) * asin((double)(t.side3) / (2 * R));

	

	angles[0] = ceil(angle1);
	angles[1] = ceil(angle2);
	angles[2] = ceil(angle3);
	
	return angles;

}
#include "rectangleSolver.h"

void getRectangleSides(int* rectangleSides) {
	printf_s("Enter the four sides of your renctangle: ");
	scanf_s("%d %d %d %d", &rectangleSides[0], &rectangleSides[1], &rectangleSides[2], &rectangleSides[3]);
}

void analyzeRectangle(int *rectanglesides)
{
	int point1 = rectanglesides[0], point2 = rectanglesides[1], point3 = rectanglesides[2], point4 = rectanglesides[3];
	char* result = "";
	if (point1 <= 0 || point2 <= 0 || point3 <= 0 || point4 <= 0) {
		result = "Not a rectangle";
	}
	else if (point1 != point2 && point1 != point3 && point1 != point4 || point3 != point1 && point3 != point2 && point3 != point4 || point2 != point1 && point2 != point3 && point2 != point4) {
		result = "Not a rectangle";
	}
	else if (point1 == point2 && point1 == point3 && point1 == point4)
	{
		result = "Square";
	}
	else if ((point1 < point2 && point1 == point3 && point3 < point4) ||
		(point1 != point2))
	{
		result = "Vertical Rectangle";
	}
	else if ((point1 > point2 && point1 == point3 && point2 == point4 && point3 > point4) ||
		(point1 != point2))
	{
		result = "Horizontal Rectangle";
	}

	else
	{
		result = "Not a rectangle";
	}

	printf_s("%s\n", result);
}
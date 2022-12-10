#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectanglesolver.h"

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			printf_s("Rectangle selected.\n");
			int *rectangleSides[4];
			getRectangleSides(rectangleSides);
			analyzeRectangle(rectangleSides);
			break;
		case 1:
			printf_s("Triangle selected.\n");
			TRI triangle = GetTriangleSides();
			AnalyzeTriangle(triangle);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}
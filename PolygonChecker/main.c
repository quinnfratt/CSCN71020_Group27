#include "main.h"

int main() {
	char results[MAXSTRINGLEN];
	int* triResults = malloc(sizeof(int)*3);
	if (triResults == NULL)
		printf("error allocating memory");
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 2:
			
			printf("Rectangle selected.\n");
			printf("\nPlease enter the four points of the rectangle:");
			Point pt1 = getPoint(1), pt2 = getPoint(2), pt3 = getPoint(3), pt4 = getPoint(4);
			REC* rectangle = createRectangle();
			if (!assignRectanglePoints(rectangle, pt1, pt2, pt3, pt4)) {
				printf("Not a rectangle\n");
				break;
			}
			strcpy(results, analyzeRectangle(rectangle));
			printf("The Rectangle Entered is: %s\n\n", results);
			break;
		case 1:
			printf("Triangle selected.\n");
			TRI triangle = GetTriangleSides();
			AnalyzeTriangle(&triangle);
			if (triangle.triangleTypeID == 1){
				printf("\nThe Triangle Entered is: %s\n", triangle.triangleType);
				break;
			}
			triResults = FindAngles(triangle);
			printf("\nThe Triangle Entered is: %s\n", triangle.triangleType);
			printf("and has the following inner angles: %d %d %d\n\n", triResults[0], triResults[1], triResults[2]);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf("\n");
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**   Polygon Checker  **\n");
	printf(" **********************\n");
}

int printShapeMenu() {
	printf("1. Triangle\n");
	printf("2. Rectangle\n");
	printf("0. Exit\n\n");

	int shapeChoice;

	printf("Enter number: ");
	scanf("%1o", &shapeChoice);

	return shapeChoice;
}
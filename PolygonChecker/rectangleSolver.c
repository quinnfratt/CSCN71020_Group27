#include "rectangleSolver.h"

Point getPoint(int n){
	Point pt;
	pt.xcoord = NULL;
	pt.ycoord = NULL;
	char *buffer;
	printf("\n\nPoint %d:\n", n);
	printf("\nEnter the X-Coordinate: ");
	while(true){
		fseek(stdin, 0, SEEK_END);
		scanf("%s", &buffer);
		if(testCoord(&buffer)){
			sscanf(&buffer, "%d", &pt.xcoord);
			break;
		} 
		else {
			printf("\nEnter only an integer for the X-Coordinate: ");
		}
	}

	printf("Enter the Y-Coordinate: ");
	while (true) {
		fseek(stdin, 0, SEEK_END);
		scanf("%s", &buffer);
		if (testCoord(&buffer)) {
			sscanf(&buffer, "%d", &pt.ycoord);
			break;
		}
		else {
			printf("\nEnter only an integer for the Y-Coordinate: ");
		}
	}
	
	return pt;
}
bool testCoord(char *coord){
	for (int i = 0; i < strlen(coord); i++) {
		if (!*(coord+i) >= 48 && *(coord+i) <= 57) {
			return false;
		}
	}
	return true;
}

REC* createRectangle () {
	REC* newRectangle = malloc(sizeof(REC));
	if (newRectangle == NULL) {
		printf("Error allocating memory");
		exit(1);
	}
	newRectangle->topL.xcoord = NULL, newRectangle->topL.ycoord = NULL;
	newRectangle->topR.xcoord = NULL, newRectangle->topR.ycoord = NULL;
	newRectangle->bottomL.xcoord = NULL, newRectangle->bottomL.ycoord = NULL;
	newRectangle->bottomR.xcoord = NULL, newRectangle->bottomR.ycoord = NULL;
	return newRectangle;
}

bool assignRectanglePoints(REC* rectangle, Point p1, Point p2, Point p3, Point p4) {
	Point *orderedPts = malloc(sizeof(Point)* 4);
	orderedPts = returnOrder(p1, p2, p3, p4);
	if (orderedPts == NULL) {
		return false;
	}
	setRecPt(&rectangle->topL, orderedPts[0]);
	setRecPt(&rectangle->topR, orderedPts[1]);
	setRecPt(&rectangle->bottomL, orderedPts[2]);
	setRecPt(&rectangle->bottomR, orderedPts[3]);
	return true;
}

void setRecPt(Point* recPt, Point pt) {
	recPt->xcoord = pt.xcoord;
	recPt->ycoord = pt.ycoord;
}
Point* returnOrder(Point p1, Point p2, Point p3, Point p4) {
	Point *largerYs = malloc(sizeof(Point) * 4);
	if (largerYs == NULL) {
		printf("Error allocating memory");
		exit(1);
	}
	Point *order = malloc(sizeof(Point) * 4);
	if (order == NULL) {
		printf("Error allocating memory");
		exit(1);
	}
	if (!YOrder(p1, p2, p3, p4)) {
		Point *nullPt = NULL;
		return nullPt;
	}
	else {
		largerYs = YOrder(p1, p2, p3, p4);
	}
	if (largestX(largerYs[0], largerYs[1])) {
		order[0] = largerYs[1], order[1] = largerYs[0];
	}
	else{
		order[0] = largerYs[0], order[1] = largerYs[1];
	}

	if (largestX(largerYs[2], largerYs[3])) {
		order[2] = largerYs[3], order[3] = largerYs[2];
	}
	else if (largestX(largerYs[3], largerYs[2])) {
		order[2] = largerYs[2], order[3] = largerYs[3];
	}
	else {
		order[2] = largerYs[3], order[3] = largerYs[2];
	}
	return order;
}


Point* YOrder(Point p1, Point p2, Point p3, Point p4) {
	Point *yorder = malloc(sizeof(Point) * 4);
	if (yorder == NULL) {
		printf("Error allocating memory");
		exit(1);
	}
	if (p1.ycoord == p2.ycoord) {
		if (p1.ycoord > p3.ycoord) {
			yorder[0] = p1, yorder[1] = p2, yorder[2] = p3, yorder[3] = p4;
			return yorder;
;		}
		else if (p1.ycoord < p3.ycoord) {
			yorder[0] = p3, yorder[1] = p4, yorder[2] = p1, yorder[3] = p2;
			return yorder;
		}
	}
	else if (p1.ycoord == p3.ycoord) {
		if (p1.ycoord > p2.ycoord) {
			yorder[0] = p1, yorder[1] = p3, yorder[2] = p2, yorder[3] = p4;
			return yorder;
			;
		}
		else if (p1.ycoord < p2.ycoord) {
			yorder[0] = p2, yorder[1] = p4, yorder[2] = p1, yorder[3] = p3;
			return yorder;
		}
	}

	else if (p1.ycoord == p4.ycoord) {
		if (p1.ycoord > p2.ycoord) {
			yorder[0] = p1, yorder[1] = p4, yorder[2] = p2, yorder[3] = p3;
			return yorder;
			;
		}
		else if (p1.ycoord < p2.ycoord) {
			yorder[0] = p2, yorder[1] = p3, yorder[2] = p1, yorder[3] = p4;
			return yorder;
		}
	}
	else {
		return false;
	}
}
bool largestX(Point p1, Point p2) {
	if (p1.xcoord > p2.xcoord) {
		return true;
	}
	return false;
}


char* analyzeRectangle(REC rectangle)
{
	char result[MAXSTRINGLEN];
	if (rectangle.topR.xcoord == rectangle.topL.xcoord || rectangle.bottomL.xcoord == rectangle.bottomR.xcoord) {
		strcpy(result, "Not a rectangle\0");
	}
	else if (rectangle.topR.xcoord - rectangle.topL.xcoord == rectangle.topL.ycoord - rectangle.bottomR.ycoord)
	{
		strcpy(result, "A Square\0");
	}
	else if (rectangle.topR.xcoord - rectangle.topL.xcoord < rectangle.topL.ycoord - rectangle.bottomR.ycoord)
	{
		strcpy(result, "A Vertical Rectangle\0");
	}
	else if (rectangle.topR.xcoord - rectangle.topL.xcoord > rectangle.topL.ycoord - rectangle.bottomR.ycoord)
	{
		strcpy(result, "A Horizontal Rectangle\0");
	}
	return result;
}
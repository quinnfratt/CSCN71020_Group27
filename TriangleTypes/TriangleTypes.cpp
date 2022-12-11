#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include "..\PolygonChecker\triangleSolver.h"
extern "C" void AnalyzeTriangle(TRI*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace TestTriangleTypes
{
	TEST_CLASS(TestTriangleTypes)
	{
	public:

		TEST_METHOD(equilateralTriangle)
		{
			//Tests to get equilateral triangle
			TRI equilatateral;
			equilatateral.side1 = 30;
			equilatateral.side2 = 30;
			equilatateral.side3 = 30;
			AnalyzeTriangle(&equilatateral);
			int actual = equilatateral.triangleTypeID;

			Assert::AreEqual(actual, 2);
		}

		TEST_METHOD(isoscelesTriangle)
		{
			//Tests to get isosceles triangle
			TRI isosceles;
			isosceles.side1 = 25;
			isosceles.side2 = 25;
			isosceles.side3 = 30;
			AnalyzeTriangle(&isosceles);
			int actual = isosceles.triangleTypeID;

			Assert::AreEqual(actual, 3);
		}

		TEST_METHOD(scaleneTriangle)
		{

			//Tests to get scalene triangle
			TRI scalene;
			scalene.side1 = 15;
			scalene.side2 = 25;
			scalene.side3 = 30;
			AnalyzeTriangle(&scalene);
			int actual = scalene.triangleTypeID;

			Assert::AreEqual(actual, 4);
		}

		TEST_METHOD(invalidTriangle)
		{
			//Tests using invalid side lengths to get the not a triangle prompt
			TRI invalid;
			//uses negative numbers because side lengths can not be negative
			invalid.side1 = -25;
			invalid.side2 = 0;
			invalid.side3 = -30;
			AnalyzeTriangle(&invalid);
			int actual = invalid.triangleTypeID;

			Assert::AreEqual(actual, 1);
		}
	};
}

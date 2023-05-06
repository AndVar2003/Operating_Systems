#include "pch.h"
#include "CppUnitTest.h"
#include "../OS_Lab2/minmax.h"
#include "../OS_Lab2/minmax.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTestsLab2)
	{
	public:
		
		TEST_METHOD(Minimum_Test)
		{
			std::pair<double, double> minmax;
			std::vector<double> Array = { 1,2,3,4,5 };
			int expected_min = 1;

			std::thread ThreadMinMax(MinMax::Min_Max, std::ref(Array), std::ref(minmax));
			ThreadMinMax.join();
			Assert::AreEqual(static_cast<int>(minmax.first), expected_min);
		}

		TEST_METHOD(Maximum_Test)
		{
			std::pair<double, double> minmax;
			std::vector<double> Array = { 1,2,3,4,5 };
			int expected_max = 5;

			std::thread ThreadMinMax(MinMax::Min_Max, std::ref(Array), std::ref(minmax));
			ThreadMinMax.join();
			Assert::AreEqual(static_cast<int>(minmax.second), expected_max);
		}

		TEST_METHOD(Average_Test)
		{
			double average;
			std::vector<double> Array = { 1,2,3,4,5 };
			double expected_average = 3;

			std::thread ThreadAverage(MinMax::Average, std::ref(Array), std::ref(average));
			ThreadAverage.join();
			Assert::AreEqual(average, expected_average);
		}

		TEST_METHOD(Negative_Test_Min)
		{
			std::pair<double, double> minmax;
			std::vector<double> Array = { -1, -2, -3, -4, -5 };
			int expected_min = -5;

			std::thread ThreadMinMax(MinMax::Min_Max, std::ref(Array), std::ref(minmax));
			ThreadMinMax.join();
			Assert::AreEqual(static_cast<int>(minmax.first), expected_min);
		}

		TEST_METHOD(Negative_Test_Max)
		{
			std::pair<double, double> minmax;
			std::vector<double> Array = { -1, -2, -3, -4, -5 };
			int expected_max = -1;

			std::thread ThreadMinMax(MinMax::Min_Max, std::ref(Array), std::ref(minmax));
			ThreadMinMax.join();
			Assert::AreEqual(static_cast<int>(minmax.second), expected_max);
		}

		TEST_METHOD(Mix_Test_MinMax)
		{
			std::pair<double, double> minmax;
			std::vector<double> Array = { -1, 2, -3, 4, -5 };
			int expected_min = -5;
			int expected_max = 4;

			std::thread ThreadMinMax(MinMax::Min_Max, std::ref(Array), std::ref(minmax));
			ThreadMinMax.join();
			Assert::AreEqual(static_cast<int>(minmax.first), expected_min);
			Assert::AreEqual(static_cast<int>(minmax.second), expected_max);
		}

		TEST_METHOD(ArrayChanging_Test)
		{
			std::vector<double> Array = { -1, 2, -3, 4, -5 };
			std::vector<double> expectedArray = { -1, 2, -3, -0.6, -0.6 };
			std::pair<double, double> minmax = std::make_pair(-5, 4);
			double average = -0.6;

			MinMax::Change_Array(Array, minmax, average);
			Assert::AreEqual(Array[3], expectedArray[3]);
			Assert::AreEqual(Array[4], expectedArray[4]);
		}
	};
}

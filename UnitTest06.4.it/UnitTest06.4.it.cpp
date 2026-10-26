#include "pch.h"
#include "CppUnitTest.h"
#include "../PR06.4.it/FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064it
{
	TEST_CLASS(UnitTest064it)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double test_arr[] = { 5.1, -2.2, 0.5, -0.1, 3.0 };
			int n = 5;
			int actual = findminIndex(test_arr, n);
			int excepted = 3;
			Assert::AreEqual(excepted, actual);
		}
		TEST_METHOD(TestMethod2)
		{
			double test_arr[] = { 2.0, 3.0, -4.0, 5.0, -6.0 };
			int n = 5;
			double actual = findsumIndex(test_arr, n);
			double expected = 11;
			Assert::AreEqual(expected, actual, 0.001);
		}
		TEST_METHOD(TestMethod3)
		{
			double test_arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
			int n = 5;
			compresarray(test_arr, n, 2.0, 4.0);


			Assert::AreEqual(1.0, test_arr[0]);
			Assert::AreEqual(5.0, test_arr[1]);
			Assert::AreEqual(0.0, test_arr[2]);
			Assert::AreEqual(0.0, test_arr[3]);
			Assert::AreEqual(0.0, test_arr[4]);
		}
	};
}

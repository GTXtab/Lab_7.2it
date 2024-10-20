#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2it/Lab_7.2it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int a[n] = { 3, 1, 4, 1, 5 };

			int minIndex = Search(a, n);

			Assert::AreEqual(1, minIndex);
		}
	};
}

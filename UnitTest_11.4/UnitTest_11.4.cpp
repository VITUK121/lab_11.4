#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_11.4/lab_11.4.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest114
{
	TEST_CLASS(UnitTest114)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string line = "word1 word22 word333";
			string expected = "word333";
			Assert::AreEqual(" " + expected, findLongestWord(line));
		}
	};
}

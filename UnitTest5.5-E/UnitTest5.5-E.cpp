#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1-E/BitString.cpp"
#include "../Lab_5.1-E/Object.cpp"
#include "../Lab_5.1-E/MyException.cpp"
#include "../Lab_5.1-E/MyDerivedException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55E
{
	TEST_CLASS(UnitTest55E)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BitString a, b;
			a.SetFirst(0);
			a.SetSecond(0);

			b.SetFirst(0);
			b.SetSecond(0);

			BitString c = (a ^ b);
			Assert::AreEqual(c.GetFirst(), 0.);
			Assert::AreEqual(c.GetSecond(), 0.);
		}
	};
}

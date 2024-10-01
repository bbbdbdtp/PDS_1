#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_1/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тест для функції implication
        TEST_METHOD(TestImplication) {
            Assert::IsTrue(implication(0, 0));
            Assert::IsTrue(implication(0, 1));
            Assert::IsFalse(implication(1, 0));
            Assert::IsTrue(implication(1, 1));
        }

        // Тест для функції equivalence
        TEST_METHOD(TestEquivalence) {
            Assert::IsTrue(equivalence(0, 0));
            Assert::IsFalse(equivalence(0, 1));
            Assert::IsFalse(equivalence(1, 0));
            Assert::IsTrue(equivalence(1, 1));
        }

        // Тест для порозрядних операцій OR, AND, XOR
        TEST_METHOD(TestBitwiseOperations) {
            string a = "111100000";
            string b = "101010011";
            string orResult, andResult, xorResult;

            bitwise_operations(a, b, orResult, andResult, xorResult);

            Assert::AreEqual(string("111110011"), orResult);
            Assert::AreEqual(string("101000000"), andResult);
            Assert::AreEqual(string("010110011"), xorResult);
        }

        // Це один приклад тесту для рядків з іншими значеннями
        TEST_METHOD(TestBitwiseOperations_AllOnesAndZeros) {
            string a = "111111111";
            string b = "000000000";
            string orResult, andResult, xorResult;

            bitwise_operations(a, b, orResult, andResult, xorResult);

            Assert::AreEqual(string("111111111"), orResult);
            Assert::AreEqual(string("000000000"), andResult);
            Assert::AreEqual(string("111111111"), xorResult);
        }

    };
}

#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1/Lab 7.1.cpp"

TEST_CLASS(UnitTest1)
{
public:
    TEST_METHOD(TestCalc)
    {
        const int Rows = 7;
        const int ColCount = 6;
        int a[Rows][ColCount]{};

        int testMatrix[Rows][ColCount] = {
            {10, 12, 16, 25, 29, 30},
            {10, 16, 16, 26, 38, 43},
            {11, 17, 22, 34, 39, 43},
            {12, 19, 24, 38, 43, 52},
            {13, 21, 29, 38, 46, 54},
            {13, 29, 31, 44, 50, 60},
            {30, 37, 45, 47, 60, 61}
        };

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < ColCount; j++) {
                a[i][j] = testMatrix[i][j];
            }
        }

        int S = 0;
        int k = 0;
        Calc(a, Rows, ColCount, S, k);

        int expectedS = 690;
        int expectedK = 21;

        std::cout << "S = " << S << std::endl;
        std::cout << "k = " << k << std::endl;

        Assert::AreEqual(S, expectedS);
        Assert::AreEqual(k, expectedK);
    }
};

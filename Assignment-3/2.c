// Aditya Mitra
// 20BCE2044
// Program to use binary search to implement binary search
// to get square root of a number

#include <stdio.h>

int binsearch_imp(int l, int r)
{
    int m, x;

    x = r;

    if (x == 0 || x == 1)
    {
        return x;
    }
    else
    {
        l = 1;
        r = x;
        while (l <= r)
        {
            m = l + (r - l) / 2;

            // Check if x is present at mid
            if (m * m == x)
                break;

            // If x greater, ignore left half
            if (m * m < x)
                l = m + 1;

            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
    }

    return m;
}
int main()
{
    int x, m;

    // Input
    printf("Enter number: ");
    scanf("%d", &x);

    // Processing
    m = binsearch_imp(1, x);

    // Output
    printf("Square Root : %d", m);

    return 0;
}

// Aditya Mitra 20BCE2044
#include <stdio.h>
void Hanoi(int n, char x, char y, char z) // Recursive function to move disks
{
    if(n==1) // base condition
    {
        printf("\nMoved Disk %d from %c to %c", n, x, y); // To print which disk has been moved where
    }
    else
    {
        Hanoi(n - 1, x, z, y);
        printf("\nMoved Disk %d from %c to %c", n, x, y); // To print which disk has been moved where
        Hanoi(n - 1, z, y, x);
    }
}
int main()// Main function to drive the code
{
    int n;// To store the number of disks
    printf("Enter the number of Discs\n");
    scanf("%d",&n);
    Hanoi(n, 'A', 'B', 'C');
}

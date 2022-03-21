#include <stdio.h>

int main()
{

    int firstNumber = 0;
    int secondNumber = 1;

    for(int i = 0; i < 20; i++)
    {
        printf("%i", firstNumber);
        int nextNumber = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = nextNumber;
    }

}

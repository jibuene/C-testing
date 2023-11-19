#include <stdio.h>
#include <time.h>
#include <unistd.h>

// If we list all the natural numbers below 10
// that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23

// Find the sum of all the multiples of 3 or 5 below 1000.

int multipleOfNum(int numbers[], int numbersLength, int maxNum)
{
    int sum = 0;
    for (int i = 0; i < maxNum; ++i)
    {
        for (int multipleOf = 0; multipleOf < numbersLength; ++multipleOf)
        {
            if (i % numbers[multipleOf] == 0)
            {
                sum += i;
                break;
            }
        }
    }
    
    return sum;
}


int main(int argc, char *argv[])
{
    int numbersArray[2] = {3, 5};
    int numbersArraysize = sizeof(numbersArray) / sizeof(numbersArray[0]);
    
    int sum = multipleOfNum(numbersArray, numbersArraysize, 1000);

    printf("Sum is: %d \n", sum);
    
    return 0;
}

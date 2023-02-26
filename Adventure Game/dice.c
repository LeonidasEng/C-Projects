#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Randomise(void);
int Random_Dice_Roll(int number);

int main()
{
    int input;
    scanf("Enter a number: %d", &input);
    Randomise();
    printf("%d", Random_Dice_Roll(input));

    return 0;
}

int Random_Dice_Roll(int number)
{
        //int number, i;
    // printf("Enter number of dice:");
    // scanf("%d", &number); 
    // printf("The value on dice are: ( ");
    // for (i = 0; i < number; i++)
    //     printf("%d ", (rand() % 6) + 1);
    // printf(")");
    return (rand() % 6) + 1; // Add 1 to get all values 1,2,3,4,5,6 from modulo of n % 6  
}

void Randomise()
{
    srand( (unsigned)time(NULL)); // Ensures random time is running for each run of the Random Dice Roll
}


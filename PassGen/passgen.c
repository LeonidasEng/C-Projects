#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void randPassGen (int N)
{
    // Initialises counter
    int i = 0;
    int randomiser = 0;

    // Seed the random-number generator with current time so that the 
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));

    // Array of numbers
    char numbers[] = "0123456789";

    // Array of lowercase letters
    char letter[] = "abcdefghijklmnopqrstuvwxyz";

    // Array of capital letters
    char LETTER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Array of special characters
    char symbols[] = "!@#~$^&*?.,";

    // Stores the random password
    char password[N];

    // To select the randomiser inside the loop
    randomiser = rand() % 4;
    
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++)
    {
        if (randomiser == 1) {
            password[i] = numbers[rand() % 10];
            randomiser = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomiser == 2) {
            password[i] = symbols[rand() % 11];
            randomiser = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomiser == 3) {
            password[i] = LETTER[rand() % 26];
            randomiser = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomiser = rand() % 4;
            printf("%c", password[i]);
        }   
    }
}

// User input, password output
int main() {

    // Length of the password to be generated & flag that keeps application running
    int N, flag = 0;
    
    // User key press
    char ch;
    do{
        // Prompt for user to input their desired length.
        printf("How many characters do you want your password to be?\nType a number:\n");
        scanf(" %d", &N);
        printf("Initialising...\n");
        
        // Function Call
        randPassGen(N);

        printf("\nPress 'q' to quit , 'y' to continue generating ");
        scanf(" %c", &ch);

        //Prompt for user to end app or continue generating
        if (ch == 'q')
            flag = 1;
        if (ch == 'y')
            flag = 0;    
    } while (flag == 0);

    return 0;
}
/**************************************\
|*  A choose your own Adventure Game  *|
|*          By LeonidasEng            *|
\**************************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
/* To Include pauses in the text */
int sleep();
void Randomise(void);
int Random_Dice_Roll(int input);

int main()
{
    /* Option Variables */
    int flag = 0;
    char ch;
    char opt; // For Options
    char LR; // Left or Right
    
    /* Character Variables */
    char name[50];
    char gender;
    char pronoun_src[5];
    char pronoun_dest[5];

    /* Game Variables */
    char invalid[] = "Invalid Option!";
    char endgame[] = "Game Over!";
    

    //int ptrLR = *LR;

    int N;

    /* Run game in a loop */
    do{
        // Make it possible to insert a name with ehite space:
        printf("Enter your name to begin your adventure:");
        //fgets(name, 20, stdin);
        scanf("%s", name);
        
        // Set the gender of the character:
        printf("Are you male or female? (Enter M/F)\n");
        scanf(" %c", &gender);
        
        /* Logic for adding the correct pronoun to the adventure game */
        if (gender == 'M' || gender == 'm')
        {
            memset(pronoun_dest, '\0', sizeof(pronoun_dest));
            strcpy(pronoun_src, "he");
            strncpy(pronoun_dest, pronoun_src, 2);
            printf("Pronoun : %s\n", pronoun_dest);
        } else if (gender == 'F' || gender == 'f')
        {
            memset(pronoun_dest, '\0', sizeof(pronoun_dest));
            strcpy(pronoun_src, "she");
            strncpy(pronoun_dest, pronoun_src, 3);
        } else
            printf("%s", invalid);
        
        printf("Your adventure is loading...\n");
        sleep(4);

        /* Game Starts */
        printf("%s is walking through the forest when %s hears a monstrous roar!\n", name, pronoun_dest);
        sleep(3);
        printf("Does %s...\n", pronoun_dest);
        printf("1.Run towards the sound.\n2.Run away!\n(Press 1/2)\n");
        scanf(" %c", &opt);
        
        /* First set of options */
        if (opt == '2')
        {
            printf("%s runs away! %s will be forevermore known as %s the coward! %s", name, pronoun_dest, name, endgame);
            sleep(4);    
        } else if (opt != '1' && opt != '2')
        {
            printf("%s", invalid);
        } else {
            printf("%s heroically charges in the direction of the sound until %s arrives at a cave.\n", name, pronoun_dest);
            printf("The sound of the monster is echoing from the mouth of the cave.\n");  
            while (1)
            {
                printf("Does %s...\n", name);
                printf("1. Charge headlong into the cave, sword drawn!\n2. A surprise attack would be best, let's tread carefully.\n3. Maybe there is another way in?\n(Press 1/2/3)\n");        
                scanf(" %c", &opt);
                if (opt == '1')
                {
                    printf("%s charges into the cave but trips on a rock, breaking their neck!\n", name);
                    printf("%s", endgame);
                    sleep(4);
                    break;
                } else if (opt == '2')
                {
                    break;
                } else if (opt != '1' && opt != '2' && opt != '3')
                {
                    printf("%s", invalid);
                    printf(" Please select another option!\n");
                    sleep(3);
                } else {
                    printf("%s looks around for an alternative route, but there are none to be found. Steep cliffs on either side of the cave make it impossible to go any other way.\nPick another option!\n", name);
                    sleep(4);
                }    
            }
        if (opt == '2')
            {
                printf("Lighting a torch, %s goes down the passage until %s reaches a fork in the passageway.\n", name, pronoun_dest);
                printf("Does %s go \"left\" or \"right\"? Type L or R:", pronoun_dest);
                scanf(" %c", &LR);
                if (LR == 'L' || LR == 'l')
                {
                    printf("%s takes the left passageway...\n", name);
                    sleep(2);
                    printf("Oh no! %s activated a trap!\n", name);
                    printf("%s was impaled on a spike. Game over!", name);
                } else if (LR == 'R' || LR == 'r')
                {
                    printf("%s takes the right passageway...\n", name);
                    printf("%s enters a large cavern, where %s comes upon the source of the sound...\n", name, pronoun_dest);
                    sleep(2);
                    printf("A dragon!\n");
                    
                    // Combat Starts <here new combat feature goes here>
                    sleep(3);
                    printf("The dragon is alerted to your prescence!\n");
                    sleep(2);
                    printf("The dragon is charging at you!\n");
                    sleep(3);
                    printf("What will you do?\n");
                    printf("1.Charge at the beast!\n2.Roll to the side\n3.Stand still and scream!\n(Press 1/2/3)\n");
                    scanf("%d", &opt);
                    if (opt == 1)
                    {
                        Randomise();
                        Random_Dice_Roll(opt);
                        if (Random_Dice_Roll > 5)
                        {
                            printf("%s charges at the dragon and with a ferocious display of agility strikes the dragon down!\n", name);
                            sleep(2);
                            printf("With the dragon defeated %s's work is done and any treasure from the dragon's horde is for the taking!\n", name);
                            sleep(3);
                            printf("%s is victorious! %s will be forevermore known as %s the dragonslayer! %s", name, pronoun_dest, name, endgame);
                        }
                        else
                            printf("%s charges at the dragon and is immediately crushed beneath powerful claws!\n", name);
                            sleep(2);
                            printf("%s was killed! %s will be forevermore known as %s the flattened! %s", name, pronoun_dest, name, endgame);
                    }
                    else if (opt == 2)
                    {
                        Randomise();
                        Random_Dice_Roll(opt);
                        if (Random_Dice_Roll > 3)
                        {
                            printf("%s sneakily avoids the dragon's charge and fires arrows at the dragons exposed hide!\n");
                            sleep(1);
                            printf("With the dragon defeated %s's work is done and any treasure from the dragon's horde is for the taking!\n", name);
                            sleep(2);
                            printf("%s is victorious! %s will be forevermore known as %s the dragonslayer! %s", name, pronoun_dest, name, endgame);
                        }
                        else
                            printf("%s tries to roll out the way and is too slow! The dragon counters smashing %s with it's tail!\n", name);
                            sleep(1);
                            printf("%s was killed! %s will be forevermore known as %s the whiplashed! %s", name, pronoun_dest, name, endgame);                   
                    }
                    else if (opt == 3)
                    {
                        printf("The dragon towers over %s, and with a deep breath breathes a torrent of fire!\n", name);
                        sleep(2);
                        printf("%s was killed %s will be forevermore known as %s the charred! %s", name, pronoun_dest, name, endgame);                            
                    }
                    else
                        printf("%s", invalid);
                } else
                {
                    printf("%s", invalid);
                }
            }   
        }
        printf("\n\nPress 'q' to quit , 'y' to try again? ");
        scanf(" %c", &ch);

        //Prompt for user to end app or continue game
        if (ch == 'q')
            flag = 1;
        if (ch == 'y')
            flag = 0;   
    } while (flag == 0);

    return 0;
}

int Random_Dice_Roll(int input)
{
    return (rand() % 6) + 1; // Add 1 to get all values 1,2,3,4,5,6 from modulo of n % 6  
}

void Randomise()
{
    srand((unsigned)time(NULL)); // Ensures random time is running for each run of the Random Dice Roll
}


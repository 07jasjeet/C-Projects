/*
Author : Jasjeet Singh (UE218049)
Date : 19th July 2022
Purpose : Guess the number game.
          User will have to guess a number that is randomly generated by the
          computer in the range of 0-20.
          User gets 5 tries and computer will tell if their entered number is 
          too high or too low. If the guess is within the range "number ± 3"
          then the game will either tell you "Your guess is close but higher."
          or "Your guess is close but lower." based on the conditions at that 
          moment.

Libraries Used : <stdio.h>,  <stdlib.h>,  <time.h>
*/


void GuessTheNumber()
{
    system("cls");
    
    int guess; 
    unsigned int tries = 4;
    
    // Code to select random integer between 0 to 20.
    time_t t;
    srand((unsigned) time(&t));                                                 
    int number = rand()%21;
    
    printf("Welcome to the guessing game where you have to guess a number within 0 to 20 within 5 tries!\n");
    printf("\nComputer has selected a random number within 0 to 20 and its your turn to guess the number.\n");
    
    while (tries <= 4)                      
    // The code which should be repeated should all be written after defining a loop
    {    
        printf("\nYou have %d tr%s left.\n", (tries + 1) , (tries + 1) == 1 ? "y" : "ies" ); 
        // Will show "try" if tries == 1 and "tries" if tries > 1
        printf("Your guess : ");
        scanf("%d",&guess);

        if (guess != number){
                if (guess >= 0 && guess <= 20)          
                // Condition to check if the guessed number is within the permissible range.
                {   
                    if (guess > number){
                        if (guess > number+3)                       
                            printf("\nYour guess is too high.\n");          
                        else
                            printf("\nYour guess is close but higher.\n");
                        
                        // Gives you a hint that your guess is higher than the selected number.
                    }
                    else{
                        if (guess < number-3)
                            printf("\nYour guess is too low.\n");
                        else
                            printf("\nYour guess is close but lower.\n"); 
                                      
                        // Gives you a hint that your guess is lower than the selected number.
                    }
                }
                else
                {   
                    printf("\nPlease enter a number within the given range.\n");
                    ++tries;     
                    // Increments number of tries if guess value inserted is out of given range.
                }

            printf("%s", tries == 0 ? "Sorry, you lost.\n" : "");          
            // Displays "Sorry, you lost." message after 5 tries.   
        }           
        else
        {
            printf("\nCONGRATULATIONS! You've guessed the number accurately.");
            break;     // Jumps out of loop immediately after getting correct answer. 
        }
        --tries;       // Reduces the count of tries left.
    }
    
    printf("\nThankyou for playing the game.\nPress any key to continue.\n");       
    // Message that confirms the end of the game.
    getch();            
    // Requests for a character input from the user.

}



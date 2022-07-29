
/* 
Author : Jasjeet Singh (UE218049)
Date : 19th July 2022
Purpose : This is the driver function for the two include games
          as part of the summer training project.
          Every game's respective description is given in the
          game module itself.  
*/

#include<stdio.h>
#include<stdlib.h>      // For use of system() function.
#include<conio.h>       // For use of getch() function.
#include<time.h>        // Used to generate seed (or use the time_t data type) 
                        // for random number generation.

#include"TicTacToe.h"       // Tic Tac Toe Game
#include"GuessTheNumber.h"      // Guess the Number Game

int main()
{
    for (;;){               // infinite loop
        system("cls");      // Clears screen
        int choice;
        printf("Choose which game you want to play:\n1) Tic Tac Toe\n2) Guess the Number\n3) Exit\nChoice : ");
        scanf("%d",&choice);

    
        switch (choice){
        case 1: {
            TicTacToe();        // Enter 1 to play Tic Tac Tio.
            break;
        }
        case 2:{
            GuessTheNumber();       // Enter 2 to play Guess the Number game.
            break;
        }
        case 3:{
            exit(0);        // Exits the infinite loop
            break;
        }
        default:
            printf("Invalid Selection!\n\n");       // Prints the following message when any other 
                                                    // input is given by the user.
            getch();
            break;
        }
    }
    return 0;
}

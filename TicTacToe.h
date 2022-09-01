
/*
Author : Jasjeet Singh (UE218049)
Date : 19th July 2022
Purpose : Tic Tac Toe Game
Libraries Used : <stdio.h>,  <stdlib.h>,  <conio.h>
*/

void reassign();
void showBoard(int);
void takeValue(int);
int checkForWin(int);

// Global variables
char grid[10];      
// Note that index '0' remains unused throughout the
// program for the sake of simplicity.

const char player1 = 'X';
const char player2 = 'O';

void TicTacToe()
{
    reassign();

    for (int i = 0; i < 9; i++)     // maximum nine moves can be played in this game.
    {
        int result;

        showBoard(i);        
        // This function prints the board every round with updated details.
        takeValue(i);        
        // This function is reponsible for input and error checking of values.
        result = checkForWin(i);

        if (i==8 || result == 1){
            showBoard(i);
        }
        
        if (result == 1)        
        // Prints the Win message for each player (if the player has won) dynamically.
        {
            printf("\n%s has won the game!",i%2==0 ? "Player 1" : "Player 2");
            printf("\nPress any key to continue.");
            getch();            // Gets character input from the user.
            break;              // Exits the for loop as the game is won already.
        }
        else if (result == -1)
        {
            printf("\nDraw!");      
            // Prints out draw when both players run out of options.
            printf("\nPress any key to continue.");
            getch();
        }
                         
    }
}

// This function reassigns the grid to int values if the user wants
// to play Tic Tac Toe again otherwise the game will show previous results.
void reassign(){            
    char c = '1';
    for (int i = 1; i <= 10; i++){
        grid[i] = c;                
        c++;
    }
}

void showBoard(int i)
{
    system("clear");            
    // Clears the whole screen so as to show updated data.

    // Printing of whole interface begins.
    printf("\nTic Tac Toe ");
    printf("\n___________");
    printf("\n\nPlayer 1 (X) vs Player 2 (O)\n\n");

    // Interface code
    printf("\n    |     |");
    printf("\n%c   |  %c  |  %c", grid[1],grid[2],grid[3]);
    printf("\n____|_____|____");
    printf("\n    |     |");
    printf("\n%c   |  %c  |  %c", grid[4],grid[5],grid[6]);
    printf("\n____|_____|____");
    printf("\n    |     |");
    printf("\n%c   |  %c  |  %c", grid[7],grid[8],grid[9]);
    printf("\n    |     |\n");

    // Dynamically tells the users that who's turn is it now.
    if (i%2==0)
        printf("\nPlayer 1's (X) turn : ");
    else
        printf("\nPlayer 2's (O) turn : ");
}

void takeValue(int i)
{
    int location;
    for(;;)
    {
        printf("\nPlease enter where you want to place your choice on the board : ");
        scanf("%d",&location);

        // Checking the location to see if the slot is already 
        // filled or not or if location entry is correct or not.

        if ( (grid[location] == 'X') || (grid[location] == 'O') || location>9 || location<1 ){
            printf("\nInvalid selection.");
        }
        else        
        // This else block assigns the X or O to the given location or choice.
        {
            grid[location] = i%2==0 ? player1 : player2;        
            // This logic decides which players turn is it so it can appropriately 
            // assign X or O to the location.
            break;
        }
    }
}

int checkForWin(int i)
{
    int returnValue = 0;
    
    if (   // Horizonatal Wins
           grid[1]==grid[2] && grid[2]==grid[3]   
        || grid[4]==grid[5] && grid[5]==grid[6] 
        || grid[7]==grid[8] && grid[8]==grid[9]
           // Vertical Wins 
        || grid[1]==grid[4] && grid[4]==grid[7]  
        || grid[2]==grid[5] && grid[5]==grid[8]  
        || grid[3]==grid[6] && grid[6]==grid[9]
           // Diagonal Wins   
        || grid[1]==grid[5] && grid[5]==grid[9]  
        || grid[3]==grid[5] && grid[5]==grid[7]  
        )           
        returnValue = 1;
    else if (i==8)
        returnValue = -1; 
    
    return (returnValue);
}

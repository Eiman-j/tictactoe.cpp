#include <iostream>
using namespace std;

//global variables and array to be accessed in the entire code

char space[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
//character array to store values displayed on the grid

string playerOne, playerTwo;            //the names of the players

int row, column;                        //array location variables to be edited as the game progresses

char symbol='x';                        //initial value of the symbol is equal to the symbol of player 1 

bool draw=false;                        //boolean variable for the declaration of a draw

void displayGrid()                      //function to display the tictactoe grid when called in main
{
    cout<<"  "<<space[0][0]<<"|  "<<space[0][1]<<"|  "<<space[0][2]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"  "<<space[1][0]<<"|  "<<space[1][1]<<"|  "<<space[1][2]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<"  "<<space[2][0]<<"|  "<<space[2][1]<<"|  "<<space[2][2]<<endl;
    
    //numbers displayed for players to easily select their box location
}
void gameProgress()                     //function that asks the grid location, updates values of row and column
{                                       //checks if the box is empty 
    int gridNumber;                     //if box is not empty, calls itself again to take input of the user again
    if(symbol=='x')                     //updates the value of symbol after each turn
    {
        cout<<playerOne<<" please select a box:  "<<endl;
        cin>>gridNumber;
    }
    if(symbol=='o')
    {
        cout<<playerTwo<<" please select a box:  "<<endl;
        cin>>gridNumber;
    }

    switch(gridNumber)
    {
        case 1:
        row=0;
        column=0;
        break;
        case 2:
        row=0;
        column=1;
        break;
        case 3:
        row=0;
        column=2;
        break;
        case 4:
        row=1;
        column=0;
        break;
        case 5:
        row=1;
        column=1;
        break;
        case 6:
        row=1;
        column=2;
        break;
        case 7:
        row=2;
        column=0;
        break;
        case 8:
        row=2;
        column=1;
        break;
        case 9:
        row=2;
        column=2;
        break;
        default:
        cout<<"Invalid Number";
        break; 
    }
   if(symbol=='x' &&  space[row][column]!= 'x' && space[row][column]!='o')//checking if box is empty
   {
    space[row][column]='x';
    symbol='o';
   } 
   else if(symbol=='o' &&  space[row][column]!= 'x' && space[row][column]!='o')
   {
    space[row][column]='o';
    symbol='x';
   }
   else
   {
    cout<<"There's no empty space available!"<<endl;
    gameProgress();         //call the function again
   }
}
bool check()                //to check for the winner or a draw
{                           //first checks horizontal, then vertical, then both diagonals
    for(int i=0; i<3; i++)
    {
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
        {                   //checking rows and columns 
            return true;   //when it returns true, the while loop in main function ends
        }
        if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0])
        {                   //checking diagonals
            return true;
        }

    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(space[i][j]!='x'&& space[i][j]!='o')
            {
                return false;           //returning false if theres still empty spaces, game must go on
            }
        }
    }
    draw=true;      //if no matches on rows, columns or diagonals and no empty spaces then its a draw

    return true;    //so while loop ends
}
int main()
{   char answer;
    cout<<"*********************\n";
    cout<<"*****Tic Tac Toe*****\n";
    cout<<"*********************\n";
    cout<<endl;
    cout<<"Player 1 -- x\n";
    cout<<"Player 2 -- o\n";
    cout<<endl;
    cout<<"Player 1, Please enter your name:  ";
    cin>>playerOne;
    cout<<endl;
    cout<<"Player 2, Please enter your name:  ";
    cin>>playerTwo;
    cout<<endl;
    while(!check())
    {
        displayGrid();
        gameProgress();
        check();
    }
    if(symbol=='x'&& draw==false)
    {
        displayGrid();
        cout<<playerTwo<<" wins!"<<endl;
    }
    else if(symbol=='o'&& draw==false)
    {
        displayGrid();
        cout<<playerOne<<" wins!"<<endl;

    }
    else
    {
        cout<<"It's a Draw!";
    }
    cout<<"Do you want to play again?(y/n) "<<endl;
    cin>>answer;
    while(answer=='y'|| answer=='Y')        //another loop for rematch, repeats process
    {
    cout<<"*********************\n";
    cout<<"*****Tic Tac Toe*****\n";
    cout<<"*********************\n";
    cout<<endl;
    cout<<"Player 1 -- x\n";
    cout<<"Player 2 -- o\n";
    cout<<endl;
    cout<<"Player 1, Please enter your name:  ";
    cin>>playerOne;
    cout<<endl;
    cout<<"Player 2, Please enter your name:  ";
    cin>>playerTwo;
    cout<<endl;
    while(!check())
    {
        displayGrid();
        gameProgress();
        check();
    }
    if(symbol=='x'&& draw==false)
    {
        cout<<playerTwo<<" wins!"<<endl;
    }
    else if(symbol=='o'&& draw==false)
    {
        cout<<playerOne<<" wins!"<<endl;

    }
    else
    {
        cout<<"It's a Draw :p";
    }
    cout<<"Do you want to play again?(y/n) "<<endl;
    cin>>answer;
    }
}
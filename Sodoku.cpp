/***********************************************************************                                                       
* Author:                                                                       
*    Marek Swan                                                                 
* Summary:
*    This Program opens up a file with a table preset with values
*    then allows the user to make guesses and see current results.
************************************************************************/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void writeFile(char board[][9]);
void getWriteName(char fileName[]);
bool checkValue(char board[][9],int row,int col,int value);
void getCoords(char coord[2]);
void displayBoard(char board[][9]);
/**********************************************************************         
* Gets the user coords and converts the the Letter into a number
***********************************************************************/
bool checkValue(char board[][9],int row,int col,char value)
{
    displayBoard(board);
    cout << "\n in: " << value << endl;
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == value)
        return false;
        else
          cout << board[row][i]  << " != " << value << endl;
    }
    
    
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == value)
        return false;
            else
          cout << board[i][col]  << " != " << value << endl;
    }
    
    int startX = row / 3 * 3;
    int startY = col / 3 * 3;
    
    for (int i = startX; i < startX + 3; i++)
    {
        for (int j = startY; j < startY + 3; j++)
        {
            if (board[i][j] == value)            
            return false;
                else
          cout << board[i][j]  << " != " << value << endl;
q

/**********************************************************************         
* Gets the user coords and converts the the Letter into a number
***********************************************************************/
void showSquare(char gameBoard[][9])
{
    char coord[2];
    checkValue(gameBoard, 1, 1, '1');
    getCoords(coord);
      
    int row = coord[0] - '0';
  
    int col = (coord[1] - 1) - '0';
     
    int count = 1;
    bool isTrue;
    bool isFirst = true;
    char value;
    while (count < 10)
    {
        value = count + '0';
        cout << "\ndec: " << value << endl; 
        isTrue = checkValue(gameBoard, row, col, value);
        if (isTrue)
        {
            if(isFirst)
            {
                cout << count;
                isFirst = false;
            }
            
            else
            {
                cout << "," << value;
            }
        }
        count++;
    }
    
    cout << endl;
}

/**********************************************************************         
* Gets the user coords and converts the the Letter into a number
***********************************************************************/
void getCoords(char coord[2])
{
    bool correct = false;

    //while(correct == false)
    //{
        cout << "What are the coordinates of the square: ";
        cin >> coord;
        
        switch(coord[0])
        {
            case 'A':
            case 'a':
            coord[0] = '0';
            correct = true;
            break;

            case 'B':
            case 'b':
            coord[0] = '1';
            correct = true;
            break;

            case 'C':
            case 'c':
            coord[0] = '2';
            correct = true;
            break;

            case 'D':
            case 'd':
            coord[0] = '3';
            correct = true;
            break;
    
            case 'E':
            case 'e':
            coord[0] = '4';
            correct = true;
            break;

            case 'F':
            case 'f':
            coord[0] = '5';
            correct = true;
            break;

            case 'G':
            case 'g':
            coord[0] = '6';
            correct = true;
            break;

            case 'H':
            case 'h':
            coord[0] = '7';
            correct = true;
            break;

            case 'I':
            case 'i':
            coord[0] = '8';
            correct = true;
            break;
    
            default:
            cout << "ERROR: Square " << coord << " is invalid" << endl;
            break;
        }
        
    //}
}  

/**********************************************************************         
* edits the square and checks if a values exists
***********************************************************************/
void editSquare(char board[][9])
{
    bool valueChange = false;
    
    char coord[2];
    getCoords(coord);
    int x = coord[0] - '0';
    int y = (coord[1] - 1) - '0';
    
    int newVal;
    
    while (valueChange == false)
    {
        
        if (board[x][y] == ' ')
        {
            cout << "What is the value at " << "\'" << coord << "\'" << ": ";
            cin >> newVal;
            cin.ignore();
            
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "ERROR: Value " << newVal << " in square " << coord << " is invalid" << endl;
            }

            else if ( newVal > 9 || newVal < 1)
            {
                cout << "ERROR: Value " << newVal << " in square " << coord << " is invalid" << endl;
            }
            
            else
            {
                board[x][y] = newVal + 48;
                valueChange = true;
            }
        }
        
        else
        {
            cout << "ERROR: Square " << coord << " is filled" << endl;
        }
    }
}

/**********************************************************************         
* Displays the options
***********************************************************************/
void displayOptions()
{
    cout << "Options: \n"
         << "   " << "?  Show these instructions\n"
         << "   " << "D  Display the board\n"
         << "   " << "E  Edit one square\n"
         << "   " << "S  Show the possible values for a square\n"
         << "   " << "Q  Save and quit" << endl;
}

/**********************************************************************         
* Displays the board, no matter the condition.
***********************************************************************/
void displayBoard(char board[][9])
{
    cout << endl;
    cout << "   " <<  "A B C D E F G H I" << endl;
    for (int row = 0; row < 9; row++)
   {
    cout << row + 1 << " ";
    for (int col = 0; col < 9; col++)
    {
        if(board[row][col] == '0')
        {
            board[row][col] = ' ';
        }
        
        if(col == 2 || col == 5)
        {
            cout << " " << board[row][col] << "|";
        }
        else
        {
            if (col == 3 || col == 6)
            {
                cout << board[row][col];
            }
            
            else
            {
                cout << " " << board[row][col];
            }
            
        }
    }
    
    cout << endl;
    
     if (row == 2 || row == 5)
    {
        cout << "   " << "-----+-----+-----" << endl;
    }
    
  }
  cout << endl;
     
}

/**********************************************************************         
* This runs the game until the command Q is given.
***********************************************************************/
void gameLoop(char board[][9])
{
    bool endGame = false;
    char command;
    
   displayOptions(); 
   displayBoard(board);
   cout << "> ";
   
   while (endGame == false)
   {
   cin >> command;
   
   switch(command)
   {
    case 'D':
    case 'd':
    displayBoard(board);
    cout << "> ";
    break;

    case 'Q':
    case 'q':
    writeFile(board);
    endGame = true;
    break;

    case '?':
    displayOptions();
    cout << "> ";
    break;

    case 'E':
    case 'e':
    editSquare(board);
    cout << "> ";
    break;

    case 'S':
    case 's':
    showSquare(board);
    cout << "> ";
    break;
    
    case 'X':
    case 'x':
    cout << "This is the solver WIP";
    break;
    
    default:
    cout << "Invalid Command\n";
    break;
    }
   }
   
}

/**********************************************************************         
* Gets a name for the file to be written to
***********************************************************************/
void getWriteName(char fileName[])
{   
   cout << "What file would you like to write your board to: ";
   cin >> fileName;
   cin.ignore();
   return;

}

/**********************************************************************         
* creates a file and writes a file.
***********************************************************************/
void writeFile(char board[][9])
{
    char fileName[256];
    getWriteName(fileName);
    
    ofstream fout;
    
    fout.open(fileName);
    
    for (int row = 0; row < 9; row++)
    {
      for(int col = 0; col < 9; col++)
      {
        fout << board[row][col];
      }
    }
    
    fout.close();
    cout << "Board written successfully" << endl;
    return;

}

/**********************************************************************         
* reads the Filename
***********************************************************************/
int readFile(char fileName[], char board[][9])
{
    //opening the file
   int numChar = 0;
   
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file " << fileName << endl;
      return 0;
   }
   
   for (int row = 0; row < 9; row++)
    {
      for(int col = 0; col < 9; col++)
      {
        fin >> board[row][col];
      }
    }
    
    fin.close();
    return numChar;

}

/**********************************************************************         
* Gets the Filename from the User
***********************************************************************/
void getFileName(char fileName[])
{   
   cout << "Where is your board located?: ";
   cin >> fileName;
   cin.ignore();
   return;

}

/**********************************************************************         
 * Driver function and the display the results.                
***********************************************************************/
int main()
{
    // variables to hold required data
    char fileName[256];
    char board[9][9];
    
    // get the filename, open the file and save the data
    getFileName(fileName);
    readFile(fileName, board);
    
    //run the gameloop
    gameLoop(board);
    
    
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    int numRounds;
    int playerWins = 0;
	int computerWins = 0;
    system("cls");
    cout << "\n\n\n\n\t\t\tWelcome to Rock, Paper, Scissors Game!" << endl;
    cout << "\n\n\t\t\tEnter the number of rounds you want to play: ";
    cin >> numRounds;

    srand(static_cast<unsigned int>(time(0)));

    for (int round = 1; round <= numRounds; ++round) 
	{
        char playerChoice, computerChoice;
		inputchoice:
        cout << "\n\n\n\t\t\tRound " << round << " : Enter your choice (r for Rock, p for Paper, s for Scissors): ";
        cin >> playerChoice;

        // Convert playerChoice to lowercase for case-insensitive comparison
        playerChoice = tolower(playerChoice);
        
        if((playerChoice != 'r') && (playerChoice != 'p') && (playerChoice != 's'))
        {
        	cout<<"\n\t\t\tInvalid input";
        	goto inputchoice;
		}

        int computerNum = rand() % 3; // Generates a random number between 0 and 2
        switch (computerNum) 
		{
            case 0:
                computerChoice = 'r';
                break;
            case 1:
                computerChoice = 'p';
                break;
            default:
                computerChoice = 's';
        }

        cout << "\n\t\t\tComputer chose : " << computerChoice << endl;

        // Determine the winner of the round
        if ((playerChoice == 'r' && computerChoice == 's') ||(playerChoice == 'p' && computerChoice == 'r') ||(playerChoice == 's' && computerChoice == 'p')) 
		{
            cout << "\n\t\t\tYou win this round!" << endl;
            playerWins++;
        } else if (playerChoice == computerChoice) 
		{
            cout << "\n\t\t\tIt's a tie this round!" << endl;
        } else 
		{
            cout << "\n\t\t\tComputer wins this round!" << endl;
            computerWins++;
        }

        cout << endl;
    }

    // Determine the winner of the game
    if (playerWins > computerWins) 
	{
        cout << "\n\n\t\t\tCongratulations! You are the winner of the game!" << endl;
    } else if (playerWins < computerWins) 
	{
        cout << "\n\n\t\t\tSorry, the computer wins the game. Better luck next time!" << endl;
    } else 
	{
        cout << "\n\n\t\t\tIt's a tie game!" << endl;
    }

    return 0;
}


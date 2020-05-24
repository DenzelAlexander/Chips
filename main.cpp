
#include <iostream>
#include <ctime>
#include <cstdlib>

const int MAX_CHIPS = 100;
const double MAX_TURN = .5;

int main()
{

	bool player1Turn = true;
	bool gameOver = false;
	char playAgain = 'y';

	int chipsInPile = 0;
	int chipsTaken = 0;
	int maxPerTurn = 0;
	std::string playerNames[2];

	
	
	while (playAgain == 'y') {
	
	//seed the random number generator
	srand(time(0));

	gameOver = false;
	std::cout << "Player 1, enter your name: ";
	std::cin >> playerNames[0];
	std::cout << "Player 2, enter your name: ";
	std::cin >> playerNames[1];



	chipsInPile = (rand() % MAX_CHIPS) + 1;
	std::cout << "This round will start with " << chipsInPile << " chips in the pile \n";
	maxPerTurn = MAX_TURN * chipsInPile;
	
		while (gameOver == false)
		{
			do {
				if (player1Turn)
				{
					std::cout << playerNames[0] << ", How many chips would you like? \n";
				}
				else
				{
					std::cout << playerNames[1] << ", How many chips would you like? \n";
				}
				std::cout << "You can take up to ";
				if (static_cast<int>(MAX_TURN * chipsInPile) == 0)
				{
					std::cout << "1 \n";
				}
				else
				{
					std::cout << static_cast<int>(MAX_TURN * chipsInPile) << std::endl;
				}

				std::cin >> chipsTaken;

			} while (chipsTaken > (static_cast<int>(MAX_TURN * chipsInPile)) && chipsInPile > 1);

			chipsInPile = chipsInPile - chipsTaken;
			chipsTaken = (rand() & maxPerTurn) + 1;
			std::cout << "There are " << chipsInPile << " left in the pile. \n";

			if (chipsInPile == 0)
			{
				gameOver = true;
				if (!player1Turn)
				{
					std::cout << playerNames[0] << ", You win! \n";
				}
				else
				{
					std::cout << playerNames[1] << ", You win! \n";
				}
				
				do 
				{
					std::cout << "Play again? Press y to play again otherwise press n to end \n";
					std::cin >> playAgain;
				} while (playAgain != 'y' && playAgain != 'n' );
				
				if (playAgain == 'y') 
				{
					player1Turn = !player1Turn;
					std::cout << "\n";
				}

			}
			else
			{
				player1Turn = !player1Turn;
			}
		}
	}
	
	
	system("pause");
	return 0;
}
#include "Game.h"

int main()
{
	_mkdir("Saves");
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int selectItem = 1;
	Game game;
	game.SetTextColour(game.GetMTextColour());
	while (true)
	{
		game.OutputMainMenu(selectItem);
		
		while (!_kbhit())
			_cputs("");
		char symbol = _getch();
		if (symbol == 'w' || symbol == 'ц' || symbol == 'W' || symbol == 'Ц')
		{
			selectItem--;
			if (selectItem < minCount)
			{
				selectItem = menuItemsCount;
			}

		}
		else 
		{
			if (symbol == 's' || symbol == 'ы' || symbol == 'S' || symbol == 'Ы')
			{
				selectItem++;
				if (selectItem > menuItemsCount)
				{
					selectItem = minCount;
				}
			}
			else
			{
				if (symbol == ' ')
				{
					switch (MainMenuItems(selectItem))
					{
					case startGame:
					{
						game.StartGame(0, 0);
						break;
					}
					case loadGame:
					{
						game.LoadingGame();
						break;
					}
					case exitGame:
					{

						return 0;
					}
					default:
						break;
					}
				}
			}
		}
		Sleep(25);
		symbol = ' ';
	}
}
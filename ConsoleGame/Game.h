#include "Header.h"

class Game
{

	int mainTextColour = 15;
	int secTextColour = 9;
	int actionTextColour = 14;
	int choiceTextColour = 14;
	int errorTextColour = 12;
	int loadingTextColour = 10;
	int highlightTextColour = 13;
	int readerSpeed = 150;
	int menuStrOutputSize = 100;
	int gameStrOutputSize = 115;

public:

	int GetMTextColour()
	{
		return(mainTextColour);
	}

	int GetSTextColour()
	{
		return(secTextColour);
	}

	void SetTextColour(int colour)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)(colour));
	}

	void CheckItem(int item, MainMenuItems selectItem)
	{
		if (item == selectItem)
			SetTextColour(mainTextColour);
		else
			SetTextColour(secTextColour);
	}

	void OutputMainMenu(int selectItem)
	{
		int spliter = menuStrOutputSize;
		char splitSymbol = '—';
		system("cls");
		SetTextColour(actionTextColour);
		cout << "\n\n\n\n\n\t\tГЛАВНОЕ МЕНЮ\n";
		SetTextColour(secTextColour);
		SetTextColour(secTextColour);
		cout << "\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		cout << "\n\n";
		CheckItem(selectItem, startGame);
		cout << "\t\t\t1 - НАЧАТЬ ИГРУ\n\n";
		CheckItem(selectItem, loadGame);
		cout << "\t\t\t2 - ЗАГРУЗИТЬ ИГРУ\n\n";
		CheckItem(selectItem, exitGame);
		cout << "\t\t\t3 - ВЫХОД\n\n";
		SetTextColour(secTextColour);
		cout << "\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		cout << "\n\n";
		SetTextColour(actionTextColour);
		cout << "\t\t\tW(Ц) - Пункт вверх\n\n";
		cout << "\t\t\tS(Ы)- Пункт вниз\n\n";
		cout << "\t\t\tSpace(Пробел) - Выбрать текущий пункт\n\n";
		SetTextColour(secTextColour);
		cout << "\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		cout << "\n\n";
	}

	void OutputSymbols(int spliter, char symbol, int mode)
	{
		for (int i = 0; i < spliter; i++)
		{
			cout << symbol;
			if (mode == 1)
			{
				Sleep(1);
			}
		}
	}

	void OutputByLinesT(string* mas, int currentStr)
	{
		int count = 0;
		int currentSym = 0;
		int spliter = gameStrOutputSize;
		cout << "\n\t\t";
		for (int i = 0; i < mas[currentStr].size(); i++)
		{
			if (count < spliter)
			{
				switch (mas[currentStr][currentSym])
				{
				case '*':
				{
					cout << "\n\n\t\t";
					count = 0;
					break;
				}
				case '#':
				{
					cout << "\n\t\t";
					count = 0;
					break;
				}
				case '<':
				{
					SetTextColour(highlightTextColour);
					break;
				}
				case '>':
				{
					SetTextColour(mainTextColour);
					break;
				}

				default:
					cout << mas[currentStr][currentSym];
					
					count++;
					break;
				}
				currentSym++;
				Sleep(1);
			}
			else
			{
				cout << "\n\t\t";
				count = 0;
			}
		}
	}

	void OutputByLinesQ(string* mas, int currentStr)
	{
		int count = 0;
		int currentSym = 0;
		int spliter = gameStrOutputSize;
		cout << "\n\t\t";
		for (int i = 0; i < mas[currentStr].size(); i++)
		{
			if (count < spliter)
			{
				if (isdigit(mas[currentStr][currentSym]))
				{
					SetTextColour(choiceTextColour);
					if (mas[currentStr][currentSym] != '1')
					{
						cout << "\n\n\t\t";
						count = 0;
					}
				}
				cout << mas[currentStr][currentSym];
				SetTextColour(mainTextColour);
				currentSym++;
				count++;
				Sleep(1);
			}
			else
			{
				cout << "\n\t\t";
				count = 0;
			}
		}
	}

	void OutputByLines(string str)
	{
		int count = 0;
		int currentSym = 0;
		int spliter = gameStrOutputSize;
		cout << "\n\t\t";
		for (int i = 0; i < str.size(); i++)
		{
			if (count < spliter)
			{
				cout << str[currentSym];
				currentSym++;
				count++;
				Sleep(1);
			}
			else
			{
				cout << "\n\t\t";
				count = 0;
			}
		}
	}

	void OutputByLines(string str, int sleepTime)
	{
		int count = 0;
		int currentSym = 0;
		int spliter = menuStrOutputSize;
		cout << "\n\t\t";
		for (int i = 0; i < str.size(); i++)
		{
			if (count < spliter)
			{
				cout << str[currentSym];
				currentSym++;
				count++;
				Sleep(sleepTime);
			}
			else
			{
				cout << "\n\t\t";
				count = 0;
			}
		}
	}

	void OutputText(string* masText, string* masQuestion, int currentStr)
	{
		int spliter = gameStrOutputSize;
		char splitSymbol = '—';
		SetTextColour(secTextColour);
		cout << "\n\n\n\n\n\n\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		SetTextColour(mainTextColour);
		cout << "\n\t\t";
		OutputByLinesT(masText, currentStr);
		SetTextColour(secTextColour);
		cout << "\n\n\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		SetTextColour(mainTextColour);
		cout << "\n\t\t";
		OutputByLinesQ(masQuestion, currentStr);
		SetTextColour(secTextColour);
		cout << "\n\n\t\t";
		OutputSymbols(spliter, splitSymbol, menuMode);
		SetTextColour(actionTextColour);
		cout << "\t\t";
		OutputByLines("Ваше действие: ");
		SetTextColour(mainTextColour);
	}

	void Help()
	{
		SetTextColour(secTextColour);
		cout << "\n\n\n\n\n\n\t\tСписок команд:\n";
		SetTextColour(mainTextColour);
		cout << "\n\t\t1)Save/Сохранение = Сохранить текущую игру;\n";
		cout << "\n\t\t2)Load/Загрузка = Загрузить игру;\n";
		cout << "\n\t\t3)Rules/Правила = Вывести список правил;\n";
		cout << "\n\t\t4)Help/Помошь = Вывести список команд;\n";
		cout << "\n\t\t5)Retry/Заново = Начать игру заново;\n";
		cout << "\n\t\t6)Exit/Выход = Выйти из игры.\n";
		SetTextColour(secTextColour);
		cout << "\n\t\tПримечания:\n";
		SetTextColour(mainTextColour);
		cout << "\n\t\t1)Регистр текста при вводе команд можно не учитывать;\n";
		cout << "\n\t\t2)Для распознавания команд не требуется никакого специального символа.\n\n\t\t";
	}

	void Rules()
	{
		SetTextColour(secTextColour);
		cout << "\n\n\n\n\n\n\t\tПринцип игры в текстовый квест:\n";
		SetTextColour(mainTextColour);
		cout << "\n\t\t1)Вам выводится информация о текущей ситуации;\n";
		cout << "\n\t\t2)Вам выводятся варианты действий в данной ситуации;\n";
		cout << "\n\t\t3)Вы выбираете наиболее подходящий по вашему мнению вариант в данной ситуации;\n";
		cout << "\n\t\t4)Происходит переход в другую ситуацию или продолжается описание предыдущей;\n";
		cout << "\n\t\t5)Всё это повторяется до конца игры.\n";
		SetTextColour(secTextColour);
		cout << "\n\t\tПравила игры:\n";
		SetTextColour(mainTextColour);
		cout << "\n\t\t1)Выбор осуществляется лишь из предложенных вариантов;\n";
		cout << "\n\t\t2)Выбор осуществляет цифрами;\n";
		cout << "\n\t\t3)Для использования команд используются ключевые слова.\n\n\t\t";
	}

	void CommandProcessing(string commandStr, int currentStr)
	{
		if (commandStr == "HELP" || commandStr == "ПОМОЩЬ")
		{
			system("cls");
			Help();
			system("pause");
			system("cls");
		}
		else
		{
			if (commandStr == "SAVE" || commandStr == "СОХРАНЕНИЕ")
			{
				system("cls");
				SetTextColour(actionTextColour);
				cout << "\n\n\n\n\n\n\t\tВведите название сохранения: ";
				string fileName;
				SetTextColour(mainTextColour);
				getline(cin, fileName);
				ofstream writeFile;
				writeFile.open("Saves/" + fileName + ".txt");
				writeFile << currentStr;
				writeFile.close();
				system("cls");
				SetTextColour(secTextColour);
				cout << "\n\n\n\n\n\n\t\tУспешное сохранение файла (" << fileName << ".txt)\n\n\t\t";
				SetTextColour(mainTextColour);
				system("pause");
				system("cls");
			}
			else
			{
				if (commandStr == "EXIT" || commandStr == "ВЫХОД")
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\tВыход в главное меню\n\t\t";
				}
				else
				{
					if (commandStr == "RETRY" || commandStr == "ЗАНОВО")
					{
						system("cls");
						string str = "0";
						int choice = 0;
						SetTextColour(secTextColour);
						cout << "\n\n\n\n\n\n\t\tВы точно хотите начать заново? (1 - да, 2 - нет)";
						SetTextColour(actionTextColour);
						cout << "\n\n\t\tВаше действие:";
						SetTextColour(mainTextColour);
						getline(cin, str);
						SetTextColour(secTextColour);
						choice = atoi(str.c_str());
						SetTextColour(mainTextColour);
						if (choice == 1)
						{
							system("cls");
							SetTextColour(secTextColour);
							cout << "\n\n\n\n\n\n\t\tНачатие новой игры\n\n\t\t";
							SetTextColour(mainTextColour);
							system("pause");
							this->StartGame(0, 0);
						}
						else
						{
							if (choice == 2)
							{
								system("cls");
								SetTextColour(secTextColour);
								cout << "\n\n\n\n\n\n\t\tВозвращение в игру\n\n\t\t";
								SetTextColour(mainTextColour);
								system("pause");
								system("cls");
							}
							else
							{
								system("cls");
								SetTextColour(errorTextColour);
								cout << "\n\n\n\n\n\n\t\tНеверная командаm, возвращение в игру\n\n\t\t";
								SetTextColour(mainTextColour);
								system("pause");
								system("cls");
							}
						}
					}
					else
					{
						if (commandStr == "RULES" || commandStr == "ПРАВИЛА")
						{
							system("cls");
							Rules();
							system("pause");
							system("cls");
						}
						else
						{
							if (commandStr == "LOAD" || commandStr == "ЗАГРУЗКА")
							{
								LoadingGame();
								system("cls");
							}
							else
							{
								system("cls");
								SetTextColour(errorTextColour);
								cout << "\n\n\n\n\n\n\t\tИзвините, такой команды не существует, попробуйте ещё раз\n\n\t\t";
								SetTextColour(mainTextColour);
								system("pause");
								system("cls");
							}	
						}
					}
				}
			}
		}
	}

	bool IsNumber(string str)
	{
		bool isNumber = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (!isdigit(str[i]))
			{
				isNumber = false;
				break;
			}
		}
		return isNumber;
	}

	void Loading()
	{
		SetTextColour(secTextColour);
		cout << "\n\n\n\n\n\n\t\tПожалуйста подождите, пока идёт загрузка\n\t\t";
		SetTextColour(loadingTextColour);
		OutputByLines("- - - - - - - - - - - - - - - - - - - - ", 25);
		Sleep(timeLoading);
		system("cls");
	}

	void StartGame(int currentStr, int targetStr)
	{
		system("cls");
		ifstream readFile;
		string fileName;
		readFile.open("Game.txt");
		if (!readFile)
		{
			SetTextColour(errorTextColour);
			cout << "\n\n\n\n\n\n\t\tОшибка: Не удалось открыть файл Game.txt\n\t\t";
			SetTextColour(mainTextColour);
		}
		else
		{
			string commandStr = "";
			char* reader = new char[readerSize];
			int typeString = minCount;
			int commandInt = 0;
			int count = 0;

			while (!readFile.eof())
			{
				readFile.getline(reader, readerSize, '\n');
				count++;
			}

			readFile.close();
			readFile.open("Game.txt");
			delete[] reader;
			string symbol = " ";
			string* masStr = new string[count];
			string* masText = new string[count];
			string* masQuestion = new string[count];
			string* masWays = new string[count];
			int i = 0;

			while (!readFile.eof())
			{
				getline(readFile, masStr[i], '\n');
				i++;
			}

			for (int j = 0; j < count; j++)
			{
				for (int k = 0; k < masStr[j].size(); k++)
				{
					symbol = masStr[j][k];
					if (symbol == splitSymbol)
					{
						typeString++;
					}

					switch (StringType(typeString))
					{
					case text:
					{

						if (symbol != splitSymbol)
							masText[j] += symbol;
						break;
					}
					case question:
					{
						if (symbol != splitSymbol)
							masQuestion[j] += symbol;
						break;
					}
					case ways:
					{
						if (symbol != splitSymbol)
							masWays[j] += symbol;
						break;
					}
					default:
					{
						if (typeString > stringTypeCount)
						{
							if (j % readerSpeed == 0)
							{
								Loading();
							}
							typeString = minCount;
						}
						break;
					}
					}
				}
			}

			transform(commandStr.begin(), commandStr.end(), commandStr.begin(), toupper);
			SetTextColour(secTextColour);
			OutputByLines("\n\n\n\n\n\n\t\tДанная игра была написана одним человеком в течении четырёх или пяти дней для сдачи курсового проекта и может содеражать критические ошибки или недочёты.  ", 0);
			SetTextColour(mainTextColour);
			OutputByLines("\n\n\t\tЕсли вы не знакомы с принципом игры в тектовые квесты, ознакомиться с ними можно прописав одну из следующих команд:\n\n", 0);
			SetTextColour(choiceTextColour);
			OutputByLines("1) Rules\n", 0);
			OutputByLines("2) Правила\n", 0);
			SetTextColour(mainTextColour);
			OutputByLines("Для просмотра всех доступных команд пропишите одну из следующих команд:\n", 0);
			SetTextColour(choiceTextColour);
			OutputByLines("1) Help\n", 0);
			OutputByLines("2) Помощь\n", 0);
			SetTextColour(highlightTextColour);
			OutputByLines("Приятной вам игры <3 <3 <3\n\n\t\t", 0);
			SetTextColour(mainTextColour);
			system("pause");
			system("cls");
			OutputText(masText, masQuestion, currentStr);
			while (commandStr != "EXIT" && commandStr != "ВЫХОД")
			{
				getline(cin, commandStr);
				if (IsNumber(commandStr))
				{
					commandInt = atoi(commandStr.c_str());
					int countChoise = 0;
					bool nextNum = false;
					string number = "";
					string bufStr;
					for (int i = 0; i < masWays[currentStr].size(); i++)
					{
						if (isdigit(masWays[currentStr][i]))
						{
							number += masWays[currentStr][i];
							if (nextNum == false)
							{
								countChoise++;
								nextNum = true;
							}
						}
						else
						{
							Sleep(1);
							number = "";
							nextNum = false;
						}
					}
					if (countChoise != 0)
					{
						int* masChoice = new int[countChoise];
						int l = 1;

						for (int i = 0; i < masWays[currentStr].size(); i++)
						{
							if (isdigit(masWays[currentStr][i]))
							{
								number += masWays[currentStr][i];
								if (nextNum == false)
								{
									nextNum = true;
								}
							}
							else
							{
								masChoice[l] = atoi(number.c_str());
								l++;
								Sleep(1);
								number = "";
								nextNum = false;
							}
						}
						system("cls");
						if (commandInt > 0 && commandInt <= countChoise)
						{
							targetStr = masChoice[commandInt];
							currentStr = targetStr;
							OutputText(masText, masQuestion, currentStr);
							SetTextColour(mainTextColour);
						}
						else
						{
							SetTextColour(errorTextColour);
							cout << "\n\n\n\n\n\n\t\tВарианта выбора под таким номером не существует.\n\n\t\t";
							SetTextColour(mainTextColour);
							system("pause");
							system("cls");
							OutputText(masText, masQuestion, currentStr);
						}
					}
					else
					{
						system("cls");
						string str = "0";
						int choice = 0;
						SetTextColour(mainTextColour);
						cout << "\n\n\n\n\n\n\t\tКонец игры";
						cout << "\n\t\tВы хотите начать игру заново? (1 - да, 2 - нет)";
						SetTextColour(actionTextColour);
						cout << "\n\n\t\tВаше действие:";
						SetTextColour(mainTextColour);
						getline(cin, str);
						SetTextColour(secTextColour);
						choice = atoi(str.c_str());
						SetTextColour(mainTextColour);
						if (choice == 1)
						{
							system("cls");
							cout << "\n\n\n\n\n\n\t\tНачатие новой игры\n\n\t\t";
							system("pause");
							this->StartGame(0, 0);
						}
						else
						{
							if (choice == 2)
							{
								system("cls");
								cout << "\n\n\n\n\n\n\t\tВыход в меню\n\n\t\t";
								system("pause");
								return;
								system("cls");
							}
							else
							{
								system("cls");
								SetTextColour(errorTextColour);
								cout << "\n\n\n\n\n\n\t\tНеверная команда, возвращение назад\n\n\t\t";
								SetTextColour(mainTextColour);
								system("pause");
								system("cls");
								OutputText(masText, masQuestion, currentStr);
							}
						}
					}
				}
				else
				{
					transform(commandStr.begin(), commandStr.end(), commandStr.begin(), toupper);
					CommandProcessing(commandStr, currentStr);
					if (commandStr != "EXIT" && commandStr != "ВЫХОД")
					{
						OutputText(masText, masQuestion, currentStr);
					}
				}
			}
			delete[] masStr;
			delete[] masText;
			delete[] masQuestion;
			delete[] masWays;
		}
		readFile.close();
		system("pause");
	}

	void LoadingGame()
	{
		system("cls");
		ifstream readFile;
		string fileName;
		SetTextColour(actionTextColour);
		cout << "\n\n\n\n\n\n\t\tВведите название вашего сохранения: ";
		SetTextColour(mainTextColour);
		getline(cin, fileName);
		readFile.open("Saves/" + fileName + ".txt");
		if (!readFile)
		{
			system("cls");
			SetTextColour(errorTextColour);
			cout << "\n\n\n\n\n\n\t\tСохранения с таким названием не существует, возвращение назад." << "\n\n\t\t";
			SetTextColour(mainTextColour);
			cout << "\n\t\t";
			system("pause");
		}
		else
		{
			int point = 0;
			while (readFile.eof() == false)
			{
				readFile >> point;
			}
			StartGame(point, point);
		}
		readFile.close();
	}

};

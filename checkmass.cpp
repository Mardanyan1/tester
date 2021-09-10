#include <iostream>
#include <vector>
#include <Windows.h>
#include <csignal>
using namespace std;

BOOL WINAPI HandlerRoutine(DWORD type)
{
	if (type == CTRL_C_EVENT)
		return true; // false, если хочешь, чтобы завершилось

	return false;
}



int main()
{

	setlocale(LC_ALL, "RUSSIAN");
	char m, opa;
	int code, mn = 0;
	string qwer;
	cout << "введите M в диапазоне от 2 до 5 включительно " << endl;
	cin >> m;

	//signal(SIGINT,^C);
	if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		SetConsoleCtrlHandler(HandlerRoutine, 1);

		cout << "неверные данные. нажмите на любую кнопку" << endl;
		cin.clear(); // возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '^C'); // удаляем значения предыдущего ввода из входного буфера
		
		return main();
	}
	if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{

		cout << "неверные данные. нажмите на любую кнопку" << endl;
		cin.clear(); // возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
		return main();
	}
	if ((m < '2') || (m > '5'))
	{
		cout << "вы ввели данные, не подходящие условию" << endl;
		cin.clear(); // возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
		return main();
	}
	int p = m - '0';
	string** a = new string * [p];
	for (int i = 0; i < p; i++)
	{
		a[i] = new string[p];
	}
	cout << "рандом(напиши '0') или сам(напиши '1')?" << endl;
	int vibor;
	cin >> vibor;
	while (cin.fail()) // если предыдущее извлечение оказалось неудачным,
	{
		cout << "неверные данные. нажмите любую цифру" << endl;
		cin.clear(); // то возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		cout << "рандом(напиши '0') или сам(напиши '1')?" << endl;
		cin >> vibor;

	}
	while ((vibor != 1) && (vibor != 0))
	{
		cout << "слышь, ты достал неправильно вводить данные. Норм введи" << endl;
		cin >> vibor;
		if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			cout << "неверные данные. нажмите любую цифру" << endl;
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cin >> vibor;
		}
	}
	if (vibor == 0)
	{
		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					string flsh;
					flsh = 'a' + (rand() % 25);
					a[i][j] = a[i][j] + flsh;
				}
			}
		}
	}
	if (vibor == 1)
	{
		cout << "вводите поочередно слова длиной в 4 буквы" << endl;
		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
			{
				cin >> a[i][j];
				while (cin.fail()) // если предыдущее извлечение оказалось неудачным,
				{
					cout << "неверные данные. нажмите любую цифру, а потом введите нужные данные" << endl;
					cin.clear(); // то возвращаем cin в 'обычный' режим работы
					cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
					cin >> a[i][j];
				}
				qwer = a[i][j];
				if ((a[i][j].length() != 4))
				{
					cout << "длина слова должна быть равна 4 букв" << endl;
					j--;
				}
				else
				{
					for (int k = 0; k < qwer.length(); k++)
					{
						opa = qwer[k];
						int code = (int)(opa);
						if (((code < 'A') || (code > 'Z')) && ((code < 'a') || (code > 'z')))
						{
							mn++;
						}
					}
					if (mn > 0)
					{
						cout << "слово может содержать только английские буквы" << endl;
						j--;
					}
					mn = 0;
				}
			}
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int* ion = new int[p * p];
	string got;
	char sim;
	int ark = 0;
	int cccp = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			got = a[i][j];
			for (int u = 0; u < 4; u++)
			{
				sim = got.at(u);
				if ((sim == 'a') || (sim == 'e') || (sim == 'i') || (sim == 'u') || (sim == 'y') || (sim == 'o'))
				{
					ark++;
				}
			}
			ion[cccp] = ark;
			ark = 0;
			cccp++;
		}
	}
	for (int io = 0; io < p * p; io++)
	{
		for (int jo = 0; jo < p * p - 1; jo++)
		{
			if (ion[jo] > ion[jo + 1])
			{
				swap(ion[jo], ion[jo + 1]);
			}
		}
	}
	for (int yu = 0; yu < p * p; yu++)
	{
		cout << "ion[" << yu << "]=" << ion[yu] << endl;
	}
}

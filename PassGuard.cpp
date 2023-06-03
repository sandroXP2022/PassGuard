#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

void ViewPasswords()
{
	int c;
	system("cls");

	ifstream PasswordFile("passwords.dat");

	string read;

	while (getline(PasswordFile, read))
	{
		cout << read << "\n";
	}

	cout << "\n\n\nPress any key to continue...";
	cin >> c;
}

void GeneratePassword()
{
	system("cls");

	int platforms = 0;

	cout << "How many passwords do you need to generate? ";
	cin >> platforms;

	string identifier[platforms];
	string passwords[platforms];

	for (int i = 0; i < platforms; i++)
	{
		cout << "\n\n\n\tIdentify where you will use this password: ";
		cin >> identifier[i];
	}

	string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	for (int x = 0; x < platforms; x++)
	{
		string key;

		for (int i = 0; i < 16; ++i) {
			int randomIndex = rand() % characters.size();
			key += characters[randomIndex];
		}

		string generated_password = key;
		passwords[x] = generated_password;
	}

	ofstream PasswordFile("passwords.dat");

	for (int z = 0; z < platforms; z++)
	{
		system("cls");
		PasswordFile << identifier[z] << "\t\t" << passwords[z] << "\n";
	}

	string x;

	cout << "Press any key to continue...";
	cin >> x;
}

int menu()
{
	int option;
	cout << "---------------------------------------------------\n\tPassGuard 1.0\n---------------------------------------------------";
	cout << "\n\n\tSelect an option from the menu:\n\n\t1 - Generate Passwords\n\n\t2 - View Generated Passwords\n";
	cin >> option;

	return option;
}

int main()
{
	srand(time(NULL));

	while (true)
	{
		system("cls");
		int option = menu();

		if (option == 1)
		{
			GeneratePassword();
		}
		else if (option == 2)
		{
			ViewPasswords();
		}
	}
}


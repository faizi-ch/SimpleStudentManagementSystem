#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

void MainMenu();
void AddData();
void InsertData();
void DeleteData();
void SearchData();
void ModifyData();
void DisplayData();
void PrintData(int);
COORD coord = { 0, 0 }; // sets coordinates to 0,0
						//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y; // X and Y coordinates... "." is used as an access operator 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int total;

struct studentData
{
	int reg;
	char name[50];
	float gpa;
}; studentData student[50];

void main()
{
	AddData();
	

	system("pause");
}

void MainMenu()
{
	system("CLS");
	cout << "1. Add Data\n2. Insert Data\n3. Delete Data\n4. Search Data\n5. Modify Data\n6. Display Data\n0. Exit\nEnter your choice: ";
	//int c;
	//cin >> c;
	switch (_getch())
	{
	case '1':
		AddData();
		break;
	case '2':
		InsertData();
		break;
	case '3':
		DeleteData();
		break;
	case '4':
		SearchData();
		break;
	case '5':
		ModifyData();
		break;
	case '6':
		DisplayData();
		break;
	case '0':
		exit(0);
		break;
	default:
		cout << "\n\aWrong entry!!!";
		break;
	}
}
void AddData()
{
	system("CLS");
	cout << "Enter number of student you wanna add: ";
	cin >> total;
	int nn = 1;
	int tempReg;
	bool check = false;
	for (int i = 0; i < total; i++, nn++)
	{
		cout << "\nEnter registration no. of student " << nn << ": ";
		cin >> tempReg;
		//cin >> student[i].reg;
		for (int j = 0; j < total; j++)
		{
			if (tempReg == student[j].reg)
			{
				check = true;
			}
		}
		if (check)
		{
			cout << "\aRegistration number: " << tempReg << " is already in the record!";
			/*cout << "\n Enter any other registration number: ";
			cin >> student[i].reg;*/
			//MainMenu();
			cout << "\n\nPress ENTER to add again or ESCAPE to go exit.";

			char ch = _getch();
			if (ch == 13)
				InsertData();
			else if (ch == 27)
				exit(0);
		}
		else
			student[i].reg = tempReg;

		cout << "Enter name of student " << nn << ": ";
		cin >> student[i].name;
		
		
		cout << "Enter GPA of student " << nn << ": ";
		cin >> student[i].gpa;
		//cout << endl;
	}

	MainMenu();
}

void InsertData()
{
	system("CLS");
	total++;
	cout << "Where you wanna insert data? ";
	int ind;
	cin >> ind;
	
	for (int i = total - 1; i >= ind; i--)
	{
		strcpy_s(student[i + 1].name, student[i].name);
		student[i + 1].reg = student[i].reg;
		student[i + 1].gpa = student[i].gpa;
	}
	int tempReg;
	bool check = false;
	cout << "\nEnter registration no. of student: ";
	cin >> tempReg;
	//cin >> student[i].reg;
	for (int j = 0; j < total; j++)
	{
		if (tempReg == student[j].reg)
		{
			check = true;
		}
	}
	if (check)
	{
		cout << "\aRegistration number: " << tempReg << " is already in the record!";
		/*cout << "\n Enter any other registration number: ";
		cin >> student[i].reg;*/
		//MainMenu();
		cout << "\n\nPress ENTER to add again or ESCAPE to go exit.";

		char ch = _getch();
		if (ch == 13)
			InsertData();
		else if (ch == 27)
			exit(0);
	}
	else
		student[ind].reg = tempReg;

	cout << "Enter name of student: ";
	cin >> student[ind].name;
	cout << "Enter GPA of student: ";
	cin >> student[ind].gpa;

	cout << "\nNew data at " << ind<<":";
	PrintData(ind);

	cout << "\n\nPress ENTER to insert more or ESCAPE to go back to menu.";

	char ch = _getch();
	if (ch == 13)
		InsertData();
	else if (ch == 27)
		MainMenu();

}
void DeleteData()
{
	system("CLS");
	int n;
	cout << "Enter registration number of student: ";
	cin >> n;
	bool check = false;
	int ind = 0;
	for (int i = 0; i < total; i++)
	{
		if (student[i].reg == n)
		{
			check = true;
			ind = i;
		}
	}

	if (check)
	{
		cout << "\nRecord Found!";
		PrintData(ind);
		
		cout << "\nDo you wanna delete this record [y/n]:";
		if (_getch() == 'y')
		{
			total--;
			for (int i = ind; i < total - 1; i++)
			{
				strcpy_s(student[i].name, student[i + 1].name);
				student[i].reg = student[i + 1].reg;
				student[i].gpa = student[i + 1].gpa;

			}
			cout << "\nRecord deleted successfully!";
		}
		else
			MainMenu();
	}
	else
		cout << "\n\aRegistration number: " << n << " not found!";

	cout << "\n\nPress ENTER to delete more or ESCAPE to go back to menu.";

	char ch = _getch();
	if (ch == 13)
		DeleteData();
	else if (ch == 27)
		MainMenu();
}
void SearchData()
{
	system("CLS");
	int n;
	cout << "Enter registration number of student: ";
	cin >> n;
	bool check = false;
	int ind = 0;
	for (int i = 0; i < total; i++)
	{
		if (student[i].reg == n)
		{
			check = true;
			ind = i;
		}
	}

	if (check)
	{
		cout << "\nRecord Found!";
		PrintData(ind);
	}
	else
		cout << "\n\aRegistration number: " << n << " not found!";

	cout << "\n\nPress ENTER to search more or ESCAPE to go back to menu.";

	char ch = _getch();
	if (ch == 13)
		SearchData();
	else if (ch == 27)
		MainMenu();

}
void ModifyData()
{
	system("CLS");
	int n;
	cout << "Enter registration number of student: ";
	cin >> n;
	bool check = false;
	int ind = 0;
	for (int i = 0; i < total; i++)
	{
		if (student[i].reg == n)
		{
			check = true;
			ind = i;
		}
	}

	if (check)
	{
		cout << "\nRecord Found!";
		PrintData(ind);	

		cout << "\nWhat you want to modify?\n1. Name\n2. Registration Number\n3. GPA\n";
		char c = _getch();
		if (c == '1')
		{
			char newName[50];
			cout << "\n\nEnter new  name: ";
			cin >> newName;
			
			strcpy_s(student[ind].name, newName);
			system("CLS");
			cout << "\nRecord modified successfully!\n";

			PrintData(ind);
		}
		else if (c == '2')
		{
			int newReg;
			cout << "\n\nEnter new registration number: ";
			cin >> newReg;

			student[ind].reg = newReg;
			system("CLS");
			cout << "\nRecord modified successfully!\n";

			PrintData(ind);
		}
		else if (c == '3')
		{
			int newGPA;
			cout << "\n\nEnter new GPA: ";
			cin >> newGPA;

			student[ind].reg = newGPA;
			system("CLS");
			cout << "\nRecord modified successfully!\n";

			PrintData(ind);
		}
		else
			MainMenu();
	}
	else
		cout << "\n\aRegistration number: " << n << " not found!";

	cout << "\n\nPress ENTER to modify more or ESCAPE to go back to menu.";

	char ch = _getch();
	if (ch == 13)
		ModifyData();
	else if (ch == 27)
		MainMenu();
}
void DisplayData()
{
	int j = 6;
	system("CLS");
	gotoxy(28, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENTS LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(27, 4);
	printf("  ID   |         NAME         |  REGISTRATION NO.  |    GPA    |");
	gotoxy(28, 5);
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	for (int i = 0; i < total; i++, j++)
	{
		gotoxy(28, j);
		cout << "  " << i;
		gotoxy(34, j);
		cout << "| " << student[i].name;
		gotoxy(57, j);
		cout << "| " << student[i].reg;
		gotoxy(78, j);
		cout << "| " << student[i].gpa;
		gotoxy(90, j);
		cout << "|";
	}
	gotoxy(28, j + 1);
	cout << "Total students: " << total;
	gotoxy(57, j + 1);
	printf("Press ENTER to return to Main Menu");
	if (_getch())
		MainMenu();
}
void PrintData(int num)
{
	cout << "\n=========================\n";
	cout << "Student Name: " << student[num].name;
	cout << "\nRegistration Number: " << student[num].reg;
	cout << "\nGPA: " << student[num].gpa;
	cout << "\n=========================\n";
}








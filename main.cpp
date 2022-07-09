#include<iostream>
#include<fstream>
using namespace std;
int rows;
void file_main(char*& str1, char*& str2);
void manual_main(char*& str1, char*& str2);
char* memory_deallocation(char* str);
char** get_tokens(char* str);
int str_len(char* str);
void concatenate(char*& str1, char* str2);
char** inverse_tokens(char* str);
void display(char**temp);
char* reverse(char* ca);

int main()
{
	int choice;
	char* str1;
	char* str2;
	do {
		system("cls");
		cout << "\tWelcome To Dynamic String Manipulation\n";
		cout << "\t\tPress (1) For File Input\n";
		cout << "\t\tPress (2) For Manual Input\n";
		cout << "\t\tPress (3) For Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			file_main(str1, str2);
			break;
		case 2:
			manual_main(str1, str2);
			break;
		case 3:
			cout << "Exited Successfully\n";
			break;
		default:
			cout << "Invalid Input\n";
			system("pause");
			break;
		}
	} while (choice != 3);
}
void file_main(char*& str1, char*& str2)
{
	char** tokens;
	char* temp;
	int choice, option;
	int size;
	string filename;
	system("cls");
		cout << "\tWelcome To File Input Main\n";
		cout << "\t\tEnter filename of the input data file (format-> filename.txt)\n";
		cin >> filename;
		ifstream fin(filename);
		if (!fin)
		{
			cout << "No such file found\n";
			system("pause");
			main();
		}
		else
		{
		    fin >> size;
            str1 = new char[size];
            str2 = new char[size];
            for (; !fin.eof();)
            {
	           fin.ignore();
               fin.getline(str1, size, ',');
	           fin.getline(str2, size);
            }
		}
		do{
		cout << "\t\tEnter (1) For Concatenation\n";
		cout << "\t\tEnter (2) To Get Tokens(words)\n";
		cout << "\t\tEnter (3) To Get Inverse Tokens(words)\n";
		cout << "\t\tEnter (4) To Reverse The Words In A String\n";
		cout << "\t\tEnter (5) To Return To Previous Main\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			concatenate(str1, str2);
			cout << str1 << endl;
			system("pause");
			break;
		case 2:
			cout << "Press 1 For string 1 \ 2 For string 2\n";
			cin >> option;
			if (option == 1)
			{
				tokens = get_tokens(str1);
				display(tokens);
			}
			else if (option == 2)
			{
				tokens = get_tokens(str2);
				display(tokens);
			}
			else {
			}
			system("pause");
			break;
		case 3:
			cout << "Press 1 For string 1 / 2 For string 2\n";
			cin >> option;
			if (option == 1)
			{
				tokens = inverse_tokens(str1);
				display(tokens);
			}
			else if (option == 2)
			{
				tokens = inverse_tokens(str2);
				display(tokens);
			}
			else {
			}
			system("pause");
			break;
		case 4:
			cout << "Press 1 For string 1 / 2 For string 2\n";
			cin >> option;
			if (option == 1)
			{
				temp = reverse(str1);
			}
			else if (option == 2)
			{
				temp = reverse(str2);
			}
			else
			{
			}
			system("pause");
			break;
		case 5:
			main();
			break;
		default:
			cout << "Invalid Input\n";
			break;
		}
	} while (choice!=4);
}
void manual_main(char*& str1, char*& str2)
{
	system("cls");
	int size, choice, option;
	cout << "\tWelcome To Manual Input Main\n";
	cout << "\t\tEnter size for Dynamic strings\n";
	cin >> size;
	str1 = new char[size];
	str2 = new char[size];
	char** tokens;
	char* temp;
	cout << "\t\tEnter for String 1\n";
	cin.ignore();
	cin.getline(str1, size);
	cout << "\t\tEnter for String 2\n";
	cin.getline(str2, size);
	str1 = memory_deallocation(str1);
	str2 = memory_deallocation(str2);
	do{
	cout << "\t\tEnter (1) For Concatenation\n";
	cout << "\t\tEnter (2) To Get Tokens(words)\n";
	cout << "\t\tEnter (3) To Get Inverse Tokens(words)\n";
	cout << "\t\tEnter (4) To Reverse The Words In A String\n";
	cout << "\t\tEnter (5) To Return To Previous Main\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		concatenate(str1, str2);
		cout << str1<<endl;
		system("pause");
		break;
	case 2:
		cout << "Press 1 For string 1 \ 2 For string 2\n";
		cin >> option;
		if (option == 1)
		{
			tokens = get_tokens(str1);
			display(tokens);
		}
		else if (option == 2)
		{
			tokens = get_tokens(str2);
			display(tokens);
		}
		else {
		}
		system("pause");
		break;
	case 3:
		cout << "Press 1 For string 1 \ 2 For string 2\n";
		cin >> option;
		if (option == 1)
		{
			tokens = inverse_tokens(str1);
			display(tokens);
		}
		else if (option == 2)
		{
			tokens = inverse_tokens(str2);
			display(tokens);
		}
		else {
		}
		system("pause");
		break;
	case 4:
		cout << "Press 1 For string 1 / 2 For string 2\n";
		cin >> option;
		if (option == 1)
		{
			temp = reverse(str1);
			cout << temp;
		}
		else if (option == 2)
		{
			temp = reverse(str2);
			cout << temp;
		}
		else
		{
		}
		system("pause");
		break;
	case 5:
		main();
		break;
	default:
		cout << "Invalid Input\n";
		break;
	}
	} while (choice != 4);
}
int str_len(char* str)
{
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}
char* memory_deallocation(char* str)
{
	int length = str_len(str);
	char* temp = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = '\0';
	delete[]str;
	return temp;
}
void concatenate(char*& str1, char* str2)
{
	int size = str_len(str1);
	int size2 = str_len(str2);
	int j, b = 0, totalsize = size + size2 + 2;

	char* temp = new char[totalsize + 1];
	int count = 0;
	for (int i = 0; str1[i] != '\0'; i++)
	{
		temp[i] = str1[i];
	}
	temp[size] = ' ';
	for (j = size + 1; str2[b] != '\0'; j++, b++)
	{
		temp[j] = str2[b];
	}
	temp[j] = '\0';
	delete[]str1;
	str1 = temp;
}
char** get_tokens(char* string1)
{
	int count = 0;
	for (int i = 0; string1[i] != '\0'; i++)
	{
		if (string1[i] == ' ')
		{
			count++;
		}
	}
	rows = count + 1;
	char** temp = new char* [count + 1];
	int b = 0;
	int k = 0;
	for (int i = 0; i < count + 1; i++)            //since input string size is 20
	{
		int counter = 0;
		temp[i] = new char[10];
		for (int j = 0; string1[j] != '\0'; j++)
		{
			if (string1[b] != ' ')
			{
				temp[i][j] = string1[b];
				b++;
				counter++;
			}
			if (string1[j + 1] == ' ')
			{
				b = b + 1;
				temp[i][j + 1] = '\0';
				break;
			}
			temp[i][j + 1] = '\0';
		}
	}
	return temp;
}
char** inverse_tokens(char* string1)
{
	int count = 0;
	for (int i = 0; string1[i] != '\0'; i++)
	{
		if (string1[i] == ' ')
		{
			count++;
		}
	}
	rows = count + 1;
	char** temp = new char* [count + 1];
	int b = 0;
	int k = 0;
	for (int i = count; i >= 0; i--)            //since input string size is 20
	{
		int counter = 0;
		temp[i] = new char[10];
		for (int j = 0; string1[j] != '\0'; j++)
		{
			if (string1[b] != ' ')
			{
				temp[i][j] = string1[b];
				b++;
				counter++;
			}
			if (string1[j + 1] == ' ')
			{
				b = b + 1;
				temp[i][j + 1] = '\0';
				break;
			}
			temp[i][j + 1] = '\0';
		}
	}
	return temp;
}
void display(char**temp)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; temp[i][j] != '\0'; j++)
		{
			cout << temp[i][j];
		}
		cout << '\n';
	}
}
char* reverse(char* ca)
{
	char* rev = new char[strlen(ca) + 1];
	int i = strlen(ca);
	int m = 0;
	while (ca[i] != '\0' && i < strlen(ca))
		i++;
	for (int j = 0; j < i; j++)
	{
		if (ca[j] == ' ') {
			rev[i - 1 - j] = ca[m];
			m++;
		}
		if (ca[j + 1] == '\0' || ca[j + 1] == ' ')
		{
			int n = m;
			for (int k = 0; k <= j - n; k++, m++)
				rev[i - 1 - j + k] = ca[m];
		}
	}
	rev[i] = '\0';
	return rev;
}
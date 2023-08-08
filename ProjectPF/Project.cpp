#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
const int row = 4, col = 6;
void Welcome();
void menu();
void dataFile(int*);
bool fullFieldChecker(const int[][col], int);
bool inserter(int[][col], int);
int numOfFilledLoc(int*);
bool once_more();
int fieldSelector();
bool emptyFieldChecker(const int[][col], int);
bool deleter(int[][col], int);
void displayField();
int valueChecker();
int optionChecker(int);
int valueSearcher(int*, int, int);
void shiftValues(int*, int);
void maxOccurs(int*);
float calAverageScore(int*);
void maxFieldsScore(int[][col]);
void display(int*);
void saveChanges(int[][col]);
void Ending();
int main()
{
	system("COLOR E4");
	Welcome();
	int fields[row][col], fieldNo{};
	bool flag{}, flag1{};
	dataFile(*fields);
	if (numOfFilledLoc(*fields) != 0)
	{
		cout << "\n\n\n\t\t\t\t\t   ";
		cout << "*******************************" << endl << "\t\t\t\t\t   ";
		cout << "* Press \'1\' to use File Data. *" << endl << "\t\t\t\t\t   ";
		cout << "* Press \'2\' for New One.      *" << endl << "\t\t\t\t\t   ";
		cout << "*******************************" << endl;
		if (2 == optionChecker(2))
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
					fields[i][j] = -1;
			}
		}
	}
	else
		Sleep(1000);
	system("cls");
	do
	{
		menu();
		switch (optionChecker(7))
		{
		case 1:
			if (numOfFilledLoc(*fields) != row*col)
			{
				do
				{
					cout << endl << "In which field you want to enter the Test value:	" << endl;
					fieldNo = fieldSelector(), flag = false;
					while (fullFieldChecker(fields, fieldNo - 1) ? flag1 = 1, inserter(fields, fieldNo - 1) ? true : false : !(flag = 1));
					if (flag)
					{
						cout << "---------------------------" << endl;
						cout << "|Sorry! the field is full.|" << endl;
						cout << "---------------------------" << endl;
					}
					if (24 == numOfFilledLoc(*fields))
						break;
					cout << endl << "Do you want to add test values in another field?" << endl;
				} while (once_more());
			}
			else
			{
				cout << "-----------------------------" << endl;
				cout << "|Sorry! All fields are full.|" << endl;
				cout << "-----------------------------" << endl;
				cout << endl << "If you want to add more then first delete previously entered test values." << endl;
			}
			break;
		case 2:
			cout << "						*******" << endl;
			cout << "The total number of filled locations is/are:	  " << numOfFilledLoc(*fields) << endl;
			cout << "						*******" << endl;
			break;
		case 3:
			if (numOfFilledLoc(*fields))
			{
				do
				{
					cout << endl << "From which field you want to delete the Test value:	" << endl;
					fieldNo = fieldSelector(), flag = false;
					while (emptyFieldChecker(fields, fieldNo - 1) ? flag1 = 1, deleter(fields, fieldNo - 1) ? true : false : !(flag = 1));
					if (flag)
					{
						cout << "----------------------------" << endl;
						cout << "|Sorry! the field is empty.|" << endl;
						cout << "----------------------------" << endl;
					}
					if (0 == numOfFilledLoc(*fields))
						break;
					cout << endl << "Do you want to delete test values from another field?" << endl;
				} while (once_more());
			}
			else
			{
				cout << "------------------------------" << endl;
				cout << "|Sorry! all fields are empty.|" << endl;
				cout << "------------------------------" << endl;
				cout << endl << "If you want to delete more than add some test values." << endl;
			}
			break;
		case 4:
			if (numOfFilledLoc(*fields))
				maxOccurs(*fields);
			else
			{
				cout << "------------------------------------------------" << endl;
				cout << "|Sorry! the number of filled locations is zero.|" << endl;
				cout << "------------------------------------------------" << endl;
			}
			break;
		case 5:
			if (numOfFilledLoc(*fields))
			{
				cout << "						*******" << endl;
				cout << "Average test score of all the field values:	" << setprecision(3) << fixed << calAverageScore(*fields) << endl;
				cout << "						*******" << endl;
			}
			else
			{
				cout << "------------------------------------------------" << endl;
				cout << "|Sorry! the number of filled locations is zero.|" << endl;
				cout << "------------------------------------------------" << endl;
			}
			break;
		case 6:
			if (numOfFilledLoc(*fields))
				maxFieldsScore(fields);
			else
			{
				cout << "------------------------------------------------" << endl;
				cout << "|Sorry! the number of filled locations is zero.|" << endl;
				cout << "------------------------------------------------" << endl;
			}
			break;
		default:
			display(*fields);
		}
		cout << endl << endl << "Do you want to see the menu again?" << endl;
	} while (once_more());
	if (numOfFilledLoc(*fields) != 0 && flag1)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
		cout << "*****************************" << endl << "\t\t\t\t\t\t";
		cout << "* Press \'1\' for Save.       *" << endl << "\t\t\t\t\t\t";
		cout << "* Press \'2\' for Don\'t Save. *" << endl << "\t\t\t\t\t\t";
		cout << "*****************************" << endl;
		switch (optionChecker(2))
		{
		case 1:
			saveChanges(fields);
		}
	}
	Ending();
	return 0;
}
void Welcome()
{
	const char welcome[] = { "\'Welcome To Pestcouts\'" };
	cout << "\t \t \t \t \t";
	for (int i = 1; i <= 38; i++)
	{
		cout << "*";
		Sleep(100);
	}
	cout << endl << "\t \t \t \t \t*       ";
	for (int i = 0; welcome[i] != '\0'; i++)
	{
		cout << welcome[i];
		Sleep(250);
	}
	cout << "\t     *" << endl << "\t \t \t \t \t* An Emerging Pesticide Research Lab *\n\t \t \t \t \t";
	for (int i = 1; i <= 38; i++)
	{
		cout << "*";
		Sleep(100);
	}
	cout << "\n\n";
}
void menu()
{
	cout << "\t\t\t\t\t\t     ********" << endl;
	cout << "\t\t\t\t\t\t      *MENU*" << endl;
	cout << "\t\t\t\t\t\t     ********" << endl;
	cout << "\t        ********************************************************************************" << endl;
	cout << "\t        * Press \'1\' to Insert a new Test value.                                        *" << endl;
	cout << "\t        * Press \'2\' to Count the total number of conducted Tests.                      *" << endl;
	cout << "\t        * Press \'3\' to Delete a Test value.                                            *" << endl;
	cout << "\t        * Press \'4\' to Display the top two Test values which have maximum occurrences. *" << endl;
	cout << "\t        * Press \'5\' to Calculate average Test score of all the fields.                 *" << endl;
	cout << "\t        * Press \'6\' to Display the field/s no having maximum success scores value.     *" << endl;
	cout << "\t        * Press \'7\' to Display all test values in all fields.	                       *" << endl;
	cout << "\t        ********************************************************************************" << endl;
}
bool once_more()
{
	char again{};
	bool flag{};
	cout << "If yes then press \'Y\' otherwise \'N\' :	";
	do
	{
		if (cin >> again && (('y' == again || 'Y' == again) ? flag = true : ('n' == again || 'N' == again)))
		{
			cout << endl;
			cin.ignore(100, '\n');
			break;
		}
		cout << "-----------------" << endl;
		cout << "|Invalid option.|" << endl;
		cout << "-----------------" << endl;
		cout << "Press \'y\' for (yes) and \'n\' for (no) :	";
		cin.clear(), cin.ignore(100, '\n');
	} while (true);
	return flag;
}
bool fullFieldChecker(const int Fields[][col], int row)
{
	return -1 == Fields[row][col - 1];
}
bool inserter(int Fields[][col], int row)
{
	int i{};
	bool flag{};
	cout << endl << "Enter a value which you want to store:	";
	for (; Fields[row][i] != -1; i++);
	Fields[row][i] = valueChecker();
	cout << endl << "******************************" << endl;
	cout << "*Value inserted successfully.*" << endl;
	cout << "******************************" << endl << endl;
	if (numOfFilledLoc(*Fields) != 24)
	{
		if (fullFieldChecker(Fields, row))
		{
			cout << "Do you want to add one more value in this field?" << endl;
			flag = once_more();
		}
		else
		{
			cout << "-------------------------" << endl;
			cout << "|Now, this field is full.|" << endl;
			cout << "-------------------------" << endl;
		}
	}
	else
	{
		cout << "-------------------------------" << endl;
		cout << "|Now, all the fields are full.|" << endl;
		cout << "-------------------------------" << endl;
		cout << endl << "If you want to add more then first delete some entered test values." << endl;
	}
	return flag;
}
int numOfFilledLoc(int* Field)
{
	int count{};
	for (int i = 0; i < row * col; i++)
	{
		if (-1 != *(Field + i))
			count++;
	}
	return count;
}
int fieldSelector()
{
	cout << "***************************" << endl;
	cout << "* Press \'1\' for Field 1   *" << endl;
	cout << "* Press \'2\' for Field 2   *" << endl;
	cout << "* Press \'3\' for Field 3   *" << endl;
	cout << "* Press \'4\' for Field 4   *" << endl;
	cout << "***************************" << endl;
	return optionChecker(4);
}
bool emptyFieldChecker(const int Fields[][col], int row)
{
	return Fields[row][0] != -1;
}
bool deleter(int Fields[][col], int row)
{
	int value{}, count{};
	bool flag{};
	do
	{
		count = 0, flag = 0;
		cout << endl << "These are the test values of this field." << endl;
		for (int i = 0; i < col; i++)
		{
			if (-1 == Fields[row][i])
				break;
			cout << left << setw(7) << "     Test \'" << i + 1 << "\'";
		}
		cout << endl;
		for (int i = 0; i < col; i++)
		{
			if (-1 == Fields[row][i])
				break;
			cout << "       " << left << setw(6) << Fields[row][i];
		}
		cout << endl << endl << "Enter a value which you want to delete:	";
		value = valueChecker();
		for (int i = 0; i < col; i++)
		{
			if (Fields[row][i] == value)
				count++;
		}
		if (0 == count)
		{
			cout << "-----------------------------" << endl;
			cout << "|Not available in the field.|" << endl;
			cout << "-----------------------------" << endl;
			cout << "Only enter the test value from the given." << endl;
			flag = true;
		}
		else if (1 == count)
		{
			shiftValues(Fields[row], valueSearcher(Fields[row], value, 0));
			cout << "***********************" << endl;
			cout << "*Deleted successfully.*" << endl;
			cout << "***********************" << endl;
		}
		else
		{
			cout << "There are more then one test values in this field." << endl;
			cout << "*********************************************************" << endl;
			cout << "* Press \'1\' to Delete a specific test value.            *" << endl;
			cout << "* Press \'2\' to Delete all tests which has this value.   *" << endl;
			cout << "*********************************************************" << endl;
			switch (optionChecker(2))
			{
			case 1:
				do
				{
					if (1 == count)
					{
						shiftValues(Fields[row], valueSearcher(Fields[row], value, 0));
						cout << "***********************" << endl;
						cout << "*Deleted successfully.*" << endl;
						cout << "***********************" << endl;
						cout << "                   " << "******" << endl;
						cout << "Now all entries of  " << value << "   are deleted from this Field." << endl;
						cout << "                   " << "******" << endl;
						break;
					}
					int* indexes = new int[count]{}, tempIndex{}, num{};
					cout << "                                   " << "******" << endl;
					cout << "These are the tests which includes  " << value << endl;
					cout << "                                   " << "******" << endl;
					cout << "******************************" << endl;
					for (int i = 0; i < count; i++)
					{
						indexes[num] = valueSearcher(Fields[row], value, tempIndex);
						tempIndex = indexes[num++] + 1;
						cout << "* Press \'" << num << "\' to Delete Test " << indexes[num - 1] + 1 << " *" << endl;
					}
					cout << "******************************" << endl;
					shiftValues(Fields[row], indexes[optionChecker(num) - 1]);
					cout << "***********************" << endl;
					cout << "*Deleted successfully.*" << endl;
					cout << "***********************" << endl;
					delete[] indexes;
					indexes = 0, count--;
					cout << "Do you want to delete this value from another test in this field?" << endl;
				} while (once_more());
				break;
			default:
				for (int i = 0; i < col; i++)
				{
					if (Fields[row][i] == value)
					{
						shiftValues(Fields[row], i);
						i--;
					}
				}
				cout << "*************************" << endl;
				cout << "*All values are deleted.*" << endl;
				cout << "*************************" << endl;
			}
		}
	} while (flag);
	if (numOfFilledLoc(*Fields) != 0)
	{
		if (emptyFieldChecker(Fields, row))
		{
			cout << "Do you want to delete one more test value from this field?" << endl;
			flag = once_more();
		}
		else
		{
			cout << "-----------------------------------------" << endl;
			cout << "|Now, the field has no more test values.|" << endl;
			cout << "-----------------------------------------" << endl;
		}
	}
	else
	{
		cout << "----------------------------" << endl;
		cout << "|Now! all fields are empty.|" << endl;
		cout << "----------------------------" << endl;
		cout << endl << "If you want to delete more than add some test values." << endl;
	}
	return flag;
}
int valueChecker()
{
	int value{};
	do
	{
		if (cin >> value && value >= 0)
		{
			cin.ignore(100, '\n');
			break;
		}
		cin.clear(), cin.ignore(100, '\n');
		cout << "----------------" << endl;
		cout << "|Invalid value.|" << endl;
		cout << "----------------" << endl;
		cout << "Re-enter value:	";
	} while (true);
	return value;
}
int optionChecker(int limit)
{
	int option{};
	cout << endl << "Type your desired option (1 - " << limit << "):	";
	do
	{
		if (cin >> option && (option >= 1 && option <= limit))
		{
			cin.ignore(100, '\n');
			break;
		}
		cout << "-----------------" << endl;
		cout << "|Invalid option.|" << endl;
		cout << "-----------------" << endl;
		cout << "Type your desired option again (1 - " << limit << "):	";
		cin.clear(), cin.ignore(100, '\n');
	} while (true);
	return option;
}
int valueSearcher(int* Field, int Value, int indx)
{
	for (; indx < col; indx++)
	{
		if (Field[indx] == Value)
			break;
	}
	return indx;
}
void shiftValues(int* Field, int index)
{
	for (; index < col - 1; index++)
		*(Field + index) = Field[index + 1];
	Field[index] = -1;
}
void maxOccurs(int* Fields)
{
	int count, l{}, count1{}, Max1{ -1 }, Max2{ -1 }, size{};
	int** freq = new int*[2]{};
	for (int i = 0, j = 0; i < row*col; i++)
	{
		if (-1 == Fields[i])
			continue;
		for (j = 0; j < i; j++)
		{
			if (Fields[i] == Fields[j])
				break;
		}
		if (i == j)
			size++;
	}
	freq[0] = new int[size]{}, freq[1] = new int[size]{};
	for (int i = 0, j = 0; i < row*col; i++)
	{
		count = 1;
		if (-1 == Fields[i])
			continue;
		for (j = 0; j < i; j++)
		{
			if (Fields[i] == Fields[j])
				break;
		}
		if (i == j)
		{
			for (int k = i + 1; k < row*col; k++)
			{
				if (Fields[i] == Fields[k])
					count++;
			}
			freq[0][l] = Fields[i];
			freq[1][l++] = count;
		}
	}
	for (int i = 0; i < l; i++)
	{
		if (Max1 < freq[1][i])
			Max1 = freq[1][i];
	}
	for (int i = 0; i < l; i++)
	{
		if (freq[1][i] > Max2  && freq[1][i] < Max1)
			Max2 = freq[1][i];
	}
	cout << " ******                          " << "******" << endl;
	for (int i = 0; i < l; i++)
	{
		if (Max1 == freq[1][i])
			cout << "  " << left << setw(7) << freq[0][i] << "has maximum occurence of " << Max1 << "    time/s." << endl;
	}
	cout << " ******                          " << "******" << endl;
	if (Max2 != -1)
	{
		cout << " ******                                 " << "******" << endl;
		for (int i = 0; i < l; i++)
		{
			if (Max2 == freq[1][i])
				cout << "  " << left << setw(7) << freq[0][i] << "has second maximum occurence of " << Max2 << "    time/s." << endl;
		}
		cout << " ******                                 " << "******" << endl;
	}
	else
	{
		cout << "---------------------------------------" << endl;
		cout << "|There is no second maximum occurence.|" << endl;
		cout << "---------------------------------------" << endl;
	}
	delete[] freq[0], delete[] freq[1];
	delete[] freq;
	freq = 0;
}
float calAverageScore(int* Fields)
{
	float sum = 0;
	for (int i = 0; i < row*col; i++)
	{
		if (Fields[i] != -1)
			sum += Fields[i];
	}
	return sum / numOfFilledLoc(Fields);
}
void maxFieldsScore(int Fields[][col])
{
	bool flag{};
	int fieldNo, max{ -1 };
	cout << "*******************************************************************************" << endl;
	cout << "* Press \'1\' if you want to know that which field has maximum test score.      *" << endl;
	cout << "* Press \'2\' if you want to know the maximum test score of a specific field.   *" << endl;
	cout << "*******************************************************************************" << endl;
	switch (optionChecker(2))
	{
	case 1:
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (max < Fields[i][j])
					max = Fields[i][j];
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (max == Fields[i][j])
				{
					cout << "     " << "                            " << "******" << endl;
					cout << "Field \'" << i + 1 << "\'  has maximum test score " << max << endl;
					cout << "     " << "                            " << "******" << endl;
					break;
				}
			}
		}
		break;
	default:
		do
		{
			max = -1, flag = false;
			cout << endl << "From which field you want to know maximum test Score: " << endl;
			fieldNo = fieldSelector();
			if (emptyFieldChecker(Fields, fieldNo - 1))
			{
				for (int i = 0; i < col; i++)
				{
					if (max < Fields[fieldNo - 1][i])
						max = Fields[fieldNo - 1][i];
				}
				cout << "                                     ******" << endl;
				cout << "Maximum test score of Field no \'" << fieldNo << "\' :  " << max << endl;
				cout << "                                     ******" << endl;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "|Sorry! the field is empty.|" << endl;
				cout << "----------------------------" << endl;
			}
			cout << endl << "Do you want to know maximum test score from another field?" << endl;
		} while (once_more());
	}
}
void display(int* Fields)
{
	cout << "*******************************************************************************************************" << endl;
	cout << "|           |   Test \'1\'   |   Test \'2\'   |   Test \'3\'   |   Test \'4\'   |   Test \'5\'   |   Test \'6\'   |" << endl;
	cout << "*******************************************************************************************************" << endl;
	cout << "| Field \'1\' |";
	for (int i = 0, j = 2; i < row*col; i++)
	{
		cout << "    " << left << setw(10) << Fields[i] << "|";
		if (0 == (i + 1) % col && j<5)
			cout << endl << "| Field \'" << j++ << "\' |";
	}
	cout << "\n*******************************************************************************************************" << endl;
}
void Ending()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\t \t \t \t \t \t    ";
	const char endingMsg[] = { "Exiting......" };
	for (int i = 0; endingMsg[i] != '\0'; i++)
	{
		cout << endingMsg[i];
		Sleep(150);
	}
	cout << endl << "\t \t \t \t \t \t";
	for (int i = 1; i < 3; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			cout << "*";
			Sleep(60);
		}
		for (int k = 1; k <= 20; k++)
			cout << "\b";
		for (int l = 1; l <= 10; l++)
		{
			cout << "-=";
			Sleep(60);
		}
		for (int m = 1; m <= 20; m++)
			cout << "\b";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n";
}
void dataFile(int *Fields)
{
	ifstream fin("FieldsData.txt");
	int count{ 0 };
	if (fin.is_open())
	{
		int i = 0;
		while (fin >> Fields[i++])
			count++;
		fin.close();
		if (!count || count != 24)
		{
			for (int i = 0; i < row*col; i++)
				Fields[i] = -1;
		}
	}
	else
	{
		cout << endl << "\t\t\t\t\t-----------------------------------" << endl;
		cout << "\t\t\t\t\t|Unable to get data from the file.|" << endl;
		cout << "\t\t\t\t\t-----------------------------------" << endl;
		cout << "\t\t\t\t\t  So, blank fields are used now." << endl;
		for (int i = 0; i < row*col; i++)
			Fields[i] = -1;
		Sleep(4000);
	}
}
void saveChanges(int Fields[][col])
{
	ofstream fout("FieldsData.txt");
	if (!fout.is_open())
	{
		cout << endl << "\t\t\t\t\t----------------------------------" << endl;
		cout << "\t\t\t\t\t|Unable to save data in the file.|" << endl;
		cout << "\t\t\t\t\t----------------------------------" << endl;
		Sleep(3000);
	}
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				fout << left << setw(10) << Fields[i][j];
			fout << endl;
		}
		fout.close();
		cout << "\n\n\t \t \t \t \t      ";
		const char datastored[] = { "Data is Stored Successfully." };
		for (int i = 0; datastored[i] != '\0'; i++)
		{
			cout << datastored[i];
			Sleep(100);
		}
		Sleep(1000);
	}
}
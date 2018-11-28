#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	int roll;
	float CSE, IPE, PLC, DSP, VEHICLE, average;
public:



	void InsertData(string n, int r, float cse, float ipe, float plc, float dsp , float vehicle)
	{
		name = n;
		roll = r;
		CSE = cse;
		IPE = ipe;
		PLC = plc;
		DSP = dsp;
		VEHICLE = vehicle;

		average = (cse + ipe + plc + dsp + vehicle) / 5;
	}

	int GetRoll()
	{
		return roll;
	}

	void Report()
	{
		cout << "\nSTUDENT REPORT" << endl;
		cout << "==============" << endl << endl;
		cout << "Name: " << name << endl;
		cout << "Roll: " << roll << endl;
		cout << "cse Marks: " << CSE << endl;
		cout << "ipe Marks: " << IPE << endl;
		cout << "plc Marks: " << PLC << endl;
		cout << "dsp Marks: " << DSP << endl;
		cout << "vehicle Marks: " << VEHICLE << endl;
		cout << "Average Marks: " << average << endl;
		cout << "CGPA: " << average / 25 << endl;
	}
};


vector<Student> database;
int databaseSize;

void PrintReport(int roll)
{
	for (int i = 0; i < databaseSize; i++)
		if (database[i].GetRoll() == roll)
		{
			database[i].Report();
			return;
		}

	cout << "\nTHE ENTERED ROLL(" << roll << ") DOES NOT EXIST.\n" << endl;
}

void ResizeDatabase()
{
	database.resize(databaseSize);
}

void ShowStats()
{
	cout << "\nSIZE: " << databaseSize << endl;
	cout << "STUDENT LIST (ROLL): ";

	if (databaseSize == 0)
	{
		cout << "DATABASE IS EMPTY\n" << endl;
		return;
	}

	for (int i = 0; i < databaseSize; i++)
		cout << database[i].GetRoll() + " ";

	cout << "\n" << endl;
}

void Add()
{
	string name;
	int roll;
	float cse, ipe, plc, dsp, vehicle;

	cout << "\nPLEASE ENTER THE DETAILS OF THE STUDENT:" << endl;
	cout << "NAME: ";
	cin.ignore();
	getline(cin, name);
	cout << "ROLL: ";
	cin >> roll;
	cout << "MARKS IN CSE, IPE, PLC, DSP AND VEHICLE: ";
	cin >> cse >> ipe >> plc >> dsp >> vehicle;
	cout << "\nSTUDENT DATA ADDED TO DATABASE" << endl;

	databaseSize++;
	ResizeDatabase();
	database[databaseSize - 1].InsertData(name, roll, cse, ipe, plc, dsp, vehicle);
}

void Delete(int roll)
{
	for (int i = 0; i < databaseSize; i++)
		if (database[i].GetRoll() == roll)
		{
			database.erase(database.begin() + i);
			cout << "\nSTUDENT WITH ROLL " << roll << " HAS BEEN REMOVED FROM THE DATABASE\n" << endl;
			databaseSize--;
			return;
		}

	cout << "\nTHE ENTERED ROLL(" << roll << ") DOES NOT EXIST.\n" << endl;
}

int main()
{
	int choice, roll;

	cout << " RESULT REGERATOR PROJECT\n Name : Shuvendu Biswas\n Roll : 138025\n Dept. : Mechatronics Engineering " << endl;
	cout << "##########################################################################\n " << endl;
	cout << "PLEASE CHOOSE AN ACTION :" << endl;

	do
	{
		cout << "\n1. ADD NEW STUDENT DATA\n2. DELETE STUDENT DATA\n3. PRINT REPORT\n0. EXIT" << endl;
		cout << "YOUR CHOICE: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Add();
			break;

		case 2:
			cout << "ROLL: ";
			cin >> roll;
			Delete(roll);
			break;

		case 3:
			cout << "ROLL: ";
			cin >> roll;
			PrintReport(roll);
			break;

		case 4:
			ShowStats();
			break;

		case 0:
			break;

		default:
			cout << "\nINVALID CHOICE\n" << endl;
			break;
		}
	} while (choice);

	return 0;
}

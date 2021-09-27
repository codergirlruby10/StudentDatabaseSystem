#include<fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class student
{
private:
	char Student_Name[50];
	int Student_Id;
	int Social_Studies, Statistics, Math, English, Computer_Science;
	double Student_Percentage;
	char Student_Grade;
	bool flag;
	void CalculateGrade();

public:
	student();
	void getData();
	void CheckForDupilicationInFile();
	void showData();
	void tabularDisplay();
	int getStudentID();
	void showStudentRecord(int);
};

//Constructor
student::student()
{
	//Create student.dat
	ofstream outFile("student.dat",ios::binary|ios::app); //Creating ofstream object 
	outFile.close();

	//Create DuplicateCheckingFile.txt
	ofstream outDFile("DuplicateCheckingFile.txt", ios::app);
	outDFile.close();
}


void student::getData()
{
	flag = false;
	cout << "\nEnter Student ID";
	cin >> Student_Id;
	//Check for duplication
	CheckForDupilicationInFile();
	if (flag == true)
	{
		cout << "Error duplicate record" << endl;
		return;
	}

	cout << "\n\nEnter the Name of the student ";
	cin.ignore();
	cin.getline(Student_Name, 50);
	cout << "Enter the grade in SocialStudies out of 100 : ";
	cin >> Social_Studies;
	cout << "Enter the grade in Statistics out of 100 : ";
	cin >> Statistics;
	cout << "Enter the grade in Math out of 100 : ";
	cin >> Math;
	cout << "Enter the grade in English out of 100 : ";
	cin >> English;
	cout << "Enter the grade in Computer Science out of 100 : ";
	cin >> Computer_Science;
	CalculateGrade();

}


void student::showData()
{
	cout << "\nStudent ID = " << Student_Id;
	cout << "\n Name of Student = " << Student_Name;
	cout << "\n Grade in SocialStudies = " << Social_Studies;
	cout << "\n Grade in Statistics = " << Statistics;
	cout << "\n Grade in Math = " << Math;
	cout << "\n Grade in English = " << English;
	cout << "\n Grade in Computer Science = " << Computer_Science;
	cout << "\n Percentage of grade is  = " << Student_Percentage;
	cout << "\n Grade of student = " << Student_Grade;
}

void student::CalculateGrade()
{
	Student_Percentage = (Social_Studies + Statistics + Math + English + Computer_Science) / 5.0;
	if (Student_Percentage >= 90)
		Student_Grade = 'A';
	if (Student_Percentage>=80 && Student_Percentage<90)
		Student_Grade = 'B';
	if (Student_Percentage >= 70 && Student_Percentage < 80)
		Student_Grade = 'C';
	if (Student_Percentage >= 60 && Student_Percentage < 70)
		Student_Grade = 'D';
	if (Student_Percentage < 60)
		Student_Grade = 'F';
}

void student::tabularDisplay() 
{
	cout << Student_Id << setw(4) << Student_Name << setw(20 - strlen(Student_Name)) << Social_Studies << setw(6) << Statistics << setw(6) << Math << setw(6) << English << setw(8) << Computer_Science << setw(8) << Student_Percentage << setw(8) << Student_Grade << endl;
}

int student::getStudentID() 
{
	return Student_Id;
}

void student::showStudentRecord(int n) 
{
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)// if file can't be opened
	{
		cout << "File could not be opened !! Press any key to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while(inFile.read(reinterpret_cast<char *> (this), sizeof(student)))
	{
		if (getStudentID() == n)
		{
			showData();
			flag = true; //record was found in file student.dat

		}
		inFile.close();
		if (flag == false)
		{
			cout << "\nRecord does not exist";
			cin.ignore();
			cin.get();
		}
	}
}

void student::CheckForDupilicationInFile() 
{
	//Open File, Compare student Id with others, found = true otherwise false.
	int Current_ID = 0;
	flag = false;
	ifstream infile("DuplicateCheckingFile.txt");
	while (!infile.eof())
	{
		infile >> Current_ID;
		if (Current_ID == Student_Grade)
		{
			flag = true;
		}
	}//end while
	infile.close();
	if (flag == false) //means no duplicate
	{
		//Write student Id into DuplicateCheckingFile.txt
		ofstream outfile("DuplicateCheckingFile.txt", ios::app);
		outfile <<"\n" << Student_Id;
		outfile.close();

	}
	
}

void intro();
int main()
{
	system("CLS");
	system("color B1");
	char ch;
	student std_obj;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2);
	intro();

	do {
		system("cls");
		intro();
		cout << "\n\n\n\tHOME SCREEN\n\n\n";
		cout << "\n\n\t1. Result Calculation System";
		cout << "\n\n\t2. Student Database Management System";
		cout << "\n\n\t3. EXIT";
		cout << "\n\n\n\n\n\tPlease Select Your Option (1-3)\n\n\n\n\n\t";
		cin >> ch;
		switch (ch) {
		case'1':
		//shows result calculation
			break;
		case'2':
			//shows student database
			break;
		case '3':
			//user wants to exit system
		default: cout<<"\a";
			break;
		}

	} while (ch != '3');

	system("pause");
	return 0;
}
void intro()
{

	cout<<"\n\n\n**** WELCOME TO STUDENT DATABASE MANAGEMENT AND RESULT CALCULATION SYSTEM ****\n\n";
}


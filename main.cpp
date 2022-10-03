// Assignment_1_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
using namespace std;


int main()
{
	string line;
	ifstream inputFile;
	//opens the text file as input
	inputFile.open("grades_Section2.txt", ios::in);
	string arr[2];
	//iterates through first line to have 2D array row and column numbers
	for (int i = 0; i < 2; i++)
		 inputFile >> arr[i];
	 
	 //converting string to numbers to initiate array intstance with row and column numbers found from first line
	const unsigned int students = stoi(arr[0]); 
	const unsigned int examNum = stoi(arr[1]);
	//declaring 2D array with dynamic memory allocation
	int** studExam= new int*[students];
	for (int i = 0; i < students; i++)
		studExam[i] = new int[examNum];
	//delcaring 1D array to hold Student's Name
	string* studName=new string[students];
	string tempStudName[2];
	//iterating through lines to extract numbers and store them in the 2D array
	for (int j = 0; j <=students; j++) {
		getline(inputFile, line);
		//discarding the first line
		if (line.length() > 0) {
			studName[j-1] = nameEx(line, ' ');
			int* exScore = examScoresExt(line, examNum);
			for ( int k = 0; k < examNum; k++)
			{
				studExam[j - 1][k] = exScore[k];
			}
		}
		
	}	
	
	for (size_t i = 0; i < students; i++)
	{
		cout << "Student:" << i << " ";
		for (size_t j = 0; j < examNum; j++)
		{
			cout<<studExam[i][j]<<',';
		}
		cout << endl;
	}
	
	delete[] exScore;
	delete[] studExam;
	delete[] studName;
	return 0;
}

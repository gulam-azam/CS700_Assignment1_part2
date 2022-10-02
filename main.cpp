// Assignment_1_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <sstream>
using namespace std;

int* examScoresExt(string line,int n) {
	stringstream tempstr;
	tempstr << line;
	string container;
	int num;
	int* examScores = new int[n];
	int tcount = 0;
	while (!tempstr.eof())
	{
		tempstr >> container;
		if (stringstream(container) >> num) {
			examScores[tcount] = (num);
			tcount++;
		}
		
		container = "";
	}
	return examScores;
}
string nameEx(string str, char del) {
	string arofstr[20];
	int arrcount = 0;
	string name[3];
	int ischar = 0;
	string tmp = "";
	string fullname = "";

for (int i = 0; i < str.length(); i++) {
	if (str[i] != del) {
		ischar = isalpha(str[i]);
			if (ischar > 0)
					tmp += str[i];
			}
		else {
				fullname += tmp + ' ';
				tmp = "";
			}
		}
	return fullname;	
}

int main()
{
	string line;
	ifstream inputFile;
	inputFile.open("grades_Section.txt", ios::in);
	string arr[2];
	//getline(inputFile, line);

	for (int i = 0; i < 2; i++)
		 inputFile >> arr[i];

	const unsigned int students = stoi(arr[0]); 
	const unsigned int examNum = stoi(arr[1]);
	
	int** studExam= new int*[students];
	for (int i = 0; i < students; i++)
		studExam[i] = new int[examNum];

	string* studName=new string[students];
	string tempStudName[2];
	
	for (int j = 0; j <=students; j++) {
		getline(inputFile, line);
		//discarding the first line
		if (line.length() > 0) {
			//studName[j-1] = nameEx(line, ' ');
			int* exScore = examScoresExt(line, examNum);
			for ( int k = 0; k < examNum; k++)
			{
				studExam[j - 1][k] = exScore[k];
			}
		}
		
	}	
	/*
	for (size_t i = 0; i < students; i++)
	{
		cout << "Student: " << i;
		for (size_t j = 0; j < examNum; j++)
		{
			cout<<studExam[i][j];
		}
		cout << endl;
	}*/
	
	//delete[] exScore;
	delete[] studExam;
	delete[] studName;
	return 0;
}
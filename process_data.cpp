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

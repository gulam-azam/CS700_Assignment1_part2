#This projet is written in C++ language
# There are 3 files in this project
 1. Main.CPP : It takes a text file as input where several student's exam info is described. To process the information
	       it call several functions and finally output Student's Name,Number of Exam taken,total score,average score
		Grade in tabular format.

 2. Data_Processor.CPP: This file contains 3 functiions infoProcess,arrayprocess,gradCalc to finish the main process.

	> infoProcess: This function is called from main function and takes the line from file as argument split the words
			 by 'space' delimiter and keeps them in an array of strings passes the array to arrayprocess 
			function to extract name and numbers
	> arrayprocess: This functin processes the array of student info passed from infoprocess function.It iterates 
			through the array values and matches char if its alphabet or numeric. Alphabets are considered 
			as Name and numerics are kept in an array for further processing
	> gradCalc:    This is a helpher function for arrayprocess function which takes average score of a srudent as an argment and matches the 
			average score with given grading score. Finally returns the grade for the studen.

3. Header.h: This is a header file which describes all the functions used in this project

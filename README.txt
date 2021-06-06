Birthday Paradox Assignment README

Problem Statement from Skills Assessment: 
	In a Jupyter Notebook, write a Python program that will simulate the “birthday paradox” 
	<Birthday problem>. Your output should include a graph of the probability of two people 
	having the same birthday, given an input of the total number of people. 

		Ex: 
		Input = # of people 
		Output = Probability that two people have the same birthday 
	
	Graph the probability output for inputs in the range of 2 to 367. 
	Document your code using the markdown boxes provided in Jupyter. Return your 
	program to us as a PDF of the notebook. 
	
Background:  The birthday paradox assignment is concerned with finding the probability of a shared birthday given n number of people.

Formula:  To calculate the probability of a shared birthday given n people, we can calculate the probability of no shared birthdays and subtract that probability from 1 such that 

Probability of Shared Birthday = 1 - Probability of No Shared Birthdays

To calculate the probability of no shared birthdays, we can do the following.  If n = 1, the probability of no shared birthdays is 1.0 as the person can have a birthday on any day of the year or 365/365.  If we add a second person, the probability of no shared birthday is 1 * 364/365.  This is because there is now one day that can possibly be shared (same day as first person's).  If we add a third person, the probability of no shared birthdays is 1 * 364/365 * 363/365 as the third person now has two other possible days that can be shared (with person 1 and person 2).  So the formula is

Probability of No Shared Birthdays = 365/365 * 364/365 * 363/365 ...... * (365-n-1)/365.

Deviations from Assignment:  I was told I could write this program in C++ as I am more proficient in the language, so this program is writen in C++ instead of Python.

Building the Project:  On a machine that has gcc, issue the command "g++ birthdayProblem.cpp -o birthdayProblem.exe".  Note that I used Cygwin.  I've included the .exe that was built, but there are no guarantees that this will work in your environment.

Running the Project:  Issue the command ./birthdayProblem.  Note that I used Cygwin

Input Format:
Number of People:  Enter the values you want to get probabilities.  The values can be ranged or comma separated.  For example, "1,2,4,5" will get probabilities for 1, 2, 3, 4, and 5 people.  "1-5" will get probabilities for 1, 2, 3, 4, and 5 people.  "1-3,6,7" will get probabilities for 1, 2, 3, 6, and 7 people.
Output File:  Enter the desired output file.  If you want to display results on the console, type "console"

Test Cases:
1) input: Number of People = exit -> expected output: exits the program
2) input: Number of People = all -> expected output: outputs probabilities for 1-365 people
3) input: Number of People = 1-365 -> expected output: outputs probabilities for 1-365 people
4) input: Number of People = 5 -> expected output: outputs probabilities for 5 people
5) input: Number of People = 1-5,8,10 -> expected output: outputs probabilities for 1-5 and 8 and 10 people
6) input: Number of People = 1,5,10 -> expected output: outputs probabilities for 1, 5, and 10 people
7) input: Number of People = blah -> expected output: Error.  Invalid input
8) input: Output File: console -> expected output: Results displayed on console
9) input: Output File: all.txt -> expected output: Results outputted to all.txt file


Limitations:  Precision is limited to the compiler definition of a long double.  For my particular case, it seems like 19 digits of precision to the right of the decimal point is the limit.  This allows n to be of value 166 before the lack of precision rounds probabilities to round up to 1.0

Verifying Results: To verify my results, I used calculators that can easily be found online.  I used the calculator at https://keisan.casio.com/exec/system/1223738282 to verify my results.  The results from my program seems accurate.
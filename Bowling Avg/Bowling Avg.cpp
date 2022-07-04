// Bowling Avg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

#include<iomanip>

#include<fstream>

using namespace std;

// # of players
#define NO_PLAYERS 10

// making the GetBowlingData function to read with arrays
bool GetBowlingData(char names[][100], int scores[][6], int& n) {

	// reading BowlingScores.txt
	ifstream in("BowlingScores.txt");

	// Checking for failure
	if (!in.fail()) {

		while (!in.eof()) {
			// allocating the data to each Array
			in >> names[n] >> scores[n][0] >> scores[n][1] >> scores[n][2] >> scores[n][3] >> scores[n][4] >> scores[n][5];

			n++;

		}
		// returning true or false
		return true;

	}

	return false;

}

// Calculating the average scores
void GetAverageScore(int scores[][6], double avg_scores[], int n) {

	// for loop to check all the scores
	for (int i = 0; i < n; i++) {

		avg_scores[i] = 0;
		// adding all the scores up and dividing to get the average
		for (int j = 0; j < 6; j++) {

			avg_scores[i] += scores[i][j];

		}

		avg_scores[i] /= 6.0;

	}

}

// printing the results
void PrettyPrintResults(char names[][100], int scores[][6], double avg_scores[], int n) {

	// lineing up the results and spacing them out
	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tScore6\tAvg_Score" << endl;

	for (int i = 0; i < n; i++) {

		cout << left << setw(15) << names[i] << "\t";

		for (int j = 0; j < 6; j++)

			cout << scores[i][j] << "\t";

		cout << avg_scores[i] << endl;

	}

}

int main() {
	// making varibles for all the players and also there scores
	char names[NO_PLAYERS][100];

	int scores[NO_PLAYERS][6];

	double avg_scores[NO_PLAYERS];

	int n = 0;

	// calling the functions 
	if (GetBowlingData(names, scores, n)) {

		GetAverageScore(scores, avg_scores, n);

		PrettyPrintResults(names, scores, avg_scores, n);

	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

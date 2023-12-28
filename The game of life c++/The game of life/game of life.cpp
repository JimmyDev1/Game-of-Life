#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

const char LIVE = 'o'; //life cells
const char DEAD = '.'; //dead cell

//sets the array rows and columns
#define ROWS 10
#define COLUMNS 28

// prototypes

// Guides user to get input
void getUser(string space[]);
// Updates the array holding user input
void update(string space[]);
// Prints an array
void printarray(string array[]);

int main(){

	int i = 0;
	string space[ROWS];

	getUser(space);

	cout << "\n\n";

	while (i <= 20) {

		update(space);

		printarray(space);

		i++;

	}

}


void getUser(string space[]) {

	bool done = false;

	cout << "Enter a series of '.' and 'o'  '.' being dead and 'o' being alive" << endl;
	cout << "(" << ROWS << " x " << COLUMNS << ")" << endl;

	for (int w = 0; w < COLUMNS; w++) {

		cout << '-';

	}

	cout << "\n";

	for (int i = 0; i < ROWS; i++) {


		while (!done) {

			cin >> space[i];

			if (space[i].length() > COLUMNS) {

				cout << "Error larger than " << COLUMNS << endl;
				continue;
			}
			else if (space[i].length() < COLUMNS) {

				cout << "Error less than " << COLUMNS << endl;
				continue;

			}
			else {

				done = true;

			}

		}

		done = false;

	}


}

void update(string space[]) {

	string hold[ROWS];
	int count = 0;

	for (int i = 0; i < ROWS; i++) {

		hold[i] = space[i];

	}


	for (int r = 0; r < ROWS; r++) {


		for (int c = 0; c < COLUMNS; c++) {




			// top left corner square 
			if (r == 0 && c == 0) {

				if (space[r][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				




			}
			
			// top mid section
			if (r == 0 && c > 0 && c < COLUMNS - 1){
				 
				if (space[r][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c] == LIVE) {

					count++;

				}
				if (space[r + 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r][c - 1] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				



			}

			 //top right corner
			if (r == 0 && c == (COLUMNS - 1) ) {

				if (space[r + 1][c] == LIVE) {

					count++;

				}
				if (space[r + 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r][c - 1] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				


			}

			//left middle segment
			if (r > 0 && r < (ROWS - 1) && c == 0) {

				if (space[r - 1][c] == LIVE) {

					count++;

				}
				if (space[r - 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r + 1][c] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				



			}


			//bottom left corner
			if (r == (ROWS - 1) && c == 0 ) {

				if (space[r - 1][c] == LIVE) {

					count++;

				}
				if (space[r - 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r][c + 1] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				



			}

			// bottom mid section
			if (r == (ROWS - 1) && c > 0 && c < COLUMNS - 1) {

				if (space[r][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c] == LIVE) {

					count++;

				}
				if (space[r - 1][c + 1] == LIVE) {

					count++;

				}
				if (space[r][c + 1] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				


			}

			// bottom right corner
			if (r == (ROWS - 1) && c == (COLUMNS - 1) ) {

				if (space[r][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				


			}

			//right mid section
			if ( r > 0 && r < (ROWS - 1) && c == (COLUMNS - 1)) {


				if (space[r + 1][c] == LIVE) {

					count++;

				}
				if (space[r + 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c - 1] == LIVE) {

					count++;

				}
				if (space[r - 1][c] == LIVE) {

					count++;

				}

				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				


			}

			//the middle section has all sides 
			if ( r > 0 && r < (ROWS - 1) && c > 0 && c < (COLUMNS - 1) ) {


				if (space[r][c + 1] == LIVE) {

					count++;
					
				}
				if (space[r + 1][c + 1] == LIVE) {
					//bottom right
					count++;
					
				}
				if (space[r + 1][c] == LIVE) {
					//bottom
					count++;
					
				}
				if (space[r + 1][c - 1] == LIVE) {
					//bottom left
					count++;
					
				}
				if (space[r][c - 1] == LIVE) {

					count++;
					
				}
				if (space[r - 1][c - 1] == LIVE) {

					count++;
					
				}
				if (space[r - 1][c] == LIVE) {

					count++;
					
				}
				if (space[r - 1][c + 1] == LIVE) {

					count++;
					
				}


				if (count == 1 || count == 0) {

					hold[r][c] = DEAD;

					count = 0;

				}
				if (count == 2) {

					count = 0;

				}
				if (count == 3) {

					hold[r][c] = LIVE;

					count = 0;

				}
				if (count > 3) {

					hold[r][c] = DEAD;

					count = 0;

				}
				



			}





		}


	}




	for (int i = 0; i < ROWS; i++) {

		space[i] = hold[i];

	}




}

void printarray(string array[]) {


	for (int i = 0; i < ROWS; i++) {

		cout << array[i];
		cout << "\n";

	}

	cout << "\n";


}

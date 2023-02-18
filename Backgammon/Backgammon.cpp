#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;

default_random_engine dre(chrono::steady_clock::now().time_since_epoch().count());     
int random()
{
	uniform_int_distribution<int> uid{ 1,6 };  
	return uid(dre);    
}

int main()
{

	int x1, y1;
	int a = 0,b=0;
	while (a == 0) {
		
		x1 = random();
		y1 = random();
		if (x1 != y1) {
			a = 1;
		}
		cout << x1 << endl;
		cout << y1 << endl;

	}
	int counter = 1;
	string first, second;
	if (x1 > y1) {
		first = "X";
		second = "Y";
	}
	else {
		first = "Y";
		second = "X";
	}
	int d1, d2;
	int arr1[24]{ NULL };
	char arr2[24]{ NULL };


	for (int i = 0; i < 24; i++) {
		if (i == 0 || i == 6 || i == 17 || i == 23) {
			arr1[i] = 5;
		}
		if (i == 4 || i == 19) {
			arr1[i] = 3;
		}
		if (i == 11 || i == 12) {
			arr1[i] = 2;
		}
		if (i == 4 || i == 6 || i == 12 || i == 23) {
			arr2[i] = 'X';
		}
		if (i == 0 || i == 11 || i == 17 || i == 19) {
			arr2[i] = 'Y';
		}
	}
	ofstream dice("DICE.txt", ios::out, ios::trunc);
	ofstream board("BOARD.txt", ios::out, ios::trunc);
	if (dice.is_open()) {
		dice << x1 << endl;
		dice << y1 << endl;
		while (b==0) {
		
			d1 = random();
			d2 = random();
			
			if (counter % 2 == 1) {

				dice << first << " " << d1 << " " << d2 << endl;
				cout << first << " " << d1 << " " << d2 << endl;
			}
			else {

				dice << second << " " << d1 << " " << d2 << endl;
				cout << second << " " << d1 << " " << d2 << endl;
			}
			int movc = 0;
			string mov[4]{};
		
			cout << "Please enter the moves you want to make" << endl;
			if (d1 == d2) {
				movc = 4;
				for (int i = 0; i < movc; i++) {
					cin >> mov[i];
				}				
			}
			else {
				movc = 2;
				for (int i = 0; i < movc; i++) {
					cin >> mov[i];
				}

			}
			for (int i = 0; i < movc; i++) {

				if (mov[i] == "a1" || mov[i] == "A1") {
					if (arr1[0] != NULL) {
						arr1[0]--;
						
						if (arr2[0] == 'X') {
														
							if (i == 0) {
								if (arr2[d1] == NULL) {
									arr2[d1] = 'X';
								}
								arr1[d1]++;
							}
							else {
								if (arr2[d2] == NULL) {
									arr2[d2] = 'X';
								}
								arr1[d2]++;
							}
						}
						if (arr2[0] == 'Y') {
							if (i == 0) {
								if (arr2[24 - d1] == NULL) {
									arr2[24 - d1] = 'Y';
								}
								arr1[24 - d1]++;
							}
							else {
								if (arr2[24-d2] == NULL) {
									arr2[24 - d2] = 'Y';
								}
								arr1[24 - d2]++;
							}						
						}
						else { cout << "error1" << endl; }
						if (arr1[0] == 0) {
							arr1[0] = NULL;
							arr2[0] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "b1" || mov[i] == "B1") {
					if (arr1[1] != NULL) {
						arr1[1]--;

						if (arr2[1] == 'X') {

							if (i == 0) {
								if (arr2[d1+1] == NULL) {
									arr2[d1+1] = 'X';
								}
								arr1[d1+1]++;
							}
							else {
								if (arr2[d2+1] == NULL) {
									arr2[d2+1] = 'X';
								}
								arr1[d2+1]++;
							}
						}
						if (arr2[1] == 'Y') {
							int val = 0;
							if (i == 0) {								
								val = 1 - d1;
								if (val < 0) {
									if (arr2[25 - d1] == NULL) {
										arr2[25 - d1] = 'Y';
									}
									arr1[25 - d1]++;
								}
								else {
									if (arr2[1 - d1] == NULL) {
										arr2[1 - d1] = 'Y';
									}
									arr1[1 - d1]++;
								}
								
							}
							else {
								val = 1 - d2;
								if (val < 0) {
									if (arr2[25 - d2] == NULL) {
										arr2[25 - d2] = 'Y';
									}
									arr1[25 - d2]++;
								}
								else {
									if (arr2[1 - d2] == NULL) {
										arr2[1 - d2] = 'Y';
									}
									arr1[1 - d2]++;
								}
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[1] == 0) {
							arr1[1] = NULL;
							arr2[1] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "c1" || mov[i] == "C1") {
				if (arr1[2] != NULL) {
					arr1[2]--;

					if (arr2[2] == 'X') {

						if (i == 0) {
							if (arr2[d1 + 2] == NULL) {
								arr2[d1 + 2] = 'X';
							}
							arr1[d1 + 2]++;
						}
						else {
							if (arr2[d2 + 2] == NULL) {
								arr2[d2 + 2] = 'X';
							}
							arr1[d2 + 2]++;
						}
					}
					if (arr2[2] == 'Y') {
						int val = 0;
						if (i == 0) {
							val = 2 - d1;
							if (val < 0) {
								if (arr2[26 - d1] == NULL) {
									arr2[26 - d1] = 'Y';
								}
								arr1[26 - d1]++;
							}
							else {
								if (arr2[2 - d1] == NULL) {
									arr2[2 - d1] = 'Y';
								}
								arr1[2 - d1]++;
							}

						}
						else {
							val = 2 - d2;
							if (val < 0) {
								if (arr2[26 - d2] == NULL) {
									arr2[26 - d2] =='Y';
								}
								arr1[26 - d2]++;
							}
							else {
								if (arr2[2 - d2] == NULL) {
									arr2[2 - d2] = 'Y';
								}
								arr1[2 - d2]++;
							}
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[2] == 0) {
						arr1[2] = NULL;
						arr2[2] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
					}
				}
				else if (mov[i] == "d1" || mov[i] == "D1") {
				if (arr1[3] != NULL) {
					arr1[3]--;

					if (arr2[3] == 'X') {

						if (i == 0) {
							if (arr2[d1 + 3] == NULL) {
								arr2[d1 + 3] = 'X';
							}
							arr1[d1 + 3]++;
						}
						else {
							if (arr2[d2 + 3] == NULL) {
								arr2[d2 + 3] = 'X';
							}
							arr1[d2 + 3]++;
						}
					}
					if (arr2[3] == 'Y') {
						int val = 0;
						if (i == 0) {
							val = 3 - d1;
							if (val < 0) {
								if (arr2[27 - d1] == NULL) {
									arr2[27 - d1] = 'Y';
								}
								arr1[27 - d1]++;
							}
							else {
								if (arr2[3 - d1] == NULL) {
									arr2[3 - d1] = 'Y';
								}
								arr1[3 - d1]++;
							}

						}
						else {
							val = 3 - d2;
							if (val < 0) {
								if (arr2[27 - d2] == NULL) {
									arr2[27 - d2] = 'Y';
								}
								arr1[27 - d2]++;
							}
							else {
								if (arr2[3 - d2] == NULL) {
									arr2[3 - d2] = 'Y';
								}
								arr1[3 - d2]++;
							}
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[3] == 0) {
						arr1[3] = NULL;
						arr2[3] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
					}
				}
				else if (mov[i] == "e1" || mov[i] == "E1") {
				if (arr1[4] != NULL) {
					arr1[4]--;

					if (arr2[4] == 'X') {

						if (i == 0) {
							if (arr2[d1 + 4] == NULL) {
								arr2[d1 + 4] = 'X';
							}
							arr1[d1 + 4]++;
						}
						else {
							if (arr2[d2 + 4] == NULL) {
								arr2[d2 + 4] = 'X';
							}
							arr1[d2 + 4]++;
						}
					}
					if (arr2[4] == 'Y') {
						int val = 0;
						if (i == 0) {
							val = 4 - d1;
							if (val < 0) {
								if (arr2[28 - d1] == NULL) {
									arr2[28 - d1] = 'Y';
								}
								arr1[28 - d1]++;
							}
							else {
								if (arr2[4 - d1] == NULL) {
									arr2[4 - d1] = 'Y';
								}
								arr1[4 - d1]++;
							}

						}
						else {
							val = 4 - d2;
							if (val < 0) {
								if (arr2[28 - d2] == NULL) {
									arr2[28 - d2] = 'Y';
								}
								arr1[28 - d2]++;
							}
							else {
								if (arr2[4 - d2] == NULL) {
									arr2[4 - d2] = 'Y';
								}
								arr1[4 - d2]++;
							}
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[4] == 0) {
						arr1[4] = NULL;
						arr2[4] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
					}
				}
				else if (mov[i] == "f1" || mov[i] == "F1") {
				if (arr1[5] != NULL) {
					arr1[5]--;

					if (arr2[5] == 'X') {

						if (i == 0) {
							if (arr2[d1 + 5] == NULL) {
								arr2[d1 + 5] = 'X';
							}
							arr1[d1 + 5]++;
						}
						else {
							if (arr2[d2 + 5] == NULL) {
								arr2[d2 + 5] = 'X';
							}
							arr1[d2 + 5]++;
						}
					}
					if (arr2[5] == 'Y') {
						int val = 0;
						if (i == 0) {
							val = 5 - d1;
							if (val < 0) {
								if (arr2[29 - d1] == NULL) {
									arr2[29 - d1] = 'Y';
								}
								arr1[29 - d1]++;
							}
							else {
								if (arr2[5 - d1] == NULL) {
									arr2[5 - d1] = 'Y';
								}
								arr1[5 - d1]++;
							}

						}
						else {
							val = 5 - d2;
							if (val < 0) {
								if (arr2[29 - d2] == NULL) {
									arr2[29 - d2] = 'Y';
								}
								arr1[29 - d2]++;
							}
							else {
								if (arr2[5 - d2] == NULL) {
									arr2[5 - d2] = 'Y';
								}
								arr1[5 - d2]++;
							}
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[5] == 0) {
						arr1[5] = NULL;
						arr2[5] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
				}
				}
				else if (mov[i] == "g1" || mov[i] == "G1") {
					if (arr1[6] != NULL) {
						arr1[6]--;

						if (arr2[6] == 'X') {

							if (i == 0) {
								if (arr2[d1+6] == NULL) {
									arr2[d1+6] = 'X';
								}
								arr1[d1+6]++;
							}
							else {
								if (arr2[d2+6] == NULL) {
									arr2[d2+6] = 'X';
								}
								arr1[d2+6]++;
							}
						}
						if (arr2[6] == 'Y') {
							if (i == 0) {
								if (arr2[6 - d1] == NULL) {
									arr2[6 - d1] = 'Y';
								}
								arr1[6 - d1]++;
							}
							else {
								if (arr2[6 - d2] == NULL) {
									arr2[6 - d2] = 'Y';
								}
								arr1[6 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[6] == 0) {
							arr1[6] = NULL;
							arr2[6] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "h1" || mov[i] == "H1") {
					if (arr1[7] != NULL) {
						arr1[7]--;

						if (arr2[7] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 7] == NULL) {
									arr2[d1 + 7] = 'X';
								}
								arr1[d1 + 7]++;
							}
							else {
								if (arr2[d2 + 7] == NULL) {
									arr2[d2 + 7] = 'X';
								}
								arr1[d2 + 7]++;
							}
						}
						if (arr2[7] == 'Y') {
							if (i == 0) {
								if (arr2[7 - d1] == NULL) {
									arr2[7 - d1] = 'Y';
								}
								arr1[7 - d1]++;
							}
							else {
								if (arr2[7 - d2] == NULL) {
									arr2[7 - d2] = 'Y';
								}
								arr1[7 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[7] == 0) {
							arr1[7] = NULL;
							arr2[7] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "ı1" || mov[i] == "I1") {
					if (arr1[8] != NULL) {
						arr1[8]--;

						if (arr2[8] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 8] == NULL) {
									arr2[d1 + 8] = 'X';
								}
								arr1[d1 + 8]++;
							}
							else {
								if (arr2[d2 + 8] == NULL) {
									arr2[d2 + 8] = 'X';
								}
								arr1[d2 + 8]++;
							}
						}
						if (arr2[8] == 'Y') {
							if (i == 0) {
								if (arr2[8 - d1] == NULL) {
									arr2[8 - d1] = 'Y';
								}
								arr1[8 - d1]++;
							}
							else {
								if (arr2[8 - d2] == NULL) {
									arr2[8 - d2] = 'Y';
								}
								arr1[8 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[8] == 0) {
							arr1[8] = NULL;
							arr2[8] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "j1" || mov[i] == "J1") {
					if (arr1[9] != NULL) {
						arr1[9]--;

						if (arr2[9] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 9] == NULL) {
									arr2[d1 + 9] = 'X';
								}
								arr1[d1 + 9]++;
							}
							else {
								if (arr2[d2 + 9] == NULL) {
									arr2[d2 + 9] = 'X';
								}
								arr1[d2 + 9]++;
							}
						}
						if (arr2[9] == 'Y') {
							if (i == 0) {
								if (arr2[9 - d1] == NULL) {
									arr2[9 - d1] = 'Y';
								}
								arr1[9 - d1]++;
							}
							else {
								if (arr2[9 - d2] == NULL) {
									arr2[9 - d2] = 'Y';
								}
								arr1[9 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[9] == 0) {
							arr1[9] = NULL;
							arr2[9] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "k1" || mov[i] == "K1") {
					if (arr1[10] != NULL) {
						arr1[10]--;

						if (arr2[10] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 10] == NULL) {
									arr2[d1 + 10] = 'X';
								}
								arr1[d1 + 10]++;
							}
							else {
								if (arr2[d2 + 10] == NULL) {
									arr2[d2 + 10] = 'X';
								}
								arr1[d2 + 10]++;
							}
						}
						if (arr2[10] == 'Y') {
							if (i == 0) {
								if (arr2[10 - d1] == NULL) {
									arr2[10 - d1] = 'Y';
								}
								arr1[10 - d1]++;
							}
							else {
								if (arr2[10 - d2] == NULL) {
									arr2[10 - d2] = 'Y';
								}
								arr1[10 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[10] == 0) {
							arr1[10] = NULL;
							arr2[10] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "l1" || mov[i] == "L1") {
					if (arr1[11] != NULL) {
						arr1[11]--;

						if (arr2[11] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 11] == NULL) {
									arr2[d1 + 11] = 'X';
								}
								arr1[d1 + 11]++;
							}
							else {
								if (arr2[d2 + 11] == NULL) {
									arr2[d2 + 11] = 'X';
								}
								arr1[d2 + 11]++;
							}
						}
						if (arr2[11] == 'Y') {
							if (i == 0) {
								if (arr2[11 - d1] == NULL) {
									arr2[11 - d1] = 'Y';
								}
								arr1[11 - d1]++;
							}
							else {
								if (arr2[11 - d2] == NULL) {
									arr2[11 - d2] = 'Y';
								}
								arr1[11 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[11] == 0) {
							arr1[11] = NULL;
							arr2[11] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "l5" || mov[i] == "L5") {
					if (arr1[12] != NULL) {
						arr1[12]--;

						if (arr2[12] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 12] == NULL) {
									arr2[d1 + 12] = 'X';
								}
								arr1[d1 + 12]++;
							}
							else {
								if (arr2[d2 + 12] == NULL) {
									arr2[d2 + 12] = 'X';
								}
								arr1[d2 + 12]++;
							}
						}
						if (arr2[12] == 'Y') {
							if (i == 0) {
								if (arr2[12 - d1] == NULL) {
									arr2[12 - d1] = 'Y';
								}
								arr1[12 - d1]++;
							}
							else {
								if (arr2[12 - d2] == NULL) {
									arr2[12 - d2] = 'Y';
								}
								arr1[12 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[12] == 0) {
							arr1[12] = NULL;
							arr2[12] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "k5" || mov[i] == "K5") {
					if (arr1[13] != NULL) {
						arr1[13]--;

						if (arr2[13] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 13] == NULL) {
									arr2[d1 + 13] = 'X';
								}
								arr1[d1 + 13]++;
							}
							else {
								if (arr2[d2 + 13] == NULL) {
									arr2[d2 + 13] = 'X';
								}
								arr1[d2 + 13]++;
							}
						}
						if (arr2[13] == 'Y') {
							if (i == 0) {
								if (arr2[13 - d1] == NULL) {
									arr2[13 - d1] = 'Y';
								}
								arr1[13 - d1]++;
							}
							else {
								if (arr2[13 - d2] == NULL) {
									arr2[13 - d2] = 'Y';
								}
								arr1[13 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[13] == 0) {
							arr1[13] = NULL;
							arr2[13] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "j5" || mov[i] == "J5") {
					if (arr1[14] != NULL) {
						arr1[14]--;

						if (arr2[14] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 14] == NULL) {
									arr2[d1 + 14] = 'X';
								}
								arr1[d1 + 14]++;
							}
							else {
								if (arr2[d2 + 14] == NULL) {
									arr2[d2 + 14] = 'X';
								}
								arr1[d2 + 14]++;
							}
						}
						if (arr2[14] == 'Y') {
							if (i == 0) {
								if (arr2[14 - d1] == NULL) {
									arr2[14 - d1] = 'Y';
								}
								arr1[14 - d1]++;
							}
							else {
								if (arr2[14 - d2] == NULL) {
									arr2[14 - d2] = 'Y';
								}
								arr1[14 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[14] == 0) {
							arr1[14] = NULL;
							arr2[14] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "ı5" || mov[i] == "I5") {
					if (arr1[15] != NULL) {
						arr1[15]--;

						if (arr2[15] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 15] == NULL) {
									arr2[d1 + 15] = 'X';
								}
								arr1[d1 + 15]++;
							}
							else {
								if (arr2[d2 + 15] == NULL) {
									arr2[d2 + 15] = 'X';
								}
								arr1[d2 + 15]++;
							}
						}
						if (arr2[15] == 'Y') {
							if (i == 0) {
								if (arr2[15 - d1] == NULL) {
									arr2[15 - d1] = 'Y';
								}
								arr1[15 - d1]++;
							}
							else {
								if (arr2[15 - d2] == NULL) {
									arr2[15 - d2] = 'Y';
								}
								arr1[15 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[15] == 0) {
							arr1[15] = NULL;
							arr2[15] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "h5" || mov[i] == "H5") {
					if (arr1[16] != NULL) {
						arr1[16]--;

						if (arr2[16] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 16] == NULL) {
									arr2[d1 + 16] = 'X';
								}
								arr1[d1 + 16]++;
							}
							else {
								if (arr2[d2 + 16] == NULL) {
									arr2[d2 + 16] = 'X';
								}
								arr1[d2 + 16]++;
							}
						}
						if (arr2[16] == 'Y') {
							if (i == 0) {
								if (arr2[16 - d1] == NULL) {
									arr2[16 - d1] = 'Y';
								}
								arr1[16 - d1]++;
							}
							else {
								if (arr2[16 - d2] == NULL) {
									arr2[16 - d2] = 'Y';
								}
								arr1[16 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[16] == 0) {
							arr1[16] = NULL;
							arr2[16] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "g5" || mov[i] == "G5") {
					if (arr1[17] != NULL) {
						arr1[17]--;

						if (arr2[17] == 'X') {

							if (i == 0) {
								if (arr2[d1 + 17] == NULL) {
									arr2[d1 + 17] = 'X';
								}
								arr1[d1 + 17]++;
							}
							else {
								if (arr2[d2 + 17] == NULL) {
									arr2[d2 + 17] = 'X';
								}
								arr1[d2 + 17]++;
							}
						}
						if (arr2[17] == 'Y') {
							if (i == 0) {
								if (arr2[17 - d1] == NULL) {
									arr2[17 - d1] = 'Y';
								}
								arr1[17 - d1]++;
							}
							else {
								if (arr2[17 - d2] == NULL) {
									arr2[17 - d2] = 'Y';
								}
								arr1[17 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[17] == 0) {
							arr1[17] = NULL;
							arr2[17] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "f5" || mov[i] == "F5") {
					if (arr1[18] != NULL) {
						arr1[18]--;

						if (arr2[18] == 'X') {

							int val = 0;
							if (i == 0) {
								val = 18 + d1;
								if (val > 23) {
									if (arr2[val - 24] == NULL) {
										arr2[val - 24] = 'X';
									}
									arr1[val - 24]++;
								}
								else {
									if (arr2[val] == NULL) {
										arr2[val] = 'X';
									}
									arr1[val]++;
								}

							}
							else {
								val = 18 + d2;
								if (val > 23) {
									if (arr2[val - 24] == NULL) {
										arr2[val - 24] = 'X';
									}
									arr1[val - 24]++;
								}
								else {
									if (arr2[val] == NULL) {
										arr2[val] = 'X';
									}
									arr1[val]++;
								}
							}
						}
						
						if (arr2[18] == 'Y') {
							
							if (i == 0) {
								if (arr2[18 - d1] == NULL) {
									arr2[18 - d1] = 'Y';
								}
								arr1[18 - d1]++;
							}
							else {
								if (arr2[18 - d2] == NULL) {
									arr2[18 - d2] = 'Y';
								}
								arr1[18 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[18] == 0) {
							arr1[18] = NULL;
							arr2[18] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
				}
				else if (mov[i] == "e5" || mov[i] == "E5") {
				if (arr1[19] != NULL) {
					arr1[19]--;

					if (arr2[19] == 'X') {

						int val = 0;
						if (i == 0) {
							val = 19 + d1;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}

						}
						else {
							val = 19 + d2;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}
						}
					}

					if (arr2[19] == 'Y') {

						if (i == 0) {
							if (arr2[19 - d1] == NULL) {
								arr2[19 - d1] = 'Y';
							}
							arr1[19 - d1]++;
						}
						else {
							if (arr2[19 - d2] == NULL) {
								arr2[19 - d2] = 'Y';
							}
							arr1[19 - d2]++;
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[19] == 0) {
						arr1[19] = NULL;
						arr2[19] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
				}
				}
				else if (mov[i] == "d5" || mov[i] == "D5") {
				if (arr1[20] != NULL) {
					arr1[20]--;

					if (arr2[20] == 'X') {

						int val = 0;
						if (i == 0) {
							val = 20 + d1;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}

						}
						else {
							val = 20 + d2;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}
						}
					}

					if (arr2[20] == 'Y') {

						if (i == 0) {
							if (arr2[20 - d1] == NULL) {
								arr2[20 - d1] = 'Y';
							}
							arr1[20 - d1]++;
						}
						else {
							if (arr2[20 - d2] == NULL) {
								arr2[20 - d2] = 'Y';
							}
							arr1[20 - d2]++;
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[20] == 0) {
						arr1[20] = NULL;
						arr2[20] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
				}
				}
				else if (mov[i] == "c5" || mov[i] == "C5") {
				if (arr1[21] != NULL) {
					arr1[21]--;

					if (arr2[21] == 'X') {

						int val = 0;
						if (i == 0) {
							val = 21 + d1;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}

						}
						else {
							val = 21 + d2;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}
						}
					}

					if (arr2[21] == 'Y') {

						if (i == 0) {
							if (arr2[21 - d1] == NULL) {
								arr2[21 - d1] = 'Y';
							}
							arr1[21 - d1]++;
						}
						else {
							if (arr2[21 - d2] == NULL) {
								arr2[21 - d2] = 'Y';
							}
							arr1[21 - d2]++;
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[21] == 0) {
						arr1[21] = NULL;
						arr2[21] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
				}
				}
				else if (mov[i] == "b5" || mov[i] == "B5") {
				if (arr1[22] != NULL) {
					arr1[22]--;

					if (arr2[22] == 'X') {

						int val = 0;
						if (i == 0) {
							val = 22 + d1;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}

						}
						else {
							val = 22 + d2;
							if (val > 23) {
								if (arr2[val - 24] == NULL) {
									arr2[val - 24] = 'X';
								}
								arr1[val - 24]++;
							}
							else {
								if (arr2[val] == NULL) {
									arr2[val] = 'X';
								}
								arr1[val]++;
							}
						}
					}

					if (arr2[22] == 'Y') {

						if (i == 0) {
							if (arr2[22 - d1] == NULL) {
								arr2[22 - d1] = 'Y';
							}
							arr1[22 - d1]++;
						}
						else {
							if (arr2[22 - d2] == NULL) {
								arr2[22 - d2] = 'Y';
							}
							arr1[22 - d2]++;
						}
					}
					else { cout << "error1" << endl; }
					if (arr1[22] == 0) {
						arr1[22] = NULL;
						arr2[22] = NULL;
					}
				}
				else {
					cout << "error2" << endl;
				}
				}
					else if (mov[i] == "a5" || mov[i] == "A5") {
					if (arr1[23] != NULL) {
						arr1[23]--;

						if (arr2[23] == 'X') {

						
							if (i == 0) {
														
									if (arr2[d1 - 1] == NULL) {
										arr2[d1 - 1] = 'X';
									}
									arr1[d1 - 1]++;
							
							}
							else {
														
									if (arr2[d2 - 1] == NULL) {
										arr2[d2 - 1] = 'X';
									}
									arr1[d2 - 1]++;
							
							}
						}

						if (arr2[23] == 'Y') {

							if (i == 0) {
								if (arr2[23 - d1] == NULL) {
									arr2[23 - d1] = 'Y';
								}
								arr1[23 - d1]++;
							}
							else {
								if (arr2[23 - d2] == NULL) {
									arr2[23 - d2] = 'Y';
								}
								arr1[23 - d2]++;
							}
						}
						else { cout << "error1" << endl; }
						if (arr1[23] == 0) {
							arr1[23] = NULL;
							arr2[23] = NULL;
						}
					}
					else {
						cout << "error2" << endl;
					}
					}
				else {
					cout << "invalid move" << endl;
				}
			}
			if (board.is_open()) {
				for (int i = 1; i < 13; i++) {
					for (int j = 1; j < 75; j++) {
						if (i == 1 && j == 5) {
							board << "A";
						}
						else if (i == 1 && j == 11) {
							board << "B";
						}
						else if (i == 1 && j == 17) {
							board << "C";
						}
						else if (i == 1 && j == 23) {
							board << "D";
						}
						else if (i == 1 && j == 29) {
							board << "E";
						}
						else if (i == 1 && j == 35){
							board << "F";
						}
						else if (i == 1 && j == 41){
							board << "G";
						}
						else if (i == 1 && j == 47) {
							board << "H";
						}
						else if (i == 1 && j == 53) {
							board << "I";
						}
						else if (i == 1 && j == 59) {
							board << "J";
						}
						else if (i == 1 && j == 65) {
							board << "K";
						}
						else if (i == 1 && j == 71) {
							board << "L";
						}
						else if ((i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12) && j>=2) {
							board << "*";
						}
						else if (i == 3 && j == 1) {
							board << "1";
						}
						else if (i == 5 && j == 1) {
							board << "2";
						}
						else if (i == 7 && j == 1) {
							board << "3";
						}
						else if (i == 9 && j == 1) {
							board << "4";
						}
						else if (i == 11 && j == 1) {
							board << "5";
						}
						else if ((i + 1) % 2 == 0 && (j + 4) % 6 == 0 && i!=1 && j!=38) {
							board << "|";
						}
						else if ((i + 1) % 2 == 0 && j==38) {
							board << "#";
						}
						else if (i == 7 && j == 35) {
							board << d1;
						}
						else if (i == 7 && j == 41) {
							board << d2;
						}
						else if (i == 3 && (j+2)%6 == 0 )  {
							if (arr1[((j + 2)/6)-1] != NULL) {
								board << arr1[((j + 2)/6)-1];
							}
							else {
								board << " ";
							}
						}
						else if (i == 11 && (j + 2) % 6 == 0) {
							if (arr1[23-(((j + 2) / 6) - 1)] != NULL) {
								board << arr1[23 - (((j + 2) / 6) - 1)];
							}
							else {
								board << " ";
							}
						}
						else if (i == 3 && (j + 1) % 6 == 0 ) {
							if (arr2[((j + 1) / 6) - 1] != NULL) {
								board << arr2[((j + 1) / 6) - 1];
							}
							else {
								board << " ";
							}
							
						}
						else if (i == 11 && (j + 1) % 6 == 0) {
							if (arr2[23 - (((j + 1) / 6) - 1)] != NULL) {
								board << arr2[23 - (((j + 1) / 6) - 1)];
							}
							else {
								board << " ";
							}
						}
						else {
							board <<" ";
						}
					}
					board << endl;

				}

			}
			int c = 0;
			while (c == 0) {
				int s;
				cout << "Enter 0 to continue or enter 1 to finish" << endl;
				cin >> s;
				if (s == 1) {
					b = 1;
					break;
				}
				else if (s == 0) {
					b = 0;
					break;
				}
				else { cout << "invalid value..!!" << endl; }
			}
			counter++;
		}
		
	}
   

}



#include<iostream>
using namespace std;

int vect[3][3] = {
		1,2,3,
		4,5,6,
		7,8,9,
};

int newVect[3][3];

void spin() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			newVect[j][2 - i] = vect[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vect[i][j] = newVect[i][j];
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}

	

}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}
	cout << '\n';
	spin();
	cout << '\n';
	spin();
	cout << '\n';
	spin();
	cout << '\n';
	spin();


}
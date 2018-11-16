#pragma once
#include <iostream>

using namespace std;

class Adia {

public:

	void exe() {

		cout << "n = "; cin >> n;
		createGraph();
		writeMatrix();

	}

private:

	int n, a[20][20];

	void createGraph() {

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) 
				a[i][j] = ((result(i, j) == 1) ? 1 : 0);

		a[n][1] = 1;
	}

	int result(int x, int y) {
		
		if (x > y)
			return x - y;

		return y - x;
	}

	void writeMatrix() {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout << i << '-' << j << ' ' << a[i][j] << endl;
		}
	}
};
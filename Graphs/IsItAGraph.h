#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

class IsItAGraph {

public:

	void exe() {

		in.open("mat");
		read();
		printf("%s", isGraph());

	}

private:

	ifstream in;
	int n, m, a[20][20], s;

	int gradLinie(int i) {

		int s = 0;
		for (int j = 1; j <= n; j++)
			s += a[i][j];

		return s;
	}

	int gradCol(int i) {

		int s = 0;
		for (int j = 1; j <= n; j++)
			s += a[j][i];

		return s;
	}

	void read() {

		in >> n;
		for (int i = 1; i <= n; i++) 	
		for (int j = 1; j <= n; j++) 
				in >> a[i][j];		
	}

	string isGraph() {

		for (int i = 1; i <= n; i++)
			if (gradLinie(i) != gradCol(i))
				return "Nu-i";

		return "Este";
	}

	int muchiiMini() {
		return (n + 1) / 2;
	}

};
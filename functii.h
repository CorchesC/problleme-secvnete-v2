#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void citire(int v[], int& dim) {

	ifstream f("numere.txt");

	f >> dim;
	for (int i = 0; i < dim; i++) {

		f >> v[i];
	}

	f.close();
}
void afisare(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
int elementMaximPoz(int v[], int dim) {
	int eMax = -1;
	int poz = 0;
	for (int i = 0; i < dim; i++) {
		if (v[i] > eMax) {
			eMax = v[i];
			poz = i;
		}
	}
	return poz;
}
int elementMinimPoz(int v[], int dim) {
	int eMin = 9999;
	int poz = 0;
	for (int i = 0; i < dim; i++) {
		if (v[i] < eMin) {
			eMin = v[i];
			poz = i;
		}
	}
	return poz;
}
int sumaSecventaMaxMin(int v[], int dim) {
	int pMax = elementMaximPoz(v, dim);
	int pMin = elementMinimPoz(v, dim);
	int sum = 0;
	for (int i = 0; i < dim; i++) {
		if (i >= pMin && i <= pMax) {
			sum += v[i];
		}
	}
	return sum;
}
bool numarPrim(int n) {
	int nrd = 0;
	for (int x = 1; x <= n; x++) {
		if (n % x == 0) {
			nrd++;
		}
	}
	if (nrd == 2) {
		return true;
	}
	else if (nrd == 1) {
		return true;
	}
	else {
		return false;
	}
}
int oglindit(int n) {
	int ogl = 0;
	while (n != 0) {
		int cifra = n % 10;
		ogl = ogl * 10 + cifra;
		n = n / 10;
	}
	return ogl;
}
void secventiereSol2(int v[], int dim) {
	int smax = 1;
	int dmax = 0;
	for (int i = 0; i < dim; i++) {
		if (numarPrim(v[i]) == true && numarPrim(v[i+1]) == true  &&   numarPrim(oglindit(v[i])) == true && numarPrim(oglindit(v[i+1])) == true) {
			int j = i;
			while (j + 1 < dim && numarPrim(v[j]) == true && numarPrim(v[j+ 1]) == true &&  numarPrim(oglindit(v[j])) == true && numarPrim(oglindit(v[j+1])) == true) {
				j++;
			}
			if (j - i + 1 > dmax - smax + 1) {;
				smax = i, dmax = j;

			}
		}
	}
	for (int f = 0; f < dim; f++) {
		if (f >= smax && f <= dmax) {
			cout << v[f] << " ";
		}
	}
	cout << endl;
}



#pragma once
#include "functii.h"
using namespace std;

void sol1() {
	//Se dă un şir format din n numere naturale distincte.Calculați suma elementelor din secvenţa ce uneşte cel mai mic şi cel mai mare element din şir.
	int v[100], d = 0;
	citire(v, d);
	int s = sumaSecventaMaxMin(v, d);
	cout << "Suma elementelor formate din secventa cuprinsa inte elementul minim si cel maxim (inclusiv) este: " << s << endl;
}	
void sol2() {
	//Se da un vector de numere intregi pozitive de cel putin doua cifre fiecare. Sa se determine cea mai lunga subsecventa de elemente consecutive prime, ale caror oglindire sunt tot numere prime.
	int v[100], d = 0;
	citire(v, d);
	secventiereSol2(v, d);
}
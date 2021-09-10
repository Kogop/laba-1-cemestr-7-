#include <iostream>

using namespace std;
const double pi = atan(1) * 4;
int roR = 1380, t0 = 6, roV = 1000, mu = 0.001, Senm = 0;
double nu = 0.09, Q = 0.038, D = 0.222, dn1 = 0.144, dv1 = 0.126, L1 = 2830, dn2 = 0.178, dv2 = 0.6, L2 = 60;

double Vsr() {
	return 4 * Q / (pi * dv1);


}
double SenM() {
	return t0 * dv1 / (nu * Vsr());

}
double Rem() {
	return roR * Vsr() * dv1 / (nu * (1 + (1 / 6.0) * SenM()));


}

double Lambda() {

	if (Rem()<2100)
	{
		return 64 / Rem();

	}
	else
	{
		return 0.316 / pow(Rem(), 0.25);
	}

}
double dPm() {

	return Lambda() * (L1 / dv1) * ((roR * pow(Vsr(), 2)) / 2) / 100000;

}
int main() {



	return 1;
}
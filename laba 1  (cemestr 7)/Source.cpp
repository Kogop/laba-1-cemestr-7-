#include <iostream>

using namespace std;
const double pi = atan(1) * 4;
int roR = 1380, t0 = 6, roV = 1000, mu = 0.001, Senm = 0;
double nu = 0.09, Q = 0.038, D = 0.222, dn1 = 0.144, dv1 = 0.126, L1 = 2830, dn2 = 0.178, dv2 = 0.6, L2 = 60;

double Vsr(double x) {
	return 4 * Q / (pi * x);


}
double SenM(double x) {
	return t0 * x / (nu * Vsr(x));

}
double Rem(double x) {
	return roR * Vsr(x) * x / (nu * (1 + (1 / 6.0) * SenM(x)));


}

double Lambda(double x) {

	if (Rem(x)<2100)
	{
		return 64 / Rem(x);

	}
	else
	{
		return 0.316 / pow(Rem(x), 0.25);
	}

}
double dPm(double x) {

	return Lambda(x) * (L1 / x) * ((roR * pow(Vsr(x), 2)) / 2) / 100000;

}

double VsrN(double y) {



	return 4 * Q / (pi * (D * D - y * y));


}
double SenMN(double y) {
	return t0 * (D * D - y * y) / (nu * VsrN(y));

}
double RemN(double y) {
	return roR * VsrN(y) * (D - y) / (nu * (1 + (1 / 8.0) * SenMN(y)));


}

double LambdaN(double y) {

	if (Rem(y) < 1600)
	{
		return 96 / RemN(y);

	}
	else
	{
		return 0.316 / pow(RemN(y), 0.25);
	}

}
double dPmN(double y) {

	return LambdaN(y) * (L1 / (D - y)) * ((roR * pow(VsrN(y), 2)) / 2) / 100000;

}
double DP(double x, double y) {

	return dPm(x) + dPmN(y);
	
}

double N(double x,double y) {

	return DP(x,y) * Q / (0.4 / 0.6);
}

double Voda() {
	double RemV = roV * Vsr(dv1) * dv1 / nu;
	double RemNV = roV;
}




int main() {
	
	cout << N(dv1, dn1);
	N();
		
	return 1;
}

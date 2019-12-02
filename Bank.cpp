#include "Bank.h"
#include <iostream>
#include "Myexception.h"
using namespace std;

void Bank::GetBill() {
	cout << "\nВведите число фунтов: ";
	cin >> pounds;
	cout << "Введите число ширлингов: ";
	cin >> shirlings;
	cout << "Введите число пенсов: ";
	cin >> penny;
	if (pounds < 0 || shirlings < 0 || penny < 0.0) {
		throw my_exception("отрицательных величин не бывает!");
	}
	if (penny - (int)penny * 1.0 == 0.5 || penny - (int)penny * 1.0 == 0) {
		if (shirlings >= 20 || penny >= 12) {
			throw my_exception("Превышение возможных значений!");
		}
		long double sum = 2.0 * penny + (long long)shirlings * 24 + pounds * 480;
		if (sum / 480 > 1000000000)
			throw my_exception("Превышена максимальная хранимая величина!");
		cout << endl;
	}
	else {
		throw my_exception("Неправильный формат пенни");
	}
}
void Bank::showBill() const {
	cout << pounds << " ph. " << shirlings << " sh. " << penny << " pen. \n";
}
Bank Bank:: operator - () const {
	return Bank(-pounds, shirlings, penny);
}
Bank Bank::operator + (const Bank& ph) const {
	long long f = pounds + ph.pounds;
	long s = shirlings + ph.shirlings;
	double p = penny + ph.penny;
	if (p >= 12) {
		p -= 12;
		s++;
	}
	if (s >= 20) {
		s -= 20;
		f++;
	}
	return Bank(f, s, p);
}
Bank Bank::operator - (const Bank& ph) const {
	int f = pounds - ph.pounds;
	int s = shirlings - ph.shirlings;
	double p = penny - ph.penny;
	if (p < 0) {
		p += 12;
		s--;
	}
	if (s < 0) {
		s += 20;
		f--;
	}
	return Bank(f, s, p);
}
void Bank::operator += (const Bank& ph) {
	pounds += ph.pounds;
	shirlings += ph.shirlings;
	penny += ph.penny;
	if (penny >= 12) {
		penny -= 12;
		shirlings++;
	}
	if (shirlings >= 20) {
		shirlings -= 20;
		pounds++;
	}
}
void Bank::operator -= (const Bank& ph) {
	pounds -= ph.pounds;
	shirlings -= ph.shirlings;
	penny -= ph.penny;
	if (penny < 0) {
		penny += 12;
		shirlings--;
	}
	if (shirlings < 0) {
		shirlings += 20;
		pounds--;
	}
}
bool Bank::operator == (const Bank& ph) const {
	return (pounds == ph.pounds && shirlings == ph.shirlings && penny == ph.penny);
}
bool Bank::operator != (const Bank& ph) const {
	return (pounds != ph.pounds || shirlings != ph.shirlings || penny != ph.penny);
}
bool Bank::operator > (const Bank& ph) const {
	return ((pounds * 240 + (long long)shirlings * 20 + penny * 2.0) > (ph.pounds * 240 + (long long)ph.shirlings * 20 + ph.penny * 2.0));
}
bool Bank::operator < (const Bank& ph) const {
	return !this->operator > (ph) && !this-> operator == (ph);
}
bool Bank::operator >= (const Bank& ph) const {
	return !(*this < ph);
}
bool Bank::operator <= (const Bank& ph) const {
	return !(*this > ph);
}
Bank::~Bank() {}

#include "Bank.h"
#include <iostream>
#include "Myexception.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Bank count1, count2;
	try {
		count1.GetBill();
		count2.GetBill();
	}
	catch (my_exception & error) {
		cout << error.what() << endl;
		exit(-1);
	}
	cout << "Унарный минус\n";
	(-count1).showBill();
	(-count2).showBill();
	cout << "Сумма\n";
	(count1 + count2).showBill();
	cout << "разность\n";
	(count1 - count2).showBill();
	cout << "\t\t\t----------------------------------\n" << "\t\t\t\tОПЕРАЦИИ СРАВНЕНИЯ \n";
	cout << "\t\t\t----------------------------------\n";
	if (count1 > count2)
		cout << "Первое больше второго\n";
	if (count1 < count2)
		cout << "Первое меньше второго\n";
	if (count1 == count2)
		cout << "Оба равны\n";
	if (count1 != count2)
		cout << "Оба не равны\n";
	if (count1 >= count2)
		cout << "Первое больше или равно второго\n";
	if (count1 <= count2)
		cout << "Первое меньше или равно второму\n\n";
	cout << "операция +=";
	count1 += count2;
	cout << "теперь 1 значение равно: "; count1.showBill();
	cout << "операция -=";
	count1 -= count2;
	cout << "теперь 1 значение равно: "; count1.showBill();
	return 0;
}

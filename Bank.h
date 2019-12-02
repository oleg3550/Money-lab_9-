#ifndef __bank_defined__
#define __bank_defined__
#include<exception>
class Bank {
private:
	long long  pounds;
	long shirlings;
	double penny;
public:
	Bank(long long ph = 0, long sh = 0, double pn = 0) : pounds(ph), shirlings(sh), penny(pn) { }
	void GetBill();
	void showBill() const;
	Bank operator - () const;
	Bank operator + (const Bank& ph) const;
	Bank operator - (const Bank& ph) const;
	void operator += (const Bank& ph);
	void operator -= (const Bank& ph);
	bool operator == (const Bank& ph) const;
	bool operator != (const Bank& ph) const;
	bool operator > (const Bank& ph) const;
	bool operator <= (const Bank& ph) const;
	bool operator < (const Bank& ph) const;
	bool operator >= (const Bank& ph) const;
	virtual ~Bank();
};
#endif

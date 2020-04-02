#pragma once
#include<iostream>
template<class T>

#ifndef basic_
#define basic_

class basic{
public:
	bool Make2DArray(T**& x, int rows, int columns) {
			x = new T * [rows];
			for (int i = 0; i < rows; i++) {
				x[i] = new int[columns];
			}
			return true;

	}

	void Delete2DArray(T**& x, int rows) {
		for (int i = 0; i < rows; i++) delete[]x[i];
		delete[] x;
		x = 0;
	}

	T* ChangeSize1D(T*& x, int size, int ToSize) {
		T* y = new T[ToSize];
		for (int i = 0; i < size; i++) {
			y[i] = x[i];
		}
		delete[]x;
		return y;
	}

	void print() {
		std::cout << "hello" << std::endl;
	}
};
#endif

#ifndef currency_
#define currency_
using std::cout; using std::ostream;
using std::istream;
enum sign { plus, minus };
class Currency {
	friend istream& operator>>(istream& in, Currency& x);
	friend ostream& operator<<(ostream& out, const Currency& x);
public:
	Currency(sign s = plus, unsigned long d = 0, unsigned int c = 0);
	~Currency() {};
	bool Set(sign s, unsigned long d, unsigned int c);
	bool Set(float a);
	sign Sign()const { if (amount > 0) return plus; else return minus; };
	unsigned long Dollars()const { if (amount < 0) return	(-amount) / 100; else return amount / 100; };
	unsigned int Cents()const { if (amount < 0) return -amount - Dollars() * 100; else return amount - Dollars() * 100; };
	Currency Add(const Currency& x) const ;
	Currency& Increment(const Currency& x) { amount += x.amount; return *this; };
	Currency operator+(const Currency& x) const;
	Currency& operator+=(const Currency& x) {
		amount += x.amount; return *this;
	}
	Currency operator-(const Currency& x)const;
	Currency operator*(const Currency& x)const;
	Currency operator/(const Currency& x)const;
	//void Output(ostream& out)const;
    //当不声明友元的时候，利用Output来重载流运算符
	//因为该函数不能访问x的amount，所以要借助Output函数来实现重载

	long Input(istream& in)const;
	long Subtract(Currency& x) {
		return amount - x.amount;
	}
	Currency Percent(double x) {
		Currency ans;
		ans.amount = amount * (x+ 0.001) / 100;
		return ans;
	}
private:
	long amount;
};

Currency::Currency(sign s, unsigned long d, unsigned int c) {
	if (c > 99) {
		std::cerr << "Cents should be < 100" << std::endl;
		exit(1);
	}
	amount = d * 100 + c;
	if (s == minus) amount = -amount;
}

bool Currency::Set(sign s, unsigned long d, unsigned int c) {
	if (c > 99) {
		std::cerr << "Cents should be < 100" << std::endl;
		return false;
	}
	amount = d * 100 + c;
	if (s == minus) amount = -amount;
	return true;
}

bool Currency::Set(float a) {
	sign sgn;
	if (a < 0) {sgn = minus; a = -a;
}
	else sgn = plus;
	amount = (a + 0.001) * 100;
	if (sgn = minus) amount = -amount;
	return true;
}

Currency Currency::operator+(const Currency& x)const {
	Currency ans;
	ans.amount = x.amount + amount;
	return ans;
}

Currency Currency::operator*(const Currency& x)const {
	Currency ans;
	ans.amount = x.amount * amount;
	return ans;
}
Currency Currency::operator-(const Currency& x)const {
	Currency ans;
	ans.amount = amount - x.amount;
	return ans;
}
Currency Currency::operator/(const Currency& x)const {
	if (x.amount == 0) {
		std::cerr << "should not be zero" << std::endl;
		exit(1);
	}
	Currency ans;
	ans.amount = amount / x.amount;
	return ans;
}
long Currency::Input(istream& in)const {
	long ans;
	in >> ans;
	return ans;
}


ostream& operator<<(ostream& out, const Currency& x) {
	//声明为友元，可以直接定义
	long a = x.amount;
	if (a < 0) { out << '-'; a = -a; }
	long d = a / 100;
	out << '$' << d << '.';
	int c = a - d * 100;
	if (c < 10) out << "0";
	out << c;
	return out;
}

istream& operator>>(istream& in, Currency& x) {
	double tmp;
	sign sgn;
	in >> tmp;
	if (tmp < 0) { sgn = minus; tmp = -tmp; }
	else sgn = plus;
	x.amount = (tmp + 0.001) * 100;
	if (sgn == minus) x.amount = -x.amount;
	return in;
}
#endif

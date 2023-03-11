#pragma once

#include <iostream>
using namespace std;

template <class T>
class myClass
{
private:
	T a;
	T b;

public:
	myClass();
	myClass(T x, T y);
	myClass(double d);

	void Print();
	void Input();

	template <class ST>
	friend std::ostream& operator<<(std::ostream& out, myClass<ST> const& mc);
	template <class ST>
	friend istream& operator>>(istream& out, myClass<ST>& mc);
};

/******************************************************/

template <class T>
myClass<T>::myClass()
{
	a = (T)0;
	b = (T)0;
}

template <class T>
myClass<T>::myClass(T x, T y)
{
	a = x;
	b = y;
}

template <class T>
myClass<T>::myClass(double d)
{
	// 2.34
	// a = 2
	// b = 34

	a = (T)d;
	b = (T)(d * 100 - a * 100);
}

template <class T>
void myClass<T>::Print()
{
	cout << "A: " << a << "\tB: " << b << endl << endl;
}

template <class T>
void myClass<T>::Input()
{
	cout << "Enter A B: ";
	cin >> a >> b;
}

template <class ST>
std::ostream& operator<<(std::ostream& out, myClass<ST> const& mc)
{
	out << "A: " << mc.a << "\tB: " << mc.b << endl << endl;
	return out;
}

template <class ST>
std::istream& operator>>(std::istream& in, myClass<ST>& mc)
{
	cout << "Enter A B: ";
	in >> mc.a >> mc.b;
	return in;
}
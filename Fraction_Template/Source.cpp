//Justin Ritchey. MP3. 10/5/2020. Fraction_Math_Program: Meant to overload operators while using fractions. Will ask user to enter two fractions and what what want to do with those fractions. Also has ++ -- ~ - ! >> << used for the programmer.

#include "fraction.h"
#include "FractionTemplate.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ostream>


using namespace std;

void main()
{
	
	long t = 10000;
	long b = 20000;
	ofstream out;
	Fraction<char> bu;


	Fraction<long> a(t, b);
	Fraction<long> u(200, 4302);
	Fraction<char> j('t', 'b');
	Fraction<char> f('y', 'l');
	Fraction<int> c(2, 5);
	Fraction<int> q(7, 2);
	Fraction<short> au(9, 3);
	Fraction<short> yu(4, 10);

	bu=bu.input(out);

	au=au.subFrac(yu);
	f=f.addFrac(bu);
	a=a.multFrac(u);
	c=c.divFrac(q);

	au.print();
	f.print();
	a.print();
	c.print();
	
	system("PAUSE");
}
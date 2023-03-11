#pragma once
#define FRACTION_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

template <class T>
class Fraction
{
private:
	T num;
	T denom;


public:

	//constructors
	Fraction();                           //default constructor
	Fraction(T x);                        //constructor with only numerator entered
	Fraction(T x, T y);                   //constructor with both num and demon entered


	//functions
	Fraction addFrac(Fraction<T>);           //add fractions that returns a new variable
	Fraction subFrac(Fraction<T>);           //subtract fractions that returns a new variable
	Fraction multFrac(Fraction<T>);          //Multiply fractions that returns a new variable
	Fraction divFrac(Fraction<T>);           //Divide fractions that returns a new variable

	void addFrac(Fraction<T>, Fraction<T>);     //add fractions that updates a current value
	void subFrac(Fraction<T>, Fraction<T>);     //Subtract fractions that updates a current value
	void multFrac(Fraction<T>, Fraction<T>);    //Mulitply fractions that updates a current value
	void divFrac(Fraction<T>, Fraction<T>);     //Divide fractions that updates a current value

	T gcd(T x, T y);                    //function to find the gcd of two numbers

	Fraction<T> input(ofstream&);            //function to gather num and denom from user

	const void print();          //function to print out to answer to console and file

	// operator functions for MP3
	Fraction operator+(const Fraction<T>&rhs);     //fucntion to add two fractions and return a new fraction
	Fraction operator-(const Fraction<T>&rhs);     //fucntion to subtract two fractions and return a new fraction
	Fraction operator/(const Fraction<T>&rhs);     //fucntion to add divide fractions and return a new fraction
	Fraction operator*(const Fraction<T>&rhs);     //fucntion to add multiply fractions and return a new fraction
	Fraction operator=(const Fraction<T>&rhs);     //fucntion to add set a fraction equal to anohter and return a new fraction
	Fraction operator+=(const Fraction<T>&rhs);    //fucntion to add two fractions and update current variable
	Fraction operator-=(const Fraction<T>&rhs);    //fucntion to add subtract fractions and update current variable
	Fraction operator*=(const Fraction<T>&rhs);    //fucntion to add multiply fractions and update current variable
	Fraction operator/=(const Fraction<T>&rhs);    //fucntion to add divide fractions and update current variable

	Fraction &operator-();                        //changing a number to a negative
	Fraction &operator~();                        //chnaging num and denom
	Fraction &operator++();                       //++x adding 1/1 first (before any other op on the variable)
	Fraction &operator--();                       //--x subtracting 1/1 first (before any other op on the variable)

	Fraction operator++(int);                     //x++ adding 1/1 after any operation
	Fraction operator--(int);                     //x-- subtracting 1/1 after any operation

	// << and >> operators
	template <class ST>
	friend std::ostream& operator<<(std::ostream& out, Fraction<ST> const& r);      //cout operation
	template <class ST>
	friend istream& operator>>(istream& out, Fraction<ST>& r);                      //cin operation


	//compare fucntions
	bool operator>(const Fraction<T>& rhs) const;                //greater than function
	bool operator<(const Fraction<T>& rhs) const;                //less than function
	bool operator ==(const Fraction<T>& rhs) const;              //are they equal function

	bool operator>=(const Fraction<T>& rhs) const;               //greater than or equal to function
	bool operator<=(const Fraction<T>& rhs) const;               //less than or equal to function
	bool operator !=(const Fraction<T>& rhs) const;              //not equal to fucntion
	bool operator !();                                        //not function

	//Casting functions
	operator double() const;                                  //convert to double function
	operator float() const;                                   //convert to float function
};

//constructors
template <class T>
Fraction<T>::Fraction()                                      //Default constructor
{
	num = (T)0;
	denom = (T)1;
}
template <class T>
Fraction<T>::Fraction(T x)                         //Constructor when only numerator is entered
{
	num = x;
	denom = (T)1;
}
template <class T>
Fraction<T>::Fraction(T x, T y)      //Consturctor when both numerator and denomator are entered
{
	num = x;
	denom = y;
}

//functions
template <class T>
Fraction<T> Fraction<T>::input(ofstream& output)                                      //function to gather numerator and denomantor from user
{
	Fraction<T> a;                                                                 //used the the third function withen the program for all math functions
	T numerator = 0;                                                       //holds the numerator
	char abrv = '\0';                                                           //holds the "/" when the user enters the fraction
	T denominator = 0;                                                        //holds the denominator entered by the user

	cout << "Please enter a fraction(Numerator/Denominator): ";                 //Asking the user for the fration
	output << "Please enter a fraction(Numerator/Denominator): ";
	cin >> numerator;

	if (cin.peek() == '\n')                                                     //if the user presses enter instead of entering a number this will update the denominator to 1
	{
		denominator = 1;
	}
	else                                                                        //otherwise the denominator will be placed into its variable
	{
		cin >> abrv >> denominator;
	}

	if (denominator == 0)                                                       //if the entered denominator is 0, this will force an update until a number other than 0 is entered.
	{
		while (denominator == 0)
		{
			cin.ignore();
			cout << "Denominator cannot be 0. Please re-enter a new denominator: ";
			output << "Denominator cannot be 0. Please re-enter a new denominator: ";
			if (cin.peek() == '\n')                                            //if user presses enter this will make the denomniator 1
			{
				denominator = 1;
			}
			else                                                               //otherwise the denominator will be placed
			{
				cin >> denominator;
			}

		}
	}

	if (floor(numerator) == numerator)                                          //checking for a decimal place if there is one will create the function variable with the correct constructor
	{
		a.num = numerator;
		a.denom = denominator;
	}
	else                                                                        //sending to the decimal constructor if there is decimal places
	{
		a = Fraction(numerator);
	}

	return a;                                                                   //returning the fraction
}
template <class T>
Fraction<T> Fraction<T>::addFrac(Fraction<T> x)                                          //a=b.add(x)   adds two fractions and returns a new fraction
{
	Fraction<T> a;
	T numb = 0;                                                               //number to hold the denominator for multuplying after it has been updated
	numb = denom;
	T gcd1;                                                                   //will hold the gcd of the numerator and denominator

	denom = numb * x.denom;                                                     //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	num = x.denom * num;
	x.denom = numb * x.denom;
	x.num = numb * x.num;

	a.num = num + x.num;                                                       //now that the denominators are equal I am am adding the numerators and assining to the new fraction
	a.denom = denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator


	a.num = a.num / gcd1;                                                         //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;

	return a;                                                                  //returning the new fraction after adding two.
}
template <class T>
Fraction<T> Fraction<T>::subFrac(Fraction<T> x)                                         //a=b.subFrac(x) subtracts two fractions and returns a new fraction
{
	Fraction<T> a;

	T numb = denom;                                                          //number to hold the denominator for multuplying after it has been updated
	T gcd1;                                                                  //will hold the gcd of the numerator and denominator

	denom = numb * x.denom;                                                    //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	num = x.denom * num;
	x.denom = numb * x.denom;
	x.num = numb * x.num;

	a.num = num - x.num;                                                       //subtracting the first numerator from the second numerator and assinging to the new fraction
	a.denom = denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator


	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;


	return a;
}
template <class T>
Fraction<T> Fraction<T>::multFrac(Fraction<T> x)                                        //a=b.multFrac(x) multiplies two fractions and returns a new fraction
{
	Fraction<T> a;
	T gcd1 = 0;                                                              //will hold the gcd of the numerator and denominator

	a.num = x.num * num;                                                       //multiplying the numerators and denominators and updating the new fraction
	a.denom = x.denom * denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator

	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;

	return a;
}
template <class T>
Fraction<T> Fraction<T>::divFrac(Fraction<T> x)                                         //a=b.divFrac(x)  divides two fraction and returns a new fraction
{
	Fraction<T> a;

	T gcd1 = 0;                                                              //will hold the gcd of the numerator and denominator

	a.num = num * x.denom;                                                     //multiplying the first fraction by the recipricol of the second fraction
	a.denom = denom * x.num;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator

	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;

	return a;
}

template <class T>
void Fraction<T>::addFrac(Fraction<T> x, Fraction<T> y)                                //a.addFrac(x, y)  adds two fractiosn and updates a current fraction
{
	T numb = NULL;                                                             //int to hold the value of the denominator to multiply with after the denominator has been updated
	numb = x.denom;
	T gcd1;                                                                 //will hold the gcd of the num and denom

	x.denom = numb * y.denom;                                                 //multiplying the fractions by the opposite fractions denominators to make the denominators equal                                                
	x.num = x.num * y.denom;

	y.denom = numb * y.denom;
	y.num = numb * y.num;

	num = y.num + x.num;                                                      //adding the numerators and updating the current fraction
	denom = y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;

}
template <class T>
void Fraction<T>::subFrac(Fraction x, Fraction y)                                //a.subFrac(x, y) subtracts two fractionsa dn updates the current fraction
{
	int numb = 0;                                                             //int to hold the value of the denominator to multiply with after the denominator has been updated
	numb = x.denom;
	int gcd1;                                                                 //will hold the gcd of the num and denom

	x.denom = numb * y.denom;                                                 //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	x.num = x.num * y.denom;

	y.denom = numb * y.denom;
	y.num = numb * y.num;

	num = x.num - y.num;                                                      //subtracting the numerators and updating the current fraction
	denom = y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;
}
template <class T>
void Fraction<T>::multFrac(Fraction<T> x, Fraction<T> y)                               //a.multFrac(x, y)  multuplys two fractions and updates a current fraction
{
	T gcd1 = NULL;                                                             //will hold the gcd of the num and denom

	num = x.num * y.num;                                                      //multiplying the fractions 
	denom = x.denom * y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;

}
template <class T>
void Fraction<T>::divFrac(Fraction<T> x, Fraction<T> y)                               //a.divFrac(x, y) divides two fractions and updates a current fraction object
{
	T gcd1 = NULL;                                                            //will hold the gcd of the num and denom

	num = x.num * y.denom;                                                   //multiplying the first fraction by the recipricol of the second
	denom = x.denom * y.num;

	gcd1 = gcd(num, denom);                                                  //finding the gcd of the num and denom                      

	num = num / gcd1;                                                        //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;
}
template <class T>
T Fraction<T>::gcd(T x, T y)                                       //function to find the GCD of 2 numbers
{
	T gcdTotal = NULL;
	T remainder = NULL;

	if (x == 0)                                                       //if the numerator is 0, it will return 0. 
	{
		return 0;
	}
	else if (x == y)                                                    //if the num and denom are equal it will return the numerator as the fraction will be a whole number
	{
		return x;
	}
	else                                                              //finding the remainder using that to find the lowest term of gcd
	{
		remainder = (x % y);

		while (remainder < 0 || remainder >0)
		{
			x = y;
			y = remainder;
			remainder = (x % y);

		}
		gcdTotal = y;
	}

	return gcdTotal;

}
template <class T>
const void Fraction<T>::print()                          //function to print out the result to file and console
{
	cout << "Here is the result: " << num << "/" << denom << "\n";
}
template <class T>
Fraction<T> Fraction<T>::operator+(const Fraction<T>& rhs)                     //funtion to do addation with fractions and return a new fraction
{
	Fraction k;
	k = this->addFrac(rhs);
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator-(const Fraction<T>& rhs)                      //funtion to do subtraction with fractions and return a new fraction
{
	Fraction<T> k;
	k = this->subFrac(rhs);
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator*(const Fraction<T>& rhs)                     //funtion to do multiplication with fractions and return a new fraction
{
	Fraction<T> k;
	k = this->multFrac(rhs);
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator/(const Fraction<T>& rhs)                      //funtion to do divison with fractions and return a new fraction
{
	Fraction<T> k;
	k = this->multFrac(rhs);
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator=(const Fraction<T>& rhs)                     //funtion to set one fraction equal to *this* fraction and return it
{
	num = rhs.num;
	denom = rhs.denom;
	return *this;
}
template <class T>
Fraction<T> Fraction<T>::operator+=(const Fraction<T>& rhs)                    //function to do addtion to two fractions and update the current fraction
{
	Fraction<T> k;
	k = this->addFrac(rhs);
	num = k.num;
	denom = k.denom;
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator-=(const Fraction& rhs)                    //function to do subtraction and update the current fraction
{
	Fraction<T> k;
	k = this->subFrac(rhs);
	num = k.num;
	denom = k.denom;
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator*=(const Fraction<T>& rhs)                    //function to do mulitplicationa and update the current fractuon
{
	Fraction<T> k;
	k = this->multFrac(rhs);
	num = k.num;
	denom = k.denom;
	return k;
}
template <class T>
Fraction<T> Fraction<T>::operator/=(const Fraction<T>& rhs)                   //function to do dvision and reutrn the current fraction
{
	Fraction<T> k;
	k = this->divFrac(rhs);
	num = k.num;
	denom = k.denom;
	return k;
}
template <class T>
Fraction<T>& Fraction<T>::operator-()              //reutrns a negative number and does not update orignal
{
	this->num = -num;
	return *this;
}
template <class T>
Fraction<T>& Fraction<T>::operator~()              //swaps num and denom
{
	Fraction<T> tmp = *this;
	this->num = tmp.denom;
	this->denom = tmp.num;
	return *this;
}
template <class T>
Fraction<T>& Fraction<T>::operator++()             //++x done before the rest of operation
{
	Fraction<T> tmp(1, 1);
	*this = this->addFrac(tmp);
	return *this;
}
template <class T>
Fraction<T>& Fraction<T>::operator--()             //--x done before rest of operation
{
	Fraction<T> tmp(1, 1);
	*this = this->subFrac(tmp);
	return *this;
}
template <class T>
Fraction<T>  Fraction<T>::operator++(int)           //x++  done after operation
{
	Fraction<T> tmp = *this;
	Fraction<T> tmp2(1, 1);
	*this = this->addFrac(tmp2);
	return tmp;
}
template <class T>
Fraction<T> Fraction<T>::operator--(int)           //x--  done after operation
{
	Fraction<T> tmp = *this;
	Fraction<T> tmp2(1, 1);
	*this = this->subFrac(tmp2);
	return tmp;
}
template <class ST>
std::ostream& operator<<(std::ostream& out, Fraction<ST> const& r)        //sets the cout
{
	out << r.num << "/" << r.denom;
	return out;
}
template <class ST>
std::istream& operator>>(std::istream& out, Fraction<ST>& r)             //sets the cin
{
	cout << "Enter a num and denom: ";
	out >> r.num >> r.denom;
	return out;
}
template <class T>
bool Fraction<T>::operator >(const Fraction<T>& rhs) const        //checks if one fractions is greater than the other
{
	int tmp;
	int tmp2;

	tmp = num * rhs.denom;
	tmp2 = rhs.num * denom;

	bool b = tmp > tmp2;
	return b;
}
template <class T>
bool Fraction<T>::operator <(const Fraction<T>& rhs) const         //checks in one fraction is less than the other
{
	int tmp;
	int tmp2;

	tmp = num * rhs.denom;
	tmp2 = rhs.num * denom;

	bool b = tmp < tmp2;
	return b;
}
template <class T>
bool Fraction<T>::operator ==(const Fraction<T>& rhs) const        //checks if both fractions are equal (checks for gcd)
{
	T num1;
	T num2;

	num1 = rhs.denom * num;
	num2 = denom * rhs.num;

	bool b = (num1 == num2);
	return b;
}
template <class T>
bool Fraction<T>::operator >=(const Fraction<T>& rhs) const       //checks if one fraction is greater than or equal to another
{
	bool b = (*this > rhs);
	if (b)
		return true;
	bool c = (*this == rhs);
	if (c)
		return true;
	return false;

}
template <class T>
bool Fraction<T>::operator <=(const Fraction<T>& rhs) const         //checks if one fractions is less than or eqaul to another
{
	bool b = (*this < rhs);
	if (b)
		return true;
	bool c = (*this == rhs);
	if (c)
		return true;
	return false;
}
template <class T>
bool Fraction<T>::operator !=(const Fraction<T>& rhs) const         //checks if one fractons is not equal to another
{
	return !(*this == rhs);
}
template <class T>
bool Fraction<T>::operator !()                                   //checks what is current and returns the opposite
{
	if (this)
		return false;
	return true;
}
template <class T>
Fraction<T>::operator double() const                              //returns the fraction as a double value
{
	double j;
	j = (double)num / (double)denom;
	return j;
}
template <class T>
Fraction<T>::operator float() const                               //returnsa the fraction as a float
{
	float j;
	j = (float)num / (float)denom;
	return j;
}

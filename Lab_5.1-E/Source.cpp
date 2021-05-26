//Source.cpp

#include <iostream>
#include "BitString.h"

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

void Call_Bad() throw(int)
{
	throw 'x';
}

int main()
{
	set_unexpected(_unexpected_to_bad);

	cout << "Number of elements of class BitString : " << BitString::Count() << endl;

	try
	{
		BitString o;
		int n;
		int z;
		cin >> o;
		cout << o << endl << endl;

		cout << "Size of class: " << sizeof(o) << endl;
		cout << "Number of elements of class BitString : " << BitString::Count() << endl;

		// ShiftLeft
		cout << "How many bits do you want to shift left?" << endl;
		cout << "Input:  "; cin >> n;
		BitString a = o << n;
		cout << a << endl << endl;

		// ShiftRight
		cout << "How many bits do you want to shift right?" << endl;
		cout << "Input:  "; cin >> z;
		BitString b = o >> z;
		cout << b << endl << endl;

		// Xor
		cout << "Xor: " << endl;
		cout << (a ^ b) << endl;

		cout << "try o--" << endl;
		try
		{
			o--;
		}
		catch (MyDerivedException a)
		{
			cerr << a.What() << endl << endl;
		}
		catch (MyDerivedException* a)
		{
			cerr << a->What() << endl << endl;
		}
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}
	cout << "Number of elements of class BitString : " << BitString::Count() << endl;



	cout << "--------------------------------------------------------" << endl;

	BitString N;
	cin >> N;
	cout << N;

	cout << "Number of elements of class BitString : " << BitString::Count() << endl;

	cout << endl << "try N++" << endl;
	try
	{
		N++;
	}
	catch (MyException& a)
	{
		cerr << "Exception: " << a.What() << endl;
	}
	catch (logic_error a)
	{
		cerr << "Exception: " << a.what() << endl;
	}

	try
	{
		Call_Bad();
	}
	catch (bad_exception)
	{
		cerr << "catch (bad_exception)" << endl;
	}

	return 0;
}

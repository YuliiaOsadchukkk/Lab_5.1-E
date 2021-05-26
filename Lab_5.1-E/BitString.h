//BitString.h
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "MyException.h"
#include "MyDerivedException.h"
#include "Object.h"


class BitString : public Object
{
private:
	long first;
	long second;

public:
	BitString();
	BitString(long first, long second) throw(logic_error);
	BitString(const BitString& v);

	double GetFirst() const { return first; }
	double GetSecond() const { return second; }
	void SetFirst(double value) { first = value; }
	void SetSecond(double value) { second = value; }


	BitString& operator = (const BitString& pr);
	operator string() const;

	BitString& operator --() throw(MyDerivedException);
	BitString& operator ++() throw(MyException);
	BitString operator --(int) throw(MyDerivedException);
	BitString operator ++(int) throw(logic_error);

	friend ostream& operator <<(ostream& out, const BitString& r);
	friend istream& operator >>(istream& in, BitString& r) throw(logic_error);


	friend BitString operator ^ (const BitString& a, const BitString& b);
	friend BitString operator << (const BitString& a, int n);
	friend BitString operator >> (const BitString& a, int n);
};


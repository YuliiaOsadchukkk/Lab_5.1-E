//BitString.cpp

#include "BitString.h"
using namespace std;


BitString::BitString()
    : first(0), second(0)
{}

BitString::BitString(long first, long second) throw(logic_error)
{
    if ((first < 0 || first>20) && (second < 0 || second>20))
        throw logic_error("Condition is not met");

    this->SetFirst(first);
    this->SetSecond(second);

}

BitString::BitString(const BitString& v)
{
    first = v.first;
    second = v.second;
}


BitString& BitString::operator = (const BitString& pr)
{
    first = pr.first;
    second = pr.second;
    return *this;
}
BitString::operator string() const
{
    stringstream ss;
    ss << first << ", " << second;
    return ss.str();
}





ostream& operator << (ostream& out, const BitString& r)
{
    out << string(r);
    return out;
}
istream& operator >> (istream& in, BitString& r) throw(logic_error)
{
    long first, second;
    cout << "first = "; in >> first;
    cout << "second = "; in >> second;

    if ((first < 0 || first>20) && (second < 0 || second>20))
        throw logic_error("Condition is not met");

    r.SetFirst(first);
    r.SetSecond(second);

    return in;
}




BitString& BitString::operator --() throw(MyDerivedException)
{
    --first;
    if (first < 0)
        throw new MyDerivedException();
    return *this;
}

BitString& BitString::operator ++() throw(MyException)
{
    ++first;
    if (second > 20)
        throw logic_error("Number is bigger than 20");
    return *this;
}

BitString BitString::operator --(int) throw(MyDerivedException)
{
    BitString a(*this);
    first--;
    if (first < 0)
        throw MyDerivedException();
    return a;
}

BitString BitString::operator ++(int) throw(logic_error)
{
    BitString a(*this);
    second++;
    if (second > 20)
        throw logic_error("Number is bigger than 20");
    return a;
}


////////////////////////////////////////////////////////////////////////////////
BitString operator ^ (const BitString& a, const BitString& b)
{
    BitString t;
    t.first = a.first ^ b.first;
    t.second = a.second ^ b.second;
    return t;
}

BitString operator << (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.first << 1;
        tmp[1] = t.second << 1;
        if (t.first & (1 << last_bit))
            tmp[1] |= (1 << 0);
        else
            tmp[1] &= ~(1 << 0);
        /*
        if (t.second & (1 << last_bit))
            tmp[0] |= (1 << 0);
        else
            tmp[0] &= ~(1 << 0);
            */
        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}

BitString operator >> (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.first >> 1;
        tmp[1] = t.second >> 1;
        if (t.first & (1 << 0))
            tmp[1] |= (1 << last_bit);
        else
            tmp[1] &= ~(1 << last_bit);
        /*
        if (t.second & (1 << 0))
            tmp[0] |= (1 << last_bit);
        else
            tmp[0] &= ~(1 << last_bit);
            */
        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}


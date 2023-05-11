//Author: Kevin Zhu
//Assignment 6

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

const int COLUMN_WIDTH = 60;

bool isAcceptable(char c) //lower and uppercase alphabets and digits.
{
    return (((c >= 48) && (c <= 57)) || ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)));
}

class MyString
{
private:
    string str; //a phrase may contain one to five words
    int frequency;
public:
    MyString()
    {
        string str = "";
        int frequency = 0;
    };
    MyString(string s)
    {
        str = s;
        frequency = 1;
    }

    bool operator ==(const MyString& rhs) const //used in linear search
    {
        return (str == rhs.str);
    }

    bool operator >(MyString s) const //used in sort algorithm
    {
        return (frequency > s.frequency);
    }

    bool operator <(MyString s) const //used in sort algorithm
    {
        return (frequency < s.frequency);
    }

    MyString operator ++(int) //used to increment the frequency
    {
        frequency++;
        return *this;
    }

    friend ostream& operator <<(ostream& o, const MyString& obj);
};

ostream& operator<<(ostream& o, const MyString& obj) //output to file
{
    o << setw(40) << obj.str << obj.frequency << endl;
    return o;
}

bool isChar(string str)
{
    return (str.length() == 1);
}

string removePunctuation(string str)
{
    string result = "";
    if (isChar(str))
    {
        result = toupper(str[0]);
        return result;
    }

    if (isAcceptable(str[0]))
        result += toupper(str[0]);

    for (int i = 1; i < str.length() - 1; i++)
        result += toupper(str[i]);

    if (isAcceptable(str[str.length() - 1]))
        result += toupper(str[str.length() - 1]);

    return result;
}
#endif
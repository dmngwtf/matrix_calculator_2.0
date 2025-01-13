#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string>
#include <utility>


bool isStringOnlySpaces(const std::string& str);
int GCD (int a, int b);
std::string checkout(std::string str);
std::pair<int, int> convertion(std::string number);
void Normalize ();
class Fraction {
private:
    void Normalize ();
    int num = 1;
    int den = 1;
public:
    Fraction(int n, int d) : num(n), den(d) {
        Normalize();
    }
    Fraction(int n) : num(n), den(1) {}
    Fraction(): num(0), den(1) {}
    Fraction(const Fraction& other) : num(other.num), den(other.den) {}
    Fraction(const Fraction&& other) : num(other.num), den(other.den) {}
    Fraction(std::string str) : num(1), den(1) {
        std::pair<int,int>fr = convertion(str);
        num = fr.first;
        den = fr.second;
        Normalize();
    }
    Fraction(const char * str);
    Fraction operator - () const;
    Fraction& operator += (const Fraction& other);
    Fraction& operator += (const Fraction&& other);
    Fraction& operator -= (const Fraction& other);
    Fraction& operator -= (const Fraction&& other);
    Fraction& operator *= (const Fraction& other);
    Fraction& operator *= (const Fraction&& other);
    Fraction& operator /= (const Fraction& other);
    Fraction& operator /= (const Fraction&& other);
    Fraction& operator = (const Fraction& other);
    Fraction& operator = (const Fraction&& other);
    bool operator == (const Fraction& other) const;
    friend std::ostream& operator << (std::ostream& out, Fraction fraction);
    friend std::istream& operator >> (std::istream& in, Fraction& fraction);
    friend std::string FractionToString (const Fraction& fraction);
};
Fraction operator / (const Fraction& f1, const Fraction& f2);
Fraction operator / (const Fraction& f1, const Fraction&& f2);
Fraction operator * (const Fraction& f1, const Fraction&& f2);
Fraction operator * (const Fraction& f1, const Fraction& f2);
Fraction operator - (Fraction& f1, Fraction& f2);
Fraction operator - (Fraction& f1, Fraction&& f2);
Fraction operator - (Fraction&& f1, Fraction&& f2);
Fraction operator + (Fraction& f1, Fraction& f2);
Fraction operator + (Fraction& f1, Fraction&& f2);
#endif // FRACTION_H

#include "fraction.h"
bool isStringOnlySpaces(const std::string& str) {
    for (char c : str) {
        if (!std::isspace(c)) {
            return false;
        }
    }
    return true;
}
std::string FractionToString (const Fraction& fraction) {
    std::string res = "";
    if (fraction.den != 1 && fraction.num != 0) {
        res += std::to_string(fraction.num) + '/' + std::to_string(fraction.den);
    } else {
        res += std::to_string(fraction.num);
    }
    return res;
}

void Fraction::Normalize () {
    int gcd = GCD(num, den);
    num/=gcd;
    den/=gcd;
    if (den < 0) {
        den*=(-1);
        num*=(-1);
    }
}

Fraction& Fraction::operator += (const Fraction& other) {
    num = num*other.den + den*other.num;
    den *= other.den;
    Normalize();
    return *this;
}

Fraction& Fraction::operator += (const Fraction&& other) {
    num = num*other.den + den*other.num;
    den *= other.den;
    Normalize();
    return *this;
}


Fraction& Fraction::operator -= (const Fraction& other) {
    *this += (-other);
    return *this;
}

Fraction& Fraction::operator -= (const Fraction&& other) {
    *this += (-other);
    return *this;
}

Fraction& Fraction::operator *= (const Fraction& other) {
    num *= other.num;
    den *= other.den;
    Normalize();
    return *this;
}

Fraction& Fraction::operator *= (const Fraction&& other) {
    num *= other.num;
    den *= other.den;
    Normalize();
    return *this;
}

Fraction& Fraction::operator /= (const Fraction& other) {
    int num1 = other.den;
    int den1 = other.num;
    Fraction temp(num1, den1);
    *this *= temp;
    return *this;
}

Fraction& Fraction::operator /= (const Fraction&& other) {
    int num1 = other.den;
    int den1 = other.num;
    Fraction temp(num1, den1);
    *this *= temp;
    return *this;
}

Fraction& Fraction::operator = (const Fraction& other) {
    num = other.num;
    den = other.den;
    Normalize();
    return *this;
}

Fraction& Fraction::operator = (const Fraction&& other) {
    num = other.num;
    den = other.den;
    Normalize();
    return *this;
}

bool Fraction::operator == (const Fraction& other) const {
    return num == other.num && den == other.den;
}

std::istream& operator >> (std::istream& in, Fraction& fraction) {
    std::string number;
    in >> number;
    std::pair<int, int> temp = convertion(number);
    fraction.num = temp.first;
    fraction.den = temp.second;
    fraction.Normalize();
    return in;
}

std::ostream& operator << (std::ostream& out, Fraction fraction) {
    if (fraction.den != 1 && fraction.num != 0) {
        out << fraction.num << '/' << fraction.den;
    } else {
        out << fraction.num;
    }

    return out;}

std::string checkout(std::string str) {
    if (isStringOnlySpaces(str) || str.size() == 0) {
        return "Empty";
    }
    bool flag_decimal = 0;
    bool flag_dot = 0;
    bool flag_minus_num = 0;
    bool flag_minus_den = 0;

    for (size_t i = 0; i != str.size(); ++i) {

        if (str[i] == '-') {
            if (i != 0 && flag_decimal == 0 || i == str.size()) {
                return std::string("Error");
            } else if (i == 0) {
                flag_minus_num = 1;
            } else if (i != 0 && (str[i-1] == '\\' || str[i-1] == '/')) {
                flag_minus_den = 1;
            }
        } else if (str[i] == ',' || str[i] == '.') {
            if (i == 0 || i == str.size()-1) {
                return std::string("Error");
            } else if (flag_dot == 1) {
                return std::string("Error");
            } else {
                flag_dot = 1;
            }
        } else if (str[i] == '\\' || str[i] == '/') {
            if (i == 0 || i == str.size()-1 || str[i-1] == '-') {
                return std::string("Error");
            } else if (flag_decimal == 1) {
                return std::string("Error");
            } else {
                flag_decimal = 1;
            }
        } else if (!isdigit(str[i])) {
            return std::string("Error");
        }
    }

    if (flag_decimal == 1 && flag_dot == 1) {
        return std::string("Error");
    } else if (flag_decimal == 1) {
        return std::string("Fraction");
    } else if (flag_dot == 1) {
        return std::string("Double");
    }
    return std::string("Integer");
}
Fraction operator - (Fraction& f1, Fraction& f2) {
    Fraction new_fraction = f1;
    new_fraction -= f2;
    return new_fraction;
}

Fraction operator - (Fraction& f1, Fraction&& f2) {
    Fraction new_fraction = f1;
    new_fraction -= f2;
    return new_fraction;
}
Fraction operator - (Fraction&& f1, Fraction&& f2) {
    Fraction new_fraction = f1;
    new_fraction -= f2;
    return new_fraction;
}
Fraction operator * (const Fraction& f1, const Fraction& f2) {
    Fraction new_fraction = f1;
    new_fraction *= f2;
    return new_fraction;
}
Fraction operator * (const Fraction& f1, const Fraction&& f2) {
    Fraction new_fraction = f1;
    new_fraction *= f2;
    return new_fraction;
}
Fraction operator / (const Fraction& f1, const Fraction&& f2) {
    Fraction new_fraction = f1;
    new_fraction /= f2;
    return new_fraction;
}
Fraction operator / (const Fraction& f1, const Fraction& f2) {
    Fraction new_fraction = f1;
    new_fraction /= f2;
    return new_fraction;
}
Fraction Fraction::operator - () const{
    int num1 = -num;
    int den1 = den;
    Fraction temp(num1, den1);
    return temp;
}
Fraction operator + (Fraction& f1, Fraction& f2) {
    Fraction new_fraction = f1;
    new_fraction += f2;
    return new_fraction;
}

Fraction operator + (Fraction& f1, Fraction&& f2) {
    Fraction new_fraction = f1;
    new_fraction += f2;
    return new_fraction;
}

int GCD (int a, int b){ return b ? GCD(b, a % b) : a;}
std::pair<int, int> convertion(std::string number) {
    std::string type = checkout(number);

    if (type == "Empty") {
        return {0,1};
    }
    if (type == "Error") {
        throw "Error";
    } else if (type == "Fraction" || type == "-Fraction") {
        size_t i = 0;
        std::string numenator;
        std::string denominator;
        while (number[i] != '/' && number[i] != '\\') {
            numenator += number[i];
            ++i;
        }
        ++i;
        while (i != number.size()) {
            denominator += number[i];
            ++i;
        }
        return {std::stoi(numenator), std::stoi(denominator)};
    } else if (type == "Integer") {
        return {stoi(number), 1};
    } else if (type == "Double") {
        size_t i = 0;
        std::string numenator;
        std::string denominator;

        while (number[i] != '.' && number[i] != ',') {
            numenator += number[i];
            ++i;
        }
        ++i;
        while (i != number.size()) {
            denominator += number[i];
            ++i;
        }

        int len_den = denominator.size();
        int num;

        if (stoi(numenator)*stoi(denominator) >= 0) {
            num = abs(stoi(numenator) * pow(10, len_den)) + abs(stoi(denominator));
        } else {
            num = -(abs(stoi(numenator) * pow(10, len_den)) + abs(stoi(denominator)));
        }
        int den = pow(10, len_den);
        return {num, den};
    }
    return {1, 1};
}

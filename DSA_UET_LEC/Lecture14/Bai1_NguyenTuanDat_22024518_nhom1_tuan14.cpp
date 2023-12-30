#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }

    Complex(double r, double i)
    {
        real = r;
        img = i;
    }

    double getReal() const
    {
        return real;
    }

    double getImg() const
    {
        return img;
    }

    virtual void add(const Complex& other) = 0;
    virtual void subtract(const Complex& other) = 0;
    virtual void multiply(const Complex& other) = 0;
    virtual void divide(const Complex& other) = 0;

};

class MyComplex : public Complex
{
public:
    MyComplex() : Complex() {}
    MyComplex(double r, double i) : Complex(r, i) {}

    void add(const Complex& other)
    {
        double r = getReal() + other.getReal();
        double i = getImg() + other.getImg();
        cout << r << " + " << i << "i" << endl;
    }

    void subtract(const Complex& other)
    {
        double r = getReal() - other.getReal();
        double i = getImg() - other.getImg();
        cout << r << " + " << i << "i" << endl;
    }

    void multiply(const Complex& other)
    {
        double r = getReal() * other.getReal() - getImg() * other.getImg();
        double i = getReal() * other.getImg() + getImg() * other.getReal();
        cout << r << " + " << i << "i" << endl;
    }

    void divide(const Complex& other)
    {
        double r = (getReal() * other.getReal() + getImg() * other.getImg()) / (other.getReal() * other.getReal() + other.getImg() * other.getImg());
        double i = (getImg() * other.getReal() - getReal() * other.getImg()) / (other.getReal() * other.getReal() + other.getImg() * other.getImg());
        cout << r << " + " << i << "i" << endl;
    }
};

int main()
{
    MyComplex c1(1, 2);
    MyComplex c2(3, 4);

    c1.add(c2);
    c1.subtract(c2);
    c1.multiply(c2);
    c1.divide(c2);

    return 0;
}
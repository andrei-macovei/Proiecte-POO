#include <iostream>
#include <math.h>

using namespace std;

class Vector_Complex;

class Numar_Complex
{
    double r,i;
public:
    Numar_Complex()
    {
        r=0;
        i=0;
    }
    Numar_Complex(double r1,double i1)
    {
        r=r1;
        i=i1;
    }
    Numar_Complex(const Numar_Complex &nr)
    {
        r=nr.r;
        i=nr.i;
    }
    ~Numar_Complex(){}
    double getr(){return r;}
    double geti(){return i;}
    void seti(double i1){i=i1;}
    void setr(double r1){r=r1;}
    double modul()
    {
        return sqrt(r*r+i*i);
    }

    friend ostream & operator<<(ostream& out,const Numar_Complex &nr);
    friend istream & operator>>(istream& in, Numar_Complex &nr);
    Numar_Complex operator+(const Numar_Complex&);
    Numar_Complex operator*(const Numar_Complex&);

    friend Vector_Complex;

};

ostream& operator<<(ostream &out, const Numar_Complex &nr)
{
    if(nr.r == 0 && nr.i ==0) out<<0;
        else if(nr.r == 0) out<<nr.i<<"*i";
        else if(nr.i == 0) out<<nr.r;
        else if(nr.i > 0) out<<nr.r<<"+"<<nr.i<<"*i";
        else out<<nr.r<<nr.i<<"*i";
        return out;
}

istream& operator>>(istream &in, Numar_Complex &nr)
{
    cout<<"Introduceti partea reala:\n";
    in>>nr.r;
    cout<<"Introduceti partea imaginara:\n";
    in>>nr.i;
    return in;
}

Numar_Complex Numar_Complex::operator+(const Numar_Complex &a)
{
    Numar_Complex b;
    b.r=r+a.r;
    b.i=i+a.i;
    return b;
}

Numar_Complex Numar_Complex::operator*(const Numar_Complex &a)
{
    Numar_Complex b;
    b.r=a.r*r - a.i*i;
    b.i=a.r*i + r*a.i;
    return b;
}
class Vector_Complex
{
    int n;
    Numar_Complex v[100];
public:
    Vector_Complex(){int n=0;}
    Vector_Complex(Numar_Complex a,int x)
    {
        n=x;
        for(int i=0;i<x;i++)
            v[i]=a;
    }
    Vector_Complex(const Vector_Complex &a)
    {
        n=a.n;
        for(int i=0;i<a.n;i++)
        {
            v[i]=a.v[i];
        }
    }
    ~Vector_Complex()
    {
        n=0;
    }
    int getN(){return n;}
    double* VectorModule();
    void SortareModule();
    friend ostream& operator<<(ostream& out,Vector_Complex &a);
    friend istream& operator>>(istream& in, Vector_Complex &a);

    Numar_Complex AdunareElemVector();
    Numar_Complex operator*(const Vector_Complex&);

};

ostream& operator<<(ostream& out,Vector_Complex &a)
{
    out<<"Elementele vectorului sunt: ";
    for(int i=0;i<a.n;i++)
    {
        out << a.v[i] <<" ";
    }
    out<<endl;
    return out;
}

istream& operator>>(istream& in, Vector_Complex &a)
{
    cout<<"Introduceti numarul de elemente al vectorului:\n";
    in>>a.n;
    cout<<"Introduceti "<<a.n<<" elemente in vector:\n";
    for(int i=0;i<a.n;i++)
        in>>a.v[i];
    return in;
}

Numar_Complex Vector_Complex::AdunareElemVector()
{
    Numar_Complex nr(0,0);
    for(int i=0;i<n;i++)
        nr=nr+v[i];
    return nr;
}

Numar_Complex Vector_Complex::operator*(const Vector_Complex &a)
{
    Numar_Complex nr(0,0);
    for(int i=0;i<n;i++)
    {
        nr=nr+v[i]*a.v[i];
    }
    return nr;
}

double* Vector_Complex::VectorModule()
{
    static double a[100];
        for(int i=0;i<n;i++)
        {
            a[i]=v[i].modul();
        }
        return a;
}

void Vector_Complex::SortareModule()
{
    Numar_Complex auxiliar;
    double *a=VectorModule();
    int i,j,x;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]<a[j])
            {
                double aux=a[i];
                auxiliar=v[i];
                a[i]=a[j];
                v[i]=v[j];
                a[j]=aux;
                v[j]=auxiliar;
            }
}


int main()
{
    Numar_Complex nr(1,23);
    Vector_Complex v;
    cin>>v;
    double *a;
    int n=v.getN();
    a=v.VectorModule();
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

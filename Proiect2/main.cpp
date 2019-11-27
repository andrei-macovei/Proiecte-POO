#include <iostream>

using namespace std;

class Monom{
    int grad;
    float coef;
public:

    Monom(float c = 1,int g = 0) : grad(g), coef(c){}

    Monom(const Monom &m){
        grad = m.grad;
        coef = m.coef;
    }

    ~Monom(){}
    friend ostream & operator<<(ostream& out,const Monom &m);
    friend istream & operator>>(istream& in, Monom &m);
    Monom& operator=(const Monom &m) {
        if (this != &m) {
            coef = m.coef;
            grad = m.grad;
        }
        return *this;
    }
    int getCoef(){
        return static_cast<int>(coef);
    }
};

ostream& operator<<(ostream &out,const Monom &m){
    if(m.coef == 0) {}
    else if(m.grad == 1 && m.coef == 1) out<<"X";
    else if(m.grad == 1)
        if(m.coef > 0) out<<"+"<<m.coef<<"*X";
        else out<<m.coef<<"*X";
    else if(m.grad == 0)
        if(m.coef > 0) out<<"+"<<m.coef;
        else out<<m.coef;
    else if(m.coef == 1) out<<"X^"<<m.grad;
    else if(m.coef > 0) out<<"+"<<m.coef<<"*X^"<<m.grad;
    else out<<m.coef<<"*X^"<<m.grad;
    return out;
}

istream& operator>>(istream &in, Monom &m){
    cout<<"Introduceti coeficientul:";
    in>>m.coef;
    cout<<"Introduceti gradul:";
    in>>m.grad;
    return in;
}

class Polinom{
protected:
    int nr_monoame;
    Monom* m;
public:
    Polinom(){
        nr_monoame = 0;
        m = new Monom[nr_monoame+1];
        Monom n(1,0);
        m[0] = n;
    }
    Polinom(int grad, float c){
        nr_monoame = grad;
        m = new Monom[nr_monoame+1];
        for(int i=nr_monoame;i>=0;i--){
            Monom n(c,i);
            m[i] = n;
        }
    }
    Polinom(const Polinom &p){
        nr_monoame = p.nr_monoame;
        for(int i=0;i<nr_monoame;i++)
        {
            m[i] = p.m[i];
        }
    }
    ~Polinom(){
        nr_monoame = -1;
        delete[] m;
    }

    Polinom& operator=(const Polinom &p) {
        if (this != &p) {
            nr_monoame = p.nr_monoame;
            m = p.m;
        }
        return *this;

    }

    friend ostream & operator<<(ostream& out,const Polinom &p);
    friend istream & operator>>(istream& in, Polinom &p);

};

    istream& operator>>(istream& in, Polinom &p){
        cout<<"Introduceti gradul polinomului:";
        in>>p.nr_monoame;
        auto *coef = new float[p.nr_monoame+1];
        p.m =new Monom[p.nr_monoame+1];
        cout<<"Introduceti coeficientii monoamelor:\n";
        for(int i=p.nr_monoame;i>=0;i--){
            cout<<"Introduceti coeficientul pentru monomul de gradul "<<i<<endl;
            in>>coef[i];
            Monom n(coef[i],i);
            p.m[i] = n;
        }
        return in;
    }

    ostream& operator<<(ostream& out, const Polinom &p)
    {
        for(int i=p.nr_monoame;i>=0;i--)
        {
            out<<p.m[i];
        }
        return out;
    }


    class Polinom_ireductibil: public Polinom{
    public:
        Polinom_ireductibil() : Polinom() {}
        Polinom_ireductibil(int grad, float coef) : Polinom(grad,coef) {}
        Polinom_ireductibil(const Polinom_ireductibil &p) : Polinom(p) {}
        ~Polinom_ireductibil() {}
        Polinom_ireductibil&operator=(const Polinom_ireductibil &p){
            if (this != &p) this->Polinom::operator=(p);
            return *this;
        }

        static bool prim(int x){
            for(int i=2;i<x/2;i++) {
                if (x % i == 0) return false;
            }
            return true;
        }

        bool Ireductibil(){
            int cond = 0;
            for(int p=2;p<=101;p++){
                if(prim(p)){
                    if(m[nr_monoame+1].getCoef() % p) cond++;
                    if(m[0].getCoef() % p*p) cond++;
                    for(int i=1;i<=nr_monoame;i++) {
                        if (m[i].getCoef() % p) break;
                        else if (i == nr_monoame) cond++;
                    }
                    if(cond == 3) return true;
                    else cond = 0;
                }
            }
            return false;
        }
    };


int main() {
    int n,a;
    cout<<"Introduceti numarul polinoamelor de salvat:  \n";
    cin>>n;
    Polinom *v = new Polinom[n];
    for(int i=0;i<n;i++){
        cout<<"Polinomul "<<i+1<<" este ireductibil? \n0 - nu\n1 - da\n";
        cin>>a;
        cout<<"Introduceti datele polinomului:\n";
        if(a){
            Polinom_ireductibil *pi = new Polinom_ireductibil;
            cin>>*pi;
            v[i] = *pi;
        }
        else cin>>v[i];
    }

    for(int i=0;i<n;i++)
        cout<<v[i]<<endl;

    return 0;
}
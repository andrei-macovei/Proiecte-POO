#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Automobil{
protected:
    string marca;
    string model;
    double cilindree;
    double lungime;
    double pret;
public:
    Automobil() : marca(" "),model(" "),cilindree(0),lungime(0),pret(0) {}
    Automobil(string m, string mm, double c=0, double l=0, double p=0) : marca(m),model(mm),cilindree(c),lungime(l),pret(p) {}

    Automobil(const Automobil &a){
        marca = a.marca;
        model = a.model;
        cilindree = a.cilindree;
        lungime = a.lungime;
        pret = a.pret;
    }

    Automobil& operator=(const Automobil &a){
        if(this != &a){
            marca = a.marca;
            model = a.model;
            cilindree = a.cilindree;
            lungime = a.lungime;
            pret = a.pret;
        }
        return *this;
    }
    ~Automobil() {}
    friend istream& operator>>(istream &in, Automobil &a);
    virtual void Afisare(){
        cout<<"Numele automobilului este "<<marca<<" "<<model<<".\nAcesta are o capacitate cilindrica de "<<cilindree<<" litri, lungimea de "<<lungime<<" metri.\n";
        cout<<"Pretul automobilului este evaluat la "<<pret<<" euro."<<endl;
    }
};

class MINI : public virtual Automobil{
    int volum_interior;
public:
    MINI() : Automobil(), volum_interior(0) {}
    MINI(string m,string mm, double c=0, double l=0, double p=0,int v=0) : Automobil(m,mm,c,l,p), volum_interior(v) {}
    MINI(const MINI &m) : Automobil(m), volum_interior(m.volum_interior) {}
    MINI& operator=(const MINI &m){
        if(this != &m) {
            Automobil::operator=(m);
            volum_interior = m.volum_interior;
        }
        return *this;
    }
    friend istream& operator>>(istream &in, MINI &m);
    void Afisare(){
        Automobil::Afisare();
        cout<<"Volumul interior al automobilului este de "<<volum_interior<<" litri\n";
    }
};

class MICA : public Automobil{
    int volum_interior;
    double consum;
public:
    MICA() : Automobil(), volum_interior(0), consum(0) {}
    MICA(string m, string mm, double c=0, double l=0, double p=0, int v=0, double co=0) : Automobil(m,mm,c,l,p), volum_interior(v), consum(co) {}
    MICA(const MICA &m) : Automobil(m), volum_interior(m.volum_interior), consum(m.consum) {}
    friend istream& operator>>(istream &in, MICA &m);
    void Afisare(){
        Automobil::Afisare();
        cout<<"Volumul interior al automobilului este de "<<volum_interior<<" litri, iar consumul acestuia este de "<<consum<<" l/100 km.\n";
    }
};

class COMPACTA : public Automobil{
    string forma;
public:
    COMPACTA() : Automobil(), forma(" ") {}
    COMPACTA(string m, string mm, double c=0, double l=0, double p=0, string f = " ") : Automobil(m,mm,c,l,p), forma(f) {}
    COMPACTA(const COMPACTA &c) : Automobil(c), forma(c.forma) {}
    friend istream& operator>>(istream &in, COMPACTA &m);
    void Afisare(){
        Automobil::Afisare();
        cout<<"Forma compactei este de tip: "<<forma;
        cout<<endl;
    }
};

class MONOVOLUM : public Automobil{
    int nr_locuri;
    int vechime;
public:
    MONOVOLUM() : Automobil(), nr_locuri(0), vechime(0) {}
    MONOVOLUM(string m, string mm, double c=0, double l=0, double p=0, int n = 0,int v = 0) : Automobil(m,mm,c,l,p), nr_locuri(n), vechime(v) {}
    MONOVOLUM(const MONOVOLUM &m) : Automobil(m), nr_locuri(m.nr_locuri), vechime(m.vechime) {}
    void schimb_pret(double p){ this->pret *= p; }
    int getVechime() {return vechime;}
    void Afisare(){
        Automobil::Afisare();
        cout<<"Monovolumul are "<<nr_locuri<<" locuri si o vechime de "<<vechime<<" ani.\n";
    }
    friend istream& operator>>(istream &in, MONOVOLUM &m);
};

istream& operator>>(istream &in, Automobil &a){
    cout<<"Introduceti marca automobilului:";
    in>>a.marca;
    cout<<"Introduceti modelul automobilului:";
    in>>a.model;
    cout<<"Introduceti capacitatea cilindrica a automobilului:";
    in>>a.cilindree;
    cout<<"Introduceti lungimea automobilului:";
    in>>a.lungime;
    cout<<"Introduceti pretul automobilului:";
    in>>a.pret;
    return in;
}

istream& operator>>(istream &in, MINI &m){
    in >> static_cast<Automobil&>(m);
    cout<<"Introduceti volumul interior al automobilului:";
    in>>m.volum_interior;
    return in;
}

istream& operator>>(istream &in, MICA &m){
    in >> static_cast<Automobil&>(m);
    cout<<"Introduceti volumul interior al automobilului:";
    in>>m.volum_interior;
    cout<<"Precizati consumul automobilului:";
    in>>m.consum;
    return in;
}

istream& operator>>(istream &in, COMPACTA &m){
    in >> static_cast<Automobil&>(m);
    cout<<"Introduceti forma compactei (sedan/combi/hatch):";
    in>>m.forma;
    return in;
}

istream& operator>>(istream &in, MONOVOLUM &m){
    in >> static_cast<Automobil&>(m);
    cout<<"Introduceti numarul de locuri al monovolumului:";
    in>>m.nr_locuri;
    cout<<"Introduceti vechime monovolumului:";
    in>>m.vechime;
    return in;
}

template <class Tip>
class Vanzare{
    int nr_masini_stoc;
    int nr_masini_vandute;
    set<Tip> stoc;
    set<Tip> vandute;
public:
    Vanzare() : nr_masini_stoc(0), nr_masini_vandute(0) {}
    Vanzare& operator-=(const Tip &a){
        stoc.erase(a);
        nr_masini_stoc--;
        vandute.insert(a);
        nr_masini_vandute++;
        return *this;
    }
    void adaugare(Tip a){
        stoc.insert(a);
        nr_masini_stoc++;
    }
    void afisare_stoc(){
        for(auto i = stoc.begin(); i != stoc.end(); ++i) i.Afisare();
    }
    void afisare_vandute(){
        for(auto i = vandute.begin(); i != vandute.end(); ++i) i.Afisare();
    }
};


template<>
class Vanzare<MONOVOLUM>
{
    int nr_masini_stoc;
    int nr_masini_vandute;
    static string anotimp;
    double discount;
    typedef pair<MONOVOLUM,bool> pereche;
    set<pereche> stoc;
    set<pereche> vandute;
public:
    Vanzare() : nr_masini_vandute(0), nr_masini_stoc(0), discount(0.1) {}
    void vanzare(MONOVOLUM &a,bool nou){
        pereche pair1(a,nou);
        if(!nou){
            a.schimb_pret(a.getVechime() * 0.05);
        }
        else if(anotimp == "vara"){ a.schimb_pret(discount);}
        //stoc.erase(pair1); =>eroare de compilare pe care nu o pot explica
        nr_masini_stoc--;
        //vandute.insert(pair1);
        nr_masini_vandute++;
    }
    void adaugare(MONOVOLUM &a,bool nou){
        pair<MONOVOLUM,bool> pair1(a,nou);
        //stoc.insert(pair1);
        nr_masini_stoc++;

    }
    static void setAnotimp(string a = "vara"){ anotimp = a;}

};

string Vanzare<MONOVOLUM>::anotimp;


int main() {
    Vanzare<MONOVOLUM>::setAnotimp();
    vector<Automobil*>v;
    int n,x,it = 0;
    cout<<"Introduceti numarul de automobile de stocat:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Introduceti tipul automobilului "<<i+1<<" \n1-Mini\n2-Mica\n3-Compacta\n4-Monovolum\n";
        cin>>x;
        switch(x){
            case 1 : v.push_back(new MINI());
            break;
            case 2 : v.push_back(new MICA());
            break;
            case 3 : v.push_back(new COMPACTA());
            break;
            case 4 : v.push_back(new MONOVOLUM());
            break;
            default: cout<<"Introduceti o valoare corecta!\n"; i--;
            break;
        }
    }
    for(auto i : v){
        cout<<"Introduceti datele pentru automobilul "<<++it<<endl;
        if(dynamic_cast<MINI*>(i))
            cin>>*dynamic_cast<MINI*>(i);
        if(dynamic_cast<MICA*>(i))
            cin>>*dynamic_cast<MICA*>(i);
        if(dynamic_cast<COMPACTA*>(i))
            cin>>*dynamic_cast<COMPACTA*>(i);
        if(dynamic_cast<MONOVOLUM*>(i))
            cin>>*dynamic_cast<MONOVOLUM*>(i);
    }
    it = 0;

    for(auto &i : v){
        cout<<"Datele pentru automobilul "<<++it<<" sunt:\n";
        i->Afisare();
        cout<<endl;
    }
    
    return 0;
}

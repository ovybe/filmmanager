//
// Created by lemaw on 5/24/2021.
//

#ifndef SPFILM_FILM_H
#define SPFILM_FILM_H
using namespace std;
class Film{
protected:
    char *nume,*gen,*actor;
    int an,pretbilet;
    int id;
    static int filmidnum;
public:
    class Film *next;
    Film(char *nume,char *gen,int an,char *actor,int pretbilet){
        this->init(nume,gen,an,actor,pretbilet);
    }
    Film(const Film &p){
        this->init(p.nume,p.gen,p.an,p.actor,p.pretbilet);
    }
    ~Film(){
        this->stergere();
    }
    Film& operator=(const Film&p){
        if(this==&p) return *this;
        this->stergere();
        this->init(p.nume,p.gen,p.an,p.actor,p.pretbilet);
        return *this;
    }
    virtual ostream& afisare(ostream&st)const{
        st<<"ID:"<<this->id<<endl<<"Nume: "<<this->nume<<endl<<"Gen: "<<this->gen<<endl<<"An: "<<this->an<<endl<<"Actor Principal: "<<this->actor<<endl<<"Pret bilet:"<<this->pretbilet<<" lei"<<endl<<"----------------------"<<endl;
        return st;
    }
    friend ostream& operator<<(ostream&st, const Film&p){
        return p.afisare(st);
    }
    friend ostream& operator<<(ostream&st, const Film*p){
        return p->afisare(st);
    }
    friend class list;
protected:
    void init(char *numein,char *genin,int anin,char *actorin,int pretbiletin){
        filmidnum++;
        //cout<<"Init working";
        this->nume=new char[strlen(numein)+1];
        this->gen=new char[strlen(genin)+1];
        this->actor=new char[strlen(actorin)+1];
        strcpy(this->nume,numein);
        strcpy(this->gen,genin);
        this->an=anin;
        strcpy(this->actor,actorin);
        this->pretbilet=pretbiletin;
        this->id=this->filmidnum;
    }
    void stergere(){
        delete this->nume;
        delete this->gen;
        delete this->actor;
    }
    friend void afisarefilmenume(char *);
    friend void afisarefilmegen(char *);
    friend void afisarefilmeactor(char *);
    friend void afisarefilmid(int &);
};
int Film::filmidnum=0;
#endif //SPFILM_FILM_H

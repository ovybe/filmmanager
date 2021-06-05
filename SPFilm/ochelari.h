//
// Created by lemaw on 5/30/2021.
//

#ifndef SPFILM_OCHELARI_H
#define SPFILM_OCHELARI_H
class Ochelari{
protected:
    char *nume,*detalii;
    int pretochelari;
    void init(char *numein,char *detalii,int pretochelariin){
        this->nume=new char[strlen(numein)+1];
        strcpy(this->nume,numein);
        this->detalii=new char[strlen(detalii)+1];
        strcpy(this->detalii,detalii);
        this->pretochelari=pretochelariin;
    }
public:
    Ochelari(){
        this->nume = new char[50];
        this->detalii = new char[255];
        this->pretochelari=0;
    }
    Ochelari(char *numein,char *detalii,int pretochelariin){
        this->init(numein,detalii,pretochelariin);
    }
    virtual ostream& afisare(ostream&st)const{
        st<<"Nume: "<<this->nume<<endl<<"Pret: "<<this->pretochelari<<" lei"<<endl;
        return st;
    }
    friend ostream& operator<<(ostream&st, const Ochelari&p){
        return p.afisare(st);
    }
    friend ostream& operator<<(ostream&st, const Ochelari*p){
        return p->afisare(st);
    }
    Ochelari* operator[](int idx){
        Ochelari *ochelari = new Ochelari[idx + 1];
        return ochelari;
    }
    void aratadetalii(){
        cout<<"Detalii: "<<this->detalii<<endl;
    }
    friend void citirelista();
    friend class list3d;
};
Ochelari o[3];
Ochelari citireochelari(ifstream &och){
    char x[255];
    char *nume,*detalii,pretch[1];
    int pret;
    Ochelari o;
    och.getline(x,254);
    char *token=strtok(x,",");
    nume=new char[strlen(token)+1];
    strcpy(nume,token);
    token=strtok(nullptr,",");
    detalii=new char[strlen(token)+1];
    strcpy(detalii,token);
    token=strtok(nullptr,",");
    pret=atoi(token);
    o=Ochelari(nume,detalii,pret);
    return o;
}
#endif //SPFILM_OCHELARI_H

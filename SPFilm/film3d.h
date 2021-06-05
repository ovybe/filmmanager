//
// Created by lemaw on 5/30/2021.
//

#ifndef SPFILM_FILM3D_H
#define SPFILM_FILM3D_H
#include "ochelari.h"
#include "film.h"
class Film3D: public Film{
    class Ochelari ochelari;
public:
    class Film3D *next;
    Film3D(char *nume,char *gen,int an,char *actor,int pretbilet, Ochelari ochelariin):Film(nume,gen,an,actor,pretbilet){
        this->ochelari=ochelariin;
        //this->id=this->filmidnum;
        //cout<<this->ochelari;
    }
    virtual ostream& afisare(ostream&os)const{
        os<<"ID:"<<this->id<<endl<<"Nume: "<<this->nume<<endl<<"Gen: "<<this->gen<<endl<<"An: "<<this->an<<endl<<"Actor Principal: "<<this->actor<<endl<<"Pret bilet:"<<this->pretbilet<<" lei"<<endl<<"**Informatie ochelari**"<<endl<<this->ochelari<<"----------------------"<<endl;
        return os;
    }
    friend class list3d;
};
#endif //SPFILM_FILM3D_H

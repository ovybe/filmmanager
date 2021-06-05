#include <iostream>
#include <cstring>
#include "film.h"
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "ochelari.h"
#include "liste.h"

using namespace std;
class list lista;
class list3d lista3d;
void adaugare(){ //adaugarea filmelor in lista
    cout<<"Sunteti sigur ca vreti sa adaugati un film?(y/n)"<<endl;
    if(question()) {
        char nume[255], gen[255], actor[255];
        int an;
        int pretbilet;
        cout << "Nume:";
        cin.getline(nume, 254);
        cout << "Gen:";
        cin.getline(gen, 255);
        cout << "An:";
        cin >> an;
        cin.ignore();
        cout << "Actor:";
        cin.getline(actor, 255);
        cout << "Pret bilet:";
        cin >> pretbilet;
        cout << "Este film 3d(y/n)";
        if (question()) {
            int t;
            do {
                system("cls");
                cout << "Alege tipul de ochelari sau detalii:";
                cout
                        << "\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n4.Detalii\n5.Adauga-l ca film 2D\n6.M-am razgandit!\n"
                        << endl;
                t = _getch();
                switch (t) {
                    case 49: //1
                        cout<<"Sunteti sigur?(y/n):";
                        if(question())
                        lista3d.append(nume, gen, an, actor, pretbilet, o[0]); // Anaglyph
                        t = -1;
                        break;
                    case 50: //2
                        cout<<"Sunteti sigur?(y/n):";
                        if(question())
                        lista3d.append(nume, gen, an, actor, pretbilet, o[1]); // Polarized
                        t = -1;
                        break;
                    case 51: //3
                        cout<<"Sunteti sigur?(y/n):";
                        if(question())
                        lista3d.append(nume, gen, an, actor, pretbilet, o[2]); // Active Shutter
                        t = -1;
                        break;
                    case 52: //4
                        int det;
                        do {
                            system("cls");
                            cout << "Alege ochelarii despre care vrei sa aflii mai mult.";
                            cout << "\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n0.Inapoi" << endl;
                            det = _getch();
                            switch (det) {
                                case 49:
                                    o[0].aratadetalii();
                                    check();
                                    break;
                                case 50:
                                    o[1].aratadetalii();
                                    check();
                                    break;
                                case 51:
                                    o[2].aratadetalii();
                                    check();
                                    break;
                                case 48:
                                    break;
                                default:
                                    cout << "Alege 1, 2, 3 sau 0.";
                            }
                        } while (det != 48);
                        break;
                    case 53: //5
                        cout<<"Sunteti sigur?(y/n):";
                        if(question())
                        lista.append(nume, gen, an, actor, pretbilet);
                        t = -1;
                        break;
                    case 54: //
                        t=-1;
                        break;
                    case 48:
                        break;
                    default:
                        cout << "Alege 1,2,3 sau 0." << endl;
                }
                // BUG HAPPENS HERE
            } while (t != -1);
            cin.ignore();
        }
            //cout<<"Appending.\n";
        else{
            cout<<"Sunteti sigur?(y/n):";
            if(question())
            lista.append(nume, gen, an, actor, pretbilet);
            cin.ignore();
            }
        //cout<<"Append done\n";
    }
}
//CITIRE OCHELARI
//CITIRE LISTA 3d si 2d
void citirelista(){
    ifstream listaf("lista.txt");
    if(listaf.is_open()){
    char x[255];
    char *nume,*gen,*actor;
    int an,pretbilet,este3d;
    Ochelari oin;
    while(listaf.getline(x,254)){
        char *token=strtok(x,",");
        nume=new char[strlen(token)+1];
        strcpy(nume,token);
        token=strtok(nullptr,",");
        gen=new char[strlen(token)+1];
        strcpy(gen,token);
        token=strtok(nullptr,",");
        an=atoi(token);
        token=strtok(nullptr,",");
        actor=new char[strlen(token)+1];
        strcpy(actor,token);
        token=strtok(nullptr,",");
        pretbilet=atoi(token);
        token=strtok(nullptr,",");
        //citirea fiecarui lucru
        if(atoi(token)==1){ // verificam daca e film 3d sau nu
            token=strtok(nullptr,",");
            for(int i=0;i<3;i++){
                if(strcmp(token,o[i].nume)==0){
                    oin=o[i];
                    break;}
            }
            lista3d.append(nume,gen,an,actor,pretbilet,oin);
        }
        else {
            lista .append(nume,gen,an,actor,pretbilet);
        }
    }
    }
    else {
        cout<<"Error! Could not open file! No data has been read!";
        check();
    }
}
// CREARE SI ADAUGARE VARIANTA 2D/3D FILM
void afisarefilmenume(char *numeluat){
    //cout<<"Entered afisare\n";
    Film *p1;
    Film3D *p2;
    p1=lista.head;
    p2=lista3d.head;
    cout<<"--------------Filme 2D------------------\n";
    while(p1){
        if(strcmp(p1->nume,numeluat)==0)
            cout<<p1->id<<"."<<p1->nume<<endl;
        p1=p1->next;
    }
    cout<<"--------------Filme 3D------------------\n";
    while(p2){
        if(strcmp(p2->nume,numeluat)==0)
            cout<<p2->id<<"."<<p2->nume<<endl;
        p2=p2->next;
    }
}
void afisarefilmegen(char *gen){
    //cout<<"Entered afisare\n";
    Film *p1;
    Film3D *p2;
    p1=lista.head;
    p2=lista3d.head;
    cout<<"--------------Filme 2D------------------\n";
    while(p1){
        if(strcmp(p1->gen,gen)==0)
            cout<<p1->id<<"."<<p1->nume<<endl;
        p1=p1->next;
    }
    cout<<"--------------Filme 3D------------------\n";
    while(p2){
        if(strcmp(p2->gen,gen)==0)
            cout<<p2->id<<"."<<p2->nume<<endl;
        p2=p2->next;
    }
}
void afisarefilmeactor(char *actor){
    //cout<<"Entered afisare\n";
    Film *p1;
    Film3D *p2;
    p1=lista.head;
    p2=lista3d.head;
    cout<<"--------------Filme 2D------------------\n";
    while(p1){
        if(strcmp(p1->actor,actor)==0)
            cout<<p1->id<<"."<<p1->nume<<endl;
        p1=p1->next;
    }
    cout<<"--------------Filme 3D------------------\n";
    while(p2){
        if(strcmp(p2->actor,actor)==0)
            cout<<p2->id<<"."<<p2->nume<<endl;
        p2=p2->next;
    }
}
void afisarefilmid(int &iddat){
    //cout<<"Entered afisare\n";
    Film *p1;
    Film3D *p2;
    p1=lista.head;
    p2=lista3d.head;
    while(p1){
        if(p1->id==iddat){
            cout<<p1;
            break;
            }
        p1=p1->next;
    }
    while(p2){
        if(p2->id==iddat){
            cout<<p2;
            break;
            }
        p2=p2->next;
    }
}
int main() {
    int n;
    //cout << endl << "Test start";
    //CITIRE OCHELARI DIN FISIER
    ifstream och("ochelari.txt");
    for(int i=0;i<3;i++)
    {
        o[i]=citireochelari(och);
    }
    och.close();
    //CITIRE OCHELARI DIN FISIER
    //CITIRE LISTA 3d si 2d
    citirelista();
    //CITIRE LISTA 3d si 2d
    do{
        cout<<"*****************************************\n1.Adaugare film\n2.Stergere film dupa ID\n3.Modificare film dupa ID\n4.Afisare Filme Simplu\n5.Afisare Filme Detaliat\n6.Filtrare filme dupa nume\n7.Filtrare filme dupa gen\n8.Filtrare filme dupa actor\n9.Cautare film dupa ID\n0.Iesire\n";
        cout << "*****************************************\nApasati una dintre tastele respective\n";
        n=_getch();
        system("cls");
        switch (n) {
            case 49:
                system("cls");
                adaugare();
                system("cls");
                cout<<"Vrei sa vezi lista?(y/n)\n";
                if(question()){
                    lista.afisarenume();
                    lista3d.afisarenume();
                }
                check();
                system("cls");
                break;// adaugare // STOPPED HERE
            case 50:
                int iddesters;
                cout<<"Introdu id-ul:";
                cin>>iddesters;
                system("cls");
                if(lista.searchfilm(iddesters))
                lista.deletefilm(iddesters);
                else{
                    cout<<"ID-ul nu a fost gasit in lista filmelor 2D!\n";
                    lista3d.deletefilm(iddesters);
                }
                cout<<"Vrei sa vezi lista?(y/n)\n";
                if(question()){
                    lista.afisarenume();
                    lista3d.afisarenume();
                }
                check();
                system("cls");
                break; // STERGERE
            case 51:
                int iddeschimbat;
                cout<<"Introdu id-ul:";
                cin>>iddeschimbat;
                system("cls");
                if(lista.searchfilm(iddeschimbat))
                lista.modifyfilm(iddeschimbat);
                else{
                cout<<"ID-ul nu a fost gasit in lista filmelor 2D!\n";
                lista3d.modifyfilm(iddeschimbat);
                };
                cout<<"Vrei sa vezi lista?(y/n)\n";
                if(question()){
                    lista.afisarenume();
                    lista3d.afisarenume();
                }
                check();
                system("cls");
                break;
            case 52:
                cout<<"--------------Filme 2D------------------\n";
                lista.afisarenume();
                cout<<"--------------Filme 3D------------------\n";
                lista3d.afisarenume();
                check();
                system("cls");
                break;
            case 53:
                cout<<"--------------Filme 2D------------------\n";
                lista.afisare();
                cout<<"--------------Filme 3D------------------\n";
                lista3d.afisare();
                check();
                system("cls");
                break;
            case 54:
                char numefilm[255];
                cout<<"Introduceti numele filmului pe care il cautati:";
                cin.getline(numefilm,254);
                afisarefilmenume(numefilm);
                cout<<"Am afisat tot ce am gasit cu numele:"<<numefilm<<endl;
                check();
                system("cls");
                break;
            case 55:
                char numegen[255];
                cout<<"Introduceti genul filmelor care le cautati:";
                cin.getline(numegen,254);
                afisarefilmegen(numegen);
                cout<<"Am afisat tot ce am gasit cu genul:"<<numegen<<endl;
                check();
                system("cls");
                break;
            case 56:
                char numeactor[255];
                cout<<"Introduceti actorul fimelor pe care le cautati:";
                cin.getline(numeactor,254);
                afisarefilmeactor(numeactor);
                cout<<"Am afisat tot ce am gasit cu actorul:"<<numeactor<<endl;
                check();
                system("cls");
                break;
            case 57:
                int idfilm;
                cout<<"Introduceti id-ul filmului pe care il cautati:";
                cin>>idfilm;
                afisarefilmid(idfilm);
                check();
                cin.ignore();
                system("cls");
                break;
            case 48:
                lista.stocare();
                lista3d.stocare();
                exit(0);
            default:
                system("cls");
                printf("Apasati una dintre tastele corecte\n");
        }
    }while(n!=48);
}

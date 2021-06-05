//
// Created by lemaw on 5/30/2021.
//

#ifndef SPFILM_LISTE_H
#define SPFILM_LISTE_H
#include "film.h"
#include "film3d.h"
bool question() { // verificare basic
    int ch=0;
    do {
        ch = _getch(); // ia primul caracter din input
    } while(ch!=121 && ch!=110);
    return ch==121 ? true : false;
}
void  check() //Simuleaza o pauza
{
    char chk; int j;
    cout<<"\n\nPress any key to continue...";
    chk=getch();
    j=chk;
    for(int i=1;i<=256;i++)
        if(i==j) break;
    system("cls");
}
class list // lista filme
{
    Film *head;
    Film *tail;
public:
    list(){
        head=nullptr;
        tail=nullptr;
    }
    void append(char *nume, char *gen, int an, char *actor,int pretbilet) //Adaugare element in lista
    {
        //cout<<"Append entered.\n";
        Film *p=new Film(nume,gen,an,actor,pretbilet);
        p->next=nullptr;
        if(this->head == nullptr)
        {
            this->head = p;
            this->tail = p;
        }
        else
        {
            this->tail->next = p;
            this->tail = p;
        }
    }
    bool searchfilm(int iddat) {
        Film *temp = this->head;
        Film *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            return true;
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                return false;
            else {
                return true;
            }
        }
    }
    void deletefilm(int iddat) {
        Film *temp = this->head;
        Film *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            cout<<"Filmul a fost gasit in lista filmelor 2D! Detalii:\n";
            cout<<temp;
            cout<<"Sunteti sigur(a) ca vreti sa stergeti acest film?(y/n)";
            if(question()){
                this->head = temp->next; // Changed head
                delete temp;            // free old head
                system("cls");
                cout<<"Filmul 2D a fost sters cu succes!"<<endl;
                cin.ignore();
            }
            else{
                cin.ignore();
                cout<<"Am incheiat operatia"<<endl;
            }
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                cout << "ID-ul nu a fost gasit in lista filmelor 2D!" << endl;
            else{
                cout<<"Filmul a fost gasit in lista filmelor 2D! Detalii:\n";
                cout<<temp;
                cout<<"Sunteti sigur(a) ca vreti sa stergeti acest film?(y/n)";
                char conf;
                if(question()){
                    prev->next = temp->next;
                    delete temp;
                    system("cls");
                    cout<<"Filmul 2D a fost sters cu succes!"<<endl;
                    cin.ignore();
                }
                else {
                    cin.ignore();
                    cout<<"Operatia a fost oprita."<<endl;
                }
            }
        }
    }
    void modifyfilm(int iddat) {
        Film *temp = this->head;
        Film *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            cout<<"Filmul a fost gasit in lista filmelor 2D! Detalii:\n";
            cout<<temp;
            cout<<"Sunteti sigur(a) ca vreti sa modificati acest film?(y/n)";
            if(question()){
                cin.ignore();
                system("cls");
                int n=6;
                while(n!=48){
                    system("cls");
                    cout<<"Detalii curente:\n";
                    cout<<temp<<endl;
                    cout<<"Ce doriti sa modificati?\n1.Numele\n2.Genul\n3.Anul\n4.Actorul\n5.Pretul\n0.M-am razgandit.\n";
                    n=_getch();
                    switch(n){
                        case 49:
                            char nume[255];
                            cout<<"Introduceti un nume nou:";
                            cin.getline(nume,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->nume;
                                temp->nume=new char[strlen(nume)+1];
                                strcpy(temp->nume,nume);
                            }
                            break;
                        case 50:
                            char gen[255];
                            cout<<"Introduceti un gen nou:";
                            cin.getline(gen,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->gen;
                                temp->gen=new char[strlen(gen)+1];
                                strcpy(temp->gen,gen);
                            }
                            break;
                        case 51:
                            int an;
                            cout<<"Introduceti un an nou:";
                            cin>>an;
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                temp->an=an;
                            }
                            break;
                        case 52:
                            char actor[255];
                            cout<<"Introduceti un actor nou:";
                            cin.getline(actor,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->actor;
                                temp->actor=new char[strlen(actor)+1];
                                strcpy(temp->actor,actor);
                            }
                            break;
                        case 53:
                            int pret;
                            cout<<"Introduceti un pret nou:";
                            cin>>pret;
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                temp->pretbilet=pret;
                            }
                            break;
                        case 48:
                            cout<<"Iesim din modificare...";
                            break;
                    }
                }
                cout<<"Ma intorc...";
            }
            else{
                cout<<"Am incheiat operatia"<<endl;
                cin.ignore();
            }
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                cout << "ID-ul nu a fost gasit in lista filmelor 2D!" << endl;
            else{
                cout<<"Filmul a fost gasit in lista filmelor 2D! Detalii:\n";
                cout<<temp;
                cout<<"Sunteti sigur(a) ca vreti sa modificati acest film?(y/n)";
                if(question()){
                    system("cls");
                    int n=6;
                    while(n!=48){
                        system("cls");
                        cout<<"Detalii curente:\n";
                        cout<<temp<<endl;
                        cout<<"Ce doriti sa modificati?\n1.Numele\n2.Genul\n3.Anul\n4.Actorul\n5.Pretul\n0.M-am razgandit.\n";
                        n=_getch();
                        switch(n){
                            case 49:
                                char nume[255];
                                cout<<"Introduceti un nume nou:";
                                cin.getline(nume,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->nume;
                                    temp->nume=new char[strlen(nume)+1];
                                    strcpy(temp->nume,nume);
                                }
                                break;
                            case 50:
                                char gen[255];
                                cout<<"Introduceti un gen nou:";
                                cin.getline(gen,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->gen;
                                    temp->gen=new char[strlen(gen)+1];
                                    strcpy(temp->gen,gen);
                                }
                                break;
                            case 51:
                                int an;
                                cout<<"Introduceti un an nou:";
                                cin>>an;
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    temp->an=an;
                                }
                                break;
                            case 52:
                                char actor[255];
                                cout<<"Introduceti un actor nou:";
                                cin.getline(actor,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->actor;
                                    temp->actor=new char[strlen(actor)+1];
                                    strcpy(temp->actor,actor);
                                }
                                break;
                            case 53:
                                int pret;
                                cout<<"Introduceti un pret nou:";
                                cin>>pret;
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    temp->pretbilet=pret;
                                }
                                break;
                            case 48:
                                cout<<"Iesim din modificare...";
                                break;
                        }
                    }
                    cout<<"Ma intorc...";
                }
                else{
                    cout<<"Am incheiat operatia"<<endl;
                }
            }
        }
    }
    void afisare(){
        //cout<<"Entered afisare\n";
        Film *p1;
        p1=this->head;
        while(p1){
            cout<<p1;
            p1=p1->next;
        }
    }
    void afisarenume(){
        //cout<<"Entered afisare\n";
        Film *p1;
        p1=this->head;
        while(p1){
            cout<<"("<<p1->id<<") "<<p1->nume<<endl;
            p1=p1->next;
        }
    }
    void stocare(){
        Film *p1;
        cout<<"stocare Called."<<endl;
        ofstream stoc("lista.txt");
        p1=this->head;
        while(p1){
            stoc<<p1->nume<<","<<p1->gen<<","<<p1->an<<","<<p1->actor<<","<<p1->pretbilet<<",0,"<<endl;
            p1=p1->next;
        }
    }
    friend void afisarefilmenume(char *);
    friend void afisarefilmegen(char *);
    friend void afisarefilmeactor(char *);
    friend void afisarefilmid(int &);
}list;

class list3d // lista filme 3d
{
    Film3D *head;
    Film3D *tail;
public:
    list3d() {
        head = nullptr;
        tail = nullptr;
    }

    void
    append(char *nume, char *gen, int an, char *actor, int pretbilet, Ochelari ochelari) //Adaugare element in lista
    {
        //cout<<"Append entered.\n";
        Film3D *p = new Film3D(nume, gen, an, actor, pretbilet, ochelari);
        p->next = nullptr;
        if (this->head == nullptr) {
            this->head = p;
            this->tail = p;
        } else {
            this->tail->next = p;
            this->tail = p;
        }
    }
    bool searchfilm(int iddat) {
        Film3D *temp = this->head;
        Film3D *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            return true;
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                return false;
            else {
                return true;
            }
        }
    }
    void deletefilm(int iddat) {
        Film3D *temp = this->head;
        Film3D *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            cout << "Filmul a fost gasit in lista filmelor 3D! Detalii:\n";
            cout << temp;
            cout << "Sunteti sigur(a) ca vreti sa stergeti acest film?(y/n)";
            if (question()) {
                this->head = temp->next; // Changed head
                delete temp;            // free old head
                system("cls");
                cout << "\nFilmul 3D a fost sters cu succes!" << endl;
                cin.ignore();
            } else {
                cin.ignore();
                cout << "\nAm incheiat operatia" << endl;
            }
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                cout << "ID-ul nu a fost gasit in lista filmelor 3D!" << endl;
            else {
                cout << "Filmul a fost gasit in lista filmelor 3D! Detalii:\n";
                cout << temp;
                cout << "Sunteti sigur(a) ca vreti sa stergeti acest film?(y/n)";
                if (question()) {
                    prev->next = temp->next;
                    delete temp;
                    system("cls");
                    cout << "\nFilmul 3D a fost sters cu succes!" << endl;
                    cin.ignore();
                } else {
                    cin.ignore();
                    cout << "\nOperatia a fost oprita." << endl;
                }
            }
        }
    }
    void modifyfilm(int iddat) {
        Film3D *temp = this->head;
        Film3D *prev = NULL;
        if (temp != NULL && temp->id==iddat) {
            cout<<"Filmul a fost gasit! Detalii:\n";
            cout<<temp;
            cout<<"Sunteti sigur(a) ca vreti sa modificati acest film?(y/n)";
            if(question()){
                cin.ignore();
                system("cls");
                int n=6;
                while(n!=48){
                    system("cls");
                    cout<<"Detalii curente:\n";
                    cout<<temp<<endl;
                    cout<<"Ce doriti sa modificati?\n1.Numele\n2.Genul\n3.Anul\n4.Actorul\n5.Pretul\n6.Tipul de ochelari\n0.M-am razgandit.\n";
                    n=_getch();
                    switch(n){
                        case 49: //1 Numele
                            char nume[255];
                            cout<<"Introduceti un nume nou:";
                            cin.getline(nume,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->nume;
                                temp->nume=new char[strlen(nume)+1];
                                strcpy(temp->nume,nume);
                            }
                            break;
                        case 50: //2 Genul
                            char gen[255];
                            cout<<"Introduceti un gen nou:";
                            cin.getline(gen,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->gen;
                                temp->gen=new char[strlen(gen)+1];
                                strcpy(temp->gen,gen);
                            }
                            break;
                        case 51: // 3 Anul
                            int an;
                            cout<<"Introduceti un an nou:";
                            cin>>an;
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                temp->an=an;
                            }
                            break;
                        case 52: // 4 Actorul
                            char actor[255];
                            cout<<"Introduceti un actor nou:";
                            cin.getline(actor,254);
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                delete temp->actor;
                                temp->actor=new char[strlen(actor)+1];
                                strcpy(temp->actor,actor);
                            }
                            break;
                        case 53: //5 Pretul
                            int pret;
                            cout<<"Introduceti un pret nou:";
                            cin>>pret;
                            cout<<"\nFaceti modificarea?(y/n)";
                            if(question()){
                                temp->pretbilet=pret;
                            }
                            break;
                        case 54: //6 Tipul de ochelari
                            int t;
                            do{
                                system("cls");
                                cout<<"Alege tipul de ochelari sau detalii:";
                                cout<<"\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n4.Detalii\n5.M-am razgandit!\n"<<endl;
                                t=_getch();
                                switch(t){
                                    case 49: //1
                                        cout<<"\nFaceti modificarea ?(y/n)";
                                        if(question()){
                                            temp->ochelari=o[0]; // Anaglyph
                                            t=-1;
                                        }
                                        break;
                                    case 50: //2
                                        cout<<"\nFaceti modificarea ?(y/n)";
                                        if(question()){
                                            temp->ochelari=o[1]; // Polarized
                                            t=-1;
                                        }
                                        break;
                                    case 51: //3
                                        cout<<"\nFaceti modificarea ?(y/n)";
                                        if(question()) {
                                            temp->ochelari = o[2]; // Active Shutter
                                            t = -1;
                                        }
                                        break;
                                    case 52: //4
                                        int det;
                                        do{ system("cls");
                                            cout<<"Alege ochelarii despre care vrei sa aflii mai mult.";
                                            cout<<"\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n0.Inapoi"<<endl;
                                            det=_getch();
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
                                        }while(det!=48);
                                        break;
                                    case 53:
                                        t=-1;
                                        break;
                                    default:
                                        cout<<"Alege unul dintre numerele corecte."<<endl;
                                }
                                // BUG HAPPENED HERE
                            }while(t!=-1);
                            break;
                        case 48:
                            cout<<"Iesim din modificare...";
                            break;
                    }
                }
                cout<<"Ma intorc...";
            }
            else{
                cout<<"\nAm incheiat operatia"<<endl;
                cin.ignore();
            }
        } else {
            while (temp != NULL && temp->id!=iddat) {
                prev = temp;
                temp = temp->next;
            }
            //daca nu a gasit numele
            if (temp == NULL)
                cout << "ID-ul nu a fost gasit in lista filmelor 3D!" << endl;
            else{
                cout<<"Filmul a fost gasit in lista filmelor 3D! Detalii:\n";
                cout<<temp;
                cout<<"Sunteti sigur(a) ca vreti sa modificati acest film?(y/n)";
                if(question()){
                    system("cls");
                    int n=6;
                    while(n!=48){
                        system("cls");
                        cout<<"Detalii curente:\n";
                        cout<<temp<<endl;
                        cout<<"Ce doriti sa modificati?\n1.Numele\n2.Genul\n3.Anul\n4.Actorul\n5.Pretul\n6.Tipul de ochelari\n0.M-am razgandit.\n";
                        n=_getch();
                        switch(n){
                            case 49:
                                char nume[255];
                                cout<<"Introduceti un nume nou:";
                                cin.getline(nume,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->nume;
                                    temp->nume=new char[strlen(nume)+1];
                                    strcpy(temp->nume,nume);
                                }
                                break;
                            case 50:
                                char gen[255];
                                cout<<"Introduceti un gen nou:";
                                cin.getline(gen,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->gen;
                                    temp->gen=new char[strlen(gen)+1];
                                    strcpy(temp->gen,gen);
                                }
                                break;
                            case 51:
                                int an;
                                cout<<"Introduceti un an nou:";
                                cin>>an;
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    temp->an=an;
                                }
                                break;
                            case 52:
                                char actor[255];
                                cout<<"Introduceti un actor nou:";
                                cin.getline(actor,254);
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    delete temp->actor;
                                    temp->actor=new char[strlen(actor)+1];
                                    strcpy(temp->actor,actor);
                                }
                                break;
                            case 53:
                                int pret;
                                cout<<"Introduceti un pret nou:";
                                cin>>pret;
                                cout<<"\nFaceti modificarea?(y/n)";
                                if(question()){
                                    temp->pretbilet=pret;
                                }
                                break;
                            case 54: //6 Tipul de ochelari
                                int t;
                                do{
                                    system("cls");
                                    cout<<"Alege tipul de ochelari sau detalii:";
                                    cout<<"\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n4.Detalii\n5.M-am razgandit!\n"<<endl;
                                    t=_getch();
                                    switch(t){
                                        case 49: //1
                                            cout<<"\nFaceti modificarea ?(y/n)";
                                            if(question()){
                                                temp->ochelari=o[0]; // Anaglyph
                                                t=-1;
                                            }
                                            break;
                                        case 50: //2
                                            cout<<"\nFaceti modificarea ?(y/n)";
                                            if(question()){
                                                temp->ochelari=o[1]; // Polarized
                                                t=-1;
                                            }
                                            break;
                                        case 51: //3
                                            cout<<"\nFaceti modificarea ?(y/n)";
                                            if(question()) {
                                                temp->ochelari = o[2]; // Active Shutter
                                                t = -1;
                                            }
                                            break;
                                        case 52: //4
                                            int det;
                                            do{ system("cls");
                                                cout<<"Alege ochelarii despre care vrei sa aflii mai mult.";
                                                cout<<"\n1.Anaglyph\n2.Polarized\n3.Active Shutter\n0.Inapoi"<<endl;
                                                det=_getch();
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
                                            }while(det!=48);
                                            break;
                                        case 53:
                                            t=-1;
                                            break;
                                        default:
                                            cout<<"Alege unul dintre numerele corecte."<<endl;
                                    }
                                    // BUG HAPPENED HERE
                                }while(t!=-1);
                                break;
                            case 48:
                                cout<<"Iesim din modificare...";
                                break;
                        }
                    }
                    cout<<"Ma intorc...";
                }
                else{
                    cout<<"Am incheiat operatia"<<endl;
                }
            }
        }
    }
    void afisare(){
        //cout<<"Entered afisare\n";
        Film3D *p1;
        p1=this->head;
        while(p1){
            cout<<p1;
            p1=p1->next;
        }
    }
    void afisarenume(){
        //cout<<"Entered afisare\n";
        Film3D *p1;
        p1=this->head;
        while(p1){
            cout<<"("<<p1->id<<") "<<p1->nume<<endl;
            p1=p1->next;
        }
    }
    void stocare(){
        cout<<"stocare3d Called."<<endl;
        Film3D *p1;
        ofstream stoc;
        stoc.open("lista.txt",ios::app); // adauga la lista
        p1=this->head;
        while(p1){
            stoc<<p1->nume<<","<<p1->gen<<","<<p1->an<<","<<p1->actor<<","<<p1->pretbilet<<","<<"1,"<<p1->ochelari.nume<<","<<endl;
            p1=p1->next;
        }
    }
    friend void afisarefilmenume(char *);
    friend void afisarefilmegen(char *);
    friend void afisarefilmeactor(char *);
    friend void afisarefilmid(int &);
};
#endif //SPFILM_LISTE_H

#include <iostream>
#include <cstring>
using namespace std;

class PassengerList{
public:
    string passengername;
    string passengerflight;
    PassengerList *nextnode;
    PassengerList(const string passengername,string passengerflight,PassengerList* p=NULL){
        //Schimbam numele pasagerului la cel primit de la user
        this->passengername=passengername;
        //Schimbam numele zborului la cel primit de la user
        this->passengerflight=passengerflight;

        this->nextnode=p;
    }
};

class PassengerTicket{
private:
   PassengerList *lhead,*ltail;

public:
    //Declaram un constructor pentru clasa
    PassengerTicket();
    //Declaram un destructor pentru clasa
    ~PassengerTicket();

    //Declaram functiile pe care le vom folosi

    void reversePassengerticket();
    void cancellPassengerticket();
    void checkPassengerticket();
    void afisare();
};



PassengerTicket::PassengerTicket() {
    lhead=ltail=NULL;
}

PassengerTicket::~PassengerTicket() {
    PassengerList* p=lhead,*q=lhead;
    // Sterge noduri din lista pana devine goala.
    while(p!=NULL){
        q=lhead->nextnode;
        //Sterge fiecare nod din lista
        delete p;
        //Pana cand lista devine goala;
        p=q;
    }
}
//This function adds name of passenger and name of flight to linked list
void PassengerTicket::reversePassengerticket() {
    //Declaram variabile
    string passengername;
    string passengerflight;
    //Input de la USER
    cout<<"Enter passenger Name:";
    cin>>passengername;
    cout<<"Enter flight Name:";
    cin>>passengerflight;
    //Daca lista este goala atunci adaugam detaliile pasagerului in HEAD
    if(lhead==NULL){
        //Punem detaliile pasagerului ca si primul nod al listei
        lhead=ltail=new PassengerList(passengername,passengerflight);
        //Se afiseaza mesajul
        cout<<"Succesful Booking";
        return;
    }
    else{
        PassengerList *p=lhead;
        while(p->nextnode){
            if(passengername!=p->passengername) {
                break;
            }
            else p=p->nextnode;
        }
        p->nextnode=new PassengerList(passengername,passengerflight,p->nextnode);
        cout<<"Succesful";
        return;
    }


}
//Functia urmatoare anuleaza biletul deja rezervat
//Obtine informatia de la user si sterge nodul corespunzator din lista

void PassengerTicket::cancellPassengerticket() {
    //declaram variabilele
    string passengername,passengerflight;
    //Obtinem detele de la USER
    cout<<"Enter passenger Name:";
    cin>>passengername;
    cout<<"Enter passenger Flight:";
    cin>>passengerflight;
    PassengerList *p=lhead,*q=lhead;
    if((p->passengername==passengername)&&(p->passengerflight == passengerflight)){
    lhead=lhead->nextnode;
    cout<<"Ticket Cancelled";
    delete p;
    return;
}
    p=lhead->nextnode;
    //Stergem toate nodurile listei care se potrivesc cu datele data de USER
    while(p){
        //Comparam datele date de USER cu cele din lista
        //Daca corespund,nodul este sters
        if((p->passengername==passengername)&&(p->passengerflight == passengerflight)){
            q->nextnode=p->nextnode;
            delete p;
            //Display Message
            cout<<"Succesful Cancellation";
            return;
        }
        else{
            q=p;
            p=p->nextnode;
        }

    }
    cout<<"No such person exists";
    return;
}

//Functia checkPassengerticket() cauta in toata lista daca datele introduse
//de USER exista.Daca le gaseste afiseaza numele pasagerului si detaliile zborului

void PassengerTicket::checkPassengerticket() {
    string passengername;
    cout<<"Enter Passenger Name:";
    cin>>passengername;
    PassengerList* p=lhead;
    while(p!=NULL){
        if(p->passengername==passengername){
            cout<<"Passenger Name"<<"\n"<<p->passengername<<"\n"<<"Flight Name"<<"\n"<<p->passengerflight<<"\n";
            return;
        }else p=p->nextnode;
    }
    //Afisam mesaj
    cout<<"Succesful!";
    return;

}

//Urmatoare functie afiseaza toate informatiie din lista

void PassengerTicket::afisare() {
    PassengerList* p=lhead;
    //Printam toate informatiile pasagerilor pana lista ajunge la sfarsit
    while(p!=NULL){

        cout<<"==============================\n"<<"Passenger Name"<<"\n"<<p->passengername<<"\n"<<" Flight Name"<<"\n"<<p->passengerflight<<"\n"<<"==============================\n";

        p=p->nextnode;
    }
    cout<<"\n\n\n";
}


int main() {
    PassengerTicket t;
    while(true){
        //display menu
        cout<<"=============================="<<"\n";

        cout<<"Airline Ticket Reservation Program"<<"\n";

        cout<<"1. Book Ticket"<<"\n";

        cout<<"2. Cancel Ticket"<<"\n";

        cout<<"3. Check Ticket"<<"\n";

        cout<<"4. Display Passengers"<<"\n";

        cout<<"5. Quit"<<"\n";

        cout<<"=============================="<<"\n";

        cout<<"Enter your choice:";

        //recieve user input

        int option;
        cin>>option;

        switch(option){
            case 1:
                t.reversePassengerticket();
                break;
            case 2:
                t.cancellPassengerticket();
                break;
            case 3:
                t.checkPassengerticket();
                break;
            case 4:
                t.afisare();
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid Option!Try again.";
                break;
        }

    }
    return 0;

}

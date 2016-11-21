#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;
/*
3. praktiskais darbs "Virtualas funkcijas"
Autors   : Guntis Bertins
Grupa    : P2-4
Variants : 16 "Celosana"
Uzdevums :
Izveidot sava individuâlâ varianta bâzes klasi ar trîs atribûtiem: publisko, aizsargâto un privâto.

Izveidot divus konstruktorus (vienu – bez parametriem), kas inicializç klases atribûtus un destruktoru,
kas paziòo par objekta iznîcinâðanu.

Izveidojiet set un get metodes privâtajam un aizsargâtajam atribûtam. Izveidot print metodi
un kâdu savu metodi, kas veic aprçíinus (ja iespçjams, tad ar klases atribûtiem) un atgrieþ vçrtîbu.

Izveidot atvasinâto klasi, kura publiski manto bâzes klasei un papildina bâzes klasi
ar diviem privâtiem atribûtiem. Pievienot atbilstoðâs set un get metodes.

Izveidot divus konstruktorus, kas inicializç jaunos klases atribûtus un destruktoru. Vienam no tiem
atklâtâ veidâ jâizsauc bâzes klases konstruktoru, nododot tam parametrus.

Pârdefinçjiet bâzes klases metodi print, lai tâ izdrukâtu visu atribûtu vçrtîbas.

Nodemostrçt visu metoþu izsaukumu, izveidojot gan bâzes klases, gan atvasinâtâs klases objektus.
*/

class Travel {
    // Bāzes klases definēšana
private:
                /*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato BussTravel
                privato mainigo nevar mainīt arpus bāzes klases
    */
                int travel_dur;

protected:
                //Mainigie ,kurus var pieskirt tikai Travel un BussTravel
                float travel_price;

public:
                // Mainigie ,kurus var brivi izmantot visâ programmâ
                /*
                [static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
                static int travel_count;
                string travel_name;

                // Non-Overloaded Constructor
                Travel(){
                this->travel_count++;
                this->travel_name = "Tenerife";
                this->travel_dur = 24;
                this->travel_price = 1780.000;
    }
                // Overloaded constructor
                Travel(string name,int dur, float price) {
    this->travel_count++;
                this->travel_name = name;
                this->travel_dur = dur;
                this->travel_price = price;
    }
                // Deconstructor
                ~Travel(){

                cout << endl << "Celojums numurs :  " << travel_count <<" "<< this->travel_name<< " "  << " tika izpardots"<< endl;
travel_count--;
                getch();
    }
                // TravelName method
                string getTravelName();
                void setTravelName(string);
                // Traveldur method
                int getTravelDur();
                void setTravelDur(int);
                // TravelPrice
                void setTravelPrice(float);
                // printData
                void printData();
                // paymentMethode
               virtual float payment(float, int)=0;
};
//Static integer
int Travel::travel_count = 0;

// Metodes TravelName
string Travel::getTravelName() {
                return travel_name;
}

void Travel::setTravelName(string name) {
                this->travel_name = name;
}

// Metodes Traveldur
int Travel::getTravelDur() {
                return travel_dur;
}

void Travel::setTravelDur(int dur) {
                this->travel_dur = dur;
}
// Metodes TravelPrice
void Travel::setTravelPrice(float price) {
                this->travel_price = price;
}
// Kredita aprekina metode
float Travel::payment(float travel_price, int first_payment) {
                return this->travel_price - first_payment;
}
// printData
void Travel::printData() {
                cout << "Celojums  nr." << travel_count << endl <<
                                "Celojuma nosaukums : " << travel_name << endl <<
                                "Celojuma ilgums : " << travel_dur << endl <<
                                "Celojuma izmaksas : " << travel_price << endl;
}

// Secondary Class BussTravel
class BussTravel : public Travel {
private:
                int bussTravel_person;
                string BussTravel_date;

public:

                // person
                int getPerson();
                void setPerson(int person);
                // Date
                string getDate();
    void setDate(string date);

    // Atvasinatas klases aprekinu metode
                float payment(float ,int);

                // Print Order
                void printData();
                BussTravel(){
                    this->travel_name = "Germany";
                    this->travel_price=420.69;
                    this->bussTravel_person=5;
                    this->BussTravel_date="15.2.1995";
                    this->travel_count++;

                }

                // Atvasinatas Class Constructor
                BussTravel(int person, string date, string name,int dur, float price) : Travel(name,dur, price) {

                                this->travel_name = name;
                                this->travel_price = price;
                                this->bussTravel_person = person;
                                this->BussTravel_date = date;
                }

};
// person metodes
int BussTravel::getPerson() {
                return this->bussTravel_person;
}
void BussTravel::setPerson(int person) {
                this->bussTravel_person = person;
}
// Date metodes
string BussTravel::getDate() {
                return this->BussTravel_date;
}
void BussTravel::setDate(string date) {
                this->BussTravel_date = date;
}
// Atvasina bazes klases metodi payment()
float BussTravel::payment(float travel_price, int first_payment) {
                return this->travel_price * bussTravel_person - bussTravel_person*first_payment;
}
// Mikstas mebeles  : Print order
void BussTravel::printData() {
cout <<"Celojuna nosaukums :" << this->getTravelName() << endl <<
                "Celojuma ilgums : " << this->getTravelDur() << endl <<
                "Celojuma izmaksas : " << this->travel_price << " EUR" << endl <<
                "Celojuma personu skaits : " << this->getPerson() << endl<<
                "Datums ,kad izlido : " << this->getDate() << endl;
}
class Plane : public Travel {
protected:
	float plane_distance;
	string plane_company;

public:
	// Non-Overloaded Constructor
	Plane() {
		this->plane_distance = 550;
		this->plane_company = "Air Baltic";

	}

	Plane(float distance, string company, string name,int dur,float price)
		: Travel(name,dur, price) {
		this->travel_name = name;
		this->travel_price = price;
		this->plane_distance = distance;
		this->plane_company = company;

	}

	// Plane distance
	float getPlaneDistance() {
		return this->plane_distance;
	}

	void setPlaneDistance(float distance) {
		this->plane_distance = distance;
	}

	// Plane company
	string getPlaneCompany() {
		return this->plane_company;
	}

	void setPlaneCompany(string company) {
		this->plane_company = company;
	}
	// PrintOrder
	void printOrder();
	float payment(float,int);

};
float Plane::payment(float distance,int first_payment){
	return distance*first_payment -150;
}

void Plane::printOrder() {
	//cout << "Mebele numur." << this->Travel_count << endl;
	cout << "Mebeles nosaukums :" << this->getTravelName() << endl;
	cout << "Summa: " << this->travel_price << " EUR" << endl;
	cout << "Mebeles izmers " << this->getPlaneCompany() << " CM^2 " << endl;
	cout << "Mebeles svars: " << this->getPlaneDistance() << " KG " << endl;

	//cout << "Aprekinu plans " << this->calcDate(plane_distance,plane_company)<<endl;
}


int main() {

    /**< Mainigo defenicija
                --- INTEGER ---
    i - FOR cikla iteracija // count - Ievadamo objektu skaits
    travelS - Nosaka klases izveli // datuIzvelne - Nosaka datu ievades tipu
    people - Utility klases mainigais // empl - Hospital klases mainigais
                --- FLOAT ---
    price - Bazes klases mainigais // size - Utility klases mainigais
                --- STRING ---
    name , street - Bazes klases mainigie // date - Hospital klases mainigie
                -----------                                                     */

                int first_payment,i,travelS,datuIzvelne,distance,person;
                const int count=4;
                float price,dur;
                string name,company,date;
                /*
                [int] first_payment - Variable for function payment
                [float] Price - Variable for travel_price
                [string] Name - Variable for travel_name
              dur - Variable for travel_dur
                */
                first_payment=150;
              Travel *mass[count];

	// Stat of for-loop ,for object creation
	for (i = 0; i < count; i++) {

		cout << i +1 << ".Celojuma regestracija"<<endl<<"Ar kadu veidu velaties parvietoties ?"<<endl<<"1. Ar autobusu vai 2. lidojot? :";
		do {
			cin >> travelS;
			if (travelS != 1 && travelS != 2) {
				cout << "Kludaina datu ievade.";
				cin >> travelS;
			}
		}
		while (travelS != 1 && travelS != 2);

		cout << endl <<"1. Ievadit celumu datus pasam vai 2. Izmantot parastos datus"<<endl;
		do {
			cin >> datuIzvelne;

			switch (travelS) {
			case 1:

				// Non-overloaded constructor
				if (datuIzvelne == 2) {
					mass[i] = new BussTravel;

				}
				// Pasa parametri
				else if (datuIzvelne == 1) {
					cout  <<"Ludzu ievadiet prasitos datus !" << endl;
					cout << "Autobusa celojuma nosaukumi : ";
					cin >> name;
					cout << "Autobusa celojuma datumu : ";
					cin >> date;
					do {
						cout <<"Biletes cenu : ";
						cin >> price;
						if (price <= 0){
							cout << "Cenai jabut lielakai par 0!";
						}
					}
					while (price <= 0);
						do {
						cout <<"Cilveku skaitu : ";
						cin >> person;
						if (person <= 0){
							cout << "Cilveku skaitam ir jabut lielakam par 0";
						}a
					}
					while (person <= 0);
						do {
						cout << "Celojuma ilgumu : ";
						cin >> dur;
						if (dur <= 0){
							cout << "Celojuma ilgumam ir jabut lielakam par 0! : ";
						}
                            }
					while (dur <= 0);
					mass[i] = new BussTravel( person,  date,  name, dur,  price);
				}
				break;do {
                        cout << " Lidojuma attalumu : ";
                    cin >> distance;
						if (distance <= 0){
							cout << "Celojuma attalums nevar but mazaks par nulli : " << endl;
						}
					}while (distance <= 0);


			case 2:
				if (datuIzvelne == 2) {
					mass[i] = new Plane;

				}
				else if (datuIzvelne == 1) {
					cout << "1. Travel" << endl;
					mass[i] = new Plane;
					Plane *pPlane = dynamic_cast<Plane*>(mass[i]);

                    cout <<"Ludzu ievadiet prasitos datus !" << endl;

					cout << "Aviokompanijas nosaukmuu : ";
					cin >> company;

					cout <<"Galamerka valsti : ";
					cin >> name;

					do {
						cout  <<"Lidojuma cenu : ";
						cin >> price;
						if (price <= 0)
							cout << "Cena nevar but mazaka par nulli : ";
					}
					while (price <= 0);
					do {
                        cout << " Lidojuma attalumu : ";
                    cin >> distance;
						if (distance <= 0){
							cout << "Celojuma attalums nevar but mazaks par nulli : " << endl;
						}
					}while (distance <= 0);
					do {
                        cout << " Lidojuma ilgumu : ";
                    cin >> dur;
						if (dur <= 0){
							cout << "Celojuma ilgums nevar but mazaks par nulli : " << endl;
						}
					}while (dur <= 0);


					mass[i] = new Plane( distance,  company,  name,dur,  price);
				break;

			}

			default:
				cout <<endl<< "Nepareizi ievaditas vertibas"<<endl;
		}
			}while (datuIzvelne != 1 && datuIzvelne != 2);
		system("cls");
	}
	for(i=0;i<count;i++){
        BussTravel *pBuss = dynamic_cast<BussTravel*>(mass[i]);
        if(pBuss){
             pBuss->printData();
        }
        else{
          Plane *pPlane = dynamic_cast<Plane*>(mass[i]);

            pPlane->printData();

        }
	}


    return 0;
}


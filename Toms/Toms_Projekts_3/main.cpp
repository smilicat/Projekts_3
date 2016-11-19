#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;
/*
 2. praktiskais darbs "Mantoðana"
 Autors   : Toms Svars
 Grupa    : P2-4
 Variants : 14 "Telpa"
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

class Room {
    // Bāzes klases definēšana
private:
	/*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato Hospital
	privato mainigo nevar mainīt arpus bāzes klases
    */
	string room_street;

protected:
	//Mainigie ,kurus var pieskirt tikai Room un Hospital
	float room_price;

public:
	// Mainigie ,kurus var brivi izmantot visâ programmâ
	/*
	[static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
	static int room_count;
	string room_name;

	// Non-Overloaded Constructor
   Room(){
	this->room_count++;
	this->room_name = "Kabinets";
	this->room_street = "Rigas iela 18";
	this->room_price = 780.000;
    }
	// Overloaded constructor
	Room(string name,string street, float price) {
    this->room_count++;
	this->room_name = name;
	this->room_street = street;
	this->room_price = price;
    }
	// Deconstructor
	~Room(){
	cout << endl << " Telpa numurs :  " << room_count <<" "<< room_name<< " "  << "ir pardota."<< endl;
	room_count--;
	getch();
    }
	// RoomName method
	string getRoomName();
	void setRoomName(string);
	// RoomStreet method
	string getRoomStreet();
	void setRoomStreet(string);
	// RoomPrice
	void setRoomPrice(float);
	// printRoom
	void printRoom();
	// paymentMethode
	virtual float payment(float, int)=0;
};
//Static integer
int Room::room_count = 0;

// Metodes RoomName
string Room::getRoomName() {
	return room_name;
}

void Room::setRoomName(string name) {
	this->room_name = name;
}

// Metodes Roomstreet
string Room::getRoomStreet() {
	return room_street;
}

void Room::setRoomStreet(string street) {
	this->room_street = street;
}
// Metodes RoomPrice
void Room::setRoomPrice(float price) {
	this->room_price = price;
}
// Kredita aprekina metode

// printRoom
void Room::printRoom() {
	cout << "Telpas  nr." << room_count << endl <<
		"Telpas nosaukums : " << room_name << endl <<
		"Telpas adrese : " << room_street << endl << "Telpas cena : " <<
		room_price << endl;
}

// Secondary Class Hospital
class Hospital : public Room {
private:
	int hospital_empl;
	string hospital_date;

public:

	// empl
	int getEmpl();
	void setEmpl(int empl);
	// Date
	string getDate();
    void setDate(string date);

    // Atvasinatas klases aprekinu metode
	float payment(float ,int);
	void unique1();

	// Print Order
	void printRoom();
    Hospital(){
    	this->room_name = "Saules";
		this->room_price = 1234;
		this->hospital_empl = 125;
		this->hospital_date = "12.12.2112";

    }
	// Atvasinatas Class Constructor
	Hospital(int empl, string date, string name,string street, float price) : Room(name,street, price) {
		this->room_name = name;
		this->room_price = price;
		this->hospital_empl = empl;
		this->hospital_date = date;
	}
	~Hospital(){
        cout << "Telpa nr. " << room_count << " " << room_name << " tika pardota" << endl;
        room_count--;
        getch();
	}

};
// empl metodes
int Hospital::getEmpl() {
	return this->hospital_empl;
}
void Hospital::setEmpl(int empl) {
	this->hospital_empl = empl;
}
// Date metodes
string Hospital::getDate() {
	return this->hospital_date;
}
void Hospital::setDate(string date) {
	this->hospital_date = date;
}
// Atvasina bazes klases metodi payment()
float Hospital::payment(float room_price, int empl) {
	return this->room_price * empl;
}
// Mikstas mebeles  : Print order
void Hospital::printRoom() {
	cout << "Telpa numur." << this->room_count << endl <<
	 "Telpas nosaukums :" << this->getRoomName() << endl <<
	"Telpas adrese : " << this->getRoomStreet() << endl <<
	 "Telpas cena: " << this->room_price << " EUR" << endl <<
	"Telpas darbinieku skaits:" << this->getEmpl() << endl<<
	 "Datums ,kad telpa tika izireta: " << this->getDate() << endl;
}
void Hospital::unique1(){
    cout<<"Unikala funkcija !";
}
class Utility : public Room {
protected:
	int utility_people;
	float utility_size;

public:
	// Non-Overloaded Constructor
	Utility() {
		utility_people = 5;
		utility_size = 12.1;

	}

	Utility(float people, float size, string name,string street, float price)
		: Room(name,street, price) {
		this->room_name = name;
		this->room_price = price;
		this->utility_people = people;
		this->utility_size = size;

	}

	// Utility people
	float getUtilityPeople() {
		return this->utility_people;
	}

	void setUtilityPeople(float people) {
		this->utility_people = people;
	}

	// Utility Size
	float getUtilitySize() {
		return this->utility_size;
	}

	void setUtilitySize(float size) {
		this->utility_size = size;
	}

	// Credit
	float payment(float size ,int people) {
		return size*people;
	}
	// printRoom
	void printRoom();

};


void Utility::printRoom() {
	//cout << "Mebele numur." << this->Room_count << endl;
	cout << "Mebeles nosaukums :" << this->getRoomName() << endl;
	cout << "Summa: " << this->room_price << " EUR" << endl;
	cout << "Mebeles izmers " << this->getUtilitySize() << " CM^2 " << endl;
	cout << "Mebeles svars: " << this->getUtilityPeople() << " KG " << endl;
	cout << "Mebeles cena " << this->payment(utility_size ,utility_people)<<endl<<endl;
	//cout << "Aprekinu plans " << this->calcDate(utility_people,Utility_size)<<endl;
}


int main() {
    /**< Mainigo defenicija
                --- INTEGER ---
    i - FOR cikla iteracija // count - Ievadamo objektu skaits
    classSelect - Nosaka klases izveli // paramSelect - Nosaka datu ievades tipu
    people - Utility klases mainigais // empl - Hospital klases mainigais
                --- FLOAT ---
    price - Bazes klases mainigais // size - Utility klases mainigais
                --- STRING ---
    name , street - Bazes klases mainigie // date - Hospital klases mainigie
                -----------                                                     */

	int i,classSelect,paramSelect,people,empl;
	const int count = 4;
	float price,size;
	string name, street,date;

	/**< Masivs ,kurs pieder bazes klasei.
        attiecas uz objektu ievadi un izvadi*/
	Room *arr[count];

	// Datu ievades cikla sakums.
	for (i = 0; i < count; i++) {
    // Objektu izvelne
		cout << endl << i +
			1 << ".Ludzu izvelaties klasi : "<< endl <<" 1. Hospital / 2. Utility : ";
		do {
			cin >> classSelect;
			if (classSelect != 1 && classSelect != 2) {
				cout << "Izveleta klase neeksiste";
			}
		}
		while (classSelect != 1 && classSelect != 2);

		cout << endl <<"1. Lietotajs pats ievada mainigos";
		cout <<endl << "2. Izmantot standarta mainigos"<<endl;
		do {
			cin >> paramSelect;

			switch (classSelect) {
			case 1:

				// Klases Hospital objekts , izmanto neparslogoto Hospital()
				if (paramSelect == 2) {
					arr[i] = new Hospital;
				}
				// Pasa parametri
				else if (paramSelect == 1) {
                Hospital *pHospital = dynamic_cast<Hospital*>(arr[i]);
					cout << "1. Objekts" << endl;

					cout << "Ievadiet slimnicas nosaukmu: ";
					cin >> name;
					cout << "Ievadiet slimnicas adresi";
					cin >> street;


					cout << "Ievadiet slimnicas darbinieku skaitu : ";
					cin >> empl;
					while(empl <= 0){
                        if(empl <=0){
                            cout<<"Darbinieku skaits ir pozitivs un lielaks par nulli";
                                cin >> empl;
                        }
					}
					cout << "Ievadiet slimnicas atversanas";
					cin >> date;

						cout << "Ievadiet izmaksas par 1 dienas arstesanos ";
						cin >> price;
						while(price<=){
						if (price <= 0){
							cout << "Cenai ir jabut lielakai par nulli";
							cin>>price;
				}
			}

					arr[i] = new Hospital( empl,  date,  name, street,  price);
				}
				break;
            /**< Utility klases objektu veidosana*/
			case 2:
			    // Izmanto Utility() konstruktoru
				if (paramSelect == 2) {
					arr[i] = new Utility;

				}
				// Izmanto parslogoto Utility konstruktoru
				else if (paramSelect == 1) {
					cout << "1. Objekts" << endl;
					arr[i] = new Utility;

                    cout << "Ievadiet mebeles nosaukumu";
					cin >> name;

					cout << "Ievadiet mebeles nosaukumu";
					cin >> street;

						cout << "Ievadiet uznemuma darbinieku skaitu ";
						cin >> people;
                        while(people <=0){
                            if(people<=0){
                                cout<<"Darbinieku skaits nevar but vienads ar nulli";
                                    cin >> people;
                            } }

					do {
						cout << "Ievadiet paligtelpu izmeru ";
						cin >> size;
						if (size <= 0)
							cout << "Izmers nevar but mazaks par nulli";
					}
					while (size <= 0);

					do {
						cout << "Ievadiet paligtelpu izmantosas cenu : ";
						cin >> price;
						if (price <= 0)
							cout << "Cena nevar but mazaka par nulli";
					}
					while (price <= 0);
                    // Objekts tiek izmantots ar parslogoto konstruktoru
					arr[i] = new Utility( people,  size,  name, street,  price);
				}
				break;

			default:
				cout <<endl<< "Kludaina ievade !, ludzu izvelaties eksistejosu klasi"<<endl;
			}

		}
		while (paramSelect != 1 && paramSelect != 2);
		/**> Notira konsoli*/
		system("cls");
	}
	// Cikls visu objektu izvadei
	for(i=0;i<count;i++){
        Hospital *pHospital = dynamic_cast<Hospital*>(arr[i]);
        if(pHospital){
            pHospital->unique1();
             pHospital->printRoom();
        }
        else{
          Utility *pUtility = dynamic_cast<Utility*>(arr[i]);
          cout << "Citas mebeles izmaksas :";
            pUtility->printRoom();
        }
	}
getch();
	return 0;
}

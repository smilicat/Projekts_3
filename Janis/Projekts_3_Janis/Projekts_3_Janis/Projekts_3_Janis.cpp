#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>



using namespace std;
/*
3. praktiskais darbs "Virtualas funkcijas"
Autors   : Jānis Mangulis
Grupa    : P2-4
Variants : 17 "Prece"
Uzdevums :
Izveidot sava individuâlâ varianta bâzes klasi ar trîs atribûtiem: publisko, aizsargâto un privâto.

Izmainît otro praktisko darbu:
1. Bâzes klases rçíinoðo metodi pârveidot par tîri virtuâlo.
2. Papildinât programmu ar vçl vienu atvasinâto klasi atbilstoði
individuâlajam uzdevumam. Pievienot tai savu atribûtu un savas metodes.
3. Realizçt bâzes klases rçíinoðo metodi atvasinâtajâs klasçs
(vçlams - ar atðíirîgu realizâciju).
3.1. Pievienot katrâ atvasinâtajâ klasç tai unikâlo metodi.
4. Main funkcijâ izveidot masîvu no norâdçm uz bâzes klases elementiem,
ar to palîdzîbu izveidot atvasinâto klaðu objektus pçc lietotâja izvçles
(lietotâjs izvçlâs gan objekta tipu, gan konstruktora variantu).
5. Izmantojot dinamisko tipu pârveidoðanu un bâzes klases norâdi izsaukt visas programmas metodes
(ar dynamic cast palîdzîbu izsaukt arî unikâlâs atvasinâto klaðu metodes).
*/

class Item {
	// Bāzes klases definēšana
private:
	/*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato Food
	privato mainigo nevar mainīt arpus bāzes klases
	*/
	string item_manuf;

protected:
	//Mainigie ,kurus var pieskirt tikai Item un Food
	float item_price;

public:
	// Mainigie ,kurus var brivi izmantot visâ programmâ
	/*
	[static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
	static int item_count;
	string item_name;

	// Non-Overloaded Constructor
	Item() {
		this->item_count++;
		this->item_name = "Pildspalva";
		this->item_manuf = "China";
		this->item_price = 1,7;
	}
	// Overloaded constructor
	Item(string name, string manuf, float price) {
		this->item_count++;
		this->item_name = name;
		this->item_manuf = manuf;
		this->item_price = price;
	}
	// Deconstructor
	~Item() {
		cout << endl << "Prece numurs :  " << item_count << " " << this->item_name << " " << " tika pardota" << endl;
		item_count--;

	}
	// ItemName method
	string getItemName();
	void setItemName(string);
	// ItemManuf method
	string getItemManuf();
	void setItemManuf(string);
	// ItemPrice
	void setItemPrice(float);
	// printData
	void printData();
	// paymentMethode
	virtual float payment(float, int)=0;
};
//Static integer
int Item::item_count = 0;

// Metodes ItemName
string Item::getItemName() {
	return item_name;
}

void Item::setItemName(string name) {
	this->item_name = name;
}

// Metodes ItemManuf
string Item::getItemManuf() {
	return item_manuf;
}

void Item::setItemManuf(string manuf) {
	this->item_manuf = manuf;
}
// Metodes ItemPrice
void Item::setItemPrice(float price) {
	this->item_price = price;
}
// Kredita aprekina metode
float Item::payment(float item_price, int items) {
	return this->item_price * items;
}
// printData
void Item::printData() {
	cout <<	"Preces nosaukums : " << item_name << endl <<
		"Prece izstradataj valsts : : " << item_manuf << endl <<
		"Preces cena : " << item_price << " Euro" << endl<<endl;
}

// Secondary Class Food
class Food : public Item {
private:
	int food_weight;
	string food_date;

public:

	// weight
	int getWeight();
	void setWeight(int weight);
	// Date
	string getDate();
	void setDate(string date);

	// Atvasinatas klases aprekinu metode
	float payment(float, int);

	// Print Order
	void printData();
	Food() {
		this->item_name = "Cisini";
		this->item_price = 420;
		this->food_date = "15.12.1992";
		this->food_weight = 7;
	}
	// Atvasinatas Class Constructor
	Food(int weight, string date, string name, string manuf, float price) : Item(name, manuf, price) {

		this->item_name = name;
		this->item_price = price;
		this->food_weight = weight;
		this->food_date = date;
	}
	void unique1() {
		cout << "Es esmu unikala ediena funkcija" << endl;
	}

};
// weight metodes
int Food::getWeight() {
	return this->food_weight;
}
void Food::setWeight(int weight) {
	this->food_weight = weight;
}
// Date metodes
string Food::getDate() {
	return this->food_date;
}
void Food::setDate(string date) {
	this->food_date = date;
}
// Atvasina bazes klases metodi payment()
float Food::payment(float item_price, int items) {
	return 0, 21 * item_price*items;
}

// Mikstas mebeles  : Print order
void Food::printData() {
	cout <<"Partikas preces nosaukums :" << this->getItemName() << endl <<
		"Partikas preces razotajvalsts : " << this->getItemManuf() << endl <<
		"Partikas preces cena : " << this->item_price << " EUR" << endl <<
		"Partikas preces svars : " << this->getWeight() << " KG " << endl <<
		"Partikas preces razosanas datums : " << this->getDate() << endl<<endl;
}
// Secondary Class Utility°
class Utility : public Item {
private:
	string utility_size;
	string utility_date;

public:

	// Serial
	string getSize();
	void setSize(string size);
	// Date
	string getDate();
	float payment(float, int);
	void setDate(string date);
	// Print Order
	void printData();
	void unique2();

	Utility() {
		this->utility_size = "54.123.31";
		this->utility_date = "12.05.2013";
		this->item_name = "Spilvens";
		this->item_price = 74;

	}

	// Atvasinatas Class Constructor
	Utility(string size, string date, string name, string manuf, float price)
		: Item(name,manuf,price) {
		this->item_name = name;
		this->item_price = price;
		this->utility_size = size;
		this->utility_date = date;
		
	}


};

// size metodes
string Utility::getSize() {
	return this->utility_size;
}

void Utility::setSize(string size) {
	this->utility_size = size;
}

// Date metodes
string Utility::getDate() {
	return this->utility_date;
}

void Utility::setDate(string date) {
	this->utility_date = date;
}

// Atvasina bazes klases metodi Credit()
float Utility::payment(float item_price, int items) {
	return this->item_price / items;
}

void Utility::unique2() {
	cout << "Esmu saimniecibas preces unikala metode !" << endl;
}

// Mikstas mebeles  : Print order
void Utility::printData() {

	cout << "Saimniecibas prece nosaukums :" << this->getItemName() << endl;
	cout << "Saimniecibas prece razotajs : " << this->getItemManuf() << endl;
	cout << "Saimniecibas prece cena : " << this->item_price << " EUR" << endl;
	cout << "Saimniecibas preces izmers: " << this->getSize() << endl;
	cout << "Saimniecibas preces razosanas datums: " << this->getDate() << endl << endl;

}

int main() {

	int  value, type, i, weight;
	const int count = 4;
	float price;
	string name, manuf, date, size;
	char c;
	/*
	[int] items - Variable for function payment
	[float] Price - Variable for item_price
	[string] Name - Variable for item_name
	manuf - Variable for item_manuf
	*/
	
	// Dynamic array of objects ,with the size of count
	Item *mass[count];
	Utility *pUtility;
	Food *pFood;
	// Stat of for-loop ,for object creation
	for (i = 0; i < count; i++) {

		cout << i +
			1 << ". Precu izvele " << endl << " 1. Ediens " << endl << " 2. Saimnieciska prece : ";
		do {
			cin >> type;
			if (type != 1 && type != 2) {
				cout << "Ludzu atkartojiet ievadi : ";
			}
		} while (type != 1 && type != 2);

		cout << endl << "1. Pasam ievdit ediena datus";
		cout << endl << "2. Izmantot paraugu" << endl;
		do {
			cin >> value;

			switch (type) {
			case 1:

				// Non-overloaded constructor
				if (value == 2) {
					mass[i] = new Food;

				}
				// Pasa parametri
				else if (value == 1) {

					cout << "Ievadiet partikas nosaukumu : ";
					cin >> name;


					cout << "Ievadiet partikas izstradataju : ";
					cin >> manuf;


					cout << "Ievadiet partikas izgatavosanas datumu : ";
					cin >> date;

					do {
						cout << "Ievadiet partikas svaru : ";
						cin >> weight;
						if (weight <= 0)
							cout << "Svars nevar but mazaks par nulli : ";

					} while (weight <= 0);


					do {
						cout << "Ievadiet partikas cenu : ";
						cin >> price;
						if (price <= 0)
							cout << "Summai jabut lielakai par 0! : ";
					} while (price <= 0);

					// Izveido objektu ,balstoties uz atvasinatas klases parslogoto konstruktoru
					mass[i] = new Food(weight, date, name, manuf, price);
				}
				break;

			case 2:
				if (value == 2) {
					mass[i] = new Utility;
				}
				else if (value == 1) {
					cout << "1. Item" << endl;

					
						cout << "Ievadiet saimnieciskas preces nosaukumu : ";
						cin >> name;

						cout << "Ievadiet saimnieciskas prece izstadataju";
						cin >> manuf;

						cout << "Ievadiet saimnieciskas preces izgatavosanas datumu : ";
						cin >> date;


						cout << "Ievadiet saimnieciskas preces izmerus (CM^2) : ";
						cin >> size;



						do {
							cout << "Ievadiet saimnieciskas preces cenu : ";
							cin >> price;
							if (price <= 0)
								cout << "Cena nevar but mazaka par nulli :";
						} while (price <= 0);
						

						mass[i] = new Utility(size, date, name, manuf, price);
						
					}
						break;

					
			default:
				cout << endl << "Ludzu atkartojiet ievadi :" << endl;
				}
				} while (value != 1 && value != 2);
			}
// Cikls izveidoto objektu un unikalo metožu izvadei 
	for (i = 0; i < count; i++) {
		Food *pFood = dynamic_cast<Food*>(mass[i]);
		if (pFood) {
			pFood->unique1();
			pFood->printData();

		}
		else {
			Utility *pUtility = dynamic_cast<Utility*>(mass[i]);
			pUtility->unique2();
			pUtility->printData();


		}

		cin >> c;
	}

	return 0;
}


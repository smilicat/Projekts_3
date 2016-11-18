#include <iostream>
#include <string>
#include <conio.h>
#include <typeinfo>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


using namespace std;
/*
 3. praktiskais darbs "Virtualas funkcijas"
 Autors   : Kirils Volobujevs
 Grupa    : P2-4
 Variants : 8 "Mebeles"
 Uzdevums :

 Izmain�t otro praktisko darbu:
 1. B�zes klases r��ino�o metodi p�rveidot par t�ri virtu�lo.
 2. Papildin�t programmu ar v�l vienu atvasin�to klasi atbilsto�i
 individu�lajam uzdevumam. Pievienot tai savu atrib�tu un savas metodes.
 3. Realiz�t b�zes klases r��ino�o metodi atvasin�taj�s klas�s
 (v�lams - ar at��ir�gu realiz�ciju).
 3.1. Pievienot katr� atvasin�taj� klas� tai unik�lo metodi.
 4. Main funkcij� izveidot mas�vu no nor�d�m uz b�zes klases elementiem,
 ar to pal�dz�bu izveidot atvasin�to kla�u objektus p�c lietot�ja izv�les
 (lietot�js izv�l�s gan objekta tipu, gan konstruktora variantu).
 5. Izmantojot dinamisko tipu p�rveido�anu un b�zes klases nor�di izsaukt visas programmas metodes
 (ar dynamic cast pal�dz�bu izsaukt ar� unik�l�s atvasin�to kla�u metodes).
 */

class Furniture {
private:
	// Bazes klases privatais mainigais ,kurs neattiecas uz SoftFur
	string furniture_color;

protected:
	// Mainigie ,kurus var pieskirt tikai Furniture un SoftFur
	static int furniture_count;
	float furniture_price;

public:
	// Mainigie ,kurus var brivi izmantot vis� programm�
	string furniture_name;
	string order_date;

	// Constructor
	Furniture();
	// Overloaded constructor
	Furniture(string, string, float);
	Furniture(string, float);
	// Deconstructor
	~Furniture();
	// FurnitureName
	string getFurnitureName();
	void setFurnitureName(string);
	// FurnitureColor
	string getFurnitureColor();
	void setFurnitureColor(string);
	// FurniturePrice
	void setFurniturePrice(float);
	// PrintOrder
	void printOrder();
	// CreditMethode
	virtual float credit(float, int) = 0;
};

// Static integer
int Furniture::furniture_count = 0;

// Constructor
Furniture::Furniture() {
	this->furniture_count++;
	this->furniture_name = "Galds";
	this->furniture_color = "Yellow";
	this->furniture_price = 780.1;
}

// Overloaded constructor
Furniture::Furniture(string name, string color, float price) {
	this->furniture_name = name;
	this->furniture_color = color;
	this->furniture_price = price;
}

Furniture::Furniture(string name, float price) {
	this->furniture_name = name;
	this->furniture_price = price;
}

// Deconstructor
Furniture::~Furniture() {
	cout << endl << " Dzestas preces  numurs : " << furniture_count << endl <<
		"Preces nosaukums : " << furniture_name;
	furniture_count--;
	getch();

}

// Metodes FurnitureName
string Furniture::getFurnitureName() {
	return furniture_name;
}

void Furniture::setFurnitureName(string name) {
	this->furniture_name = name;
}

// Metodes FurnitureColor
string Furniture::getFurnitureColor() {
	return furniture_color;
}

void Furniture::setFurnitureColor(string color) {
	this->furniture_color = color;
}

// Metodes furniturePrice
void Furniture::setFurniturePrice(float price) {
	this->furniture_price = price;
}

// Kredita aprekina metode
/*
float Furniture::credit(float furniture_price, int month) {
	return this->furniture_price / month;
}
 */
// printOrder
void Furniture::printOrder() {
	cout << "Main Preces Mebele nr." << furniture_count << endl <<
		"Mebeles nosaukums : " << furniture_name << endl <<
		"Mebeles Krasas : " << furniture_color << endl << "Mebeles cena : " <<
		furniture_price << endl;
}

// Secondary Class SoftFur
class SoftFur : public Furniture {
private:
	string softFur_serial;
	string softFur_date;

public:

	// Serial
	string getSerial();
	void setSerial(string serial);
	// Date
	string getDate();
	float credit(float, int);
	void setDate(string date);
	// Print Order
	void printOrder();
	void combData();

	SoftFur() {
		this->softFur_serial = "54.123.31";
		this->softFur_date = "12.05.2013";
		this->furniture_name = "Spilvens";
		this->furniture_price = 74;

	}

	// Atvasinatas Class Constructor
	SoftFur(string serial, string date, string name, string color, float price)
		: Furniture(name, color, price) {
		this->furniture_name = name;
		this->furniture_price = price;
		this->softFur_serial = serial;
		this->softFur_date = date;
		cout << endl;
	}

};

// Serial metodes
string SoftFur::getSerial() {
	return this->softFur_serial;
}

void SoftFur::setSerial(string serial) {
	this->softFur_serial = serial;
}

// Date metodes
string SoftFur::getDate() {
	return this->softFur_date;
}

void SoftFur::setDate(string date) {
	this->softFur_date = date;
}

// Atvasina bazes klases metodi Credit()
float SoftFur::credit(float furniture_price, int month) {
	return this->furniture_price * month;
}

void SoftFur::combData() {
	cout << "Svarigaka informacija par Mikstajam mebelem ir : " << endl <<
		this->getSerial() << " " << this->getDate() << endl;
}

// Mikstas mebeles  : Print order
void SoftFur::printOrder() {
	//cout << "Mebele numur." << this->furniture_count << endl;
	cout << "Mebeles nosaukums :" << this->getFurnitureName() << endl;
	cout << "Mebeles Krasa : " << this->getFurnitureColor() << endl;
	cout << "Summa: " << this->furniture_price << " EUR" << endl;
	cout << "Pasutijums Nr. " << this->getSerial() << endl;
	cout << "Datums: " << this->getDate() << endl<<endl;

}

class Other : public Furniture {
protected:
	int other_weight;
	float other_size;

public:
	// Non-Overloaded Constructor
	Other() {
		other_weight = 5;
		other_size = 12.1;

	}

	Other(float weight, float size, string name, float price)
		: Furniture(name, price) {
		this->furniture_name = name;
		this->furniture_price = price;
		this->other_weight = weight;
		this->other_size = size;

	}

	// Other Weight
	float getOtherWeight() {
		return this->other_weight;
	}

	void setOtherWeight(float weight) {
		this->other_weight = weight;
	}

	// Other Size
	float getOtherSize() {
		return this->other_size;
	}

	void setOtherSize(float size) {
		this->other_size = size;
	}

	// Credit
	float credit(float size, int weight) {
		return size*weight;
	}
	// PrintOrder
	void printOrder();
	float calcDate(int,float);
};
float Other::calcDate(int weight,float size){
	return weight*size -150;
}

void Other::printOrder() {
	//cout << "Mebele numur." << this->furniture_count << endl;
	cout << "Mebeles nosaukums :" << this->getFurnitureName() << endl;
	cout << "Summa: " << this->furniture_price << " EUR" << endl;
	cout << "Mebeles izmers " << this->getOtherSize() << " CM^2 " << endl;
	cout << "Mebeles svars: " << this->getOtherWeight() << " KG " << endl;
	cout << "Mebeles cena " << this->credit(other_weight,other_size)<<endl<<endl;
	//cout << "Aprekinu plans " << this->calcDate(other_weight,other_size)<<endl;
}

/*
 Autors : Mikus Leduskrasts
 String p�rbaude no vi�a private library
 */
string inputNonEmptyString() {
	string tempString;
	while (1) {
		try {
			getline(cin, tempString);
			if (tempString != "")
				return tempString;
			cout << "The string must not be empty";
		}
		catch (...) {
			cout << "Error in input! There is an issue with the string you provided.\n";
		}
	}
}

int main() {
	int month, value, type, i, size, weight;
	const int count = 4;
	float price;
	string name, color, date, serial;
	char c;
	/*
	 [int] Month - Variable for funtion Credit
	 value -
	 type -
	 i - For cikla inkriments
	 size - Class Other variable for Other_size
	 weight - Class Other variable for Other_weight
	 [const] count - Number or objects in loop
	 [float] price - Variable for furniture_price
	 [string] name - Variable for furniture_name
	 color - Variable for furniture_color
	 date - Class SoftFur vairable for SoftFur_date
	 serail - Class SoftFur variable for SoftFur_serial
	 */

	/* --- Start of interaction --- */

	// Variable input for credit(float,int)
	// [INT] varibale test
	cout << "Number of months : " << endl;
	cin >> month;
	while (month <= 0) {
		if (month <= 0) {
			cout << "Invalid month input. Please repeat input : "
				<< endl;
			cin >> month;
		}
	}

	// Dynamic array of objects ,with the size of count
	Furniture *fur[count];
	 Other *pOther ;
	 SoftFur *pSoft;
	// Stat of for-loop ,for object creation
	for (i = 0; i < count; i++) {

		cout << endl << i +
			1 << ". Furniture registry : "<<endl<<" 1. Soft Furniture "<< endl <<" 2. Other Furniture"<< endl<< "Input : ";
		do {
			cin >> type;
			if (type != 1 && type != 2) {
				cout << "Input is not correct.";
			}
		}
		while (type != 1 && type != 2);

		cout << endl <<"1. Manual atribute input";
		cout <<endl << "2. Use default atributes"<<endl;
		do {
			cin >> value;

			switch (type) {
			case 1:

				// Non-overloaded constructor
				if (value == 2) {
					fur[i] = new SoftFur;

				}
				// Pasa parametri
				else if (value == 1) {



					cout << "1. Furniture" << endl;

					cout << "Ievadiet mebeles nosaukumu: ";
					name = inputNonEmptyString();


					cout << "Ievadiet mebeles krasu: ";
					color = inputNonEmptyString();


					cout << "Ievadiet mebeles izveidosanas datumu (dd/mm/yyyy) ";
					date = inputNonEmptyString();


					cout << "Ievadiet mebeles serialo numuru (****-****)";
					serial = inputNonEmptyString();

					do {
						cout << "Ievadiet mebles cenu: ";
						cin >> price;
						if (price <= 0)
							cout << "Summai jabut lielakai par 0!\n";
					}
					while (price <= 0);

					fur[i] = new SoftFur(serial, date, name, color, price);
				}
				break;

			case 2:
				if (value == 2) {
					fur[i] = new Other;

				}
				else if (value == 1) {
					cout << "1. furniture" << endl;
					fur[i] = new Other;
					Other *pOther = dynamic_cast<Other*>(fur[i]);
					do {

						cout << "Ievadiet mebeles svaru (KG): ";
						cin >> weight;

						if (weight <= 0)
							cout << "Svars nevar but mazaks par nulli";
					}

					while (weight <= 0);
					do {
						cout << "Ievadiet mebeles izmerus (CM^2): ";
						cin >> size;
						if (size <= 0)
							cout << "Izmers nevar but mazaks par nulli";
					}
					while (size <= 0);

					cout << "Ievadiet mebeles nosaukumu";
					name = inputNonEmptyString();

					do {
						cout << "Ievadiet ievadiet mebeles cenu : ";
						cin >> price;
						if (price <= 0)
							cout << "Cena nevar but mazaka par nulli";
					}
					while (price <= 0);

					fur[i] = new Other(weight, size, name, price);
				}
				break;

			default:
				cout <<endl<< "Wrong input (1 or 2)"<<endl;
			}

		}
		while (value != 1 && value != 2);
		system("cls");
	}
	for(i=0;i<count;i++){
        SoftFur *pSoft = dynamic_cast<SoftFur*>(fur[i]);
        if(pSoft){
            pSoft->combData();
             pSoft->printOrder();

        }
        else{
          Other *pOther = dynamic_cast<Other*>(fur[i]);
          cout << "Citas mebeles izmaksas :" << pOther->calcDate(weight,month);
            pOther->printOrder();

        }
getch();
	}

	return 0;
}

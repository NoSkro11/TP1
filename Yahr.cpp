#include "Ship.h"
#include "Yahr.h"


void Yaht::save()
{
	string path = "Yaht.obj";
	ofstream fout;
	fout.open(path, ofstream::app);
	if (!fout.is_open()) {
		cout << "file wasn't opened\n";
	}
	else {
		//cout << "file was open\n";
		Yaht ya(this->type, this->name, this->mission, this->speedMax, this->length, this->crew);
		fout.write((char*)&ya, sizeof(Yaht));
	}
	fout.close();

}

void Yaht::print()
{

	printf("Type: %s\n", this->type);
	printf("Name: %s\n", this->name);
	printf("Mission: %s\n", this->mission);
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Lenght: " << this->length << endl;
	cout << "Count of crew: " << this->crew << endl;
}

void Yaht::change()
{
	this->print();
	this->init();
}

//void Yaht::recovery()
//{
//
//	string path = "Yaht.obj";
//	ifstream fin;
//	fin.open(path);
//	if (!fin.is_open()) {
//		fin.close();
//	}
//	else {
//		cout << "file was open\n";
//		Yaht ya;
//		
//		while (fin.read((char*)&ya, sizeof(Yaht))) {
//			ya.print();
//		}
//		fin.close();
//	}
//	
//	
//}

void Yaht::init()
{
	cout << "введите тип " << endl;
	cin >> this->type;

	cout << "введите название " << endl;
	cin >> this->name;

	cout << "введите назначение " << endl;
	cin >> this->mission;


	cout << "введите максимальную скорость " << endl;
	cin >> this->speedMax;
	inputMy(this->speedMax);


	cout << "введите длину " << endl;
	cin >> this->length;
	inputMy(this->length);


	cout << "¬ведите экипаж " << endl;
	cin >> this->crew;
	inputMy(this->crew);
}

Yaht::Yaht()
{
	this->type[0] = '0';
	this->type[1] = '\0';
	this->name[0] = '0';
	this->name[1] = '\0';
	this->mission[0] = '0';
	this->mission[1] = '\0';
	this->speedMax = 0;
	this->length = 0;
	this->crew = 0;
}

Yaht::Yaht(string str)
{
	string type = "";
	string name = "";
	string mission = "";
	string speedMax;
	string length;
	string crew;
	int i = 0, sign = 0;

	while (str[i] != ';') {

		if (str[i] == '|') {
			sign++;
		}
		else if (str[i] == '#') {
			sign = 0;
		}

		else {

			if (sign < 1) {
				type += str[i];

			}

			else if (sign < 2) {
				name += str[i];
			}

			else if (sign < 3) {
				mission += str[i];
			}

			else if (sign < 4) {
				speedMax += str[i];
			}

			else if (sign < 5) {
				length += str[i];
			}
			else {

				crew += str[i];

			}
		}

		i++;
	}
	//this->type = type;
	//this->name = name;
	//this->mission = mission;
	i = 0;
	while (i < type.length()) {
		this->type[i] = type[i];
		i++;
	}
	this->type[i] = '\0';
	i = 0;
	while (i < name.length()) {
		this->name[i] = name[i];
		i++;
	}
	this->name[i] = '\0';
	i = 0;
	while (i < mission.length()) {
		this->mission[i] = mission[i];
		i++;
	}
	this->mission[i] = '\0';

	this->speedMax = stoi(speedMax);
	this->length = stoi(length);
	this->crew = stoi(crew);
}


Yaht::Yaht(char* type, char* name, char* mission, int speedMax, int length, int crew)
{

	//this->type = type;
	int i = 0;
	do {
		this->type[i] = type[i];
		i++;
	} while (type[i] != '\0');
	this->type[i] = '\0';
	i = 0;
	do {
		this->name[i] = name[i];
		i++;
	} while (name[i] != '\0');
	this->name[i] = '\0';

	i = 0;
	do {
		this->mission[i] = mission[i];
		i++;
	} while (mission[i] != '\0');
	this->mission[i] = '\0';
	//this->name = name;
	//this->mission = mission;
	this->speedMax = speedMax;
	this->length = length;
	this->crew = crew;
}

Yaht::Yaht(int fl)
{
	this->init();
	this->save();
}

Yaht::Yaht(const Yaht& other)
{

	this->speedMax = other.speedMax;
	this->length = other.length;
	this->crew = other.crew;

	int i = 0;
	do {
		this->type[i] = other.type[i];
		i++;
	} while (other.type[i] != '\0');
	this->type[i] = '\0';
	i = 0;
	do {
		this->name[i] = other.name[i];
		i++;
	} while (other.name[i] != '\0');
	this->name[i] = '\0';

	i = 0;
	do {
		this->mission[i] = other.mission[i];
		i++;
	} while (other.mission[i] != '\0');
	this->mission[i] = '\0';

}

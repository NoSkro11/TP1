#include "Ship.h"
#include "Submarine.h"


void Submarine::save()
{
	string path = "Sub.obj";
	ofstream fout;
	fout.open(path, ofstream::app);
	if (!fout.is_open()) {
		cout << "file wasn't opened\n";
	}
	else {
		cout << "file was open\n";
		Submarine sub(this->length, this->width, this->crew, this->time, this->speedMax, this->armament);
		fout.write((char*)&sub, sizeof(Submarine));
	}
	fout.close();
}

//void Submarine::recovery()
//{
//	string path = "Sub.obj";
//	ifstream fin;
//	fin.open(path);
//	if (!fin.is_open()) {
//		fin.close();
//	}
//	else {
//		cout << "file was open\n";
//		Submarine sub;
//		while (fin.read((char*)&sub, sizeof(Submarine))) {
//			sub.print();
//		}
//		fin.close();
//	}
//
//}

void Submarine::print()
{
	cout << "Lenght: " << this->length << endl;
	cout << "Width: " << this->width << endl;
	cout << "Count of crew: " << this->crew << endl;
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Count of arnamet: " << this->armament << endl;
}

void Submarine::change()
{

	this->print();
	this->init();

}

void Submarine::init()
{
	cout << "введите длину" << endl;
	cin >> this->length;
	inputMy(this->length);

	cout << "введите ширину" << endl;
	cin >> this->width;
	inputMy(this->width);

	cout << "введите жкипаж" << endl;
	cin >> this->crew;
	inputMy(this->crew);

	cout << "введите время нахождения под водой" << endl;
	cin >> this->time;
	inputMy(this->time);

	cout << "введите максимальную скорость" << endl;
	cin >> this->speedMax;
	inputMy(this->speedMax);

	cout << "введите вооружение" << endl;
	cin >> this->armament;
	inputMy(this->armament);
}

Submarine::Submarine()
{
	this->length = 0;
	this->width = 0;
	this->crew = 0;
	this->time = 0;
	this->speedMax = 0;
	this->armament = 0;
}

Submarine::Submarine(int fl)
{
	init();
	save();
}

Submarine::Submarine(string str)
{
	string length = "";
	string width = "";
	string crew = "";
	string time = "";
	string speedMax = "";
	string armament = "";
	int i = 0, in = 0, sign = 0;

	while (str[i] != ';') {

		if (str[i] == '|') {
			sign++;
		}
		else if (str[i] == '#') {
			sign = 0;
		}
		else {

			if (sign < 1) {
				length += str[i];

			}

			else if (sign < 2) {
				width += str[i];
			}

			else if (sign < 3) {
				crew += str[i];
			}
			else if (sign < 4) {
				time += str[i];
			}
			else if (sign < 5) {
				speedMax += str[i];
			}
			else {
				armament += str[i];
			}


		}
		i++;
	}
	this->length = stoi(length);
	this->width = stoi(width);
	this->crew = stoi(crew);
	this->time = stoi(time);
	this->speedMax = stoi(speedMax);
	this->armament = stoi(armament);
}

Submarine::Submarine(int lenght, int widht, int crew, int time, int speedMax, int armament)
{
	this->length = lenght;
	this->width = widht;
	this->crew = crew;
	this->time = time;
	this->speedMax = speedMax;
	this->armament = armament;
}

Submarine::Submarine(const Submarine& other)
{
	this->length = other.length;
	this->width = other.width;
	this->crew = other.crew;
	this->time = other.time;
	this->speedMax = other.speedMax;
	this->armament = other.armament;
}

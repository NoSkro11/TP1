#include "Ship.h"
#include "Speedboat.h"

void Speedboat::save()
{
	int i, j;
	char s[80];
	string path = "Sboat.obj";
	ofstream fout;
	fout.open(path, ofstream::app);
	if (!fout.is_open()) {
		cout << "file wasn't opened\n";
	}
	else {
		//cout << "file was open\n";
		drive.getData(i, j, s);
		Speedboat sb(this->mission, this->materials, i, j, s, this->speedMax, this->crew);
		fout.write((char*)&sb, sizeof(Speedboat));
	}
	fout.close();
}

void Speedboat::change()
{
	this->print();
	this->init();
}

//void Speedboat::recovery()
//{
//	string path = "Sboat.obj";
//	ifstream fin;
//	fin.open(path);
//	if (!fin.is_open()) {
//		fin.close();
//	}
//	else {
//		cout << "file was open\n";
//		Speedboat sb;
//		while (fin.read((char*)&sb, sizeof(Speedboat))) {
//			sb.print();
//		}
//		fin.close();
//	}
//}

void Speedboat::print()
{
	int life, weight;
	char count[80];
	this->drive.getData(life, weight, count);
	cout << "Missions: " << this->mission << endl;
	cout << "Materials: " << this->materials << endl;
	cout << "Driving haracteristics: " << life << "\t" << weight << "\t" << count << endl;
	cout << "Max speed: " << this->speedMax << endl;
	cout << "Count of crew: " << this->crew << endl;
}

void Speedboat::init()
{
	int i, j;
	char s[80];
	cout << "введите гарантию " << endl;
	cin >> i;
	inputMy(i);
	cout << "введите вес" << endl;
	cin >> j;
	inputMy(j);


	cout << "введите страну производител¤" << endl;
	cin >> s;
	drive.setData(i, j, s);

	cout << "введите цель миссии" << endl;
	cin >> this->mission;

	cout << "введите материалы" << endl;
	cin >> this->materials;

	cout << "введите максимальную скорость" << endl;
	cin >> this->speedMax;
	inputMy(this->speedMax);

	cout << "введите экипаж " << endl;
	cin >> this->crew;
	inputMy(this->crew);
}

Speedboat::Speedboat(string str)
{
	string mission = "";
	string materials = "";

	string life = "";//срок жизни
	string weight = "";
	string country = "";

	string speedMax = "";
	string crew = "";
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
				mission += str[i];

			}

			else if (sign < 2) {
				materials += str[i];
			}

			else if (sign < 3) {
				in = i;
				//{***|***|***}
				int nSign = 0;
				if (str[in] == '{') {
					//nSign++;
					in++;
				}



				while (str[in] != '}') {
					if (str[in] == '|') {
						nSign++;
					}
					else {
						if (nSign < 1) {
							life += str[in];

						}
						else if (nSign < 2) {
							weight += str[in];
						}
						else if (nSign < 3) {
							country += str[in];
						}
						else if (str[in] != '{') {
							break;
						}

					}
					in++;
				}

				//mission += str[i];
				i = in;

			}

			else if (sign < 4) {
				speedMax += str[i];
			}

			else {
				crew += str[i];
			}
		}

		i++;
	}

	i = 0;
	while (i < mission.length()) {
		this->mission[i] = mission[i];
		i++;
	}
	this->mission[i] = '\0';

	i = 0;
	while (i < materials.length()) {
		this->materials[i] = materials[i];
		i++;
	}
	this->materials[i] = '\0';
	//this->materials = materials;
	char s[80];
	i = 0;
	while (i < country.length()) {
		s[i] = country[i];
		i++;
	}
	s[i] = '\0';
	drive.setData(stoi(life), stoi(weight), s);
	this->speedMax = stoi(speedMax);
	this->crew = stoi(crew);
}

Speedboat::Speedboat()
{

	this->mission[0] = '0';
	this->mission[1] = '\0';
	this->materials[0] = '0';
	this->materials[1] = '\0';
	char s[1] = { '0' };
	this->drive.setData(0, 0, s);
	this->speedMax = 0;
	this->crew = 0;
}

Speedboat::Speedboat(int fl)
{
	this->init();
	this->save();
}

Speedboat::Speedboat(char* missions, char* materials, int life, int weight, char* country, int maxspeed, int crew)
{
	int i = 0;
	do {
		this->mission[i] = missions[i];
		i++;
	} while (missions[i] != '\0');
	this->mission[i] = '\0';

	i = 0;
	do {
		this->materials[i] = materials[i];
		i++;
	} while (materials[i] != '\0');
	this->materials[i] = '\0';

	this->drive.setData(life, weight, country);
	this->speedMax = maxspeed;
	this->crew = crew;
}

Speedboat::Speedboat(const Speedboat& other)
{
	this->crew = other.crew;
	this->speedMax = other.speedMax;

	int i = 0;
	do {
		this->mission[i] = other.mission[i];
		i++;
	} while (other.mission[i] != '\0');
	this->mission[i] = '\0';

	i = 0;
	do {
		this->materials[i] = other.materials[i];
		i++;
	} while (other.materials[i] != '\0');
	this->materials[i] = '\0';

	int j;
	char s[80];

	auto dr = other.drive;
	dr.getData(i, j, s);
	this->drive.setData(i, j, s);


}

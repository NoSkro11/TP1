#pragma once
#include "Ship.h"
#include "helpsFunctions.h"
using namespace std;
class Ship;

class Speedboat :
	public Ship
{
	class drivingCharacteristics {

		int life;
		int weght;
		char country[80];

	public:
		drivingCharacteristics() {
			life = 0;
			weght = 0;
			country[0] = '\0';
		}
		void setData(int life, int weght, char* country) {
			this->life = life;
			this->weght = weght;
			int i = 0;
			do {
				this->country[i] = country[i];
				i++;
			} while (country[i] != '\0');
			this->country[i] = '\0';
			//this->country = country;
		}
		void getData(int& life, int& weght, char* country) {
			life = this->life;
			weght = this->weght;
			int i = 0;
			do {
				country[i] = this->country[i];
				i++;
			} while (this->country[i] != '\0');
			country[i] = '\0';
			//country = this->country;
		}
	};

	drivingCharacteristics drive;
	char mission[80];
	char materials[80];
	int speedMax;
	int crew;


public:
	void save()override;
	void change() override;
	void print()override;
	void init()override;
	Speedboat(string str);
	explicit Speedboat();
	Speedboat(int fl);
	Speedboat(char* missions, char* materials, int life, int weight, char* country, int maxspeed, int crew);
	Speedboat(const Speedboat& other);
};


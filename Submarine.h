#pragma once
#include "Ship.h"
#include "helpsFunctions.h"
using namespace std;

class Ship;

class Submarine :
	public Ship
{
	int length;
	int width;
	int crew;
	int time;
	int speedMax;
	int armament;//вооружение


public:
	void save()override;
	void print()override;
	void change() override;
	void init()override;
	explicit Submarine();
	Submarine(int fl);
	Submarine(string str);
	Submarine(int lenght, int widht, int crew, int time, int speedMax, int armament);
	Submarine(const Submarine& other);
};


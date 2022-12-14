#pragma once
#include"List.h"
#include"Ship.h"
#include"Yahr.h"
#include"Submarine.h"
#include"Speedboat.h"
using namespace std;
class MyDB
{
	List<Yaht> MyYaht;
	List<Submarine> MySubmarine;
	List<Speedboat> MySpeedboat;
public:
	MyDB();

	void printsYaht();
	void printsSub();
	void printSboat();
	void prints();

	void saves();
	void recoverys();

	void addNewYaht();
	void addNewSboat();
	void addNewSub();

	void removeYaht(int i);
	void removeSboat(int i);
	void removeSub(int i);


	int getCntYahts();
	int getCntSub();
	int getCntSboat();

	void changeYaht();
	void changeSub();
	void changeSboat();

};


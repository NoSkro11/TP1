#include "MyDB.h"

MyDB::MyDB()
{
	this->recoverys();

}

void MyDB::prints()
{
	this->printsYaht();
	this->printsSub();
	this->printSboat();

}

void MyDB::printsYaht()
{
	cout << "\n-----------------Yahts----------------\n";
	for (int i = 0; i < MyYaht.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MyYaht[i].print();
	}
	cout << endl;
}

void MyDB::printsSub()
{
	cout << "\n-----------------Submarines----------------\n";
	for (int i = 0; i < MySubmarine.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MySubmarine[i].print();
	}

	cout << endl;
}

void MyDB::printSboat()
{
	cout << "\n-----------------Speed boats----------------\n";
	for (int i = 0; i < MySpeedboat.getSize(); i++) {
		cout << "[" << i << "]:" << endl;
		MySpeedboat[i].print();
	}
	cout << endl;
}

void MyDB::saves()
{
	ofstream of;
	of.open("Yaht.obj");
	of.close();

	of.open("Sub.obj");
	of.close();

	of.open("Sboat.obj");
	of.close();
	for (int i = 0; i < MyYaht.getSize(); i++)
		MyYaht[i].save();

	for (int i = 0; i < MySubmarine.getSize(); i++)
		MySubmarine[i].save();

	for (int i = 0; i < MySpeedboat.getSize(); i++)
		MySpeedboat[i].save();



}

void MyDB::recoverys()
{

	//до тех пор, пока не прочтЄм файл, будем заполн€ть список
	string path = "Yaht.obj";
	ifstream fin;
	fin.open(path);
	cout << "\n-----------------Yahts----------------\n";
	int i = 0;
	if (!fin.is_open()) {

		cout << "not open " << path << endl;
	}
	else {
		Yaht ya;
		while (fin.read((char*)&ya, sizeof(Yaht))) {
			cout << "[" << i << "]:" << endl;
			MyYaht.append(Yaht(ya));
			ya.print();
			i++;
		}
		cout << endl;
	}
	fin.close();

	cout << "\n-----------------Submarines----------------\n";
	i = 0;
	path = "Sub.obj";
	fin.open(path);
	if (!fin.is_open()) {
		cout << "not open " << path << endl;
	}
	else {
		Submarine sub;
		while (fin.read((char*)&sub, sizeof(Submarine))) {
			cout << "[" << i << "]:" << endl;
			MySubmarine.append(Submarine(sub));
			sub.print();
			i++;
		}
		cout << endl;
	}
	fin.close();

	cout << "\n-----------------Speed boats----------------\n";
	i = 0;
	path = "Sboat.obj";
	fin.open(path);
	if (!fin.is_open()) {
		cout << "not open " << path << endl;
	}
	else {
		Speedboat sboat;
		while (fin.read((char*)&sboat, sizeof(Speedboat))) {
			cout << "[" << i << "]:" << endl;
			MySpeedboat.append(Speedboat(sboat));
			sboat.print();
			i++;
		}
		cout << endl;
	}
	fin.close();

}

void MyDB::addNewYaht()
{
	MyYaht.append(Yaht(1));
}

void MyDB::addNewSboat()
{
	MySpeedboat.append(Speedboat(1));
}

void MyDB::addNewSub()
{
	MySubmarine.append(Submarine(1));
}

void MyDB::removeYaht(int i)
{
	try {
		MyYaht.irase(i);
		ofstream of;
		of.open("Yaht.obj");
		of.close();
		for (int i = 0; i < MyYaht.getSize(); i++)
			MyYaht[i].save();
		saves();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}

}

void MyDB::removeSboat(int i)
{
	try {
		MySpeedboat.irase(i);
		ofstream of;
		of.open("Sboat.obj");
		of.close();
		for (int i = 0; i < MySpeedboat.getSize(); i++)
			MySpeedboat[i].save();
		saves();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}
}

void MyDB::removeSub(int i)
{
	try {
		MySubmarine.irase(i);
		ofstream of;
		of.open("Sub.obj");
		of.close();
		for (int i = 0; i < MySubmarine.getSize(); i++)
			MySubmarine[i].save();
		saves();
	}
	catch (int a) {
		cout << "Not deleted\n";
	}

	catch (string s)
	{
		cout << s;
	}
}

int MyDB::getCntYahts()
{
	return MyYaht.getSize();
}

int MyDB::getCntSub()
{
	return MySubmarine.getSize();
}

int MyDB::getCntSboat()
{
	return MySpeedboat.getSize();
}

void MyDB::changeYaht()
{
	int i = 0;
	cout << "¬ведите индекс €хты: ";
	cin >> i;
	MyYaht[i].change();
}

void MyDB::changeSub()
{
	int i = 0;
	cout << "¬ведите индекс судна: ";
	cin >> i;
	MySubmarine[i].change();
}

void MyDB::changeSboat()
{
	int i = 0;
	cout << "¬ведите индекс катера: ";
	cin >> i;
	MySpeedboat[i].change();
}

//void MyDB::cntShips()
//{
//	/*int val;
//	string nstr = "";
//	int pos = str.find("|");
//	int i = pos + 1;
//	while (str[i] != '|') {
//		nstr += str[i];
//		i++;
//	}
//
//	return stoi(nstr);*/
//	
//}
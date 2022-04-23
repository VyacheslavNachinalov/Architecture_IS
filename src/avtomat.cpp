#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Image {
	int imx;
	int imy;
	int pic[10][10];

};

struct Sun
{
	double posX;
	double posY;
};

class Camera
{
	Image picture;

public:
	Image takePhoto()
	{
		ifstream f;
		f.open("photo1");
		char* buf = new char[10];
		for (int i = 0; i < 10; i++){
			f.getline(buf, 10);
			for (int j = 0; j < 10; j++) {
				picture.pic[i][j] = buf[j];
			}
		}
		delete buf;
		return picture;
	}
/*	Sun directToSun() {
		for (int i=0;i<10;i++)
		{
			for (int j=0;j<10;j++)
			{
				if (picture.pic[i][j] > 229) // platinum color in grey-scale or more white 
				{
					
				}
			}
		}
	}*/
};

class CloudService
{
	double speed;
	double time;
	void sendData()
	{

	}
	void giveData(const Systema& syst)
	{
		this.speed = syst.speed;
		this.time = syst.time; 
	}
};
class Generator
{
private:
	double rmp;
	bool activity;
public:
	Generator(Sstates state ) {};
	~Generator() { rmp = 0; };
	void Start() {
		activity = true;
	}
	void Stop(){
		rmp = 0;
		activity = false;
		state = Sstates::Eoff;
	}
};

enum Sstates { starting, Son, Soff, Eon, Eoff, automat, manual, error, recvdata, analysis, EXIT};

class Systema {
	Sstates state;
	Image pictures[1];
	double speed;
	double time;
	bool genState;
	bool workMode;
	Generator gen;
public:
	Systema() {
		state = Sstates::Soff;  //system off
	}
	~Systema() {}
	void setState(Sstates s) {
		switch (s)
		{
		case(Sstates::starting):
			if (state == Son) {
				state = starting;
				cout << "SYSTEM::system is starting!" << endl;
			}
			else cout << "SYSTEM::error" << endl;
			break;

		case (Sstates::Son):
			if (state == Soff) {
				state = Son;
				cout << "SYSTEM::system ON" << endl;
			}
			break;
		case (Sstates::Soff):
			state = Soff;
			cout << "SYSTEM::system OFF" << endl;
			break;

		case (Sstates::Eon):
			if (state== Sstates::analysis || state==manual)
			{
				state = Eon;
				gen.Start();
				cout << "SYSTEM::system Eon" << endl;
			}
			break;

		case (Sstates::Eoff):
			if (state == Sstates::analysis || state == manual)
			{
				state = Eoff;
				gen.Stop();
				cout << "SYSTEM::system Eoff" << endl;
			}
			break;

		case (Sstates::automat):
			if (state == starting || state == manual)
			{
				state = automat;
				cout << "SYSTEM::system automat" << endl;
			}
			break;

		case (Sstates::error):
			state = error;
			cout << "SYSTEM::system error" << endl;
			break;

		case (Sstates::recvdata):
				state = recvdata;
				break;

		case (Sstates::analysis):
					state = Sstates::analysis;
					break;
		}

	}

	void Get_data() {
		
	}
	bool analysis(Image im)
	{
		Sun sun;
		sun.posX = -1;
		sun.posY = -1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (pictures[1].pic[i][j] == 2) {
					sun.posX = i;
					sun.posY = j;
				}
			}
		}
		if (sun.posX == -1) {
			return false;
		}
		return true;
	}
};

Sstates getEvent() {
	string commanda;
	cin >> commanda;
	if (commanda=="starting")
		return Sstates::starting;
	if (commanda == "Son")
		return Sstates::Son;
	if (commanda == "Soff")
		return Sstates::Soff;
	if (commanda == "Eon")
		return Sstates::Eon;
	if (commanda == "Eoff")
		return Sstates::Eoff;
	if (commanda == "automat")
		return Sstates::automat;
	if (commanda == "manual")
		return Sstates::manual;
	if (commanda == "error")
		return Sstates::error;
	if (commanda == "recvdata")
		return Sstates::recvdata;
	if (commanda == "automat")
		return Sstates::analysis;
	if (commanda == "EXIT")
		return Sstates::EXIT;
}

int main()
{
	Systema machine;
	cout << "enter command: " << endl;
	Sstates ev = getEvent();
	cout << ev << endl;
	while (ev != 1) {
		cout << "error, please press 'Son'" << endl;
		ev = getEvent();
	}
	machine.setState(ev);
	ev = getEvent();
	while (ev != 10) {
		machine.setState(ev);
		ev = getEvent(); 
	}

}

#include <iostream>
#include <string>

using namespace std;

struct Image {
	double imx;
	double imy;
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

	}
	Sun directToSun() {

	}
};

class CloudService
{
	double speed;
	double time;
	void sendData()
	{

	}
	void giveData()
	{

	}
};
class Generator
{
private:
	double rmp;
public:
	Generator() {};
	~Generator() {};
	void Start() {

	}
	void Stop(){

	}
};

enum Sstates { starting, Son, Soff, Eon, Eoff, automat, manual, error, recvdata, analysis, EXIT};

class Systema {
	Sstates state;
	Image pictures[300];
	double speed;
	double time;
	bool genState;
	bool workMode;
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
				cout << "SYSTEM::system Eon" << endl;
			}
			break;

		case (Sstates::Eoff):
			if (state == Sstates::analysis || state == manual)
			{
				state = Eoff;
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
	void analysis()
	{

	}
	void Generator()
	{

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
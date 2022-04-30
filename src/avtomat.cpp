#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

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
	void sendPicture()
	{
		
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

class Client{
	public:
		virtual void connect()
		{
			
		}
		virtual void send (string msg)
		{
			
		}
		virtual void disconnect()
		{

		}		
};

class WinClient: public Client{
	public:
		virtual void connect()
		{
			
		}

		virtual void send (string msg)
		{
			
		}
		
		virtual void disconnect()
		{

		}	
};

class LinuxClient: public Client{
	private:
		int sock;
  		struct sockaddr_in addr;

	public:
		LinuxClient()
		{
			sock = socket(AF_INET, SOCK_DGRAM, 0);
		}
		virtual void connect()
		{
  			addr.sin_family = AF_INET;
 			addr.sin_port = htons(3425);
  			addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
		}
		virtual void send (string msg)
		{
			char msg1[] = "MESSAGE1";
			sendto(sock, msg1, sizeof(msg1), 0, (struct sockaddr *)&addr, sizeof(addr));
		}

		
		~LinuxClient()
		{
			close(sock);
		}	
};

class Server{
	public:
		virtual void connect()
		{
			
		}
		virtual void recive()
		{
			
		}
};

class WinServer: public Server{
	public:
		virtual void connect()
		{
			
		}
		virtual void recive()
		{
			
		}	
};

class LinuxServer: public Server{
	private:
		int sock;
  		struct sockaddr_in addr;
  		char buf[50];
  		int bytes_read;

		LinuxServer()
		{
			sock = socket(AF_INET, SOCK_DGRAM, 0);
		}

	public:
		virtual void connect()
		{
			addr.sin_family = AF_INET;
  			addr.sin_port = htons(3425);
  			addr.sin_addr.s_addr = htonl(INADDR_ANY);
  			if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    		perror("bind");
    		return;
			}	
		}

		virtual void recive()
		{
			while(1) {
    		bytes_read = recvfrom(sock, buf, 50, 0, NULL, NULL);
    		buf[bytes_read] = '\0';
    		printf("%s\n", buf);
  			}
		}	
};


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

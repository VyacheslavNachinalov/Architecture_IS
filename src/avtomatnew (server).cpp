#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

class Generator
{
private:
	double rmp;
	bool activity;
public:
	Generator() { activity = false; rmp = 0; };
	~Generator() { rmp = 0; };
	void Start(int sp) {
		activity = true;
		rmp = sp;
	}
	void Stop() {
		rmp = 0;
		activity = false;
	}
};


int main()
{
	Generator gen;
	int speed = 0;
	int sock;
	struct sockaddr_in addr;
	char buf[5];
	int bytes_read;
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("bind");
		return 1;
	}
	while (1) {

		bytes_read = recvfrom(sock, buf, 5, 0, NULL, NULL);
		buf[bytes_read] = '\0';
		cout<<buf<<endl;
		int t = 1;
		for (int i = 3; i >= 1; i--) {
			speed = speed+int(buf[i] -'0') * t; cout <<speed<<endl;
			t = t * 10;
		}
		if (buf[0] == '1') {
			gen.Start(speed);
			cout << "Gen started" << endl;
			cout << "Gen speed = "<< speed<<endl;
		}
			
		if (buf[0] == '0') {
			gen.Stop();
			cout << "Gen stoped" << endl;
		}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include "scheduler.h"
using namespace std;
char buf[256];
char str[256];
int idHost;
int idJob;
string userGroup;

// Command form: scheduler lastHost idJob 
int main(int argc, char* argv[]) {
	idHost = randomHost(NUMBER_HOST);
	cout << "Host to execute jobs:"<<idHost<<endl;
	if (argc<3) {
                cout << "Usage is: scheduler idJob userGroup\n";
                exit(0);
        } else {
                idJob = atoi(argv[1]);
                userGroup = argv[2];
        }
        cout << "IdJob:  "<<idJob<<"    UserGroup:   "<<userGroup<<"\n"<<endl;
	connectHostUseSsh(idHost, "ls");
	return 1;
}

int getIdHost(int lastHost) {
	int idHost = lastHost % NUMBER_HOST+1;
	if (lastHost==8) idHost = 1;
	return idHost;
}

void connectHostUseSsh(int idHost,  const string &commandVM) {
	string command = "ssh -f root@10.0.0."+convertInt(idHost)+" '"+commandVM+
"'";
	cout <<command<<endl;
	system(command.c_str());
		
}

int parseParameter(int argc, char* argv[]) {
	if (argc<4) {
		cout << "Usage is: scheduler lastHost idJob userGroup\n";
		exit(0);
	} else {
		idJob = atoi(argv[2]);
		userGroup = argv[3];
	}
	cout << " IdJob: "<<idJob<<"    UserGroup:"<<userGroup<<"\n"<<endl;

}



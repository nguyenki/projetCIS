#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

#include <limits.h>
#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <map>

#include "scheduler.h"
using namespace std;
string copyCmd = "scp ";
map<string,int> hostJob;

char buf[256];
char str[256];
int idHost;
int idJob;
string userGroup;

// Command form: ./scheduler userGroup
int main(int argc, char* argv[]) {
//	idHost = randomHost(NUMBER_HOST);
//	cout << "Host to execute jobs:"<<idHost<<endl;
//	cout << "IdJob:  "<<idJob<<"    UserGroup:   "<<userGroup<<"\n"<<endl;
//	connectHostUseSsh(idHost, "ls");


	/***********************
	 * Principle task
	 ***********************/
	parseParameter(argc, argv);
	
//	copyAllArchivesToDestination();
	
	copyArchivesToDestinationTempFolder("sge_nom_123456.tar.gz","/tmp/123456/");
	connectHostUseSsh(8,"demarre","123456","sge");

	/****************
	 * END
	 ****************/
	cout<<getIdJob("kim_nomarchives_asf6646116.tar.gz")<<"\n"<<endl;
	cout<<getUserName("kimddf_nomarchive_asf1asf5a.tar.gz")<<endl;
	cout <<"Current directory:"<< getCurrentDirectory() <<"\n"<< endl;
	displayVectorContent(getAllArchivesName(getCurrentDirectory()));
	return 1;
}

void connectHostUseSsh(int idHost, const string &commandVM, const string &idJob, const string &userName) {
	string command = "ssh -f root@10.0.0."+convertInt(idHost)+" '"+commandVM+" "+idJob+" "+userName+
"'";
	cout <<command<<endl;
	system(command.c_str());
}

// To review:

void copyAllArchivesToDestination() {
	string currentD  = getCurrentDirectory();
	vector<string> allArchives = getAllArchivesName(currentD);
	for (vector<string>::const_iterator i = allArchives.begin(); i!= allArchives.end(); ++i) {
		string fileName = *i;
		//string tempsLocation = "/tmp/"+getUserName();
		string tempsLocation = "";
		copyArchivesToDestinationTempFolder(fileName,tempsLocation);
	}
}

void copyArchivesToDestinationTempFolder(const string &fileName, const string &location) {
	idHost = randomHost(NUMBER_HOST);
	idHost = 8;
	hostJob.insert(std::pair<string,int>(getIdJob(fileName),idHost)); // Save the location of host where the job will be executed
	cmdk = "mkdir /tmp/"+getIdJob(fileName);
	string cmd = "ssh -f root@10.0.0."+convertInt(idHost)+ " '"+cmdk+"'";
	system(cmd.c_str());
	system(cmd.c_str());
	system("exit");
	string scpCmd = "scp "+fileName+" root@10.0.0."+convertInt(idHost)+":"+location;
	system(scpCmd.c_str());
}

int parseParameter(int argc, char* argv[]) {
	if (argc<2) {
		cout << "Usage is: scheduler userGroup\n";
		exit(0);
	} else {
		idJob = atoi(argv[1]);
		userGroup = argv[1];
	}
}
//username_nomarchive_ID.tar.gz
string getIdJob(const string &fileName) {
	size_t last_underline = fileName.find_last_of("_");
	if (last_underline==-1) {
		cout<<"Erreur archive name." << "_ NOT FOUND" << endl;
		return string("NULL");
	}
	string sb = fileName.substr(last_underline,fileName.length());
	return sb.substr(1,sb.length()-8);
}

string getUserName(const string &fileName) {
	size_t first_underline = fileName.find_first_of("_");
	if (first_underline==-1) {
                cout<<"Erreur archive name." << "_ NOT FOUND" << endl;
		return string("NULL");
        }
	return fileName.substr(0,first_underline);
}

std::string getCurrentDirectory() {
	char result[ PATH_MAX ];
	ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
	std::string proName = std::string( result, (count > 0) ? count : 0 );
	size_t lastSlash = proName.find_last_of("\\/");
	return proName.substr(0,lastSlash)+"/"; 
}

vector<string> getAllArchivesName(const string &dirPath) {
	vector<string> archives = vector<string>();
	DIR *dp;
	struct dirent *drnt;
	dp = opendir(dirPath.c_str());
	if (dp == NULL) {
		cout << "Error(" << errno << ") opening" << dirPath << endl;
	} else {
		while ((drnt=readdir(dp)) != NULL) {
				archives.push_back(drnt->d_name);
		}
		closedir(dp);
	}
	if (archives.size()>2) {
		archives.erase(archives.end());
		archives.erase(archives.end());
	}
	return archives;
}

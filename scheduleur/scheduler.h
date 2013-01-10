#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define NUMBER_HOST 7
// idjobs, hostname

using namespace std;

void connectHostUseSsh(int idHost, const string &username);
int parseParameter(int argc, char* argv[]);
string getCurrentDirectory();
vector<string> getAllArchivesName(const string &dirPath);
void copyArchivesToDestinationTempFolder(const string &fileName, const string &location);
void copyAllArchivesToDestination();
string getIdJob(const string &fileName);

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int randomHost(int limit)
{
	srand(time(NULL)); // seeds the random number generator with the current time
	int randNum = rand() % limit + 1;
	return randNum;
}

// Test functions
void displayVectorContent(const vector<string> &list) {
	cout << "ALL FILE IN CURRENT DIRECTORY:\n"<< endl;
	for (vector<string>::const_iterator i = list.begin(); i!=list.end(); ++i) {
		cout << *i << "\n" <<endl;
	}
}

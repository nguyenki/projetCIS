#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#define NUMBER_HOST 7
// idjobs, hostname

using namespace std;

void connectHostUseSsh(int idHost, const string &username);
int getIdHost(int lastHost);
int parseParameter(int argc, char* argv[]);

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

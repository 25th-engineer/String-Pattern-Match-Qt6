#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class patternMatch
{
public:
    patternMatch(char [100]);
	~patternMatch();
	bool BF();
	bool RK();
	void generateBC(int []);
	void generateGS(int *, bool *);
	int moveByGS(int, int *, bool *);
	bool BM();
	void getNext(int *);
	bool KMP();
	void random_string(); // static
    void displayTarget();
    void displayPattern();
private:
	string target_s;
	string pattern_s;
	char *target;
	char *pattern;
	int tlen;
	int plen;
    char fileName[100];
};

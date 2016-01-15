#include "string.h"
#include "stdio.h"
#include <iostream>
#include "TsReader.h"
using namespace std;
int main(int argc, char ** args){
	int n = 3;
	unsigned int size = 188;
	unsigned char buf[200];
	memset(buf, 0,200);
	TsReader tr;
	tr.configTsReader("/home/jason_wang/TSCutter/546Mhz_error_onid.ts");
	while (n--){
		if ((size = tr.fileRead((void*)buf, size)) == -1)
		{
			cout << "file read fail !"<< endl;
			return -1;
		}
		cout << "read size: "<< size<<endl;
		for (int i = 0; i<size; i++)
		{
			if (i != 0 && i%16 == 0)
				cout << endl;
			printf("%0.2x ", buf[i]);
		}	
		cout <<endl;
	}
	cout <<endl<< "finish"<<endl;
	return 1;	
}

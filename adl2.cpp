#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	string line;
	string st1[3] = {"it", "to", "about"};

	ifstream myinfile ("inputData.txt", ios::in);
	ofstream myoutfile("outputData.txt", ios::out);

	if (myinfile.is_open())
	{
		cout<<"\n\nOriginal Text: ";
		while (! myinfile.eof() )
		{
			getline (myinfile, line);
			cout << line << endl;
		}

		myinfile.close();
	}

	else
		cout << "Unable to open file";

	
	while(1)
	{
		line = myinfile.get();
		if(buff == EOF)
			break;

		myoutfile.put(line);
	}
	


return 0;
}
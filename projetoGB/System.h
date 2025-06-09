#pragma once

#include <string>

using namespace std;

class System {
public:
	System();
	void set_file(string);
	string get_file();
	void run();

private:
	string file;
	int option;
	void CreateProcess();
	void ExecuteNextProcess();
	void ExecuteSpecificProcess();
	void SaveInFile();
	void RetrieveFromFile();
};
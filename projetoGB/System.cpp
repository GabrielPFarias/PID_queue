#include <iostream>
#include <string>
#include <queue>

#include "ComputingProcess.h"
#include "Process.h"
#include "System.h"

using namespace std;

System::System() {
	this->file = "";
	this->option = 0;
}

void System::set_file(string file) {
	file = file;
}

string System::get_file() {
	return file;
}

void System::run() {
	int option = 0;
	cout << "Digite a opcao desejada: " << endl;
	cout << "(1) Criar Processo" << endl;
	cout << "(2) Executar Proximo" << endl;
	cout << "(3) Executar Processo Especifico" << endl;
	cout << "(4) Salvar fila de processos" << endl;
	cout << "(5) Carregar do arquivo a fila de processos" << endl;
	cin >> option;

	if(option==1) {
		createProcess();
	}
	else if (option==2) {
		executeNextProcess();
	}
	else if (option == 3) {
		executeSpecificProcess();
	}
}


void System::createProcess() {
	int option = 0;
	cout << "Escolha o processo que deseja criar: " << endl;;
	cout << "(1) ComputingProcess" << endl;
	cout << "(2) WritingProcess" << endl;
	cout << "(3) ReadingProcess" << endl;
	cout << "(4) PrintingProcess" << endl;
	cin >> option;

	if(option==1) {
		string equation = "";
		cout << "Digite a equacao: ";
		cin >> equation;

		ComputingProcess computingProcess;
		computingProcess.parse(equation);
		computingProcess.execute();
	}
	else if(option == 2) {
		
	}
	else if (option == 3) {

	}
}

void System::executeNextProcess() {
	if (!processQueue.empty()) {
		Process* removedProcess = processQueue.front();
		removedProcess->execute();
		processQueue.pop();
	}
	else {
		cout << "Não há processos na fila." << endl;
	}
}

void System::executeSpecificProcess() {
	if (processQueue.empty()) {
		cout << "Não há processos na fila." << endl;
	}
	else {
		queue<Process*> processQueueTemp;
		bool found = false;
		int processPID = 0;

		cout << "Digite o PID do processo que deseja executar: ";
		cin >> processPID;
		while (!processQueue.empty()) {
			Process* current = processQueue.front();
			processQueue.pop();

			if (current->get_PID() == processPID && !found) {
				current->execute();
				delete current;
				found = true;
				continue; // nao faz o push do processo na fila temp
			}
			processQueueTemp.push(current);
		}
		if (!found) {
			cout << "Processo com PID " << processPID << " nao encontrado." << endl;
		}

		processQueue = processQueueTemp; // atualiza a fila original sem o processo executado
	}
}
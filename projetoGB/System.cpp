#include <iostream>
#include <string>
#include <queue>

#include "ComputingProcess.h"
#include "PrintingProcess.h"
#include "ReadingProcess.h"
#include "WritingProcess.h"
#include "Process.h"
#include "System.h"

using namespace std;

System::System() {
	this->computation_file = "";
	this->pid_counter = 1;
}

void System::set_computation_file(string computation_file) {
	computation_file = computation_file;
}

string System::get_computation_file() {
	return computation_file;
}

void System::run() {
	int option = -1;
	while (true) {
		cout << "(1) Criar Processo" << endl;
		cout << "(2) Executar Proximo" << endl;
		cout << "(3) Executar Processo Especifico" << endl;
		cout << "(4) Salvar fila de processos" << endl;
		cout << "(5) Carregar do arquivo a fila de processos" << endl;
		cout << "(0) Sair" << endl;
		cout << "Digite a opcao desejada: ";
		cin >> option;
		cout << "\n";

		switch (option) {
		case 1:
			createProcess();
			break;
		case 2:
			executeNextProcess();
			break;
		case 3:
			executeSpecificProcess();
			break;
		case 4:
			// salvarFila(); // (adicione isso quando implementar)
			cout << "[placeholder] Salvando fila..." << endl;
			break;
		case 5:
			// carregarFila(); // (adicione isso quando implementar)
			cout << "[placeholder] Carregando fila..." << endl;
			break;
		case 0:
			cout << "Saindo do sistema..." << endl;
			return;
		default:
			cout << "Opcao invalida. Tente novamente." << endl;
			break;
		}
	}
}


void System::createProcess() {
	int option = 0;
	cout << "(1) ComputingProcess" << endl;
	cout << "(2) WritingProcess" << endl;
	cout << "(3) ReadingProcess" << endl;
	cout << "(4) PrintingProcess" << endl;
	cout << "Escolha o processo que deseja criar: ";
	cin >> option;

	if (option == 1) {
		string equation = "";
		cout << "Digite a equacao: " << endl;
		cin.ignore();
		getline(cin, equation);

		ComputingProcess* computingProcess = new ComputingProcess();
		computingProcess->parse(equation);
		computingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(computingProcess);
	}
	else if (option == 2) {
		string equation = "";
		cout << "Digite a equacao: " << endl;
		cin.ignore();
		getline(cin, equation);

		WritingProcess* writingProcess = new WritingProcess();
		writingProcess->set_file(computation_file);
		writingProcess->set_equation(equation);
		writingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(writingProcess);
	}
	else if (option == 3) {
		ReadingProcess* readingProcess = new ReadingProcess(&processQueue);
		readingProcess->set_file(computation_file);
		readingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(readingProcess);
	}
	else if (option == 4) {
		PrintingProcess* printingProcess = new PrintingProcess(&processQueue);
		printingProcess->set_file(computation_file);
		printingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(printingProcess);
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

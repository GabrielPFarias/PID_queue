#include <fstream>
#include <iostream>
#include <string>
#include <queue>

#include "util.h"
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
	this->pool_file = "";
}

void System::set_computation_file(string computation_file) {
	this->computation_file = computation_file;
}

string System::get_computation_file() {
	return computation_file;
}

void System::set_pool_file(string pool_file) {
	this->pool_file = pool_file;
}

string System::get_pool_file() {
	return pool_file;
}

void System::run() {
	int option = -1;
	while (true) {
		cleanTerminal();
		cout << "MENU PRINCIPAL\n" << endl;
		cout << "(1) Criar Processo" << endl;
		cout << "(2) Executar Proximo" << endl;
		cout << "(3) Executar Processo Especifico" << endl;
		cout << "(4) Salvar fila de processos" << endl;
		cout << "(5) Carregar do arquivo a fila de processos" << endl;
		cout << "(0) Sair\n" << endl;
		cout << "Digite a opcao desejada: ";
		cin >> option;
		cout << "\n";

		switch (option) {
		case 1:
			cleanTerminal();
			createProcess();
			break;
		case 2:
			cleanTerminal();
			executeNextProcess();
			break;
		case 3:
			//cleanTerminal();
			executeSpecificProcess();
			break;
		case 4:
			//cleanTerminal();
			saveInFile();
			break;
		case 5:
			retrieveFromFile();
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
	cout << "CRIAR PROCESSO\n" << endl;
	cout << "(1) ComputingProcess" << endl;
	cout << "(2) WritingProcess" << endl;
	cout << "(3) ReadingProcess" << endl;
	cout << "(4) PrintingProcess\n" << endl;
	cout << "Escolha o processo que deseja criar: ";
	cin >> option;

	if (option == 1) {
		cleanTerminal();
		string equation = "";
		cout << "Digite a equacao: ";
		cin.ignore();
		getline(cin, equation);

		while (verifyEquationSyntax(equation) != true) {
			cleanTerminal();
			cout << "Digite a equacao: " << endl;
			cin >> equation;
		}

		ComputingProcess* computingProcess = new ComputingProcess();
		computingProcess->set_equation(equation);
		computingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(computingProcess);
		cout << "\nEquacao criada com sucesso!" << endl;
		tapToContinue();
	}
	else if (option == 2) {
		string equation = "";

		while (verifyEquationSyntax(equation) != true) {
			cleanTerminal();
			cout << "Digite a equacao: " << endl;
			cin >> equation;
		}
		
		WritingProcess* writingProcess = new WritingProcess();
		writingProcess->set_file(computation_file);
		writingProcess->set_equation(equation);
		writingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(writingProcess);
		tapToContinue();
	}
	else if (option == 3) {
		ReadingProcess* readingProcess = new ReadingProcess(&processQueue, &pid_counter);
		readingProcess->set_file(computation_file);
		readingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(readingProcess);
		tapToContinue();
	}
	else if (option == 4) {
		PrintingProcess* printingProcess = new PrintingProcess(&processQueue);
		printingProcess->set_PID(pid_counter);
		pid_counter++;
		processQueue.push(printingProcess);
		tapToContinue();
	}
}

bool System::verifyEquationSyntax(string equation) {
	equation = removeSpaces(equation);
	if (equation.empty()) {
		return false;
	}
	if (equation.size() < 2) {
		cout << "Erro: expressão muito curta." << endl;
		tapToContinue();
		return false;
	}

	size_t opPos = equation.find_first_of("+-*/xX");
	if (opPos == string::npos) {
		cout << "Erro: operador não encontrado." << endl;
		tapToContinue();
		return false;
	}

	try {
		double num1 = stod(equation.substr(0, opPos));
		string sign = equation.substr(opPos, 1);
		double num2 = stod(equation.substr(opPos + 1));

		if (sign != "+" && sign != "-" && sign != "*" &&
			sign != "/" && sign != "x" && sign != "X") {
			cout << "Erro: operador inválido." << endl;
			tapToContinue();
			return false;
		}

		return true;
	}
	catch (const std::exception& e) {
		cout << "Erro ao converter números: " << e.what() << endl;
		tapToContinue();
		return false;
	}
}

void System::executeNextProcess() {
	if (!processQueue.empty()) {
		Process* removedProcess = processQueue.front();
		removedProcess->execute();
		processQueue.pop();
		cout << "Processo executado!" << endl;
		tapToContinue();
	}
	else {
		cout << "Nao existem processos na fila." << endl;
		tapToContinue();
	}
}

void System::executeSpecificProcess() {
	cleanTerminal();
	if (processQueue.empty()) {
		cout << "Nao existem processos na fila." << endl;
		tapToContinue();
	}
	else {
		Process* processToExecute = nullptr;
		queue<Process*> processQueueTemp;
		bool found = false;
		int processPID = 0;

		cout << "Digite o PID do processo que deseja executar: ";
		cin >> processPID;
		while (!processQueue.empty()) {
			Process* current = processQueue.front();
			processQueue.pop();

			if (current->get_PID() == processPID && !found) {
				processToExecute = current;
				found = true;
				continue; // nao faz o push do processo na fila temp
			}
			processQueueTemp.push(current);
		}

		processQueue = processQueueTemp; // atualiza a fila original sem o processo executado

		if (found && processToExecute != nullptr) {
			processToExecute->execute();
			tapToContinue();
		}
		else {
			cout << "Processo com PID " << processPID << " nao encontrado." << endl;
			tapToContinue();
		}
	}
}

void System::saveInFile(){
	cleanTerminal();
	ofstream oMyFile(pool_file);
	queue<Process*> processQueueTemp = processQueue;

	while (!processQueueTemp.empty()) {
		Process* tempProcess = processQueueTemp.front();
		processQueueTemp.pop();
		oMyFile << tempProcess->toPoolFile() << endl;
	}
	oMyFile.close();
	cout << "Arquivo salvo!" << endl;
	tapToContinue();
}

void System::retrieveFromFile() {
	while (!processQueue.empty()) {
		processQueue.pop();
	}

	ifstream iMyFile(pool_file);
	vector<string> parts;
	string line = "";
	while (getline(iMyFile, line)) {
		size_t start = 0;
		size_t end = line.find(';');
		

		while (end != string::npos) {
			parts.push_back(line.substr(start, end - start));
			start = end + 1;
			end = line.find(';', start);
		}
		parts.push_back(line.substr(start));
	}

	string type = parts[0];
	int pid = stoi(parts[1]);

	if (type == "ComputingProcess") {
		ComputingProcess* new_process = new ComputingProcess();
		new_process->set_equation(parts[2]);
		new_process->set_PID(pid);
		processQueue.push(new_process);
	}
	else if (type == "WritingProcess") {
		WritingProcess* new_process = new WritingProcess();
		new_process->set_equation(parts[2]);
		new_process->set_PID(pid);
		new_process->set_file(computation_file);
		processQueue.push(new_process);
	}
	else if (type == "ReadingProcess") {
		ReadingProcess* new_process = new ReadingProcess(&processQueue, &pid_counter);
		new_process->set_PID(pid);
		new_process->set_file(computation_file);
		processQueue.push(new_process);
	}
	else if (type == "PrintingProcess") {
		PrintingProcess* new_process = new PrintingProcess(&processQueue);
		new_process->set_PID(pid);
		processQueue.push(new_process);
	}

	if (pid >= pid_counter) {
		pid_counter += 1;
	}

	iMyFile.close();
}

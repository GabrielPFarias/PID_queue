#include <iostream>
#include <string>
#include "util.h"

#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(){
	this->num1 = 0;
	this->num2 = 0;
	this->sign = "";
	this->result = 0;
}

void ComputingProcess::execute() {
	if (sign == "+") {
		result = num1 + num2;
	}
	else if (sign == "-") {
		result = num1 - num2;
	}
	else if (sign == "*" || sign == "x" || sign == "X") {
		result = num1 * num2;
	}
	else if (sign == "/") {
		if (num2 != 0)
			result = num1 / num2;
		else
			cout << "Erro: divisao por zero." << endl;
			return;
	}
	else {
		cout << "Operador invalido: " << sign << endl;
		return;
	}

	cout << "Resultado da expressao: " << result << endl;
}


void ComputingProcess::parse(string equation) {
	equation = removeSpaces(equation);

	size_t opPos = equation.find_first_of("+-*/xX");
	if (opPos == string::npos) {
		cout << "Erro: operador nao encontrado." << endl;
		return;
	}

	num1 = stoi(equation.substr(0, opPos));
	sign = equation.substr(opPos, 1);
	num2 = stoi(equation.substr(opPos + 1));
}
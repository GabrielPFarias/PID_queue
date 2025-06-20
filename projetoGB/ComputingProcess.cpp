#include <iostream>
#include <string>
#include "util.h"

#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(){
	this->num1 = 0;
	this->num2 = 0;
	this->sign = "";
	this->result = 0;
	this->equation = "";
}

void ComputingProcess::execute() {
	parse();
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


void ComputingProcess::parse() {
	equation = removeSpaces(equation);

	size_t opPos = equation.find_first_of("+-*/xX");
	if (opPos == string::npos) {
		cout << "Erro: operador nao encontrado." << endl;
		return;
	}

	num1 = stod(equation.substr(0, opPos));
	sign = equation.substr(opPos, 1);
	num2 = stod(equation.substr(opPos + 1));
}


string ComputingProcess::get_equation() {
	return equation;
}

void ComputingProcess::set_equation(string equation) {
	this->equation = equation;
}

void ComputingProcess::print() {
	cout << "Tipo: " << "ComputingProcess" << "  PID: " << get_PID() << "  Equation: " << get_equation() << endl;
}
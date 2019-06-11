#include "stdafx.h"
#include "Parser.h"
#include <regex>

//Guarda la lista de de digitos y simbolos para verificar que no se metan caracteres invalidos
Parser::Parser()
{
	this->digitos = { "1","2","3","4","5","6","7","8","9","0" };
	this->simbolos = { "(",")","[","]","^","*","/","%","+","-" ,"."};
}

//Revisa si el el primer caracter de este elemento es valido. Se deben permitir digitos, parentesis, corchetes, o signo negativo
bool Parser::checkF(string word) {
	if (word[0] == '(' || word[0] == '[' || word[0] == '-') {
		return true;
	}
	for (int i = 0; i < 10; i++) {
		string digit;
		digit = word[0];
		if (digit == digitos[i]) {
			return true;
		}
	}
	return false;
}

//Revisa si el elemtento es parentesis o corchete. No se necesita al final
bool Parser::checkPC(string word) {
	if (word != "(" || word != "[") {
		return false;
	}
	return true;
}

//Revisa si este elemento es un digito
bool Parser::checkD(string word) {
	string c;
	c = word[0];
	for (int i = 0; i < 10; i++) {
		if (c == digitos[i]) {
			return true;
		}
	}
	return false;
}

//Revisa si este elemento es un simbolo, ya sea parentes, corchete, o un operador
bool Parser::checkS(string word) {
	for (int i = 0; i < 11; i++) {
		if (word == simbolos[i]) {
			return true;
		}
	}
	return false;
}

//Revisa si este elemente es un operador solamente
bool Parser::checkO(string word) {
	for (int i = 4; i < 11; i++) {
		if (word == simbolos[i]) {
			return true;
		}
	}
	return false;
}

//Esta funcion revisa toda la expresion par ver si es valida
bool Parser::checkAll(string word) {
	//Estas variables ayudan a ver si se cierran todos los parentesis y corchetes que se abren
	int brackets = 0;
	int parenthesis = 0;
	//Al final estas variables deben terminar en 0, y en ningun momento pueden tener un valor negativo
	//Se suma cada vez que se abre un parentesis o corchete, y se resta cada vez que se cierra uno
	for (int i = 0; i < word.size(); i++) {
		string s;
		s = word[i];
		bool digit = checkF(s);
		bool sign = checkS(s);
		//Si se encuentra un elemento que no es parte de la lista de digitos o simbolos, se tira un mensaje de error
		if (checkF(s) == false && checkS(s) == false) {
			cout << "Caracter " << word[i] << " es invalido" << endl;
			return false;
		}
		//Validacion de cuando se abre un parentesis
		if (s == "(") {
			//A la izquierda de una apertura de parentesis o chorchete no puede haber un digito
			//Excepto cuando el parentesis o corhcete es el primer elemento de la expresion, por eso se valida que no estemos en la posicion 0
			if (i > 0) {
				//Esta variable es el elemento a la izquierda del parentesis o corchete
				string num;
				num = word[i - 1];
				//Esta variable es el elemento a la derecha del parentesis o corchete
				string num1;
				num1 = word[i + 1];
				//Mira si hay un numero a la izquierda
				if (checkD(num)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
				//Debe haber un numero a la derecha, si no lo hay retorna falso
				if (!checkD(num1)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
			}
			//Se suma la cantidad de parentesis que hay en la expresion
			parenthesis ++;
		}
		//Validacion de cuando se abre un corchete
		if (s == "[") {
			//A la izquierda de una apertura de parentesis o chorchete no puede haber un digito
			//Excepto cuando el parentesis o corhcete es el primer elemento de la expresion, por eso se valida que no estemos en la posicion 0
			if (i > 0) {
				//Esta variable es el elemento a la izquierda del parentesis o corchete
				string num;
				num = word[i - 1];
				//Esta variable es el elemento a la derecha del parentesis o corchete
				string num1;
				num1 = word[i + 1];
				//Mira si hay un numero a la izquierda
				if (checkD(num)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
				//Debe haber un numero a la derecha, si no lo hay retorna falso
				if (!checkD(num1)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
			}
			//Se suma la cantidad de corchetes que hay en la expresion
			brackets ++;
		}
		//Validacion de cuando se cierra un parentesis
		if (s == ")") {
			if (i > 0) {
				//Esta variable es el elemento a la derecha del parentesis o corchete
				string num;
				num = word[i + 1];
				//Debe haber un numero a la derecha, si no lo hay retorna falso
				if (checkD(num)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
			}
			//Se resta la cantidad de parentesis
			parenthesis--;
			//Si en algun momento la cantidad de parentesis es negativo, debe retornar falso
			if (parenthesis < 0) {
				cout << "Parentesis cerrado sin ser abierto" << endl;
				return false;
			}
		}
		//Validacion de cuando se cierra un corchete
		if (s == "]") {
			if (i > 0) {
				//Esta variable es el elemento a la derecha del parentesis o corchete
				string num;
				num = word[i + 1];
				//Debe haber un numero a la derecha, si no lo hay retorna falso
				if (checkD(num)) {
					cout << "Expresion incompleta" << endl;
					return false;
				}
			}
			//Se resta la cantidad de corchetes
			brackets--;
			//Si en algun momento la cantidad de corchetes es negativo, debe retornar falso
			if (parenthesis < 0) {
				cout << "Corchete cerrado sin ser abierto" << endl;
				return false;
			}
		}
		//Aqui se verifican los operadores
		if (i > 0) {
			if (checkO(s)) {
				//Elemento a la izquierda y derecha de el elemento
				string num;
				string num1;
				num = word[i - 1];
				num1 = word[i + 1];
				//Si al menos uno de los dos elemtos al lado del operador no es un digito, verifica si son parentesis o corchetes
				if (checkD(num) == false || checkD(num1) == false) {
					if ((num != ")" || num != "]") || (num1 != "(" || num1 != "[")) {

					}
					//Si no son parentesis ni corchete, debe tirar error
					else {
						cout << "Expresion incompleta" << endl;
						return false;
					}
				}
			}
		}
	}
	//La expresion no puede terminar con ninugun operador, ni con .
	if (word[word.size()-1] == '^' || word[word.size()-1] == '*' || word[word.size()-1] == '/' || word[word.size()-1] == '%' || word[word.size()-1] == '+' || word[word.size()-1] == '-' || word[word.size()-1] == '.') {
		cout << "La expresion no puede terminar con: " << word[word.size() - 1] << endl;
		return false;
	}
	//Verifica que se cerraron todos los corchetes y parentesis
	if (parenthesis != 0 || brackets != 0) {
		cout << "Parentesis o corchetes incompleto!" << endl;
		return false;
	}
	//Retorna verdadero si no entro en ninguna condicion
	return true;
}

//(1+3)^[3(8-3/1)%2]
void Parser::buildPost(vector<string>cmd) {
	result.clear();
	stack.clear();
	for (int i = 0; i < cmd.size(); i++) {
		if (checkD(cmd[i])) {
			this->result.push_back(cmd[i]);
		}
		else if (checkS(cmd[i])) {
			//n
			if (i > 0) {
				if (!stack.empty()) {
					int size = stack.size();
					if (cmd[i] == "+" || cmd[i] == "-") {
						if (stack[size-1] == "+" || stack[size - 1] == "-") {
							this->stack.pop_back();
							this->stack.push_back(cmd[i]);
						}
						if (stack[size - 1] == "*" || stack[size - 1] == "/" || stack[size - 1] == "^" || stack[size - 1] == "%") {
							vector<string> temp;
							int z = size;
							while (stack[z - 1] != "+" || stack[z - 1] != "-") {
								temp.push_back(stack[z - 1]);
								this->stack.pop_back();
								z--;
							}
							this->stack.push_back(cmd[i]);
							int j = temp.size();
							for (int k = j - 1; k >= 0; k++) {
								this->stack.push_back(temp[k]);
								temp.pop_back();
							}
						}
					}
				}
			}
			//n
			this->stack.push_back(cmd[i]);
			if (cmd[i] == "]") {
				int sizec = stack.size() - 1;
				bool endc = false;
				for (int z = sizec; z >= 0; z--) {
					if (stack[z] == "[") {
						endc = true;
					}
					if (stack[z] != "[" && endc == false) {
						if (stack[z] != "]") {
							result.push_back(stack[z]);
						}
						stack.pop_back();
					}
				}
				stack.pop_back();
			}
			if (cmd[i] == ")") {
				int size = stack.size() - 1;
				bool end = false;
				for (int z = size; z >= 0; z--) {
					if (stack[z] == "(") {
						end = true;
					}
					if (stack[z] != "(" && end == false) {
						if (stack[z] != ")") {
							result.push_back(stack[z]);
						}
						stack.pop_back();
					}
				}
				if (stack.empty()) {
					cout << "Pila vacia. se escribio bien la expresion?" << endl;
				}
				else {
					stack.pop_back();
				}
			}
		}
	}
	for (int i = stack.size() - 1; i >= 0; i--) {
		result.push_back(stack[i]);
	}
	for (int z = 0; z < result.size(); z++) {
		cout << "Result: " << result[z] << endl;
	}
}

int Parser::answer(vector<string>res) {
	vector<string> answ;
	if (res.empty()) {
		return NULL;
	}
	else {
		for (int i = 0; i <= res.size() - 1; i++) {
			if (checkD(res[i])) {
				answ.push_back(res[i]);
			}
			if (checkO(res[i])) {
				int size = answ.size()-1;
				float num = atof(answ[size].c_str());
				float num1 = atof(answ[size - 1].c_str());
				if (res[i] == "+") {
					float ans = num + num1;
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
				if (res[i] == "-") {
					float ans = num1 - num;
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
				if (res[i] == "*") {
					float ans = num * num1;
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
				if (res[i] == "/") {
					double ans = num1 / num;
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
				if (res[i] == "^") {
					float og = num1;
					float ans = og;
					for (int j = 0; j < num-1; j++) {
						ans = ans * num1;
					}
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
				if (res[i] == "%") {
					float ans = fmod(num1, num);
					string nans = to_string(ans);
					answ.pop_back();
					answ.pop_back();
					answ.push_back(nans);
				}
			}
		}
	}
	float fres = atof(answ[0].c_str());
	cout << " = " << fres<< endl;
	answ.clear();
	return fres;
}

void Parser::buildCommand(string cmd) {
	string infix = cmd;
	if(checkAll(infix)){
		std::regex words_regex("[0-9]?([0-9]*[.])?[0-9]+|[\\-\\+\\\\\(\\)\\\\[\\]\\/\\^\\%\\*]");
		auto words_begin = std::sregex_iterator(infix.begin(), infix.end(), words_regex);
		auto words_end = std::sregex_iterator();

		for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
			words.push_back((*i).str());
		}
	}
}

void Parser::execute(string cmd) {
	bool invalid = checkF(cmd);
	if (!invalid) {
		cout << "El comando no puede iniciar con: " << cmd[0] << endl;
		words.clear();
	}
	else {
		buildPost(words);
		printWords();
		answer(result);
		words.clear();
	}
}

void Parser::printWords() {
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << " ";
	}
}

void Parser::loop() {
	while (true) {
		string command;
		getline(cin, command);
		this->buildCommand(command);
		this->execute(command);
	}
}

Parser::~Parser()
{
}

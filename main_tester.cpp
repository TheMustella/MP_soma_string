/*
Nome: Jonas Prado Soares
Matricula: 13/0117277
Execução da função soma_string(string string_entrada) sem uso de framework de teste
*/

#include "string_soma.hpp"
#include <iostream>
#include <string>

/*Funcoes do modulo*/

using namespace std;

int main(int argc, char** argv) {

	string line; //linha lida pelo getline
	string entrada_total; //string total formada pela concatenacao de varios getline feitos no arquivo
	string filename;

	while (getline (cin, line)) { //le o arquivo txt de entrada
		//cout << "Foi lida a linha " << line << endl;
		entrada_total += line;
		entrada_total += '\n';
	}
	entrada_total = entrada_total.substr(0, entrada_total.size()-1); //retira o ultimo '\n' inserido

	//cout << "(" << entrada_total << ")\n";
	cout << soma_string(entrada_total) << endl;
	
	return 0;
}
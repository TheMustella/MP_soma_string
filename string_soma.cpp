#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#define NUMBER 1
#define SEPARATOR 2
#define NEWLINE 3

using namespace std;

int soma_string(string string_entrada) {

	string string_operacoes = string_entrada;
	vector<string> separadores; //vetor de separadores
	separadores.push_back(","); //virgula eh o primeiro separador valido

	if (string_operacoes.at(0) == '/' && string_operacoes.at(1) == '/') { //string de entrada comeca com // (especifica delimitador)
		
			unsigned int split = string_operacoes.find('\n')+1; //onde se separam a linha de delimitador e de operacoes
			string delimitadores = string_operacoes.substr(0, split);
			string_operacoes = string_operacoes.substr(split, string_operacoes.length());		

			string separador_atual = delimitadores.substr(delimitadores.find('[')+1, delimitadores.find(']')-3); //apenas o que esta dentro do primeiro []
		do {	
			if (separador_atual.length() < 1) {
				cout << "Delimitador mal formado" << endl;
				return -1; //delimitador mal formado
			}

			separadores.push_back(separador_atual); //insere separador atual no vetor
			delimitadores = delimitadores.substr(delimitadores.find(']')+1, delimitadores.length()); //limpa o primeiro delimitador da string
			separador_atual = delimitadores.substr(delimitadores.find('[')+1, delimitadores.find(']')-1); //apenas o que esta dentro de []
		} while (delimitadores.at(0) == '['); //para cada separador definido

	}

    if (string_operacoes.find("-") != string::npos) { //se houverem numeros negativos
    		cout << "Numeros negativos" << endl;
    		return -1;
    }

    if (string_operacoes.at(0) == ',') { //inicia com virgula
    		cout << "Inicia com virgula" << endl;
    		return -1;
    }

    if (string_operacoes.at(string_operacoes.length()-1) != '\n') { //termina sem '\n'
    	cout << "Termina sem '\n'" << endl;
    	return -1;
    }

    if (!isdigit(string_operacoes.at(string_operacoes.length()-2))) { //o ultimo elemento (penultimo char) nao eh numero
    	cout << "Ultimo elemento nao eh numero" << endl;
    	return -1;
    }

    vector <int> operandos;
    int lastChar = 0; //flag para identificar ultimo caracter; 1 para numero; 2 para virgula; 3 para \n
    int numeroAtual = 0; //operador atual
    int elementosLinha = 0;
    string separador_lido;

	for (unsigned i = 0; i < (string_operacoes.length()); i++) { //testa cada caracter
		char charAtual = string_operacoes[i];

		if (isdigit(charAtual)) { // eh numero
			if (lastChar == NUMBER) { //eh continuacao do numero anterior
				numeroAtual *= 10;
				numeroAtual += charAtual - '0';
				//cout << "MUDOU 1" << endl;
			}
			else { //eh primeiro caracter do numero
				numeroAtual = charAtual - '0';
				//cout << "MUDOU 2 " << numeroAtual << endl;
				lastChar = NUMBER;
			}
		} else {
		if (charAtual == '\n') { //nova linha
			char charAnterior = string_operacoes[i-1];
			
			if (numeroAtual < 1001 && lastChar == NUMBER) { //se o caracter anterior era um numero (ignorar numero maiores que 1000 e sequencias de \n)
				operandos.push_back(numeroAtual); //inserir operador na lista de operandos
				elementosLinha++; //ultimo elemento da linha}
			}
			lastChar = NEWLINE;
			int numeroAtual = 0; //zera o numeroAtual para proxima iteracao

			if (elementosLinha > 3) { //so sao permitidos 3 elmentos por linha
				cout << "3 ou mais elementos numa linha" << endl;
				return -1; 
			}
			else { //a linha eh valida; iniciar a proxima
				elementosLinha = 0; //zera o numero de elementos da nova linha
			}
		}
		else {
			char proxChar = string_operacoes[i+1];
			separador_lido += charAtual;
			while (!(isdigit(proxChar) || proxChar == '\n')) { //ate que charAtual termine de percorrer o separador { //inicio de separador encontrado; avancar ate finalizar o separador
				i++; //avancar no vetor de caracteres
				charAtual = string_operacoes[i]; //atualizar charAtual
				proxChar = string_operacoes[i+1];
				separador_lido += charAtual;
			}

			if (lastChar == NUMBER) { //separador apos numero
				if (find(separadores.begin(), separadores.end(), separador_lido) == separadores.end()) { //separador nao esta listado
					cout << "Separador nao listado" << endl;
					return -1;
				}
				else { //separacao entre numeros
					if (numeroAtual < 1001) { //ignorar numero maiores que 1000
						operandos.push_back(numeroAtual); //inserir operador na lista de operandos
						elementosLinha++; //ultimo elemento da linha}
					}
					lastChar = SEPARATOR;
					separador_lido.clear(); //limpar string de separador lido
					numeroAtual = 0; //zera o numeroAtual para proxima iteracao
				}
			}
		}
		}
	}

	//LEITURA DE CARACTERES FINALIZADA; FAZER A CONTA

	int resultadoSoma = 0;
	while (!operandos.empty()) { //enquanto houver elementos no vetor
    	resultadoSoma += operandos.back(); //somar o ultimo elemento
    	operandos.pop_back(); //retirar o ultimo elemento
	}

	return resultadoSoma;
}
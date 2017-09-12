#include <vector>
#include <iostream>
#include <string>

using namespace std;

int soma_string(string string_entrada) {

    if (!string_entrada.find('-')) { //se houverem numeros negativos
    		return -1;
    }

    if (string_entrada.at(0) == ',') { //inicia com virgula
    		return -1;
    }

    if (string_entrada.at(string_entrada.length()-1) != '\n') { //termina sem '\n'
    	return -1;
    }

    if (!isdigit(string_entrada.at(string_entrada.length()-2))) { //o ultimo elemento (penultimo char) nao eh numero
    	return -1;
    }

    vector <int> operandos;
    vector <string> separadores;
    separadores.push_back (","); //virgula eh um separador valido
    int lastChar = 0; //flag para identificar ultimo caracter; 1 para numero; 2 para virgula; 3 para \n
    int numeroAtual = 0; //operador atual
    int elementosLinha = 0;

	for (unsigned i = 0; i < (string_entrada.length()); i++) { //testa cada caracter
		char charAtual = string_entrada[i];

		//cout << "OPERANDO COM " << charAtual << endl;

		if (!isdigit(charAtual) && charAtual != ',' && charAtual != '\n') { //nao eh numero, virgula ou \n: invalido
			return -1;
		}

		if (isdigit(charAtual)) { // eh numero
			if (lastChar == 1) { //eh continuacao do numero anterior
				numeroAtual *= 10;
				numeroAtual += charAtual - '0';
				//cout << "MUDOU 1" << endl;
			}
			else { //eh primeiro caracter do numero
				numeroAtual = charAtual - '0';
				//cout << "MUDOU 2 " << numeroAtual << endl;
				lastChar = 1;
			}
		}
		if (charAtual == ',') { //eh virgula
			
			if (lastChar == 2) { //duas virgulas seguidas
				return -1;
			}

			if (lastChar != 3) { //virgula apos numero (para nao fazer push com virgulas apos \n)
				if (numeroAtual < 1001) { //ignorar numero maiores que 1000
					operandos.push_back(numeroAtual); //inserir operador na lista de operandos
					elementosLinha++; //ultimo elemento da linha}
				}
				lastChar = 2;
				int numeroAtual = 0; //zera o numeroAtual para proxima iteracao
			}
		}
		if (charAtual == '\n') { //nova linha
			
			if (numeroAtual < 1001) { //ignorar numero maiores que 1000
				operandos.push_back(numeroAtual); //inserir operador na lista de operandos
				elementosLinha++; //ultimo elemento da linha}
			}
			lastChar = 3;
			int numeroAtual = 0; //zera o numeroAtual para proxima iteracao

			if (elementosLinha > 3) { //so sao permitidos 3 elmentos por linha
				return -1; 
			}
			else { //a linha eh valida; iniciar a proxima
				elementosLinha = 0; //zera o numero de elementos da nova linha
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
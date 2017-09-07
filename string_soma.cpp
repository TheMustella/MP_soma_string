#include <vector>
#include <iostream>
#include <string>

using namespace std;

int soma_string(string string_entrada) {

	if (string_entrada.find(",,")) { //se houverem virgulas seguidas
    		return -1;
    }

    if (string_entrada.find('-')) { //se houverem numeros negativos
    		return -1;
    }

    if (string_entrada.at(0) == ',') { //inicia com virgula
    		return -1;
    }

    if (string_entrada.at(string_entrada.length()-1) != '\n') { //termina sem '\n'
    	return -1;
    }

	/*for (unsigned i = 0; i < (string_entrada.length()); i++) {

	}*/

	return 0;
}
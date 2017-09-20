CC = g++
CFLAGS = -g -O0 --coverage

all: clean soma tester #EXECUTAR ESSES COMANDOS ANTES DA LINHA ABAIXO
	$(CC) $(CFLAGS) string_soma.o main_tester.o -o testa_soma_string_stdin

soma: string_soma.cpp #ARQUIVOS DE ENTRADA
	$(CC) -c $(CFLAGS) string_soma.cpp

tester: main_tester.cpp #ARQUIVOS DE ENTRADA
	$(CC) -c $(CFLAGS) main_tester.cpp

clean:
	find . -name '*.o' -exec rm '{}' \;
	find . -name 'testa_soma_string_stdin' -exec rm '{}' \;
	find . -name '*.gcno' -exec rm '{}' \;
	find . -name '*.gcda' -exec rm '{}' \;

GTEST1:
	rm -f -r build
	mkdir build #CRIAR DIRETORIO PARA RECEBER ARQUIVOS DO MAKE

GTEST2: # EXECUTAR APOS DAR COMANDO 'cd build'
	# cmake ../  #REALIZA O MAKE DA BIBLIOTECA
	# make       #GERA O EXECUTAVEL
	# ./runTests #RODA O TESTES

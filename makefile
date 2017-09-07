all: clean soma tester #EXECUTAR ESSES COMANDOS ANTES DA LINHA ABAIXO
	g++ string_soma.o main_tester.o -o run

soma: string_soma.cpp #ARQUIVOS DE ENTRADA
	g++ -c string_soma.cpp

tester: main_tester.cpp #ARQUIVOS DE ENTRADA
	g++ -c main_tester.cpp

clean:
	find . -name '*.o' -exec rm '{}' \;
	find . -name 'run' -exec rm '{}' \;

GTEST:
	rm -f -r build
	mkdir build #CRIAR DIRETORIO PARA RECEBER ARQUIVOS DO MAKE
	cd build
	cmake ../  #REALIZA O MAKE DA BIBLIOTECA
	make       #GERA O EXECUTAVEL
	./runTests #RODA O TESTES

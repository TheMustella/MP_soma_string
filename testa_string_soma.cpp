// <arquivos testados>.cpp
#include "string_soma.cpp"
#include <gtest/gtest.h> //VERIFICAR
 
TEST(SomaStringTest, DoisElementos) { 
    ASSERT_EQ(3, soma_string("1,2\n"));
}

TEST(SomaStringTest, TresElementos) { 
    ASSERT_EQ(6, soma_string("3,2,1\n"));
}

TEST(SomaStringTest, VirgulaNoFim) { 
    ASSERT_EQ(-1, soma_string("1,\n"));
}

TEST(SomaStringTest, VirgulaNoInicio) { 
    ASSERT_EQ(-1, soma_string(",2\n"));
}

TEST(SomaStringTest, VirgulasSeguidas) { 
    ASSERT_EQ(-1, soma_string("1,,2\n"));
}

TEST(SomaStringTest, VirgulaSozinha) { 
    ASSERT_EQ(-1, soma_string(",\n"));
}

TEST(SomaStringTest, SeparadorErrado) { 
    ASSERT_EQ(-1, soma_string("1;2\n"));
}

TEST(SomaStringTest, SemContrabarraN) { 
    ASSERT_EQ(-1, soma_string("1,2"));
}

TEST(SomaStringTest, EspacoNoFinal) { 
    ASSERT_EQ(-1, soma_string("1,2 \n"));
}

TEST(SomaStringTest, IgnoradoEntreNumeros) { 
    ASSERT_EQ(3, soma_string("1\n,2\n")); //valido pois o \n eh ignorado se estiver entre números
}

TEST(SomaStringTest, IgnoradoEntreNumeros2) { 
    ASSERT_EQ(5, soma_string("1\n\n\n,4\n")); //valido pois o \n eh ignorado se estiver entre números
}

TEST(SomaStringTest, IgnoradoEntreNumeros3) { 
    ASSERT_EQ(4, soma_string("1\n\n\n,\n\n\n3\n")); //valido pois o \n eh ignorado se estiver entre números
}

TEST(SomaStringTest, EstouraLimite) { 
    ASSERT_EQ(-1, soma_string("1,2,3,4\n")); //Apenas 3 numeros por linha
}
TEST(SomaStringTest, LimiteNumerosPorLinha) { 
    ASSERT_EQ(10, soma_string("1,2,3\n,4\n"));
}
TEST(SomaStringTest, Negativos) { 
    ASSERT_EQ(-1, soma_string("-1,2\n")); //Numero negativo
}
TEST(SomaStringTest, Negativos2) { 
    ASSERT_EQ(-1, soma_string("2,-1\n"));
}
TEST(SomaStringTest, IgnorarMaiorQue1000) { 
    ASSERT_EQ(3, soma_string("3,2000\n"));
}
TEST(SomaStringTest, IgnorarMaiorQue1001) { 
    ASSERT_EQ(3, soma_string("2000,3\n"));
}
TEST(SomaStringTest, NovoSeparador) { 
    ASSERT_EQ(5, soma_string("//[;]\n2;3\n")); //A entrada //;\n2;3\n faz com que ; seja um separador valido e o resultado seja 5
}

TEST(SomaStringTest, NovoSeparadorComposto) { 
    ASSERT_EQ(5, soma_string("//[;@;]\n2;@;3\n")); //Um delimitador pode ter qualquer tamanho; //[***]\n2***3***4\n retorna 9
}

TEST(SomaStringTest, DoisSeparadoresComposto) { 
    ASSERT_EQ(9, soma_string("//[;@;][%%%]\n2;@;3%%%4\n")); //Podem haver multiplos delimitadores nessa descricao
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
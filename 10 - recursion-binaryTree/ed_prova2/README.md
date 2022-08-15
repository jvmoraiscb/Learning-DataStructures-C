Prova feita por João Victor Morais

Guia de utilização do programa:
    Por padrão, o programa abre o arquivo chamado "entrada.txt"(na mesma pasta do "makefile"), mas isso pode ser facilmente modificado no arquivo "main.c"
    - "make"          -> compila todos os arquivos e cria um executável dentro da pasta "bin"
    - "make clean"    -> apaga todas os arquivos temporários ("bin/", "obj/" e saida.txt)
    - "make run"      -> roda o executável ("./bin/final.exe") e constrói o arquivo "saida.txt"
    - "make valgrind" -> roda o executável com valgrind ("valgrind ./bin/final.exe") e constrói o arquivo "saida.txt"
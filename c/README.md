<!-- trash -->
# Calculadora em C
Esse projeto é a revitalização de um antigo trabalho
de Estrutura de Dados para o qual era necessário implementar uma calculadora em C
~~porque quem é programador de verdade programa em C~~. A calculadora executa algumas
operações básicas utilizando listas lincadas, pilhas e conversão entre as formas infixa
e pós-fixa.


## O que ela faz?
Aceita algumas expressões simples entradas pelo usuário e apresenta o resultado no terminal:

![gif da calculadora](/c/.github/calculator.gif)


## Dependendências
* git
* gcc
* g++
* [CMake](https://cmake.org/)
* make


## Como usar

##### Baixe o repositório
Abra o terminal e digite:

```
$ git clone https://github.com/y-azvd/calculator.git
```

Ou clique no botão verde no diretório raíz desse repositório.

##### Depois de ter baixado
```
$ cd calculator/C
$ mkdir build
$ cd build/
$ cmake ..
$ make
```

É normal demorar um pouco pra compilar porque os testes são realizados utilizando
o framework [Catch2](https://github.com/catchorg/Catch2). Mas é só na primeira vez.


##### Executar
```
$ ./calculator
```


## A fazer
1. Incluir algumas funções (sin, cos, log).
2. Continuar o testador da `main.c`. Duas formas:
* dois programas rodando em paralelo: `$ ./test_main | ./calculator`
* `input1.txt` com as entradas de comandos e expressões: `./test_main`, que, por sua vez executaria os seguintes comandos no `TEST_CASES`:
  * `system("./test_main < input1.txt");`
  * `system("./test_main < input2.txt");`
Mas então como conferir o resultado?
3. Descobrir um jeito melhor de encapsular (e deixar mais legível) as funções de receber input e diferenciar os comandos.

<!-- trash -->
# 🔢 Calculadora em C
Esse projeto é a revitalização de um antigo trabalho
de Estrutura de Dados para o qual era necessário implementar uma calculadora em C
~~porque quem é programador de verdade programa em C~~. A calculadora executa algumas
operações básicas utilizando listas lincadas, pilhas e conversão entre as formas infixa
e pós-fixa.

Esse projeto faz parte de um "projeto maior" de [calculadoras](https://github.com/yudi-azvd/calculator).

<!-- Esse projeto faz parte do projeto Calculadora(link pro repositório principal) -->


## O que ela faz?
Aceita algumas expressões simples entradas pelo usuário e apresenta o resultado no terminal:

![gif da calculadora](/.github/calculator.gif)


## Dependências
* git
* gcc
* g++
* [CMake](https://cmake.org/)
* make


## Como usar
Para baixar o repositório, abra o terminal e digite:

```
$ git clone https://github.com/y-azvd/c-calculator.git
```

Ou clique no botão verde no diretório raíz desse repositório.

Depois de ter baixado execute no terminal:
```
$ cd c-calculator/build/
$ cmake ..
$ make
```

É normal demorar um pouco pra compilar porque os testes são realizados utilizando
o framework [Catch2](https://github.com/catchorg/Catch2). Mas é só na primeira vez.


Para executar: 
```
$ ./calculator
```

## Documentação

Para saber mais sobre a calculadora, cheque a [documentação](./docs/README.md).

## Extensões úteis para VSCode

- C/C++
- CMake
- CMake Tools
- C++ TestMate


## A fazer
1. Incluir algumas funções (sin, cos, log).
2. Continuar o testador da `main.c`. Duas formas:
* dois programas rodando em paralelo: `$ ./test_main | ./calculator`
* `input1.txt` com as entradas de comandos e expressões: `./test_main`, que, por sua vez executaria os seguintes comandos no `TEST_CASES`:
  * `system("./test_main < input1.txt");`
  * `system("./test_main < input2.txt");`
Mas então como conferir o resultado? Dar uma olhada no trabalho de [EDA2](https://github.com/yudi-azvd/EDA2-Trabalho-2) na parte da interação entre o programa do joagdor e do árbitro.

3. Descobrir um jeito melhor de encapsular (e deixar mais legível) as funções de receber input e diferenciar os comandos.

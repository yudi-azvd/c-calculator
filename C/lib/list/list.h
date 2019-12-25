
/**
 * @file 		list.h
 *
 * @author     	Yudi Yamane de Azevedo
 *
 * @date        18 de julho de 2019
 *
 * @brief      	Definição do tipo t_list e suas funções.
 *
 *
 * É uma pequena lista de operações em listas simplemente lincadas.
 * Inspirada em https://github.com/DevonCrawford/Video-Editing-Automation/blob/master/include/LinkedListAPI.h
 */


#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @brief      Nó com ponteiro para dado genérico e com ponteiro
 * para o próximo nó.
 */
typedef struct t_node {
    void* data;				/**< Ponteiro genérico para um tipo de dado. */
    struct t_node* next;	/**< Ponteiro para o próximo nó. */
} t_node;


/**
 * @memberof   t_list
 *
 * @brief      Cria um nó dinamicamente. Normalmente, essa função
 * não é chamada diretamente. É chamada por funções como insert_head()
 * e push(). Pode ser considerada uma função privada.
 *
 *
 * @note       Só é preciso se preocupar com vazamento memória se
 * ela for chamada diretamente.
 *
 * @param      data  Ponteiro genérico para um tipo de dado.
 *
 * @return     Ponteiro para o espaço alocado.
 */
t_node* create_node(void* data);


/**
 * @brief      Lista simplesmente lincada. Está longe de ser uma biblioteca adequada
 * para essa estrutura de dados.
 *
 * Foi implementado apenas o suficiente para implementar a
 * <a href="https://github.com/y-azvd/calculator/tree/master/C">calculadora em C</a>
 *
 * Na documentação, as funções para lista estão na seção "Membros públicos". Apesar de C não ser
 * uma linguagem que tem suporte para orienteção objeto, as funções foram indicadas com
 * \"<tt>\@memberof t_list</tt>\" para juntar a definição da estrutura de dados t_list e suas
 * funções na mesma página, além de dar a ideia de uma classe e seus métodos.
 *
 * @warning    Cabe ressaltar ao usuário que a lista implementada "não sabe" se o espaço
 * de memória apontado @c node->data foi alocado dinamicamente ou não. Essa resposabilidade
 * é deixada ao usuário (até porque não sei outra maneira de fazer isso). Esse aviso é
 * ressaltado ao longo da documentação em algumas funções (remove_head(), delete_head(),
 * soft_pop()).
 * Resumidamente, essa biblioteca libera a memória apontada pelo nó, mas a memória
 * apontada por <tt>void* data</tt> (em t_node) deve ser analisada em cada caso, dependendo
 * da aplicação do usuário, que deve escolher qual função é mais apropriada.
 *
 * Essa lista foi testada usando <a href="http://www.valgrind.org/">valgrind</a> e a framework
 * <a href="https://github.com/catchorg/Catch2#whats-the-catch">Catch2</a>. Alguns trechos dos
 * arquivos testes são usados como exemplo, por isso algumas macros do Catch2 estão presentes.
 * Se você não tem familiriadade, cheque a parte
 * <a href="https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#test-cases-and-sections">
 * Testes e Seções</a>.
 *
 * @see
 * Inspirada na lista implemetada em
 * <a href="https://github.com/DevonCrawford/Video-Editing-Automation/blob/master/include/LinkedListAPI.h">
 * link</a>.
 */
typedef struct t_list {
    t_node* head;	/**< Ponteiro para o primeiro item. */
    t_node* tail;	/**< Ponteiro para o último item. */

    int length;		/**< Comprimento da lista. */

    void (*print)(struct t_list* list);	/** Ponteiro para função de imprimir */

} t_list;


/**
 * @memberof   t_list
 *
 * @brief      Cria dinamicamente uma lista.
 *
 * Além disso, associa as funções print() - e, futuramente, compare() -
 * as suas funções com os seus devidos tipos. Por enquanto tem suporte
 * para @c int e @c char* .
 *
 * @note       Para novos tipos de dados, o usuário deve criar a sua própria
 * versão de create_list() e definir, a seu gosto, como associar as funções
 * print() e compare().
 *
 * @warning    Quem chama essa função deve liberar o espaço depois de usá-lo.
 *
 * @param[in]  data_type  O tipo de dado.
 * @pre        @c "int", @c "char" @c "double" ou @c "char*"
 *
 * @return     Ponteiro para a lista criada dinamicamente.
 */
t_list* create_list(const char* data_type);


/**
 * @memberof   t_list
 * @brief      Retorna o dado apontado pelo primeiro item da lista.
 * Retorna @c NULL se a lista estiver vazia.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 *
 * @return     Ponteiro para dado. Retorna @c NULL se a lista
 * estiver vazia.
 */
void* get_head(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Retorna o dado apontado pelo último item da lista.
 * Retorna @c NULL se a lista estiver vazia.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 *
 * @return     Ponteiro para dado.
 */
void* get_tail(t_list* list);


/**
* @memberof   t_list
*
* @brief      Retorna ponteiro para o nó no índice index.
* @c get_data_at talvez seja um nome melhor
*
* @param      list  Ponteiro <b>não nulo</b> para lista.
*
* @return     Ponteiro para dado.
*/
void* get_at_index(t_list* list, int index);


/**
 * @memberof   t_list
 *
 * @brief      Checa se a lista está vazia. É o caso de uma lista
 * que acabou de ser criada.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 *
 * @return     1 se está vazio, 0 caso contrário.
 */
int is_empty(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Para fins de depuração, imprime a lista na tela.
 * Só deve ser usada quando foi definida o tipo de dados da lista.
 *
 * @param      list  Ponteiro para lista.
 */
void print(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Não tá pronta. Não Preciso por agora.
 */
void compare();


/**
 * @memberof   t_list
 *
 * @brief      Insere um item no começo da lista.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 * @param      data  Ponteiro <b>não nulo</b> para dado.
 */
void insert_head(t_list* list, void* data);


/**
 * @memberof   t_list
 *
 * @brief      Insere um item no final da lista.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 * @param      data  Ponteiro <b>não nulo</b> para dado.
 */
void insert_tail(t_list* list, void* data);


/**
 * @memberof   t_list
 *
 * @brief      Remove o primeiro nó da lista e retorna seu dado e libera
 * a memória apontada pelo nó.
 *
 * @warning Quem chama essa função dever ser o reponsável por liberar
 * memória apontada por data.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 *
 * @return     O ponteiro para o primeiro dado da lista.
 *
 * Em constraste, ver delete_head().
 */
void* remove_head(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Remove o primeiro nó da lista e libera o espaço de
 * memória apontado por @c data desse nó.
 *
 * @note       Deve ser usado _apenas_ em listas cujos dados foram
 * alocado dinamicamente.
 *
 * @param      list  Ponteiro <b>não nulo</b> para lista.
 *
 * @snippet    ./TEST_LIST.cpp
 *
 */
void delete_head(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Limpa a lista cujos ponteiros para dado
 * <b>apontam</b> para espaços alocados dinamicamente.
 *
 * Exemplo:
 * @snippet    ./TEST_LIST.cpp clear_1
 *
 * @param      list  Ponteiro para lista.
 */
void clear(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Limpa a lista cujos ponteiros para dado
 * <b>não</b> apontam para espaços alocados dinamicamente.
 *
 * Nos exemplos abaixo não há chamada de funções como @c malloc()
 * ou @c calloc() para alocar memória para os dados a serem armazenados
 * na lista.
 * @snippet    ./TEST_LIST.cpp soft_clear_1
 * @snippet    ./TEST_LIST.cpp soft_clear_2
 *
 * Em contraste, ver clear().
 *
 * @param      list  Ponteiro para lista.
 */
void soft_clear(t_list* list);


/*## funções tipadas para listas ##*/

/**
 * @memberof   t_list
 *
 * @brief      Para fins de depuração, é chamada por print() para
 * listas com tipo de dados @c int. Pode  ser considerada uma função
 * privada.
 *
 * @note        Não precisa ser chamada diretamente.
 *
 * @param      list  Ponteiro para lista.
 */
void print_int_list(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Para fins de depuração, é chamada por print() para listas com tipo
 * de dados @c char. Pode  ser considerada uma função privada.
 *
 * @note        Não precisa ser chamada diretamente.
 *
 * @param      list  Ponteiro para lista.
 */
void print_char_list(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Para fins de depuração, é chamada por print() para listas com tipo
 * de dados @c double. Pode  ser considerada uma função privada.
 *
 * @note        Não precisa ser chamada diretamente.
 *
 * @param      list  Ponteiro para lista.
 */
void print_double_list(t_list* list);


/**
 * @memberof   t_list
 *
 * @brief      Para fins de depuração, é chamada por print() para listas com tipo
 * de dados @c char* (ou \"<tt>string</tt>\"). Pode ser considerada uma função
 * privada.
 *
 * @note 	   Não precisa ser chamada diretamente.
 *
 * @param      list  Ponteiro para lista.
 */
void print_str_list(t_list* list);


/**********************/
/* Funções para Pilha */
/**********************/
/**
 * @memberof   t_list
 *
 * @brief Definição de t_stack. Tem compatibilidade com
 * t_list.
 *
 * Honestamente, fiquei com preguiça de colocar esse tipo e suas funções em outro
 * arquivo. São muito poucas. Talvez no futuro eu separe em um arquivo diferente.
 */
typedef t_list t_stack;

t_stack* create_stack(const char* data_type);


/**
 * @memberof   t_list
 *
 * @brief      Adiciona um nó ao topo da pilha.
 *
 * @param      stack 	Ponteiro <b>não nulo</b> para pilha.
 * @param      data   	Ponteiro <b>não nulo</b> para o dado.
 */
void push(t_stack* stack, void* data);


/**
 * @memberof   t_list
 *
 * @brief      Remove da pilha o nó no topo da pilha e libera o espaço
 * de memória apontado pelo dado do nó.
 *
 * @note       Deve ser usado _apenas_ em pilhas cujos dados  foram
 * alocados dinamicamente. Semelhante a remove_head().
 *
 * @param      stack Ponteiro para pilha.
 */
void pop(t_stack* stack);


/**
 * @memberof   t_list
 *
 * @brief      Remove o nó do topo da pilha
 *
 * @warning    Quem chama essa função dever ser o reponsável por
 * liberar memória apontada por data.
 *
 * @param      stack Ponteiro para pilha.
 *
 * @return     Ponteiro para o dado do nó que estava no topo da
 * pilha. Retorna @c NULL se a pilha está vazia.
 */
void* soft_pop(t_stack* stack);


/**
 * @memberof   t_list
 *
 * @brief      Retorna o ponteiro para o dado do nó
 * no topo da pilha.
 *
 * @warning    Se o espaço apontado pelo ponteiro foi alocado
 * dinamicamente, quem chamou essa função é responsável por
 * liberá-lo.
 *
 * @param      stack  Ponteiro para pilha.
 *
 * @return     Ponteiro para o dado do nó
 * no topo da pilha.
 */
void* peek(t_stack* stack);


#endif

/**
* Fase 2: Padrão "Two Pointers" (Dois Ponteiros)
* Conceito: Manipular índices para reduzir a complexidade de tempo sem aumentar o uso de memória
 (Space Complexity O(1)).
* Estrutura C++: while, índices left e right.
* 
* Desafio 2: Inverter String In-Place
* Inverta uma string sem criar uma nova string auxiliar.
* 
* Lógica: Um ponteiro no início, outro no fim. Troca os valores e move os ponteiros para o 
* centro até se encontrarem.
* 
* Complexidade: Tempo O(N/2) -> O(N). Espaço O(1) (apenas variáveis auxiliares).
 */

#include <string>
#include <algorithm>

void reverterString(std::string& s){
    int left = 0;
    int right = s.length() - 1; // valor é 4

    while (left < right){
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}

/**
 * Lição C++: Passar por referência (string& s) é crucial. Se fosse passar por valor (string s), o
 * C++ copiará a string inteira (O(N)), desperdiçando mem;ória e tempo antes mesmo da função
 * começar.
 * 
 */
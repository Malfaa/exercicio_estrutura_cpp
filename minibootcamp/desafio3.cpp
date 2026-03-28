/**
 * Fase 3: A Mágica do Logaritmo (Binary Search)Conceito: Se os dados estão ordenados, 
 * nunca verifique um por um.Complexidade: $O(\log N)$. 
 * Isso é muito rápido. Para 1 milhão de elementos, $O(N)$ 
 * faz 1 milhão de operações. $O(\log N)$ faz apenas ~20.
 * 
 * Desafio 3: Busca Binária Manual
 * Não use std::binary_search ainda. 
 * Implemente a lógica para achar um número num vetor ordenado.
 * 
 * Lógica:
 * Pegue o meio.
 * É o número? 
 * Achou.
 * É maior? 
 * Jogue a metade esquerda fora.
 * É menor? 
 * Jogue a metade direita fora.
 * 
 */

 #include <vector>
 #include <string>
 #include <iostream>

 /**
  * Meu
  * 
  * @param array 
  * @param valor 
  */
 void buscaBinaria(const std::vector<int>& array, size_t valor) {
    size_t inicio = 0;
    size_t final = array.size() - 1; //PODE QUEBRAR, POR SER VALOR NEGATIVO, O size_t PODE VIRAR INFINITO
    size_t contador = 0;

    while (inicio < final) {
        size_t meio = (inicio + final) / 2;

        if(array[meio] == valor){
            std::cout << "Achou";
            break;
        }else if (array[meio] > valor){
            final = meio - 1;
            contador++;
        }else{
            inicio = meio + 1;
            contador++;
        }
        
    }   
    std::cout << "Foram necessário: " << contador << " passos." << std::endl;
 }


/**
* Gemini ======== Bem melhor ========
* 
* @param array 
* @param valor 
*/

#include <optional> // C++17: A forma profissional de dizer "pode não retornar nada"

// Retorna optional: ou tem o índice (size_t), ou é nullopt (vazio)
// Nada de retornar -1 mágico!
std::optional<size_t> binarySearchPro(const std::vector<int>& nums, int target) {
    size_t left = 0;
    size_t right = nums.size(); // Note: Não tem o -1. Aponta para "fora" do vetor.

    // Loop enquanto o intervalo não estiver vazio
    while (left < right) { 
        // Lógica segura contra overflow na soma
        size_t mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[mid] < target) {
            left = mid + 1; // Parte esquerda já foi testada
        } else {
            right = mid;    // O PULO DO GATO: Não subtraímos 1.
                            // O novo intervalo termina em mid (exclusivo).
                            // Como mid não é target, ele vira o novo limite "fora".
        }
    }

    return std::nullopt; // Não encontrou
}

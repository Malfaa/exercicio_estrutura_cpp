/**
 * Desafio 1: A Soma Cumulativa (Prefix Sum)
 * 
 * Dado um vetor de números, crie um novo vetor onde cada posição 'i' seja a soma de todos os números 
 * de '0' até 'i'
 * 
 *  - Abordagem Ingênua (O(N^2)): Para cada posição 'i', fazer um loop interno somando tudo de
 *    novo do zero.
 *  - Lógica Otimizada (O(N)): A soma atual é igual à soma anterior + o número atual. Não precisa
 *    recalcular tudo.
 * 
 */

#include <vector>
#include <iostream>

/* ================================== CÓDIGO INGÊNUO ================================== */
/**
 * Abordagem Ingênua ($O(N^2)$): Para cada posição i, fazer um loop interno somando tudo de novo do zero.
 */
std::vector<int> prefixSum(const std::vector<int>& nums){

    std::vector<int> result; // ele é armazendo na heap
    
    if (nums.empty()) return result;

    // Este é o primeiro loop 
    for (size_t i = 1; i < nums.size(); ++i){ // 0..4 = 5 elementos
        int current_sum = 0;

        for (size_t j = 0; i <= i; ++j){ // 0 
            current_sum += nums[j];
        }

        result.push_back(current_sum);
    }
    return result;
}

/* ================================== CÓDIGO OTIMIZADO ================================== */
/**
 * Lógica Otimizada ($O(N)$): A soma atual é igual à soma anterior + o número atual. 
 * Não precisa recalcular tudo.
 */

std::vector<int> prefixSum(const std::vector<int>& nums) {
    std::vector<int> result;
    if (nums.empty()) return result;

    result.push_back(nums[0]);
    // Loop único: O(N)
    for (size_t i = 1; i < nums.size(); ++i) {
        result.push_back(result[i-1] + nums[i]);
    }
    return result;
}

/* Lição de complexidade: Evite loops aninhados (um `for` dentro de outro) sempre que possível. Em
C++, usar push_back pode ter custo oculto de realocação, mas é amortizado O(1)*/
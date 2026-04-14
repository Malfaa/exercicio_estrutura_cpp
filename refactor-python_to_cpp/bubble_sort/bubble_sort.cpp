// ordena comparando atual com o próximom, se o atual for maior que o próximo,
// eles trocam
#include <algorithm>
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  bool trocou;

  for (int i = 0; i < n - 1; i++) {
    trocou = false;

    // n - i - 1 evita comparar elementos que já estão ordenados no final
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // troca elementos de lugar
        std::swap(arr[j], arr[j + 1]);
        trocou = true;
      }
    }

    // Se não houve troca, o vator já está ordenado
    if (!trocou)
      break;
  }
}

void printVector(std::vector<int> &arr) {
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {

  std::vector<int> arr = {0, 5, 6, 4, 2, 3, 9, 8, 7};

  printVector(arr);

  bubbleSort(arr);

  printVector(arr);

  return 0;
}

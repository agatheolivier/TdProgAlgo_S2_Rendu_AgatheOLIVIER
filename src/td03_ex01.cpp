#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

/*************************************************** Trie par sélection *****************************************************/
void selection_sort(std::vector<int> & vec){
    for (size_t i = 0; i < vec.size(); i++){
        int minimumIndex = i;
        for (size_t j = i+1; j < vec.size(); j++){
            if (vec[j] < vec[minimumIndex]) {
                minimumIndex = j;
            }
        }
        int pivot = vec[i];
        vec[i] = vec[minimumIndex];
        vec[minimumIndex] = pivot;
    }
}

int main() {
    std::vector<int> tableau {6, 2, 8, 1, 5, 3, 9};
    selection_sort(tableau);

    //Affichage du tableau pour débug
    for (size_t i = 0; i < tableau.size(); i++){
        std::cout << tableau[i] << ", " <<  std::endl;
    }

    if (is_sorted(tableau)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

/*************************************************** Trie par fusion *****************************************************/
//Fusionne
void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){
    size_t i = left;
    size_t j = middle;
    std::vector<int> trie(vec.size());

    for (size_t k = left; k < right; k++){
        if (i < middle && j < right){
            if (vec[i] < vec[j]) {
                trie[k] = vec[i];
                i++;
            }
            else {
                trie[k] = vec[j];
                j++;
            }
        }
        else if (i == middle) {
            trie[k] = vec[j];
            j++;
        }
        else if (j == right) {
            trie[k] = vec[i];
            i++;
        }
    }

    for (size_t k = left; k < right; k++) {
        vec[k] = trie[k];
    }
}

//Sépare le vect en 2 et trie
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (right - left <= 1) {
        return;
    }
    size_t middleIndex = left + (right - left) / 2;
    merge_sort(vec, left, middleIndex);
    merge_sort(vec, middleIndex , right);
    merge_sort_merge(vec, left, middleIndex, right);
}

//Appel de la fonction
void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size());
}

int main() {
    std::vector<int> tableau {6, 2, 8, 1, 5, 3, 9};
    merge_sort(tableau);

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
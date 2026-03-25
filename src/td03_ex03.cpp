#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

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

/*************************************************** Trie par fusion *****************************************************/
//Fusionne
void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right){
    size_t i = left;
    size_t j = middle;
    std::vector<int> trie;

    for (size_t k = left; k < vec.size(); k++){
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
        }
        else if (j == right) {
            trie[k] = vec[i];
        }
    }

    vec = trie;
}

//Sépare le vect en 2 et trie
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (vec.size() > 1) {
        size_t middleIndex = (right / 2);
        merge_sort(vec, left, middleIndex-1);
        merge_sort(vec, middleIndex , right-1);
        merge_sort_merge(vec, left, middleIndex, right);
    }
};

//Appel de la fonction
void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

/********************************************* Générer tableau ******************************************************/

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


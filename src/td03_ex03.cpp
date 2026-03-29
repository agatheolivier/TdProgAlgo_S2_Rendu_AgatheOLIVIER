#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

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

/********************************************* Générer tableau ******************************************************/

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

/************************************************ Vérifications *****************************************************/

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

/*********************************************** Main ***************************************************************/

main() {
    std::vector<int> tab1 = generate_random_vector(100,1000);
    {
        ScopedTimer timer1("Temps - selection sort");
        selection_sort(tab1);
    }
    if (is_sorted(tab1)) {
        std::cout << "Le tableau 1 est trié" << std::endl;
    } else {
        std::cout << "Le tableau 1 n'est pas trié" << std::endl;
    }

    std::vector<int> tab2 = generate_random_vector(100,1000);
    {
        ScopedTimer timer2("Temps - merge sort");
        merge_sort(tab2);
    }
    if (is_sorted(tab2)) {
        std::cout << "Le tableau 2 est trié" << std::endl;
    } else {
        std::cout << "Le tableau 2 n'est pas trié" << std::endl;
    }

    std::vector<int> tab3 = generate_random_vector(100,1000);
    {
        ScopedTimer timer3("Temps - standard sort");
        std::sort(tab3.begin(), tab3.end());
    }
    if (is_sorted(tab3)) {
        std::cout << "Le tableau 3 est trié" << std::endl;
    } else {
        std::cout << "Le tableau 3 n'est pas trié" << std::endl;
    }
}

/********************************************************* Questions *************************************************************/
/*
Avec cette fonction, vous pouvez comparer les temps d'exécution de vos algorithmes de tri avec celui de la bibliothèque standard.
Selection sort : 0.0311 ms
Merge sort : 0.0406 ms
Standard sort : 0.0145 ms

Que constatez-vous ?
La fonction standard est plus rapide.
Que pouvez-vous en dire ?
La fonction standard est mieux optimisée.
*/
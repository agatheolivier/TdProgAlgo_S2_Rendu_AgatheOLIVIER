#include <iostream>
#include <vector>
#include <algorithm>

int search(std::vector<int> & tab, int valeurR) {
    size_t left = 0;
    size_t right = tab.size()-1;

    if (right - left <= 0) {
        return -1;
    }
    else if (valeurR < tab[left] || valeurR > tab[right]){
        return -1;
    }

    while (left <= right) {
            size_t middleIndex = (left + right) / 2;

        if (valeurR > tab[middleIndex]){
            left = middleIndex + 1;
        }
        else if (valeurR < tab[middleIndex]){
            right = middleIndex - 1;
        }
        else if (valeurR == tab[middleIndex]) {
            return middleIndex;
        }
    }

    return -1;
}


int main() {
    int index = 0;
    std::vector<int> tableau {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valeur = 10;
    index = search(tableau, valeur);

    if (index == -1) {
        std::cout << "La valeur n'est pas dans le tableau" << std::endl;
    } else {
        std::cout << "L'index de cette valeur dans le tableau est " << index << std::endl;
    }
}
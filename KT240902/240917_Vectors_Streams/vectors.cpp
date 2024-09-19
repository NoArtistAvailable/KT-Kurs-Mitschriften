#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void util_vector();
void sort_vector();
void vector_2d();

void _main()
{
    //util_vector();
    //sort_vector();
    vector_2d();
}

void util_vector() {
    std::vector<int> iVector;   // maybe lazy initialized
    std::vector<int> iVec2 = { 3,4,5,6 };

    for (int i = 0; i < 100; i++) {
        iVector.push_back(i);   // fügt i an den letzten Platz des Arrays
        ++iVector[i];           // erhöht den Wert an Stelle i um 1.
    }

    for(int i = 0; i < iVector.size(); i++)
        std::cout << iVector[i] << " ";

    std::cout << "\nDas dritte Element ist: " << iVector[2] << std::endl;
    std::cout << "\nDas vierte Element ist: " << iVector.at(3) << std::endl;
    //std::cout << "\nNicht zugreifbar ist: " << iVector.at(999) << std::endl;

    iVector.pop_back(); // Entfernt das letzte Element
    std::cout << "\nDas Array nach dem entfernen des letzten Elements:\n" << std::endl;
    for (int elem : iVector)
        std::cout << elem << " ";
}

void sort_vector() {
    
}

void vector_2d() {
    vector<vector<int>> jaggedArray = {
        {1,2},
        {14,16,18,20,22},
        {19,19,19}
    };

    /*int array[3][4] = {
        {1,1,1,1},
        {14,16,18,20},
        {-3,-7,-10,-12}
    };*/

    for (int i = 0; i < jaggedArray.size(); i++) {
        for (int j = 0; j < jaggedArray[i].size(); j++) {
            std::cout << jaggedArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


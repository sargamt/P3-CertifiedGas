//
// Created by gabri on 4/16/2024.
//

//#include "Heap_structure.h"
#include <vector>
using namespace std;
template<typename T>
inline void heapify_up(vector<T>& vec, T attribute){
vec.push_back(attribute);
int index = vec.size() - 1;
        while(vec[index] < vec[(index - 1)/2] && index != 0){
        T temp = vec[index];
        vec[index] = vec[(index - 1)/2];
        vec[(index - 1)/2] = temp;
        index = (index - 1)/2;
    }
}
template<typename T>
inline void heapify_down(vector<T>& vec){
    int i = 0;
    while((2*i)+1 < vec.size() && (vec[i] > vec[(2*i)+1] || (vec[i] > vec[(2*i)+2]))){
        if(vec[(2*i)+1] < vec[(2*i)+2]){
            T temp = vec[i];
            vec[i] = vec[(2*i)+1];
            vec[(2*i)+1] = temp;
            i = (2*i)+1;
        }
        else if(vec[(2*i)+2] < vec[(2*i)+1]){
            T temp = vec[i];
            vec[i] = vec[(2*i)+2];
            vec[(2*i)+2] = temp;
            i = (2*i)+2;
        }
    }
}


//
// Created by gabri on 4/16/2024.
//

//#include "Heap_structure.h"
#include <vector>
#include "song.h"

using namespace std;
inline void heapify_up(vector<song>& vec, int heap_s){
    int index = heap_s;
    while((vec[index].getComparison() > vec[(index - 1)/2].getComparison())&& index != 0){
        // if the element further down the tree is smaller a swap is preformed
        song temp = vec[index];
        vec[index] = vec[(index - 1)/2];
        vec[(index - 1)/2] = temp;
        // update the index, so we follow the element for any further swaps that need to be preformed
        index = (index - 1)/2;
    }
}
inline void heapify_down(vector<song>& vec, int heap_s){
    // preforms that initial swap so the "bounds" of the heap
    int i = 0;
    int j = heap_s;
    song temp = vec[0];
    vec[0] = vec[heap_s];
    vec[heap_s] = temp;
    while((2*i)+1 < j){ // makes sure we dont try to index out of bounds
        if((2*i)+2 == j){ //edge case if the last element doesn't have a "sibling"
            if (vec[i].getComparison() < vec[(2*i)+1].getComparison()){
                temp = vec[i];
                vec[i] = vec[(2*i)+1];
                vec[(2*i)+1] = temp;
                i = (2*i)+1;
            }
            else{
                i = (2*i)+1;
            }
        }
        else if(vec[i].getComparison() < vec[(2*i)+1].getComparison()){
            if(vec[i].getComparison() < vec[(2*i)+2].getComparison()){
                // make sure both are bigger before performing swaps^^
                // if both are bigger check which of the two is bigger
                if(vec[(2*i)+1].getComparison() > vec[(2*i)+2].getComparison()){
                    temp = vec[i];
                    vec[i] = vec[(2*i)+1];
                    vec[(2*i)+1] = temp;
                    i = (2*i)+1;
                }
                else if(vec[(2*i)+2].getComparison() >= vec[(2*i)+1].getComparison()){
                    temp = vec[i];
                    vec[i] = vec[(2*i)+2];
                    vec[(2*i)+2] = temp;
                    i = (2*i)+2;
                }
            }
            // if only child one bigger swap that
            else{
                temp = vec[i];
                vec[i] = vec[(2*i)+1];
                vec[(2*i)+1] = temp;
                i = (2*i)+1;
            }
        // else the second child is bigger so we swap that
        }
        else if(vec[i].getComparison() < vec[(2*i)+2].getComparison()){
                temp = vec[i];
                vec[i] = vec[(2*i)+2];
                vec[(2*i)+2] = temp;
                i = (2*i)+2;
        }
        else{
            i = j;
        }
    }
}


inline void heap_sort(vector<song>& vec ){
    int heap_size = 1;
    // first add the elements to the heap
    while(heap_size != vec.size()){
        heapify_up(vec, heap_size);
        heap_size ++;
    }
    // remove from heap and sort
    int heap_end = vec.size()-1;
    while( heap_end != 0){
        heapify_down(vec, heap_end);
        heap_end--;
    }
}


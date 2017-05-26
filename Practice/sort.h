//
//  sort.h
//  Practice
//
//  Created by Austin Montgomery on 5/14/17.
//  Copyright © 2017 University of Michigan. All rights reserved.
//

#ifndef sort_h
#define sort_h

// sorts string segments of contiguous numbers/characters
// preserving segment order
std::string segmentSort(std::string str){
    return str;
}

//  quickly implement heapsort
std::vector<int> heapSort(std::vector<int> &list){
    return list;
}

std::vector<int> insertionSort(std::vector<int> &list){
    for(int i = 1; i < list.size(); ++i){
        for(int j = i; j >= 1; --j){
            if(list[j-1] > list[j]){
                int tmp = list[j];
                list[j] = list[j-1];
                list[j-1] = tmp;
            }else{
                break;
            }
        }
    }
    return list;
}

void printVector(std::vector<int> list){
    for(int i = 0; i < list.size(); ++i){
        std::cout << list[i];
        if(i < list.size() - 1) std::cout<<" ";
    }
    std::cout<<std::endl;
}


#endif /* sort_h */

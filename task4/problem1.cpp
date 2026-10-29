//remove duplicates from unsorted array 
#include<vector>
#include<algorithm>
#include<iostream>

// w index to write into
// r index to read the new number
// check will be with w-1 (to leave an element)
void removeDuplicates(std::vector<int>& v){
    if(v.empty()) return;
    std::sort(v.begin(),v.end());

    unsigned int w = 1;
    for(unsigned int r = 1;r < v.size();r++){
        if(v[r] != v[w - 1]){
            v[w] = v[r];
            w++;
        }
    }

    v.resize(w);
}

int main(){
    std::vector<int> v{2,3,4,5,1,5,8,3,-1,4,-4};
    std::cout<< "the vector before removing the duplicates:";
    for(auto& num: v){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";

    removeDuplicates(v);
    
    std::cout<< "the vector after removing the duplicates:";
    for(auto& num: v){
        std::cout<<num<<" ";
    }
    std::cout<<"\n";

}
//how many contigous subarray with sum = k
#include<unordered_map>
#include<vector>
#include<iostream>

//prefix sum solution 
int numOfContigousSubarray(std::vector<int>& v, int k){
    int prefixSum=0,count=0;
    std::unordered_map<int,int> freq;
    for(int i=0;i<v.size();i++){
        prefixSum += v[i];
        freq[prefixSum] = i;

        if(prefixSum == k) count++;

        if(freq.count(prefixSum - k)) count++;
    }

    return count;
}

int main(){
    std::vector<int> v{1,2,2,3,1,2,1,2};
    int k = 3;
    int num = numOfContigousSubarray(v ,k);
    
    std::cout<<"The count of the contigous subarrays whose length is "<< k <<" is "<<num <<"\n";
}

//least subarray size have sum > or equal k
#include<limits.h>

#include<vector>
int getLeastSubArray(std::vector<int>& v,int k){
    if(v.empty()) return -1;

    int sum = v[0];
    int curr_length;
    int best_length = INT_MAX;
    int i=0,j=0;
    while( i < v.size()){
        if(sum < k){
            j++;
            if(j == v.size()) break;
            sum += v[j];
        }else{
            curr_length = j - i +1;
            if(curr_length < best_length) best_length = curr_length;

            sum-= v[i];
            i++;
        }
    }

    return (best_length == INT_MAX)? 0 : best_length ;
}
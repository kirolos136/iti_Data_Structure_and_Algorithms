// max average subarray
#include <vector>
#include <iostream>
#include <algorithm>

// fixed sliding window
float maxAverage(std::vector<int> v, int k)
{
    if (v.size() < k)
        return -1;

    int right = 0, left = 0, sum = 0;
    float average, max_average = 0;

    for (; right < v.size(); right++)
    {
        sum += v[right];
        if ((right - left + 1) == k)
        {
            average = ((float)sum) / (right - left + 1);
            max_average = std::max(average, max_average);
            sum -= v[left];
            left++;
        }
    }

    return max_average;
}

int main()
{
    std::vector<int> v = {1, 12, -5, -6, 50, 3};
    int k = 4;

    std::cout << "Max average: " << maxAverage(v, k) << '\n';
}
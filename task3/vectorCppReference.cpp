#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

void pointer_func(const int *p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
}

int main()
{
    std::vector<int> c = {1, 2, 3, 4, 5};

    std::cout << "elements in vector using first method:";
    for (auto &num : c)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "elements in vector using second method:";
    std::vector<int>::iterator it = c.begin();
    for (; it != c.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    std::vector<int> a1{1, 2, 3}, a2{4, 5};
    std::cout << "elements in vector a1 before swapping:";
    for (auto &num : a1)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "elements in vector a2 before swapping:";
    for (auto &num : a2)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    a1.swap(a2);

    std::cout << "elements in vector a1 after swapping:";
    for (auto &num : a1)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "elements in vector a2 after swapping:";
    for (auto &num : a2)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::vector<int> s = {5, 2, 10};

    std::cout << "s before sorting:";
    for (auto &num : s)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";

    sort(s.begin(), s.end());
    std::cout << "s after sorting:";
    for (auto &num : s)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";

    std::cout << "s before reversing:";
    for (auto &num : s)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";

    reverse(s.begin(), s.end());
    std::cout << "s after sorting:";
    for (auto &num : s)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";

    std::vector<int> big{1, 2, 3, 4, 5, 6};
    std::vector<int> small{3, 4};

    std::cout << "big vector:";
    for (auto &num : big)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";

    std::cout << "small vector:";
    for (auto &num : small)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";
    std::vector<int>::iterator its = std::search(big.begin(), big.end(), small.begin(), small.end());

    if (its == big.end())
        std::cout << "vector not found";
    else
        std::cout << "found at index: " << its - big.begin();

    std::vector<int> freqs{1, 2, 2, 2, 3, 4, 4};
    std::cout << "the Freq vector:";
    for (auto &num : freqs)
    {
        std::cout << num << " ";
    }

    std::cout << "\n";
    std::vector<int> uniq(freqs);
    auto last = std::unique(uniq.begin(), uniq.end());
    uniq.erase(last, uniq.end());
    for (auto &num : uniq)
    {
        std::cout << "The num is:" << num << " The freq is:" << count(freqs.begin(), freqs.end(), num) << "\n";
    }

    std::cout << "\n";

    std::cout << "the Freq vector:";
    for (auto &num : freqs)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int sum = std::accumulate(freqs.begin(), freqs.end(), 0);
    std::cout << "the sum of the frequency vector:" << sum;
    std::cout << "\n";

    std::cout << "the Freq vector:";
    for (auto &num : freqs)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::ranges::reverse(freqs.begin(), freqs.end());
    std::cout << "the Freq vector reversed:";
    for (auto &num : freqs)
    {
        std::cout << num << " ";
    }

    std::vector<int> container{1, 2, 3, 4};

    pointer_func(container.data(), container.size());
}
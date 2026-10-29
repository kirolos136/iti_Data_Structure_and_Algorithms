# Subarray Sum Patterns

Two common patterns for solving contiguous subarray problems.

## 1. Sliding Window / Two Pointers

**Use when:**
- The problem involves a contiguous subarray.
- For a variable-size window, all array elements are **non-negative**.
- The window can be expanded or shrunk based on its sum.
- For a fixed-size window, negative numbers are allowed because the window length stays constant.

**Idea:**

Maintain a window between `left` and `right` and keep track of its `sum`.

- Expand the window by moving `right`.
- Update `sum` when adding an element.
- Shrink the window by moving `left` when the condition requires it.
- Update the answer whenever a valid window is found.

### Example: Minimum subarray length with `sum >= k`

```cpp
int left = 0;
int best = INT_MAX;
long long sum = 0;

for (int right = 0; right < v.size(); right++) {
    sum += v[right];

    while (sum >= k) {
        best = min(best, right - left + 1);

        sum -= v[left];
        left++;
    }
}

return best == INT_MAX ? 0 : best;
```

*Assumption: all elements are non-negative and `k > 0`.*

**Time:** `O(n)`  
**Extra space:** `O(1)`

Each pointer moves forward at most `n` times.

### Common variations

- `sum >= k`: shrink while `sum >= k` to find the minimum length.
- `sum <= k`: shrink while `sum > k` to maintain a valid window.
- Fixed window of size `k`: remove the outgoing element and add the incoming element.

**Important:** With negative numbers, expanding the window can decrease the sum, and shrinking it can increase the sum. The usual variable-size sliding-window logic is therefore not reliable.

---

## 2. Prefix Sum + Hashmap

**Use when:**
- The problem involves the sum of contiguous subarrays.
- Negative numbers may exist.
- The problem asks for subarrays whose sum is exactly `k`, or another problem that can be solved by looking up previous prefix sums.

**Idea:**

Maintain a running `prefixSum`.

The sum of a subarray from index `i` to index `j` is:

```text
subarraySum = prefixSum[j] - prefixSum[i - 1]
```

If the required subarray sum is `k`, we need a previous prefix sum equal to:

```text
prefixSum - k
```

Use an `unordered_map` to store information about previous prefix sums.

### Example: Count contiguous subarrays with `sum == k`

```cpp
int countSubarrays(const vector<int>& v, int k) {
    unordered_map<long long, int> freq;

    long long prefixSum = 0;
    long long count = 0;

    freq[0] = 1;

    for (int x : v) {
        prefixSum += x;

        count += freq[prefixSum - k];

        freq[prefixSum]++;
    }

    return count;
}
```

**Why `freq[0] = 1`?**

It accounts for subarrays starting at index `0` whose sum is exactly `k`.

**Why store frequencies instead of indices?**

The same prefix sum can occur multiple times. Each occurrence represents a possible starting boundary for another subarray. We must count all of them.

**Time:** `O(n)` on average  
**Extra space:** `O(n)`

### Common variations

- **Count subarrays with sum `k`:** Store the frequency of each prefix sum.
- **Find whether a subarray with sum `k` exists:** Track whether a required prefix sum has appeared.
- **Find the longest subarray with sum `k`:** Store the earliest index of each prefix sum instead of overwriting it.

**Important:** Prefix sum + hashmap also works with positive numbers, but it is not always the most space-efficient solution.

---

## Quick Decision Guide

| Problem condition | Pattern |
|---|---|
| Fixed window size | Sliding window |
| Variable-size window, non-negative elements, sum constraint | Sliding window / two pointers |
| Exact sum `== k`, negative numbers possible | Prefix sum + hashmap |
| Exact sum `== k`, non-negative elements | Sliding window or prefix sum |
| Sum inequality with negative numbers | Usually needs additional techniques; a basic sliding window or frequency hashmap may not be enough |

## Remember

**Sliding window:** Maintain a window and adjust its boundaries.

**Prefix sum + hashmap:** Use previous prefix sums to discover or count subarrays.

Both can run in `O(n)` time, but sliding window usually uses `O(1)` extra space, while the hashmap approach usually uses `O(n)` extra space.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // ==========================================
    // Task 1: Iterators vs Const Iterators
    // ==========================================
    cout << "=== Task 1: Iterators vs Const Iterators ===" << endl;
    vector<int> nums = {10, 20, 30};

    cout << "Loop A (Standard iterator - can modify): ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        *it += 5; // Modifying elements
        cout << *it << " ";
    }
    cout << endl;

    cout << "Loop B (Const iterator - read only): ";
    for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
        // *it += 5; // Error! const_iterator cannot modify *it
        cout << *it << " ";
    }
    cout << "\n\n";

    // ==========================================
    // Task 2: Search with find()
    // ==========================================
    cout << "=== Task 2: Search with find() ===" << endl;
    const vector<int> scores = {78, 92, 65, 88, 74, 92};

    // Testing 88 and 100
    int testTargets[] = {88, 100};
    for (int target : testTargets) {
        cout << "Searching for score: " << target << endl;
        auto result = find(scores.cbegin(), scores.cend(), target);
        if (result != scores.cend()) {
            cout << "Result: Found (" << *result << ")" << endl;
        } else {
            cout << "Result: Not found" << endl;
        }
    }
    cout << "\n";

    // ==========================================
    // Task 3: Sort in Ascending and Descending Order
    // ==========================================
    cout << "=== Task 3: Sort in Ascending and Descending Order ===" << endl;
    vector<int> values = {78, 92, 65, 88, 74, 92};

    // Ascending
    sort(values.begin(), values.end());
    cout << "Ascending:  ";
    for (auto v : values) cout << v << " ";
    cout << endl;

    // Descending
    sort(values.begin(), values.end(), greater<int>());
    cout << "Descending: ";
    for (auto v : values) cout << v << " ";
    cout << "\n\n";

    // ==========================================
    // Task 4: Explore STL Algorithm
    // ==========================================
    cout << "=== Task 4: Explore STL Algorithm ===" << endl;
    // Demonstration 1: count()
    // Purpose: Counts elements matching target value. Returns count (ptrdiff_t).
    int count92 = count(values.begin(), values.end(), 92);
    cout << "count(): Number of times 92 occurs = " << count92 << endl;

    // Demonstration 2: min_element() & max_element()
    // Purpose: Returns an iterator pointing to the min/max element in range.
    auto minIt = min_element(values.begin(), values.end());
    auto maxIt = max_element(values.begin(), values.end());
    if (minIt != values.end() && maxIt != values.end()) {
        cout << "min_element(): Smallest value = " << *minIt << endl;
        cout << "max_element(): Largest value = " << *maxIt << endl;
    }

    // Demonstration 3: reverse()
    // Purpose: Reverses the sequence of elements in-place. Modifies the vector.
    reverse(values.begin(), values.end());
    cout << "reverse(): Vector order reversed: ";
    for (auto v : values) cout << v << " ";
    cout << endl;

    return 0;
}

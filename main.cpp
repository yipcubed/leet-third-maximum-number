#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"

// https://leetcode.com/problems/third-maximum-number/

// #include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // Time complexity for Building a Binary Heap is O(n).
    void heapify(vector<int> &arr, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < arr.size() && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < arr.size() && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, largest);
        }
    }

    void deleteRoot(vector<int> &arr) {
        // Get the last element
        int lastElement = arr[arr.size() - 1];

        // Replace root with first element
        arr[0] = lastElement;

        // Decrease size of heap by 1
        arr.pop_back();

        // heapify the root node
        heapify(arr, 0);
    }


    void buildHeap(vector<int> &arr) {
        for (int i = arr.size() / 2; i >= 0; --i) {
            heapify(arr, i);
        }
    }

    int thirdMax(vector<int> &nums) {
        assert(nums.size() > 0);
        buildHeap(nums);
        cout << nums << endl;
        int count = 1;
        int m1 = nums[0];
        int maximum = m1;
        deleteRoot(nums);
        while (count < 3 && nums.size() > 0) {
            int m2 = nums[0];
            deleteRoot(nums);
            if (m2 != m1)
                ++count;
            m1 = m2;
        }
        if (count != 3)
            return maximum;
        else
            return m1;
    }
};

void test1() {
    vector<int> v1{3, 2, 1};

    cout << " ? " << Solution().thirdMax(v1) << endl;
}

void test2() {

}

void test3() {

}
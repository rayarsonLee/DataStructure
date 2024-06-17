//
//  sorts.cpp
//  DataStructure
//
//  Created by lijiaxin on 2024/6/17.
//

#include <vector>
#include <iostream>
using namespace std;


// BubbleSort
// You code here!

// SelectionSort

#define let auto const
#define var auto

auto findMax(vector<int>& nums, int left, int right) -> size_t {
    size_t maxIndex = left;
    while (left <= right) {
        if (nums[left] > nums[maxIndex]) {
            maxIndex = left;
        }
        left += 1;
    }
    return maxIndex;
}

auto selectionSort(vector<int>& nums, int left, int right) -> void {
    while (right >= left) {
        auto maxIndex = findMax(nums, left, right);
        swap(nums[maxIndex], nums[right]);
        right -= 1;
    }
}

auto insertSort(vector<int>& nums, int left, int right) -> void {
    if (left >= right) {
        return;
    }
    for (int i = 1; i <= right; i += 1) {
        var temp = i;
        while (temp - 1 > -1 && nums[temp] < nums[temp - 1]) {
            swap(nums[temp], nums[temp - 1]);
            temp -= 1;
        }
    }
}

auto partition(vector<int>& nums, int left, int right) -> int {
    int baseIndex = right;
    // 交换随机索引
    int less = left;
    int curIndex = left;
    while (curIndex <= baseIndex - 1) {
        if (nums[curIndex] <= nums[baseIndex]) {
            swap(nums[less], nums[curIndex]);
            less += 1;
        }
        curIndex += 1;
    }
    swap(nums[less], nums[baseIndex]);
    return less;
}

auto quickSort(vector<int>& nums, int left, int right) -> void {
    if (left >= right) {
        return;
    }
    let baseIndex = partition(nums, left, right);
    quickSort(nums, left, baseIndex - 1);
    quickSort(nums, baseIndex + 1, right);
}

auto merge(vector<int>& nums, int left, int mid, int right) -> void {
    vector<int> temp(nums.size(), 0);
    var p1 = left;
    var p2 = mid + 1;
    var p3 = left;
    while (p1 <= mid && p2 <= right) {
        if (nums[p1] <= nums[p2]) {
            temp[p3] = nums[p1];
            p1 += 1;
        } else {
            temp[p3] = nums[p2];
            p2 += 1;
        }
        p3 += 1;
    }
    
    while (p1 <= mid) {
        temp[p3] = nums[p1];
        p3 += 1;
        p1 += 1;
    }
    while (p2 <= right) {
        temp[p3] = nums[p2];
        p3 += 1;
        p2 += 1;
    }
    for (int i = left; i <= right; i += 1) {
        nums[i] = temp[i];
    }
}

auto mergeSort(vector<int>& nums, int left, int right) -> void {
    if (left >= right) {
        return;
    }
    let mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

auto left(int index) -> int {
    return 2 * index + 1;
}

auto right(int index) -> int {
    return left(index) + 1;
}

auto parent(int index) -> int {
    return (index - 1) / 2;
}

// beautify美化
auto heapify(vector<int>& nums, int curIndex) -> void {
    int leftIndex = left(curIndex);
    int rightIndex = right(curIndex);
    // 没孩子
    if (leftIndex >= nums.size()) {
        return;
    }
    // 只有左孩子
    if (leftIndex < nums.size() && rightIndex >= nums.size()) {
        int leftVal = nums[leftIndex];
        if (nums[curIndex] < leftVal) {
            swap(nums[curIndex], nums[leftIndex]);
        } else {
            return;
        }
    }
    // 都有
    int leftVal = nums[leftIndex]; // 4
    int rightVal = nums[rightIndex]; // 2
    int targetIndex = leftIndex; // 100
    int leftOrRightIndex = leftIndex;
    if (leftVal > rightVal) {
        leftOrRightIndex = leftIndex; // 4
    } else {
        leftOrRightIndex = rightIndex;
    }
    
    if (nums[curIndex] > nums[leftOrRightIndex]) {
        targetIndex = curIndex;
    } else {
        targetIndex = leftOrRightIndex;
    }
    
    if (curIndex == targetIndex) {
        return;
    }
    swap(nums[curIndex], nums[targetIndex]);
    heapify(nums, targetIndex);
}

auto buildHeap(vector<int>& nums) -> void {
    int start = parent(nums.size() - 1);
    while (start >= 0) {
        heapify(nums, start);
        start -= 1;
    }
}

auto heapSort(vector<int>& nums) -> void {
    int size = nums.size();
    // 出错原因:这段代码实际上每次都弹出了一个元素
    // 堆的大小应该减小1
    // 但是heapify中用的是nums.size(),这个值一直没变,所以出错
    // 作业:bugfix
    buildHeap(nums);
    while (size - 1> 0) {
        let maxval = nums[0];
        cout << maxval << " ";
        swap(nums[0], nums[size - 1]);
        heapify(nums, 0);
    }
}

auto print(vector<int> const& nums) {
    for (int val: nums) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v{3, 4, 5, 1, 2, 123, 98, 1234,654, 0, -2};
    heapSort(v);
}


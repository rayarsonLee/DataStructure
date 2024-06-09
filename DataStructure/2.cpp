#include <iostream>

using namespace std;

// 第二章,向量

class Vector {
private:
    int *_nums = nullptr;
    int _capacity = 1;
    int _size = 0;
    
    // 从一个普通数组复制
    auto copyFrom(int *nums, int left, int right) -> void {
        if (nums == nullptr) {
            return;
        }
        _size = right + 1 - left;
        _capacity = 2 * _size;
        _nums = new int[_capacity];
        
        for (int i = 0; i < _size; i += 1) {
            _nums[i] = nums[left + i];
        }
    }
    // 空间不够时,扩容
    auto expand() -> void {
        _capacity = 2 * _size == 0 ? 1: 2 * _size;
        auto newNums = new int[_capacity];
        for (int i = 0; i < _size; i += 1) {
            newNums[i] = _nums[i];
        }
        auto oldNums = _nums;
        _nums = newNums;
        delete[] oldNums;
    }
    // 空间过大时,缩容
    auto shrink() -> void;
    
public:
    Vector(int *nums, int left, int right) {
        copyFrom(nums, left, right);
    }
    
    ~Vector() {
        delete[] _nums;
    }
    
    // O(n)
    auto max() -> int {
        auto maxVal = INT_MIN;
        for (int i = 0; i < _size; i += 1) {
            auto curNum = _nums[i];
            if (curNum > maxVal) {
                maxVal = curNum;
            }
        }
        return maxVal;
    }
    // O(n)
    auto min() -> int {
        auto minVal = INT_MAX;
        for (int i = 0; i < _size; i += 1) {
            auto curNum = _nums[i];
            if (curNum < minVal) {
                minVal = curNum;
            }
        } 
        return minVal;
    }
    // O(1)
    auto size() -> int {
        return _size;
    }
    // O(1)
    auto empty() -> bool {
        return _size == 0;
    }
    
    auto full() -> bool {
        return _size == _capacity;
    }
//
    // 无序查找 O(n)
    auto find(int target) -> int {
        return find(target, 0, _size - 1);
    }
    
    // O(n)
    auto find(int target, int left, int right) -> int {
        if (left > right) {
            return -1;
        }
        int pos = right;
        while (pos >= left) {
            if (_nums[pos] == target) {
                return pos;
            }
            pos -= 1;
        }
        return -1;
    }
//    // 有序查找 二分查找 O(logn)
    auto search(int target) -> int {
        return search(target, 0, _size);
    }
    auto search(int target, int left, int right) -> int {
        while (left < right) {
            auto mid = (left + right) / 2;
            if (_nums[mid] == target) {
                return mid;
            } else if (_nums[mid] < target) {
                left = mid + 1;
            } else if (_nums[mid] > target) {
                right = mid;
            }
        }
        return -1;
    }
    
    // 操作符重载
    auto operator[](int index) -> int {
        return _nums[index];
    }
    
    // 这是你的作业
//    auto operator+=(Vector const& otherVector) -> Vector& {
//        
//    }
    
    auto operator=(Vector const& otherVector) -> Vector& {
        _nums = otherVector._nums;
        _capacity = otherVector._capacity;
        _size = otherVector._size;
        return *this;
    }
//    // 移除
    auto removeAt(int index) -> int {
        auto oldVal = _nums[index];
        for (int i = index + 1; i < _size; i += 1) {
            _nums[i - 1] = _nums[i];
        }
        _size -= 1;
        return oldVal;
    }
    
    // 返回删除的个数
    auto removeBetween(int left, int right) -> int {
        if (right >= _size) {
            right = _size - 1;
        }
        auto realLeft = left;
        for (int i = right + 1; i < _size; i += 1) {
            _nums[left] = _nums[i];
            left += 1;
        }
        auto removedCount = right + 1 - realLeft;
        _size -= removedCount;
        return removedCount;
    }
//
    auto insertAt(int index, int val) -> void {
        if (full()) {
            expand();
        }
        for (int i = _size - 1; i >= index; i -= 1) {
            _nums[i + 1] = _nums[i];
        }
        _nums[index] = val;
        _size += 1;
    }
    auto append(int val) -> void {
        if (full()) {
            expand();
        }
        _nums[_size] = val;
        _size += 1;
    }

// 后面的内容
    auto sort() -> void {
        sortBetween(0, _size - 1);
    }
    auto bubble(int left, int right) -> void {
        for (int i = left; i + 1 <= right; i += 1) {
            if (_nums[i] > _nums[i + 1]) {
                swap(_nums[i], _nums[i + 1]);
            }
        }
    }
    
    auto sortBetween(int left, int right) -> void {
        while (left <= right) {
            bubble(left, right);
            right -= 1;
        }
    }
    
//    auto shuffle() -> void;
    auto shuffleBetween(int left, int right) -> void {
        for (int i = left; i <= right; i += 1) {
            //从i+1到right选一个随机数
            auto randomIndex = rand() %(right + 1 - i) + i;
            swap(_nums[randomIndex], _nums[i]);
        }
    }
    // 无序去重
    auto deduplicate() -> int {
        auto count = 0;
        for (int i = 0; i < _size;) {
            auto left = 0, right = i - 1;
            auto removedIndex = find(_nums[i], left, right);
            if (removedIndex != -1) {
                removeAt(removedIndex);
                count += 1;
            } else {
                i += 1;
            }
        }
        return count;
    }
    // 有序去重
    auto uniquify() -> int {
        auto right = 0, left = 0;
        auto pos = 0;
        auto oldSize = _size;
        while (right < _size) {
            while (right < _size && _nums[right] == _nums[left]) {
                right += 1;
            }
            _nums[pos] = _nums[left];
            pos += 1;
            left = right;
        }
        _size = pos;
        return oldSize - _size;
    }
    // 遍历
    auto traverse() -> void {
        for (int i = 0; i < _size; i += 1) {
            cout << _nums[i] << " ";
        }
        cout << "\n";
    }

};




/*
 作业
 https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
 https://leetcode.cn/problems/remove-element/
 https://leetcode.cn/problems/move-zeroes/
 https://leetcode.cn/problems/reverse-string/
 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
 https://leetcode.cn/problems/longest-palindromic-substring/
 */

int main() {
    int *nums = new int[10];
    
    for (int i = 0; i < 5; i += 1) {
        nums[i] = i;
    }
    for (int i = 5; i < 10; i += 1) {
        nums[i] = i - 5;
    }

    auto v = Vector(nums, 0, 9);
    v.sort();
    v.traverse();
    v.uniquify();
    v.traverse();
}

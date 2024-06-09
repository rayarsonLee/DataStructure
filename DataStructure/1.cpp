#include <iostream>

using namespace std;

// 第一章：绪论
// 时间复杂度

// O(1)
// 考虑将输入的三个数按照从小到大的顺序重新排列
// code:
//auto sort3Num(int a, int b, int c) -> void {
//    // 多种if * 常数
//}

// O(logn)
// 计算输入的整数的二进制中1的个数, 5 -> 101; x -> 001..10101;
// 001..10101
// code:
// 110101 &
// 000001 -> 000001

// 110000
// 000001 -> 000000
// x -> x/c -> x/4 -> x/8
//auto getCountOfOne(int x) -> int {
//    auto count = int{0};
//    while (x > 0) {
//        auto lastNum = x & 1; // 提取最低位
//        x >>= 1; // 右移
//        if (lastNum == 1) {
//            count += 1;
//        }
//    }
//    return count;
//}

// O(n)
// 计算一维数组中n个数的和
// code:

//auto getSum(vector<int> const & nums) {
//    auto size = nums.size();
//    auto sum = 0;
//    for (int i = 0; i < size; i += 1) {
//        sum += nums[i];
//    }
//    return sum;
//}

// O(多项式n^2)
// 计算二维数组中n个数的和
// code:

// O(2^n) -> O(多项式n^2)


 

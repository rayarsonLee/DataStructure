#include <iostream>

using namespace std;

// 第二章,向量

class Vector {
private:
    int *_nums = nullptr;
    int _capacity = 1;
    int _size = 0;
    
    // 从一个普通数组复制
    auto copyFrom(int * nums, int left, int right) -> void;
    // 空间不够时,扩容
    auto expand() -> void;
    // 空间过大时,缩容
    auto shrink() -> void;
    
public:
    Vector(int *nums);
    Vector(Vector const& otherVector);
    ~Vector();
    
    auto max() -> int;
    auto min() -> int;
    auto size() -> int;
    auto empty() -> bool;
    
    // 无序查找
    auto find(int target) -> int;
    auto find(int target, int left, int right) -> int;
    // 有序查找
    auto search(int target) -> int;
    auto search(int target, int left, int right) -> int;
    // 操作符重载
    auto operator[](int index) -> int;
    auto operator=(Vector const& otherVector) -> Vector&;
    
    // 移除
    auto removeAt(int index) -> int;
    auto removeBetween(int left, int right) -> int;
    
    auto insertAt(int index, int val) -> void;
    auto append(int val) -> void;
    auto sort() -> void;
    auto sortBetween(int left, int right) -> void;
    auto shuffle() -> void;
    auto shuffleBetween(int left, int right) -> void;
    // 无序去重
    auto deduplicate() -> int;
    // 有序去重
    auto uniquify() -> int;
    // 遍历
    auto traverse() -> void;
};


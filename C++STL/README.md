# C++ STL

- 传递STL等空间开销较大的对象时，传引用。如：`void foo(vector& vec) { /*...*/}`

### 一些注意点
- **哈希集合**`unordered_set<const V>`中的元素不可改，数据类型是`const V`
```C++
std::unordered_set<int> uset;
for (auto& x : uset) { /*...*/ } // x 不拷贝，数据类型是const int
for (const int& x : uset) { /*...*/ } // 同上，两者等价

for (auto x : uset) { /*...*/ } // 拷贝一个 x，数据类型是int
for (int x : uset) { /*...*/ } // 同上，两者等价

for (int& x : uset) { /*...*/ } // ❌ 报错
```
- **哈希表**`unordered_map<cosnt K, V>`中的**键**不可改，数据类型是`const K`，**值**可以改
```C++
for (auto& [k, v] : hashmap) { 
    // k++; // ❌ 报错
    v++; // 是可行的
}
```

- `{}`用来赋初始值，如`int x{3};`

- `pop()`之前先判`!empty()`
#include <iostream>

using namespace std;

const int N = 20;

int arr[N];
int idx; // 当前位置

void print(int a[])
{
    for (int i = 0; i < idx; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    memset(arr, 0, sizeof(arr)); // 将数组初始化为全 0

    // 追加(append) - O(1)
    for (int i = idx; i < 10; i++)
    {
        arr[idx++] = (i + 1); // 先试用idx 然后自增
    }
    print(arr);

    // 插入(insert) - 需要移动元素
    // (1)数组未满: 中间插入 - O(N), 结尾插入 - O(1)
    int n = 2; // 在索引为 `n` 的位置(第三个元素)插入一个元素
    for (int i = idx++; i > n; i--) // arr[idx] 此时没有元素，插入后会有元素，需要++
    {
        arr[i] = arr[i - 1];
    }
    arr[n] = 666; // 插入元素
    print(arr);

    // (2)数组已满: 需要开辟一块新空间，一般大小为原来数组的两倍
    int new_arr[2*N];
    for (int i = 0; i < idx; i++)
    {
        new_arr[i] = arr[i];
    }
    print(new_arr);
    // 如果是alloc的数组，释放内存，并进行相同的插入操作

    // 删除(delete)
    // 删除中间元素 - O(N), 删除结尾元素 - O(1)
    n = 2; // 删除索引为 n 的元素
    idx--; // `idx - 1`的位置也会没有元素
    for (int i = n; i < idx; i++)
    {
        arr[i] = arr[i + 1]; // 后面的元素覆盖前面的元素
    }
    idx--; //如果删除末尾元素，那上面的for循环会直接跳过
    print(arr);


    return 0;
}
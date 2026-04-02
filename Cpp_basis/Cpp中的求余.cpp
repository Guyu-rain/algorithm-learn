#include <iostream>

using namespace std;

/*
    对整数求余，C++保证：
        a == (a / b) * b + (a % b)
    a / b 会向 0 截断，因此 a % b 可能是负数，
    而且 ⚠️ a % b 的符号跟着 a 走。
*/

int main() {
    printf("-7 %% 3 = %d \n", -7 % 3); // -1

    printf("7 %% -3 = %d \n", 7 % -3); // 1

    printf("-7 %% -3 = %d \n", -7 % -3); // -1

    return 0;
}
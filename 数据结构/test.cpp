#include <iostream>
#include <vector>

double f_iter(double x0) {
    struct Frame {
        double x;
        int state;     // 0: 刚进入; 1: 已算出 f(x-1); 2: 已算出 f(x - f(x-1))
        double a;      // 保存 a = f(x-1)
    };

    std::vector<Frame> st;
    st.push_back(Frame{x0, 0, 0.0});

    double ret = 0.0;  // “最近一次返回值”，用于向上层栈帧传递

    while (!st.empty()) {
        Frame &cur = st.back();

        if (cur.state == 0) {
            // 对应递归函数开头
            if (cur.x < 0.0) {
                ret = -cur.x;      // base case
                st.pop_back();     // 返回到调用者
            } else {
                // 需要先算 a = f(x-1)
                cur.state = 1;
                st.push_back(Frame{cur.x - 1.0, 0, 0.0});
            }
        }
        else if (cur.state == 1) {
            // 刚从 f(x-1) 返回，ret 就是 a
            cur.a = ret;
            // 现在要算 b = f(x - a)
            cur.state = 2;
            st.push_back(Frame{cur.x - cur.a, 0, 0.0});
        }
        else { // cur.state == 2
            // 刚从 f(x - a) 返回，ret 就是 b
            ret = ret / 2.0;   // 返回 b/2
            st.pop_back();
        }
    }

    return ret;
}


int main() {
    std::cout << f_iter(3) << std::endl;

    return 0;
}
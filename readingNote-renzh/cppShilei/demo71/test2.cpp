#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
C++11 函数对象的升级版 =》 lambda表达式
函数对象的缺点：
使用在泛型算法参数传递   比较性质/自定义操作  优先级队列  智能指针

lambda表达式的语法：
[捕获外部变量](形参列表)->返回值{操作代码};

如果lambda表达式的返回值不需要，那么"->返回值"可以省略的

[捕获外部变量]
[]：表示不捕获任何外部变量
[=]：以传值的方式捕获外部的所有变量
[&]：以传引用的方式捕获外部的所有变量
[this]：捕获外部的this指针
[=,&a]：以传值的方式捕获外部的所有变量，但是a变量以传引用的方式捕获
[a, b]：以值传递的方式捕获外部变量a和b
[a, &b]：a以值传递捕获，b以传引用的方式捕获
*/
template <typename T = void>
class TestLambda01 {
   public:
    TestLambda01() {}
    void operator()() const { cout << "hello world" << endl; }
};

template <typename T = void>
class TestLambda02 {
   public:
    TestLambda02() {}
    int operator()(int a, int b) const { return a + b; }
};

template <typename T = int>
class TestLambda03 {
   public:
    TestLambda03(int& a, int& b) : ma(a), mb(b) {}
    void operator()() const {
        int tmp = ma;
        ma = mb;
        mb = tmp;
    }

   private:
    int& ma;
    int& mb;
};

int main() {
    vector<int> vec;
    for (int i = 0; i < 20; ++i) {
        vec.push_back(rand() % 100 + 1);
    }
    sort(vec.begin(), vec.end(), [](int a, int b) -> bool { return a > b; });

    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 65按序插入序列  要找第一小于65的数字
    auto it =
        find_if(vec.begin(), vec.end(), [](int a) -> bool { return a < 65; });
    if (it != vec.end()) {
        vec.insert(it, 65);
    }

    for_each(vec.begin(), vec.end(), [](int a) {
        if (a % 2 == 0) cout << a << " ";
    });
    cout << endl;

    return 0;
}
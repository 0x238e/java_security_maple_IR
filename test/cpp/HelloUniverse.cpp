#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "The Answer to Life, the Universe and Everything is:  ";
    cin >> n;
    if (n == 42) {
        cout << "Find highly intelligent lifeform! Start the destruction process!" << endl;
    }
    // 这里为了测试编译器效果
    else if (n != 42) {
        cout << "Yes, you are right!" << endl;
    }
    return 0;
}

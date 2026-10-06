#include <iostream>
#include <string>
using namespace std;

// 打印子集
void printSubset(string subset[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
}

// 遞迴函數計算冪集合
void set(string S[], int n, string subset[], int size, int index) {
    if (index == n) {
        // 已處理完所有元素，打印當前子集
        printSubset(subset, size);
        return;
    }

    // 遞迴處理：不包含當前元素
    set(S, n, subset, size, index + 1);

    // 遞迴處理：包含當前元素
    subset[size] = S[index];
    set(S, n, subset, size + 1, index + 1);
}

int main() {
    string input;
    cout << "請輸入集合的元素(以空格分隔): ";
    getline(cin, input); // 讀取輸入的整行字串

    // 將輸入字串按照空格拆分為單個元素
    string S[100];
    int n = 0; // 集合的大小
    string temp = "";

    // 解析輸入字串，按空格分隔各個元素
    for (char c : input) {
        if (c == ' ') {
            if (!temp.empty()) {
                S[n++] = temp; // 將元素加入集合
                temp = ""; // 清空暫存
            }
        }
        else {
            temp += c; // 將字元加入到當前元素
        }
    }

    // 將最後一個元素加入集合
    if (!temp.empty()) {
        S[n++] = temp;
    }

    // 分配用於儲存子集的陣列
    string subset[100];

    // 計算並打印冪集合
    cout << "冪集合為:" << endl;
    set(S, n, subset, 0, 0);

    return 0;
}

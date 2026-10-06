#include <iostream>
#include <string>
using namespace std;

void printSubset(string subset[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
}

void set(string S[], int n, string subset[], int size, int index) {
    if (index == n) {
    
        printSubset(subset, size);
        return;
    }

    set(S, n, subset, size, index + 1);
    subset[size] = S[index];
    set(S, n, subset, size + 1, index + 1);
}

int main() {
    string input;
    cout << "請輸入集合的元素(以空格分隔): ";
    getline(cin, input); 


    string S[100];
    int n = 0; 
    string temp = "";


    for (char c : input) {
        if (c == ' ') {
            if (!temp.empty()) {
                S[n++] = temp; 
                temp = ""; 
            }
        }
        else {
            temp += c; 
        }
    }

    if (!temp.empty()) {
        S[n++] = temp;
    }

    string subset[100];

    cout << "冪集合為:" << endl;
    set(S, n, subset, 0, 0);

    return 0;
}

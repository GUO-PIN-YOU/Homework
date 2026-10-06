# 41243134

作業二

## 解題說明

本題要求實現一個遞迴函式，生成並輸出給定集合的所有子集（即冪集合 Power Set）。

### 解題策略

1. 使用遞迴（Backtracking / 包含與不包含策略）將問題拆解為子問題：
   對於集合中的每一個元素，都有兩種選擇：
   - 不將該元素納入當前子集。
   - 將該元素納入當前子集。
2. 當處理到的元素索引 `index` 等於集合大小 `n` 時，達到遞迴結束條件，輸出當前的子集組合。
3. 主程式讀取使用者輸入的集合元素（以空格分隔），呼叫遞迴函式計算並印出冪集合。

## 程式實作

以下為主要程式碼：

```cpp
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
```

## 效能分析

1. 時間複雜度：對於包含 $n$ 個元素的集合，其子集總數為 $2^n$ 個。遞迴樹深度為 $n$，每個葉節點印出長度最多為 $n$ 的子集，因此時間複雜度為 $O(n \cdot 2^n)$。
2. 空間複雜度：遞迴呼叫堆疊最大深度為 $O(n)$，搭配長度為 $n$ 的暫存陣列 `subset`，整體額外空間複雜度為 $O(n)$。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數（集合元素） | 預期輸出 | 實際輸出 |
|----------|----------------------|----------|----------|
| 測試一   | `(空字串)`            | `{ }` | `{ }` |
| 測試二   | `A`                  | `{ }`<br>`{ A }` | `{ }`<br>`{ A }` |
| 測試三   | `a b`                | `{ }`<br>`{ b }`<br>`{ a }`<br>`{ a b }` | `{ }`<br>`{ b }`<br>`{ a }`<br>`{ a b }` |
| 測試四   | `1 2 3`              | `{ }`<br>`{ 3 }`<br>`{ 2 }`<br>`{ 2 3 }`<br>`{ 1 }`<br>`{ 1 3 }`<br>`{ 1 2 }`<br>`{ 1 2 3 }` | `{ }`<br>`{ 3 }`<br>`{ 2 }`<br>`{ 2 3 }`<br>`{ 1 }`<br>`{ 1 3 }`<br>`{ 1 2 }`<br>`{ 1 2 3 }` |

### 編譯與執行指令

```shell
$ g++ -std=c++17 -o power_set main.cpp
$ ./power_set
請輸入集合的元素(以空格分隔): 1 2 3
冪集合為:
{ }
{ 3 }
{ 2 }
{ 2 3 }
{ 1 }
{ 1 3 }
{ 1 2 }
{ 1 2 3 }
```

### 結論

1. 程式能正確生成並印出任意輸入集合的所有可能子集（冪集合）。  
2. 測試案例涵蓋了空集合、單一元素、多個元素等情況，驗證了遞迴邊界與狀態回溯的正確性。

## 申論及開發報告

### 選擇遞迴的原因

在本程式中，使用遞迴來生成冪集合的主要原因如下：

1. **程式邏輯簡單直觀**  
   遞迴能夠清楚表達「決策樹（Decision Tree）」的思想。對於每一個元素，只需考慮「不選」與「選」兩種狀態，並透過遞迴展開所有可能的子集組合。

2. **易於理解與實現**  
   相較於位元運算（Bitmasking）或迭代法，遞迴回溯（Backtracking）寫法更符合人類列舉所有組合的自然思考流程：  

   ```cpp
   // 不選當前元素
   set(S, n, subset, size, index + 1);
   // 選當前元素
   subset[size] = S[index];
   set(S, n, subset, size + 1, index + 1);
   ```

3. **遞迴的語意清楚**  
   每次遞迴呼叫代表針對陣列中下一個元素的抉擇，當 `index == n` 時自動抵達邊界並列印結果。利用傳入 `size` 與 `index` 參數記錄狀態，無須複雜的全域變數管理。

透過遞迴實作冪集合生成，程式邏輯清晰明確。然而需要注意，冪集合的大小隨 $n$ 呈指數型成長（$2^n$），當集合元素數量較大時，將會耗費大量時間與記憶體空間，在實際應用中應注意 $n$ 的上限限制。
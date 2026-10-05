#include <iostream>
using namespace std;
int Ack(  int m,   int n) {
    if (m == 0) return n + 1 ;
    if (n == 0) return Ack(m - 1, 1 );
    return Ack(m - 1, Ack(m, n - 1));
}


int main() {
      int m;
      int n;
    cout << "輸入 m n : ";
    if (!(cin >> m >> n)) return 0;

      int res = Ack(m, n);
    cout << "Ack(" << m << ", " << n << ") = " << res << endl;
    return 0;
}

#include <iostream>
#include <cmath>
 
void printLine(const int k, const int iRow, const int vShift = 0) {
  for (int iCol = 0; iCol < k; iCol += 1) {
    std::cout << ((iRow + vShift) % k == iCol ? 'X' : '.');
  }
}
 
void printTbl(const int n, const int k = 1,  const int vShift = 0) {
  for (int iLine = 0; iLine < n / k; iLine += 1) {
    for (int iRow = 0; iRow < k; iRow += 1) {
      for (int iCol = 0; iCol < n / k; iCol += 1) {
        printLine(k, iRow, vShift);
      }
      std::cout << '\n';
    }
  }
}
 
int main() {
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i += 1) {
    int n = 0; //
    int k = 0; //
    int r = 0; //
    int c = 0; //
    std::cin >> n >> k >> r >> c;
    int y = r % k;
    int x = c % k;
    int shift = (x - y + k) % k;
    printTbl(n, k, shift);
  }
}
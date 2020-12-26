//begintemplate S
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define t(r) ((1<<(r))&n)<<(r)|((1<<(r))&n)<<(r+1)
#define tt(r) t(r)|t(r+1)|t(r+2)|t(r+3)|t(r+4)|t(r+5)|t(r+6)|t(r+7)|t(r+8)|t(r+9)


unsigned long long duplicatebits(unsigned long long n) {
  return 0|tt(0)|tt(10)|tt(20)|t(30)|t(31);
}

int main() {
  std::string n;
  std::cin >> n;
  unsigned long long b = duplicatebits(std::bitset<64>(n).to_ullong());
  std::cout << b << "\n";
  std::cout << std::bitset<64>(b);

  return 0;
}
//endtemplate S
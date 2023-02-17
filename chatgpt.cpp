#include <iostream>
using namespace std;

int main() {
  int i, j, n;
  cout << "Enter the number of rows: ";
  cin >> n;

  // Loop to print the top half of the star
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n - i; j++) {
      cout << " ";
    }
    for (j = 1; j <= 2 * i - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }

  // Loop to print the bottom half of the star
  for (i = n - 1; i >= 1; i--) {
    for (j = 1; j <= n - i; j++) {
      cout << " ";
    }
    for (j = 1; j <= 2 * i - 1; j++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}

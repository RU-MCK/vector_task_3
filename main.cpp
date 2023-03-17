#include <iostream>
#include "vector"
#include <limits>
using namespace std;

vector<int> del_first_el(vector<int> vec) {
  vector<int> new_vec(vec.size() - 1);
  for (int i = 1; (i < vec.size()); i++) {
    new_vec[i - 1] = vec[i];
  }
  new_vec.resize(vec.size());
  return new_vec;
}

void print_output(vector<int> vec, int size) {
  cout << "Output: ";
  for (int i = 0; i < size; i++)
    cout << vec[i] << " ";
  cout << endl;
}

bool check_symbol(int value) {
  while (true) {
    if (cin.fail() || cin.peek() != '\n') {
      cerr << "Data entry error!\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return false;
    } else
      return true;
  }
}

int main() {

  vector<int> db(20);
  cout << "Press to print '-1 '" << endl
       << "Press to exit  '-2 '" << endl
       << "Input numbers: " << endl;
  int n;
  int count = 0;

  while (true) {
    cin >> n;
    if (!(check_symbol(n)))continue;

    if (n >= 0) {
      if (count < db.size()) {
        db[count] = n;
        ++count;
      } else {
        db = del_first_el(db);
        db[db.size() - 1] = n;
      }
    } else {
      if (n == -1) print_output(db, count);
      if (n == -2)break;
    }
  }
  cout << "End of work.";
}

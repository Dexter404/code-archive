#include<iostream>
#include"vector.h"
using namespace std;
int main() {
    Vector<char> B(10,'A');
    Vector<char> C(5, 'B');
    C = B;
    B[0] = 'Z';
    cout << B << endl;
    cout << C << endl;
    
    Vector<int> A;
    A.push_back(10);
    A.push_back(20);
    A.push_back(50);
    cout << A << endl;
    A.pop_back();
    cout << A << endl;
}

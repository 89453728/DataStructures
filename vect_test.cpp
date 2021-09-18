#include "vect.hpp"
#include <iostream>

using namespace yassin;
using namespace std;

int main(){
    int a[1] = {1};
    Vec<int> v(a,1);
    v.push(4);
    v.push(5);
    v.push(4);
    v.print();
    v.push(3);
    v.push(1);
    v.print();
    int k = v.pop();
    cout << "poped element: " << k << endl;
    v.print();
    cout << "elemento 0: "<< v[0] << " elemento 1: "<<v[1] << endl;
    cout << "elemento 12: " << v[12] << " elemento 11: " << v[11] << endl;
    v.print();

    return 0;
}

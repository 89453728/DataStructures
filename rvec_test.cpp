#include "rvec.hpp"
#include <iostream>

using namespace std;
using namespace yassin;

int main(){
    
    int a[2] = {3,2};   
    Rvec<int> v(a,2);

    // add some items
    v.push(10);
    v.push(17);
    v.push(12);
    v.push(0);
    v.push(-1);

    // show all
    v.print();

    // make pop
    int k = v.pop();
    cout << "item deleted: " << k << "\n";
    // check if it was deleted
    v.print();

    cout << "access random: " <<  v[10] << "\n";
    
    k = 0;
    int count = 0;
    while (k!=12){
        count ++;
        k = v[12];
    }

    cout << "element 12 was encountered after "<<count<<" steps\n";
    
    return 0;
}

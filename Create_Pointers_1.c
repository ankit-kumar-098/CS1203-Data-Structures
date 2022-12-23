#include <iostream>
use namespace std;
int main() {
    int x = 9;
    int *y;
    y = &x;
    cout<<y<<endl;
    cout<<*y<<endl;
    cout<<&y<<endl;
    cout<<x<<endl;
    cout<<&x<<endl;

    return 0;
}

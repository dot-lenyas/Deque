#include <iostream>
#include "Deque.h"
using namespace std;
int main()
{
    Deque deque(4);
    deque.push_left(3);
    deque.push_left(2);
    deque.push_right(1);
    cout << deque;
    Deque deque1(2);
    deque1.push_left(4);
    deque1.push_left(5);
    deque = deque1;
    deque.push_left(6);
    deque.push_right(3);
    cout << deque;
    return 0;
}

#include <iostream>
#include "ArrayQueue.hpp"
using namespace std;

int main() {
    ArrayQueue<int> q(4);
    cout << boolalpha << "empty=" << q.isEmpty() << " len=" << q.getLength() << "\n";
    try { q.front(); } catch (const string& e) { cout << e << "\n"; }
    try { q.back(); }  catch (const string& e) { cout << e << "\n"; }

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "front=" << q.front() << " back=" << q.back() << " len=" << q.getLength() << "\n";

    q.dequeue();
    cout << "front=" << q.front() << " back=" << q.back() << " len=" << q.getLength() << "\n";

    q.enqueue(40);
    q.enqueue(50);
    cout << "front=" << q.front() << " back=" << q.back() << " len=" << q.getLength() << " full=" << q.isFull() << "\n";
    try { q.enqueue(60); } catch (const string& e) { cout << e << "\n"; }

    ArrayQueue<int> r(q);
    cout << "copy front=" << r.front() << " back=" << r.back() << " len=" << r.getLength() << "\n";

    r.dequeue();
    r.enqueue(99);
    cout << "r front=" << r.front() << " back=" << r.back() << " len=" << r.getLength() << "\n";
    cout << "q front=" << q.front() << " back=" << q.back() << " len=" << q.getLength() << "\n";

    ArrayQueue<string> s(3);
    s.enqueue("a");
    s.enqueue("b");
    cout << "s front=" << s.front() << " back=" << s.back() << " len=" << s.getLength() << "\n";
    s.dequeue();
    s.enqueue("c");
    cout << "s front=" << s.front() << " back=" << s.back() << " len=" << s.getLength() << "\n";

    q.clear();
    cout << "q cleared empty=" << q.isEmpty() << " len=" << q.getLength() << "\n";
    try { q.dequeue(); } catch (const string& e) { cout << e << "\n"; }
    return 0;
}
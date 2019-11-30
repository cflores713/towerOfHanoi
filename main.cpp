#include <iostream>
#include "graph.h"
using namespace std;

// Function Prototype for H2:
// It is declared so that H1 can use H2 before it is formally defined.
void H2(int n, string a, string b, string c, string d, string e, graph &g);

// Move one space within the cycle
void H1(int n, string a, string b, string c, string d, string e, graph &g){
    if (n){
        g.invoke();
        H2(n-1, a, b, c, d, e, g);
        g.move(a, b);
        H2(n-1, c, a, b, d, e, g);
    }
}

// Move two spaces within the cycle
void H2(int n, string a, string b, string c, string d, string e, graph &g){
    if (n){
        g.invoke();
        H2(n-1, a, b, c, d, e, g);
        g.move(a, b);
        H1(n-1, c, a, b, d, e, g);
        g.move(b, c);
        H2(n-1, a, b, c, d, e, g);
    }
}

// Move three spaces from outside to inside the cycle
void unstack(int n, string a, string b, string c, string d, string e, graph& g){
    if (n){
        g.invoke();
        unstack(n-1, a, b, c, d, e, g);
        g.move(a, b);
        g.move(b, c);
        H1(n-1, d, b, c, a, e, g);
        g.move(c, d);
        H2(n-1, b, c, d, a, e, g);
    }
}

// Move three spaces from inside to outside the cycle
void restack(int n, string a, string b, string c, string d, string e, graph &g){
    if (n){
        g.invoke();
        H2(n-1, b, c, d, e, a, g);
        g.move(b, c);
        H1(n-1, d, b, c, e, a, g);
        g.move(c, d);
        g.move(d, e);
        restack(n-1, a, b, c, d, e, g);
    }
}

// Solve the problem with the helper functions
void H4(int n, string a, string b, string c, string d, string e, graph &g){
    if (n){
        // Move N-1 discs from Start to Aux3
        unstack(n-1, a, b, c, d, e, g);
        
        // Move one disc from Start to Aux2
        g.move(a, b);
        g.move(b, c);
        
        // Move N-1 discs from Aux3 to Aux1
        H1(n-1, d, b, c, a, e, g);
        
        // Move one disc from Aux2 to Dest
        g.move(c, d);
        g.move(d, e);
        
        // Move N-1 discs from Aux1 to Dest
        restack(n-1, a, b, c, d, e, g);
    }
}


int main() {
    int num = 5;
    double animation = 1;
    cout << "Enter the number of disks: " << endl;
    cin >> num;
    cout << "Enter the speed in the animation: " << endl;
    cout << "    (1 is slow and 10 is fast)    " << endl;
    cin >> animation;
    graph test(num, 10-animation);

    H4 (num, "start", "aux1", "aux2","aux3","dest", test);
    test.showStatus();

    return 0;
}

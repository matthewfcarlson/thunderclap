// (clean2) matches/0x001d47c0.cpp with the wrong address in the callee name (0x001d4320 for 0x001d43b0)
#include "gen/owners.h"
void* Alloc(int n);
struct Node {
    Node* Init_001d4320(int a, int b, int c);
};
struct Q_1d47c0 {
    void Add(Node* n);
};
struct Mgr_1d47c0 {};
void Reg(Mgr_1d47c0*, Node*);
void Cb(Mgr_1d47c0*, void (*)(), int);
void Post(Mgr_1d47c0*, int, int);
void Handler();
struct Owner_1d47c0 {
    char pad[8];
    Mgr_1d47c0* mgr;
    Q_1d47c0 q;
    void Fn(int a, int b, int c);
};
void Owner_1d47c0::Fn(int a, int b, int c) {
    Node* p = (Node*)Alloc(0x24);
    Node* n;
    if (p)
        n = p->Init_001d4320(a, b, c);
    else
        n = 0;
    ((owners::CAgent_1d04b0 *)n)->FUN_001d04b0((hulk_intptr)a);
    q.Add(n);
    Mgr_1d47c0* m = mgr;
    Reg(m, n);
    Cb(m, (void (*)())Handler, 1);
    Post(m, -10001, a);
}

#include "compat/ptr.h"
class Node {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Match(int, int);
    virtual int Check(int, int, int);
    Node* next;
    int mode;
};
extern int __cdecl FUN_00238190(int);
extern int __cdecl FUN_00266da0(int);
class Owner_231a40 {
  public:
    char pad[0x28];
    Node* nodes;
    unsigned char Run(int, int);
};
unsigned char Owner_231a40::Run(int a, int b) {
    int t = FUN_00238190(3);
    t = FUN_00266da0(t);
    Node* n = nodes;
    unsigned char result = 0;
    if (n) {
        do {
            if (n->mode == 0) {
                if (n->Match(a, b) == a) {
                    result = 1;
                    break;
                }
            } else if (n->mode == 3) {
                int matched = n->Match(a, b);
                if (matched == a && n->Check((hulk_intptr)this, matched, b) == 0) {
                    result = 1;
                    break;
                }
            }
            n = n->next;
        } while (n);
    }
    FUN_00266da0(t);
    return result;
}
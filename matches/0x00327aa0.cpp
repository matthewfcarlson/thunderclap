#include "decls/data/engine/pure3d.h"
// data: gCounter_327aa0 = DAT_005555b8

typedef unsigned int uint;
class Helper_327aa0 {
  public:
    void run(int);
};
struct Node {
    int key;
    int pad;
    void (Helper_327aa0::*fn)(int);
    int context;
    char pad10[8];
};
class pddiBaseShader_327aa0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual unsigned char f7(int, int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual Node* get();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    char pad4[8];
    int id;
};
unsigned char pddiBaseShader_327aa0::f7(int key, int arg) {
    Node* p = get();
    if (p) {
        while (p->key) {
            if (p->key == key) {
                Helper_327aa0* h = (Helper_327aa0*)((char*)this + p->context);
                (h->*(p->fn))(arg);
                int n = (*(int*)&DAT_005555b8) + 1;
                (*(int*)&DAT_005555b8) = n;
                if (n == -1) {
                    n = 0;
                    (*(int*)&DAT_005555b8) = n;
                }
                id = n;
                ++(*(int*)&DAT_005555b8);
                return 1;
            }
            p++;
        }
    }
    return 0;
}
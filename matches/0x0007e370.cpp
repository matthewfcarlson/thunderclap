#include "decls/data/game/global.h"
// data: keyA = DAT_0048e100, keyB = DAT_0048e0e4

extern "C" unsigned char __cdecl Query(const void*);
class Function_7e370 {
  public:
    Function_7e370(int, int);
    virtual void f();
    char pad[12];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Function_7e370 {
  public:
    Method1(int n, int xx) : Function_7e370(n, 1) {
        x = xx;
        a = Query(((int*)&DAT_0048e100));
        b = Query(((int*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int n, int xx, int yy);
    virtual void f();
};
Closure1::Closure1(int n, int xx, int yy) : Method1(n, yy) {
    y = xx;
}
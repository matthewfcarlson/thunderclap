#include "decls/data/game/global.h"
// data: gValue = DAT_0048e0e4

extern "C" unsigned char getFlag(void*);
class Function_1f7eb0 {
  public:
    Function_1f7eb0(int, int);
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Function_1f7eb0 {
  public:
    Method1(int p, int q) : Function_1f7eb0(p, 1) {
        x = q;
        b = getFlag(((int*)&DAT_0048e0e4));
        a = getFlag(((int*)&DAT_0048e0e4));
    }
    virtual void fn();
};
class Closure1 : public Method1 {
  public:
    Closure1(int p, int q, int r);
    virtual void fn();
};
Closure1::Closure1(int p, int q, int r) : Method1(p, r) {
    y = q;
}

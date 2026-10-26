#include "decls/data/game/global.h"
// data: nameA = DAT_0048e100, nameB = DAT_0048e0f0

extern char __cdecl lookup(const char*);
class Function_9cd10 {
  public:
    Function_9cd10(const char*, int);
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int p;
};
class Method1 : public Function_9cd10 {
  public:
    Method1(const char* n, int p) : Function_9cd10(n, 1) {
        this->p = p;
        b = lookup(((char*)&DAT_0048e100));
        a = lookup(((char*)&DAT_0048e0f0));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, int, int);
    virtual void f();
    int q;
};
Closure1::Closure1(const char* n, int q, int p) : Method1(n, p) {
    this->q = q;
}

#include "decls/data/game/global.h"

char __cdecl lookup(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    char x;
    char pad2[7];
    char y;
    char pad3[3];
};
class Closure1_1ce290 : public Base {
  public:
    Closure1_1ce290(void*, void*);
    virtual void f();
    void* arg;
};
class Closure1 : public Closure1_1ce290 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* extra;
};
Closure1::Closure1(void* p, void* q, void* r) : Closure1_1ce290(p, r) {
    extra = q;
}
Closure1_1ce290::Closure1_1ce290(void* p, void* q) : Base(p, 1) {
    arg = q;
    y = lookup(((char*)&DAT_0048e100));
    x = lookup(((char*)&DAT_0048e0e4));
}

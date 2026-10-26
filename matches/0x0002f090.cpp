#include "decls/data/game/global.h"

extern char a[];
extern "C" unsigned char __cdecl lookup(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    unsigned char flag10;
    char pad2[7];
    unsigned char flag18;
    char pad3[3];
    void* value;
};
class Closure1_2f090 : public Base {
  public:
    Closure1_2f090(void*, void*);
    virtual void f();
};
class Closure1 : public Closure1_2f090 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* other;
};
Closure1_2f090::Closure1_2f090(void* p, void* v) : Base(p, 1) {
    value = v;
    flag18 = lookup(a);
    flag10 = lookup(((char*)&DAT_0048e0f0));
}
Closure1::Closure1(void* p, void* v, void* q) : Closure1_2f090(p, q) {
    other = v;
}
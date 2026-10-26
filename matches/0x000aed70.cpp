#include "decls/data/game/global.h"

extern "C" unsigned char ReadFlag(const char*);
class Function_aed70 {
  public:
    Function_aed70(void*, int);
    virtual void v();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    void* p;
    void* q;
};
class Method1_aed70 : public Function_aed70 {
  public:
    Method1_aed70(void* a, void* c) : Function_aed70(a, 1) {
        p = c;
        y = ReadFlag(((const char*)&DAT_0048e100));
        x = ReadFlag(((const char*)&DAT_0048e0e4));
    }
    virtual void v();
};
class Closure1_aed70 : public Method1_aed70 {
  public:
    Closure1_aed70(void*, void*, void*);
    virtual void v();
    virtual void v2();
};
Closure1_aed70::Closure1_aed70(void* a, void* b, void* c) : Method1_aed70(a, c) {
    q = b;
}
#include "decls/data/game/global.h"
// data: keyA = DAT_0048e100, keyB = DAT_0048e0f0

extern "C" unsigned char __cdecl Lookup(const char*);
class Function_1ea3b0 {
  public:
    virtual void Invoke(const char*);
    Function_1ea3b0(const char*, int);
    char pad[12];
    unsigned char flagB;
    char pad2[7];
    unsigned char flagA;
    char pad3[3];
    void* member;
};
class Method1 : public Function_1ea3b0 {
  public:
    virtual void Invoke(const char*);
    Method1(const char* s, void* p) : Function_1ea3b0(s, 1) {
        member = p;
        flagA = Lookup(((const char*)&DAT_0048e100));
        flagB = Lookup(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(const char*);
    void* extra;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* x, void* p) : Method1(s, p) {
    extra = x;
}
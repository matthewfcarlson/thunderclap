#include "decls/data/game/global.h"
// data: name1 = DAT_0048e0e4, name2 = DAT_0048e0f0

typedef unsigned int uint;
extern "C" unsigned char parse(const char*);
class Function_1cbd90 {
  public:
    Function_1cbd90(void*, int);
    virtual void f();
};
class Method1 : public Function_1cbd90 {
  public:
    char pad[12];
    unsigned char a;
    char gap[7];
    unsigned char b;
    char gap2[3];
    void* m;
    Method1(void* p, void* v) : Function_1cbd90(p, 1) {
        m = v;
        b = parse((const char*)&(*(const char**)&DAT_0048e0e4));
        a = parse((const char*)&(*(const char**)&DAT_0048e0f0));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    void* n;
    Closure1(void* p, void* q, void* v);
    virtual void f();
};
Closure1::Closure1(void* p, void* q, void* v) : Method1(p, v) {
    n = q;
}

#include "decls/data/game/global.h"
// data: gName = DAT_0048e0f0

extern unsigned char __cdecl GetFlag(const char*);
class Function_200440 {
  public:
    Function_200440(const char*, int);
    virtual void Fn();
    char pad[0xc];
};
class Method1 : public Function_200440 {
  public:
    Method1(const char* s, const char* t) : Function_200440(s, 1) {
        m = t;
        a = GetFlag(((char*)&DAT_0048e0f0));
        b = GetFlag(((char*)&DAT_0048e0f0));
    }
    virtual void Fn();
    char b;
    char pad2[7];
    char a;
    char pad3[3];
    const char* m;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, const char* t, const char* u);
    virtual void Fn();
    const char* n;
};
Closure1::Closure1(const char* s, const char* t, const char* u) : Method1(s, u) {
    n = t;
}

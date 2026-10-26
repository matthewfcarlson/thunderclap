#include "decls/data/game/global.h"

extern "C" unsigned char __cdecl Check(const void*);
class Function_8e750 {
  public:
    Function_8e750(const char*, int);
    virtual void fn();
    char pad[0xc];
    unsigned char flag;
    char pad2[7];
};
class Method1_8e750 : public Function_8e750 {
  public:
    Method1_8e750(const char* s, void* p) : Function_8e750(s, 1) {
        value = p;
        flag2 = Check(((char*)&DAT_0048e100));
        flag = Check(((char*)&DAT_0048e0f0));
    }
    virtual void fn();
    unsigned char flag2;
    char pad3[3];
    void* value;
};
class Closure1_8e750 : public Method1_8e750 {
  public:
    Closure1_8e750(const char* s, void* x, void* p);
    virtual void fn();
    void* extra;
};
Closure1_8e750::Closure1_8e750(const char* s, void* x, void* p) : Method1_8e750(s, p) {
    extra = x;
}
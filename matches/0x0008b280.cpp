#include "decls/data/game/global.h"
// data: gName1 = DAT_0048e0e4, gName2 = DAT_0048e0f0

unsigned char Find(const char*);
class Function_8b280 {
  public:
    virtual void Invoke();
    Function_8b280(const char*, int);
    char pad[0xc];
    unsigned char flag2;
    char pad2[7];
    unsigned char flag1;
    char pad3[3];
    void* target;
    void* extra;
};
class Method1_8b280 : public Function_8b280 {
  public:
    virtual void Invoke();
    Method1_8b280(const char* n, void* m) : Function_8b280(n, 1) {
        target = m;
        flag1 = Find(((const char*)&DAT_0048e0e4));
        flag2 = Find(((const char*)&DAT_0048e0f0));
    }
};
class Closure1_8b280 : public Method1_8b280 {
  public:
    virtual void Invoke();
    Closure1_8b280(const char*, void*, void*);
};
Closure1_8b280::Closure1_8b280(const char* name, void* ctx, void* method) : Method1_8b280(name, method) {
    extra = ctx;
}

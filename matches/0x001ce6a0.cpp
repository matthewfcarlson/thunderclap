#include "decls/data/game/global.h"

struct Item {
    int x;
};
extern "C" unsigned char check(Item*);
class Function_1ce6a0 {
  public:
    Function_1ce6a0(const char*, int);
    virtual void invoke();
    char pad[12];
    unsigned char f10;
    char pad2[7];
    unsigned char f18;
    char pad3[3];
    void* target;
};
class Method1_1ce6a0 : public Function_1ce6a0 {
  public:
    Method1_1ce6a0(const char*, void*);
    virtual void invoke();
};
inline Method1_1ce6a0::Method1_1ce6a0(const char* name, void* a) : Function_1ce6a0(name, 1) {
    target = a;
    f18 = check(((Item*)&DAT_0048e100));
    f10 = check(((Item*)&DAT_0048e0f0));
}
class Closure1_1ce6a0 : public Method1_1ce6a0 {
  public:
    Closure1_1ce6a0(const char*, void*, void*);
    virtual void invoke();
    void* arg;
};
Closure1_1ce6a0::Closure1_1ce6a0(const char* name, void* p, void* a) : Method1_1ce6a0(name, a) {
    arg = p;
}
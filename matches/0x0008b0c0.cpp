#include "decls/data/game/global.h"

int GetValue(int*);
class Base {
  public:
    Base(const char*, int);
    virtual void Run();
    char pad[12];
};
class Method : public Base {
  public:
    Method(const char*, int);
    virtual void Run();
    char a;
    char pad3[7];
    char b;
    char pad4[3];
    int value;
};
class Closure1_8b0c0 : public Method {
  public:
    Closure1_8b0c0(const char*, int, int);
    virtual void Run();
    int extra;
};
Method::Method(const char* name, int v) : Base(name, 1) {
    value = v;
    b = GetValue(((int*)&DAT_0048e100));
    a = GetValue(((int*)&DAT_0048e0f0));
}
Closure1_8b0c0::Closure1_8b0c0(const char* name, int v, int w) : Method(name, w) {
    extra = v;
}

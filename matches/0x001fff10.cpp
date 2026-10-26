#include "decls/address.h"
#include "decls/data/game/global.h"
class Function_1fff10 {
  public:
    Function_1fff10(const char*, int);
    virtual void Run();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int v;
    int w;
};
class Method1 : public Function_1fff10 {
  public:
    Method1(const char* s, int x, int y) : Function_1fff10(s, 1) {
        v = y;
        b = FUN_001d04d0(((char*)&DAT_0048e100));
        a = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    virtual void Run();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, int x, int y);
    virtual void Run();
};
Closure1::Closure1(const char* s, int x, int y) : Method1(s, x, y) {
    w = x;
}

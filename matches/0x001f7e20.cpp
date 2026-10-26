#include "decls/data/game/global.h"
// data: name1 = DAT_0049b95c, name2 = DAT_0049cad8

extern unsigned char __cdecl find(char*);
class Function_1f7e20 {
  public:
    Function_1f7e20(char*, int);
    virtual void f();
};
class Method1 : public Function_1f7e20 {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    unsigned int x;
    Method1(char* p, unsigned int n) : Function_1f7e20(p, 1) {
        x = n;
        b = find(((char*)&DAT_0049b95c));
        a = find(((char*)&DAT_0049cad8));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    unsigned int y;
    Closure1(char* p, unsigned int n, unsigned int m);
    virtual void f();
};
Closure1::Closure1(char* p, unsigned int n, unsigned int m) : Method1(p, m) {
    y = n;
}

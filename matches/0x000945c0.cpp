#include "decls/data/game/global.h"

class Parent {
  public:
    Parent(int, int);
    virtual void f();
    char p[12];
};
class Closure1_945c0 : public Parent {
  public:
    Closure1_945c0(int a, int b);
    virtual void f();
    char x;
    char pad2[7];
    char y;
    char pad3[3];
    int n;
};
class Closure1 : public Closure1_945c0 {
  public:
    Closure1(int a, int b, int c);
    virtual void f();
    int m;
};
extern char Get(const char*);
Closure1_945c0::Closure1_945c0(int a, int b) : Parent(a, 1) {
    n = b;
    y = Get(((const char*)&DAT_0048e0e4));
    x = Get(((const char*)&DAT_0048e134));
}
Closure1::Closure1(int a, int b, int c) : Closure1_945c0(a, c) {
    m = b;
}
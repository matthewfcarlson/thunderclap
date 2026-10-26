#include "decls/data/game/global.h"
// data: tag1 = DAT_004c5d10, tag2 = DAT_0048e0f0

class Root {
  public:
    Root(const char*, int);
    virtual void f();
    char pad[12];
    char a;
    char p1[7];
    char b;
    char p2[3];
    int x;
};
extern int check(const char*);
class Closure1_1d4320 : public Root {
  public:
    Closure1_1d4320(const char*, int, int);
    virtual void f();
};
class Closure1 : public Closure1_1d4320 {
  public:
    Closure1(const char*, int, int);
    virtual void f();
    int y;
};
Closure1_1d4320::Closure1_1d4320(const char* s, int x0, int x1) : Root(s, 1) {
    x = x1;
    b = check(((const char*)&DAT_004c5d10));
    a = check(((const char*)&DAT_0048e0f0));
}
Closure1::Closure1(const char* s, int x0, int x1) : Closure1_1d4320(s, x0, x1) {
    y = x0;
}
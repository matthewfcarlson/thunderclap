#include "decls/data/game/global.h"

class CSPManager;
class Function_1e0650 {
  public:
    virtual void basefn();
    Function_1e0650(const char*, int);
};
class Method3 : public Function_1e0650 {
  public:
    virtual void dummy();
    Method3(const char*, void*);
    char pad[0x0c];
    char a, b, c;
    char pad2[5];
    char d;
    char pad3[3];
    void* x;
};
extern const char n3[];
extern char fun(const char*);
Method3::Method3(const char* s, void* p) : Function_1e0650(s, 3) {
    x = p;
    d = fun(((const char*)&DAT_0048e100));
    a = fun(((const char*)&DAT_0048e0f0));
    b = fun(((const char*)&DAT_0048e0f0));
    c = fun(n3);
}
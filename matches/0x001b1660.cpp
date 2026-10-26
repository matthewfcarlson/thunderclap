#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: strA = DAT_0048e100, strB = DAT_0048e0f0, strC = DAT_0048e128

char __cdecl GetFlag(const char*);
class Function_1b1660 {
  public:
    virtual void f();
    Function_1b1660(void*, int);
    char pad[20];
};
class Function2 : public Function_1b1660 {
  public:
    virtual void g();
    Function2(void*, void*);
    char flag18[4];
    void* target;
};
Function2::Function2(void* a, void* b) : Function_1b1660(a, 2) {
    target = b;
    flag18[0] = GetFlag(((const char*)&DAT_0048e100));
    ((char*)this)[0x10] = GetFlag(((const char*)&DAT_0048e0f0));
    ((char*)this)[0x11] = GetFlag(((const char*)&DAT_0048e128));
}

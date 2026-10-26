#include "decls/data/engine/content.h"
#include "decls/data/engine/unknown.h"
// data: gCallback_266eb0 = DAT_00527f64, gContext = DAT_00527f68, gEntries_266eb0 = DAT_00527c60

class Entry_266eb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Get(int, int);
};
struct Slot_266eb0 {
    Entry_266eb0* p;
    char pad[12];
};
typedef int(__cdecl* Callback_266eb0)(int, int, int, int);
int Func(int a, int b, int c) {
    int r = ((Slot_266eb0*)((char*)&DAT_00527c58 + 8))[a].p->Get(b, c);
    if (r == 0 && (*(Callback_266eb0*)&DAT_00527f64))
        (*(Callback_266eb0*)&DAT_00527f64)((*(int*)&DAT_00527f68), a, b, c);
    return r;
}
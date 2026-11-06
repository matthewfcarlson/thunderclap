#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
// data: gCallback_266eb0 = DAT_00527f64, gContext = DAT_00527f68

class Entry_266eb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void* Get(int, int);
};
typedef int(__cdecl* Callback_266eb0)(int, int, int, int);
extern "C" void* FUN_00266eb0(int a, int b, int c) {
    void* r = ((Entry_266eb0*)DAT_00527c60[a].allocator)->Get(b, c);
    if (r == 0 && (*(Callback_266eb0*)&DAT_00527f64))
        (*(Callback_266eb0*)&DAT_00527f64)((*(int*)&DAT_00527f68), a, b, c);
    return r;
}

#include "decls/data/engine/unknown.h"
#include "decls/data/records.h"
// data: gCallback_266e00 = DAT_00527f64, gContext = DAT_00527f68

class Item_266e00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* Get(int);
};
typedef int(__cdecl* Callback_266e00)(int, int, int, int);
extern "C" void* FUN_00266e00(int a, int b) {
    void* r = ((Item_266e00*)DAT_00527c60[a].allocator)->Get(b);
    if (!r && (*(Callback_266e00*)&DAT_00527f64))
        (*(Callback_266e00*)&DAT_00527f64)((*(int*)&DAT_00527f68), a, b, 1);
    return r;
}

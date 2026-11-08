extern "C" void _ReadWriteBarrier();
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
extern void* g_vftable_1d3410;
class Item_1d3410 {
  public:
    virtual void Release(int);
};
class ScriptHandler {
  public:
    void* vptr;
    char pad[4];
    LuaVMState* p8;  // 0x08
    Item_1d3410* items[1024];
    int count;
    ~ScriptHandler();
};
ScriptHandler::~ScriptHandler() {
    vptr = &g_vftable_1d3410;
    _ReadWriteBarrier();
    if (p8) {
        FUN_002151e0(p8);
        p8 = 0;
    }
    for (int i = 0; i < count; ++i) {
        Item_1d3410* p = items[i];
        if (p)
            p->Release(1);
    }
    count = 0;
}

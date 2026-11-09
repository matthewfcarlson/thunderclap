extern "C" void _ReadWriteBarrier();
#include "decls/data/script.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
extern void* g_vftable_1d3410;
class Item_1d3410 {
  public:
    virtual void Release(int);
};
// ScriptHandler's destructor (include/decls/data/script.h ScriptHandlerFields): closes the Lua state and releases
// every registered Function.
class ScriptHandler : public ScriptHandlerView {
  public:
    ~ScriptHandler();
};
ScriptHandler::~ScriptHandler() {
    vftable = &g_vftable_1d3410;
    _ReadWriteBarrier();
    if (f.L) {
        FUN_002151e0(f.L);
        f.L = 0;
    }
    for (int i = 0; i < f.functions.count; ++i) {
        Item_1d3410* p = (Item_1d3410*)f.functions.items[i];
        if (p)
            p->Release(1);
    }
    f.functions.count = 0;
}

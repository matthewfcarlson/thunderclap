// method.cpp rewritten against the generated headers (include/gen/). Verify with:
//   build/venv/bin/python tools/compare.py experiments/first-matches/method_gen.cpp 0x2cf30 Method0@VCActorManager@@H
//   build/venv/bin/python tools/compare.py experiments/first-matches/method_gen.cpp 0x2ce30 Method1@VCActorManager@@XPBD
#include <gen/global.h>

// CActorManager has no RTTI, so the headers only forward-declare it. Completing it here
// fixes the member-pointer representation (single inheritance, 4 bytes).
class CActorManager {
public:
    int GetCount();
    void Spawn(const char* name);
};

// FUNCTION: 0x0002cf30 (Method0<CActorManager,int>::vfunc_2) -- Invoke
template <>
void Method0<CActorManager, int>::vfunc_2(void* object, void* args, void* result) {
    int (CActorManager::*fn)() = f_1c;
    int r = (static_cast<CActorManager*>(object)->*fn)();
    if (result) *static_cast<int*>(result) = r;
}

// FUNCTION: 0x0002ce30 (Method1<CActorManager,void,const char*>::vfunc_2) -- Invoke
template <>
void Method1<CActorManager, void, const char*>::vfunc_2(void* object, void* args, void* result) {
    (static_cast<CActorManager*>(object)->*f_1c)(*static_cast<const char**>(args));
}

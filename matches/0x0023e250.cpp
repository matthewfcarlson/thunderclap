#include "compat/ptr.h"
#include "decls/data/engine/fight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* operator new(unsigned int, void* p) {
    return p;
}
void __cdecl FUN_0023df40();
void __cdecl FUN_0023df60();
void __cdecl FUN_0023df80();
struct FUN_00234960 {
    virtual void placeholder();
    char data[12];
    void(__cdecl* callback)();
    char tail[4];
    FUN_00234960(const char*);
};
namespace fight {
class WaitTrack;
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    ParamFloatConstRange(const char* s, void(__cdecl* f)()) : FUN_00234960(s) { callback = f; }
    virtual void placeholder();
};
} // namespace fight
void __cdecl FUN_002347b0(int*, FUN_00234960**, int);
void target() {
    if (!DAT_004e5c70) {
        FUN_00234960* items[3];
        void* mem = FUN_0008d690(24);
        items[0] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeBegin", FUN_0023df40) : 0;
        mem = FUN_0008d690(24);
        items[1] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeEndMin", FUN_0023df60) : 0;
        mem = FUN_0008d690(24);
        items[2] =
            mem ? new (mem) fight::ParamFloatConstRange<fight::WaitTrack>("timeEndMax", FUN_0023df80) : 0;
        FUN_002347b0(&DAT_004e5c6c, items, 3);
    }
    ++DAT_004e5c70;
}
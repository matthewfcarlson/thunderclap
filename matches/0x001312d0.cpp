#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
void FUN_0012dfe0();
void FUN_0012e2c0();
void FUN_0012e320();
struct FUN_002349e0 {
    virtual void slot0();
    char pad[12];
    void (*callback)();
    int tail;
    FUN_002349e0(const char*);
};
struct FUN_00234cc0 {
    virtual void slot0();
    char pad[12];
    int* list;
    int count;
    void (*callback)();
    int tail;
    FUN_00234cc0(const char*);
};
namespace hulkfight {
class MissionProgressCondition;
}
namespace fight {
template <class T> struct ParamString : FUN_002349e0 {
    virtual void slot0();
    ParamString(const char* s, void (*f)()) : FUN_002349e0(s) { callback = f; }
};
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    ParamEnumConstList(const char* s, int n) : FUN_00234cc0(s) {
        count = n;
        list = ((int*)&DAT_00427758);
        callback = FUN_0012dfe0;
    }
};
} // namespace fight
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
    if (!DAT_004e0e50) {
        void* params[3];
        typedef fight::ParamString<hulkfight::MissionProgressCondition> S;
        typedef fight::ParamEnumConstList<hulkfight::MissionProgressCondition> E;
        void* p = FUN_0008d690(24);
        params[0] = p ? new (p) S("mission", FUN_0012e2c0) : 0;
        p = FUN_0008d690(32);
        params[1] = p ? new (p) E("compare", (*(int*)&DAT_00427760)) : 0;
        p = FUN_0008d690(24);
        params[2] = p ? new (p) S("progress", FUN_0012e320) : 0;
        FUN_002347b0(&DAT_004e0e4c, params, 3);
    }
    ++DAT_004e0e50;
}

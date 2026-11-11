// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00054240 FUN_00054240 (192 B): matches/0x00054240.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00054240
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace fn_f089f8b4 {} using namespace fn_f089f8b4;
namespace fn_f089f8b4 {


} // namespace fn_f089f8b4
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_f089f8b4 {

extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl SetCompare_000480e0();
extern "C" void __cdecl SetStatus_000480f0();
struct Base_54240 {
    virtual void slot0();
    char padding[12];
    void FUN_00234cc0(const char*);
};
class CAlertStatusCondition;
namespace fight {
template <class T> struct ParamEnumConstList : Base_54240 {
    virtual void slot0();
    void* list;
    int count;
    void(__cdecl* callback)();
    int extra;
};
} // namespace fight
typedef fight::ParamEnumConstList<CAlertStatusCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Base_54240**, int);
extern "C" void FUN_00054240() {
    if ((*(int*)&DAT_004dc53c) == 0) {
        Base_54240* entries[2];
        void* mem = FUN_0008d690((int)sizeof(Param));
        if (mem) {
            int count = (*(int*)&DAT_00427760);
            ((Base_54240*)mem)->FUN_00234cc0("compare");
            Param* p = new (mem) Param;
            p->list = ((char*)&DAT_00427758);
            p->count = count;
            p->callback = SetCompare_000480e0;
            entries[0] = p;
        } else
            entries[0] = 0;
        mem = FUN_0008d690((int)sizeof(Param));
        if (mem) {
            int count = (*(int*)&DAT_0040d0e4);
            ((Base_54240*)mem)->FUN_00234cc0("status");
            Param* p = new (mem) Param;
            p->list = ((char*)&DAT_004a1ab4);
            p->count = count;
            p->callback = SetStatus_000480f0;
            entries[1] = p;
        } else
            entries[1] = 0;
        FUN_002347b0(((int*)&DAT_004dc538), entries, 2);
    }
    ++(*(int*)&DAT_004dc53c);
}
} // namespace fn_f089f8b4


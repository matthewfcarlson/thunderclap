// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00053fe0 FUN_00053fe0 (192 B): matches/0x00053fe0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00053fe0
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_fc7522f5 {} using namespace fn_fc7522f5;
namespace fn_fc7522f5 {


} // namespace fn_fc7522f5
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_fc7522f5 {

extern void* __cdecl FUN_0008d690(unsigned int);
extern char SetCompare_00048040(void*, int); /* (unb4) as defined; address taken only */
extern char SetMotionState_00048050(void*, int); /* (unb4) as defined; address taken only */
struct Base_53fe0 {
    virtual void slot0();
    char pad[12];
    void FUN_00234cc0(const char*);
};
namespace fight {
template <class T> struct ParamEnumConstList : Base_53fe0 {
    virtual void slot0();
    void* values;
    unsigned int count;
    void(__cdecl* callback)();
    unsigned int tail;
};
} // namespace fight
class CMotionStateCondition;
extern void __cdecl FUN_002347b0(void*, Base_53fe0**, int);
extern "C" void __cdecl FUN_00053fe0() {
    if (!DAT_004dc524) {
        Base_53fe0* items[2];
        void* p = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CMotionStateCondition>));
        if (p) {
            unsigned int count = (*(unsigned int*)&DAT_00427760);
            Base_53fe0* b = (Base_53fe0*)p;
            b->FUN_00234cc0("compare");
            fight::ParamEnumConstList<CMotionStateCondition>* q =
                new (p) fight::ParamEnumConstList<CMotionStateCondition>;
            q->values = ((unsigned char*)&DAT_00427758);
            q->count = count;
            q->callback = (void (*)())SetCompare_00048040;
            items[0] = q;
        } else
            items[0] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CMotionStateCondition>));
        if (p) {
            unsigned int count = (*(unsigned int*)&DAT_003f5bb8);
            Base_53fe0* b = (Base_53fe0*)p;
            b->FUN_00234cc0("motionState");
            fight::ParamEnumConstList<CMotionStateCondition>* q =
                new (p) fight::ParamEnumConstList<CMotionStateCondition>;
            q->values = ((unsigned char*)&DAT_0048f57c);
            q->count = count;
            q->callback = (void (*)())SetMotionState_00048050;
            items[1] = q;
        } else
            items[1] = 0;
        FUN_002347b0(((unsigned char*)&DAT_004dc520), items, 2);
    }
    ++DAT_004dc524;
}
} // namespace fn_fc7522f5


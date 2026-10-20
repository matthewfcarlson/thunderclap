#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_00048040();
extern void __cdecl FUN_00048050();
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
void __cdecl FUN_00053fe0() {
    if (!DAT_004dc524) {
        Base_53fe0* items[2];
        void* p = FUN_0008d690(32);
        if (p) {
            unsigned int count = (*(unsigned int*)&DAT_00427760);
            Base_53fe0* b = (Base_53fe0*)p;
            b->FUN_00234cc0("compare");
            fight::ParamEnumConstList<CMotionStateCondition>* q =
                new (p) fight::ParamEnumConstList<CMotionStateCondition>;
            q->values = ((unsigned char*)&DAT_00427758);
            q->count = count;
            q->callback = FUN_00048040;
            items[0] = q;
        } else
            items[0] = 0;
        p = FUN_0008d690(32);
        if (p) {
            unsigned int count = (*(unsigned int*)&DAT_003f5bb8);
            Base_53fe0* b = (Base_53fe0*)p;
            b->FUN_00234cc0("motionState");
            fight::ParamEnumConstList<CMotionStateCondition>* q =
                new (p) fight::ParamEnumConstList<CMotionStateCondition>;
            q->values = ((unsigned char*)&DAT_0048f57c);
            q->count = count;
            q->callback = FUN_00048050;
            items[1] = q;
        } else
            items[1] = 0;
        FUN_002347b0(((unsigned char*)&DAT_004dc520), items, 2);
    }
    ++DAT_004dc524;
}
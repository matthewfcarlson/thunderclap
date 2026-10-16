#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

void* __cdecl operator new(unsigned int) throw();
void FUN_00047c80();
void FUN_00047c90();
struct FUN_00234cc0 {
    FUN_00234cc0(const char*) throw();
    virtual void slot0();
    char padding[12];
};
namespace fight {
class CCollisionHitLocationCondition;
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
    const char* values;
    int count;
    void (*callback)();
    int tail;
    ParamEnumConstList(const char* name, const char* v, int n, void (*cb)()) throw() : FUN_00234cc0(name) {
        values = v;
        count = n;
        callback = cb;
    }
};
} // namespace fight
void __cdecl FUN_002347b0(void*, void*, int);
void __cdecl FUN_000532e0() {
    if (!DAT_004dc454) {
        typedef fight::ParamEnumConstList<fight::CCollisionHitLocationCondition> Param;
        Param* entries[2];
        entries[0] = new Param("compare", ((char*)&DAT_0042773c), (*(int*)&DAT_00427754), FUN_00047c80);
        entries[1] = new Param("hitLocation", DAT_0048f6cc, (*(int*)&DAT_003f5ed0), FUN_00047c90);
        FUN_002347b0(((int*)&DAT_004dc450), entries, 2);
    }
    ++DAT_004dc454;
}
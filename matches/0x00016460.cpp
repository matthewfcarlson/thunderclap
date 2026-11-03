#include "gen/global.h"
#include "gen/owners.h"

class CAction_16460 {
    char pad[0x1c];
};
struct HelperA_16460 {
    char pad[0x1c];
    char* g();
};

void CSmartPropThrowingAction::vfunc_4() {
    HelperA_16460* p = *(HelperA_16460**)((char*)this + 0x1c);
    p = ((HelperA_16460 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    char* q = p->g();
    q[0x1f51] = 0;
}

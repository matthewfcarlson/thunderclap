// Same code shape as 0x00025370 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
struct Ctx_253c0 {
    int pad[17];
};
struct Act_253c0 {
    int pad;
    void Do(int);
};
void owners::Target_253c0::FUN_000253c0(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_253c0* c = (Ctx_253c0*)vt[17];
        hulk_intptr r = ((int)((owners::ThisWrap_00059c10 *)c)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (r)
            ((Act_253c0*)r)->Do(arg);
        ++i;
    }
}

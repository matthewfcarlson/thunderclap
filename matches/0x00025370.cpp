#include "compat/ptr.h"
#include "gen/owners.h"
struct Ctx_25370 {
    int pad[17];
};
struct Act_25370 {
    int pad;
    void Do(int);
};
void owners::Target_25370::FUN_00025370(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_25370* c = (Ctx_25370*)vt[17];
        hulk_intptr r = ((int)((owners::ThisWrap_00059c10 *)c)->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
        if (r)
            ((Act_25370*)r)->Do(arg);
        ++i;
    }
}

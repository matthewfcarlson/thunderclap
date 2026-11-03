#include "compat/ptr.h"
#include "gen/owners.h"
struct X_25260 {
};
struct Y_25260 {
    void Use(int);
};
void owners::C_25260::FUN_00025260(int arg, int, int) {
    int i = 0;
    if (count > 0) {
        do {
            void* p = ((void**)v)[17];
            hulk_intptr x = ((int)((owners::ThisWrap_00059c10 *)(((X_25260*)p)))->FUN_00059c10((void *)(hulk_uintptr)(int)(items[i])));
            if (x)
                ((Y_25260*)x)->Use(arg);
            ++i;
        } while (i < count);
    }
}

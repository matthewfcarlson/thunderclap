#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" char DAT_00429434[];
struct Helper_24dce0 {
    void init(void*, void*, int, int);
    void fini();
};
extern int __cdecl F247530(void*);
int __cdecl target() {
    char local[0x48];
    ((Helper_24dce0*)local)->init((void*)((hulk_intptr)DAT_004e6328), (void*)((hulk_intptr)DAT_004e6320), 0x30, 4);
    *(void**)local = (void*)((hulk_intptr)DAT_00429434);
    int result = F247530(local);
    ((Helper_24dce0*)local)->fini();
    return result;
}
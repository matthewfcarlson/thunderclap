#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_004246cc[];
struct Function_1f0af0 {
    hulk_uintptr vt;
    void Init(void*, int);
};
struct Method3_1f0af0 : Function_1f0af0 {
    char pad04[0x0c];
    char m10;
    char m11;
    char m12;
    char pad13[5];
    char m18;
    char pad19[3];
    void* m1c;
    Method3_1f0af0* Run(void*, void*);
};
Method3_1f0af0* Method3_1f0af0::Run(void* a, void* b) {
    Init(a, 3);
    vt = ((hulk_intptr)DAT_004246cc);
    m1c = b;
    m18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0049cad8)));
    m12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}
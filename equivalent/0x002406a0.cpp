// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 6/6)
// FUN_002406a0 @ 0x002406a0
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

void __cdecl FUN_00247570(void* p);
struct Str_2406a0 {
    char* p;
    unsigned short kind;
    char pad6[6];
    Str_2406a0* FUN_002406a0(Str_2406a0* ret, const void* rhs);
};
Str_2406a0* Str_2406a0::FUN_002406a0(Str_2406a0* ret, const void* rhs) {
    Str_2406a0 tmp;
    ((owners::Handle_240090 *)&tmp)->FUN_00240090((const owners::Handle_240090 *)(const Str_2406a0 *)this);
    ((owners::String_23ff50 *)&tmp)->FUN_0023ff50((owners::String_23ff50 *)rhs);
    ((owners::Handle_240090 *)ret)->FUN_00240090((const owners::Handle_240090 *)(const Str_2406a0 *)(&tmp));
    if (tmp.kind == 2) {
        char* data = tmp.p;
        if (*(unsigned short*)(data - 4) == 1) {
            if (data != (*(const char**)&DAT_004cc02c))
                FUN_00247570(data - 8);
        } else {
            (*(unsigned short*)(data - 4))--;
        }
    }
    return ret;
}

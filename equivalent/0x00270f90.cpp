// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 12/12)
// FUN_00270f90 @ 0x00270f90
#include "decls/data/engine/unknown.h"

struct Resource_270f90 {
    virtual void unused();
    virtual void release();
    char FUN_00272b80();
};
struct Entry_270f90 { Resource_270f90 *resource; char rest[0x118]; };
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
void __cdecl FUN_0026d6d0(int);
void __cdecl thunk_FUN_00270a50();
// equiv-conv: FUN_00270980 eax
void FUN_00270980(char *);
int __cdecl FUN_00270c10(const char *);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);

bool __cdecl FUN_00270f90(const char *name) {
    char buffer[17];
    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    if (name) {
        strncpy(buffer, name, 16);
        buffer[16] = 0;
        FUN_00270980(buffer);
    } else {
        int i = 0;
        char c;
        do {
            c = DAT_0052a10c[i];
            buffer[i++] = c;
        } while (c);
    }
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        return false;
    }
    Resource_270f90 *resource = ((Entry_270f90*)&DAT_0052842c)[index].resource;
    if (!resource) {
        FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        return false;
    }
    ((Entry_270f90*)&DAT_0052842c)[index].resource = 0;
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
    while (resource->FUN_00272b80()) {
        thunk_FUN_00270a50();
        FUN_0026d6d0(0);
    }
    resource->release();
    return true;
}

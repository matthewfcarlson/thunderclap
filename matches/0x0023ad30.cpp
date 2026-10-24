#include "gen/fight.h"

#include "compat/ptr.h"
extern void __cdecl FUN_00267880(char*, hulk_intptr, int);

bool fight::ScriptReader::FUN_0023ad30(int index, char* out, int arg) {
    if (index < 0 || index >= this->f_12c)
        return false;
    int* status = (int*)((char*)this + (index * 3 + 0x27) * 8);
    if (*status != 4)
        return false;
    if (out) {
        *out = 0;
        hulk_intptr p = *(int*)((char*)this + 0x13c + index * 24);
        while (p) {
            FUN_00267880(out, p, arg);
            p = *(int*)(p + 0x100);
        }
    }
    return true;
}

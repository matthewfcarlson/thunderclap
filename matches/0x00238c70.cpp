#include "gen/fight.h"

#include "compat/ptr.h"
class Action_238c70 {
    char pad[0x1c];
};
class NonCopyable_238c70 {};
class IRefCount_238c70 {};
extern int FUN_00238bb0(int, int, const char*, int);
const char formatString_238c70[] = "%s\n";

bool fight::PrintAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    hulk_intptr p = *(int*)((char*)this + 0x1c);
    if (*(int*)((char*)p + 0x14))
        FUN_00238bb0(*(int*)((char*)this + 0x20), *(int*)((char*)p + 0x10), formatString_238c70,
                     *(int*)((char*)p + 0x14));
    return false;
}

#include "gen/global.h"

extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049f4f0[];
extern int __cdecl FUN_00344e74(int, int, const char*, const char*, int);

void VScroll::vfunc_18(void* __p0) { void * item = (void *)__p0;

    if (this->f_240 < 0x20) {
        ((int*)((char*)this + (this->f_240 + 4) * 16))[0] = (int)item;
        ((int*)((char*)this + 0x48 + this->f_240 * 16))[0] = 0;
        if (!(*(int *)&this->f_244)) {
            if (FUN_00344e74(((int*)((char*)this + (this->f_240 + 4) * 16))[0], 0, (const char*)((int)DAT_0049dba4),
                             (const char*)((int)DAT_0049f4f0), 0))
                (*(int *)&this->f_244) = FUN_00344e74(((int*)((char*)this + (this->f_240 + 4) * 16))[0], 0, (const char*)((int)DAT_0049dba4),
                                        (const char*)((int)DAT_0049f4f0), 0);
        }
        ++this->f_240;
        if (this->f_240 > 1)
            ++this->f_268;
    }
}

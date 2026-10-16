#include "gen/core.h"

typedef unsigned int size_t;
extern "C" char* __cdecl strncpy(char*, const char*, size_t);

struct Worker_26e710 {
    void run(core::DebugConsole*, char*);
};

void core::DebugConsole::vfunc_3(void* __p0) { char * arg = (char *)__p0;

    (*(Worker_26e710 * *)&this->f_a4)->run(this, arg);
    strncpy((*(char (*)[128])&this->f_14), arg, 0x80);
    *((char*)this + 0x93) = 0;
}

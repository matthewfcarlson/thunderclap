// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026de20..0x0026efc0 (kind game, layer engine, confidence high), dominant class core::DebugConsole
#include "tree_prelude.h"


// 0x0026e710 core::DebugConsole::vfunc_3 (51 B): matches/0x0026e710.cpp [isolated: conflict: strncpy; on include/gen/ and not mergeable]
// sym: ?vfunc_3@DebugConsole@core@@UAEXPAX@Z
#include "gen/core.h"

/* size_t: tree_prelude.h */

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, size_t);
#endif


struct Worker_26e710 {
    void run(core::DebugConsole*, char*);
};

void core::DebugConsole::vfunc_3(void* __p0) { char * arg = (char *)__p0;

    (*(Worker_26e710 * *)&this->f_a4)->run(this, arg);
    strncpy((*(char (*)[128])&this->f_14), arg, 0x80);
    *((char*)this + 0x93) = 0;
}


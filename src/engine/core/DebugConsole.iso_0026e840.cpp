// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026de20..0x0026efc0 (kind game, layer engine, confidence high), dominant class core::DebugConsole
// (tree_prelude.h: not needed)


// 0x0026e840 core::DebugConsole::vfunc_8 (84 B): matches/0x0026e840.cpp [isolated: conflict: strncpy; on include/gen/ and not mergeable]
// sym: ?vfunc_8@DebugConsole@core@@UAEXPAXII@Z
#include "gen/core.h"


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern char* strncpy(char*, const char*, int);
#endif


class Console2 {
  public:
    void Func(void* msg, int n);
};

struct Msg_26e840 {
    int tag;
    void* self;
    unsigned p3;
    unsigned p4;
    char buf[84];
};

void core::DebugConsole::vfunc_8(void* __p0, unsigned int p3, unsigned int p4) { const char * s = (const char *)__p0;

    Console2* c = (*(Console2 * *)&this->f_a4);
    Msg_26e840 msg;
    msg.tag = 6;
    msg.self = this;
    msg.p3 = p3;
    msg.p4 = p4;
    strncpy(msg.buf, s, 0x54);
    msg.buf[83] = 0;
    c->Func(&msg, 100);
}


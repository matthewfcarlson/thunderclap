#include "gen/core.h"

extern char* strncpy(char*, const char*, int);

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

// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa1f0 @ 0x002fa1f0
// FUN_002fa1f0: set up a range over a shared u16 buffer and fill it from two descriptors
#include "decls/data/engine/physics.h"

struct Desc_2fa1f0 {
    char data[12];
};

struct Pair6 {
    char data[6];
};

struct Frame_2fa1f0 {
    Pair6 first;
    Pair6 second;
};

class Range_2fa1f0;

struct Worker_2fa1f0 {
    void FUN_00307060(Pair6 *p, Range_2fa1f0 *r);
};

struct Holder_2fa1f0 {
    char pad00[0x14];
    Worker_2fa1f0 *worker;
};

struct Skeleton {
    char pad00[0x44];
    Holder_2fa1f0 *holder;
    char pad48[0xd0 - 0x48];
    int fd0;
    void FUN_002f3960(Pair6 *out, Desc_2fa1f0 *d);
};


void __cdecl FUN_002f46a0(unsigned short *begin, unsigned short *end, int count);
unsigned short *__cdecl FUN_002f9190(unsigned short *begin, unsigned short *end);

class Range_2fa1f0 {
public:
    Skeleton *owner;
    int f4;
    unsigned short *begin;
    unsigned short *end;

    void FUN_002fa1f0(Desc_2fa1f0 *d, Skeleton *s);
};

void Range_2fa1f0::FUN_002fa1f0(Desc_2fa1f0 *d, Skeleton *s)
{
    unsigned short *oldBegin = begin;
    owner = s;
    end = oldBegin;
    f4 = s->fd0;
    Frame_2fa1f0 f;
    s->FUN_002f3960(&f.first, d);
    s->FUN_002f3960(&f.second, d + 1);
    begin = (*(unsigned short**)&DAT_00555440);
    end = (*(unsigned short**)&DAT_00555440);
    s->holder->worker->FUN_00307060(&f.first, this);
    end = begin + *(*(unsigned short**)&DAT_0055543c);
    FUN_002f46a0(begin, end, (int)(end - begin));
    end = FUN_002f9190(begin, end);
}

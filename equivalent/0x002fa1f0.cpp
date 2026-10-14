// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa1f0 @ 0x002fa1f0
// FUN_002fa1f0: set up a range over a shared u16 buffer and fill it from two descriptors
struct Desc {
    char data[12];
};

struct Pair6 {
    char data[6];
};

struct Frame {
    Pair6 first;
    Pair6 second;
};

class Range;

struct Worker {
    void FUN_00307060(Pair6 *p, Range *r);
};

struct Holder {
    char pad00[0x14];
    Worker *worker;
};

struct Skeleton {
    char pad00[0x44];
    Holder *holder;
    char pad48[0xd0 - 0x48];
    int fd0;
    void FUN_002f3960(Pair6 *out, Desc *d);
};

extern unsigned short *DAT_00555440;
extern unsigned short *DAT_0055543c;

void __cdecl FUN_002f46a0(unsigned short *begin, unsigned short *end, int count);
unsigned short *__cdecl FUN_002f9190(unsigned short *begin, unsigned short *end);

class Range {
public:
    Skeleton *owner;
    int f4;
    unsigned short *begin;
    unsigned short *end;

    void FUN_002fa1f0(Desc *d, Skeleton *s);
};

void Range::FUN_002fa1f0(Desc *d, Skeleton *s)
{
    unsigned short *oldBegin = begin;
    owner = s;
    end = oldBegin;
    f4 = s->fd0;
    Frame f;
    s->FUN_002f3960(&f.first, d);
    s->FUN_002f3960(&f.second, d + 1);
    begin = DAT_00555440;
    end = DAT_00555440;
    s->holder->worker->FUN_00307060(&f.first, this);
    end = begin + *DAT_0055543c;
    FUN_002f46a0(begin, end, (int)(end - begin));
    end = FUN_002f9190(begin, end);
}

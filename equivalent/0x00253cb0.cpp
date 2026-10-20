// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 26/26)
// FUN_00253cb0 @ 0x00253cb0
#include "compat/ptr.h"
class Reader {
public:
    virtual void v0();
    virtual int v1();
    virtual int *v2();
    virtual void v3();
    virtual int v4();
    virtual void v5(int value);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

struct Owner_253cb0 {
    char pad00[0x84];
    int f84;
};

struct Stream {
    char pad00[0x34];
    void *source;          // 0x34
    Reader *reader;        // 0x38
    Owner_253cb0 *owner;          // 0x3c
    char pad40[0x5c - 0x40];
    unsigned char done;    // 0x5c
    void FUN_0025d480(int *pos);
};

int FUN_0024b220(void *source);
char FUN_0024b200(void *source);
Reader *FUN_0025cab0(int a, int b, int c, int d);
void FUN_0025be60(int *pos, int *local);
int FUN_0024c4d0(int *local, int v);
int FUN_0024c480(int *local, int v);
int FUN_0024c2f0(int *pos);
hulk_uintptr FUN_0026fd80(hulk_uintptr a, unsigned int b);
Reader *FUN_0025bec0(Reader *r);
int FUN_0024ba70(void *source, Reader *reader, int amount);

class SeqActionStream_253cb0 {
public:
    char pad00[8];
    int f08;
    int f0c;
    int result;            // 0x10
    int f14;
    int f18;
    int state;             // 0x1c
    int f20;
    int pos;               // 0x24
    int f28;

    void FUN_00253cb0(Stream *s);
};

void SeqActionStream_253cb0::FUN_00253cb0(Stream *s)
{
    if (s->done)
        return;

    if (state == 0) {
        bool create;
        if (s->source == 0)
            create = (f18 == 0);
        else if (s->reader != 0)
            create = false;
        else
            create = (FUN_0024b220(s->source) == 0);
        if (create) {
            Reader *r = FUN_0025cab0(s->owner->f84, f08 + 8, 0, 0);
            s->reader = r;
            r->v0();
            state = 1;
        }
    }
    if (state == 1) {
        s->reader->v11();
        int st = s->reader->v1();
        if (st == 1)
            return;
        if (st == 2) {
            pos = *s->reader->v2();
            f28 = s->reader->v4();
            state = 2;
        } else if (st == 3) {
            state = 4;
            s->reader->v12();
            s->reader = 0;
            f20 = 2;
            return;
        }
    }
    if (state != 2)
        return;

    int local;
    FUN_0025be60(&pos, &local);
    int base = FUN_0024c4d0(&local, f14);
    state = 2;
    if (s->source == 0)
        s->FUN_0025d480(&pos);
    if (s->source == 0) {
        state = 4;
        s->reader->v12();
        s->reader = 0;
        f20 = 2;
        return;
    }
    if (FUN_0024b200(s->source))
        return;
    int n = FUN_0024c480(&pos, base);
    hulk_intptr m = FUN_0026fd80(n, FUN_0024c2f0(&pos));
    s->reader->v5(m);
    s->reader = FUN_0025bec0(s->reader);
    int k = FUN_0024c4d0(&pos, f28) - base;
    result = FUN_0024ba70(s->source, s->reader, FUN_0024c480(&local, k));
    s->reader = 0;
    f0c = f14;
    state = 3;
}

// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 25/26, incomplete)
// FUN_0024b920 @ 0x0024b920
class Sink {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void write(unsigned int addr, unsigned int a, unsigned int b);
    virtual void v7();
    virtual char poll(unsigned int *out);
};

struct Source {
    unsigned int base;
    char pad4[4];
    unsigned int f8;
    char padc[0x14 - 0xc];
    unsigned int off;
};

struct Slot {
    Sink *sink;
    char rest[8];
};

struct Queue {
    Slot slots[10];
    void FUN_0024b270();
};

char FUN_0025e450(Source *src, int size);
char FUN_0024af90(Source *src);
Source *FUN_0025e090(Source *src);
unsigned int FUN_0026fd80(Source *src, int size);
void FUN_0025e0b0(Source *src, unsigned int v, int zero);
int FUN_00267f80(unsigned int live);

struct Player {
    char pad0[0x14];
    Source *source;
    int f18;
    int f1c;
    char pad20[0x40 - 0x20];
    Queue queue;
    unsigned char current;
    unsigned char enabled;
    char pad_ba[0xc8 - 0xba];
    int started;
    char pad_cc[4];
    unsigned int pending;
};

// equiv-conv: FUN_0024b920 esi ebx
void FUN_0024b920(Player *p, unsigned int live)
{
    unsigned int got;

    if (p->source == 0)
        return;
    if (!p->enabled)
        return;
    Slot *slot = &p->queue.slots[p->current];
    if (slot == 0)
        return;
    Sink *sink = slot->sink;
    if (sink != 0) {
        if (sink->state() != 2)
            return;
    }
    if (p->started == 0) {
        if (!FUN_0025e450(p->source, 0x800))
            return;
        if (!FUN_0024af90(p->source))
            return;
        if (sink == 0)
            return;
        if (sink->state() != 2)
            return;
        unsigned int n = FUN_0026fd80(FUN_0025e090(p->source), 0x800);
        if (n == 0)
            return;
        p->f1c++;
        p->f18 = FUN_00267f80(live);
        sink->write(p->source->off + p->source->base, p->source->f8, n);
        p->pending = n;
        p->started = 1;
    } else {
        if (!sink->poll(&got))
            return;
        FUN_0025e0b0(p->source, got, 0);
        if (p->pending > got)
            p->queue.FUN_0024b270();
        p->pending = 0;
        p->started = 0;
    }
}

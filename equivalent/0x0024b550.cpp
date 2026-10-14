// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 64/66, incomplete)
// FUN_0024b550 @ 0x0024b550
class Sink_24b550 {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual unsigned int v3();
    virtual void v4();
    virtual void v5();
    virtual void write(unsigned int a, unsigned int b, unsigned int c);
    virtual void v7();
    virtual char poll(unsigned int *out);
};

class Stream {
public:
    virtual void start();
    virtual void stop();
    virtual void v2();
    virtual char done();
};

struct Slot_24b550 {
    Sink_24b550 *sink;
    char rest[8];
};

struct Queue_24b550 {
    Slot_24b550 slots[10];
    unsigned char current;
    unsigned char enabled;
    void FUN_0024b270();
};

struct Chunk {
    unsigned int f0;
    unsigned int f4;
    char pad8[4];
    float fc;
    char pad10[4];
    void *f14;
};

struct Region_24b550 {
    unsigned int pos;
    char pad4[4];
    unsigned int len;
    char padc[0x18 - 0xc];
    unsigned int extra;
};

struct Frame_24b550 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

unsigned int FUN_0025e2b0(Chunk *c);
unsigned int FUN_0025e090(Chunk *c);
unsigned int FUN_0026fd80(unsigned int a, unsigned int n);
unsigned int FUN_0025e310(Region_24b550 *r);
char FUN_0025cf70(int a, void *b, unsigned int c, unsigned int *out);
char FUN_0025d070(int a, void *b, unsigned int c, int d, unsigned int *z, unsigned int *y, unsigned int *x);
unsigned int FUN_00267f80();
Stream *FUN_002703c0(unsigned int y, unsigned int z, unsigned int w, unsigned int v, unsigned int x);
void FUN_0025d0f0(int a, unsigned int b);
void FUN_0025e350(Region_24b550 *r, unsigned int v);
char FUN_0025d010(int a);
void FUN_0025e0b0(Chunk *c, unsigned int v, int flag);

struct Player_24b550 {
    char pad00[0xc];
    int h0c;
    Chunk *chunk;
    Region_24b550 *region;
    unsigned int t18;
    int n1c;
    unsigned int t20;
    unsigned int t24;
    unsigned int mark28;
    unsigned int t2c;
    unsigned int t30;
    unsigned int t34;
    unsigned int t38;
    unsigned int t3c;
    Queue_24b550 queue;
    char pad_bc[4];
    int mode;
    int state;
    char pad_c8[4];
    unsigned int pos;
    char pad_d0[4];
    Stream *stream;
};

// equiv-conv: FUN_0024b550 esi
void FUN_0024b550(Player_24b550 *p)
{
    Frame_24b550 f;
    Queue_24b550 *q = &p->queue;
    Slot_24b550 *slot = 0;
    if (q->enabled) {
        slot = &q->slots[q->current];
    }
    Sink_24b550 *sink = 0;
    bool ok;
    if (slot == 0) {
        ok = false;
    } else {
        sink = slot->sink;
        if (sink != 0 && sink->state() != 2) {
            sink = 0;
            ok = false;
        } else {
            ok = true;
        }
    }
    bool bad = !ok;

    int state = p->state;
    if (state == 0) {
        Chunk *c = p->chunk;
        f.x = FUN_0025e2b0(c);
        unsigned int limit = (unsigned int)((float)c->f4 * c->fc);
        if (f.x > limit) {
            if (p->mode != 1) {
                return;
            }
        }
        unsigned int amount = FUN_0025e090(p->chunk);
        if (p->region == 0 && sink != 0) {
            amount = FUN_0026fd80(amount, sink->v3());
        }
        if (amount == 0 || bad) {
            return;
        }
        if (sink == 0 && (p->region == 0 || FUN_0025e310(p->region) == 0)) {
            if (!FUN_0025cf70(p->h0c, p->chunk->f14, amount, &f.x)) {
                return;
            }
            p->pos = f.x;
            p->t2c = f.x;
            p->t24 = FUN_00267f80();
            p->state = 5;
            return;
        }
        if (p->region == 0) {
            if (!FUN_0025d070(p->h0c, p->chunk->f14, amount, 0, &f.z, &f.y, &f.x)) {
                return;
            }
            p->t30 = FUN_00267f80();
            p->n1c++;
            p->t18 = FUN_00267f80();
            sink->write(f.z, f.y, f.x);
            p->mark28 = f.x;
            p->state = 2;
            p->pos = f.x;
            return;
        }
        unsigned int avail = FUN_0025e310(p->region);
        if (avail == 0) {
            return;
        }
        if (avail < amount) {
            amount = avail;
        }
        if (!FUN_0025d070(p->h0c, p->chunk->f14, amount, 1, &f.y, &f.z, &f.x)) {
            return;
        }
        p->t34 = FUN_00267f80();
        Region_24b550 *r = p->region;
        p->stream = FUN_002703c0(f.y, f.z, r->extra + r->pos, r->len, f.x);
        p->stream->start();
        p->mark28 = f.x;
        p->state = 3;
        p->pos = f.x;
        return;
    }
    if (state == 2) {
        Slot_24b550 *s2 = 0;
        if (q->enabled) {
            s2 = &q->slots[q->current];
        }
        Sink_24b550 *sk = s2->sink;
        if (!sk->poll(&f.x)) {
            return;
        }
        FUN_0025d0f0(p->h0c, f.x);
        if (p->pos > f.x) {
            q->FUN_0024b270();
            p->pos = f.x;
        }
        p->state = 4;
        p->t20 = FUN_00267f80();
        return;
    }
    if (state == 3) {
        if (!p->stream->done()) {
            return;
        }
        FUN_0025d0f0(p->h0c, p->pos);
        FUN_0025e350(p->region, p->pos);
        p->stream->stop();
        p->stream = 0;
        p->state = 4;
        p->t20 = FUN_00267f80();
        return;
    }
    if (state == 4) {
        if (!FUN_0025d010(p->h0c)) {
            return;
        }
        if (p->region != 0) {
            p->t3c += FUN_00267f80() - p->t34;
        } else {
            p->t38 += FUN_00267f80() - p->t30;
        }
        FUN_0025e0b0(p->chunk, p->pos, 0);
        p->pos = 0;
        p->state = 0;
        return;
    }
    if (state == 5) {
        if (!FUN_0025d010(p->h0c)) {
            return;
        }
        FUN_0025e0b0(p->chunk, p->pos, 1);
        p->state = 0;
        p->pos = 0;
    }
}

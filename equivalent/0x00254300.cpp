// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 43/43)
// audio::SeqActionStream::vfunc_6 @ 0x00254300
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
    virtual int v12();
};

struct Source;

struct Track {
    char pad00[0x28];
    int *startPtr;          // 0x28
    float result;            // 0x2c
    unsigned int rate;       // 0x30
    int *endPtr;            // 0x34
};

struct Stream {
    char pad00[4];
    Track *track;            // 0x04
    char pad08[0x34 - 0x08];
    Source *source;          // 0x34
    Reader *reader;          // 0x38
    char pad3c[0x54 - 0x3c];
    signed char priority;    // 0x54
};

int FUN_0024afe0(Source *src);
int FUN_0024c090(Source *src);
int FUN_0024b0d0(Source *src);
void FUN_0025be60(int *pos, int *local);
int FUN_0024c4d0(int *local, int v);
int FUN_0024c480(int *local, int v);
float FUN_00261bb0(int a, int b, int c, int d, int e);

namespace audio {

class SeqActionStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6(Stream *s);
    char pad04[4];
    int f08;
    int f0c;
    int f10;
    int f14;
    unsigned int minPriority;  // 0x18
    int state;                 // 0x1c
    int mode;                  // 0x20
    int pos;                   // 0x24
    int f28;

    int FUN_00253cb0(Stream *s);
    void FUN_00253f10(Stream *s);
    void FUN_00253f40(Stream *s);
    int FUN_00253f70(Stream *s);
};

}

int audio::SeqActionStream::vfunc_6(Stream *s)
{
    switch (mode) {
    case 1: {
        Stream *st = s;
        if ((unsigned int)(int)st->priority < minPriority)
            return st->priority;
        if (state != 3) {
            int rc = FUN_00253cb0(st);
            if (state != 3)
                return rc;
        }
        int r = FUN_0024afe0(st->source);
        if (r == 0) {
            return FUN_0024c090(st->source);
        }
        if (r > 1 && r <= 4)
            mode = 2;
        return r;
    }
    case 3: {
        Stream *st = s;
        int r = FUN_0024afe0(st->source);
        if (r == 0 || r == 5) {
            mode = 5;
            return 0;
        }
        if (r == 2) {
            int *x = (int *)&s;
            int base = FUN_0024b0d0(st->source);
            f14 = (f0c - f10) + base;
            FUN_0025be60(&pos, x);
            int p0 = FUN_0024c4d0(&pos, f28);
            int p1 = FUN_0024c4d0(x, f14);
            Track *t = st->track;
            int loc0 = *t->endPtr;
            unsigned int rate = t->rate;
            int loc1 = *t->startPtr;
            t->result = FUN_00261bb0(loc1, rate, p1, (unsigned int)*x >> 9 & 0x1ffff, loc0);
            int n = FUN_0024c480(x, p0);
            FUN_00253f10(st);
            FUN_00253f40(st);
            int rl = FUN_00253f70(st);
            if (f14 > n) {
                f14 = 0;
                mode = 0;
                return 0;
            }
            return rl;
        }
        return r - 5;
    }
    case 4: {
        Stream *st = s;
        int r = FUN_0024afe0(st->source);
        if (r == 0 || r == 4)
            mode = 2;
        return r;
    }
    case 5: {
        Stream *st = s;
        if (state != 0 && state != 3 && st->reader != 0) {
            st->reader->v11();
            int rr = st->reader->v1();
            if (rr == 1)
                return rr;
            int rv = st->reader->v12();
            st->reader = 0;
            state = 0;
            return rv;
        }
        int old = state;
        Source *src = st->source;
        int ra = old;
        if (src != 0)
            ra = FUN_0024afe0(src);
        if (src == 0 || ra == 0) {
            mode = 0;
            state = 0;
        }
        return ra;
    }
    default:
        return mode - 1;
    }
}

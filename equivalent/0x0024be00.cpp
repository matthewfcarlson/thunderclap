// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// FUN_0024be00 @ 0x0024be00
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" void *memset(void *p, int c, unsigned n);

struct Sub_24be00 {
    char pad0[0xc];
    float f0c;
    char pad10[0x28 - 0x10];
    int f28;
    int f2c;
};

struct Rec_24be00 {
    Rec_24be00 *next;
    Rec_24be00 *prev;
    int handle;
    int fc;
    Sub_24be00 *f10;
    Sub_24be00 *f14;
    int f18[10];
    char pad40[0xb8 - 0x40];
    char b8;
    char b9;
    char ba;
    char pad_bb;
    int fbc;
    int fc0, fc4, fc8, fcc, fd0, fd4;
};

struct Pool_24be00 {
    char data[0x48];
};


void *FUN_00247530(void *pool);
void FUN_00247550(void *pool, Rec_24be00 *r);
int FUN_0025d340(int a, int b, int c);
int FUN_00259610(int a, int b, int c);
void FUN_00258b40(int h, int one);
hulk_intptr FUN_0025e070();
int FUN_0025d040(int h);
void FUN_0025e550(Sub_24be00 *s, int a, int b, int c);

Rec_24be00 *FUN_0024be00(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    Rec_24be00 *r = (Rec_24be00 *)FUN_00247530(((Pool_24be00*)&DAT_004e61a0));
    if (r)
        memset(r, 0, sizeof(Rec_24be00));
    r->handle = 0;
    r->fc = 0;
    r->fc0 = 0;
    r->fc4 = 0;
    r->fc8 = 0;
    r->fcc = 0;
    r->fd0 = 0;
    r->fd4 = 0;
    r->fc = FUN_0025d340(a3, a4, 1);
    if (r->fc == 0) {
        FUN_00247550(((Pool_24be00*)&DAT_004e61a0), r);
        return 0;
    }
    if ((*(Rec_24be00**)&DAT_004e61e8) == 0) {
        (*(Rec_24be00**)&DAT_004e61e8) = r;
        r->prev = 0;
    } else {
        (*(Rec_24be00**)&DAT_004e61ec)->next = r;
        r->prev = (*(Rec_24be00**)&DAT_004e61ec);
    }
    (*(Rec_24be00**)&DAT_004e61ec) = r;
    r->next = 0;
    r->handle = FUN_00259610(a1, a2, r->fc);
    FUN_00258b40(r->handle, 1);
    Sub_24be00 *s = (Sub_24be00 *)FUN_00247530((void *)FUN_0025e070());
    if (s) {
        s->f28 = 0;
        s->f2c = 0;
    }
    r->f10 = s;
    FUN_0025e550(r->f10, 0, 0, FUN_0025d040(r->fc));
    if (a5) {
        Sub_24be00 *s2 = (Sub_24be00 *)FUN_00247530((void *)FUN_0025e070());
        if (s2) {
            s2->f28 = 0;
            s2->f2c = 0;
        }
        r->f14 = s2;
        r->f10->f0c = 1.0f;
        FUN_0025e550(r->f14, a5, a7, a6);
    } else {
        r->f14 = 0;
    }
    r->b9 = 0;
    r->b8 = 0;
    r->fbc = 0;
    r->ba = 10;
    for (int i = 0; i < 10; i++)
        r->f18[i] = 0;
    return r;
}

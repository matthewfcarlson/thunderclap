// STATUS: equivalent (tools/equiv.py level 3: 19606 inputs, branch coverage 36/36)
// FUN_0024bc70 @ 0x0024bc70
// FUN_0024bc70 @ 0x0024bc70
#include "compat/ptr.h"
#include "gen/owners.h"
class Sink_24bc70 {
public:
    virtual void v0();
    virtual int state();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void finish();
};

struct Slot_24bc70 {
    Sink_24bc70 *sink;
    char rest[8];
};

struct Queue_24bc70 {
    Slot_24bc70 slots[10];
    unsigned char current;
    unsigned char enabled;
    unsigned char count;
};

struct Span_24bc70 {
    char pad0[0x1c];
    unsigned int start;
    unsigned int length;
};

struct Resource_24bc70 { char pad[4]; };

struct Player_24bc70 {
    char pad0[8];
    int handle;
    unsigned int limit;
    Span_24bc70 *span;
    Resource_24bc70 *res;
    char pad18[0x40 - 0x18];
    Queue_24bc70 queue;
    int f0bc;
    int state;
    int f0c4;
    int f0c8;
};

unsigned int __cdecl FUN_0025d040(unsigned int v);
extern "C" void * __cdecl FUN_00259c50(void *);
extern "C" void __cdecl FUN_00258ea0(int handle, int arg);
extern "C" void __cdecl FUN_0025e290(void *obj);
void __cdecl FUN_0024bae0(Player_24bc70 *p, int arg);
// equiv-conv: FUN_0024b170 eax
extern "C" bool __cdecl FUN_0024b170(void *);
// equiv-conv: FUN_0024b480 eax
extern "C" void __cdecl FUN_0024b480(void *);
// equiv-conv: FUN_0024b550 esi
extern "C" void __cdecl FUN_0024b550(void *);
// equiv-conv: FUN_0024b920 esi
extern "C" void __cdecl FUN_0024b920(void *);

// equiv-conv: FUN_0024bc70 eax
extern "C" void FUN_0024bc70(void *p)
{
    int state = ((Player_24bc70 *)p)->state;
    if (state == 1) {
        unsigned int end = ((Player_24bc70 *)p)->span->length + ((Player_24bc70 *)p)->span->start;
        if (end >= FUN_0025d040(((Player_24bc70 *)p)->limit) && ((Player_24bc70 *)p)->f0c4 == 0) {
            ((Player_24bc70 *)p)->state = 4;
            return;
        }
    } else if (state == 2 || state == 3) {
        if (state == 3 && ((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(((Player_24bc70 *)p)->handle))) == 0 && ((Player_24bc70 *)p)->f0c4 == 0) {
            ((Player_24bc70 *)p)->state = 4;
            return;
        }
        FUN_0024b170((Player_24bc70 *)((Player_24bc70 *)p));
    } else if (state == 5) {
        if (((int)(hulk_uintptr)FUN_00259c50((void *)(hulk_uintptr)(int)(((Player_24bc70 *)p)->handle))) == 0 && ((Player_24bc70 *)p)->f0c4 == 0 && ((Player_24bc70 *)p)->f0c8 == 0) {
            int found = 0;
            for (Slot_24bc70 *s = ((Slot_24bc70 *)((owners::Obj_24b2d0 *)&(((Player_24bc70 *)p)->queue))->FUN_0024b2d0()); s != 0; s = ((Slot_24bc70 *)((owners::X_24b310 *)&(((Player_24bc70 *)p)->queue))->FUN_0024b310((Slot_24bc70 *)s))) {
                Sink_24bc70 *sink = s->sink;
                if (sink != 0) {
                    int r = sink->state();
                    if (r == 1) {
                        found = r;
                        s->sink->finish();
                    }
                }
            }
            if (found == 0) {
                FUN_0024bae0(((Player_24bc70 *)p), 1);
                FUN_00258ea0(((Player_24bc70 *)p)->handle, 0);
                ((Player_24bc70 *)p)->state = 0;
                ((Player_24bc70 *)p)->f0bc = 0;
                FUN_0025e290(((Player_24bc70 *)p)->span);
                if (((Player_24bc70 *)p)->res != 0)
                    FUN_0025e290(((Player_24bc70 *)p)->res);
            }
        }
        if (((Player_24bc70 *)p)->state != 5)
            return;
    } else {
        return;
    }
    FUN_0024b480((Player_24bc70 *)((Player_24bc70 *)p));
    FUN_0024b550((Player_24bc70 *)((Player_24bc70 *)p));
    FUN_0024b920((Player_24bc70 *)((Player_24bc70 *)p));
}

// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 20/20)
// FUN_0001e870 @ 0x0001e870
#include "gen/global.h"
struct V3_1e870 {
    float x, y, z;
};

struct RefObj_1e870 {
    virtual void AddRef();
    virtual void Release();
};

struct Drawable_1e870;

struct Source_1e870 {
    char pad0[0xfc];
    int state;
    RefObj_1e870 *FUN_001d72e0();
};

struct Request_1e870 {
    char pad0[0x14];
    unsigned char active;
    char pad15[0x28 - 0x15];
    V3_1e870 target;
    char pad34[0x4c - 0x34];
    RefObj_1e870 *f4c;
    RefObj_1e870 *f50;
    char pad54[0x60 - 0x54];
    int f60;
    char pad64[0x6c - 0x64];
    RefObj_1e870 *f6c;
    int f70;
    char pad74[0x84 - 0x74];
    int f84;
    char pad88[0x98 - 0x88];
    Request_1e870 *FUN_00059820();
    void FUN_00059300();
};

struct CFightParamsCollision_nv_1e870 {
    CFightParamsCollision *FUN_000598e0(void *a, Request_1e870 *req);
    void FUN_00059790(RefObj_1e870 *obj);
};


struct Sink;
struct Slot_1e870 {
    char FUN_00231ad0(Sink *sink, CFightParamsCollision *job, int zero);
};

struct Queue_1e870 {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual Slot_1e870 *Submit(CFightParamsCollision *job, int zero);
};

struct Pad_1e870 {
    char pad0[0x10];
    void **chain;
    char pad14[0xdc - 0x14];
    int f0dc;
    char pad0e0[0x12c - 0xe0];
    RefObj_1e870 *f12c;
    char pad130[0x334 - 0x130];
    int f334;
    unsigned int FUN_00036020();
    int FUN_00035ef0(int a);
    void FUN_0003a9d0(RefObj_1e870 *obj);
};

struct Owner;
struct Fighter_1e870 { char pad[4]; };
Fighter_1e870 *__fastcall FUN_000592a0(void *owner);
Pad_1e870 *__fastcall FUN_00059a30(Fighter_1e870 *f);

void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_1e870 **slot, RefObj_1e870 *obj);
void __cdecl FUN_000187a0(RefObj_1e870 **slot, RefObj_1e870 *obj);

struct Holder_1e870 {
    char pad0[0x34];
    unsigned char ready;
    char pad35[0x44 - 0x35];
    Queue_1e870 *queue;
};

class Spawner_1e870 {
public:
    char pad0[0x1c];
    void *owner;
    Holder_1e870 *holder;
    char pad24[0x38 - 0x24];
    char spawned;
    char pad39[3];
    RefObj_1e870 *ref;

    bool FUN_0001e870(Source_1e870 *src, const V3_1e870 *pos);
};

bool Spawner_1e870::FUN_0001e870(Source_1e870 *src, const V3_1e870 *pos)
{
    if (!holder->ready || spawned)
        return false;
    if (src == 0)
        return false;
    if (src->state == 2 || src->state == 3)
        return false;

    Pad_1e870 *pad = FUN_00059a30(FUN_000592a0(owner));
    if (pad->FUN_00036020())
        return false;
    if (pad->f334)
        return false;
    if (pad->FUN_00035ef0(0))
        return false;
    pad->FUN_0003a9d0(src->FUN_001d72e0());

    Request_1e870 req;
    req.FUN_00059820();
    FUN_00018810(&req.f4c, src->FUN_001d72e0());
    FUN_00018810(&req.f50, pad->f12c);
    FUN_000187a0(&req.f6c, ref);
    req.active = 1;
    req.target = *pos;

    CFightParamsCollision *job = (CFightParamsCollision *)FUN_0008d690(0xb0);
    if (job)
        job = ((CFightParamsCollision_nv_1e870*)(job))->FUN_000598e0(*pad->chain, &req);
    job->vfunc_0();
    ((CFightParamsCollision_nv_1e870*)(job))->FUN_00059790(src->FUN_001d72e0());
    Slot_1e870 *slot = holder->queue->Submit(job, 0);
    if (slot) {
        slot->FUN_00231ad0((Sink *)&pad->f0dc, job, 0);
        spawned = 1;
        job->vfunc_1();
        req.FUN_00059300();
        return true;
    }
    job->vfunc_1();
    req.FUN_00059300();
    return false;
}

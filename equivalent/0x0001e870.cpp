// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 20/20)
// FUN_0001e870 @ 0x0001e870
struct V3 {
    float x, y, z;
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Drawable;

struct Source {
    char pad0[0xfc];
    int state;
    RefObj *FUN_001d72e0();
};

struct Request {
    char pad0[0x14];
    unsigned char active;
    char pad15[0x28 - 0x15];
    V3 target;
    char pad34[0x4c - 0x34];
    RefObj *f4c;
    RefObj *f50;
    char pad54[0x60 - 0x54];
    int f60;
    char pad64[0x6c - 0x64];
    RefObj *f6c;
    int f70;
    char pad74[0x84 - 0x74];
    int f84;
    char pad88[0x98 - 0x88];
    Request *FUN_00059820();
    void FUN_00059300();
};

struct Job {
    virtual void v0();
    virtual void v1();
    Job *FUN_000598e0(void *a, Request *req);
    void FUN_00059790(RefObj *obj);
};


struct Sink;
struct Slot {
    char FUN_00231ad0(Sink *sink, Job *job, int zero);
};

struct Queue {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual Slot *Submit(Job *job, int zero);
};

struct Pad {
    char pad0[0x10];
    void **chain;
    char pad14[0xdc - 0x14];
    int f0dc;
    char pad0e0[0x12c - 0xe0];
    RefObj *f12c;
    char pad130[0x334 - 0x130];
    int f334;
    unsigned int FUN_00036020();
    int FUN_00035ef0(int a);
    void FUN_0003a9d0(RefObj *obj);
};

struct Owner;
struct Fighter { char pad[4]; };
Fighter *__fastcall FUN_000592a0(void *owner);
Pad *__fastcall FUN_00059a30(Fighter *f);

void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj **slot, RefObj *obj);
void __cdecl FUN_000187a0(RefObj **slot, RefObj *obj);

struct Holder {
    char pad0[0x34];
    unsigned char ready;
    char pad35[0x44 - 0x35];
    Queue *queue;
};

class Spawner {
public:
    char pad0[0x1c];
    void *owner;
    Holder *holder;
    char pad24[0x38 - 0x24];
    char spawned;
    char pad39[3];
    RefObj *ref;

    bool FUN_0001e870(Source *src, const V3 *pos);
};

bool Spawner::FUN_0001e870(Source *src, const V3 *pos)
{
    if (!holder->ready || spawned)
        return false;
    if (src == 0)
        return false;
    if (src->state == 2 || src->state == 3)
        return false;

    Pad *pad = FUN_00059a30(FUN_000592a0(owner));
    if (pad->FUN_00036020())
        return false;
    if (pad->f334)
        return false;
    if (pad->FUN_00035ef0(0))
        return false;
    pad->FUN_0003a9d0(src->FUN_001d72e0());

    Request req;
    req.FUN_00059820();
    FUN_00018810(&req.f4c, src->FUN_001d72e0());
    FUN_00018810(&req.f50, pad->f12c);
    FUN_000187a0(&req.f6c, ref);
    req.active = 1;
    req.target = *pos;

    Job *job = (Job *)FUN_0008d690(0xb0);
    if (job)
        job = job->FUN_000598e0(*pad->chain, &req);
    job->v0();
    job->FUN_00059790(src->FUN_001d72e0());
    Slot *slot = holder->queue->Submit(job, 0);
    if (slot) {
        slot->FUN_00231ad0((Sink *)&pad->f0dc, job, 0);
        spawned = 1;
        job->v1();
        req.FUN_00059300();
        return true;
    }
    job->v1();
    req.FUN_00059300();
    return false;
}

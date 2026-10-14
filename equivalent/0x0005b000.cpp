// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 13/14, incomplete)
// CGrappleSequenceTrack::vfunc_10 @ 0x0005b000
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

struct Fighter;

struct Marker {
    char pad0[8];
    int value;                // 0x8
};

class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Marker *v4();
};

struct Source {
    char pad0[0x10];
    int *current;             // 0x10
};

struct Actor {
    char pad0[0x330];
    Source *primary;          // 0x330
    Source *secondary;        // 0x334
};

Fighter *__fastcall FUN_000592a0(Params *params);
Actor *__fastcall FUN_00059a30(Fighter *f);

struct SequenceAction {
    SequenceAction *FUN_00237c90(int a, int b, int c, int d, int e, int f, Marker *g);
};

class CGrappleSequenceTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int a, Params *params);
    virtual void vfunc_9();
    virtual SequenceAction *vfunc_10(int a, int b, Params *params);
    char pad04[8];
    int f0c;
    char pad10[8];
    int f18;
    int f1c;
};

SequenceAction *CGrappleSequenceTrack::vfunc_10(int a, int b, Params *params)
{
    if (params == 0)
        return 0;
    Fighter *fighter = FUN_000592a0(params);
    if (fighter == 0)
        return 0;
    Actor *actor = FUN_00059a30(fighter);
    if (actor == 0)
        return 0;
    Source *src = actor->secondary;
    if (src == 0) {
        src = actor->primary;
        if (src == 0)
            return 0;
    }
    Marker *marker = params->v4();
    marker->value = *src->current;
    SequenceAction *mem = (SequenceAction *)FUN_0008d690(0x3c);
    if (mem == 0)
        return 0;
    int first = f0c;
    return mem->FUN_00237c90(a, (int)this, first, f18, (int)&f1c, vfunc_8(b, params), marker);
}

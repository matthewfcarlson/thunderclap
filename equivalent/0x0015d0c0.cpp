// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 17/18, incomplete)
// hulkfight::motion::PhaseCondition::vfunc_6 @ 0x0015d0c0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern char DAT_0048d534[];
extern char DAT_004ac1d0[];
extern char DAT_0048e01c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern float DAT_003f32e0;
float __cdecl FUN_0015cf40(float value);

struct Marker_15d0c0 {
    char pad0[0x24];
    float value;
};

struct Ramp {
    char pad0[0x224];
    char active;
    char pad225[7];
    float start;
    float end;
    char pad234[8];
    float target;
};

struct Item;

struct Track {
    char pad0[0x68];
    unsigned int count;
    Item *FUN_00222e20(unsigned int index);
};

struct Timeline_15d0c0 {
    Track *FUN_00059a40();
};

struct Source_15d0c0 {
    Timeline_15d0c0 *FUN_000592a0();
};

class PhaseCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int unused1, Source_15d0c0 *source, int unused3);
    char pad4[8];
    float phase;
    float tolerance;
};

bool PhaseCondition::vfunc_6(int unused1, Source_15d0c0 *source, int unused3)
{
    if (!FUN_00344e74(source, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;
    Track *track = source->FUN_000592a0()->FUN_00059a40();
    if (!track)
        return false;

    float zero = DAT_003f32e0;
    float x;
    unsigned int n = track->count;
    unsigned int i = 0;
    for (;;) {
        if (i >= n) {
            x = zero - phase;
            break;
        }
        Item *item = track->FUN_00222e20(i);
        Marker_15d0c0 *m = (Marker_15d0c0 *)FUN_00344e74(item, 0, DAT_0048d534, DAT_004ac1d0, 0);
        if (m) {
            x = m->value - phase;
            break;
        }
        Ramp *r = (Ramp *)FUN_00344e74(item, 0, DAT_0048d534, DAT_0048e01c, 0);
        if (r && r->active) {
            if (r->end - r->start > 0.0f) {
                x = (r->target - r->start) / (r->end - r->start) - phase;
                break;
            }
        }
        i++;
    }
    float result = FUN_0015cf40(x);
    if (result < 0.0f)
        result = -result;
    return result < tolerance;
}

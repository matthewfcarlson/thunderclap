// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 18/18)
// CChaseAgent::vfunc_4 @ 0x000fcb70
extern "C" double sqrt(double);

struct V3_fcb70 {
    float x, y, z;
    float FUN_0022d110();
};

struct Clock;
Clock *__cdecl FUN_000964d0();

struct Anchor_fcb70 {
    char pad0[0x10];
    char FUN_00059a50(V3_fcb70 *out);
};

struct Latch {
    char FUN_00231ee0();
};

struct NameHolder_fcb70 {
    void FUN_0027b040(const char *name);
};

struct Player_fcb70 {
    char pad0[0x10];
    struct Anchor_fcb70 *anchor;
    char pad14[0xdc - 0x14];
    Latch latch;
    char padDd[0x1ce4 - 0xdd];
    float f1ce4;
    char pad1ce8[0x2098 - 0x1ce8];
    NameHolder_fcb70 gestureName;
    char pad2099[0x20a0 - 0x2099];
    unsigned char gestureFlag;
};

struct Unit_fcb70 {
    char pad0[0x12];
    char flag12;
    char pad13;
    float f14;
    char pad18[0x28 - 0x18];
    V3_fcb70 target;
    void FUN_000fde40(V3_fcb70 *out);
    void FUN_000fde60(V3_fcb70 *out);
};

struct Marker_fcb70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void *a, float b, int c);
    void FUN_001048d0(void *agent);
    void FUN_00104c60(void *a, V3_fcb70 *p, V3_fcb70 *q, float f0, int zero, float f1, float f2);
};

class Brain_fcb70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Player_fcb70 *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad[0x58 - 4];
    Unit_fcb70 unit;
    Marker_fcb70 *FUN_000fefc0();
};


class CChaseAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(void *a, float b, int c);
    char pad04[0x58 - 4];
    Brain_fcb70 *brain;
    char pad5c[0x6c - 0x5c];
    char engaged;
    char pad6d[3];
    float f70;
    void FUN_000fc550(void *a, float b, int c);
};

void CChaseAgent::vfunc_4(void *a, float b, int c)
{
    V3_fcb70 pos;
    V3_fcb70 dir;
    V3_fcb70 flat;

    FUN_000964d0();
    FUN_000fc550(a, b, c);
    Player_fcb70 *player = brain->v6();
    player->anchor->FUN_00059a50(&pos);
    Unit_fcb70 *unit = &brain->unit;
    if (brain != 0 && brain->v9() == 4)
        return;

    if (!engaged) {
        float v = unit->flag12 ? 0.0f : unit->f14;
        if (v < player->f1ce4)
            unit->FUN_000fde40(&dir);
        else
            unit->FUN_000fde60(&dir);
        f70 = 2.0f;
    } else {
        dir = unit->target;
        float dx = dir.x - pos.x;
        float dz = dir.z - pos.z;
        float dist = (float)sqrt(dz * dz + dx * dx);
        if (dist < 2.0f)
            f70 = f70 - b;
    }
    flat.x = dir.x - pos.x;
    flat.y = 0.0f;
    flat.z = dir.z - pos.z;
    flat.FUN_0022d110();
    char busy = player->latch.FUN_00231ee0();
    if ((char)c != 0 && !busy && brain->v9() < 3) {
        player->gestureName.FUN_0027b040("gesture_3");
        player->gestureFlag = 1;
    }
    Marker_fcb70 *marker = brain->FUN_000fefc0();
    marker->FUN_001048d0(this);
    marker->FUN_00104c60(a, &pos, &dir, 1.0f, 0, 0.5f, 1.0f);
    marker->v4(a, b, c);
}

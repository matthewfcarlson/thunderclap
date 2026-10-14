// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 24/26, incomplete)
// FUN_0003d1c0 @ 0x0003d1c0
struct V3_3d1c0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Target_3d1c0 {
    char pad0[0x74];
    V3_3d1c0 dir;
    char pad80[0x114 - 0x80];
    int f114;
    char pad118[0x140 - 0x118];
    int state140;
    char pad144[0x20b0 - 0x144];
    int f20b0;
};

struct Event_3d1c0 {
    char pad0[8];
    Target_3d1c0 *target;
    int kind;
};

struct Sink_3d1c0 {
    void FUN_002226f0(V3_3d1c0 *v);
};

struct Owner_3d1c0 {
    char pad0[0x10];
    void *obj10;
    char pad14[0x74 - 0x14];
    V3_3d1c0 dir;
    char pad80[0x334 - 0x80];
    Target_3d1c0 *t334;
    Target_3d1c0 *t338;
    char pad33c[0x1b24 - 0x33c];
    int f1b24;
    bool FUN_0003d1c0(Event_3d1c0 *ev, void *unused, V3_3d1c0 *in, V3_3d1c0 *out);
};

Sink_3d1c0 *__fastcall FUN_00059a40(void *obj);
char __cdecl FUN_00018960(float a, float b, float eps);

bool Owner_3d1c0::FUN_0003d1c0(Event_3d1c0 *ev, void *unused, V3_3d1c0 *in, V3_3d1c0 *out)
{
    if (!ev)
        return false;
    Sink_3d1c0 *sink = FUN_00059a40(obj10);
    if (ev->kind == 1) {
        Target_3d1c0 *t = ev->target;
        if (!t || t->f20b0 || t->state140 == 2 || t == t334 || t == t338 || f1b24 > 0)
            return false;
        V3_3d1c0 a;
        a.x = dir.x;
        a.y = dir.y;
        a.z = dir.z;
        a.FUN_0022d110();
        V3_3d1c0 b;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.x = t->dir.x;
        b.y = t->dir.y;
        b.z = t->dir.z;
        if (FUN_00018960(b.FUN_0022d110(), 0.0f, 1e-05f))
            return false;
        if (b.z * a.z + b.y * a.y + b.x * a.x > 0.5f)
            return false;
    } else if (ev->kind == 5) {
        if (ev->target->f114)
            return false;
    }
    V3_3d1c0 tmp;
    tmp.x = in->x;
    tmp.y = in->y;
    tmp.z = in->z;
    if (out->y <= in->y)
        tmp.y = out->y;
    sink->FUN_002226f0(&tmp);
    out->x = tmp.x;
    out->y = tmp.y;
    out->z = tmp.z;
    return true;
}

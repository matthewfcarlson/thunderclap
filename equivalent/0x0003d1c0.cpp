// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 24/26, incomplete)
// FUN_0003d1c0 @ 0x0003d1c0
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Target {
    char pad0[0x74];
    V3 dir;
    char pad80[0x114 - 0x80];
    int f114;
    char pad118[0x140 - 0x118];
    int state140;
    char pad144[0x20b0 - 0x144];
    int f20b0;
};

struct Event {
    char pad0[8];
    Target *target;
    int kind;
};

struct Sink {
    void FUN_002226f0(V3 *v);
};

struct Owner {
    char pad0[0x10];
    void *obj10;
    char pad14[0x74 - 0x14];
    V3 dir;
    char pad80[0x334 - 0x80];
    Target *t334;
    Target *t338;
    char pad33c[0x1b24 - 0x33c];
    int f1b24;
    bool FUN_0003d1c0(Event *ev, void *unused, V3 *in, V3 *out);
};

Sink *__fastcall FUN_00059a40(void *obj);
char __cdecl FUN_00018960(float a, float b, float eps);

bool Owner::FUN_0003d1c0(Event *ev, void *unused, V3 *in, V3 *out)
{
    if (!ev)
        return false;
    Sink *sink = FUN_00059a40(obj10);
    if (ev->kind == 1) {
        Target *t = ev->target;
        if (!t || t->f20b0 || t->state140 == 2 || t == t334 || t == t338 || f1b24 > 0)
            return false;
        V3 a;
        a.x = dir.x;
        a.y = dir.y;
        a.z = dir.z;
        a.FUN_0022d110();
        V3 b;
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
    V3 tmp;
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

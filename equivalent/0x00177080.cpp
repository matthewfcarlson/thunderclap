// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 48/50, incomplete)
// hulkfight::motion::SuckAction::vfunc_5 @ 0x00177080
struct Vec3_177080 {
    float x, y, z;
    double FUN_0022d110();
};

struct Item_177080 {
    char pad00[0x18];
    int id;
};

struct List_177080 {
    Item_177080** begin;
    Item_177080** end;
};

struct Mgr2_177080 {
    List_177080* FUN_002ed700();
};

struct Mgr1 {
    char pad00[8];
    Mgr2_177080* list;
};

struct Globals_177080 {
    char pad00[0x10];
    Mgr1* mgr;
};

struct Handle_177080 {
    void FUN_00059a50(Vec3_177080* out);
};

struct Sub_177080 {
    char FUN_001d4e40();
};

struct Link_177080 {
    int f00;
    char pad04[0x10];
    int type;
    char pad18[0x1b0 - 0x18];
    int f1b0;
};

struct Owner_177080;

struct Controller_177080 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a);
    void FUN_0016fc90(Vec3_177080* out);
    void FUN_0016fc60(Vec3_177080* out);
    void FUN_002f5a20(Vec3_177080* v);
};

struct Owner_177080 {
    char pad00[0xec];
    Sub_177080* sub;
    char padf0[0x11c - 0xf0];
    Link_177080* link;
    char FUN_000360f0();
    void FUN_001d82d0();
    void FUN_001d7510();
    void FUN_001d86d0(Vec3_177080* a, Vec3_177080* b);
    void FUN_00035760(Vec3_177080* v);
};

struct Entity {
    char pad00[8];
    Owner_177080* obj;
    int type;
    char pad10[0x40 - 0x10];
    Vec3_177080 pos;
    char pad4c[0x70 - 0x4c];
    Controller_177080* controller;
};

struct Action {
    Owner_177080* FUN_00059a30();
};

struct Config_177080 {
    char pad00[0x14];
    float minRange;
    float maxRange;
    float c1;
    float c2;
};

struct Source_177080 {
    Handle_177080* FUN_000592a0();
};

struct Frame_177080 {
    float r;
    float len;
    float minRange;
    float c1;
    float maxRange;
    int i;
    Owner_177080* owner;
    float c2;
    Vec3_177080 d;
    Vec3_177080 w;
    Vec3_177080 t;
    Vec3_177080 u;
    Vec3_177080 v;
    Vec3_177080 pos;
    Vec3_177080 y;
};

extern Globals_177080* DAT_004dd700;
Entity* FUN_000969d0(int id);

namespace hulkfight {
namespace motion {

class SuckAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, int b);

    char pad04[0x1c - 4];
    Config_177080* config;
    Source_177080* source;
};

bool SuckAction::vfunc_5(int a, int b)
{
    if (a)
        return true;
    Source_177080* src = source;
    if (!src)
        return false;

    Frame_177080 f;
    Config_177080* c = config;
    f.minRange = c->minRange;
    f.maxRange = c->maxRange;
    f.c1 = c->c1;
    f.c2 = c->c2;
    Handle_177080* h = src->FUN_000592a0();
    if (!h)
        return false;
    Owner_177080* owner = ((Action*)h)->FUN_00059a30();
    f.owner = owner;
    if (!owner)
        return false;
    f.v.x = 0;
    f.v.y = 0;
    f.v.z = 0;
    h->FUN_00059a50(&f.v);

    List_177080* list = DAT_004dd700->mgr->list->FUN_002ed700();
    if (!list)
        return true;
    int count = list->end - list->begin;
    f.i = 0;
    for (f.i = 0; f.i < count; f.i++) {
        Item_177080* item = list->begin[f.i];
        if (!item)
            continue;
        Entity* e = FUN_000969d0(item->id);
        if (!e)
            continue;
        f.pos = e->pos;
        f.d.x = f.v.x - f.pos.x;
        f.d.y = f.v.y;
        f.d.z = f.v.z - f.pos.z;
        f.d.y = 0;
        double l = f.d.FUN_0022d110();
        f.len = (float)l;
        if (l < f.minRange)
            continue;
        if (f.len > f.maxRange)
            continue;

        double range = f.maxRange - f.minRange;
        f.r = f.c1;
        if (range > 0.0)
            f.r = (f.len - f.minRange) / range * (f.c2 - f.c1) + f.c1;

        if (e->type == 5) {
            Owner_177080* o = e->obj;
            if (!o)
                continue;
            if (o->sub->FUN_001d4e40())
                continue;
            Controller_177080* x = e->controller;
            if (!x)
                continue;
            x->vfunc_6(0);
            f.w.x = 0;
            f.w.y = 0;
            f.w.z = 0;
            x->FUN_0016fc90(&f.w);
            double dot = f.w.z * f.d.z + f.w.x * f.d.x + f.w.y * f.d.y;
            f.len = (float)dot;
            if (!(dot < f.r))
                continue;
            o->FUN_001d82d0();
            o->FUN_001d7510();
            f.y.x = 0;
            f.y.y = 0;
            f.y.z = 0;
            x->FUN_0016fc60(&f.y);
            o->FUN_001d86d0(&f.d, &f.y);
            double s = f.r - f.len;
            f.t.x = f.d.x;
            f.t.y = f.d.y;
            f.t.z = f.d.z;
            f.t.y = f.t.y * s;
            f.t.z = f.t.z * s;
            f.w.x = f.w.x + f.t.x * s;
            f.w.y = f.t.y + f.w.y;
            f.w.z = f.t.z + f.w.z;
            x->FUN_002f5a20(&f.w);
        } else if (e->type == 1) {
            Owner_177080* o = e->obj;
            if (!o)
                continue;
            if (o->FUN_000360f0())
                continue;
            Link_177080* l1 = o->link;
            if (!l1)
                continue;
            Link_177080* l2 = f.owner->link;
            if (l1->f1b0 == l2->f1b0)
                continue;
            int t = l1->type;
            if (t == 5 || t == 2 || t == 3)
                continue;
            f.u.x = f.d.x;
            f.u.y = f.d.y;
            f.u.z = f.d.z;
            f.u.x = f.u.x * f.r;
            f.u.y = f.u.y * f.r;
            f.u.z = f.u.z * f.r;
            o->FUN_00035760(&f.u);
        }
    }
    return true;
}

}
}

// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 10/10)
// hulkfight::ai::MotionFleeAction::vfunc_5 @ 0x00117980
struct Vec3_117980 {
    float x, y, z;
    float FUN_0022d110();
};

struct Refd_117980 {
    virtual void addRef();
    virtual void release();
    char pad[0x3c];
    Vec3_117980 pos;
};

struct Locator {
    void FUN_00059a50(Vec3_117980 *out);
};

struct Fighter_117980 {
    char pad0[0x10];
    Locator *locator;
    char pad1[0x328 - 0x14];
    Refd_117980 *target;
    char pad2[0x2064 - 0x32c];
    Vec3_117980 flee_dir;
    int flee_extra;
};

struct Owner_117980 {
    Fighter_117980 *FUN_00059a30();
};

struct Holder_117980 {
    Owner_117980 *FUN_000592a0();
};

struct Info_117980 {
    char pad[0x14];
    int value;
};

namespace hulkfight { namespace ai { struct MotionFleeAction {
    char pad0[0x1c];
    Info_117980 *info;
    Holder_117980 *holder;
    Refd_117980 *cached;

    bool vfunc_5(int skip, int arg);
}; }}

bool hulkfight::ai::MotionFleeAction::vfunc_5(int skip, int arg)
{
    if (skip == 0) {
        if (holder == 0)
            return false;
        Fighter_117980 *f = holder->FUN_000592a0()->FUN_00059a30();
        Refd_117980 *t = f->target;
        if (t == 0)
            t = cached;
        if (t != 0) {
            t->addRef();
            if (cached != 0)
                cached->release();
            cached = t;

            Vec3_117980 p = t->pos;
            Vec3_117980 q;
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            f->locator->FUN_00059a50(&q);

            Vec3_117980 d;
            d.x = p.x - q.x;
            d.y = 0.0f;
            d.z = p.z - q.z;
            d.FUN_0022d110();

            f->flee_dir.x = d.x * -1.0f;
            f->flee_dir.y = d.y * -1.0f;
            f->flee_dir.z = d.z * -1.0f;
            f->flee_extra = info->value;
        }
    }
    return true;
}

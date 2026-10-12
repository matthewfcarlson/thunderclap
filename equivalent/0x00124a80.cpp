// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 16/16)
// hulkfight::ai::AcquireTargetAction::vfunc_5 @ 0x00124a80
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(V3 *out, unsigned int id);
};

void __cdecl FUN_00224d70(float angle, V3 *v);

struct Camera {
    char pad0[0x14];
    int field14;                // 0x14
    int field18;                // 0x18
    unsigned char active;       // 0x1c
    char pad1d[3];
    V3 offset;                  // 0x20
};

struct Singleton {
    V3 *FUN_001c39c0();
    V3 *FUN_001c39d0();
};
Singleton *__cdecl FUN_001c3d90();

struct Actor {
    char pad0[0x328];
    int target;                 // 0x328
    unsigned char flag32c;      // 0x32c
    unsigned char flag32d;      // 0x32d
    char pad32e[0x202c - 0x32e];
    int mode;                   // 0x202c
    char pad2030[0x2080 - 0x2030];
    V3 anchor;                  // 0x2080

    int FUN_000350c0(V3 *out);
    float FUN_000354c0();
    void FUN_00035dc0(V3 *out);
    int FUN_000400e0(V3 *a, V3 *b, int c, int d, int e);
};

struct Handle {
    char pad0[0x10];
    Actor *actor;
};

struct Pool {
    Actor *FUN_00059a30();
};
struct Pool0 {
    Pool *FUN_000592a0();
};

struct Owner {
    char pad0[0x124];
    Actor *current;             // 0x124
};

struct Global {
    char pad0[0x20];
    Owner *owner;               // 0x20
};
extern Global *DAT_004dd700;

class AcquireTargetAction {
public:
    void *vptr;
    char pad4[0x18];
    Camera *camera;             // 0x1c
    Pool0 *pool;                // 0x20
    char FUN_00124a80(int skip, int unused);
};

char AcquireTargetAction::FUN_00124a80(int skip, int unused)
{
    struct Frame {
        V3 a;
        V3 b;
        V3 c;
    } f;

    if (skip != 0)
        return 1;

    Actor *actor = pool->FUN_000592a0()->FUN_00059a30();
    if (actor->target == 0) {
        if (camera->active) {
            f.a.x = 0; f.a.y = 0; f.a.z = 0;
            actor->FUN_000350c0(&f.a);
            f.b = camera->offset;
            FUN_00224d70(actor->FUN_000354c0(), &f.b);
            float len = f.b.FUN_0022d110();
            if (len > 0.0f) {
                Camera *c = camera;
                actor->FUN_000400e0(&f.a, &f.b, c->field14, c->field18, 0);
            }
        } else if (actor != DAT_004dd700->owner->current) {
            f.b.x = 0; f.b.y = 0; f.b.z = 0;
            actor->FUN_00035dc0(&f.b);
            f.a.x = 0; f.a.y = 0; f.a.z = 0;
            actor->FUN_000350c0(&f.a);
            Camera *c = camera;
            actor->FUN_000400e0(&f.a, &f.b, c->field14, c->field18, 0x32);
        } else {
            f.b.x = 0; f.b.y = 0; f.b.z = 0;
            f.a.x = 0; f.a.y = 0; f.a.z = 0;
            bool done = false;
            if (actor->mode == 1) {
                V3 *anchor = &actor->anchor;
                f.c.x = 0; f.c.y = 0; f.c.z = 0;
                if (!anchor->FUN_0022d2b0(&f.c, 0x3727c5ac)) {
                    actor->FUN_000350c0(&f.b);
                    f.a = *anchor;
                    done = true;
                }
            }
            if (!done) {
                Singleton *s = FUN_001c3d90();
                f.b = *s->FUN_001c39d0();
                f.a = *s->FUN_001c39c0();
            }
            Camera *c = camera;
            actor->FUN_000400e0(&f.b, &f.a, c->field14, c->field18, 0x32);
        }
    }
    if (actor->target != 0) {
        actor->flag32c = 1;
        actor->flag32d = 1;
    }
    return 1;
}

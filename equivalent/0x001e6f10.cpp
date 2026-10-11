// STATUS: equivalent (tools/equiv.py level 3: 40 inputs, branch coverage 55/62, incomplete)
// FUN_001e6f10 @ 0x001e6f10
struct Vec3 {
    float x, y, z;
};

class Tracker {
public:
    void FUN_00034c80(float v);
};

class ObjSub {
public:
    void FUN_001b6d70(float dt);
};

class Zone {
public:
    int FUN_0007ad00(const void *pos);
};

class Ground {
public:
    int FUN_002043e0();
    char FUN_00204440(int id);
    int FUN_00204200(float x, int y, float z);
};

class Holder {
public:
    Ground *FUN_000862a0();
};

class Caster {
public:
    char FUN_00201f20(Vec3 *from, int mask, Vec3 *hit, Vec3 *normal, int *out5, int *out6);
};

class Settings {
public:
    char FUN_0023f760(const char *name, int a, int b);
};

class Obj {
public:
    char FUN_001d62a0();
    char FUN_001d6980();
    int FUN_001d6990();
    char FUN_001d69b0();
    int FUN_001d69d0();
    void FUN_001d69c0(int v);
    void FUN_001d69e0(int v);
    Vec3 *FUN_001d6b40();
    int FUN_001d6c70();
    void FUN_001d7590();
    void FUN_001d7810(Vec3 v);
    void FUN_001d7ff0();
    void FUN_001d6290(int v);
    void FUN_001d6770();
    void FUN_001d8fc0(float v);

    char pad0[8];
    float pos[3];
    char pad1[0xf9 - 0x14];
    char dead;
    char pad1b[2];
    int mode;
    char pad2[0x11c - 0x100];
    Tracker *tracker;
    char pad3[0x144 - 0x120];
    char timed;
    char pad4[3];
    int held;
    char pad5[0x14d - 0x14c];
    char zoned;
    char pad6[0x1a4 - 0x14e];
    ObjSub sub;
    char pad7[0x1c4 - 0x1a5];
    float timer;
};

struct Globals {
    char pad0[0x24];
    Caster *caster;
    char pad1[0x4c - 0x28];
    Zone *zone;
    char pad2[4];
    Holder *holder;
};


extern float DAT_0042189c;
extern Settings *DAT_004dd6e8;
extern Globals *DAT_004dd700;

class World {
public:
    void FUN_001e6f10(int unused, float dt);
    void FUN_001e57a0();
    void FUN_001e6390();
    char FUN_001dc1f0(Obj *obj);
    void FUN_001e5720(Obj *obj);
    void FUN_001e5bc0(int v);

    char pad0[0x1e620];
    Obj *objs[128];
    int count;
    char pad1[0x1e830 - 0x1e824];
    Globals *globals;
    char gather;
    char pad2[3];
    float threshold;
};

void World::FUN_001e6f10(int unused, float dt)
{
    if (globals->holder->FUN_000862a0()->FUN_002043e0() == 0)
        return;
    FUN_001e57a0();
    FUN_001e6390();
    if (!DAT_004dd6e8->FUN_0023f760("DoPhysics", 0x66, 1))
        return;
    for (int i = count - 1; i >= 0; i--) {
        Obj *obj = objs[i];
        if (!obj)
            continue;
        if (obj->FUN_001d62a0())
            continue;
        if (obj->timed && obj->FUN_001d6980() && obj->mode != 2 && obj->mode != 3 &&
            obj->FUN_001d6990() != 10) {
            float d = obj->timer - dt;
            if (d > 1.0f && d < 1.5f)
                obj->tracker->FUN_00034c80(DAT_0042189c);
            if (d <= 0.0f) {
                obj->FUN_001d7ff0();
                obj->FUN_001d6290(1);
                continue;
            }
            obj->timer = d;
        }
        if (obj->zoned) {
            if (!DAT_004dd700->zone->FUN_0007ad00(&obj->pos[0])) {
                obj->FUN_001d7ff0();
                obj->FUN_001d6290(1);
            }
        }
        bool remove = false;
        if (gather) {
            Vec3 v = *obj->FUN_001d6b40();
            bool done = false;
            if (v.y < threshold && obj->mode != 2 && obj->mode != 3 && obj->held == 0) {
                if (obj->FUN_001d69b0()) {
                    Globals *g = DAT_004dd700;
                    Holder *h = g->holder;
                    int id = obj->FUN_001d69d0();
                    if (h->FUN_000862a0()->FUN_00204440(id)) {
                        Vec3 *pos = obj->FUN_001d6b40();
                        Vec3 from;
                        from.x = pos->x;
                        from.y = 300.0f;
                        from.z = pos->z;
                        Vec3 hit;
                        Vec3 normal;
                        if (!DAT_004dd700->caster->FUN_00201f20(&from, 1, &hit, &normal, 0, 0)) {
                            remove = true;
                        } else {
                            hit.y = hit.y + 0.1f;
                            obj->FUN_001d7810(hit);
                            done = true;
                        }
                    }
                } else if (FUN_001dc1f0(obj)) {
                    obj->FUN_001d69c0(1);
                    obj->FUN_001d7590();
                    Vec3 *q = obj->FUN_001d6b40();
                    float qx = q->x;
                    float qz = q->z;
                    int id = DAT_004dd700->holder->FUN_000862a0()->FUN_00204200(qx, 0, qz);
                    obj->FUN_001d69e0(id);
                    if (id == -1)
                        remove = true;
                } else {
                    remove = true;
                }
                if (remove) {
                    obj->FUN_001d6770();
                    FUN_001e5720(obj);
                    continue;
                }
                if (done)
                    obj->FUN_001d69c0(0);
            } else {
                obj->FUN_001d69c0(0);
            }
        }
        if (obj->held == 0)
            obj->FUN_001d8fc0(dt * 1000.0f);
        obj->sub.FUN_001b6d70(dt);
    }
    for (int i = count - 1; i >= 0; i--) {
        Obj *obj = objs[i];
        if (obj && obj->FUN_001d62a0())
            FUN_001e5bc0(obj->FUN_001d6c70());
    }
}

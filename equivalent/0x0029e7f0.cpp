// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 18/18)
// FUN_0029e7f0 @ 0x0029e7f0
struct Vec3 {
    float x, y, z;
};

namespace pure3d {
class Light {
public:
    virtual void v0();
    char pad04[0xf];
    char enabled;               // 0x13
    int id;                     // 0x14
    void FUN_002a0800(float* x, float* y, float* z);
};

class DirectionalLight : public Light {
public:
    void FUN_002a2f20(float* x, float* y, float* z);
};

class PointLight : public Light {
public:
    void FUN_002c3f20(float* a, float* b, float* c);
};

class SpotLight : public Light {
public:
    void FUN_002c41c0(float* a, float* b, float* c);
    void FUN_002c4200(float* a, float* b, float* c);
    void FUN_002c4150(float* x, float* y, float* z);
};
}

struct LightRec {
    char pad00[4];
    int type;                   // 0x04
    int id;                     // 0x08
    Vec3 pos;                   // 0x0c
    Vec3 dir;                   // 0x18
    float a, b, c;              // 0x24
    char pad30[0x40 - 0x30];
    void FUN_0029c240(int id, float* v2, float* v1, float r0, float r1, float r2, float q0,
                      float q1, float q2);
};

struct LightSet {
    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    pure3d::Light** items;      // 0x18
};

class LightList {
public:
    void FUN_0029e7f0(LightSet* set, Vec3* ambient, int tag);

    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    char pad18[4];
    int tag;                    // 0x1c
    char pad20[4];
    LightRec* recs;             // 0x24
    Vec3 ambient;               // 0x28
    char pad34[4];
    char anyEnabled;            // 0x38
};

void LightList::FUN_0029e7f0(LightSet* set, Vec3* ambientColor, int newTag)
{
    int n = 0;
    anyEnabled = 0;
    for (int i = 0; i < set->count; i++) {
        if (n >= capacity)
            break;
        if (i >= set->capacity)
            continue;
        pure3d::Light* light = set->items[i];
        if (!light)
            continue;
        if (light->enabled)
            anyEnabled = 1;

        pure3d::DirectionalLight* dl = dynamic_cast<pure3d::DirectionalLight*>(light);
        if (dl) {
            Vec3 v;
            dl->FUN_002a2f20(&v.x, &v.y, &v.z);
            LightRec* rec = &recs[n];
            int id = dl->id;
            rec->type = 0;
            rec->id = id;
            rec->dir = v;
            n++;
            continue;
        }
        pure3d::PointLight* pl = dynamic_cast<pure3d::PointLight*>(light);
        if (pl) {
            float a, b, c;
            Vec3 v;
            pl->FUN_002c3f20(&a, &b, &c);
            pl->FUN_002a0800(&v.x, &v.y, &v.z);
            LightRec* rec = &recs[n];
            int id = pl->id;
            rec->type = 1;
            rec->id = id;
            rec->pos = v;
            rec->a = a;
            rec->b = b;
            rec->c = c;
            n++;
            continue;
        }
        pure3d::SpotLight* sl = dynamic_cast<pure3d::SpotLight*>(light);
        if (sl) {
            float q0, q1, q2, r0, r1, r2;
            Vec3 v2, v1;
            sl->FUN_002c41c0(&q0, &q1, &q2);
            sl->FUN_002c4200(&r0, &r1, &r2);
            sl->FUN_002a0800(&v2.x, &v2.y, &v2.z);
            sl->FUN_002c4150(&v1.x, &v1.y, &v1.z);
            recs[n].FUN_0029c240(sl->id, &v2.x, &v1.x, r0, r1, r2, q0, q1, q2);
            n++;
        }
    }
    count = n;
    ambient = *ambientColor;
    tag = newTag;
}

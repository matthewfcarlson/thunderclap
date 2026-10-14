// STATUS: equivalent (tools/equiv.py level 3: 16013 inputs, branch coverage 18/18)
// FUN_0029e7f0 @ 0x0029e7f0
// FUN_0029e7f0 @ 0x0029e7f0
struct Vec3_29e7f0 {
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

struct LightRec_29e7f0 {
    char pad00[4];
    int type;                   // 0x04
    int id;                     // 0x08
    Vec3_29e7f0 pos;                   // 0x0c
    Vec3_29e7f0 dir;                   // 0x18
    float a, b, c;              // 0x24
    char pad30[0x40 - 0x30];
    void FUN_0029c240(int id, float* v2, float* v1, float r0, float r1, float r2, float q0,
                      float q1, float q2);
};

struct LightSet_29e7f0 {
    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    pure3d::Light** items;      // 0x18
};

class LightList_29e7f0 {
public:
    void FUN_0029e7f0(LightSet_29e7f0* set, Vec3_29e7f0* ambient, int tag);

    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    char pad18[4];
    int tag;                    // 0x1c
    char pad20[4];
    LightRec_29e7f0* recs;             // 0x24
    Vec3_29e7f0 ambient;               // 0x28
    char pad34[4];
    char anyEnabled;            // 0x38
};

// Locals in the original's stack order: the out-parameters of the light queries share the frame with
// the loop counters, so a stale word from one light kind is visible to the next.
struct Frame_29e7f0 {
    int n;
    int i;
    float c, b, a;              // point light attenuation, read back in reverse
    float q2, q1, q0;           // spot light
    float r2, r1, r0;
    Vec3_29e7f0 dirV;
    Vec3_29e7f0 pointV;
    Vec3_29e7f0 v1;
    Vec3_29e7f0 v2;
};

void LightList_29e7f0::FUN_0029e7f0(LightSet_29e7f0* set, Vec3_29e7f0* ambientColor, int newTag)
{
    Frame_29e7f0 f;
    f.n = 0;
    anyEnabled = 0;
    for (f.i = 0; f.i < set->count; f.i++) {
        if (f.n >= capacity)
            break;
        if (f.i >= set->capacity)
            continue;
        pure3d::Light* light = set->items[f.i];
        if (!light)
            continue;
        if (light->enabled)
            anyEnabled = 1;

        pure3d::DirectionalLight* dl = dynamic_cast<pure3d::DirectionalLight*>(light);
        if (dl) {
            dl->FUN_002a2f20(&f.dirV.x, &f.dirV.y, &f.dirV.z);
            LightRec_29e7f0* rec = &recs[f.n];
            int id = dl->id;
            rec->type = 0;
            rec->id = id;
            rec->dir = f.dirV;
            f.n++;
            continue;
        }
        pure3d::PointLight* pl = dynamic_cast<pure3d::PointLight*>(light);
        if (pl) {
            pl->FUN_002c3f20(&f.a, &f.b, &f.c);
            pl->FUN_002a0800(&f.pointV.x, &f.pointV.y, &f.pointV.z);
            LightRec_29e7f0* rec = &recs[f.n];
            int id = pl->id;
            rec->type = 1;
            rec->id = id;
            rec->pos = f.pointV;
            rec->a = f.a;
            rec->b = f.b;
            rec->c = f.c;
            f.n++;
            continue;
        }
        pure3d::SpotLight* sl = dynamic_cast<pure3d::SpotLight*>(light);
        if (sl) {
            sl->FUN_002c41c0(&f.q0, &f.q1, &f.q2);
            sl->FUN_002c4200(&f.r0, &f.r1, &f.r2);
            sl->FUN_002a0800(&f.v2.x, &f.v2.y, &f.v2.z);
            sl->FUN_002c4150(&f.v1.x, &f.v1.y, &f.v1.z);
            recs[f.n].FUN_0029c240(sl->id, &f.v2.x, &f.v1.x, f.r0, f.r1, f.r2, f.q0, f.q1, f.q2);
            f.n++;
        }
    }
    count = f.n;
    ambient = *ambientColor;
    tag = newTag;
}

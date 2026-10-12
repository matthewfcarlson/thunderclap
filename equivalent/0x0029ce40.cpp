// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 30/32, incomplete)
// FUN_0029ce40 @ 0x0029ce40
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Light {
    char pad00[0x11];
    char active;                // 0x11
    char pad12[2];
    unsigned int color;         // 0x14 (0x00RRGGBB)
    Vec3 pos;                   // 0x18
    char pad24[0x64 - 0x24];
    float strength;             // 0x64

    float FUN_002a0d00(Vec3* p);
    void FUN_002c3d20(float* a, float* b, float* falloff);
};

struct LightList {
    char pad00[0x10];
    int count;                  // 0x10
    int size;                   // 0x14
    Light** items;              // 0x18
};

struct LightDesc {
    char pad00[0x18];
    unsigned char flags;        // 0x18
    char pad19[7];
};

struct LightSet {
    LightList* list;            // 0x00
    LightDesc* descs;           // 0x04
};

struct DynLightSet {
    LightList* list;            // 0x00
};

class Lighting {
public:
    void FUN_0029ce40(Vec3* out, Vec3* p);

    char pad00[0x28];
    char frozen;                // 0x28
    char pad29[3];
    LightSet* statics;          // 0x2c
    char pad30[0x3c - 0x30];
    DynLightSet* dynamics;      // 0x3c
};

void Lighting::FUN_0029ce40(Vec3* out, Vec3* p)
{
    if (!out)
        return;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;

    int i;
    for (i = statics->list->size - 1; i >= 0; i--) {
        if (i >= statics->list->count)
            continue;
        Light* item = statics->list->items[i];
        if (!item)
            continue;
        unsigned int color = item->color;
        double v = item->FUN_002a0d00(p);
        if (v != 0.0) {
            if (statics->descs[i].flags & 2)
                v = v * -1.0f;
            out->x = (float)(((color >> 16) & 0xff) * v + out->x);
            out->y = (float)(((color >> 8) & 0xff) * v + out->y);
            out->z = (float)((color & 0xff) * v + out->z);
        }
    }

    if (frozen)
        return;
    for (i = dynamics->list->size - 1; i >= 0; i--) {
        if (i >= dynamics->list->count)
            continue;
        Light* item = dynamics->list->items[i];
        if (!item)
            continue;
        if (!item->active)
            continue;
        if (item->FUN_002a0d00(p) == 0.0f)
            continue;

        Vec3 d;
        float a, b, falloff;
        d.x = p->x - item->pos.x;
        d.y = p->y - item->pos.y;
        d.z = p->z - item->pos.z;
        item->FUN_002c3d20(&a, &b, &falloff);
        double len = d.FUN_0022d110();
        double lenSq = len * len * falloff;
        double w = item->strength;
        double lit = w * w * falloff * 0.0588235f;
        if (lit > 1.0f)
            lit = 1.0f;
        if (lenSq > 0.0) {
            double k = lit / lenSq;
            unsigned int color = item->color;
            out->x = (float)(((color >> 16) & 0xff) * k + out->x);
            out->y = (float)(((color >> 8) & 0xff) * k + out->y);
            out->z = (float)((color & 0xff) * k + out->z);
        }
    }
}

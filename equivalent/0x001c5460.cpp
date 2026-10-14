// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 30/30)
// Render::Object::vfunc_3 @ 0x001c5460
extern unsigned char DAT_004c518c;

float __cdecl FUN_00018710(float *out, float *value);

class Gate_1c5460 {
public:
    char FUN_001d4e70();
};

struct Owner_1c5460 {
    char pad00[0xec];
    Gate_1c5460 *gate;
};

class Renderer_1c5460;

namespace Render {
class Object {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Renderer_1c5460 *r, int unused);
    char pad04[0xc];
    void *drawable;
    char pad14[8];
    Owner_1c5460 *owner;
    char pad20[2];
    unsigned char hasOwner;
    char pad23[0x80 - 0x23];
    float fade80;
    char pad84[0x90 - 0x84];
    float fade90;
    union {
        float f;
        unsigned int bits;
    } mode94;
    char pad98[4];
    int value9c;
    float duration;
    float period;
    unsigned char active;
    unsigned char flagA9;
    void FUN_001c5130(float a, float b);
    void FUN_001c51b0(Renderer_1c5460 *r);
};
}

class Renderer_1c5460 {
public:
    char pad00[0xc0];
    int state;
    char padc4[0xcc - 0xc4];
    unsigned char flagCC;
    char FUN_001c17d0(Render::Object *o);
    void FUN_001c24d0(void *drawable, int v, float f);
    void FUN_001c1330(int v);
};

void Render::Object::vfunc_3(Renderer_1c5460 *r, int unused)
{
    if (!active)
        return;
    if (!DAT_004c518c)
        return;

    if (r->flagCC && (mode94.f == 0.0f || mode94.bits == 0x3f000000) && flagA9) {
        bool skip = false;
        if (hasOwner && owner != 0) {
            if (owner->gate->FUN_001d4e70())
                skip = true;
        }
        if (!skip && r->FUN_001c17d0(this))
            FUN_001c5130(0.5f, 0.25f);
    }

    if (fade90 >= 1.0f)
        return;
    if (fade80 >= 1.0f)
        return;

    void *d = drawable;
    if (d == 0)
        return;

    float ratio = 0.0f;
    if (duration > 1e-5f) {
        float out = 0.0f;
        ratio = duration / period;
        ratio = FUN_00018710(&out, &ratio);
    }
    r->FUN_001c24d0(d, value9c, ratio);
    r->FUN_001c1330(r->state);
    if (drawable)
        FUN_001c51b0(r);
    r->FUN_001c1330(0);
}

// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// pure3d::BlendFrameController::vfunc_14 @ 0x00286210
struct BlendEntry {
    float cur;          // +0x00
    float lo;           // +0x04
    float hi;           // +0x08
    char pad0c[0x18 - 0x0c];
    float value;        // +0x18
    char pad1c[0x20 - 0x1c];
    int state;          // +0x20
    unsigned char active; // +0x24
    char pad25[0x2c - 0x25];
};

namespace pure3d {
class BlendFrameController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(float lo, float hi);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float vfunc_20();
    char pad[0x28 - 0x4];
    unsigned int count;       // 0x28
    BlendEntry entries[1];    // 0x2c
};
}

void pure3d::BlendFrameController::vfunc_14(float lo, float hi)
{
    if (count == 0)
        return;
    BlendEntry *e = &entries[count - 1];
    if (lo != e->lo || hi != e->hi) {
        e->lo = lo;
        e->hi = hi;
        float v;
        if (e->cur >= e->lo && e->cur <= e->hi)
            v = e->cur;
        else if (e->cur > e->hi)
            v = e->hi;
        else
            v = e->lo;
        e->cur = v;
        e->value = vfunc_20();
        e->active = (e->state != 3 && e->state != 5) ? 1 : 0;
    }
}

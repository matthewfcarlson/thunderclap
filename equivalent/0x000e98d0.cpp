// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// HSlider::vfunc_3 @ 0x000e98d0
class Metrics {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    float FUN_000dfbf0(const char *s);
};

struct Font {
    char pad0[0x24];
    Metrics *metrics;
};

struct LayoutEntry {
    float scale;
    int f4;
    int f8;
    int f12;
};

struct Layout {
    Font *font;
    int f4;
    LayoutEntry entries[8];
    int index;
    float f8c;
    Layout *FUN_000f7fe0(Font *font);
    float FUN_000f88a0(const unsigned short *text);
    void FUN_000f78e0();
};

class Fonts {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Font *v44();
};

struct Hold {
    char pad0[4];
    Fonts *fonts;
};

class HSlider;

class Owner {
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
    virtual void v14();
    virtual void v15();
    virtual float v16(HSlider *s);
    virtual float v17(HSlider *s);
    char pad04[8 - 4];
    Hold *hold;
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner *owner;
};

class HSlider : public FEObject {
public:
    virtual void vfunc_3();
    unsigned short text[0xa4];
    float f160;
    char pad164[4];
    int f168;
    char pad16c[0x17c - 0x16c];
    float f17c;
};

void HSlider::vfunc_3()
{
    struct Frame {
        float k;
        Layout layout;
    } fr;

    FEObject::vfunc_3();
    f17c = 0.0f;
    fr.layout.FUN_000f7fe0(owner->hold->fonts->v44());
    fr.k = owner->v17(this);
    fr.layout.entries[fr.layout.index].scale = owner->v16(this) * fr.k;
    f17c = fr.layout.FUN_000f88a0(text) + f17c;

    LayoutEntry *entry = &fr.layout.entries[fr.layout.index];
    Metrics *m = fr.layout.font->metrics;
    fr.k = 14.0f / m->v7();
    f17c = m->FUN_000dfbf0(": ") * entry->scale * fr.k + f17c;

    entry = &fr.layout.entries[fr.layout.index];
    m = fr.layout.font->metrics;
    fr.k = 14.0f / m->v7();
    f17c = m->FUN_000dfbf0("0") * entry->scale * fr.k + f17c;

    int digits = (int)f160;
    if (digits > 0) {
        do {
            m = fr.layout.font->metrics;
            LayoutEntry *e = &fr.layout.entries[fr.layout.index];
            fr.k = 14.0f / m->v7();
            f17c = m->FUN_000dfbf0("0") * e->scale * fr.k + f17c;
            digits = digits / 10;
        } while (digits > 0);
    }

    if (f168 > 0) {
        m = fr.layout.font->metrics;
        entry = &fr.layout.entries[fr.layout.index];
        fr.k = 14.0f / m->v7();
        f17c = m->FUN_000dfbf0(".") * entry->scale * fr.k + f17c;

        m = fr.layout.font->metrics;
        fr.k = 14.0f / m->v7();
        f17c = f168 * (m->FUN_000dfbf0("0") * entry->scale * fr.k) + f17c;
    }
    fr.layout.FUN_000f78e0();
}

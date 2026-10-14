// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// TextWindow::vfunc_3 @ 0x000ed360
// TextWindow::vfunc_3 @ 0x000ed360: recompute the line scale from the owner's reported extent
class Metrics_ed360 {
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
    Metrics_ed360 *metrics;
};

struct LayoutEntry {
    float scale;
    int f4;
    int f8;
    int f12;
};

struct Layout_ed360 {
    Font *font;
    int f4;
    LayoutEntry entries[8];
    int index;
    float f8c;
    Layout_ed360 *FUN_000f7fe0(Font *font);
    float FUN_000f88a0(const unsigned short *text);
    void FUN_000f78e0();
};

class Fonts_ed360 {
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

struct Hold_ed360 {
    char pad0[4];
    Fonts_ed360 *fonts;
};

struct Vec3_ed360 {
    float x, y, z;
};

class FEObject;

class Owner_ed360 {
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
    virtual void v15(Vec3_ed360 *out, FEObject *who);
    virtual float v16(FEObject *who);
    virtual float v17(FEObject *who);
    char pad04[8 - 4];
    Hold_ed360 *hold;
};

class FEObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner_ed360 *owner;
};

class TextWindow : public FEObject {
public:
    virtual void vfunc_3();
    char pad18[0x968 - 0x18];
    float f968;
    char pad96c[0x97c - 0x96c];
    float f97c;

    void FUN_000ecf10(float v);
};

void TextWindow::vfunc_3()
{
    struct Frame {
        float k;
        Vec3_ed360 tmp;
        Layout_ed360 layout;
    } fr;

    FEObject::vfunc_3();
    fr.layout.FUN_000f7fe0(owner->hold->fonts->v44());
    fr.k = owner->v17(this);
    fr.layout.entries[fr.layout.index].scale = owner->v16(this) * fr.k;
    f968 = 14.0f * fr.layout.entries[fr.layout.index].scale;
    owner->v15(&fr.tmp, this);
    FUN_000ecf10(fr.tmp.x * f97c);
    fr.layout.FUN_000f78e0();
}

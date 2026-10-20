// STATUS: equivalent (tools/equiv.py level 3: 582 inputs, branch coverage 129/142, incomplete)
// TextSelector::vfunc_5 @ 0x000ea7c0
// TextSelector::vfunc_5 (FUN_000ea7c0): draws the selector's label, entries and scroll controls.
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct Vec3_ea7c0 {
    float x, y, z;
};

union Word_ea7c0 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_ea7c0 {
    Word_ea7c0 a, b, c, d;
};

struct Source;

struct Builder {
    unsigned int hdr[2];
    Cell_ea7c0 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source* src);
    void FUN_000f78e0();
    void FUN_000f87f0(void* a, void* b);
    void FUN_000f8280(unsigned int a, unsigned int b, unsigned int c);
    float FUN_000f88a0(void* a);
    void FUN_000f80e0(const char* s, void* a, void* b);
    float FUN_000e8600(const char* s, int a);
};

namespace pure3d {
class FrameController {
  public:
    virtual void v0();
    virtual void v1();
};

class TextureAnimationController : public FrameController {
  public:
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
    virtual void v12(float value);
};
} // namespace pure3d

struct Level2_ea7c0 {
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
    virtual Source* v44();
};

struct Obj958_ea7c0 {
    char pad0[0x14];
    float f14;
    char pad18[8];
};

struct Obj978_ea7c0 {
    char pad0[0x10];
    unsigned int col10;
};

struct Hold_ea7c0 {
    char pad0[4];
    Level2_ea7c0* fonts;
    char pad8[0x958 - 8];
    Obj958_ea7c0 o958;
    Obj978_ea7c0 o978;
};

class TextSelector;

class Owner_ea7c0 {
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
    virtual bool v13(void* obj);
    virtual void v14(Vec3_ea7c0* out, void* obj);
    virtual void v15(Vec3_ea7c0* out, void* obj);
    virtual float v16(void* obj);
    virtual float v17(void* obj);
    char pad04[4];
    Hold_ea7c0* hold;
};

struct Pass_ea7c0 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_ea7c0 {
    Pass_ea7c0* pass;
    void FUN_00293d00(const Vec3_ea7c0* v);
    void FUN_00293da0(int a, int b, int c);
    void FUN_00293d40(float x, int y, int z);
};

class Widget_ea7c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};

struct Obj8_ea7c0 {
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
    virtual pure3d::FrameController* v18(int a);
};

struct Obj3c_ea7c0 {
    char pad0[8];
    Obj8_ea7c0* p8;
};

struct Obj44 {
    char pad0[0x3c];
    Obj3c_ea7c0* p3c;
};

class Ctl28 : public Widget_ea7c0 {
  public:
    char pad04[0x44 - 4];
    Obj44* p44;
};

struct Elem_ea7c0 {
    char data[0x24];
};

struct Str24 {
    char pad0[0x10];
    int w10;
    int i14;
    char pad18[0x24 - 0x18];
};

struct Entry_ea7c0 {
    Str24 str;
    Elem_ea7c0* elems;
    Ctl28* ctl;
    int count;
    int cur;
    unsigned char b34;
    char pad35[3];
};

struct ColorPack {
    unsigned int v;
    ColorPack* FUN_000115c0(int a, int b, int c, int d);
};

union Quad_ea7c0 {
    unsigned int u;
    unsigned char b[4];
};

void __cdecl FUN_000e11a0(Vec3_ea7c0 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_ea7c0 v, int a, int b);

// Group the local vectors with the builder, keeping each address stable when passed to a callee.
union IntFloat {
    float f;
    int i;
    unsigned int u;
};

struct Frame_ea7c0 {
    unsigned int savedColor;
    union {
        ColorPack temporaryColor;
        int alphaProduct;
    };
    int row;
    IntFloat numeric;
    Vec3_ea7c0 offset;
    Obj978_ea7c0* style;
    Obj958_ea7c0* fade;
    Vec3_ea7c0 origin;
    Builder builder;
    Vec3_ea7c0 unstyledElementOffset;
    Vec3_ea7c0 horizontalAdvance;
    ColorPack packedColor;
    Vec3_ea7c0 listElementOffset;
    Vec3_ea7c0 verticalAdvance;
    Vec3_ea7c0 itemOrigin;
    Vec3_ea7c0 selectedElementOffset;
    Vec3_ea7c0 iconOffset;
    Vec3_ea7c0 selectedMeasurement;
    Vec3_ea7c0 listMeasurement;
    Vec3_ea7c0 alternateMeasurement;
};

class TextSelector {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();

    char pad04[0x10];
    Owner_ea7c0* owner;
    char str18[0x3c - 0x18];
    union {
        unsigned int w;
        unsigned char b[4];
    } c3c;
    unsigned char flag40;
    char pad41[7];
    unsigned char flag48;
    char pad49[3];
    int val4c;
    Widget_ea7c0* w50;
    int v54, v58, v5c;
    Widget_ea7c0* w60;
    Widget_ea7c0* w64;
    char pad68[0x74 - 0x68];
    unsigned char active;
    char pad75[3];
    Vec3_ea7c0 anchor;
    char pad84[0xa4 - 0x84];
    void* pa4;
    char pada8[0x148 - 0xa8];
    int val148;
    char pad14c[4];
    int count;
    int index;
    Entry_ea7c0 items[128];
    int i1d58;
    int i1d5c;
    char pad1d60[8];
    float f1d68;
    float f1d6c;
    float f1d70;
    float f1d74;
    float f1d78;
    int i1d7c;
    int i1d80;
    char pad1d84[8];
    Widget_ea7c0* p1d8c;
    Widget_ea7c0* p1d90;
    char pad1d94[4];
    TextSelector* p1d98;
    Quad_ea7c0 c1d9c;
    Quad_ea7c0 c1da0;
    unsigned int i1da4;

    Vec3_ea7c0* FUN_000e2820(Vec3_ea7c0* out);
};

void TextSelector::vfunc_5() {
    if (active == 0)
        return;

    Frame_ea7c0 frame;
    Builder& b = frame.builder;

    if (flag40) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&frame.origin, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
        owner->v15(&frame.offset, this);
        FUN_000e11a0(frame.offset, val148, 2);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (flag48) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&frame.origin, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
        owner->v15(&frame.offset, this);
        FUN_000e0cc0(frame.offset, val4c, 0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (w50 != 0) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&frame.origin, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293da0(v54, v58, v5c);
        w50->v8(0, 0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }

    b.FUN_000f7fe0(owner->hold->fonts->v44());
    frame.numeric.f = owner->v17(this);
    b.cells[b.cursor].a.f = owner->v16(this) * frame.numeric.f;
    b.cells[b.cursor].c.i = 2;
    b.cells[b.cursor].b.i = 0;
    b.cells[b.cursor].d.u = c3c.w;
    b.hdr[1] = c3c.w;
    frame.fade = &owner->hold->o958;
    if (owner->v13(this) && frame.fade == 0)
        b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008),
                       (*(unsigned int*)&DAT_004de94c));

    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
    owner->v14(&frame.origin, this);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);

    frame.style = 0;
    if (owner->v13(this)) {
        if (i1d5c == 0 && w60 != 0) {
            w60->v8(0, 0);
            b.cells[b.cursor].d.u = i1da4;
        } else {
            b.cells[b.cursor].d.u = c3c.w;
            frame.style = &owner->hold->o978;
        }
    } else {
        if (i1d5c == 0 && w64 != 0) {
            w64->v8(0, 0);
        } else {
            frame.style = &owner->hold->o978;
        }
        frame.numeric.i = c1d9c.b[3] * c3c.b[3];
        int alpha = (int)(frame.numeric.i * 0.00392156886f);
        b.cells[b.cursor].d.u = (alpha << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
    }

    if (i1d5c == 0)
        b.FUN_000f87f0(str18, frame.style);
    if (p1d98 == 0) {
        float width = b.FUN_000f88a0(str18);
        frame.offset.x = width;
        frame.offset.y = 0.0f;
        frame.offset.z = 0.0f;
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.offset);
        if (i1d5c == 0) {
            b.FUN_000f80e0(": ", pa4, frame.style);
            float separatorWidth = b.FUN_000e8600(": ", 0);
            frame.offset.x = separatorWidth;
            frame.offset.y = 0.0f;
            frame.offset.z = 0.0f;
            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.offset);
        }
    } else {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        p1d98->owner->v14(&frame.origin, p1d98);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);
    }
    if (owner->v13(this) && frame.fade == 0)
        b.cells[b.cursor].d.u = b.hdr[1];

    if (i1d58 <= 0) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
        b.FUN_000f78e0();
        return;
    }

    if (i1d5c == 0) {
        Entry_ea7c0* selected = &items[index];
        pure3d::TextureAnimationController* animation = 0;
        if (selected->ctl)
            animation =
                dynamic_cast<pure3d::TextureAnimationController*>(selected->ctl->p44->p3c->p8->v18(0));
        bool focused = owner->v13(this);
        if (frame.fade != 0) {
            if (focused) {
                if (w60 != 0) {
                    b.cells[b.cursor].d.u = i1da4;
                    b.FUN_000f87f0(&items[index], frame.style);
                } else {
                    float opacity = frame.fade->f14 * 255.0f;
                    b.cells[b.cursor].d.u = 0;
                    Obj978_ea7c0* style = &owner->hold->o978;
                    frame.savedColor = style->col10;
                    style->col10 = (255 - (int)opacity) << 24;
                    b.FUN_000f87f0(&items[index], style);
                    style->col10 = frame.savedColor;
                    frame.numeric.i = c1da0.b[3] * c3c.b[3];
                    int alpha = (int)(frame.numeric.i * 0.00392156886f);
                    b.cells[b.cursor].d.u =
                        frame.temporaryColor.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], alpha)->v;
                    b.FUN_000f87f0(&items[index], frame.fade);
                }
            } else {
                frame.numeric.i = c1d9c.b[3] * c3c.b[3];
                int alpha = (int)(frame.numeric.i * 0.00392156886f);
                unsigned int color =
                    frame.temporaryColor.FUN_000115c0(c1d9c.b[2], c1d9c.b[1], c1d9c.b[0], alpha)->v;
                b.cells[b.cursor].d.u = color;
                b.FUN_000f87f0(&items[index], frame.style);
            }
            if (animation) {
                animation->v12(1.0f);
                animation->v7();
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                frame.offset.x = f1d74 * 0.5f;
                frame.offset.y = 0.0f;
                frame.offset.z = 0.0f;
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.offset);
                items[index].ctl->v8(0, 0);
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
            }
        } else {
            if (focused)
                b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008),
                               (*(unsigned int*)&DAT_004de94c));
            b.FUN_000f87f0(&items[index], frame.style);
            if (animation) {
                animation->v12(1.0f);
                animation->v7();
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                frame.offset.x = f1d74 * 0.5f;
                frame.offset.y = 0.0f;
                frame.offset.z = 0.0f;
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.offset);
                items[index].ctl->v8(0, 0);
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
            }
            if (owner->v13(this))
                b.cells[b.cursor].d.u = b.hdr[1];
        }
    } else {
        int mode = i1d5c;
        frame.row = i1d7c;
        if (mode == 2) {
            for (; frame.row <= i1d80; frame.row++) {
                Entry_ea7c0* entry = &items[frame.row];
                if (entry->str.w10 == 0 && entry->str.i14 == -1)
                    continue;
                b.cells[b.cursor].c.i = 2;
                pure3d::TextureAnimationController* animation = 0;
                if (entry->ctl)
                    animation =
                        dynamic_cast<pure3d::TextureAnimationController*>(entry->ctl->p44->p3c->p8->v18(0));
                Obj958_ea7c0* fade = frame.fade;
                if (fade != 0) {
                    if (frame.row == index) {
                        if (owner->v13(this)) {
                            frame.numeric.f = fade->f14;
                            if (w60 != 0)
                                w60->v8(0, 0);
                            float opacity = frame.numeric.f * 255.0f;
                            b.cells[b.cursor].d.u = 0;
                            Hold_ea7c0* hold = owner->hold;
                            Obj978_ea7c0* style = &hold->o978;
                            frame.savedColor = style->col10;
                            style->col10 = (255 - (int)opacity) << 24;
                            b.FUN_000f87f0(&items[index], style);
                            style->col10 = frame.savedColor;
                            if (w60 != 0) {
                                b.cells[b.cursor].d.u = 0xff000000;
                            } else {
                                frame.savedColor = c1da0.b[3] * c3c.b[3];
                                int alpha = (int)((int)frame.savedColor * 0.00392156886f);
                                b.cells[b.cursor].d.u =
                                    frame.packedColor.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], alpha)
                                        ->v;
                            }
                            b.FUN_000f87f0(&items[index], w60 != 0 ? 0 : (void*)fade);
                            if (items[index].elems) {
                                Elem_ea7c0* element = items[index].elems + items[index].cur;
                                float* width = &FUN_000e2820(&frame.selectedMeasurement)->x;
                                float elementWidth = b.FUN_000f88a0(element);
                                float offset = *width - elementWidth;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                                frame.offset.x = offset;
                                frame.offset.y = 0.0f;
                                frame.offset.z = 0.0f;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.offset);
                                b.FUN_000f87f0(element, w60 != 0 ? 0 : (void*)fade);
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                            }
                        } else {
                            if (w64 != 0)
                                w64->v8(0, 0);
                            b.cells[b.cursor].d.u = c3c.w;
                            b.FUN_000f87f0(entry, frame.style);
                            if (entry->elems) {
                                Elem_ea7c0* element = entry->elems + entry->cur;
                                float* width = &FUN_000e2820(&frame.alternateMeasurement)->x;
                                float elementWidth = b.FUN_000f88a0(element);
                                float offset = *width - elementWidth;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                                frame.selectedElementOffset.x = offset;
                                frame.selectedElementOffset.y = 0.0f;
                                frame.selectedElementOffset.z = 0.0f;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)
                                    ->FUN_00293d00(&frame.selectedElementOffset);
                                b.FUN_000f87f0(element, frame.style);
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                            }
                        }
                    } else {
                        if (w64 != 0)
                            w64->v8(0, 0);
                        frame.alphaProduct = c1d9c.b[3] * c3c.b[3];
                        int alpha = (int)(frame.alphaProduct * 0.00392156886f);
                        b.cells[b.cursor].d.u =
                            (alpha << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
                        if (!entry->b34) {
                            frame.alphaProduct = c1d9c.b[3] * c3c.b[3];
                            int disabledAlpha = (int)(frame.alphaProduct * 0.00392156886f);
                            b.cells[b.cursor].d.u = (disabledAlpha << 24) | 0xc0c000;
                        }
                        b.FUN_000f87f0(entry, frame.style);
                        Elem_ea7c0* elements = entry->elems;
                        if (elements) {
                            Elem_ea7c0* element = elements + entry->cur;
                            float* width = &FUN_000e2820(&frame.listMeasurement)->x;
                            float elementWidth = b.FUN_000f88a0(element);
                            float offset = *width - elementWidth;
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                            frame.listElementOffset.x = offset;
                            frame.listElementOffset.y = 0.0f;
                            frame.listElementOffset.z = 0.0f;
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.listElementOffset);
                            b.FUN_000f87f0(element, frame.style);
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                        }
                    }
                    if (animation) {
                        animation->v12(0.0f);
                        animation->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        frame.iconOffset.x = f1d74 * 0.5f;
                        frame.iconOffset.y = 0.0f;
                        frame.iconOffset.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.iconOffset);
                        entry->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    frame.verticalAdvance.x = 0.0f;
                    frame.verticalAdvance.y = -(f1d78 + f1d70);
                    frame.verticalAdvance.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.verticalAdvance);
                } else {
                    if (frame.row == index) {
                        if (owner->v13(this))
                            b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008),
                                           (*(unsigned int*)&DAT_004de94c));
                        else
                            b.cells[b.cursor].d.u = c3c.w;
                    }
                    b.FUN_000f87f0(entry, 0);
                    Elem_ea7c0* elements = entry->elems;
                    if (elements) {
                        Elem_ea7c0* element = elements + entry->cur;
                        owner->v15(&frame.itemOrigin, this);
                        float offset = frame.itemOrigin.x - b.FUN_000f88a0(element);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        frame.unstyledElementOffset.x = offset;
                        frame.unstyledElementOffset.y = 0.0f;
                        frame.unstyledElementOffset.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.unstyledElementOffset);
                        b.FUN_000f87f0(element, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    if (animation) {
                        animation->v12(0.0f);
                        animation->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        frame.horizontalAdvance.x = f1d74 * 0.5f;
                        frame.horizontalAdvance.y = 0.0f;
                        frame.horizontalAdvance.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.horizontalAdvance);
                        entry->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    frame.origin.x = 0.0f;
                    frame.origin.y = -(f1d78 + f1d70);
                    frame.origin.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
                    if (frame.row == index)
                        b.cells[b.cursor].d.u = b.hdr[1];
                }
            }
        } else {
            for (; frame.row <= i1d80; frame.row++) {
                Entry_ea7c0* entry = &items[frame.row];
                if (entry->str.w10 == 0 && entry->str.i14 == -1)
                    continue;
                pure3d::TextureAnimationController* animation = 0;
                if (entry->ctl)
                    animation =
                        dynamic_cast<pure3d::TextureAnimationController*>(entry->ctl->p44->p3c->p8->v18(0));
                Obj958_ea7c0* fade = frame.fade;
                float animationValue;
                if (fade != 0) {
                    if (frame.row == index) {
                        if (owner->v13(this)) {
                            float opacity = fade->f14 * 255.0f;
                            b.cells[b.cursor].d.u = 0;
                            Obj978_ea7c0* style = &owner->hold->o978;
                            frame.savedColor = style->col10;
                            style->col10 = (255 - (int)opacity) << 24;
                            b.FUN_000f87f0(&items[index], style);
                            style->col10 = frame.savedColor;
                            frame.alphaProduct = c1da0.b[3] * c3c.b[3];
                            int alpha = (int)(frame.alphaProduct * 0.00392156886f);
                            b.cells[b.cursor].d.u =
                                frame.packedColor.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], alpha)->v;
                            b.FUN_000f87f0(&items[index], fade);
                            animationValue = 1.0f;
                        } else {
                            b.cells[b.cursor].d.u = c3c.w;
                            b.FUN_000f87f0(entry, frame.style);
                            animationValue = 1.0f;
                        }
                    } else {
                        frame.alphaProduct = c1d9c.b[3] * c3c.b[3];
                        int alpha = (int)(frame.alphaProduct * 0.00392156886f);
                        b.cells[b.cursor].d.u =
                            (alpha << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
                        b.FUN_000f87f0(entry, frame.style);
                        animationValue = 0.0f;
                    }
                    if (animation) {
                        animation->v12(animationValue);
                        animation->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        frame.origin.x = f1d74 * 0.5f;
                        frame.origin.y = 0.0f;
                        frame.origin.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.origin);
                        entry->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    frame.horizontalAdvance.x = f1d74 + f1d6c;
                    frame.horizontalAdvance.y = 0.0f;
                    frame.horizontalAdvance.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.horizontalAdvance);
                } else {
                    animationValue = 0.0f;
                    if (frame.row == index) {
                        if (owner->v13(this))
                            b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008),
                                           (*(unsigned int*)&DAT_004de94c));
                        else
                            b.cells[b.cursor].d.u = c3c.w;
                        animationValue = 1.0f;
                    }
                    b.FUN_000f87f0(entry, 0);
                    if (animation) {
                        animation->v12(animationValue);
                        animation->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        frame.unstyledElementOffset.x = f1d74 * 0.5f;
                        frame.unstyledElementOffset.y = 0.0f;
                        frame.unstyledElementOffset.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.unstyledElementOffset);
                        entry->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d40(f1d74 + f1d6c, 0, 0);
                    if (frame.row == index)
                        b.cells[b.cursor].d.u = b.hdr[1];
                }
            }
        }
    }

    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    if (owner->v13(this)) {
        if (p1d8c != 0 && i1d7c != 0)
            p1d8c->v8(0, 0);
        if (p1d90 != 0 && i1d80 < i1d58 - 1)
            p1d90->v8(0, 0);
    }
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
    owner->v14(&frame.itemOrigin, this);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&frame.itemOrigin);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);
    if (owner->v13(this) && &owner->hold->o958 == 0)
        vfunc_18();
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    b.FUN_000f78e0();
}
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e9e60..0x000ebb90 (kind game, layer game, confidence high), dominant class TextSelector
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f12e8a1b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f12e8a1b {} using namespace fn_f12e8a1b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f12e8a1b {
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void FUN_slot18(float, int); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void FUN_slot30(float); };
struct List { char pad[0x24]; Item** begin; Item** end; };
struct Manager { char pad[0x48]; List* list; void FUN_002998d0(int); };
struct Owner { char pad0[0x150]; float multiplier; char pad1[0xc]; float divisor; char pad2[0x2c]; Manager* manager; char pad3[0x60]; float value; void FUN_000e9e60(); };
struct FUN_000e9240 {
    FUN_000e9240(int arg);
    virtual void slot0();
    char pad04[0x74];
    unsigned values78[3];
    char pad84[0xcc];
    float range150;
    unsigned state154;
    unsigned state158;
    unsigned state15c;
    float range160;
    float range164;
    unsigned state168;
    unsigned state16c;
    char pad170[12];
    unsigned state17c;
    unsigned state180;
    unsigned state184;
    unsigned state188;
    unsigned state18c;
    unsigned state190;
    unsigned states194[20];
    unsigned color1e4;
    unsigned color1e8;
    unsigned color1ec;
    float scale1f0;
    float scale1f4;
};
struct HSlider : FUN_000e9240 {
    virtual void slot0();
    HSlider(int arg);
};
extern void* g_vftable_e9ff0[];
class Ref_e9ff0 {
  public:
    virtual void F0();
    virtual void Release();
};
} // namespace fn_f12e8a1b
void operator delete[](void*) throw();
namespace fn_f12e8a1b {
struct Mgr_e9ff0 {
};
struct Own_e9ff0 {
    char p[8];
    Mgr_e9ff0* m8;
};
struct Sub_e9ff0 {
    char c;
};
class HSlider_e9ff0 {
  public:
    void* vptr;
    char p[0x14];
    Sub_e9ff0 s18;
    char p2[0x37];
    Ref_e9ff0* m50;
    char p3[0xc];
    Ref_e9ff0* m60;
    Ref_e9ff0* m64;
    char p4[0x40];
    Own_e9ff0* ma8;
    char* mac;
    char p5[0xd0];
    char* m180;
    char p6[0xc];
    Ref_e9ff0* m190;
    Ref_e9ff0* a[10];
    Ref_e9ff0* b[10];
    ~HSlider_e9ff0() throw();
};
struct Receiver_ea0c0 {
    virtual void vfunc_0();
};
struct Notify_ea0c0 {
    void FUN_000f8b90(int);
};
struct Item_ea0c0 {
    int owner;
    char pad[0x20];
    int field24;
    Receiver_ea0c0* receiver;
    int field2c;
    int field30;
    unsigned char enabled;
    char tail[3];
    void FUN_000f83c0(const char*);
};
struct Chooser_ea740 {
    bool FUN_000f92b0(int lo, int hi, char* out);
};
union ChooserArg {
    Chooser_ea740* chooser;
    char picked;
};
struct Listener_ea740 {
    void FUN_000f8b90(int index);
};
class TextSelector {
  public:
    virtual void vfunc_0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void vfunc_7(ChooserArg arg);
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void vfunc_19(const char*, unsigned char, Receiver_ea0c0*);
    char _m_pad_4[0x8c];
    int idLo;
    int idHi;
    char _m_pad_98[0xc];
    int owner;
    char _m_pad_a8[0xa8];
    union { int defaultIndex; int selected; };
    union { int index; int previous; };
    Item_ea0c0 items[128];
    int count;
    char _m_pad_1d5c[0x38];
    union { Listener_ea740* listener; Notify_ea0c0* notify; };
    void Refresh() { vfunc_0(); }
};


// 0x000e9e60 FUN_000e9e60 (93 B): equivalent/0x000e9e60.cpp
// sym: ?FUN_000e9e60@Owner@fn_f12e8a1b@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_000e9e60 @ 0x000e9e60
void Owner::FUN_000e9e60() { manager->FUN_002998d0(0); List* list = manager->list; if ((unsigned char)(list->end - list->begin) != 0) { Item* item = *list->begin; if (item) { item->FUN_slot30(value / divisor * multiplier); item->FUN_slot18(10.0f, 1); } } }


// 0x000e9ec0 FUN_000e9ec0 (295 B): equivalent/0x000e9ec0.cpp
// sym: ??0HSlider@fn_f12e8a1b@@QAE@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e9ec0 @ 0x000e9ec0
HSlider::HSlider(int arg) : FUN_000e9240(arg) {
    state184=state188=state18c=state190=0;
    color1e4=color1e8=0xffffffff;
    color1ec=0xff000000;
    state154=state15c=state16c=0;
    values78[0]=values78[1]=values78[2]=0;
    state17c=state180=0;
    range160=range164=range150=100.0f;
    state158=state168=1;
    scale1f0=scale1f4=1.0f;
    for (int i=0;i<20;++i) states194[i]=0;
}


// 0x000e9ff0 FUN_000e9ff0 (205 B): matches/0x000e9ff0.cpp
// sym: ??1HSlider_e9ff0@fn_f12e8a1b@@QAE@XZ
HSlider_e9ff0::~HSlider_e9ff0() throw() {
    vptr = g_vftable_e9ff0;
    if (m180)
        ((owners::Obj_f8c30 *)(ma8->m8))->FUN_000f8c30((const char *)(m180 + 0x18));
    if (m190)
        m190->Release();
    for (int i = 0; i < 10; i++)
        if (a[i])
            a[i]->Release();
    for (int i = 0; i < 10; i++)
        if (b[i])
            b[i]->Release();
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete[](mac);
        mac = 0;
    }
    ((owners::Thing_f7960 *)&s18)->FUN_000f7960();
}


// 0x000ea0c0 TextSelector::vfunc_19 (240 B): matches/0x000ea0c0.cpp
// sym: ?vfunc_19@TextSelector@fn_f12e8a1b@@UAEXPBDEPAUReceiver_ea0c0@2@@Z
void TextSelector::vfunc_19(const char* text, unsigned char select, Receiver_ea0c0* receiver) {
    if (count >= 128)
        return;
    items[count].FUN_000f83c0(text);
    items[count].owner = owner;
    items[count].field24 = 0;
    items[count].receiver = receiver;
    if (receiver)
        items[count].receiver->vfunc_0();
    items[count].field2c = 0;
    items[count].field30 = 0;
    items[count].enabled = 1;
    if (select) {
        int index = count;
        previous = index;
        selected = index;
        if (notify)
            notify->FUN_000f8b90(index);
        vfunc_0();
    }
    ++count;
}

} // namespace fn_f12e8a1b

// 0x000ea1b0 TextSelector::vfunc_20 (303 B): equivalent/0x000ea1b0.cpp [wrapped: conflict: TextSelector]
// sym: ?vfunc_20@TextSelector@fn_000ea1b0@@UAEXHPBUElem_ea1b0@2@@Z
namespace fn_000ea1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 16/20, incomplete)
// TextSelector::vfunc_20 @ 0x000ea1b0
struct Elem_ea1b0 {
    char data[0x24];
    void FUN_000f7930();
    Elem_ea1b0 *FUN_000f83c0(const Elem_ea1b0 *src);
    void FUN_000f7960();
};

struct Entry_ea1b0 {
    Elem_ea1b0 *items;
    int field_04;
    int count;
    char rest[0x38 - 0x0c];
};

extern "C" int __cdecl FUN_00266da0(int tag);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Elem_ea1b0::*ctor)());
void __cdecl FUN_0008d340(void *p);

class TextSelector {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void vfunc_20(int index, const Elem_ea1b0 *value);
    char pad[0x17c - 4];
    Entry_ea1b0 entries[127];
    char pad2[0x14];
    int entryCount;
};

void TextSelector::vfunc_20(int index, const Elem_ea1b0 *value)
{
    if (index < 0 || index >= entryCount)
        return;
    Entry_ea1b0 *e = &entries[index];
    if (e->count >= 0x80)
        return;

    int saved = FUN_00266da0(0xe);
    int n = e->count + 1;
    int *mem = (int *)FUN_0008d6d0(n * sizeof(Elem_ea1b0) + 4);
    if (mem) {
        *mem = n;
        Elem_ea1b0 *arr = (Elem_ea1b0 *)(mem + 1);
        FUN_00011520(arr, sizeof(Elem_ea1b0), n, &Elem_ea1b0::FUN_000f7930);
        for (int i = 0; i < e->count; i++)
            arr[i].FUN_000f83c0(&e->items[i]);
        arr[e->count].FUN_000f83c0(value);
        e->count++;

        Elem_ea1b0 *old = e->items;
        if (old) {
            int oldCount = ((int *)old)[-1];
            for (int i = oldCount - 1; i >= 0; i--)
                old[i].FUN_000f7960();
            FUN_0008d340((int *)old - 1);
            e->items = 0;
        }
        e->items = arr;
    }
    FUN_00266da0(saved);
}
} // namespace fn_000ea1b0


// 0x000ea2e0 TextSelector::vfunc_3 (1105 B): equivalent/0x000ea2e0.cpp [wrapped: conflict: TextSelector]
// sym: ?vfunc_3@TextSelector@fn_000ea2e0@@UAEXXZ
namespace fn_000ea2e0 {
// STATUS: equivalent (tools/equiv.py level 3: 4098 inputs, branch coverage 52/52)
// TextSelector::vfunc_3 @ 0x000ea2e0
// TextSelector::vfunc_3 @ 0x000ea2e0: measure the selector's text entries
struct Vec3 {
    float x, y, z;
};

struct Font {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float v7();
    float FUN_000dfbf0(const char *s);
};

struct Pane {
    char pad0[0x24];
    Font *font;
};

class Chain4 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual struct Pane *v44();
};

struct Chain8 {
    char pad0[4];
    Chain4 *f4;
};

struct TextSelector;

struct Slot16 {
    float x;
    char pad[12];
};

// matrix-stack style helper local: first dword set by its constructor, 8 entries, depth at +0x88
struct Xform {
    Pane *pane;
    char pad4[4];
    Slot16 entries[8];
    int depth;
    float FUN_000f88a0(void *item);
    float FUN_000f8840(void *item);
    void FUN_000f7fe0(Pane *p);
    void FUN_000f78e0();
};

struct Box {
    float a, b, c;
};

class Host {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual Vec3 *v15(Vec3 *out, TextSelector *self);
    virtual float v16(TextSelector *self);
    virtual float v17(TextSelector *self);
    char pad4[4];
    Chain8 *f8;
};

struct Item {
    char text[0x18];           // 0x00
    char flag;                 // 0x18
    char pad19[3];
    float scaled;              // 0x1c
    int sel;                   // 0x20
    char pad24[4];
    void *obj;                 // 0x28
    char pad2c[0x38 - 0x2c];
};

void __cdecl FUN_000f69e0(void *obj, Box *out);
extern "C" int __cdecl FUN_0034483c();

class FEControl_ea2e0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};

struct Frame {
    union {
        float b;             // 0x10
        int bi;
    };
    float a;                 // 0x14
    Vec3 tmpA;               // 0x18
    Box out;                 // 0x24
    Xform x;                 // 0x30
    float t;                 // 0xbc
};

class TextSelector : public FEControl_ea2e0 {
public:
    virtual void vfunc_3();
    char pad04[0x10];
    Host *host;                // 0x14
    char pad18[0x6c - 0x18];
    int f6c;
    int f70;
    char pad74[4];
    float f78;
    float f7c;
    char pad80[0x154 - 0x80];
    int f154;
    Item items[128];           // 0x158
    int count;                 // 0x1d58
    int mode;                  // 0x1d5c
    float f1d60, f1d64, f1d68, f1d6c, f1d70, f1d74, f1d78;
    int f1d7c, f1d80;
};

void TextSelector::vfunc_3()
{
    Frame f;
    int i;
    FEControl_ea2e0::vfunc_3();
    f1d60 = 0;
    f1d64 = 0;
    f1d74 = 0;
    f1d78 = 0;
    f.x.FUN_000f7fe0(host->f8->f4->v44());
    f.b = host->v17(this);
    f.x.entries[f.x.depth].x = host->v16(this) * f.b;
    f1d60 = f.x.FUN_000f88a0(&pad18) + f1d60;
    f1d64 = f.x.FUN_000f8840(&pad18) + f1d64;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            Item *it = &items[i];
            it->flag = 1;
            it->sel = -1;
            host->v15(&f.tmpA, this);
            it->scaled = f.tmpA.x * f1d68;
            it->sel = -1;
            f.a = f.x.FUN_000f88a0(it);
            f.b = f.x.FUN_000f8840(it);
            if (it->obj != 0) {
                FUN_000f69e0(it->obj, &f.out);
                if (f.out.a > f.a)
                    f.a = f.out.a;
                if (f.out.b > f.b)
                    f.b = f.out.b;
            }
            if (f.a > f1d74)
                f1d74 = f.a;
            if (f.b > f1d78)
                f1d78 = f.b;
        }
    }
    if (mode == 0) {
        Font *font = f.x.pane->font;
        Slot16 *top = &f.x.entries[f.x.depth];
        f.b = 14.0f / font->v7();
        f1d60 = font->FUN_000dfbf0(": ") * top->x * f.b + f1d60 + f1d74;
        if (f1d78 > f1d64)
            f1d64 = f1d78;
    } else if (mode == 2) {
        int e = count;
        f.b = 0.0f;
        for (i = 0; i < count; i++) {
            host->v15(&f.tmpA, this);
            if (f.b + f1d78 >= f.tmpA.y) {
                e = i;
                break;
            }
            f.b = (f.b + f1d78) + f1d70;
        }
        f1d7c = 0;
        f1d80 = count - 1;
        if (count > e)
            f1d80 = e - 1;
        while (f1d80 < f154 && f1d80 < count - 1) {
            f1d7c++;
            f1d80++;
        }
        f1d60 = f1d74 + f1d60;
        f.bi = f1d80 + 1;
        f.t = (f1d70 + f1d78) * (float)f.bi - f1d70;
        if (f.t > f1d64)
            f1d64 = f.t;
    } else {
        host->v15(&f.tmpA, this);
        hulk_freg xw = f1d6c + f1d74;
        int n = (int)(f.tmpA.x / xw);
        f1d7c = 0;
        f1d80 = count - 1;
        if (count > n)
            f1d80 = n - 1;
        f.bi = f1d80 + 1;
        f1d60 = (float)f.bi * xw + f1d60;
        if (f1d78 > f1d64)
            f1d64 = f1d78;
    }
    switch (f6c) {
    case 1:
        f78 = f78 - f1d60 * 0.5f;
        break;
    case 2:
        f78 = f78 - f1d60;
        break;
    }
    if (mode == 2) {
        switch (f70) {
        case 3:
            host->v15(&f.tmpA, this);
            f7c = f1d64 - f.tmpA.y * 0.5f;
            break;
        case 2:
            f7c = f1d64 * 0.5f;
            break;
        case 1: {
            Vec3 *t2 = (Vec3 *)&f.out;
            host->v15(t2, this);
            f.b = t2->y * 0.5f;
            f7c = f.b - f.x.FUN_000f8840(&items[f1d7c]) * 0.5f;
            break;
        }
        }
    }
    f.x.FUN_000f78e0();
}
} // namespace fn_000ea2e0

namespace fn_f12e8a1b {

// 0x000ea740 TextSelector::vfunc_7 (113 B): equivalent/0x000ea740.cpp
// sym: ?vfunc_7@TextSelector@fn_f12e8a1b@@UAEXTChooserArg@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// TextSelector::vfunc_7 @ 0x000ea740
void TextSelector::vfunc_7(ChooserArg arg)
{
    if ((idLo | idHi) == 0)
        return;
    int newIndex;
    if (arg.chooser->FUN_000f92b0(idLo, idHi, &arg.picked)) {
        int sel = arg.picked;
        int last = count - 1;
        if (sel > last)
            newIndex = last;
        else if (sel < 0)
            newIndex = 0;
        else
            newIndex = sel;
    } else {
        newIndex = defaultIndex;
    }
    index = newIndex;
    if (listener != 0)
        listener->FUN_000f8b90(newIndex);
    Refresh();
}

} // namespace fn_f12e8a1b

// 0x000ea7c0 TextSelector::vfunc_5 (5060 B): equivalent/0x000ea7c0.cpp [wrapped: conflict: TextSelector]
// sym: ?vfunc_5@TextSelector@fn_000ea7c0@@UAEXXZ
namespace fn_000ea7c0 {
// STATUS: equivalent (tools/equiv.py level 3: 582 inputs, branch coverage 129/142, incomplete)
// TextSelector::vfunc_5 @ 0x000ea7c0
// TextSelector::vfunc_5 (FUN_000ea7c0): draws the selector's label, entries and scroll controls.

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
} // namespace fn_000ea7c0


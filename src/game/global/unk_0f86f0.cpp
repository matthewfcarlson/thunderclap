// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f86f0..0x000f8da0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8fef2d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb8fef2d {} using namespace fn_fb8fef2d;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fb8fef2d {
extern "C" void* FUN_0008d6d0(unsigned int n);
struct Data_f87c0 {
    char pad[0x0c];
    int* values;
    int count;
};
class Obj_f87c0 {
  public:
    Data_f87c0* root;
    void Next_000f81b0(int, int, int);
    void F(int index, int b, int c);
};
struct Blender_f87f0;
struct Entry_f87f0 {
    int a;
    int b;
    float scale;
    int FUN_000f83f0(Owner* owner, Blender_f87f0* blender);
};
struct Blender_f87f0 {
    Owner* owner;
    char pad[0x88 - 4];
    int index;
    float scale;
    void FUN_000f81b0(int v, int a, int b);
    void FUN_000f87f0(Entry_f87f0* e, hulk_intptr arg);
};
struct Item {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual float a7();
    virtual void a8(); virtual float a9(int);
};
struct Root { char pad[0x24]; Item *items[1]; };
struct Context;
struct Choice { int slot; int FUN_000f83f0(Root *, Context *); };
struct Context {
    Root *root;
    char pad0[4];
    struct Entry { float value; char pad[12]; } entries[8];
    int index;
    hulk_freg FUN_000f8840(Choice *choice);
};
class Font {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float GetHeight();                                      // slot 7
    virtual void v8(); virtual void v9();
    virtual float GetWidth(const unsigned short *text);             // slot 10
};
struct Owner_f88a0 {
    char pad0[0x24];
    Font *fonts[1];         // 0x24
};
struct StyleEntry {
    float width;
    float pad[3];
};
class Label_f88a0;
struct Run_f88a0 {
    int fontIndex;          // 0x0
    const unsigned short *FUN_000f83f0(Owner_f88a0 *owner, Label_f88a0 *label);
};
class Label_f88a0 {
public:
    Owner_f88a0 *owner;           // 0x0
    char pad4[4];
    StyleEntry styles[8];   // 0x8
    int style;              // 0x88
    float spacing;          // 0x8c

    hulk_freg FUN_000f88a0(Run_f88a0 *run);
};
static __forceinline int CountBackspaces(const unsigned short *p)
{
    int count = 0;
    if (p != 0) {
        for (; *p != 0; p++) {
            if (*p == 8)
                count++;
        }
    }
    return count;
}
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
namespace pure3d {
class Font;
}
class Ref_f8970 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f8970 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f8970 *v3(content::LoadInventory::DynamicCaster<pure3d::Font> *caster, unsigned int lo, unsigned int hi);
};
struct Id64_f8970 {
    unsigned int lo;
    unsigned int hi;
};
} // namespace fn_fb8fef2d
extern "C" Id64_f8970 __cdecl FUN_0027b020(const char *name);
namespace fn_fb8fef2d {
class FontSet_f8970 {
public:
    char pad0[0x24];
    Ref_f8970 *fonts[0x24 / 4];
    Id64_f8970 ids[(0x88 - 0x48) / 8];
    int count;

    void FUN_000f8970(const char *name);
};
class Ref_f89e0 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Loader_f89e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f89e0 *v3(content::LoadInventory::DynamicCaster<pure3d::Font> *caster, unsigned int lo, unsigned int hi);
};
struct Id64_f89e0 {
    unsigned int lo;
    unsigned int hi;
};
class FontSet_f89e0 {
public:
    char pad0[0x24];
    Ref_f89e0 *fonts[0x24 / 4];
    Id64_f89e0 ids[(0x88 - 0x48) / 8];
    int count;

    void FUN_000f89e0();
};
struct Owner_f8a90 {
    char pad[4];
    struct Names_f8a90 *names;
};
struct Names_f8a90 {
    int FUN_000dfa60(int id);
};
int FUN_000dfcc0(char *dst, int size, const char *fmt, ...);
class NamedValue {
public:
    NamedValue(Owner_f8a90 *o, const char *n) {
        link[0] = link[1] = link[2] = link[3] = 0;
        owner = o;
        FUN_000dfcc0(name, 0x28, "%s", n);
    }
    virtual void v0();
    int link[4];
    Owner_f8a90 *owner;
    char name[0x28];
};
class NamedValueFloat : public NamedValue {
public:
    NamedValueFloat(Owner_f8a90 *o, const char *n, int v, int id);
    virtual void v0();
    int value;
    int shadow;
    int handle;
};
struct Child { virtual void FUN_00000000(int); };
struct Object { virtual void FUN_00000000(); char pad[0x3c]; int value; char pad2[4]; Child *child; void FUN_000f8b00(int); };
class B_f8b90 {
  public:
    virtual void V(int);
};
class A_f8b90 {
  public:
    virtual void Finish();
    char pad[0x3c];
    int value;
    char pad2[4];
    B_f8b90* b;
    void Set(int);
};
} // namespace fn_fb8fef2d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_fb8fef2d {
typedef unsigned int u32_f8bd0;
extern void thunk_FUN_00267090(u32_f8bd0);
struct Obj_f8bd0 {
    int pad;
    int entries[128];
};
extern char DAT_004a17a8;
extern char DAT_004a17c4;
extern "C" int __cdecl FUN_00344e74(hulk_intptr a, int b, void* c, void* d, int e);
extern int hulk_at_004a17a8;
extern int hulk_at_004a17e4;
struct This_first {
};

} // namespace fn_fb8fef2d

// 0x000f86f0 FUN_000f86f0 (153 B): matches/0x000f86f0.cpp
// sym: ?FUN_000f86f0@Obj_f86f0@owners@@QAEXHH@Z
void owners::Obj_f86f0::FUN_000f86f0(int a, hulk_intptr b) {
    m4 = ((int)b) * 2;
    m0 = (char*)FUN_0008d6d0((unsigned)(m4 >> 1) * 2);
    m10 = a;
    mC = (int*)FUN_0008d6d0(a * 4);
    unsigned v = m10;
    unsigned n = (v + 0x1f) >> 5;
    unsigned* p = (unsigned*)FUN_0008d6d0(n * 4 + 4);
    *p = v;
    if (n > 0) {
        unsigned* q = p + 1;
        for (unsigned i = n; i != 0; i--)
            *q++ = 0;
    }
    m11c = p;
    unsigned k = (*p + 0x1f) >> 5;
    if (k > 0) {
        unsigned* q = p + 1;
        for (; k != 0; k--)
            *q++ = 0;
    }
    m1c = a;
    m18 = FUN_0008d6d0(a * 8);
    m110 = 1;
}

namespace fn_fb8fef2d {

// 0x000f87c0 FUN_000f87c0 (44 B): matches/0x000f87c0.cpp
// sym: ?F@Obj_f87c0@fn_fb8fef2d@@QAEXHHH@Z
void Obj_f87c0::F(int index, int b, int c) {
    if (index < 0)
        return;
    int value;
    if (index <= root->count)
        value = root->values[index];
    else
        value = 0;
    Next_000f81b0(value, b, c);
}


// 0x000f87f0 FUN_000f87f0 (67 B): matches/0x000f87f0.cpp
// sym: ?FUN_000f87f0@Blender_f87f0@fn_fb8fef2d@@QAEXPAUEntry_f87f0@2@H@Z
void Blender_f87f0::FUN_000f87f0(Entry_f87f0* e, hulk_intptr arg) {
    float saved = scale;
    scale = e->scale;
    FUN_000f81b0(e->FUN_000f83f0(owner, this), e->a, arg);
    scale = saved;
}


// 0x000f8840 FUN_000f8840 (82 B): equivalent/0x000f8840.cpp
// sym: ?FUN_000f8840@Context@fn_fb8fef2d@@QAEMPAUChoice@2@@Z @7f06020caf84 @w303290c7113e
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 0/0)
// FUN_000f8840 @ 0x000f8840
hulk_freg Context::FUN_000f8840(Choice *choice) {
    int slot = choice->slot;
    int argument = choice->FUN_000f83f0(root, this);
    int current = index;
    Item *selected = root->items[slot];
    float divisor = root->items[0]->a7();
    float factor = (*(float*)&DAT_0040cc38) / divisor;
    float value = selected->a9(argument);
    return value * factor * entries[current].value;
}


// 0x000f88a0 FUN_000f88a0 (146 B): equivalent/0x000f88a0.cpp
// sym: ?FUN_000f88a0@Label_f88a0@fn_fb8fef2d@@QAEMPAURun_f88a0@2@@Z @4856e3cf9a3b @w301f7f7848b8
// STATUS: equivalent (tools/equiv.py level 3: 19991 inputs, branch coverage 8/8)
// FUN_000f88a0 @ 0x000f88a0
hulk_freg Label_f88a0::FUN_000f88a0(Run_f88a0 *run)
{
    const unsigned short *text = run->FUN_000f83f0(owner, this);
    Font *font = owner->fonts[run->fontIndex];
    Font *first = owner->fonts[0];
    StyleEntry *entry = &styles[style];
    float scale = 14.0f / first->GetHeight();
    hulk_freg width = font->GetWidth(text) * entry->width * scale;
    return width - ((CountBackspaces(text) * 0.073f) * spacing);
}


// 0x000f8970 FUN_000f8970 (100 B): equivalent/0x000f8970.cpp
// sym: ?FUN_000f8970@FontSet_f8970@fn_fb8fef2d@@QAEXPBD@Z @a9668320084d @w0afc861d95f8
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_000f8970 @ 0x000f8970
void FontSet_f8970::FUN_000f8970(const char *name)
{
    int i = count;
    if (fonts[i] != 0)
        fonts[i]->Release();
    Id64_f8970 id = FUN_0027b020(name);
    ids[i] = id;
    content::LoadInventory::DynamicCaster<pure3d::Font> caster;
    Ref_f8970 *r = (*(Loader_f8970**)&DAT_004dd9c8)->v3(&caster, id.lo, id.hi);
    fonts[i] = r;
    r->AddRef();
    count = count + 1;
}


// 0x000f89e0 FUN_000f89e0 (100 B): equivalent/0x000f89e0.cpp
// sym: ?FUN_000f89e0@fn_fb8fef2d@@YIXPAVFontSet_f89e0@1@@Z @96c825b00c62 @wc93b371dbc6a
// STATUS: equivalent (tools/equiv.py level 3: 2167 inputs, branch coverage 4/4)
// FUN_000f89e0 @ 0x000f89e0
void __fastcall FUN_000f89e0(FontSet_f89e0 *set)
{
    for (int i = 0; i < set->count; i++) {
        content::LoadInventory::DynamicCaster<pure3d::Font> caster;
        Ref_f89e0 *r = (*(Loader_f89e0**)&DAT_004dd9c8)->v3(&caster, set->ids[i].lo, set->ids[i].hi);
        set->fonts[i] = r;
        r->AddRef();
    }
}


// 0x000f8a90 FUN_000f8a90 (110 B): equivalent/0x000f8a90.cpp
// sym: ??0NamedValueFloat@fn_fb8fef2d@@QAE@PAUOwner_f8a90@1@PBDHH@Z @f9676f9d2316 @wf5c90a3279a1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8a90 @ 0x000f8a90
NamedValueFloat::NamedValueFloat(Owner_f8a90 *o, const char *n, int v, int id) : NamedValue(o, n)
{
    shadow = v;
    value = v;
    handle = 0;
    if (id != 0)
        handle = owner->names->FUN_000dfa60(id);
}


// 0x000f8b00 FUN_000f8b00 (32 B): equivalent/0x000f8b00.cpp
// sym: ?FUN_000f8b00@Object@fn_fb8fef2d@@QAEXH@Z @83442623dcde @w9935f695867d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8b00 @ 0x000f8b00
void Object::FUN_000f8b00(int v) { value=v; if(child) child->FUN_00000000(v); FUN_00000000(); }

} // namespace fn_fb8fef2d

// 0x000f8b20 FUN_000f8b20 (108 B): equivalent/0x000f8b20.cpp [wrapped: conflict: NamedValue]
// sym: ??0NamedValueInt@fn_000f8b20@@QAE@PAUOwner_f8b20@1@PBDH1@Z @e39bec10d0c2 @w58107394197f
namespace fn_000f8b20 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8b20 @ 0x000f8b20
struct Helper_f8b20 { int FUN_000df9e0(const char *s); };
struct Owner_f8b20 { char pad[4]; Helper_f8b20 *helper; };
int __cdecl FUN_000dfcc0(char *buf, int size, const char *fmt, ...);

class NamedValue {
public:
    int f4, f8, fc, f10;
    Owner_f8b20 *owner;
    char name[0x28];
    NamedValue(Owner_f8b20 *o, const char *n)
    {
        f4 = 0;
        f8 = 0;
        fc = 0;
        f10 = 0;
        owner = o;
        FUN_000dfcc0(name, 0x28, "%s", n);
    }
    virtual void v0();
};

class NamedValueInt : public NamedValue {
public:
    int value;
    int value2;
    int helperResult;
    NamedValueInt(Owner_f8b20 *o, const char *n, int v, const char *s);
    virtual void v0();
};

NamedValueInt::NamedValueInt(Owner_f8b20 *o, const char *n, int v, const char *s) : NamedValue(o, n)
{
    value = v;
    value2 = v;
    helperResult = 0;
    if (s != 0)
        helperResult = owner->helper->FUN_000df9e0(s);
}
} // namespace fn_000f8b20

namespace fn_fb8fef2d {

// 0x000f8b90 FUN_000f8b90 (32 B): matches/0x000f8b90.cpp
// sym: ?Set@A_f8b90@fn_fb8fef2d@@QAEXH@Z
void A_f8b90::Set(int x) {
    value = x;
    if (b)
        b->V(x);
    Finish();
}

} // namespace fn_fb8fef2d

// 0x000f8bb0 FUN_000f8bb0 (27 B): matches/0x000f8bb0.cpp
// sym: ?FUN_000f8bb0@Obj_f8bb0@owners@@QAEPAU12@H@Z
owners::Obj_f8bb0* owners::Obj_f8bb0::FUN_000f8bb0(hulk_intptr a) {
    vptr = (void*)((hulk_intptr)a);
    memset(data, 0, 0x80 * 4);
    return this;
}

namespace fn_fb8fef2d {

// 0x000f8bd0 FUN_000f8bd0 (43 B): matches/0x000f8bd0.cpp
// sym: @FUN_000f8bd0@4
extern "C" void __fastcall FUN_000f8bd0(Obj_f8bd0* self) {
    int i = 0;
    do {
        int v = self->entries[i];
        if (v == 0)
            return;
        thunk_FUN_00267090(v);
        self->entries[i] = 0;
        ++i;
    } while (i < 128);
}

} // namespace fn_fb8fef2d

// 0x000f8c00 FUN_000f8c00 (46 B): matches/0x000f8c00.cpp
// sym: ?FUN_000f8c00@C_f8c00@owners@@QAEHH@Z
int owners::C_f8c00::FUN_000f8c00(hulk_intptr x) {
    int i = 0;
    do {
        if (a[i] == 0)
            break;
        if (i == 128)
            return 0;
        ++i;
    } while (i < 128);
    a[i] = ((int)x);
    return ((int)x);
}


// 0x000f8c30 FUN_000f8c30 (130 B): matches/0x000f8c30.cpp
// sym: ?FUN_000f8c30@Obj_f8c30@owners@@QAEXPBD@Z
void owners::Obj_f8c30::FUN_000f8c30(const char* name) {
    int i;
    for (i = 0; i < 128; ++i) {
        void* p = items[i];
        if (p) {
            const char* s = (const char*)((char*)p + 0x18);
            if (strcmp(s, name) == 0) {
                ReleaseThing(items[i]);
                items[i] = 0;
                return;
            }
        }
    }
}


// 0x000f8cc0 FUN_000f8cc0 (115 B): matches/0x000f8cc0.cpp
// sym: ?FUN_000f8cc0@Table_f8cc0@owners@@QAEHPBD@Z
int owners::Table_f8cc0::FUN_000f8cc0(const char* s) {
    int i = 0;
    const char* p = s;
    do {
        if (items[i] == 0)
            return 0;
        if (strcmp((const char*)(items[i] + 0x18), p) == 0)
            return ((int*)this)[i + 1];
        ++i;
    } while (i < 128);
    return 0;
}


// 0x000f8d40 FUN_000f8d40 (36 B): matches/0x000f8d40.cpp
// sym: ?FUN_000f8d40@ThisWrap_000f8d40@owners@@QAEHH@Z
hulk_intptr owners::ThisWrap_000f8d40::FUN_000f8d40(int a) {
    return FUN_00344e74(this->FUN_000f8cc0(a), 0, &DAT_004a17a8, &DAT_004a17c4, 0);
}


// 0x000f8d70 FUN_000f8d70 (36 B): matches/0x000f8d70.cpp
// sym: ?FUN_000f8d70@Obj_f8d70@owners@@QAEHH@Z
hulk_intptr owners::Obj_f8d70::FUN_000f8d70(hulk_intptr x) {
    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(((owners::Table_f8cc0 *)(((This_first*)this)))->FUN_000f8cc0((const char *)(hulk_uintptr)(int)(((int)x)))), 0, (void*)(&hulk_at_004a17a8), (void*)(&hulk_at_004a17e4), 0));
}


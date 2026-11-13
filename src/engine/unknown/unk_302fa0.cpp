// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00302fa0..0x00304640 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0220b18 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0220b18 {} using namespace fn_f0220b18;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f0220b18 {
struct Entry_302fa0 {
    unsigned int data[9];
    float priority;
    unsigned int rest[7];
    void FUN_002f7a90(const Entry_302fa0* source);
};
struct Elem_303080 {
    unsigned int w[17];
};
struct Entry_3032d0 {
 unsigned int words[9];
 float priority;
 unsigned int tail[7];
 void FUN_002f7a90(const Entry_3032d0* source);
};
extern void __cdecl FUN_00302fa0(Entry_3032d0* entries, int hole, int start, Entry_3032d0 value);
struct Item_303480 {
    int v[17];
};
void helper_003032d0(Item_303480*, hulk_intptr, hulk_intptr, Item_303480);
struct Item_303520 {
    unsigned int prefix[9];
    float key;
    unsigned int suffix[7];
    void FUN_002f7a90(const Item_303520* other);
};
struct E_3035d0 {
    int d[17];
    void Assign_002f7a90(E_3035d0* src);
};
extern void __cdecl FUN_003032d0(E_3035d0* first, int hole, hulk_intptr len, E_3035d0 v);
struct Item_303680 {
    char pad0[0x24];
    float key;
    char pad28[0x44 - 0x28];
};
void __cdecl FUN_00303080(Item_303680 *dest, Item_303680 *first, Item_303680 *last, int a, int b);
struct E_303700 {
    char d[0x44];
};
extern "C" void __cdecl FUN_00303520(void *, void *, void *);
struct Item_3037f0 {
    unsigned int w[9];
    float key;
    unsigned int w2[7];
};
struct Partition {
    Item_3037f0 *first;
    Item_3037f0 *second;
};
void __cdecl FUN_00303700(Item_3037f0 *first, Item_3037f0 *mid, Item_3037f0 *last);
static inline bool Pred(const Item_3037f0 &a, const Item_3037f0 &b)
{
    return a.key < b.key;
}
static inline void IterSwap(Item_3037f0 *a, Item_3037f0 *b)
{
    Item_3037f0 t = *a;
    *a = *b;
    *b = t;
}
struct Elem_304260 {
    char data[0x44];
    void FUN_002f7a90(Elem_304260 *src);
};
void __cdecl FUN_003032d0(Elem_304260 *first, int hole, int len, Elem_304260 value);
extern "C" void* __cdecl FUN_0008d6d0(int);
// (x64t9-pw) the contact buffer's begin and end (decls/physics_world.h HulkContactBuffer), pointer-sized
struct Target_304350 {
    hulk_intptr a;
    hulk_intptr b;
};
extern "C++" __declspec(nothrow) void __cdecl FUN_00304370(void *, void *, int);
struct Thing_304500 {
    int* a;
    int* b;
};
struct Matrix {
    unsigned int data[16];
};
struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int type();
    char pad[0x48];
    Matrix matrix;
    char pad2[0x40];
    unsigned char enabled;
    void FUN_00306600(unsigned int);
};
struct Record_304530 {
    Matrix matrix;
    unsigned int extra;
};
struct Renderer_304530 {
    void FUN_00314be0(unsigned int, unsigned int, Object*, unsigned int, unsigned int, unsigned int);
};
struct Global_304530 {
    char pad[HULK_WORLD_AT(detector)];  // (x64t4, x64t9-pw) decls/physics_world.h
    Renderer_304530 renderer;
};
struct Queue_304530 {
    unsigned int field0;
    Record_304530* next;
    Record_304530* end;
    void FUN_00304500();
    void target(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                Object* object, unsigned int flags);
};


// 0x00302fa0 FUN_00302fa0 (211 B): equivalent/0x00302fa0.cpp
// sym: ?FUN_00302fa0@fn_f0220b18@@YAPAUEntry_302fa0@1@PAU21@HHU21@@Z @d9e836d46a08 @w07bc1eff029f
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_00302fa0 @ 0x00302fa0
Entry_302fa0* __cdecl FUN_00302fa0(Entry_302fa0* entries, int index, int lowerBound, Entry_302fa0 value) {
    int parent = (index - 1) / 2;
    while (lowerBound < index) {
        if (!(entries[parent].priority < value.priority)) break;
        entries[index].FUN_002f7a90(&entries[parent]);
        index = parent;
        parent = (parent - 1) / 2;
    }
    Entry_302fa0* destination = &entries[index];
    *destination = value;
    return destination;
}


// 0x00303080 FUN_00303080 (476 B): equivalent/0x00303080.cpp
// sym: ?FUN_00303080@fn_f0220b18@@YAXPAUElem_303080@1@00@Z @a195cdabe5ee @w851a139d24e7
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 17/18, incomplete)
// FUN_00303080 @ 0x00303080
// std::rotate for 0x44-byte elements (Dinkumware _Rotate, random access).
void FUN_00303080(Elem_303080* first, Elem_303080* mid, Elem_303080* last)
{
    hulk_intptr shift = mid - first;
    hulk_intptr total = last - first;
    hulk_intptr cycles = total;
    hulk_intptr factor = shift;
    while (factor != 0) {
        hulk_intptr tmp = cycles % factor;
        cycles = factor;
        factor = tmp;
    }
    if (cycles < total) {
        for (; cycles > 0; cycles--) {
            Elem_303080* hole = first + cycles;
            Elem_303080* next = hole;
            Elem_303080 holeVal = *hole;
            Elem_303080* next1;
            if (next + shift == last)
                next1 = first;
            else
                next1 = next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                if (last - next1 > shift)
                    next1 = next1 + shift;
                else
                    next1 = first + (shift - (last - next1));
            }
            *next = holeVal;
        }
    }
}


// 0x003032d0 FUN_003032d0 (249 B): equivalent/0x003032d0.cpp
// sym: ?FUN_003032d0@fn_f0220b18@@YAXPAUEntry_3032d0@1@HHU21@@Z @39f34d8a2ecf @w6ae37814217f
// STATUS: equivalent (tools/equiv.py level 3: 1038 inputs, branch coverage 8/8)
// FUN_003032d0 @ 0x003032d0
void __cdecl FUN_003032d0(Entry_3032d0* entries, int start, int count, Entry_3032d0 value) {
 int hole = start;
 int child = hole * 2 + 2;
 while (child < count) {
  if (entries[child].priority < entries[child-1].priority) --child;
  entries[hole] = entries[child];
  hole = child;
  child = child * 2 + 2;
 }
 if (child == count) {
  entries[hole].FUN_002f7a90(&entries[count-1]);
  hole = count-1;
 }
 FUN_00302fa0(entries, hole, start, value);
}


// 0x00303480 FUN_00303480 (99 B): matches/0x00303480.cpp
// sym: ?target@fn_f0220b18@@YAXPAUItem_303480@1@0@Z
void target(Item_303480* first, Item_303480* last) {
    hulk_intptr count = last - first;
    hulk_intptr n = count / 2;
    if (n > 0) {
        Item_303480* p = first + n;
        do {
            --n;
            helper_003032d0(first, n, count, *--p);
        } while (n > 0);
    }
}


// 0x00303520 FUN_00303520 (171 B): matches/0x00303520.cpp
// sym: _FUN_00303520
extern "C" void __cdecl FUN_00303520(void * first, void * second, void * third) {
    Item_303520 temp;
    if (((Item_303520 *)second)->key < ((Item_303520 *)first)->key) {
        temp = *((Item_303520 *)second);
        ((Item_303520 *)second)->FUN_002f7a90(((Item_303520 *)first));
        ((Item_303520 *)first)->FUN_002f7a90(&temp);
    }
    if (((Item_303520 *)third)->key < ((Item_303520 *)second)->key) {
        temp = *((Item_303520 *)third);
        ((Item_303520 *)third)->FUN_002f7a90(((Item_303520 *)second));
        ((Item_303520 *)second)->FUN_002f7a90(&temp);
    }
    if (((Item_303520 *)second)->key < ((Item_303520 *)first)->key) {
        temp = *((Item_303520 *)second);
        ((Item_303520 *)second)->FUN_002f7a90(((Item_303520 *)first));
        ((Item_303520 *)first)->FUN_002f7a90(&temp);
    }
}


// 0x003035d0 FUN_003035d0 (97 B): matches/0x003035d0.cpp
// sym: ?FUN_003035d0@fn_f0220b18@@YAXPAUE_3035d0@1@0@Z
void __cdecl FUN_003035d0(E_3035d0* first, E_3035d0* last) {
    E_3035d0 v = last[-1];
    last[-1].Assign_002f7a90(first);
    FUN_003032d0(first, 0, (last - 1) - first, v);
}


// 0x00303680 FUN_00303680 (124 B): equivalent/0x00303680.cpp
// sym: _FUN_00303680 @33ff0b039326 @w7241089d928b
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 15/18, incomplete)
// FUN_00303680 @ 0x00303680
// Insertion sort of [first, last) by ascending key.
extern "C" void FUN_00303680(void *first, void *last) {
    if (((Item_303680 *)first) == ((Item_303680 *)last)) {
        return;
    }
    for (Item_303680 *cur = ((Item_303680 *)first) + 1; cur != ((Item_303680 *)last); cur++) {
        Item_303680 *next = cur + 1;
        Item_303680 *pos;
        if (cur->key < ((Item_303680 *)first)->key) {
            pos = ((Item_303680 *)first);
        } else {
            pos = cur;
            while (cur->key < (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_00303080(pos, cur, next, 0, 0);
        }
    }
}


// 0x00303700 FUN_00303700 (157 B): matches/0x00303700.cpp
// sym: ?G@fn_f0220b18@@YAXPAUE_303700@1@00@Z
void G(E_303700* first, E_303700* mid, E_303700* last) {
    hulk_intptr n = last - first;
    if (n > 40) {
        hulk_intptr s = (n + 1) / 8;
        FUN_00303520((E_303700 *)first, (E_303700 *)(first + s), (E_303700 *)(first + s * 2));
        FUN_00303520((E_303700 *)(mid - s), (E_303700 *)mid, (E_303700 *)(mid + s));
        FUN_00303520((E_303700 *)(last - s * 2), (E_303700 *)(last - s), (E_303700 *)last);
        FUN_00303520((E_303700 *)(first + s), (E_303700 *)mid, (E_303700 *)(last - s));
    } else {
        FUN_00303520((E_303700 *)first, (E_303700 *)mid, (E_303700 *)last);
    }
}

} // namespace fn_f0220b18

// 0x003037e0 FUN_003037e0 (6 B): matches/0x003037e0.cpp
// sym: ?FUN_003037e0@Obj_3037e0@owners@@QAEXXZ
void owners::Obj_3037e0::FUN_003037e0() {
    mSecond = mFirst;
}

namespace fn_f0220b18 {

// 0x003037f0 FUN_003037f0 (2659 B): equivalent/0x003037f0.cpp
// sym: ?FUN_003037f0@fn_f0220b18@@YAXPAUPartition@1@PAUItem_3037f0@1@1@Z @e96672fe5697 @w6435efcc9894
// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 60/62, incomplete)
// FUN_003037f0 @ 0x003037f0
void __cdecl FUN_003037f0(Partition *result, Item_3037f0 *first, Item_3037f0 *last)
{
    Item_3037f0 *mid = first + (last - first) / 2;
    FUN_00303700(first, mid, last - 1);
    Item_3037f0 *pfirst = mid;
    Item_3037f0 *plast = pfirst + 1;

    while (first < pfirst && !Pred(*(pfirst - 1), *pfirst) && !Pred(*pfirst, *(pfirst - 1)))
        --pfirst;
    while (plast < last && !Pred(*plast, *pfirst) && !Pred(*pfirst, *plast))
        ++plast;

    Item_3037f0 *gfirst = plast;
    Item_3037f0 *glast = pfirst;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Pred(*pfirst, *gfirst)) {
            } else if (Pred(*gfirst, *pfirst)) {
                break;
            } else {
                IterSwap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Pred(*(glast - 1), *pfirst)) {
            } else if (Pred(*pfirst, *(glast - 1))) {
                break;
            } else {
                IterSwap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            result->first = pfirst;
            result->second = plast;
            return;
        }
        if (glast == first) {
            if (plast != gfirst)
                IterSwap(pfirst, plast);
            ++plast;
            IterSwap(pfirst++, gfirst++);
        } else if (gfirst == last) {
            if (--glast != --pfirst)
                IterSwap(glast, pfirst);
            IterSwap(pfirst, --plast);
        } else {
            IterSwap(gfirst++, --glast);
        }
    }
}


// 0x00304260 FUN_00304260 (156 B): equivalent/0x00304260.cpp
// sym: _FUN_00304260 @16a67d2a20a4 @wc0add26cbb83
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 4/4)
// FUN_00304260 @ 0x00304260
// FUN_00304260: heap sort tail (repeatedly move the first element to the end and sift down)
extern "C" void __cdecl FUN_00304260(void *first, void * last_)
{
    Elem_304260 * last = (Elem_304260 *)last_;
    while (last - ((Elem_304260 *)first) > 1) {
        Elem_304260 value = *(last - 1);
        (last - 1)->FUN_002f7a90(((Elem_304260 *)first));
        FUN_003032d0(((Elem_304260 *)first), 0, (int)((last - 1) - ((Elem_304260 *)first)), value);
        last--;
    }
}

} // namespace fn_f0220b18

// 0x00304300 FUN_00304300 (71 B): equivalent/0x00304300.cpp
// sym: ?FUN_00304300@Buffer_304300@owners@@QAEPAU12@XZ @27edadfb2920 @wc1ad8450f6aa
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00304300 @ 0x00304300
// (x64t10) the contact buffer's elements are decls/physics_world.h's HulkContact (0x44 bytes on the 32-bit builds,
// 0x58 natively: the count of contacts times the record's size)
owners::Buffer_304300* owners::Buffer_304300::FUN_00304300() { begin = 0; end = 0; capacity = 0; if (DAT_004d2f80 != 0) { int bytes = DAT_004d2f80 * (int)sizeof(HulkContact); begin = (HulkContact*)FUN_0008d6d0(bytes); if (begin != 0) { capacity = (char*)begin + bytes; end = begin; return this; } } begin = 0; end = 0; capacity = 0; return this; }

namespace fn_f0220b18 {

// 0x00304350 FUN_00304350 (17 B): matches/0x00304350.cpp
// sym: @FUN_00304350@4
extern "C" void __fastcall FUN_00304350(Target_304350* self) {
    hulk_intptr v = self->a;
    self->b = v;
    if (v)
        thunk_FUN_00267090(v);
}

} // namespace fn_f0220b18

// 0x00304370 FUN_00304370 (294 B): equivalent/0x00304370.cpp [wrapped: conflict: Partition]
// sym: _FUN_00304370 @634908489891 @w70bf5e64aeff
namespace fn_00304370 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00304370 @ 0x00304370
struct Item_304370 { char data[68]; };
struct Partition { Item_304370* first; Item_304370* second; };
void __cdecl FUN_003037f0(Partition*, Item_304370*, Item_304370*);
extern "C++" __declspec(nothrow) void __cdecl FUN_00303680(void *, void *);
void __cdecl FUN_00303480(Item_304370*, Item_304370*, int, int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00304260(void *, void *);
extern "C" void __cdecl FUN_00304370(void * first_, void * last_, int depth) {
    Item_304370 * first = (Item_304370 *)first_;
    Item_304370 * last = (Item_304370 *)last_;
    while (last - first > 32) {
        if (depth <= 0) {
            if (last - first > 1) FUN_00303480(first, last, 0, 0);
            FUN_00304260((Item_304370 *)first, (Item_304370 *)last);
            return;
        }
        Partition middle;
        FUN_003037f0(&middle, first, last);
        Item_304370* upper = middle.second;
        depth = depth / 2 + (depth / 2) / 2;
        if (middle.first - first < last - upper) {
            FUN_00304370((Item_304370 *)first, (Item_304370 *)(middle.first), depth);
            first = upper;
        } else {
            FUN_00304370((Item_304370 *)upper, (Item_304370 *)last, depth);
            last = middle.first;
        }
    }
    if (last - first > 1) FUN_00303680((Item_304370 *)first, (Item_304370 *)last);
}
} // namespace fn_00304370

namespace fn_f0220b18 {

// 0x00304500 FUN_00304500 (42 B): matches/0x00304500.cpp
// sym: ?FUN_00304500@fn_f0220b18@@YIXPAUThing_304500@1@@Z
void __fastcall FUN_00304500(Thing_304500* p) {
    int* s = p->b;
    int* d = p->a;
    FUN_00304370((void *)(hulk_uintptr)(hulk_intptr)((hulk_intptr)d), (void *)(hulk_uintptr)(hulk_intptr)((hulk_intptr)s), (int)(((char*)s - (char*)d) / 0x44));
}


// 0x00304530 FUN_00304530 (248 B): matches/0x00304530.cpp
// sym: ?target@Queue_304530@fn_f0220b18@@QAEXIIIIIPAUObject@2@I@Z
void Queue_304530::target(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                   Object* object, unsigned int flags) {
    Record_304530 temp;
    if (object->type() == 4 && object->enabled) {
        temp.matrix = object->matrix;
        ((owners::M_22c3b0 *)&(temp.matrix))->FUN_0022c3b0((float *)(hulk_uintptr)(hulk_uintptr)e, (float *)(hulk_uintptr)(hulk_uintptr)e);
        ((owners::Mat_22c2b0 *)&(temp.matrix))->FUN_0022c2b0((float *)(hulk_uintptr)(unsigned int)d, (float *)(hulk_uintptr)(unsigned int)d);
    }
    if (flags & 1) {
        object->FUN_00306600(b);
        (*(Global_304530**)&DAT_00554c14)->renderer.FUN_00314be0(a, d, object, d, c, e);
    } else if (flags & 2) {
        object->FUN_00306600(b);
        ((owners::Obj_2f8ec0 *)&temp)->FUN_002f8ec0((int)a, (int)d, (hulk_intptr)(Object *)object, (int)d, (int)c, (hulk_intptr)e);
        Record_304530* dest = next;
        if ((hulk_uintptr)dest < (hulk_uintptr)end) {
            next = dest + 1;
            if (dest)
                *dest = temp;
        }
        if (flags & 8)
            FUN_00304500();
    }
}

} // namespace fn_f0220b18

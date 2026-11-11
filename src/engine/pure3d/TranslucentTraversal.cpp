// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a18a0..0x002a26c0 (kind game, layer engine, confidence high), dominant class pure3d::TranslucentTraversal
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render/Canvas.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f7803771 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f7803771 {} using namespace fn_f7803771;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f7803771 {
struct V {
    float x, y;
};
typedef char(__cdecl* Compare_2a1a60)(int, int);
class Device_2a1b60 {
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
    virtual void v14(int a, int b);
    virtual void v15(int a);
    virtual void v16(int a);
};
} // namespace fn_f7803771
class Gfx {
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
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78(int a);
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87(int a);
    virtual void v88(int a);
};
namespace fn_f7803771 {
class Sub_2a1b60;
class Sub_2a1b60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
    char pad[0x10 - 4];
    Sub_2a1b60* next;
    char pad2[0x44 - 0x14];
    int link;
};
class Obj_2a1b60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
    virtual char v9();
};
struct ObjHandle {
    Obj_2a1b60* obj;
    void FUN_002a4060();
};
struct Item_2a1b60 {
    char pad[8];
    int n;
    ObjHandle* handle;
    Sub_2a1b60* sub;
    int tag;
};
struct Helper_2a1b60 {
    void FUN_002a06d0(int link);
};
struct Vector3_2a1ca0 { float x,y,z; };
struct Vector4 { float x,y,z,w; };
struct ItemData_2a1ca0 { char pad[0x2c]; Vector4 vector; };
struct Item_2a1ca0 { ItemData_2a1ca0* data; char pad[12]; };
struct Collection_2a1ca0 { char pad[0x48]; Item_2a1ca0* begin; Item_2a1ca0* end; };
struct Object_2a1ca0 { char pad[0x40]; Collection_2a1ca0* collection; void* extra;  };
struct Entry_2a1ca0 { float depth; float result; Object_2a1ca0* object; Item_2a1ca0* item; Collection_2a1ca0* collection; void* extra; };
typedef unsigned char(__cdecl* Compare_2a1e00)(int, int);
typedef char(__cdecl* Cmp)(int, int);
void Fix_002a1a60(int*, int, int, int, Cmp);
typedef int Elem4;
void __cdecl FUN_002a1e00(Elem4 *a, Elem4 *b, Elem4 *c, void *cmp);
void FUN_002a1e60(hulk_intptr, hulk_intptr, hulk_intptr, int, int);
extern "C" char DAT_0042d750[];
typedef unsigned int u32_2a21c0;
extern void __cdecl thunk_FUN_00267090(u32_2a21c0);
extern void __fastcall FUN_002c6aa0(void*);
struct TranslucentTraversal {
    u32_2a21c0 vptr;
    char pad04[0x18];
    u32_2a21c0 mSeven;
    char pad20[8];
    u32_2a21c0 mTen;
};
typedef bool (__cdecl *Less_2a23d0)(int a, int b);
void __cdecl FUN_002a1ac0(int *first, int *middle, int *last, int a, int b);
void __cdecl FUN_002a1e60(int*, int, hulk_intptr, int, int);
struct Partition { int* first; int* second; };
void __cdecl FUN_002a2200(Partition*, int*, int*, void*);
void __cdecl FUN_002a23d0(int*, int*, void*);
void __cdecl FUN_002a2090(int*, int*, void*, int, int);
void __cdecl FUN_002a2510(int*, int*, void*);
extern "C" void __cdecl FUN_002a18a0();
extern void FUN_002a2560(int*, int*, int, const void*);


// 0x002a18a0 FUN_002a18a0 (49 B): matches/0x002a18a0.cpp
// sym: ?FUN_002a18a0@fn_f7803771@@YAHPBUV@1@0@Z
int __cdecl FUN_002a18a0(const V* a, const V* b) {
    if (a->x != b->x)
        return a->x > b->x;
    return a->y > b->y;
}

} // namespace fn_f7803771

// 0x002a18e0 pure3d::TranslucentTraversal::vfunc_5 (8 B): matches/0x002a18e0.cpp
// sym: ?vfunc_5@TranslucentTraversal@pure3d@@UAEXXZ
void pure3d::TranslucentTraversal::vfunc_5() {
    this->f_18 = 0;
}

namespace fn_f7803771 {

// 0x002a1a60 FUN_002a1a60 (96 B): matches/0x002a1a60.cpp
// sym: ?HeapPlace@fn_f7803771@@YAXPAHHHHP6ADHH@Z@Z
void HeapPlace(int* a, int index, int limit, int value, Compare_2a1a60 cmp) {
    int parent = (index - 1) / 2;
    if (limit < index) {
        do {
            if (!cmp(a[parent], value))
                break;
            a[index] = a[parent];
            index = parent;
            parent = (index - 1) / 2;
        } while (limit < index);
    }
    a[index] = value;
}


// 0x002a1ac0 FUN_002a1ac0 (150 B): equivalent/0x002a1ac0.cpp
// sym: ?FUN_002a1ac0@fn_f7803771@@YAXPAH00@Z @fff34162d876 @w209cc2860326
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 17/18, incomplete)
// FUN_002a1ac0 @ 0x002a1ac0
// std::rotate for a range of 4-byte elements (cycle-leader algorithm)
void FUN_002a1ac0(int *first, int *middle, int *last)
{
    int shift = (int)(middle - first);
    int total = (int)(last - first);
    int cycles = total;
    for (int factor = shift; factor != 0;) {
        int rem = cycles % factor;
        cycles = factor;
        factor = rem;
    }
    if (cycles < total) {
        for (; cycles > 0; --cycles) {
            int *hole = first + cycles;
            int *next = hole;
            int holeValue = *hole;
            int *next1 = (next + shift == last) ? first : next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)(last - next1);
                next1 = (shift < left) ? next1 + shift : first + (shift - left);
            }
            *next = holeValue;
        }
    }
}

} // namespace fn_f7803771

// 0x002a1b60 pure3d::TranslucentTraversal::vfunc_4 (313 B): matches/0x002a1b60.cpp
// sym: ?vfunc_4@TranslucentTraversal@pure3d@@UAEXXZ
// pure3d::TranslucentTraversal::vfunc_4 @ 0x002a1b60
void pure3d::TranslucentTraversal::vfunc_4() {
    (*(*(Device_2a1b60***)&DAT_0052c2ac))->v15(0);
    for (unsigned int i = 0; i < (*(unsigned int *)&this->f_18); i++) {
        ObjHandle* handle = (*(Item_2a1b60 ** *)&this->f_28)[i]->handle;
        Sub_2a1b60* sub = (*(Item_2a1b60 ** *)&this->f_28)[i]->sub;
        (*(*(Device_2a1b60***)&DAT_0052c2ac))->v14(0, (*(Item_2a1b60 ** *)&this->f_28)[i]->n);
        if (handle->obj->v9() == 1 && (*(Helper_2a1b60 * *)&this->f_14) != 0 && sub->link != 0)
            (*(Helper_2a1b60 * *)&this->f_14)->FUN_002a06d0(sub->link);
        if ((*(Item_2a1b60 ** *)&this->f_28)[i]->tag == (hulk_intptr)DAT_004e2314) {
            DAT_0052c2a8->v87(8);
            DAT_0052c2a8->v78(0);
        }
        Sub_2a1b60* inner = sub->next;
        if (inner != 0) {
            Obj_2a1b60* obj = handle->obj;
            obj->v8(inner->v3(obj->v7()));
            handle->FUN_002a4060();
            obj->v8(inner->v4(obj->v7()));
        } else {
            handle->FUN_002a4060();
        }
        if ((*(Item_2a1b60 ** *)&this->f_28)[i]->tag == (hulk_intptr)DAT_004e2314)
            DAT_0052c2a8->v88(8);
    }
    (*(*(Device_2a1b60***)&DAT_0052c2ac))->v16(0);
}


// 0x002a1ca0 pure3d::TranslucentTraversal::vfunc_6 (242 B): equivalent/0x002a1ca0.cpp
// sym: ?vfunc_6@TranslucentTraversal@pure3d@@UAEXPAXIM@Z @62066553e467 @wdf3791823ea8
// STATUS: equivalent (tools/equiv.py level 3: 19092 inputs, branch coverage 4/4)
// pure3d::TranslucentTraversal::vfunc_6 @ 0x002a1ca0
void pure3d::TranslucentTraversal::vfunc_6(void* __p0, unsigned int index, float depth) { Object_2a1ca0 * object = (Object_2a1ca0 *)__p0;

 if (!object->collection) return;
 unsigned size = (unsigned)(object->collection->end - object->collection->begin);
 if (index >= size) return;
 (*(Entry_2a1ca0 ** *)&this->f_28)[(*(unsigned int *)&this->f_18)] = &(*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)];
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].depth = depth;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].object = object;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].item = object->collection->begin + index;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].collection = object->collection;
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].extra = object->extra;
 Vector4 v = (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].item->data->vector;
 Vector3_2a1ca0 out;
 ((owners::Mat_22c2b0 *)object)->FUN_0022c2b0((float *)(Vector4 *)(&v), (float *)(Vector3_2a1ca0 *)(&out));
 (*(Entry_2a1ca0 * *)&this->f_1c)[(*(unsigned int *)&this->f_18)].result = out.z;
 ++(*(unsigned int *)&this->f_18);
}

namespace fn_f7803771 {

// 0x002a1e00 FUN_002a1e00 (94 B): matches/0x002a1e00.cpp
// sym: ?Sort3@fn_f7803771@@YAXPAH00P6AEHH@Z@Z
void Sort3(int* a, int* b, int* c, Compare_2a1e00 cmp) {
    if (cmp(*b, *a)) {
        int t = *b;
        *b = *a;
        *a = t;
    }
    if (cmp(*c, *b)) {
        int t = *c;
        *c = *b;
        *b = t;
    }
    if (cmp(*b, *a)) {
        int t = *b;
        *b = *a;
        *a = t;
    }
}


// 0x002a1e60 FUN_002a1e60 (111 B): matches/0x002a1e60.cpp
// sym: ?Target@fn_f7803771@@YAXPAHHHHP6ADHH@Z@Z
void Target(int* a, int b, int c, int d, Cmp fn) {
    int original = b;
    int i = b * 2 + 2;
    while (i < c) {
        if (fn(a[i], a[i - 1]))
            --i;
        a[b] = a[i];
        b = i;
        i = b * 2 + 2;
    }
    if (i == c) {
        a[b] = a[c - 1];
        b = c - 1;
    }
    Fix_002a1a60(a, b, original, d, fn);
}


// 0x002a1fe0 FUN_002a1fe0 (167 B): matches/0x002a1fe0.cpp
// sym: ?FUN_002a1fe0@fn_f7803771@@YAXPAH00PAX@Z
// FUN_002a1fe0 @ 0x002a1fe0
// median-of-nine pivot selection step of a sort over 4-byte elements with a comparator
void __cdecl FUN_002a1fe0(Elem4 *first, Elem4 *mid, Elem4 *last, void *cmp)
{
    int n = (int)(last - first);
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_002a1e00(first, first + step, first + 2 * step, cmp);
        FUN_002a1e00(mid - step, mid, mid + step, cmp);
        FUN_002a1e00(last - 2 * step, last - step, last, cmp);
        FUN_002a1e00(first + step, mid, last - step, cmp);
    } else {
        FUN_002a1e00(first, mid, last, cmp);
    }
}


// 0x002a2090 FUN_002a2090 (61 B): matches/0x002a2090.cpp
// sym: ?FUN_002a2090@fn_f7803771@@YAXHHH@Z
void FUN_002a2090(hulk_intptr first, int last, int arg) {
    hulk_intptr count = (last - first) >> 2;
    hulk_intptr i = count / 2;
    while (i > 0) {
        --i;
        FUN_002a1e60(first, i, count, ((int*)first)[i], arg);
    }
}

} // namespace fn_f7803771

// 0x002a2130 FUN_002a2130 (130 B): equivalent/0x002a2130.cpp [wrapped: conflict: pure3d::DisplayTraversal; pure3d::TranslucentTraversal]
// sym: ??0TranslucentTraversal@pure3d@fn_002a2130@@QAE@I@Z @10960ed3b24b @w9e089267f8ee
namespace fn_002a2130 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a2130 @ 0x002a2130
// equiv-map: ??0DisplayTraversal@pure3d@@QAE@XZ = 0x002c6a80
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {

class DisplayTraversal {
public:
    DisplayTraversal() throw();
    virtual void vfunc_0_00018b30();
    virtual void vfunc_1_00018b40();
    virtual void* vfunc_2_002a24c0(char);
    virtual void vfunc_3_002a2690();
    virtual void vfunc_4_002a1b60();
    virtual void vfunc_5_002a18e0();
    char pad04[8];
    unsigned int flags;         // 0x0c
    int mode;                   // 0x10
};

class TranslucentTraversal : public DisplayTraversal {
public:
    TranslucentTraversal(unsigned int capacity);
    virtual void vfunc_6_002a1ca0(void*, int, float);
    char pad14[4];
    unsigned int count;         // 0x18
    char *entriesBegin;         // 0x1c  (24-byte entries)
    char *entriesEnd;           // 0x20
    char pad24[4];
    char *orderBegin;           // 0x28  (pointer per entry)
    char *orderEnd;             // 0x2c
};

TranslucentTraversal::TranslucentTraversal(unsigned int capacity)
{
    count = 0;

    if (capacity != 0) {
        unsigned int bytes = capacity * 24;
        char *p = (char *)FUN_0008d6d0(bytes);
        entriesBegin = p;
        entriesEnd = (p != 0) ? p + bytes : 0;
    } else {
        entriesBegin = 0;
        entriesEnd = 0;
    }

    if (capacity != 0) {
        unsigned int bytes = capacity * 4;
        char *p = (char *)FUN_0008d6d0(bytes);
        orderBegin = p;
        orderEnd = (p != 0) ? p + bytes : 0;
    } else {
        orderBegin = 0;
        orderEnd = 0;
    }

    flags &= ~0x30u;
    mode = 1;
}

}
} // namespace fn_002a2130

namespace fn_f7803771 {

// 0x002a21c0 FUN_002a21c0 (49 B): matches/0x002a21c0.cpp
// sym: ?FUN_002a21c0@fn_f7803771@@YIXPAUTranslucentTraversal@1@@Z
void __fastcall FUN_002a21c0(TranslucentTraversal* self) {
    *(volatile hulk_uintptr*)&self->vptr = ((hulk_intptr)DAT_0042d750);
    _ReadWriteBarrier();
    if (self->mTen)
        thunk_FUN_00267090(self->mTen);
    if (self->mSeven)
        thunk_FUN_00267090(self->mSeven);
    FUN_002c6aa0(self);
}

} // namespace fn_f7803771

// 0x002a2200 FUN_002a2200 (408 B): equivalent/0x002a2200.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_002a2200@fn_002a2200@@YAPAURange_2a2200@1@PAU21@PAH1P6A_NHH@Z@Z @469184f11bf2 @wbb1888ababab
namespace fn_002a2200 {
// STATUS: equivalent (tools/equiv.py level 3: 10 inputs, branch coverage 37/42, incomplete)
// FUN_002a2200 @ 0x002a2200
typedef bool (*Less_2a2200)(int a, int b);

struct Range_2a2200 {
    int *first;
    int *second;
};

void FUN_002a1fe0(int *first, int *mid, int *last, Less_2a2200 less);

static void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Partitions [first, last) around a median-of-three pivot into
// [first, lo) < pivot, [lo, hi) == pivot, [hi, last) > pivot and returns {lo, hi}.
Range_2a2200 *FUN_002a2200(Range_2a2200 *out, int *first, int *last, Less_2a2200 less)
{
    int *mid = first + (last - first) / 2;
    FUN_002a1fe0(first, mid, last - 1, less);
    int *pivotLo = mid;
    int *pivotHi = pivotLo + 1;

    while (first < pivotLo && !less(pivotLo[-1], *pivotLo) && !less(*pivotLo, pivotLo[-1]))
        --pivotLo;
    while (pivotHi < last && !less(*pivotHi, *pivotLo) && !less(*pivotLo, *pivotHi))
        ++pivotHi;

    int *up = pivotHi;
    int *down = pivotLo;
    for (;;) {
        for (; up < last; ++up) {
            if (less(*pivotLo, *up)) {
            } else if (less(*up, *pivotLo)) {
                break;
            } else {
                if (pivotHi++ != up)
                    Swap(pivotHi - 1, up);
            }
        }
        for (; first < down; --down) {
            if (less(down[-1], *pivotLo)) {
            } else if (less(*pivotLo, down[-1])) {
                break;
            } else {
                if (--pivotLo != down - 1)
                    Swap(pivotLo, down - 1);
            }
        }
        if (down == first && up == last) {
            out->first = pivotLo;
            out->second = pivotHi;
            return out;
        }
        if (down == first) {
            if (pivotHi != up)
                Swap(pivotLo, pivotHi);
            ++pivotHi;
            Swap(pivotLo, up);
            ++pivotLo;
            ++up;
        } else if (up == last) {
            --down;
            --pivotLo;
            if (down != pivotLo)
                Swap(down, pivotLo);
            --pivotHi;
            Swap(pivotLo, pivotHi);
        } else {
            --down;
            Swap(up, down);
            ++up;
        }
    }
}
} // namespace fn_002a2200

namespace fn_f7803771 {

// 0x002a23d0 FUN_002a23d0 (166 B): equivalent/0x002a23d0.cpp
// sym: ?FUN_002a23d0@fn_f7803771@@YAXPAH0P6A_NHH@Z@Z @f81f0341f58e @wa6f27e8e2832
// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 16/20, incomplete)
// FUN_002a23d0 @ 0x002a23d0
// Insertion sort of [first, last) of 4-byte elements with a comparison callback.
void FUN_002a23d0(int *first, int *last, Less_2a23d0 less)
{
    if (first == last)
        return;
    for (int *cur = first + 1; cur != last; cur++) {
        int *next = cur + 1;
        int *pos;
        if (less(*cur, *first)) {
            pos = first;
        } else {
            pos = cur;
            while (less(*cur, *(pos - 1)))
                pos--;
        }
        if (pos != cur && cur != next)
            FUN_002a1ac0(pos, cur, next, 0, 0);
    }
}

} // namespace fn_f7803771

// 0x002a24c0 pure3d::TranslucentTraversal::vfunc_2 (70 B): matches/0x002a24c0.cpp [wrapped: conflict: pure3d::TranslucentTraversal]
// sym: ?vfunc_2@TranslucentTraversal@pure3d@fn_002a24c0@@UAEPAXE@Z
void __cdecl operator delete[](void*);
void __cdecl operator delete(void*);
namespace fn_002a24c0 {


extern const int hulk_at_0042d750;

namespace pure3d {

class TranslucentTraversal {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();

    void BaseDtor_002c6aa0();

    char pad0[0x1c - 4];
    void* m1c;
    char pad1[8];
    void* m28;
};

void* TranslucentTraversal::vfunc_2(unsigned char param) {
    volatile int* v = (volatile int*)this;
    *v = (hulk_intptr)&hulk_at_0042d750;
    void* p28 = (void*)*(volatile hulk_intptr*)((char*)v + 0x28);
    if (p28 != 0) {
        operator delete[](p28);
    }
    void* p1c = (void*)*(volatile hulk_intptr*)((char*)v + 0x1c);
    if (p1c != 0) {
        operator delete[](p1c);
    }
    BaseDtor_002c6aa0();
    if ((param & 1) != 0) {
        operator delete(this);
    }
    return this;
}

} // namespace pure3d
} // namespace fn_002a24c0

namespace fn_f7803771 {

// 0x002a2510 FUN_002a2510 (74 B): equivalent/0x002a2510.cpp
// sym: ?FUN_002a2510@fn_f7803771@@YAXPAH0H@Z @15a0aae0e459 @w5e94977ea806
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002a2510 @ 0x002a2510
void __cdecl FUN_002a2510(int* first, int* last, hulk_intptr value)
{
    hulk_intptr bytes = (char*)last - (char*)first;
    while ((bytes >> 2) > 1) {
        int oldLast = *(int*)((char*)first + bytes - 4);
        *(int*)((char*)first + bytes - 4) = *first;
        FUN_002a1e60(first, 0, (bytes - 4) >> 2, oldLast, value);
        bytes -= 4;
    }
}


// 0x002a2560 FUN_002a2560 (238 B): equivalent/0x002a2560.cpp
// sym: ?FUN_002a2560@fn_f7803771@@YAXPAH0HPAX@Z @988cc7b30411 @we487d63f9af1
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_002a2560 @ 0x002a2560
void __cdecl FUN_002a2560(int* first, int* last, int depth, void* compare) {
 while (last-first > 32) {
  if (depth <= 0) {
   if (last-first > 1) FUN_002a2090(first,last,compare,0,0);
   FUN_002a2510(first,last,compare);
   return;
  }
  Partition middle;
  FUN_002a2200(&middle,first,last,compare);
  depth = depth/2;
  depth += depth/2;
  if (middle.first-first < last-middle.second) {
   FUN_002a2560(first,middle.first,depth,compare);
   first=middle.second;
  } else {
   FUN_002a2560(middle.second,last,depth,compare);
   last=middle.first;
  }
 }
 if (last-first > 1) FUN_002a23d0(first,last,compare);
}

} // namespace fn_f7803771

// 0x002a2690 pure3d::TranslucentTraversal::vfunc_3 (33 B): matches/0x002a2690.cpp
// sym: ?vfunc_3@TranslucentTraversal@pure3d@@UAEXXZ
void pure3d::TranslucentTraversal::vfunc_3() {
    int* eax = (*(int * *)&this->f_28);
    int* ecx = eax + this->f_18;
    FUN_002a2560(eax, ecx, (int)((char*)ecx - (char*)eax) >> 2, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_002a18a0));
}


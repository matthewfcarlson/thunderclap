// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f90c0..0x002fa6b0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe1b1ee9 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe1b1ee9 {} using namespace fn_fe1b1ee9;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fe1b1ee9 {
class Obj_2f91e0 {
  public:
    int m0, m1, m2, m3;
    Obj_2f91e0();
};
void *__cdecl FUN_0008d6d0(unsigned int n);
struct Block {
    int a, b, c, d;
};
struct Block_2f95f0 {
    unsigned int a, b, c, d;
};
struct Entry_2f9660 {
    int a;
    int b;
};
struct Container_2f9660 {
    char pad[0xc];
    Entry_2f9660* begin;
    Entry_2f9660* end;
};
struct Elem_2f9690 {
    char data[0x50];
};
struct Item_2f9690 {
    char pad00[0x74];
    unsigned int slot;
};
struct Entry_2f9690 {
    Item_2f9690 *owner;
    unsigned int state;
};
struct Pool_2f9690 {
    Elem_2f9690 *elems;
    char pad04[8];
    Entry_2f9690 *begin;
    Entry_2f9690 *end;

    Elem_2f9690 *FUN_002f9690(Item_2f9690 *item);
};
typedef unsigned int U_2f98c0;
typedef unsigned short U16;
struct Elem_2f9990 { int a, b, c, d; };
Elem_2f9990 *__cdecl FUN_002f95f0(Elem_2f9990 *first, hulk_intptr count, Elem_2f9990 *dest);
struct Vec_2f9990 {
    Elem_2f9990 *begin;
    Elem_2f9990 *last;
    Elem_2f9990 *end;
    Vec_2f9990 *FUN_002f9990(Vec_2f9990 *src);
};
struct Vertex_2f9a80 {
    int w[4];
};
struct MeshBuffers_2f9a80 {
    char pad[0x30];
    Vertex_2f9a80 *vertsStart;
    Vertex_2f9a80 *vertsBegin;
    Vertex_2f9a80 *vertsEnd;
    char pad3c[4];
    unsigned short *indicesStart;
    unsigned short *indicesBegin;
    unsigned short *indicesEnd;
    void FUN_002f9a80(unsigned int numVerts, unsigned int numIndices);
};
typedef unsigned int u32_2f9b30;
void __cdecl thunk_FUN_00267090(u32_2f9b30);
struct X_2f9b30 {
    u32_2f9b30 a;
    u32_2f9b30 b;
    void f();
};
extern void* Alloc(hulk_uintptr);
extern "C" unsigned int * __cdecl FUN_002f98c0(unsigned int *, unsigned int, unsigned int *);
struct Buffer { char pad[4]; unsigned short *end; unsigned short *limit; void FUN_002f9bc0(unsigned short *position, hulk_uintptr count, unsigned short *source); };
struct Range {
    unsigned int first;
    unsigned int last;
};
struct Object {
    void FUN_002f9ca0(unsigned int value);
};
void Release(void*);
struct Obj_2f9cd0 {
    char pad[0x30];
    int a;
    hulk_intptr b;
    char pad2[8];
    int c;
    hulk_intptr d;
    void f();
};
inline unsigned short* cp(unsigned short* a, unsigned short* b, unsigned short* out) {
    for (; a != b; ++a, ++out)
        *out = *a;
    return out;
}
class Str_2f9d00 {
  public:
    unsigned short* first;
    unsigned short* last;
    unsigned short* cap;
    void grow(unsigned short*, unsigned, unsigned short*);
    void fn(unsigned n, unsigned short* p);
};
class C_2f9d60 {
  public:
    char pad0[0x30];
    void* m30;
    void* m34;
    char pad38[8];
    void* m40;
    void* m44;

    C_2f9d60* func(unsigned char p);
};
} // namespace fn_fe1b1ee9
void __cdecl operator delete[](void*);
namespace fn_fe1b1ee9 {
struct Block_2f9da0 {
    int w[6];
};
struct PartA_2f9da0 {
    char data[0x10];
    void FUN_002f9990(const PartA_2f9da0 *src);
};
struct PartB_2f9da0 {
    char data[0x10];
};
struct Pose {
    Block_2f9da0 first;
    Block_2f9da0 second;
    PartA_2f9da0 a;
    PartB_2f9da0 b;
    Pose *FUN_002f9da0(const Pose *src);
};
struct Str_2f9ed0 {
    int pad0;
    int pad4;
    unsigned short *begin;          // 8
    unsigned short *end;            // 0xc
};
struct Buffer_2f9ed0 {
    unsigned short *begin;          // 0
    unsigned short *end;            // 4
    unsigned short *cap;            // 8
    void FUN_002f9bc0(unsigned short *pos, hulk_uintptr count, const unsigned short *value);
};
struct Pool_2f9ed0 {
    char pad00[0x30];
    Str_2f9ed0 *strBegin;                  // 0x30
    Str_2f9ed0 *strEnd;                    // 0x34
    char pad38[8];
    Buffer_2f9ed0 buf;                     // 0x40

    hulk_uintptr FUN_002f9ed0();
};
struct Entry {
    char pad0[0x30];
    void* a;
    void* aCopy;
    char pad1[8];
    void* b;
    void* bCopy;
    char pad2[8];
};
struct Item_2f9ff0 {
    void f(int);
};
struct Obj_2fa030 {
    int a;
    int b;
};
extern void __cdecl g(int);
struct Obj_2fa050 {
    void* a;
    void* b;
    void Target();
};
extern void __cdecl ReleaseThing(int);
extern void __cdecl DoPair(int, int);
struct Target_2fa0f0 {
    int first;
    int second;
    int pad;
    int third;
};
struct BoundsData {
    char reserved[24];
    unsigned int lower[3];
    unsigned int upper[3];
    unsigned int first[3];
    unsigned int gap;
    unsigned int second[3];
};
struct Transform {
    void FUN_002fa180(unsigned int value);
};
struct Desc_2fa1f0 {
    char data[12];
};
struct Pair6 {
    char data[6];
};
struct Frame_2fa1f0 {
    Pair6 first;
    Pair6 second;
};
class Range_2fa1f0;
struct Worker_2fa1f0 {
    void FUN_00307060(Pair6 *p, Range_2fa1f0 *r);
};
struct Holder_2fa1f0 {
    char pad00[0x14];
    Worker_2fa1f0 *worker;
};
struct Skeleton {
    char pad00[0x44];
    Holder_2fa1f0 *holder;
    char pad48[0xd0 - 0x48];
    int fd0;
};
extern "C" short * __cdecl FUN_002f9190(short *, short *);
class Range_2fa1f0 {
public:
    Skeleton *owner;
    int f4;
    unsigned short *begin;
    unsigned short *end;

    void FUN_002fa1f0(Desc_2fa1f0 *d, Skeleton *s);
};
struct Cell_2fa4e0 {
    char data[0x50];
    void FUN_002f9a80(unsigned int a, unsigned int b);
};
struct Pair_2fa4e0 {
    int first;
    int second;
};
struct CellGrid {
    Cell_2fa4e0 *cells;
    void FUN_002fa180(unsigned int n);
};
typedef unsigned int u32_2fa580;

} // namespace fn_fe1b1ee9

// 0x002f90c0 FUN_002f90c0 (90 B): matches/0x002f90c0.cpp
// sym: ?FUN_002f90c0@Vec_2f90c0@owners@@QAE_NPAU12@@Z
bool owners::Vec_2f90c0::FUN_002f90c0(owners::Vec_2f90c0* b) {
    if (!(b->f[3] <= f[3]) || !(b->f[0] >= f[0]) || !(b->f[4] <= f[4]) || !(b->f[1] >= f[1]) ||
        !(b->f[5] <= f[5]) || !(b->f[2] >= f[2]))
        return false;
    return true;
}

namespace fn_fe1b1ee9 {

// 0x002f9190 FUN_002f9190 (74 B): matches/0x002f9190.cpp
// sym: _FUN_002f9190
extern "C" short* FUN_002f9190(short* a, short* b) {
    if (a != b) {
        short* p = a + 1;
        if (p != b) {
            do {
                if (*a == *p) {
                    p = p + 1;
                    while (p != b) {
                        if (*a != *p) {
                            a = a + 1;
                            *a = *p;
                        }
                        p = p + 1;
                    }
                    return a + 1;
                }
                a = p;
                ++p;
            } while (p != b);
        }
    }
    return b;
}


// 0x002f91e0 FUN_002f91e0 (16 B): matches/0x002f91e0.cpp
// sym: ??0Obj_2f91e0@fn_fe1b1ee9@@QAE@XZ
Obj_2f91e0::Obj_2f91e0() {
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
}

} // namespace fn_fe1b1ee9

// 0x002f9340 FUN_002f9340 (72 B): matches/0x002f9340.cpp
// sym: ?FUN_002f9340@Buffer_2f9340@owners@@QAE_NI@Z
bool owners::Buffer_2f9340::FUN_002f9340(unsigned int count) {
    if (count) {
        start = (short*)FUN_0008d6d0(count * sizeof(short));
        if (start) {
            end = start + count;
            current = start;
            return true;
        }
    } else {
        start = 0;
    }
    current = 0;
    end = 0;
    return false;
}

namespace fn_fe1b1ee9 {

// 0x002f9460 FUN_002f9460 (59 B): matches/0x002f9460.cpp
// sym: ?FUN_002f9460@fn_fe1b1ee9@@YAPAUBlock@1@PAU21@00@Z
Block* FUN_002f9460(Block* first, Block* last, Block* dst) {
    for (; first != last; ++first, ++dst)
        *dst = *first;
    return dst;
}


// 0x002f95f0 FUN_002f95f0 (62 B): matches/0x002f95f0.cpp
// sym: ?Copy@fn_fe1b1ee9@@YAPAUBlock_2f95f0@1@PAU21@H0@Z
Block_2f95f0* Copy(Block_2f95f0* src, hulk_intptr count, Block_2f95f0* dst) {
    Block_2f95f0* d = dst;
    while (count != 0) {
        if (d != 0) {
            Block_2f95f0 x = *src;
            *d = x;
        }
        ++src;
        ++d;
        --count;
    }
    return d;
}


// 0x002f9660 FUN_002f9660 (37 B): matches/0x002f9660.cpp
// sym: ?target@fn_fe1b1ee9@@YIXPAUContainer_2f9660@1@@Z
void __fastcall target(Container_2f9660* self) {
    int n = (int)(((char*)self->end - (char*)self->begin) >> 3);
    while (n != 0) {
        --n;
        ++self->begin[n].b;
    }
}


// 0x002f9690 FUN_002f9690 (159 B): equivalent/0x002f9690.cpp
// sym: ?FUN_002f9690@Pool_2f9690@fn_fe1b1ee9@@QAEPAUElem_2f9690@2@PAUItem_2f9690@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 139 inputs, branch coverage 12/12)
// FUN_002f9690 @ 0x002f9690
// FUN_002f9690: find or claim the slot for an item in a pool of 0x50-byte elements
Elem_2f9690 *Pool_2f9690::FUN_002f9690(Item_2f9690 *item)
{
    if (item == 0)
        return 0;

    unsigned int slot = item->slot;
    if (slot < (unsigned int)(end - begin)) {
        Entry_2f9690 *e = &begin[slot];
        if (e->owner == item) {
            e->state = 0;
            return &elems[slot];
        }
    }

    if (((end - begin) * sizeof(Entry_2f9690) & 0xfffffff8) == 0)
        return 0;

    Entry_2f9690 *first = begin;
    unsigned int i = 0;
    do {
        if (first[i].state > 2) {
            first[i].owner = item;
            item->slot = i;
            begin[i].state = 0;
            return &elems[i];
        }
        i++;
    } while (i != (unsigned int)(end - begin));
    return 0;
}


// 0x002f98c0 FUN_002f98c0 (46 B): matches/0x002f98c0.cpp
// sym: _FUN_002f98c0
// Same code shape as 0x002b0de0 (propagated; names are from that function)
extern "C" unsigned int * __cdecl FUN_002f98c0(unsigned int * dst, unsigned int count, unsigned int * src) {
    if (count) {
        for (; count; --count) {
            if (dst) {
                dst[0] = src[0];
                dst[1] = src[1];
            }
            dst += 2;
        }
        return dst;
    }
    return dst;
}

} // namespace fn_fe1b1ee9

// 0x002f9930 FUN_002f9930 (86 B): matches/0x002f9930.cpp
// sym: ?FUN_002f9930@Buffer_2f9930@owners@@QAEXPAGHH@Z
void owners::Buffer_2f9930::FUN_002f9930(U16* src, int count, hulk_intptr value) {
    U16* p = cur;
    U16* q = p + count;
    if (q <= end) {
        cur = q;
        while (p != src) {
            --p;
            --q;
            if (q != 0)
                *q = *p;
        }
        U16* r = src;
        if (count != 0) {
            hulk_intptr d = ((int)value) - (hulk_intptr)src;
            int n = count;
            do {
                if (r != 0)
                    *r = *(U16*)(d + (hulk_intptr)r);
                ++r;
                --n;
            } while (n != 0);
        }
    }
}

namespace fn_fe1b1ee9 {

// 0x002f9990 FUN_002f9990 (109 B): equivalent/0x002f9990.cpp
// sym: ?FUN_002f9990@Vec_2f9990@fn_fe1b1ee9@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f9990 @ 0x002f9990
Vec_2f9990 *Vec_2f9990::FUN_002f9990(Vec_2f9990 *src)
{
    hulk_intptr cap = src->end - src->begin;
    if (cap == 0) {
        begin = 0;
    } else {
        hulk_uintptr bytes = cap * 16;
        Elem_2f9990 *p = (Elem_2f9990 *)FUN_0008d6d0(bytes);
        begin = p;
        if (p != 0) {
            last = p;
            end = (Elem_2f9990 *)((char *)p + bytes);
            last = FUN_002f95f0(src->begin, src->last - src->begin, p);
            return this;
        }
    }
    last = 0;
    end = 0;
    return this;
}

} // namespace fn_fe1b1ee9

// 0x002f9a00 FUN_002f9a00 (122 B): equivalent/0x002f9a00.cpp
// sym: ?FUN_002f9a00@WideVector_2f9a00@owners@@QAEPAU12@PBU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002f9a00 @ 0x002f9a00
owners::WideVector_2f9a00* owners::WideVector_2f9a00::FUN_002f9a00(const owners::WideVector_2f9a00* other) {
    hulk_intptr capacity = other->cap - other->first;
    if (capacity != 0) {
        first = (unsigned short*)FUN_0008d6d0(capacity * 2);
        if (first) {
            last = first;
            cap = first + capacity;
            const unsigned short* src = other->first;
            unsigned short* dst = first;
            for (hulk_intptr n = other->last - other->first; n != 0; n--) {
                if (dst)
                    *dst = *src;
                src++;
                dst++;
            }
            last = dst;
            return this;
        }
    } else {
        first = 0;
    }
    last = 0;
    cap = 0;
    return this;
}

namespace fn_fe1b1ee9 {

// 0x002f9a80 FUN_002f9a80 (111 B): matches/0x002f9a80.cpp
// sym: ?FUN_002f9a80@MeshBuffers_2f9a80@fn_fe1b1ee9@@QAEXII@Z
// FUN_002f9a80 @ 0x002f9a80
void MeshBuffers_2f9a80::FUN_002f9a80(unsigned int numVerts, unsigned int numIndices)
{
    if (numVerts != 0) {
        vertsStart = (Vertex_2f9a80 *)FUN_0008d6d0(numVerts * sizeof(Vertex_2f9a80));
        if (vertsStart != 0) {
            vertsBegin = vertsStart;
            vertsEnd = vertsStart + numVerts;
        } else {
            vertsBegin = 0;
            vertsEnd = 0;
        }
    } else {
        vertsStart = 0;
        vertsBegin = 0;
        vertsEnd = 0;
    }
    if (numIndices != 0) {
        indicesStart = (unsigned short *)FUN_0008d6d0(numIndices * 2);
        if (indicesStart != 0) {
            indicesEnd = indicesStart + numIndices;
            indicesBegin = indicesStart;
        } else {
            indicesBegin = 0;
            indicesEnd = 0;
        }
    } else {
        indicesStart = 0;
        indicesBegin = 0;
        indicesEnd = 0;
    }
}


// 0x002f9b30 FUN_002f9b30 (33 B): matches/0x002f9b30.cpp
// sym: ?f@X_2f9b30@fn_fe1b1ee9@@QAEXXZ
// Same code shape as 0x002a47d0 (propagated; names are from that function)
void X_2f9b30::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}

} // namespace fn_fe1b1ee9

// 0x002f9b60 FUN_002f9b60 (95 B): matches/0x002f9b60.cpp
// sym: ?FUN_002f9b60@Buffer_2f9b60@owners@@QAE_NIPAX@Z
// Same code shape as 0x002b0fb0 (propagated; names are from that function)
bool owners::Buffer_2f9b60::FUN_002f9b60(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        begin = (int*)Alloc(count * 8);
        if (begin != 0) {
            end = (int*)((char*)begin + count * 8);
            FUN_002f98c0((unsigned int *)(void *)begin, count, (unsigned int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_fe1b1ee9 {

// 0x002f9bc0 FUN_002f9bc0 (85 B): equivalent/0x002f9bc0.cpp
// sym: ?FUN_002f9bc0@Buffer@fn_fe1b1ee9@@QAEXPAGI0@Z
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 13/14, incomplete)
// FUN_002f9bc0 @ 0x002f9bc0
void Buffer::FUN_002f9bc0(unsigned short *position, hulk_uintptr count, unsigned short *source) { unsigned short *oldEnd=end; unsigned short *newEnd=oldEnd+count; if ((hulk_ulongptr)newEnd <= (hulk_ulongptr)limit) { end=newEnd; while (oldEnd != position) { --oldEnd; --newEnd; if (newEnd) *newEnd=*oldEnd; } while (count--) { if (position) *position=*source; ++position; } } }


// 0x002f9ca0 FUN_002f9ca0 (39 B): matches/0x002f9ca0.cpp
// sym: ?FUN_002f9ca0@Object@fn_fe1b1ee9@@QAEXI@Z
void Object::FUN_002f9ca0(unsigned int value) {
    Range range;
    range.first = 0;
    range.last = 0xffffffff;
    ((owners::Buffer_2f9b60 *)this)->FUN_002f9b60(value, (Range *)(&range));
}


// 0x002f9cd0 FUN_002f9cd0 (41 B): matches/0x002f9cd0.cpp
// sym: ?f@Obj_2f9cd0@fn_fe1b1ee9@@QAEXXZ
void Obj_2f9cd0::f() {
    hulk_intptr x = c;
    d = x;
    if (x)
        Release((void*)x);
    x = a;
    b = x;
    if (x)
        Release((void*)x);
}


// 0x002f9d00 FUN_002f9d00 (90 B): matches/0x002f9d00.cpp
// sym: ?fn@Str_2f9d00@fn_fe1b1ee9@@QAEXIPAG@Z
void Str_2f9d00::fn(unsigned n, unsigned short* p) {
    if (!first)
        ((owners::Buffer_2f9340 *)this)->FUN_002f9340((unsigned int)n);
    unsigned count = (unsigned)(last - first);
    if (n > count) {
        grow(last, n - count, p);
        return;
    }
    if (n < count) {
        last = cp(last, last, first + n);
    }
}


// 0x002f9d60 FUN_002f9d60 (63 B): matches/0x002f9d60.cpp
// sym: ?func@C_2f9d60@fn_fe1b1ee9@@QAEPAV12@E@Z
C_2f9d60* C_2f9d60::func(unsigned char p) {
    void* v = m40;
    m44 = v;
    if (v) {
        operator delete[](v);
    }
    v = m30;
    m34 = v;
    if (v) {
        operator delete[](v);
    }
    if (p & 1) {
        operator delete(this);
    }
    return this;
}


// 0x002f9da0 FUN_002f9da0 (115 B): matches/0x002f9da0.cpp
// sym: ?FUN_002f9da0@Pose@fn_fe1b1ee9@@QAEPAU12@PBU12@@Z
// FUN_002f9da0 @ 0x002f9da0
Pose *Pose::FUN_002f9da0(const Pose *src)
{
    first = src->first;
    second = src->second;
    a.FUN_002f9990(&src->a);
    ((owners::WideVector_2f9a00 *)&b)->FUN_002f9a00((const owners::WideVector_2f9a00 *)(const PartB_2f9da0 *)(&src->b));
    return this;
}


// 0x002f9ed0 FUN_002f9ed0 (219 B): equivalent/0x002f9ed0.cpp
// sym: ?FUN_002f9ed0@Pool_2f9ed0@fn_fe1b1ee9@@QAEIXZ
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 21/24, incomplete)
// FUN_002f9ed0 @ 0x002f9ed0
// Compacts the pool's strings (16-byte records holding [begin, end) ranges of 16-bit characters)
// to the front of the pool's character buffer and resizes the buffer to the used length.
// Returns the used length.
hulk_uintptr Pool_2f9ed0::FUN_002f9ed0()
{
    unsigned short *dest = buf.begin;
    for (Str_2f9ed0 *s = strBegin; s != strEnd; s++) {
        unsigned short *src = s->begin;
        if (src != dest) {
            unsigned short *last = s->end;
            unsigned short *d = dest;
            while (src != last) {
                *d = *src;
                src++;
                d++;
            }
            s->begin = dest;
            s->end = d;
        }
        dest = s->end;
    }

    hulk_uintptr n = dest - buf.begin;
    unsigned short fill = 0;
    if (buf.begin == 0) {
        if (n == 0) {
            buf.begin = 0;
            buf.end = 0;
            buf.cap = 0;
        } else {
            hulk_uintptr bytes = n * 2;
            unsigned short *p = (unsigned short *)FUN_0008d6d0(bytes);
            buf.begin = p;
            if (p) {
                buf.end = p;
                buf.cap = p + n;
            } else {
                buf.end = 0;
                buf.cap = 0;
            }
        }
    }
    hulk_uintptr size = buf.end - buf.begin;
    if (n > size) {
        buf.FUN_002f9bc0(buf.end, n - size, &fill);
        return n;
    }
    if (n < size)
        buf.end = buf.begin + n;
    return n;
}


// 0x002f9fb0 FUN_002f9fb0 (64 B): matches/0x002f9fb0.cpp
// sym: ?fn@fn_fe1b1ee9@@YAXPAUEntry@1@0@Z
void __cdecl fn(Entry* first, Entry* last) {
    for (; first != last; ++first) {
        void* b = first->b;
        first->bCopy = b;
        if (b)
            release(b);
        void* a = first->a;
        first->aCopy = a;
        if (a)
            release(a);
    }
}


// 0x002f9ff0 FUN_002f9ff0 (50 B): matches/0x002f9ff0.cpp
// sym: _FUN_002f9ff0
extern "C" hulk_intptr __cdecl FUN_002f9ff0(Item_2f9ff0* p, int count, int b) {
    if (count != 0) {
        int n = count;
        Item_2f9ff0* q = p;
        do {
            if (q)
                q->f(b);
            q = (Item_2f9ff0*)((char*)q + 0x50);
            --n;
        } while (n != 0);
        return (hulk_intptr)q;
    }
    return (hulk_intptr)p;
}


// 0x002fa030 FUN_002fa030 (32 B): matches/0x002fa030.cpp
// sym: ?target@fn_fe1b1ee9@@YIXPAUObj_2fa030@1@@Z
// Same code shape as 0x002907f0 (propagated; names are from that function)
void __fastcall target(Obj_2fa030* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}


// 0x002fa050 FUN_002fa050 (48 B): matches/0x002fa050.cpp
// sym: ?Target@Obj_2fa050@fn_fe1b1ee9@@QAEXXZ
void Obj_2fa050::Target() {
    Cleanup(a, b);
    if (a)
        Release(a);
    a = 0;
    b = 0;
}


// 0x002fa0f0 FUN_002fa0f0 (48 B): matches/0x002fa0f0.cpp
// sym: ?FUN_002fa0f0@fn_fe1b1ee9@@YIXPAUTarget_2fa0f0@1@@Z
void __fastcall FUN_002fa0f0(Target_2fa0f0* object) {
    if (object->third != 0)
        ReleaseThing(object->third);
    if (object->first != 0) {
        DoPair(object->first, object->second);
        ReleaseThing(object->first);
    }
}


// 0x002fa180 FUN_002fa180 (97 B): equivalent/0x002fa180.cpp
// sym: ?FUN_002fa180@Transform@fn_fe1b1ee9@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa180 @ 0x002fa180
void Transform::FUN_002fa180(unsigned int value)
{
    BoundsData bounds;
    bounds.lower[0] = 0x5368d4a5;
    bounds.lower[1] = 0x5368d4a5;
    bounds.lower[2] = 0x5368d4a5;
    bounds.upper[0] = 0xd368d4a5;
    bounds.upper[1] = 0xd368d4a5;
    bounds.upper[2] = 0xd368d4a5;
    bounds.first[0] = 0;
    bounds.first[1] = 0;
    bounds.first[2] = 0;
    bounds.second[0] = 0;
    bounds.second[1] = 0;
    bounds.second[2] = 0;
    ((owners::Buffer_2fa080 *)this)->FUN_002fa080(value, (BoundsData *)(&bounds));
}


// 0x002fa1f0 FUN_002fa1f0 (157 B): equivalent/0x002fa1f0.cpp
// sym: ?FUN_002fa1f0@Range_2fa1f0@fn_fe1b1ee9@@QAEXPAUDesc_2fa1f0@2@PAUSkeleton@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fa1f0 @ 0x002fa1f0
// FUN_002fa1f0: set up a range over a shared u16 buffer and fill it from two descriptors
void Range_2fa1f0::FUN_002fa1f0(Desc_2fa1f0 *d, Skeleton *s)
{
    unsigned short *oldBegin = begin;
    owner = s;
    end = oldBegin;
    f4 = s->fd0;
    Frame_2fa1f0 f;
    ((owners::Quantizer_2f3960 *)s)->FUN_002f3960((unsigned short *)(Pair6 *)(&f.first), (const float *)(Desc_2fa1f0 *)d);
    ((owners::Quantizer_2f3960 *)s)->FUN_002f3960((unsigned short *)(Pair6 *)(&f.second), (const float *)(Desc_2fa1f0 *)(d + 1));
    begin = (*(unsigned short**)&DAT_00555440);
    end = (*(unsigned short**)&DAT_00555440);
    s->holder->worker->FUN_00307060(&f.first, this);
    end = begin + *(*(unsigned short**)&DAT_0055543c);
    FUN_002f46a0(begin, end, (int)(end - begin));
    end = ((unsigned short *)FUN_002f9190((short *)(unsigned short *)begin, (short *)(unsigned short *)end));
}


// 0x002fa4e0 FUN_002fa4e0 (150 B): equivalent/0x002fa4e0.cpp
// sym: _FUN_002fa4e0
// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 14/16, incomplete)
// FUN_002fa4e0 @ 0x002fa4e0
extern "C" void FUN_002fa4e0(unsigned int n, unsigned int a, unsigned int b)
{
    (*(CellGrid*)&DAT_0055545c).FUN_002fa180(n);
    for (unsigned int i = 0; i < n; i++)
        (*(CellGrid*)&DAT_0055545c).cells[i].FUN_002f9a80(a, b);

    if ((*(Pair_2fa4e0**)&DAT_00555468) != 0)
        return;
    if (n != 0) {
        unsigned int bytes = n * sizeof(Pair_2fa4e0);
        Pair_2fa4e0 *p = (Pair_2fa4e0 *)FUN_0008d6d0(bytes);
        (*(Pair_2fa4e0**)&DAT_00555468) = p;
        if (p != 0) {
            (*(Pair_2fa4e0**)&DAT_0055546c) = (Pair_2fa4e0 *)((char *)p + bytes);
            for (unsigned int i = n; i != 0; i--, p++) {
                if (p != 0) {
                    p->first = 0;
                    p->second = -1;
                }
            }
            return;
        }
    }
    (*(Pair_2fa4e0**)&DAT_00555468) = 0;
    (*(Pair_2fa4e0**)&DAT_0055546c) = 0;
}


// 0x002fa580 FUN_002fa580 (10 B): matches/0x002fa580.cpp
// sym: _FUN_002fa580
// Same code shape as 0x001d0430 (propagated; names are from that function)
// data: gValue_2fa580 = DAT_004d2c9c
extern "C" void FUN_002fa580(u32_2fa580 value) {
    (*(u32_2fa580*)&DAT_004d2c9c) = value;
}


// 0x002fa5b0 FUN_002fa5b0 (1 B): matches/0x002fa5b0.cpp
// sym: _FUN_002fa5b0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_002fa5b0() {}

} // namespace fn_fe1b1ee9

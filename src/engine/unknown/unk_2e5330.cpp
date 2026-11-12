// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e5330..0x002e5a70 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6f319cd {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6f319cd {} using namespace fn_f6f319cd;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f6f319cd {
struct V {
    int a, b, c, d;
};
struct Triple {
    unsigned int a, b, c;
};
extern void* FUN_0008d6d0(unsigned int);
struct IntVec2 {
    int *first;
    int *last;
    IntVec2(const IntVec2 &other) throw();
};
struct Entry_2e55a0 {
    int* begin;
    int* end;
    int pad;
};
class Obj_2e55a0 {
  public:
    char pad[0x14];
    Entry_2e55a0* entries;
    char Check_002e5330(int, int*);
    hulk_intptr Count(int);
};
struct Row_2e55e0 {
    int* p;
    int pad[2];
};
struct Obj_2e55e0 {
    char pad[0x14];
    Row_2e55e0* mRows;
    int target(int a, int b);
};
struct E_2e5640 {
    char b[16];
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" void __cdecl Init(void*, unsigned int, void*);
class Buffer_2e5640 {
  public:
    E_2e5640* data;
    E_2e5640* end;
    char Create(unsigned int count, void* arg);
};
void __cdecl FUN_002e5410(void* data, unsigned count, int value);
void __cdecl FUN_002e5450(void*, unsigned int, void*);
extern "C" int * __cdecl FUN_002e54a0(int *, int, const int *);
class Buffer_2e5770 {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};
typedef unsigned char byte_2e5820;
class Thing_2e5820 {
  public:
    void* mValue;
    Thing_2e5820* Destroy(byte_2e5820 flags);
};
struct Segment_2e5850 {
    int *begin;
    int *end;
    int cap;
};
class Source_2e5850 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x10];
    Segment_2e5850 *segments;
    char FUN_002e5330(unsigned int key, unsigned int *outIndex);
};
class SegmentCursor {
public:
    unsigned int key;
    unsigned int index;
    int last;
    Source_2e5850 *source;
    SegmentCursor(Source_2e5850 *src, unsigned int k);
};
struct Item_2e5920 {
    int a, b, c;
};
extern "C" void __fastcall FUN_002c6d50(Item_2e5920*);
void __cdecl Finish_0008d340(Item_2e5920*);
struct Owner_2e5920 {
    Item_2e5920* begin;
    Item_2e5920* end;
};
typedef unsigned int u32_2e59b0;
class Obj_2e59b0 {
  public:
    char pad[12];
    void Work_002e54e0(u32_2e59b0);
};
namespace pure3d {
class VertexAnimKeyFrame {
public:
    virtual void FUN_002e5a70();
    unsigned int field04, field08, field0c, field10, field14, field18;
    unsigned int untouched1c;
    unsigned int field20, field24;
    unsigned int untouched28;
    unsigned int field2c, field30;
    unsigned int untouched34;
    unsigned int field38, field3c;
    unsigned int untouched40;
    unsigned int field44, field48;
    unsigned int untouched4c;
    unsigned int field50, field54;
    unsigned int untouched58;
    unsigned int field5c, field60;
    unsigned int untouched64;
    unsigned int field68, field6c;
    VertexAnimKeyFrame();
};
}

} // namespace fn_f6f319cd

// 0x002e5330 FUN_002e5330 (104 B): equivalent/0x002e5330.cpp
// sym: ?FUN_002e5330@SortedArray_2e5330@owners@@QAE_NIPAI@Z @4fa150ccacb0 @w0487671d57f4
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_002e5330 @ 0x002e5330
bool owners::SortedArray_2e5330::FUN_002e5330(unsigned int key, unsigned int* outIndex) {
    unsigned int* b = begin;
    hulk_intptr n = end - b;
    if (n == 0)
        return false;
    if (key < b[0] || key > b[n - 1])
        return false;
    hulk_uintptr lo = 0;
    hulk_uintptr hi = n - 1;
    hulk_uintptr mid = hi >> 1;
    for (;;) {
        if (mid > hi)
            return false;
        unsigned int v = b[mid];
        if (key == v) {
            if (outIndex)
                *(hulk_uintptr*)outIndex = mid;
            return true;
        }
        if (key < v)
            hi = mid - 1;
        else
            lo = mid + 1;
        mid = (hi + lo) >> 1;
        if (lo > mid)
            return false;
    }
}

namespace fn_f6f319cd {

// 0x002e53c0 FUN_002e53c0 (66 B): matches/0x002e53c0.cpp
// sym: ?FUN_002e53c0@fn_f6f319cd@@YAPAUV@1@PAU21@HPBU21@@Z
V* __cdecl FUN_002e53c0(V* dst, int n, const V* src) {
    while (n) {
        if (dst)
            *dst = *src;
        ++dst;
        --n;
    }
    return dst;
}


// 0x002e5410 FUN_002e5410 (60 B): matches/0x002e5410.cpp
// sym: ?FUN_002e5410@fn_f6f319cd@@YAPAUTriple@1@PAU21@HPBU21@@Z
Triple* __cdecl FUN_002e5410(Triple* destination, int count, const Triple* source) {
    while (count) {
        if (destination)
            *destination = *source;
        ++destination;
        --count;
    }
    return destination;
}

} // namespace fn_f6f319cd

// 0x002e5450 FUN_002e5450 (60 B): matches/0x002e5450.cpp [wrapped: lost its match in the tree (codegen differs (22 of 28 instructions))]
// sym: ?FUN_002e5450@fn_002e5450@@YAPAUTriple@1@PAU21@IPBU21@@Z
namespace fn_002e5450 {
struct Triple {
    unsigned int first, second, third;
};
Triple* __cdecl FUN_002e5450(Triple* destination, unsigned int count, const Triple* source) {
    for (; count; --count) {
        if (destination)
            *destination = *source;
        destination = (Triple*)((char*)destination + 12);
    }
    return destination;
}
} // namespace fn_002e5450

namespace fn_f6f319cd {

// 0x002e54a0 FUN_002e54a0 (40 B): matches/0x002e54a0.cpp
// sym: _FUN_002e54a0
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002e54a0(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x002e54e0 FUN_002e54e0 (110 B): equivalent/0x002e54e0.cpp
// sym: ??0IntVec2@fn_f6f319cd@@QAE@ABU01@@Z @e6af28e42022 @w28f00e00918c
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002e54e0 @ 0x002e54e0
IntVec2::IntVec2(const IntVec2 &other) throw()
{
    hulk_intptr count = other.last - other.first;
    if (count != 0) {
        first = (int *)FUN_0008d6d0(count * 4);
        if (first != 0) {
            last = first + count;
            int *dst = first;
            const int *src = other.first;
            for (count = other.last - src; count != 0; count--) {
                if (dst != 0)
                    *dst = *src;
                src++;
                dst++;
            }
            return;
        }
    }
    first = 0;
    last = 0;
}


// 0x002e55a0 FUN_002e55a0 (55 B): matches/0x002e55a0.cpp
// sym: ?Count@Obj_2e55a0@fn_f6f319cd@@QAEHH@Z
hulk_intptr Obj_2e55a0::Count(int index) {
    if (Check_002e5330(index, &index) == 1) {
        Entry_2e55a0* e = entries + index;
        return (e->end - e->begin);
    }
    return 0;
}


// 0x002e55e0 FUN_002e55e0 (54 B): matches/0x002e55e0.cpp
// sym: ?target@Obj_2e55e0@fn_f6f319cd@@QAEHHH@Z
int Obj_2e55e0::target(int a, int b) {
    if (((owners::SortedArray_2e5330 *)this)->FUN_002e5330((unsigned int)a, (unsigned int *)(&a)) == true) {
        return mRows[a].p[b];
    }
    return 0;
}


// 0x002e5640 FUN_002e5640 (93 B): matches/0x002e5640.cpp
// sym: ?Create@Buffer_2e5640@fn_f6f319cd@@QAEDIPAX@Z
char Buffer_2e5640::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2e5640*)Alloc(count * sizeof(E_2e5640));
        if (data) {
            end = data + count;
            Init(data, count, arg);
            return 1;
        }
    }
    data = 0;
    end = 0;
    return 0;
}

} // namespace fn_f6f319cd

// 0x002e56a0 FUN_002e56a0 (94 B): equivalent/0x002e56a0.cpp
// sym: ?FUN_002e56a0@Buffer_2e56a0@owners@@QAE_NIH@Z @88434c616f9f @w24ced63e9050
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e56a0 @ 0x002e56a0
bool owners::Buffer_2e56a0::FUN_002e56a0(unsigned count, hulk_intptr value) {
    if (data) return false;
    if (count) {
        void* memory = FUN_0008d6d0(count * 12);
        data = memory;
        if (memory) {
            end = (char*)memory + count * 12;
            FUN_002e5410(memory, count, ((int)value));
            return true;
        }
    }
    data = 0;
    end = 0;
    return false;
}


// 0x002e5700 FUN_002e5700 (94 B): equivalent/0x002e5700.cpp
// sym: ?FUN_002e5700@Buffer_2e5700@owners@@QAE_NIPAX@Z @ed4c823653e2 @w5a1a88dab7a6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e5700 @ 0x002e5700
bool owners::Buffer_2e5700::FUN_002e5700(unsigned int count, void* source) {
    if (begin) return false;
    if (count) {
        unsigned int bytes = count * 12;
        void* memory = FUN_0008d6d0(bytes);
        begin = memory;
        if (memory) {
            end = (char*)memory + bytes;
            FUN_002e5450(memory, count, source);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_f6f319cd {

// 0x002e5770 FUN_002e5770 (95 B): matches/0x002e5770.cpp
// sym: ?Create@Buffer_2e5770@fn_f6f319cd@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool Buffer_2e5770::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002e54a0((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002e5820 FUN_002e5820 (40 B): matches/0x002e5820.cpp
// sym: ?Destroy@Thing_2e5820@fn_f6f319cd@@QAEPAV12@E@Z
// Same code shape as 0x002b1200 (propagated; names are from that function)
Thing_2e5820* Thing_2e5820::Destroy(byte_2e5820 flags) {
    if (mValue != 0)
        FUN_0008d340(mValue);
    if ((flags & 1) != 0)
        FUN_0008d330(this);
    return this;
}


// 0x002e5850 FUN_002e5850 (133 B): equivalent/0x002e5850.cpp
// sym: ??0SegmentCursor@fn_f6f319cd@@QAE@PAVSource_2e5850@1@I@Z @277e6bad06c5 @w5b89015eb0ef
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e5850 @ 0x002e5850
SegmentCursor::SegmentCursor(Source_2e5850 *src, unsigned int k)
{
    key = 0;
    index = 0;
    last = 0;
    source = 0;
    if (src != 0)
        src->AddRef();
    if (source != 0)
        source->Release();
    source = src;
    key = k;
    index = 0;
    last = -1;
    if (source->FUN_002e5330(k, &index) == 1) {
        Segment_2e5850 *s = &source->segments[index];
        last = (int)(s->end - s->begin) - 1;
    }
}


// 0x002e5920 FUN_002e5920 (48 B): matches/0x002e5920.cpp
// sym: ?Target@fn_f6f319cd@@YIXPAUOwner_2e5920@1@@Z
void __fastcall Target(Owner_2e5920* self) {
    Item_2e5920* p = self->begin;
    if (p) {
        Item_2e5920* e = self->end;
        while (p != e) {
            FUN_002c6d50((Item_2e5920*)((char*)p + 4));
            p = (Item_2e5920*)((char*)p + 12);
        }
        Finish_0008d340(self->begin);
    }
}


// 0x002e59b0 FUN_002e59b0 (50 B): matches/0x002e59b0.cpp
// sym: _FUN_002e59b0
extern "C" hulk_uintptr __cdecl FUN_002e59b0(hulk_uintptr p, u32_2e59b0 count, u32_2e59b0 arg) {
    if (count != 0) {
        Obj_2e59b0* q = (Obj_2e59b0*)p;
        u32_2e59b0 i = count;
        do {
            if (q)
                q->Work_002e54e0(arg);
            q = (Obj_2e59b0*)((char*)q + 12);
            i--;
        } while (i != 0);
        return (hulk_uintptr)q;
    }
    return p;
}


// 0x002e5a10 FUN_002e5a10 (86 B): equivalent/0x002e5a10.cpp
// sym: ??0VertexAnimKeyFrame@pure3d@fn_f6f319cd@@QAE@XZ @9910310f0e1f @web42f9758acb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e5a10 @ 0x002e5a10
namespace pure3d {
VertexAnimKeyFrame::VertexAnimKeyFrame() {
    field04 = 0; field08 = 0; field0c = 0; field10 = 0;
    field14 = 0; field18 = 0; field20 = 0; field24 = 0;
    field2c = 0; field30 = 0; field38 = 0; field3c = 0;
    field44 = 0; field48 = 0; field50 = 0; field54 = 0;
    field5c = 0; field60 = 0; field68 = 0; field6c = 0;
}
}

} // namespace fn_f6f319cd

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a26c0..0x002a2e70 (kind game, layer engine, confidence high), dominant class pure3d::OpaqueTraversal
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff737d4f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff737d4f {} using namespace fn_ff737d4f;
namespace fn_ff737d4f { extern "C" char DAT_0042d78c[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff737d4f {
typedef unsigned int uint_2a26c0;
struct Item_2a26c0 { uint_2a26c0 key; uint_2a26c0 value; };
typedef unsigned int uint_2a27c0;
class O_2a2940 {
  public:
    void* Get(int n);
};
struct Item_2a2a30 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual uint v7();
};
struct Entry_2a2a30 {
    uint unused;
    Item_2a2a30** item;
    uint a, b;
};
extern "C" void __cdecl FUN_002a27c0(unsigned int, unsigned int, const unsigned int *, unsigned int *);
struct Device_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void bind(unsigned, unsigned);
    virtual void begin(unsigned);
    virtual void end(unsigned);
};
struct Material_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual unsigned get();
    virtual void set(unsigned);
    virtual unsigned char test();
};
struct Wrapper_2a2af0 {
    Material_2a2af0* material;
    void FUN_002a4060();
};
struct Modifier_2a2af0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual unsigned apply(unsigned);
    virtual unsigned restore(unsigned);
};
struct ItemData_2a2af0 {
    char pad[16];
    Modifier_2a2af0* modifier;
    char pad2[48];
    void* value;
};
struct Entry_2a2af0 {
    unsigned value;
    Wrapper_2a2af0* wrapper;
    ItemData_2a2af0* data;
};
struct Callback_2a2af0 {
    void FUN_002a06d0(void*);
};
struct Slot_2a2be0 {
    struct Item_2a2be0* item;      // 0x00
    struct Slot16_2a2be0* part;    // 0x04
    struct Parts* parts;    // 0x08
    int tag;                // 0x0c
};
struct Slot16_2a2be0 {
    int w[4];
};
struct Parts {
    char pad0[0x48];
    Slot16_2a2be0* begin;          // 0x48
    Slot16_2a2be0* end;            // 0x4c
};
struct Item_2a2be0 {
    char pad0[0x40];
    Parts* parts;           // 0x40
    int tag;                // 0x44
};
class OpaqueTraversal {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Item_2a2be0* item, unsigned int index, int unused);
    char pad04[0x18 - 4];
    int count;              // 0x18
    char pad1c[4];
    Slot_2a2be0* slots;            // 0x20
    char pad24[0x2c - 0x24];
    Slot_2a2be0** order;           // 0x2c
};
extern void* hulk_at_0042d78c[];
} // namespace fn_ff737d4f
void operator delete(void*);
namespace fn_ff737d4f {
class DisplayTraversal_2a2de0 {
  public:
    void* vptr;
    void Fin_002c6aa0();
};
class OpaqueTraversal_2a2de0 : public DisplayTraversal_2a2de0 {
  public:
    char pad[0x1c];
    void* m20;
    char pad2[8];
    void* m2c;
    ~OpaqueTraversal_2a2de0();
};
extern void* g_vftable_2a2e20[];
struct OpaqueTraversal_nv_2a2e20 {
    void Fn_002c6aa0();
};
class OpaqueTraversal_2a2e20 {
  public:
    void* vptr;
    char p4[0x1c];
    void* m20;
    char p24[8];
    void* m2c;
    OpaqueTraversal_2a2e20* f2(unsigned char flags);
};


// 0x002a26c0 FUN_002a26c0 (253 B): equivalent/0x002a26c0.cpp
// sym: ?FUN_002a26c0@fn_ff737d4f@@YAXIIPAUItem_2a26c0@1@0@Z @b383f3e648a6 @wa236ab08aef6
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a26c0 @ 0x002a26c0
void __cdecl FUN_002a26c0(uint_2a26c0 byteIndex, uint_2a26c0 count, Item_2a26c0* input, Item_2a26c0* output)
{
    uint_2a26c0 frequencies[256] = {0};
    uint_2a26c0 positions[256];
    uint_2a26c0 shift = (byteIndex * 8) & 31;
    uint_2a26c0 i;
    for (i = 0; i < count; ++i)
        ++frequencies[(input[i].key >> shift) & 255];
    positions[0] = 0;
    for (i = 1; i < 256; ++i)
        positions[i] = positions[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint_2a26c0 bucket = (input[i].key >> shift) & 255;
        uint_2a26c0 destination = positions[bucket];
        output[destination].key = input[i].key;
        output[destination].value = input[i].value;
        bucket = (input[i].key >> shift) & 255;
        ++positions[bucket];
    }
}


// 0x002a27c0 FUN_002a27c0 (249 B): equivalent/0x002a27c0.cpp
// sym: _FUN_002a27c0 @8cf91c01b202 @w6ae47ee57c68
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 10/10)
// FUN_002a27c0 @ 0x002a27c0
extern "C" void __cdecl FUN_002a27c0(unsigned int byteIndex, unsigned int count, const unsigned int * source, unsigned int * destination)
{
    uint_2a27c0 frequencies[256] = {0};
    uint_2a27c0 offsets[261];
    uint_2a27c0 shift = (byteIndex * 8) & 31;
    uint_2a27c0 i;
    for (i = 0; i < count; ++i)
        ++frequencies[(source[i] >> shift) & 255];
    offsets[0] = 0;
    for (i = 1; i < 256; ++i)
        offsets[i] = offsets[i-1] + frequencies[i-1];
    for (i = 0; i < count; ++i) {
        uint_2a27c0 value = source[i];
        uint_2a27c0 bucket = (value >> shift) & 255;
        destination[offsets[bucket]] = value;
        bucket = (source[i] >> shift) & 255;
        ++offsets[bucket];
    }
}

} // namespace fn_ff737d4f

// 0x002a2930 pure3d::OpaqueTraversal::vfunc_5 (8 B): matches/0x002a2930.cpp
// sym: ?vfunc_5@OpaqueTraversal@pure3d@@UAEXXZ
// Same code shape as 0x002a18e0 (propagated; names are from that function)
void pure3d::OpaqueTraversal::vfunc_5() {
    this->f_18 = 0;
}

namespace fn_ff737d4f {

// 0x002a2940 FUN_002a2940 (14 B): matches/0x002a2940.cpp
// sym: ?Get@O_2a2940@fn_ff737d4f@@QAEPAXH@Z
void* O_2a2940::Get(int n) {
    void* p = *(void**)this;
    return (char*)p + (n << 4);
}

} // namespace fn_ff737d4f

// 0x002a2a30 pure3d::OpaqueTraversal::vfunc_3 (182 B): matches/0x002a2a30.cpp
// sym: ?vfunc_3@OpaqueTraversal@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::OpaqueTraversal::vfunc_3() {
    uint keys[1024];
    uint temp[1024];
    if ((*(unsigned char *)&this->f_1c)) {
        for (uint i = 0; i < (*(uint *)&this->f_18); ++i) {
            uint h = (*(*(Entry_2a2a30 * *)&this->f_20)[i].item)->v7();
            keys[i] = ((h + (h >> 16)) & 0xffff) | (i << 22);
        }
        uint n = (*(uint *)&this->f_18);
        FUN_002a27c0(0, n, keys, temp);
        FUN_002a27c0(1, n, temp, keys);
        for (uint j = 0; j < (*(uint *)&this->f_18); ++j)
            (*(Entry_2a2a30 ** *)&this->f_2c)[j] = (*(Entry_2a2a30 * *)&this->f_20) + (keys[j] >> 22);
    }
}


// 0x002a2af0 pure3d::OpaqueTraversal::vfunc_4 (235 B): matches/0x002a2af0.cpp
// sym: ?vfunc_4@OpaqueTraversal@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::OpaqueTraversal::vfunc_4() {
    (*(*(Device_2a2af0***)&DAT_0052c2ac))->begin(0);
    for (unsigned i = 0; i < (*(unsigned int *)&this->f_18); ++i) {
        Entry_2a2af0* e = (*(Entry_2a2af0 ** *)&this->f_2c)[i];
        Wrapper_2a2af0* w = e->wrapper;
        ItemData_2a2af0* data = e->data;
        (*(*(Device_2a2af0***)&DAT_0052c2ac))->bind(0, e->value);
        if (w->material->test() == 1 && (*(Callback_2a2af0 * *)&this->f_14) && data->value)
            (*(Callback_2a2af0 * *)&this->f_14)->FUN_002a06d0(data->value);
        Modifier_2a2af0* mod = data->modifier;
        if (mod) {
            Material_2a2af0* m = w->material;
            m->set(mod->apply(m->get()));
            w->FUN_002a4060();
            m->set(mod->restore(m->get()));
        } else
            w->FUN_002a4060();
    }
    (*(*(Device_2a2af0***)&DAT_0052c2ac))->end(0);
}

namespace fn_ff737d4f {

// 0x002a2be0 pure3d::OpaqueTraversal::vfunc_6 (127 B): matches/0x002a2be0.cpp
// sym: ?vfunc_6@OpaqueTraversal@fn_ff737d4f@@UAEXPAUItem_2a2be0@2@IH@Z
// pure3d::OpaqueTraversal::vfunc_6 @ 0x002a2be0
// Queues part `index` of an item's part list, ignoring indices past the end.
void OpaqueTraversal::vfunc_6(Item_2a2be0* item, unsigned int index, int unused)
{
    if (item->parts == 0)
        return;
    if (index >= (unsigned int)(item->parts->end - item->parts->begin))
        return;
    order[count] = &slots[count];
    slots[count].item = item;
    slots[count].part = &item->parts->begin[index];
    slots[count].parts = item->parts;
    slots[count].tag = item->tag;
    count++;
}

} // namespace fn_ff737d4f

// 0x002a2d50 FUN_002a2d50 (129 B): equivalent/0x002a2d50.cpp [wrapped: conflict: OpaqueTraversal]
// sym: ?FUN_002a2d50@OpaqueTraversal@fn_002a2d50@@QAEPAV12@I@Z @2d189e93dae7 @wc09cf9404296
namespace fn_002a2d50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002a2d50 @ 0x002a2d50
// 0x002a2d50: OpaqueTraversal constructor reserving n 16-byte records and n 4-byte indices
extern char DAT_0042d78c[];
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);

class OpaqueTraversal {
public:
    hulk_intptr vptr;
    char pad04[8];
    unsigned int flags;
    int field_10;
    char pad14[4];
    int field_18;
    char field_1c;
    char pad1d[3];
    char* recordsBegin;
    char* recordsEnd;
    char pad28[4];
    char* indicesBegin;
    char* indicesEnd;
    void FUN_002c6a80();
    OpaqueTraversal* FUN_002a2d50(unsigned int n);
};

OpaqueTraversal* OpaqueTraversal::FUN_002a2d50(unsigned int n)
{
    FUN_002c6a80();
    vptr = (hulk_intptr)DAT_0042d78c;
    field_18 = 0;
    field_1c = 1;
    if (n != 0) {
        unsigned int size = n * 16;
        char* mem = (char*)FUN_0008d6d0(size);
        recordsBegin = mem;
        if (mem != 0)
            recordsEnd = mem + size;
        else {
            recordsBegin = 0;
            recordsEnd = 0;
        }
    } else {
        recordsBegin = 0;
        recordsEnd = 0;
    }
    if (n != 0) {
        unsigned int size = n * 4;
        char* mem = (char*)FUN_0008d6d0(size);
        indicesBegin = mem;
        if (mem != 0)
            indicesEnd = mem + size;
        else {
            indicesBegin = 0;
            indicesEnd = 0;
        }
    } else {
        indicesBegin = 0;
        indicesEnd = 0;
    }
    flags &= 0xffffffcf;
    field_10 = 0;
    return this;
}
} // namespace fn_002a2d50

namespace fn_ff737d4f {

// 0x002a2de0 FUN_002a2de0 (49 B): matches/0x002a2de0.cpp
// sym: ??1OpaqueTraversal_2a2de0@fn_ff737d4f@@QAE@XZ
OpaqueTraversal_2a2de0::~OpaqueTraversal_2a2de0() {
    vptr = hulk_at_0042d78c;
    _ReadWriteBarrier();
    if (m2c)
        operator delete(m2c);
    if (m20)
        operator delete(m20);
    Fin_002c6aa0();
}


// 0x002a2e20 pure3d::OpaqueTraversal::vfunc_2 (70 B): matches/0x002a2e20.cpp
// sym: ?f2@OpaqueTraversal_2a2e20@fn_ff737d4f@@QAEPAV12@E@Z
OpaqueTraversal_2a2e20* OpaqueTraversal_2a2e20::f2(unsigned char flags) {
    vptr = ((void**)DAT_0042d78c);
    _ReadWriteBarrier();
    if (m2c)
        operator delete[](m2c);
    if (m20)
        operator delete[](m20);
    ((OpaqueTraversal_nv_2a2e20*)(((pure3d::OpaqueTraversal*)this)))->Fn_002c6aa0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_ff737d4f

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002222f0..0x00222460 (kind game, layer engine, confidence high), dominant class choreo2::PartitionDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/choreo2.h"
#define TREE_TU_BEGIN namespace fn_f7ce353a {
#define TREE_TU_END }
namespace fn_f7ce353a {} using namespace fn_f7ce353a;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f7ce353a {
struct Bits_222330 {
    unsigned int count;
    unsigned int w[1];
};
struct Obj_222330 {
    char pad[0x10];
    Bits_222330* bits;
};
struct PartitionDriver_222330 {
    char pad[0x14];
    Obj_222330* obj;
    bool Check(Obj_222330* other);
};
extern "C" char DAT_00427260[];
class Base_2223f0 {
  public:
    virtual void Init();
};
extern "C" void __fastcall FUN_0022a8e0(void*);
struct Ref_222430 {
    virtual void a();
    virtual void b();
};
class PartitionDriver {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual PartitionDriver* vfunc_2(unsigned char);
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    char _m_pad_4[0xc];
    union { Base_2223f0* mSource; Ref_222430* member; };
    int a;
    int b;
    int c;
    PartitionDriver* Run(Base_2223f0* source);
};
struct PartitionDriver_222430 {
    void helper_0022a910();
};
extern void* hulk_at_00427260;
void destroy_00263f30(PartitionDriver*);


// 0x002222f0 choreo2::PartitionDriver::vfunc_7 (4 B): matches/0x002222f0.cpp
// sym: ?FUN_002222f0@fn_f7ce353a@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_002222f0(hulk_intptr object) {
    return *(int*)(object + 0x18);
}

} // namespace fn_f7ce353a

// 0x00222300 choreo2::PartitionDriver::vfunc_8 (4 B): matches/0x00222300.cpp
// sym: ?vfunc_8@PartitionDriver@choreo2@@UAEHXZ
int choreo2::PartitionDriver::vfunc_8() {
    return *(int*)((char*)this + 0x1c);
}

namespace fn_f7ce353a {

// 0x00222330 FUN_00222330 (103 B): matches/0x00222330.cpp
// sym: ?Check@PartitionDriver_222330@fn_f7ce353a@@QAE_NPAUObj_222330@2@@Z
bool PartitionDriver_222330::Check(Obj_222330* other) {
    if (!other)
        return false;
    Obj_222330* p = obj;
    if (!p)
        return true;
    Bits_222330* b = p->bits;
    Bits_222330* a = other->bits;
    unsigned int n = a->count;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int m = 1 << (i & 31);
        if ((a->w[i >> 5] & m) && (b->w[i >> 5] & m))
            return true;
    }
    return false;
}


// 0x002223f0 FUN_002223f0 (49 B): matches/0x002223f0.cpp
// sym: ?Run@PartitionDriver@fn_f7ce353a@@QAEPAV12@PAVBase_2223f0@2@@Z
PartitionDriver* PartitionDriver::Run(Base_2223f0* source) {
    FUN_0022a8e0((void*)(this));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427260);
    mSource = source;
    mSource->Init();
    a = 0;
    b = 0;
    c = *(int*)((char*)mSource + 0x10) - 1;
    return this;
}


// 0x00222430 choreo2::PartitionDriver::vfunc_2 (46 B): matches/0x00222430.cpp
// sym: ?vfunc_2@PartitionDriver@fn_f7ce353a@@UAEPAV12@E@Z
PartitionDriver* PartitionDriver::vfunc_2(unsigned char param) {
    *(void**)this = &hulk_at_00427260;
    member->b();
    ((PartitionDriver_222430*)this)->helper_0022a910();
    if (param & 1)
        destroy_00263f30(this);
    return this;
}

} // namespace fn_f7ce353a

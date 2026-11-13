// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00276650..0x00277110 (kind game, layer engine, confidence high), dominant class core::InstanceDrive
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_ff53bcc9 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff53bcc9 {} using namespace fn_ff53bcc9;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_ff53bcc9 {
struct Obj_276680 {
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
    virtual void* f13();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042bdd0[];
extern "C" char DAT_0042bddc[];
struct V {
    virtual void A();
    virtual void B();
};
struct InstanceDrive_2766e0 {
    void** v;
    void** v4;
    int pad;
    V* p;
    void f();
};
class Sub_276700 {
  public:
    virtual void F0();
    virtual void F1();
};
struct Inner_2767c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class Checker_276980 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual char check();
    void Finish_00272b60(void*, int, int);
};
extern void __cdecl Parse_002697c0(int, char*, char*, int*, int*);
extern void* __cdecl Allocate_00273560(int);
class InstanceDrive;
class Builder {
  public:
    Builder* make_002759e0(InstanceDrive*, int, int);
};
class Other_276cf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void tick();
};
struct InstanceDrive_nv_276d60 {
    void Fng_00272920(int, int);
};
struct InstanceDrive_nv_276d70 {
    void Fng_00272960(int);
};
struct InstanceDrive_nv_276d80 {
    void Fng_00272990(int);
};
struct InstanceDrive_nv_276d90 {
    void Fng_00272990(int);
};
struct InstanceDrive_nv_276da0 {
    void Fng_00272a80();
};
struct InstanceDrive_nv_276db0 {
    void Fng_00272a40(int);
};
struct InstanceDrive_nv_276dc0 {
    void Fng_002729f0(int);
};
struct InstanceDrive_nv_276dd0 {
    void Fng_00272b40(int);
};
struct InstanceDrive_nv_276de0 {
    void Fng_00272ae0(int, int);
};
class Ref_276ec0 {
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
    virtual void f20();
    virtual void f21();
};
class InstanceDrive_276ec0 {
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
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33(int*, int, int, int, int, int, int, int);
    virtual void f34(int*, int, int, int, int, int, int, int);
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
};
class Obj_277020 {
    char pad[0x10];

  public:
    unsigned int value;
};
class Inner_277030 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Inner_277040 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
struct Obj_277050 {
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
    virtual void f14(void*, void*, void*);
};
struct Drive {
    virtual void v0();
    virtual void v1();
    virtual void v2(unsigned char);
};
class InstanceDrive {
  public:
    virtual void F0();
    virtual void v1();
    virtual InstanceDrive* vfunc_2(unsigned char);
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
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void _m_vf27();
    virtual void _m_vf28();
    virtual void _m_vf29();
    virtual void _m_vf30();
    virtual void _m_vf31();
    virtual void _m_vf32();
    virtual void _m_vf33();
    virtual void _m_vf34();
    virtual void _m_vf35();
    virtual void _m_vf36();
    virtual void _m_vf37();
    virtual void _m_vf38();
    virtual void _m_vf39();
    virtual void _m_vf40();
    Sub_276700 sub;
    int count;
    union { Checker_276980* checker; Drive* drive; };
    int field10;
    void vfunc_8(int p2, int p3);
    void F1() { v1(); }
};
struct Obj_2770a0 {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4(void*);
};
extern void* hulk_at_0042bddc;
extern void* hulk_at_0042bdd0;
extern void* hulk_at_003f6098;


// 0x00276650 FUN_00276650 (45 B): matches/0x00276650.cpp
// sym: _FUN_00276650
// the "InstanceDrive" pool (0x00276680 allocates from it): items are core::InstanceDrive (0x24 bytes on the 32-bit build)
extern "C" void __cdecl FUN_00276650(int a, int b) {
    HULK_SIZE32(core::InstanceDrive, 0x24);
    FUN_0026d820(((char*)&DAT_0052a208));
    FUN_002702a0((void**)((char*)&DAT_0052a224), (int)sizeof(core::InstanceDrive), a, 0, b, (hulk_intptr)"InstanceDrive", 4);
}


// 0x00276680 FUN_00276680 (44 B): matches/0x00276680.cpp
// sym: _FUN_00276680
// Same code shape as 0x00273560 (propagated; names are from that function)
// data: gObjStorage = DAT_0052a208
// pops an item of the core memory pool (slot 13) under the lock; the item is a pointer on every target; the callers
// pass the item's size, which the pool's item size already is
extern "C" void* FUN_00276680(unsigned int size) {
    FUN_0026d850(((char*)&DAT_0052a208));
    void* r = (*(Obj_276680**)&DAT_0052a224)->f13();
    FUN_0026d840(((char*)&DAT_0052a208));
    return r;
}


// 0x002766e0 FUN_002766e0 (32 B): matches/0x002766e0.cpp
// sym: ?f@InstanceDrive_2766e0@fn_ff53bcc9@@QAEXXZ
void InstanceDrive_2766e0::f() {
    v = (void**)((hulk_intptr)DAT_0042bddc);
    v4 = (void**)((hulk_intptr)DAT_0042bdd0);
    p->B();
    v = (void**)((hulk_intptr)DAT_003f6098);
}


// 0x00276700 core::InstanceDrive::vfunc_0 (30 B): matches/0x00276700.cpp
// sym: ?F0@InstanceDrive@fn_ff53bcc9@@UAEXXZ
void InstanceDrive::F0() {
    sub.F0();
    ++count;
    sub.F1();
}

} // namespace fn_ff53bcc9

// 0x00276720 core::InstanceDrive::vfunc_1 (127 B): equivalent/0x00276720.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_1@InstanceDrive@core@fn_00276720@@UAEXXZ @80dc47ba07f9 @w6abf63025fd0
namespace fn_00276720 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// core::InstanceDrive::vfunc_1 @ 0x00276720
void* __cdecl FUN_00273560(unsigned int size);

namespace core { struct InstanceDrive; }
struct Request {
    Request* FUN_00275b40(core::InstanceDrive* file);
};
struct Queue_276720 {
    void FUN_00272b60(Request* request, unsigned int context, unsigned int zero);
};
struct Lock_276720 {
    virtual void lock();
    virtual void unlock();
};

namespace core {
struct InstanceDrive {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int flags);
    Lock_276720 lock;
    int refs;
    Queue_276720* queue;
    unsigned int context;
    char pad14[12];
    char queued;
};

void InstanceDrive::vfunc_1()
{
    Lock_276720* l = &lock;
    l->lock();
    if (--refs != 0) {
        l->unlock();
        return;
    }
    if (queued) {
        queued = 0;
        l->unlock();
        Request* memory = static_cast<Request*>(FUN_00273560(0xc));
        Request* request = 0;
        if (memory) {
            request = memory->FUN_00275b40(this);
        }
        queue->FUN_00272b60(request, context, 0);
    } else {
        refs = 0x5dc;
        l->unlock();
        vfunc_2(1);
    }
}
}
} // namespace fn_00276720


// 0x002767a0 core::InstanceDrive::vfunc_0_adj4 (12 B): matches/0x002767a0.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_002767a0@@QAEXXZ
namespace fn_002767a0 {
// Same code shape as 0x00275e50 (propagated; names are from that function)
// data: g_data_2767a0 = DAT_0052a208

namespace core {
class File {
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
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    void vfunc_0_adj4();
};
} // namespace core
extern "C" void FUN_0026d850(void*);
void core::File::vfunc_0_adj4() {
    FUN_0026d850(((char*)&DAT_0052a208));
}
} // namespace fn_002767a0


// 0x002767b0 core::InstanceDrive::vfunc_1_adj4 (12 B): matches/0x002767b0.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_002767b0@@QAEXXZ
namespace fn_002767b0 {
// Same code shape as 0x00275e50 (propagated; names are from that function)
// data: g_data_2767b0 = DAT_0052a208

namespace core {
class File {
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
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    void vfunc_0_adj4();
};
} // namespace core
extern "C" void FUN_0026d840(void*);
void core::File::vfunc_0_adj4() {
    FUN_0026d840(((char*)&DAT_0052a208));
}
} // namespace fn_002767b0


// 0x002767c0 core::InstanceDrive::vfunc_3 (8 B): matches/0x002767c0.cpp
// sym: ?vfunc_3@InstanceDrive@core@@UAEXXZ
void core::InstanceDrive::vfunc_3() {
    (*(struct Inner_2767c0 * *)&this->f_0c)->g();
}


// 0x002767d0 core::InstanceDrive::vfunc_4 (69 B): equivalent/0x002767d0.cpp [wrapped: conflict: FUN_00273560; core::InstanceDrive]
// sym: ?vfunc_4@InstanceDrive@core@fn_002767d0@@UAEII@Z @3855712a99df @w5b59a447f3c2
namespace fn_002767d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_4 @ 0x002767d0
namespace core { struct InstanceDrive; }
struct DriveMediaRequest_2767d0 {
 DriveMediaRequest_2767d0* FUN_00275750(core::InstanceDrive*, unsigned int);
};
extern DriveMediaRequest_2767d0* __cdecl FUN_00273560(unsigned int);
struct Registry_2767d0 {
 unsigned int FUN_00272b60(DriveMediaRequest_2767d0*, unsigned int, unsigned int);
};
namespace core {
struct InstanceDrive {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual unsigned int vfunc_4(unsigned int);
 char pad[8];
 Registry_2767d0* registry;
 unsigned int key;
};
unsigned int InstanceDrive::vfunc_4(unsigned int argument) {
 DriveMediaRequest_2767d0* memory = FUN_00273560(16);
 DriveMediaRequest_2767d0* object = 0;
 if (memory) object = memory->FUN_00275750(this, argument);
 return registry->FUN_00272b60(object, key, 0);
}
}
} // namespace fn_002767d0


// 0x00276820 core::InstanceDrive::vfunc_5 (60 B): matches/0x00276820.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_5@InstanceDrive@core@fn_00276820@@UAEHXZ
namespace fn_00276820 {
namespace core {
struct Inner {
    int FUN_00272b60(void* value, unsigned int flags, int zero);
};
struct Item {
    void* FUN_002757f0(void* drive);
};
struct InstanceDrive {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int vfunc_5();
    void* secondaryVtable;
    int unknown;
    Inner* inner;
    unsigned int flags;
};
} // namespace core
core::Item* __cdecl FUN_00273560(int kind);
int core::InstanceDrive::vfunc_5() {
    core::Item* item = FUN_00273560(12);
    void* value = item ? item->FUN_002757f0(this) : 0;
    return inner->FUN_00272b60(value, flags, 0);
}
} // namespace fn_00276820


// 0x00276860 core::InstanceDrive::vfunc_6 (135 B): equivalent/0x00276860.cpp [wrapped: conflict: FUN_00273560; core::InstanceDrive]
// sym: ?vfunc_6@InstanceDrive@core@fn_00276860@@UAEXI@Z @190f06a65848 @w6c7209a84f4c
namespace fn_00276860 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_6 @ 0x00276860
namespace core { struct InstanceDrive; }
struct DriveCreateDirectoryRequest_276860 { void* FUN_00275880(core::InstanceDrive*, unsigned int); };
struct Drive {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
 void FUN_00272b60(void*, unsigned int, int);
};
void __cdecl FUN_002697c0(unsigned int, char*, char*, unsigned int*, unsigned int*);
DriveCreateDirectoryRequest_276860* __cdecl FUN_00273560(unsigned int);
namespace core {
struct InstanceDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned int);
 char bases[8];
 Drive* drive;
 unsigned int context;
};
void InstanceDrive::vfunc_6(unsigned int input) {
 unsigned int first = 0, second = 0;
 char part[20]; char path[260];
 FUN_002697c0(input,path,part,&second,&first);
 unsigned int selected = second;
 if (drive->slot6() < 0) selected = first;
 DriveCreateDirectoryRequest_276860* entry = FUN_00273560(32);
 void* result = 0;
 if (entry) result = entry->FUN_00275880(this,selected);
 drive->FUN_00272b60(result,context,0);
}
}
} // namespace fn_00276860


// 0x002768f0 core::InstanceDrive::vfunc_7 (135 B): equivalent/0x002768f0.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_7@InstanceDrive@core@fn_002768f0@@QAEHPBD@Z @c4ff4ce8dfc9 @we8cbbb333265
namespace fn_002768f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_7 @ 0x002768f0
struct Drive { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual signed char s6(); int FUN_00272b60(void*,void*,int); };
extern void __cdecl FUN_002697c0(const char*,char*,void*,unsigned*,unsigned*);
extern void* __cdecl FUN_00273560(unsigned);
namespace core { struct InstanceDrive; }
struct Object { void* FUN_00275930(core::InstanceDrive*,unsigned); };
namespace core { struct InstanceDrive { char pad[12]; Drive* drive; void* context; int vfunc_7(const char*); }; }
int core::InstanceDrive::vfunc_7(const char* path) {
 unsigned first=0, second=0; char extra[16]; char buffer[260];
 FUN_002697c0(path,buffer,extra,&second,&first);
 unsigned selected=second;
 if (drive->s6()<0) selected=first;
 Object* object=(Object*)FUN_00273560(32);
 void* result=object ? object->FUN_00275930(this,selected) : 0;
 return drive->FUN_00272b60(result,context,0);
}
} // namespace fn_002768f0

namespace fn_ff53bcc9 {

// 0x00276980 core::InstanceDrive::vfunc_8 (146 B): matches/0x00276980.cpp
// sym: ?vfunc_8@InstanceDrive@fn_ff53bcc9@@QAEXHH@Z
void InstanceDrive::vfunc_8(int p2, int p3) {
    char local104[260];
    char local118[20];
    int local120 = 0;
    int local11c = 0;
    Parse_002697c0(p2, local104, local118, &local11c, &local120);
    int value = local11c;
    if (checker->check() & 0x80)
        value = local120;
    Builder* b = (Builder*)Allocate_00273560(0x114);
    Builder* r;
    if (b)
        r = b->make_002759e0(this, value, p3);
    else
        r = 0;
    checker->Finish_00272b60(r, field10, 0);
}

} // namespace fn_ff53bcc9

// 0x00276a20 core::InstanceDrive::vfunc_9 (69 B): equivalent/0x00276a20.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_9@InstanceDrive@core@fn_00276a20@@QAEII@Z @c5f07056321c @w92c042a1ee2e
namespace fn_00276a20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_9 @ 0x00276a20
namespace core { struct InstanceDrive; }
struct DriveFindNextRequest_276a20 { DriveFindNextRequest_276a20* FUN_00275aa0(core::InstanceDrive*, unsigned int); };
extern void* __cdecl FUN_00273560(unsigned int);
struct Container_276a20 { unsigned int FUN_00272b60(DriveFindNextRequest_276a20*, unsigned int, unsigned int); };
namespace core {
struct InstanceDrive {
 void* vtable;
 void* secondaryVtable;
 unsigned int field8;
 Container_276a20* container;
 unsigned int field10;
 unsigned int vfunc_9(unsigned int);
};
unsigned int InstanceDrive::vfunc_9(unsigned int arg) {
 DriveFindNextRequest_276a20* storage = static_cast<DriveFindNextRequest_276a20*>(FUN_00273560(16));
 DriveFindNextRequest_276a20* item = 0;
 if (storage) item = storage->FUN_00275aa0(this, arg);
 return container->FUN_00272b60(item, field10, 0);
}
}
} // namespace fn_00276a20


// 0x00276a70 core::InstanceDrive::vfunc_10 (138 B): equivalent/0x00276a70.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_10@InstanceDrive@core@fn_00276a70@@UAEIPBD@Z @6185d7c640df @waefa81fb10b9
namespace fn_00276a70 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_10 @ 0x00276a70
struct ParsedData { char bytes[260]; };
void __cdecl FUN_002697c0(const char*, ParsedData*, unsigned int*, unsigned int*, unsigned int*);
void* __cdecl FUN_00273560(unsigned int);
namespace core { struct InstanceDrive; }
struct Created_276a70 { Created_276a70* FUN_00275bd0(core::InstanceDrive*, unsigned int); };
struct Backend_276a70 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
 unsigned int FUN_00272b60(Created_276a70*, unsigned int, int);
};
namespace core {
struct InstanceDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual unsigned int vfunc_10(const char*);
 char padding[8]; Backend_276a70* backend; unsigned int context;
};
unsigned int InstanceDrive::vfunc_10(const char* name) {
 ParsedData parsed;
 unsigned int other, primary = 0, alternate = 0;
 FUN_002697c0(name, &parsed, &other, &primary, &alternate);
 unsigned int selected = primary;
 if (backend->slot6() < 0) selected = alternate;
 Created_276a70* memory = (Created_276a70*)FUN_00273560(0x110);
 Created_276a70* object = memory ? memory->FUN_00275bd0(this, selected) : 0;
 return backend->FUN_00272b60(object, context, 0);
}
}
} // namespace fn_00276a70


// 0x00276b00 core::InstanceDrive::vfunc_11 (26 B): matches/0x00276b00.cpp
// sym: ?vfunc_11@InstanceDrive@core@@UAEXH@Z
void core::InstanceDrive::vfunc_11(int x) {
    vfunc_4(x);
    vfunc_22();
}


// 0x00276b20 core::InstanceDrive::vfunc_12 (16 B): matches/0x00276b20.cpp
// sym: ?vfunc_12@InstanceDrive@core@@UAEXXZ
void core::InstanceDrive::vfunc_12() {
    vfunc_5();
    vfunc_22();
}


// 0x00276b30 core::InstanceDrive::vfunc_13 (26 B): matches/0x00276b30.cpp
// sym: ?vfunc_13@InstanceDrive@core@@UAEXH@Z
void core::InstanceDrive::vfunc_13(int x) {
    vfunc_6(x);
    vfunc_22();
}


// 0x00276b50 core::InstanceDrive::vfunc_14 (26 B): matches/0x00276b50.cpp
// sym: ?vfunc_14@InstanceDrive@core@@UAEXH@Z
void core::InstanceDrive::vfunc_14(int x) {
    vfunc_7(x);
    vfunc_22();
}


// 0x00276b70 core::InstanceDrive::vfunc_15 (31 B): matches/0x00276b70.cpp
// sym: ?vfunc_15@InstanceDrive@core@@UAEXHH@Z
void core::InstanceDrive::vfunc_15(int a, int b) {
    vfunc_8(a, b);
    vfunc_22();
}


// 0x00276b90 core::InstanceDrive::vfunc_16 (26 B): matches/0x00276b90.cpp
// sym: ?vfunc_16@InstanceDrive@core@@UAEXH@Z
void core::InstanceDrive::vfunc_16(int p) {
    vfunc_9(p);
    vfunc_22();
}


// 0x00276bb0 core::InstanceDrive::vfunc_17 (26 B): matches/0x00276bb0.cpp
// sym: ?vfunc_17@InstanceDrive@core@@UAEXH@Z
void core::InstanceDrive::vfunc_17(int x) {
    vfunc_10(x);
    vfunc_22();
}


// 0x00276bd0 core::InstanceDrive::vfunc_18 (61 B): matches/0x00276bd0.cpp [wrapped: conflict: FUN_00273560; core::InstanceDrive]
// sym: ?vfunc_18@InstanceDrive@core@fn_00276bd0@@QAEHXZ
namespace fn_00276bd0 {
void* __cdecl FUN_00273560(int);
struct DriveCancelRequest_276bd0 {
    void* FUN_00275c80(void*);
};
struct DriveObject {
    int FUN_00272b60(void*, void*, int);
};
namespace core {
struct InstanceDrive {
    char pad[12];
    DriveObject* object;
    void* field10;
    int vfunc_18();
};
int InstanceDrive::vfunc_18() {
    DriveCancelRequest_276bd0* entry = (DriveCancelRequest_276bd0*)FUN_00273560(12);
    void* result = entry ? entry->FUN_00275c80(this) : 0;
    return object->FUN_00272b60(result, field10, 1);
}
} // namespace core
} // namespace fn_00276bd0


// 0x00276c10 core::InstanceDrive::vfunc_19 (85 B): equivalent/0x00276c10.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_19@InstanceDrive@core@fn_00276c10@@QAEIII@Z @94385131cbcd @we47d2e2b1f6f
namespace fn_00276c10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_19 @ 0x00276c10
void* __cdecl FUN_00273560(unsigned size);
namespace core { struct InstanceDrive; }
void* __cdecl FUN_0026dbb0();
struct DriveCompletionRequest_276c10 { void* FUN_00274d80(void*, core::InstanceDrive*, unsigned, unsigned); };
struct Owner_276c10 { unsigned FUN_00272b60(void*, unsigned, unsigned); };
namespace core {
struct InstanceDrive {
 void* vtable;
 char padding[8];
 Owner_276c10* owner;
 unsigned context;
 unsigned vfunc_19(unsigned a, unsigned b);
};
unsigned InstanceDrive::vfunc_19(unsigned a, unsigned b) {
 DriveCompletionRequest_276c10* item = (DriveCompletionRequest_276c10*)FUN_00273560(0x18);
 void* result = 0;
 if (item) result = item->FUN_00274d80(FUN_0026dbb0(), this, a, b);
 return owner->FUN_00272b60(result, context, 0);
}
}
} // namespace fn_00276c10


// 0x00276c70 core::InstanceDrive::vfunc_20 (72 B): equivalent/0x00276c70.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_20@InstanceDrive@core@fn_00276c70@@QAEII@Z @521ff26c692a @w71bb2b74036b
namespace fn_00276c70 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_20 @ 0x00276c70
void* __cdecl FUN_00273560(unsigned int size);
struct Owner_276c70 {
 unsigned int FUN_00272b60(void* object, unsigned int value, unsigned int zero);
};
struct CompletionEventRequest_276c70 {
 void* FUN_00274ba0(unsigned int argument, Owner_276c70* owner);
};
namespace core {
struct InstanceDrive {
 void* vtable;
 void* refVtable;
 unsigned int field8;
 Owner_276c70* owner;
 unsigned int value;
 unsigned int vfunc_20(unsigned int argument);
};
unsigned int InstanceDrive::vfunc_20(unsigned int argument) {
 CompletionEventRequest_276c70* item = static_cast<CompletionEventRequest_276c70*>(FUN_00273560(16));
 void* result = 0;
 if (item) result = item->FUN_00274ba0(argument, owner);
 return owner->FUN_00272b60(result, value, 0);
}
}
} // namespace fn_00276c70


// 0x00276cc0 core::InstanceDrive::vfunc_21 (36 B): matches/0x00276cc0.cpp [wrapped: conflict: InstanceDrive]
// sym: ?vfunc_21@InstanceDrive@fn_00276cc0@@UAE_NXZ
namespace fn_00276cc0 {
class IDrive_276cc0 {
  public:
    virtual void p0();
};
class IDrive {
  public:
    virtual void a();
    virtual void b();
};
class InstanceDrive : public IDrive_276cc0, public IDrive {
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
    virtual bool vfunc_21();
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
    char pad[12];
    int value;
};
bool InstanceDrive::vfunc_21() {
    IDrive* p = (IDrive*)((char*)this + sizeof(IDrive_276cc0));  // the second base (a cast tests for null)
    p->a();
    int x = value;
    bool r = (x == 0);
    p->b();
    return r;
}
} // namespace fn_00276cc0


// 0x00276cf0 core::InstanceDrive::vfunc_22 (47 B): matches/0x00276cf0.cpp
// sym: ?vfunc_22@InstanceDrive@core@@UAEXXZ
void core::InstanceDrive::vfunc_22() {
    while (!vfunc_21()) {
        (*(class Other_276cf0 * *)&this->f_0c)->tick();
        FUN_0026d6d0(0);
    }
}


// 0x00276d20 core::InstanceDrive::vfunc_23 (63 B): matches/0x00276d20.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_23@InstanceDrive@core@fn_00276d20@@QAEPAXXZ
namespace fn_00276d20 {
namespace core {
class Guard {
  public:
    virtual void enter();
    virtual void leave();
};
class Obj {
  public:
    char ready_00272a80();
    void* get_00272880();
};
class InstanceDrive {
  public:
    char pad[4];
    Guard guard;
    char pad2[4];
    Obj* obj;
    char pad3[8];
    void* value;
    void* vfunc_23();
};
void* InstanceDrive::vfunc_23() {
    guard.enter();
    void* result;
    if (obj->ready_00272a80())
        result = obj->get_00272880();
    else
        result = value;
    guard.leave();
    return result;
}
} // namespace core
} // namespace fn_00276d20


// 0x00276d60 core::InstanceDrive::vfunc_24 (8 B): matches/0x00276d60.cpp
// sym: ?vfunc_24@InstanceDrive@core@@UAEXHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_24(int a0, int a1) {
    ((InstanceDrive_nv_276d60*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272920(a0, a1);
}


// 0x00276d70 core::InstanceDrive::vfunc_25 (8 B): matches/0x00276d70.cpp
// sym: ?vfunc_25@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_25(int a0) {
    ((InstanceDrive_nv_276d70*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272960(a0);
}


// 0x00276d80 core::InstanceDrive::vfunc_26 (8 B): matches/0x00276d80.cpp
// sym: ?vfunc_26@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_26(int a0) {
    ((InstanceDrive_nv_276d80*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272990(a0);
}


// 0x00276d90 core::InstanceDrive::vfunc_27 (8 B): matches/0x00276d90.cpp
// sym: ?vfunc_27@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_27(int a0) {
    ((InstanceDrive_nv_276d90*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272990(a0);
}


// 0x00276da0 core::InstanceDrive::vfunc_28 (8 B): matches/0x00276da0.cpp
// sym: ?vfunc_28@InstanceDrive@core@@UAEXXZ
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_28() {
    ((InstanceDrive_nv_276da0*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272a80();
}


// 0x00276db0 core::InstanceDrive::vfunc_29 (8 B): matches/0x00276db0.cpp
// sym: ?vfunc_29@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_29(int a0) {
    ((InstanceDrive_nv_276db0*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272a40(a0);
}


// 0x00276dc0 core::InstanceDrive::vfunc_30 (8 B): matches/0x00276dc0.cpp
// sym: ?vfunc_30@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_30(int a0) {
    ((InstanceDrive_nv_276dc0*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_002729f0(a0);
}


// 0x00276dd0 core::InstanceDrive::vfunc_31 (8 B): matches/0x00276dd0.cpp
// sym: ?vfunc_31@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_31(int a0) {
    ((InstanceDrive_nv_276dd0*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272b40(a0);
}


// 0x00276de0 core::InstanceDrive::vfunc_32 (8 B): matches/0x00276de0.cpp
// sym: ?vfunc_32@InstanceDrive@core@@UAEXHH@Z
// Same code shape as 0x002665a0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_32(int a0, int a1) {
    ((InstanceDrive_nv_276de0*)((*(core::InstanceDrive * *)&this->f_0c)))->Fng_00272ae0(a0, a1);
}


// 0x00276df0 core::InstanceDrive::vfunc_33 (203 B): equivalent/0x00276df0.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_33@InstanceDrive@core@fn_00276df0@@QAEPAUCreated_276df0@3@PAPAU43@IIIIIII@Z @bd5038c86a30 @wc52c0413503f
namespace fn_00276df0 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_33 @ 0x00276df0
struct Child_276df0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual unsigned char v6(); };
struct Created_276df0 { Created_276df0* FUN_002764d0(Child_276df0*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, int); };
extern void __cdecl FUN_002697c0(unsigned, char*, unsigned*, unsigned*, unsigned*);
extern Created_276df0* __cdecl FUN_00275d50(unsigned);
namespace core { struct InstanceDrive { void* vtable; void* refTable; unsigned field8; Child_276df0* child; Created_276df0* vfunc_33(Created_276df0**,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned); }; }
Created_276df0* core::InstanceDrive::vfunc_33(Created_276df0** out,unsigned path,unsigned a3,unsigned a4,unsigned a5,unsigned a6,unsigned a7,unsigned a8) {
 unsigned first=0;
 unsigned second=0;
 char buffer[260];
 unsigned other;
 FUN_002697c0(path,buffer,&other,&second,&first);
 unsigned selected=second;
 if ((signed char)child->v6()<0) selected=first;
 Created_276df0* p=FUN_00275d50(0x168);
 Created_276df0* result=0;
 if(p) result=p->FUN_002764d0(child,selected,a3,a4,a5,a6,a7,a8,1);
 *out=result;
 return result;
}
} // namespace fn_00276df0

namespace fn_ff53bcc9 {

// 0x00276ec0 core::InstanceDrive::vfunc_34 (64 B): matches/0x00276ec0.cpp
// sym: ?f34@InstanceDrive_276ec0@fn_ff53bcc9@@UAEXPAHHHHHHHH@Z
void InstanceDrive_276ec0::f34(int* p, int a, int b, int c, int d, int e, int f, int g) {
    InstanceDrive_276ec0* self = this;
    self->f33(p, a, b, c, d, e, f, g);
    if (*p)
        ((Ref_276ec0*)*(hulk_intptr*)p)->f21();
}

} // namespace fn_ff53bcc9

// 0x00276f00 core::InstanceDrive::vfunc_35 (193 B): equivalent/0x00276f00.cpp [wrapped: conflict: FUN_00275d50; core::InstanceDrive]
// sym: ?vfunc_35@InstanceDrive@core@fn_00276f00@@QAEPAUFile_276f00@3@PAPAU43@PBDIIIII@Z @719987e34b7d @w91cc8d0b6421
namespace fn_00276f00 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_35 @ 0x00276f00
struct Drive {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
};
struct File_276f00 {
 File_276f00* FUN_002763a0(Drive*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
extern void __cdecl FUN_002697c0(const char*, char*, char*, unsigned*, unsigned*);
extern File_276f00* __cdecl FUN_00275d50(unsigned);
namespace core {
struct InstanceDrive {
 char padding[12]; Drive* drive;
 File_276f00* vfunc_35(File_276f00**, const char*, unsigned, unsigned, unsigned, unsigned, unsigned);
};
File_276f00* InstanceDrive::vfunc_35(File_276f00** output, const char* input, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) {
 unsigned first=0, second=0;
 char small[20]; char large[260];
 FUN_002697c0(input,large,small,&second,&first);
 unsigned selected=second;
 if (drive->slot6()<0) selected=first;
 File_276f00* result=FUN_00275d50(0x168);
 if(result) result=result->FUN_002763a0(drive,selected,a,b,c,d,e);
 *output=result;
 return result;
}
}
} // namespace fn_00276f00


// 0x00276fd0 core::InstanceDrive::vfunc_36 (59 B): matches/0x00276fd0.cpp [wrapped: conflict: core::InstanceDrive]
// sym: ?vfunc_36@InstanceDrive@core@fn_00276fd0@@UAEXPAXIIIIII@Z
namespace fn_00276fd0 {
typedef unsigned int U_276fd0;
namespace core {
class InstanceDrive {
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
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void vfunc_36(void*, U_276fd0, U_276fd0, U_276fd0, U_276fd0, U_276fd0, U_276fd0);
};
class Obj_276fd0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
};
void InstanceDrive::vfunc_36(void* p, U_276fd0 a, U_276fd0 b, U_276fd0 c, U_276fd0 d, U_276fd0 e, U_276fd0 f) {
    this->vfunc_36(p, a, b, c, d, e, f);
    Obj_276fd0* o = *(Obj_276fd0**)p;
    if (o)
        o->v();
}
} // namespace core
} // namespace fn_00276fd0


// 0x00277010 core::InstanceDrive::vfunc_37 (3 B): matches/0x00277010.cpp
// sym: ?vfunc_37@InstanceDrive@core@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_37(int a) {
    (void)a;
}

namespace fn_ff53bcc9 {

// 0x00277020 core::InstanceDrive::vfunc_38 (4 B): matches/0x00277020.cpp
// sym: ?FUN_00277020@fn_ff53bcc9@@YIIPAVObj_277020@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_00277020(Obj_277020* self) {
    return self->value;
}

} // namespace fn_ff53bcc9

// 0x00277030 core::InstanceDrive::vfunc_39 (8 B): matches/0x00277030.cpp
// sym: ?vfunc_39@InstanceDrive@core@@UAEXXZ
// Same code shape as 0x002762d0 (propagated; names are from that function)
void core::InstanceDrive::vfunc_39() {
    (*(Inner_277030 * *)&this->f_0c)->f4();
}


// 0x00277040 core::InstanceDrive::vfunc_40 (8 B): matches/0x00277040.cpp
// sym: ?vfunc_40@InstanceDrive@core@@UAEXXZ
void core::InstanceDrive::vfunc_40() {
    ((Inner_277040*)(*(void * *)&this->f_0c))->f5();
}

namespace fn_ff53bcc9 {

// 0x00277050 FUN_00277050 (66 B): matches/0x00277050.cpp
// sym: _FUN_00277050
// Same code shape as 0x00274af0 (propagated; names are from that function)
extern "C" void FUN_00277050() {
    char a[4], b[4], c[4];
    FUN_0026d830(DAT_0052a208);
    (*(Obj_277050**)&DAT_0052a224)->f14(a, b, c);
    (*(Obj_277050**)&DAT_0052a224)->f1();
    (*(Obj_277050**)&DAT_0052a224) = 0;
}


// 0x002770a0 core::InstanceDrive::vfunc_2 (81 B): matches/0x002770a0.cpp
// sym: ?vfunc_2@InstanceDrive@fn_ff53bcc9@@UAEPAV12@E@Z
// data: g_obj_2770a0 = DAT_0052a224
InstanceDrive* InstanceDrive::vfunc_2(unsigned char flag) {
    *(void**)this = &hulk_at_0042bddc;
    *(void**)&this->sub = &hulk_at_0042bdd0;
    drive->v1();
    *(void**)this = &hulk_at_003f6098;
    if (flag & 1) {
        FUN_0026d850((void*)((hulk_intptr)DAT_0052a208));
        (*(Obj_2770a0**)&DAT_0052a224)->x4(this);
        FUN_0026d840((void*)((hulk_intptr)DAT_0052a208));
    }
    return this;
}

} // namespace fn_ff53bcc9

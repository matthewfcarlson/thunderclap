// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00275d20..0x00276650 (kind game, layer engine, confidence high), dominant class core::File
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f81ff691 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f81ff691 {} using namespace fn_f81ff691;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f81ff691 {
struct Obj_275d50 {
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
class Sub_275db0 {
  public:
    virtual void F0();
    virtual void F1();
};
class File_275db0 : public CoreFile {
  public:
    void F0();
};
void* __cdecl FUN_00273560(unsigned int size);
struct Drive_275dd0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275dd0 { void* FUN_00275110(void* file); };
struct Lock_275dd0 { virtual void lock(); virtual void unlock(); };
struct Slots_275dd0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int flags); };
struct File_275dd0 : CoreFile { void vfunc_1(); };
class File_275e70 : public CoreFile {
  public:
    void vfunc_8();
};
class FileCommitRequest_275e70 {
  public:
    void* FUN_002751a0(void*);
};
class Drive_275e70 {
  public:
    int FUN_00272b60(void*, int, int);
};
struct Drive_275eb0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275eb0 { void* FUN_00275230(void* file, void* buffer, unsigned int count, unsigned int flags); };
struct File_275eb0 : CoreFile { void vfunc_3(void* buffer, unsigned int count, unsigned int flags); };
struct Drive_275f00 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275f00 { void* FUN_002752e0(void* file, void* buffer, unsigned int count, unsigned int flags); };
struct File_275f00 : CoreFile { int vfunc_4(void* buffer, unsigned int count, unsigned int flags); };
struct Drive_275f50 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275f50 { void* FUN_00275390(void* file, unsigned int position); };
struct File_275f50 : CoreFile { void vfunc_5(unsigned int position); };
struct Drive_275fa0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275fa0 { void* FUN_00275430(void* file, unsigned int* result); };
struct File_275fa0 : CoreFile { int vfunc_6(unsigned int* result); };
struct Drive_275ff0 { int FUN_00272b60(void* request, int key, int front); };
struct Request_275ff0 { void* FUN_002754d0(void* file, unsigned int* result); };
struct File_275ff0 : CoreFile { unsigned int vfunc_7(unsigned int* result); };
class File_276120 : public CoreFile {
  public:
    void vfunc_17();
};
class FileCancelRequest_276120 {
  public:
    void* FUN_00275570(void*);
};
class Drive_276120 {
  public:
    int FUN_00272b60(void*, int, int);
};
struct Drive_276160 { int FUN_00272b60(void* request, int key, int front); };
extern "C" CoreThread* __cdecl FUN_0026dbb0();
struct FileCompletionRequest_276160 { void* FUN_00274ca0(void* thread, void* file, void* callback, unsigned int context); };
struct File_276160 : CoreFile { void vfunc_18(void* callback, unsigned int context); };
struct Drive_2761c0 { int FUN_00272b60(void* request, int key, int front); };
struct CompletionEventRequest_2761c0 { void* FUN_00274ba0(hulk_uintptr* signal, void* drive); };
struct File_2761c0 : CoreFile { void vfunc_19(hulk_uintptr* signal); };
class IMutable_276210 {
  public:
    virtual void e();
    virtual void f();
};
class File_276210 : public CoreFile {
  public:
    bool vfunc_20();
};
} // namespace fn_f81ff691
namespace core {
class X_276240 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
}
namespace fn_f81ff691 {
class Sub_276270 {
  public:
    virtual void f0();
    virtual void f1();
};
class File_276270 : public CoreFile {
  public:
    int vfunc_22();
};
} // namespace fn_f81ff691
namespace core {
class Source {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual signed char f6();
};
}
namespace fn_f81ff691 {
class File_2762a0 : public CoreFile {
  public:
    void* access();
};
class Inner_2762d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
typedef CoreFile Obj_2762f0;
struct Obj_276340 {
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
extern void* hulk_at_0042bd3c;
extern void* hulk_at_0042bd30;
extern void* hulk_at_003f6098;
class Sub_2764a0 {
  public:
    void fin_00277c30();
};
class Ref_2764a0 {
  public:
    virtual void x();
    virtual void y();
};
class File {
  public:
    void* vp;
    void* vp4;
    int f8;
    Ref_2764a0* r;
    char pad[0x11c];
    Sub_2764a0 sub;
    void vfunc_21_00276240();
    void shutdown();
};
struct Mgr_2765d0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void Free(void* p);
};
struct Obj_2765d0 {
    virtual void o0();
    virtual void Rel();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042bd30[];
extern "C" char DAT_0042bd3c[];
struct Sub_2765d0 {
    void FUN_00277c30();
};
struct File_2765d0 : CoreFile {
    File_2765d0* Fn(unsigned char f);
    void FUN_00276240();
};


// 0x00275d20 FUN_00275d20 (48 B): matches/0x00275d20.cpp
// sym: _FUN_00275d20
// data: fileName = DAT_0042bc9c
// the "File" pool (0x00275d50 allocates from it): items are core::File (records.h CoreFile, 0x168 bytes on the
// 32-bit build)
extern "C" void __cdecl FUN_00275d20(int a, int b) {
    HULK_SIZE32(CoreFile, 0x168);
    FUN_0026d820(((char*)&DAT_0052a1e8));
    FUN_002702a0((void**)((char*)&DAT_0052a204), (int)sizeof(CoreFile), a, 0, b, (hulk_intptr)DAT_0042bc9c, 4);
}


// 0x00275d50 FUN_00275d50 (44 B): matches/0x00275d50.cpp
// sym: _FUN_00275d50
// Same code shape as 0x00273560 (propagated; names are from that function)
// data: gObjStorage = DAT_0052a1e8
// pops an item of the core memory pool (slot 13) under the lock; the item is a pointer on every target; the callers
// pass the item's size, which the pool's item size already is
extern "C" void* FUN_00275d50(unsigned int size) {
    FUN_0026d850(((char*)&DAT_0052a1e8));
    void* r = (*(Obj_275d50**)&DAT_0052a204)->f13();
    FUN_0026d840(((char*)&DAT_0052a1e8));
    return r;
}


// 0x00275db0 core::File::vfunc_0 (30 B): matches/0x00275db0.cpp
// sym: ?F0@File_275db0@fn_f81ff691@@QAEXXZ
// Same code shape as 0x00276700 (propagated; names are from that function)
void File_275db0::F0() {
    ((Sub_275db0*)&vftableMutable)->F0();
    ++refs;
    ((Sub_275db0*)&vftableMutable)->F1();
}


// 0x00275dd0 core::File::vfunc_1 (123 B): equivalent/0x00275dd0.cpp
// sym: ?vfunc_1@File_275dd0@fn_f81ff691@@QAEXXZ @f29ab84439bd @w4f6443878480
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// core::File::vfunc_1 @ 0x00275dd0
void File_275dd0::vfunc_1()
{
    Lock_275dd0* l = (Lock_275dd0*)&vftableMutable;
    l->lock();
    if (--refs != 0) {
        l->unlock();
        return;
    }
    if (flag1c) {
        l->unlock();
        Request_275dd0* memory = static_cast<Request_275dd0*>(FUN_00273560(0xc));
        void* request = 0;
        if (memory) {
            request = memory->FUN_00275110(this);
        }
        ((Drive_275dd0*)provider)->FUN_00272b60(request, (int)key, 0);
    } else {
        refs = 0x5dc;
        l->unlock();
        ((Slots_275dd0*)this)->vfunc_2(1);
    }
}

} // namespace fn_f81ff691

// 0x00275e50 core::File::vfunc_0_adj4 (12 B): matches/0x00275e50.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_00275e50@@QAEXXZ
namespace fn_00275e50 {
// data: g_data_275e50 = DAT_0052a1e8
// core::File's IMutable slots enter / leave the "File" pool's critical section (0x0052a1e8)
namespace core {
class File {
  public:
    void vfunc_0_adj4();
};
} // namespace core
extern "C" void FUN_0026d850(void*);
void core::File::vfunc_0_adj4() {
    FUN_0026d850(((char*)&DAT_0052a1e8));
}
} // namespace fn_00275e50


// 0x00275e60 core::File::vfunc_1_adj4 (12 B): matches/0x00275e60.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_00275e60@@QAEXXZ
namespace fn_00275e60 {
// data: g_data_275e60 = DAT_0052a1e8
// core::File's IMutable slots enter / leave the "File" pool's critical section (0x0052a1e8)
namespace core {
class File {
  public:
    void vfunc_0_adj4();
};
} // namespace core
extern "C" void FUN_0026d840(void*);
void core::File::vfunc_0_adj4() {
    FUN_0026d840(((char*)&DAT_0052a1e8));
}
} // namespace fn_00275e60

namespace fn_f81ff691 {

// 0x00275e70 core::File::vfunc_8 (60 B): matches/0x00275e70.cpp
// sym: ?vfunc_8@File_275e70@fn_f81ff691@@QAEXXZ
// core::File::vfunc_8 (records.h CoreFile): a commit request (0x002751a0) queued on the file's drive
void File_275e70::vfunc_8() {
    FileCommitRequest_275e70* a = (FileCommitRequest_275e70*)FUN_00273560(12);
    void* x = a ? a->FUN_002751a0(this) : 0;
    ((Drive_275e70*)provider)->FUN_00272b60(x, (int)key, 0);
}


// 0x00275eb0 core::File::vfunc_3 (79 B): equivalent/0x00275eb0.cpp
// sym: ?vfunc_3@File_275eb0@fn_f81ff691@@QAEXPAXII@Z @65f62b7236cf @w771b689294da
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_3 @ 0x00275eb0
void File_275eb0::vfunc_3(void* buffer, unsigned int count, unsigned int flags) {
 Request_275eb0* memory = static_cast<Request_275eb0*>(FUN_00273560(0x18));
 void* request = 0;
 if (memory) request = memory->FUN_00275230(this, buffer, count, flags);
 ((Drive_275eb0*)provider)->FUN_00272b60(request, (int)key, 0);
}


// 0x00275f00 core::File::vfunc_4 (79 B): equivalent/0x00275f00.cpp
// sym: ?vfunc_4@File_275f00@fn_f81ff691@@QAEHPAXII@Z @70984f4c8682 @w39f211c8a5d0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_4 @ 0x00275f00
int File_275f00::vfunc_4(void* buffer, unsigned int count, unsigned int flags) {
 Request_275f00* memory = static_cast<Request_275f00*>(FUN_00273560(0x18));
 void* request = 0;
 if (memory) request = memory->FUN_002752e0(this, buffer, count, flags);
 return ((Drive_275f00*)provider)->FUN_00272b60(request, (int)key, 0);
}


// 0x00275f50 core::File::vfunc_5 (69 B): equivalent/0x00275f50.cpp
// sym: ?vfunc_5@File_275f50@fn_f81ff691@@QAEXI@Z @01c9928655b5 @w2786f4d704c1
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_5 @ 0x00275f50
void File_275f50::vfunc_5(unsigned int position) {
 Request_275f50* memory = static_cast<Request_275f50*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_00275390(this, position);
 ((Drive_275f50*)provider)->FUN_00272b60(request, (int)key, 0);
}


// 0x00275fa0 core::File::vfunc_6 (69 B): equivalent/0x00275fa0.cpp
// sym: ?vfunc_6@File_275fa0@fn_f81ff691@@QAEHPAI@Z @2db676a61572 @w52924ee95c4b
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_6 @ 0x00275fa0
int File_275fa0::vfunc_6(unsigned int* result) {
 Request_275fa0* memory = static_cast<Request_275fa0*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_00275430(this, result);
 return ((Drive_275fa0*)provider)->FUN_00272b60(request, (int)key, 0);
}


// 0x00275ff0 core::File::vfunc_7 (69 B): equivalent/0x00275ff0.cpp
// sym: ?vfunc_7@File_275ff0@fn_f81ff691@@QAEIPAI@Z @f035b859bb77 @wf1601b6115c3
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_7 @ 0x00275ff0
unsigned int File_275ff0::vfunc_7(unsigned int* result) {
 Request_275ff0* memory = static_cast<Request_275ff0*>(FUN_00273560(0x10));
 void* request = 0;
 if (memory) request = memory->FUN_002754d0(this, result);
 return ((Drive_275ff0*)provider)->FUN_00272b60(request, (int)key, 0);
}

} // namespace fn_f81ff691

// 0x00276040 core::File::vfunc_9 (36 B): matches/0x00276040.cpp
// sym: ?vfunc_9@File@core@@UAEXHHH@Z
void core::File::vfunc_9(int a, int b, int c) {
    vfunc_3(a, b, c);
    vfunc_21();
}


// 0x00276070 core::File::vfunc_10 (36 B): matches/0x00276070.cpp
// sym: ?vfunc_10@File@core@@UAEXHHH@Z
void core::File::vfunc_10(int a, int b, int c) {
    vfunc_4(a, b, c);
    vfunc_21();
}


// 0x002760a0 core::File::vfunc_11 (26 B): matches/0x002760a0.cpp
// sym: ?vfunc_11@File@core@@UAEXH@Z
void core::File::vfunc_11(int p) {
    vfunc_5(p);
    vfunc_21();
}


// 0x002760c0 core::File::vfunc_12 (26 B): matches/0x002760c0.cpp
// sym: ?vfunc_12@File@core@@UAEXI@Z
void core::File::vfunc_12(unsigned int x) {
    vfunc_6(x);
    vfunc_21();
}


// 0x002760e0 core::File::vfunc_13 (26 B): matches/0x002760e0.cpp
// sym: ?vfunc_13@File@core@@UAEXH@Z
void core::File::vfunc_13(int p) {
    vfunc_7(p);
    vfunc_21();
}


// 0x00276100 core::File::vfunc_14 (16 B): matches/0x00276100.cpp
// sym: ?vfunc_14@File@core@@UAEXXZ
void core::File::vfunc_14() {
    vfunc_8();
    vfunc_21();
}


// 0x00276110 core::File::vfunc_15 (7 B): matches/0x00276110.cpp
// sym: ?vfunc_15@File@core@@UAEHXZ
int core::File::vfunc_15() {
    return this->f_128;
}

namespace fn_f81ff691 {

// 0x00276120 core::File::vfunc_17 (61 B): matches/0x00276120.cpp
// sym: ?vfunc_17@File_276120@fn_f81ff691@@QAEXXZ
// core::File::vfunc_17 (records.h CoreFile): a cancel request (0x00275570) queued at the front of the drive's queue
void File_276120::vfunc_17() {
    FileCancelRequest_276120* p = (FileCancelRequest_276120*)FUN_00273560(12);
    void* v = p ? p->FUN_00275570(this) : 0;
    ((Drive_276120*)provider)->FUN_00272b60(v, (int)key, 1);
}


// 0x00276160 core::File::vfunc_18 (85 B): equivalent/0x00276160.cpp
// sym: ?vfunc_18@File_276160@fn_f81ff691@@QAEXPAXI@Z @46e533f8acfd @w20dd5a773f79
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// core::File::vfunc_18 @ 0x00276160
void File_276160::vfunc_18(void* callback, unsigned int context) {
 FileCompletionRequest_276160* result = (FileCompletionRequest_276160*)FUN_00273560(24);
 void* value = 0;
 if (result) {
  value = result->FUN_00274ca0(FUN_0026dbb0(), this, callback, context);
 }
 ((Drive_276160*)provider)->FUN_00272b60(value, (int)key, 0);
}


// 0x002761c0 core::File::vfunc_19 (72 B): equivalent/0x002761c0.cpp
// sym: ?vfunc_19@File_2761c0@fn_f81ff691@@QAEXPAI@Z @521ff26c692a @w71bb2b74036b
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// core::File::vfunc_19 @ 0x002761c0
void File_2761c0::vfunc_19(hulk_uintptr* signal) {
    CompletionEventRequest_2761c0* value = (CompletionEventRequest_2761c0*)FUN_00273560(16);
    void* request = 0;
    if (value)
        request = value->FUN_00274ba0(signal, provider);
    ((Drive_2761c0*)provider)->FUN_00272b60(request, (int)key, 0);
}


// 0x00276210 core::File::vfunc_20 (36 B): matches/0x00276210.cpp
// sym: ?vfunc_20@File_276210@fn_f81ff691@@QAE_NXZ
bool File_276210::vfunc_20() {
    IMutable_276210* p = (IMutable_276210*)&vftableMutable;
    p->e();
    bool r = (field18 == 0);
    p->f();
    return r;
}

} // namespace fn_f81ff691

// 0x00276240 core::File::vfunc_21 (47 B): matches/0x00276240.cpp
// sym: ?vfunc_21@File@core@@UAEXXZ
void core::File::vfunc_21() {
    while (!vfunc_20()) {
        (*(X_276240 * *)&this->f_0c)->d();
        FUN_0026d6d0(0);
    }
}

namespace fn_f81ff691 {

// 0x00276270 core::File::vfunc_22 (29 B): matches/0x00276270.cpp
// sym: ?vfunc_22@File_276270@fn_f81ff691@@QAEHXZ
int File_276270::vfunc_22() {
    Sub_276270* p = (Sub_276270*)&vftableMutable;
    p->f0();
    int r = field14;
    p->f1();
    return r;
}

} // namespace fn_f81ff691

// 0x00276290 core::File::vfunc_23 (4 B): matches/0x00276290.cpp
// sym: ?vfunc_23@File@core@@UAE_NXZ
 // namespace core
bool core::File::vfunc_23() {
    return this->f_1c;
}

namespace fn_f81ff691 {

// 0x002762a0 core::File::vfunc_24 (24 B): matches/0x002762a0.cpp
// sym: ?access@File_2762a0@fn_f81ff691@@QAEPAXXZ
void* File_2762a0::access() {
    if (((core::Source*)provider)->f6() & 0x80)
        return 0;
    return this->filename;
}

} // namespace fn_f81ff691

// 0x002762c0 core::File::vfunc_25 (4 B): matches/0x002762c0.cpp
// sym: ?vfunc_25@File@core@@UAEPAXXZ
// the file's name (records.h CoreFile)
void* core::File::vfunc_25() {
    return ((CoreFile*)this)->filename;
}


// 0x002762d0 core::File::vfunc_26 (8 B): matches/0x002762d0.cpp
// sym: ?vfunc_26@File@core@@UAEXXZ
void core::File::vfunc_26() {
    (*(Inner_2762d0 * *)&this->f_0c)->f4();
}


// 0x002762e0 core::File::vfunc_27 (3 B): matches/0x002762e0.cpp
// sym: ?vfunc_27@File@core@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void core::File::vfunc_27(int a) {
    (void)a;
}

namespace fn_f81ff691 {

// 0x002762f0 core::File::vfunc_28 (4 B): matches/0x002762f0.cpp
// sym: ?FUN_002762f0@fn_f81ff691@@YIIPAUCoreFile@@@Z
// core::File (records.h CoreFile): its key
unsigned int __fastcall FUN_002762f0(Obj_2762f0* self) {
    return self->key;
}

} // namespace fn_f81ff691

// 0x00276300 core::File::vfunc_29 (7 B): matches/0x00276300.cpp
// sym: ?vfunc_29@File@core@@UAEEXZ
unsigned char core::File::vfunc_29() {
    return this->f_160;
}


// 0x00276310 core::File::vfunc_16 (7 B): matches/0x00276310.cpp
// sym: ?vfunc_16@File@core@@UAEIXZ
 // namespace core
unsigned int core::File::vfunc_16() {
    return this->f_164;
}


// 0x00276320 core::File::vfunc_30 (13 B): matches/0x00276320.cpp
// sym: ?vfunc_30@File@core@@UAEXI@Z
 // namespace core
void core::File::vfunc_30(unsigned int x) {
    this->f_120 = x;
}


// 0x00276330 core::File::vfunc_31 (7 B): matches/0x00276330.cpp
// sym: ?vfunc_31@File@core@@UAEIXZ
 // namespace core
unsigned int core::File::vfunc_31() {
    return this->f_15c;
}

namespace fn_f81ff691 {

// 0x00276340 FUN_00276340 (66 B): matches/0x00276340.cpp
// sym: _FUN_00276340
// Same code shape as 0x00274af0 (propagated; names are from that function)
extern "C" void FUN_00276340() {
    char a[4], b[4], c[4];
    FUN_0026d830(((char*)&DAT_0052a1e8));
    (*(Obj_276340**)&DAT_0052a204)->f14(a, b, c);
    (*(Obj_276340**)&DAT_0052a204)->f1();
    (*(Obj_276340**)&DAT_0052a204) = 0;
}

} // namespace fn_f81ff691

// 0x002763a0 FUN_002763a0 (247 B): equivalent/0x002763a0.cpp [wrapped: conflict: core::File; core::IMutable; core::SaveGameOpenRequest]
// sym: ??0File@core@fn_002763a0@@QAE@PAVIDevice_2763a0@12@PBDHHHHPAX@Z @a33a80c5b1a8 @w50bc7e6ec7ec
namespace fn_002763a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002763a0 @ 0x002763a0
// equiv-map: ??_7File@core@@6BIFileBase@1@@ = 0x0042bd3c
// equiv-map: ??_7File@core@@6BIMutable@1@@ = 0x0042bd30
namespace core {
class IFileBase {
  public:
    virtual void f0();
    virtual void f1();
};
class IMutable {
  public:
    virtual void m0() HULK_PURE64;
    virtual void m1() HULK_PURE64;
    int refCount;
};
class IDevice_2763a0 {
  public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
};
struct Counters {
    int w[11];
    void FUN_00277c00();
};
class SaveGameOpenRequest {
  public:
    SaveGameOpenRequest* FUN_00275060(void* file, int a, int b, int c, int d);
};
class File : public IFileBase, public IMutable {
  public:
    File(IDevice_2763a0* device, const char* name, int flag, int a4, int a5, int a6, void* userData);
    virtual void f0();
    virtual void f1();
    virtual void m0();
    virtual void m1();
    IDevice_2763a0* device;
    void* userData;
    int field_14;
    int field_18;
    char field_1c;
    char flag;
    char name[0x100];
    char nameEnd;
    char pad_11f;
    int field_120;
    int field_124;
    int field_128;
    Counters counters;
    char pad_158[8];
    char field_160;
    char pad_161[3];
    int field_164;
};
}
class DeviceHelper {
  public:
    void FUN_00272b60(core::SaveGameOpenRequest* req, void* userData, int zero);
};
const char* FUN_002705f0();
void* FUN_00273560(unsigned size);
int thunk_FUN_00271cf0(char* dst, const char* src, unsigned n);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
char* strncpy(char* dst, const char* src, unsigned n);
#endif


core::File::File(IDevice_2763a0* dev, const char* nm, int fl, int a4, int a5, int a6, void* ud) {
    refCount = 1;
    device = dev;
    userData = ud;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    flag = (char)fl;
    field_120 = 0;
    field_124 = 0;
    field_128 = 0;
    counters.FUN_00277c00();
    field_160 = 1;
    field_164 = 0x800;
    FUN_002705f0();
    device->d0();
    if (thunk_FUN_00271cf0(name, nm, 0x100) < 0) {
        strncpy(name, nm, 0x100);
        nameEnd = 0;
    }
    device->d6();
    SaveGameOpenRequest* req = (SaveGameOpenRequest*)FUN_00273560(0x1c);
    if (req != 0) {
        req = req->FUN_00275060(this, a4, fl, a5, a6);
    }
    ((DeviceHelper*)device)->FUN_00272b60(req, userData, 0);
}
} // namespace fn_002763a0

namespace fn_f81ff691 {

// 0x002764a0 FUN_002764a0 (48 B): matches/0x002764a0.cpp
// sym: ?shutdown@File@fn_f81ff691@@QAEXXZ
void File::shutdown() {
    *(void**)this = &hulk_at_0042bd3c;
    *((void**)this + 1) = &hulk_at_0042bd30;
    vfunc_21_00276240();
    r->y();
    sub.fin_00277c30();
    *(void**)this = &hulk_at_003f6098;
}

} // namespace fn_f81ff691

// 0x002764d0 FUN_002764d0 (242 B): equivalent/0x002764d0.cpp [wrapped: conflict: FUN_002705f0]
// sym: ??0File_2764d0@core@fn_002764d0@@QAE@PAUProvider_2764d0@2@PBDIIIIIIE@Z @89604874ffbf @w4290d9129b69
namespace fn_002764d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002764d0 @ 0x002764d0

// core::File's constructor (records.h CoreFile): the bases' vftables, then its own; a reference to the drive (slot
// 0), the name (0x00271cf0 normalizes it, else a plain copy), and with `open` set an open request (0x00274f20) queued
// on the drive (0x00272b60)
struct Provider_2764d0 {
 virtual void slot0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 int FUN_00272b60(void*, int, int);
};
struct Embedded_2764d0 { void FUN_00277c00(); };
extern "C" int* FUN_002705f0();
int __cdecl thunk_FUN_00271cf0(char*, const char*, int);
extern "C" char* __cdecl _strncpy(char*, const char*, unsigned);
void* __cdecl FUN_00273560(unsigned);
struct FileOpenRequest_2764d0 { void* FUN_00274f20(void*, int, unsigned char); };
extern "C" char DAT_0042b850[];
extern "C" char DAT_0042bd30[];
extern "C" char DAT_0042bd3c[];
namespace core {
struct File_2764d0 : CoreFile {
 File_2764d0(Provider_2764d0*,const char*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned char);
};
File_2764d0::File_2764d0(Provider_2764d0* p,const char* name,unsigned a3,unsigned a4,unsigned a5,unsigned a6,unsigned a7,unsigned a8,unsigned char a9) {
 vftableMutable=DAT_0042b850;
 vftable=DAT_0042bd3c; vftableMutable=DAT_0042bd30;
 refs=1; provider=p; key=a5; field14=0; field18=0; flag1c=0; flag1d=(unsigned char)a3;
 field120=0; field124=0; field128=0;
 ((Embedded_2764d0*)&view)->FUN_00277c00();
 field160=0; field164=0x800;
 FUN_002705f0();
 ((Provider_2764d0*)provider)->slot0();
 if(thunk_FUN_00271cf0(filename,name,0x100)<0) { _strncpy(filename,name,0x100); filename[0x100]=0; }
 ((Provider_2764d0*)provider)->slot6();
 if(a9) {
 FileOpenRequest_2764d0* h=(FileOpenRequest_2764d0*)FUN_00273560(0x14);
 void* result=0;
 if(h) result=h->FUN_00274f20(this,(int)a4,(unsigned char)a3);
 ((Provider_2764d0*)provider)->FUN_00272b60(result,(int)key,0);
 }
}
}
} // namespace fn_002764d0

namespace fn_f81ff691 {

// 0x002765d0 core::File::vfunc_2 (97 B): matches/0x002765d0.cpp
// sym: ?Fn@File_2765d0@fn_f81ff691@@QAEPAU12@E@Z
// data: gLock_2765d0 = DAT_0052a1e8
File_2765d0* File_2765d0::Fn(unsigned char f) {
    vftable = DAT_0042bd3c;
    vftableMutable = DAT_0042bd30;
    FUN_00276240();
    ((Obj_2765d0*)provider)->Rel();
    ((Sub_2765d0*)&view)->FUN_00277c30();
    vftable = DAT_003f6098;
    if (f & 1) {
        FUN_0026d850(((char*)&DAT_0052a1e8));
        (*(Mgr_2765d0**)&DAT_0052a204)->Free(this);
        FUN_0026d840(((char*)&DAT_0052a1e8));
    }
    return this;
}

} // namespace fn_f81ff691

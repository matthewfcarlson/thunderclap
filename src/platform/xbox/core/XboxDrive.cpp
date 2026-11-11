// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026f070..0x0026fd50 (kind game, layer platform/xbox, confidence high), dominant class core::XboxDrive
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f4379f43 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4379f43 {} using namespace fn_f4379f43;
#include "platform/xbox/core.h"

// ---- declarations shared by the functions below
namespace fn_f4379f43 {
struct Platform {
    virtual ~Platform();
};
extern Platform platformObject;
extern "C" int* FUN_002705f0();
class X_26f130 {
  public:
    virtual void f();
    virtual void g();
    int n;
};
class Drive_26f130 {
  public:
    virtual void vfunc_0();
    const void* vftableObject;
    int heap;
    X_26f130 x;
};
class Helper_26f150 {
  public:
    void FUN_0026f160();
};
class X_26f160 {
  public:
    virtual void First();
    virtual void Second();
    virtual void Third(int);
    int count;
    void f();
};
extern "C" int __stdcall FUN_0020bbc2(void*);
extern "C" void __cdecl FUN_002697c0(const char*, char*, int, char**, int);
} // namespace fn_f4379f43
namespace core {
struct XboxDrive_26f210 : CoreXboxDrive {
    void vfunc_21(const char* source);
};
}
namespace fn_f4379f43 {
extern void __stdcall FUN_00208b9c(char *, unsigned int *, unsigned char *, unsigned char *);
extern unsigned int __stdcall FUN_00209a8e(char *);
struct XboxDrive_26f290 : CoreXboxDrive {
    void FUN_0026f290();
};
} // namespace fn_f4379f43
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f4379f43 {
struct XboxDrive_26f330 : CoreXboxDrive {
    void FUN_0026f330(const char* name, char* result, int capacity);
};
struct XboxDrive_26f3e0 { unsigned int FUN_0026f3e0(unsigned int code); };
extern "C++" __declspec(nothrow) int __stdcall FUN_0020bbc2(hulk_uintptr);
typedef unsigned char u8_26f760;
class XboxDrive_26f760 {
  public:
    void FUN_0026f0b0();
    virtual void f0();
    virtual void f1();
    virtual XboxDrive_26f760* f2(u8_26f760);
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
};
class Drive_26f790 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f7();
};
class XboxDrive_26f790 : public Drive_26f790 {
  public:
    void FUN_0026f290();
    virtual int f7();
};
unsigned long __stdcall FUN_002101d4(void*, unsigned long, unsigned long, unsigned long);
void __stdcall FUN_00210150(void*);
int __stdcall FUN_0021007a(void*, void*, unsigned long, void*, unsigned long);
unsigned long __stdcall FUN_002109b6(void*, unsigned long);
} // namespace fn_f4379f43
namespace core {
struct XboxDrive_26f990 : CoreXboxDrive {
 int vfunc_13(void*, unsigned long, unsigned long, unsigned long, void*, unsigned long, void*, unsigned long*, unsigned long);
 unsigned int FUN_0026f3e0(unsigned int);
};
}
namespace core {
struct XboxDrive_26fa40 : CoreXboxDrive { void FUN_0026f330(const char*, char*, int); int FUN_0026f4b0(const char*, char*, int*); int vfunc_18(const char* name, const char* path, int* handle, bool keep); };
}
namespace fn_f4379f43 {
void __stdcall FUN_0020bbc2(int);
int __stdcall FUN_00355ab5(const char*, char*);
} // namespace fn_f4379f43
namespace core {
class Drive_26fad0 : public CoreDrive {
  public:
    int vfunc_19(int* a, int b);
    int FUN_0026f4b0(void* result, void* entry, int* handle);
};
}
namespace fn_f4379f43 {
extern "C" int __stdcall FUN_00355bc2(int a, int* b);
class XboxDrive_26fc40 : public CoreXboxDrive {
  public:
    int vfunc_17(const char*);
    void FUN_0026f330(const char*, char*, int);
    unsigned int FUN_0026f3e0(unsigned int);
};
extern int __stdcall FUN_0021257d(char*);
extern unsigned int __stdcall GetLastError();
class XboxDrive_26fcb0 : public CoreXboxDrive {
  public:
    int vfunc_14();
    unsigned int FUN_0026f3e0(unsigned int);
};
extern int XFormatUtilityDrive();
extern "C" void* FUN_00266e00(int a, int b);
struct XboxDrive_nv_26fcf0 {
    core::XboxDrive* FUN_0026f570(const char* name, int heap);
};
struct DriveSlots_26fcf0 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual int s21(char*);
};


// 0x0026f070 FUN_0026f070 (42 B): matches/0x0026f070.cpp
// sym: _FUN_0026f070
// data: gPlatform = DAT_005283b4, gPlatformRef = DAT_005283c8, gReady = DAT_005283bc
extern "C" void FUN_0026f070() {
    (*(Platform**)&DAT_005283b4) = &platformObject;
    (*(Platform***)&DAT_005283c8) = ((Platform**)&DAT_005283b4);
    FUN_002705f0();
    thunk_FUN_003eac33(0, 0);
    (*(unsigned char*)&DAT_005283bc) = 1;
}

} // namespace fn_f4379f43

// 0x0026f0b0 FUN_0026f0b0 (113 B): equivalent/0x0026f0b0.cpp [wrapped: conflict: core::XboxDrive]
// sym: ??1XboxDrive@core@fn_0026f0b0@@QAE@XZ @a303bb2f51e4 @wf5cf1fb059e8
namespace fn_0026f0b0 {
// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 3/4, incomplete)
// FUN_0026f0b0 @ 0x0026f0b0

namespace core {
struct A_26f0b0 { virtual void a(); };
struct B_26f0b0 { virtual void b(); char pad[4]; };
struct C_26f0b0 { virtual void c(); };
struct Device_26f0b0 { virtual void f0(); virtual void f1(); char pad[12]; int status; };
class XboxDrive : public A_26f0b0, public B_26f0b0, public C_26f0b0 {
public:
 char padding[0xa8];
 Device_26f0b0 *device;
 char middle[8];
 char path[0x11c];
 void *handle;
 virtual void driveMethod();
 void FUN_00272840();
 ~XboxDrive();
};
}
extern "C" void __cdecl FUN_0026d830(void *);
core::XboxDrive::~XboxDrive() {
 if (device->status == 1) {
  device->f1();
  FUN_0026d830(handle);
  if (path[0]=='D' && path[1]==':' && path[2]==0) (*(hulk_intptr*)&DAT_00528408)=0;
  else (*(hulk_intptr*)&DAT_0052840c)=0;
 }
 FUN_00272840();
}
} // namespace fn_0026f0b0

namespace fn_f4379f43 {

// 0x0026f130 core::Drive::vfunc_0 (26 B): matches/0x0026f130.cpp
// sym: ?vfunc_0@Drive_26f130@fn_f4379f43@@UAEXXZ
void Drive_26f130::vfunc_0() {
    X_26f130* p = &x;
    p->f();
    ++p->n;
    p->g();
}

} // namespace fn_f4379f43

// 0x0026f150 core::Drive::vfunc_1 (8 B): matches/0x0026f150.cpp
// sym: ?vfunc_1@Drive@core@@UAEXXZ
// Same code shape as 0x0023c920 (propagated; names are from that function)
// core::SafeRefCount's release (0x0026f160) on the drive's IMutable base (+0xc; records.h CoreDrive)
void core::Drive::vfunc_1() {
    ((Helper_26f150*)&((CoreDrive*)this)->vftableMutable)->FUN_0026f160();
}

namespace fn_f4379f43 {

// 0x0026f160 FUN_0026f160 (45 B): matches/0x0026f160.cpp
// sym: ?f@X_26f160@fn_f4379f43@@QAEXXZ
void X_26f160::f() {
    First();
    if (--count == 0) {
        count = 0x5dc;
        Second();
        Third(1);
    } else
        Second();
}

} // namespace fn_f4379f43

// 0x0026f190 core::XboxDrive::vfunc_0_adjc (14 B): matches/0x0026f190.cpp [wrapped: conflict: core::XboxDrive]
// sym: ?vfunc_0_adjc@XboxDrive@core@fn_0026f190@@QAEXXZ
namespace fn_0026f190 {

namespace core {
// core::XboxDrive's IMutable base (+0xc of records.h CoreXboxDrive): enters the device's critical section
class XboxDrive {
  public:
    void vfunc_0_adjc();
};
} // namespace core
extern "C" void __cdecl FUN_0026d850(void*);
void core::XboxDrive::vfunc_0_adjc() {
    CoreXboxDrive* drive = (CoreXboxDrive*)((char*)this - (hulk_uintptr)&((CoreXboxDrive*)0)->drive.vftableMutable);
    FUN_0026d850(drive->lock);
}
} // namespace fn_0026f190


// 0x0026f1a0 core::XboxDrive::vfunc_1_adjc (14 B): matches/0x0026f1a0.cpp [wrapped: conflict: core::XboxDrive]
// sym: ?vfunc_0_adjc@XboxDrive@core@fn_0026f1a0@@QAEXXZ
namespace fn_0026f1a0 {

namespace core {
// core::XboxDrive's IMutable base (+0xc of records.h CoreXboxDrive): leaves the device's critical section
class XboxDrive {
  public:
    void vfunc_0_adjc();
};
} // namespace core
extern "C" void __cdecl FUN_0026d840(void*);
void core::XboxDrive::vfunc_0_adjc() {
    CoreXboxDrive* drive = (CoreXboxDrive*)((char*)this - (hulk_uintptr)&((CoreXboxDrive*)0)->drive.vftableMutable);
    FUN_0026d840(drive->lock);
}
} // namespace fn_0026f1a0


// 0x0026f1b0 core::XboxDrive::vfunc_6 (7 B): matches/0x0026f1b0.cpp
// sym: ?vfunc_6@XboxDrive@core@@UAEIXZ
// the drive's type (records.h CoreXboxDrive)
unsigned int core::XboxDrive::vfunc_6() {
    return ((CoreXboxDrive*)this)->type;
}


// 0x0026f1c0 core::XboxDrive::vfunc_4 (7 B): matches/0x0026f1c0.cpp
// sym: ?vfunc_4@XboxDrive@core@@UAEPAXXZ
// the drive's name (records.h CoreXboxDrive)
void* core::XboxDrive::vfunc_4() {
    return ((CoreXboxDrive*)this)->name;
}


// 0x0026f1d0 core::XboxDrive::vfunc_10 (28 B): matches/0x0026f1d0.cpp
// sym: ?vfunc_10@XboxDrive@core@@UAEHPAXH@Z
// CloseHandle (the XDK row 0x0020bbc2)
// closes a file of the drive (records.h CoreXboxDrive: its count of open files)
int core::XboxDrive::vfunc_10(void* __p0, int q) { void * p = (void *)__p0;

    FUN_0020bbc2(p);
    --((CoreXboxDrive*)this)->openFiles;
    return 1;
}


// 0x0026f210 core::XboxDrive::vfunc_21 (126 B): equivalent/0x0026f210.cpp
// sym: ?vfunc_21@XboxDrive_26f210@core@@QAEXPBD@Z @9f736051c2b8 @wa32c10f57378
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 7/8, incomplete)
// core::XboxDrive::vfunc_21 @ 0x0026f210
namespace core {
void XboxDrive_26f210::vfunc_21(const char* source) {
    if (source && *source) {
        FUN_002697c0(source, pathBuffer, 0, &path, 0);
        char* p = path;
        unsigned int length = 0;
        while (p[length]) ++length;
        pathLength = length;
        if (p[length] != '\\') {
            p[length] = '\\';
            path[pathLength + 1] = 0;
            ++pathLength;
        }
    } else {
        path = 0;
        pathLength = 0;
    }
}
}

namespace fn_f4379f43 {

// 0x0026f290 FUN_0026f290 (157 B): equivalent/0x0026f290.cpp
// sym: ?FUN_0026f290@XboxDrive_26f290@fn_f4379f43@@QAEXXZ @df9b4ce1ff0a @w1af2be66d4f8
// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 8/8)
// FUN_0026f290 @ 0x0026f290
void XboxDrive_26f290::FUN_0026f290()
{
    struct Locals {
        char path[4];
        unsigned int foundSize;
        unsigned int error;
        unsigned char first[8];
        unsigned char second[8];
    } local;
    char *out = local.path;
    const char *in = name;
    char c;
    do {
        c = *in++;
        *out++ = c;
    } while (c);
    out[-1] = (char)(*(unsigned short*)&DAT_0042ab54);
    out[0] = (char)((*(unsigned short*)&DAT_0042ab54) >> 8);
    FUN_00208b9c(local.path, &local.foundSize, local.second, local.first);
    if (local.error)
        drive.size = 0xffffffff;
    else
        drive.size = local.foundSize;
    unsigned int n = FUN_00209a8e(local.path);
    drive.sectorSize = n ? n : 0x200;
    drive.count = drive.size / drive.sectorSize;
}


// 0x0026f330 FUN_0026f330 (164 B): equivalent/0x0026f330.cpp
// sym: ?FUN_0026f330@XboxDrive_26f330@fn_f4379f43@@QAEXPBDPADH@Z @f397c8f1ca10 @wbbfa10553aa2
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_0026f330 @ 0x0026f330
void XboxDrive_26f330::FUN_0026f330(const char* name, char* result, int capacity)
{
    int directoryLength = 0;
    while (this->name[directoryLength] != '\0') ++directoryLength;
    int position = directoryLength + 1;
    strncpy(result, this->name, capacity - 1);
    strncpy(result + directoryLength, "\\", capacity - position);
    if (path) {
        strncpy(result + position, path, capacity - position - 1);
        position += pathLength;
    }
    if (*name == '\\') ++name;
    strncpy(result + position, name, capacity - position - 1);
    result[capacity - 1] = '\0';
}


// 0x0026f3e0 FUN_0026f3e0 (158 B): equivalent/0x0026f3e0.cpp
// sym: ?FUN_0026f3e0@XboxDrive_26f3e0@fn_f4379f43@@QAEII@Z @d16b41a1bcc1 @w34486dd75b98
// STATUS: equivalent (tools/equiv.py level 3: 20038 inputs, branch coverage 26/26)
// FUN_0026f3e0 @ 0x0026f3e0
// core::XboxDrive: an XAPI error code as the drive's error (the callers pass the drive; it is not read)
unsigned int XboxDrive_26f3e0::FUN_0026f3e0(unsigned int code)
{
    (*(unsigned int*)&DAT_00528404) = 0;
    if (code <= 17) {
        switch (code) {
        case 0: return 0;
        case 2: case 3: case 15: return 1;
        case 11: return 5;
        case 14: return 8;
        case 17: return 3;
        default: (*(unsigned int*)&DAT_00528404) = code; return 8;
        }
    }
    switch (code) {
    case 21: return 2;
    case 26: return 11;
    case 27: return 5;
    case 34: return 3;
    case 112: return 7;
    case 1005: return 6;
    case 1167: return 4;
    default: (*(unsigned int*)&DAT_00528404) = code; return 8;
    }
}

} // namespace fn_f4379f43

// 0x0026f4b0 FUN_0026f4b0 (114 B): equivalent/0x0026f4b0.cpp [wrapped: conflict: GetLastError]
// sym: ?FUN_0026f4b0@XboxDrive_26f4b0@fn_0026f4b0@@QAEHPAUResult_26f4b0@2@PAUEntry_26f4b0@2@PAH@Z @558f63b44f5a @wafad8d7a30f1
namespace fn_0026f4b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 6/6)
// FUN_0026f4b0 @ 0x0026f4b0
extern "C++" __declspec(nothrow) hulk_intptr __stdcall GetLastError();
extern "C" char * __cdecl _strncpy(char *, const char *, unsigned int);
struct Result_26f4b0 { int status; char name[257]; };
struct Entry_26f4b0 { unsigned char flags; char pad[43]; char name[256]; };
struct XboxDrive_26f4b0 {
    unsigned int FUN_0026f3e0(unsigned int error);
    int FUN_0026f4b0(Result_26f4b0 *result, Entry_26f4b0 *entry, int *handle);
};
int XboxDrive_26f4b0::FUN_0026f4b0(Result_26f4b0 *result, Entry_26f4b0 *entry, int *handle)
{
    if (*handle == -1) {
        hulk_intptr error = GetLastError();
        if (error != 18 && error != 2)
            return FUN_0026f3e0((unsigned int)error);
        result->name[0] = 0;
        result->status = 2;
        return 0;
    }
    _strncpy(result->name, entry->name, 256);
    result->name[256] = 0;
    result->status = (entry->flags >> 4) & 1;
    return 0;
}
} // namespace fn_0026f4b0


// 0x0026f530 core::XboxDrive::vfunc_0_adj4 (8 B): matches/0x0026f530.cpp [wrapped: macros]
// sym: ?vfunc_2@XboxDrive@fn_0026f530@@W3AEXH@Z
namespace fn_0026f530 {
#if !defined(HULK_PTR64)
class Drive {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
};

class IRefCount {
  public:
    virtual void vfunc_2(int);
};

class XboxDrive : public Drive, public IRefCount {
  public:
    void vfunc_2(int);
};


XboxDrive g_xbox;
#else
// The 64-bit builds: the code above is a compiler-generated adjustor thunk of an invented class (`this - 4`, then
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxDrive's
// BaseObject slot 2 takes the BaseObject sub-object, steps back to the drive by that base's offset in records.h CoreDrive,
// and runs the deleting destructor 0x0026f760 (named by its address, so the native link binds it). The function is
// named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name (as 0x002786f0).
struct Target_26f530 {
    void* FUN_0026f760(unsigned char flags);
};
struct Thunk_26f530 {
    void* FUN_0026f530(unsigned char flags);
};
void* Thunk_26f530::FUN_0026f530(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreDrive*)0)->vftableObject;
    return ((Target_26f530*)drive)->FUN_0026f760(flags);
}
#endif
} // namespace fn_0026f530


// 0x0026f540 core::XboxDrive::vfunc_2_adjc (8 B): matches/0x0026f540.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ?v2@XboxDrive@fn_0026f540@@WM@AEXH@Z
namespace fn_0026f540 {
#if !defined(HULK_PTR64)
class Drive {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    int a;
    int b;
};

class IBase {
  public:
    virtual void w0();
    virtual void w1();
    virtual void v2(int);
};

class XboxDrive : public Drive, public IBase {
  public:
    XboxDrive() {}
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
};

XboxDrive* MakeXboxDrive() {
    return new XboxDrive();
}
#else
// The 64-bit builds: the code above is a compiler-generated adjustor thunk of an invented class (`this - 0xc`, then
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxDrive's
// IMutable slot 2 takes the IMutable sub-object, steps back to the drive by that base's offset in records.h CoreDrive,
// and runs the deleting destructor 0x0026f760 (named by its address, so the native link binds it). The function is
// named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name (as 0x002786f0).
struct Target_26f540 {
    void* FUN_0026f760(unsigned char flags);
};
struct Thunk_26f540 {
    void* FUN_0026f540(unsigned char flags);
};
void* Thunk_26f540::FUN_0026f540(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreDrive*)0)->vftableMutable;
    return ((Target_26f540*)drive)->FUN_0026f760(flags);
}
#endif
} // namespace fn_0026f540


// 0x0026f550 core::XboxDrive::vfunc_20 (28 B): matches/0x0026f550.cpp
// sym: ?vfunc_20@XboxDrive@core@@UAEHH@Z
// CloseHandle (the XDK row 0x0020bbc2); the find handle is pointer-sized on the 64-bit builds
int core::XboxDrive::vfunc_20(hulk_intptr __p0) { hulk_uintptr * p = (hulk_uintptr *)__p0;

    FUN_0020bbc2(*p);
    *p = (hulk_uintptr)-1;
    return (int)(1);
}


// 0x0026f570 FUN_0026f570 (495 B): equivalent/0x0026f570.cpp [wrapped: conflict: FUN_002705f0]
// sym: ??0XboxDrive_26f570@core@fn_0026f570@@QAE@PBDH@Z @bb1c1547697c @w5ea4e169a678
namespace fn_0026f570 {
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 14/14)
// FUN_0026f570 @ 0x0026f570

extern "C++" __declspec(nothrow) void __cdecl FUN_002705f0();
extern "C" void __cdecl FUN_0026d820(void*);
// core::DriveThread (0x002733c0 constructs it: the device's lock, the heap id; slot 0 adds a reference)
struct DriveThread_26f570 { virtual void retain(); DriveThread_26f570* FUN_002733c0(hulk_uintptr, hulk_uintptr); };
extern "C" void* __cdecl FUN_00266e00(int, int);
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned);
extern "C" char DAT_00445644[];
extern "C" char DAT_0042b52c[];
extern "C" char DAT_0042b524[];
extern "C" char DAT_0042b514[];
// core::Drive's constructor (0x00272d00), named by its address, on core::XboxDrive's layout (records.h CoreXboxDrive)
struct FUN_00272d00 : CoreXboxDrive { FUN_00272d00(); };
namespace core { struct XboxDrive_26f570 : FUN_00272d00 { XboxDrive_26f570(const char*, int); }; }
core::XboxDrive_26f570::XboxDrive_26f570(const char* nameArg, int heap) {
 HULK_SIZE32(CoreDriveThread, 0x94);
 drive.vftable=DAT_0042b52c; drive.vftableObject=DAT_0042b524; drive.vftableMutable=DAT_0042b514;
 openFiles=0; path=0; pathLength=0; FUN_002705f0();
 if(nameArg[0]=='D' && nameArg[1]==':' && nameArg[2]==0) {
  type=0x22; drive.label.text=DAT_00445644;
  if(!(*(DriveThread_26f570**)&DAT_00528408)) {
   FUN_0026d820(((char*)&DAT_005283e8)); DAT_004cdbb0=heap;
   DriveThread_26f570* p=(DriveThread_26f570*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
   (*(DriveThread_26f570**)&DAT_00528408)=p ? p->FUN_002733c0((hulk_uintptr)&DAT_005283e8,(hulk_uintptr)(hulk_intptr)heap) : 0;
   lock=((char*)&DAT_005283e8); drive.driveThread=(*(DriveThread_26f570**)&DAT_00528408);
  } else { lock=((char*)&DAT_005283e8); drive.driveThread=(*(DriveThread_26f570**)&DAT_00528408); ((DriveThread_26f570*)drive.driveThread)->retain(); }
 } else {
  type=0x33;
  if(nameArg[0]=='Z' && nameArg[1]==':' && nameArg[2]==0) type=0x3b;
  else if(nameArg[0]=='W' && nameArg[1]==':' && nameArg[2]==0) type=0x20;
  const char* title="Xbox Hard Disk";
  for(int i=0;i<15;++i) drive.label.buffer[i]=title[i];
  if(!(*(DriveThread_26f570**)&DAT_0052840c)) {
   FUN_0026d820(((char*)&DAT_005283cc)); DAT_004cdbb0=heap;
   DriveThread_26f570* p=(DriveThread_26f570*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
   (*(DriveThread_26f570**)&DAT_0052840c)=p ? p->FUN_002733c0((hulk_uintptr)&DAT_005283cc,(hulk_uintptr)(hulk_intptr)heap) : 0;
   lock=((char*)&DAT_005283cc); drive.driveThread=(*(DriveThread_26f570**)&DAT_0052840c);
  } else { lock=((char*)&DAT_005283cc); drive.driveThread=(*(DriveThread_26f570**)&DAT_0052840c); ((DriveThread_26f570*)drive.driveThread)->retain(); }
 }
 drive.result=0; _strncpy(name,nameArg,16); name[16]=0;
}
} // namespace fn_0026f570

namespace fn_f4379f43 {

// 0x0026f760 core::XboxDrive::vfunc_2 (36 B): matches/0x0026f760.cpp
// sym: ?f2@XboxDrive_26f760@fn_f4379f43@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
XboxDrive_26f760* XboxDrive_26f760::f2(u8_26f760 flag) {
    FUN_0026f0b0();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}


// 0x0026f790 core::XboxDrive::vfunc_7 (25 B): matches/0x0026f790.cpp
// sym: ?f7@XboxDrive_26f790@fn_f4379f43@@UAEHXZ
int XboxDrive_26f790::f7() {
    FUN_0026f290();
    ((CoreXboxDrive*)this)->drive.error = 0;
    return 1;
}

} // namespace fn_f4379f43

// 0x0026f7b0 core::XboxDrive::vfunc_8 (356 B): equivalent/0x0026f7b0.cpp [wrapped: conflict: GetLastError]
// sym: ?vfunc_8@XboxDrive_26f7b0@core@fn_0026f7b0@@QAEHPBDHEPAH1@Z @8c20f7a83de5 @we280a5d72a2e
namespace fn_0026f7b0 {
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 11/14, incomplete)
// core::XboxDrive::vfunc_8 @ 0x0026f7b0
extern "C" int __cdecl _strncmp(const char *, const char *, unsigned int);
extern "C" int __cdecl FUN_00345804(const char *, const char *, unsigned int *, unsigned int *);
extern "C" int __stdcall FUN_00355791(unsigned int, unsigned int, int *, int *, int, int);
extern "C" int __stdcall FUN_003559b9(int, int);
extern "C" int __stdcall FUN_002109f1(const char *, unsigned int, unsigned int, int, unsigned int, int, int);
extern "C++" __declspec(nothrow) int __stdcall FUN_002109b6(int, int);
namespace XAPILIB { extern "C++" __declspec(nothrow) hulk_uintptr __stdcall GetLastError(); }
namespace core {
// core::XboxDrive::vfunc_8 (records.h CoreXboxDrive): opens a file of the drive; the handles are the file shim's
// small indices
struct XboxDrive_26f7b0 : CoreXboxDrive {
 void FUN_0026f330(const char *, char *, unsigned int);
 unsigned int FUN_0026f3e0(unsigned int);
 int vfunc_8(const char *path, int mode, unsigned char write, int *handle, int *result);
};
int XboxDrive_26f7b0::vfunc_8(const char *path, int mode, unsigned char write, int *handle, int *result) {
 char buffer[257];
 unsigned int first, second;
 int local0, localc;
 FUN_0026f330(path, buffer, 257);
 int h;
 if (_strncmp(buffer, "W:", 2) == 0) {
  if (FUN_00345804(buffer, "W:\\%u\\%u", &first, &second) != 2) { drive.error = 1; return 0; }
  h = FUN_00355791(first, second, &local0, &localc, 0, 0);
  h = FUN_003559b9(local0, 0);
 } else {
  int disposition;
  if (mode == 0) disposition = 3;
  else if (mode == 1) disposition = 4;
  else if (mode == 3) disposition = 2;
  else disposition = localc;
  h = FUN_002109f1(buffer, write ? 0xc0000000 : 0x80000000, write ? 3 : 1, 0, disposition, 0x80, 0);
 }
 *handle = h;
 if (h != -1) {
  ++openFiles;
  *result = FUN_002109b6(h, 0);
  drive.error = 0;
  return 1;
 }
 drive.error = FUN_0026f3e0((unsigned int)XAPILIB::GetLastError());
 return 0;
}
}
} // namespace fn_0026f7b0


// 0x0026f920 core::XboxDrive::vfunc_12 (108 B): matches/0x0026f920.cpp [wrapped: conflict: GetLastError]
// sym: ?Run@XboxDrive_26f920@fn_0026f920@@QAEIIIIIPAXIPAII@Z
namespace fn_0026f920 {
typedef unsigned int U_26f920;
U_26f920 __stdcall FUN_002101d4(U_26f920, U_26f920, U_26f920, U_26f920);
U_26f920 __stdcall FUN_0020ff8d(U_26f920, void*, U_26f920, hulk_uintptr, U_26f920);
U_26f920 __stdcall GetLastError();
// core::XboxDrive::vfunc_12 (records.h CoreXboxDrive): seeks the handle (p2) to p5 and reads p7 bytes into the buffer
// p6 (a pointer on every target); 0x0026f3e0 converts the XAPI error into the drive's
class XboxDrive_26f920 : public CoreXboxDrive {
  public:
    U_26f920 FUN_0026f3e0(U_26f920);
    U_26f920 Run(U_26f920, U_26f920, U_26f920, U_26f920, void*, U_26f920, U_26f920*, U_26f920);
};
U_26f920 XboxDrive_26f920::Run(U_26f920 p2, U_26f920 p3, U_26f920 p4, U_26f920 p5, void* p6, U_26f920 p7, U_26f920* p8, U_26f920 unused) {
    U_26f920 r = FUN_002101d4(p2, p5, 0, 0);
    if (r == p5)
        if (FUN_0020ff8d(p2, p6, p7, (hulk_uintptr)p8, 0)) {
            *p8 = p7;
            drive.error = 0;
            return 1;
        }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}
} // namespace fn_0026f920


// 0x0026f990 core::XboxDrive::vfunc_13 (173 B): equivalent/0x0026f990.cpp
// sym: ?vfunc_13@XboxDrive_26f990@core@@QAEHPAXKKK0K0PAKK@Z @43d2d667e302 @wed6fc8538252
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 8/8)
// core::XboxDrive::vfunc_13 @ 0x0026f990
// core::XboxDrive::vfunc_13 @ 0x0026f990
namespace core {
int XboxDrive_26f990::vfunc_13(void* handle, unsigned long a2, unsigned long a3, unsigned long offset, void* buffer, unsigned long count, void* output, unsigned long* position, unsigned long a9) {
 if (!(*(unsigned char*)&type & 1)) return 0;
 if (offset + count > *position) {
 FUN_002101d4(handle, offset + count, 0, 0);
 FUN_00210150(handle);
 }
 if (FUN_002101d4(handle, offset, 0, 0) == offset && FUN_0021007a(handle, buffer, count, output, 0)) {
 *position = FUN_002109b6(handle, 0);
 drive.error = 0;
 return 1;
 }
 drive.error = FUN_0026f3e0(XAPILIB::GetLastError());
 return 0;
}
}


// 0x0026fa40 core::XboxDrive::vfunc_18 (136 B): equivalent/0x0026fa40.cpp
// sym: ?vfunc_18@XboxDrive_26fa40@core@@QAEHPBD0PAH_N@Z @27268b5a1a99 @wb94367f159cc
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 6/6)
// core::XboxDrive::vfunc_18 @ 0x0026fa40
// core::XboxDrive::vfunc_18 (records.h CoreXboxDrive): finds the first file of a directory
int core::XboxDrive_26fa40::vfunc_18(const char* name, const char* path, int* handle, bool keep) {
 char first[257]; char second[256];
 FUN_0026f330(name, first, 257);
 if (!keep && *handle != -1) FUN_0020bbc2(*handle);
 int value = FUN_00355ab5(first, second);
 *handle = value;
 int result = FUN_0026f4b0(path, second, handle);
 drive.error = result;
 return result == 0;
}


// 0x0026fad0 core::XboxDrive::vfunc_19 (141 B): matches/0x0026fad0.cpp
// sym: ?vfunc_19@Drive_26fad0@core@@QAEHPAHH@Z
int core::Drive_26fad0::vfunc_19(int* a, int b) {
    int t;
    char buf[0x140];
    int v = *a;
    if (v == -1) {
        error = 1;
        return 0;
    }
    if (FUN_00355bc2(v, (int*)buf) == 0) {
        t = -1;
        error = FUN_0026f4b0((void*)(hulk_intptr)b, buf, &t);
    } else {
        error = FUN_0026f4b0((void*)(hulk_intptr)b, buf, a);
    }
    return error == 0;
}


// 0x0026fb60 core::XboxDrive::vfunc_15 (106 B): matches/0x0026fb60.cpp [wrapped: conflict: GetLastError]
// sym: ?vfunc_15@XboxDrive_26fb60@core@fn_0026fb60@@QAEHPBD@Z
namespace fn_0026fb60 {

extern "C++" __declspec(nothrow) __stdcall unsigned long GetLastError();
int __stdcall FUN_00355c13(char* path, int flag);

namespace core {
// core::XboxDrive::vfunc_15 (records.h CoreXboxDrive): creates a directory (0x0026f330 makes the device path,
// 0x0026f3e0 converts the XAPI error)
class XboxDrive_26fb60 : public CoreXboxDrive {
  public:
    int vfunc_15(const char* p);
    void FUN_0026f330(const char* p, char* out, int n);
    unsigned int FUN_0026f3e0(unsigned int e);
};
int XboxDrive_26fb60::vfunc_15(const char* p) {
    char buf[0x101];
    FUN_0026f330(p, buf, 0x101);
    if (FUN_00355c13(buf, 0)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}
} // namespace core
} // namespace fn_0026fb60


// 0x0026fbd0 core::XboxDrive::vfunc_16 (104 B): matches/0x0026fbd0.cpp [wrapped: conflict: GetLastError]
// sym: ?v16@XboxDrive_26fbd0@fn_0026fbd0@@QAEHPBD@Z
namespace fn_0026fbd0 {
// core::XboxDrive::vfunc_16 (records.h CoreXboxDrive): checks a path (0x0026f330 makes the device path, 0x0026f3e0
// converts the XAPI error)
class XboxDrive_26fbd0 : public CoreXboxDrive {
  public:
    int v16(const char*);
    void FUN_0026f330(const char*, char*, int);
    unsigned int FUN_0026f3e0(unsigned int);
};
extern "C" int __stdcall FUN_00355c7f(const char*);
extern "C++" __declspec(nothrow) hulk_ulongptr __stdcall GetLastError();
int XboxDrive_26fbd0::v16(const char* path) {
    char buf[0x101];
    FUN_0026f330(path, buf, 0x101);
    if (FUN_00355c7f(buf)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0((unsigned int)GetLastError());
    return 0;
}
} // namespace fn_0026fbd0

namespace fn_f4379f43 {

// 0x0026fc40 core::XboxDrive::vfunc_17 (104 B): matches/0x0026fc40.cpp
// sym: ?vfunc_17@XboxDrive_26fc40@fn_f4379f43@@QAEHPBD@Z
// core::XboxDrive::vfunc_17 (records.h CoreXboxDrive): opens a directory (0x0026f330 makes the device path,
// 0x0026f3e0 converts the XAPI error)
int XboxDrive_26fc40::vfunc_17(const char* path) {
    char buf[0x101];
    FUN_0026f330(path, buf, 0x101);
    if (FUN_0021257d(buf)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}


// 0x0026fcb0 core::XboxDrive::vfunc_14 (57 B): matches/0x0026fcb0.cpp
// sym: ?vfunc_14@XboxDrive_26fcb0@fn_f4379f43@@QAEHXZ
// core::XboxDrive::vfunc_14 (records.h CoreXboxDrive): formats the utility drive when bit 3 of its type word says
// it is one; 0x0026f3e0 converts the XAPI error
int XboxDrive_26fcb0::vfunc_14() {
    if ((*(unsigned char*)&type & 8) != 0) {
        if (XFormatUtilityDrive() == 0)
            drive.error = FUN_0026f3e0(GetLastError());
    }
    drive.error = 0;
    return 1;
}


// 0x0026fcf0 FUN_0026fcf0 (84 B): matches/0x0026fcf0.cpp
// sym: ?FUN_0026fcf0@fn_f4379f43@@YAHPAPAVXboxDrive@core@@PBDHPAD@Z
// core::XboxDrive on its heap (0x0026f570 constructs it: the path, the heap), then its slot 21 with the details
// buffer, whose result is the function's
int __cdecl FUN_0026fcf0(core::XboxDrive** result, const char* path, int heap, char* details) {
    HULK_SIZE32(CoreXboxDrive, 0x1e4);
    DAT_004cdbb0 = heap;
    void* allocated = FUN_00266e00(heap, (int)sizeof(CoreXboxDrive));
    core::XboxDrive* object = allocated ? ((XboxDrive_nv_26fcf0*)allocated)->FUN_0026f570(path, heap) : 0;
    *result = object;
    return ((DriveSlots_26fcf0*)object)->s21(details);
}

} // namespace fn_f4379f43

// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002708e0..0x002719a0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f44852ae {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f44852ae {} using namespace fn_f44852ae;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f44852ae {
extern "C" char DAT_0042b680[];
extern "C" char DAT_0042b688[];
extern "C" char DAT_0042b6b0[];
extern int gValue_2708e0;
class ControllerBuffer {
  public:
    hulk_intptr vptr;
    hulk_intptr vptr4;
    int ref;
    int enabled;
    int a;
    int b;
    int c;
    int d;
    int e;
    int pad;
    int f;
    ControllerBuffer(int);
};
void InitBase_002705f0();
enum GameMemoryAllocator { GMA_DEFAULT };
extern "C" void* FUN_00266e00(GameMemoryAllocator heap, hulk_uintptr size);
} // namespace fn_f44852ae
inline void* operator new(size_t size, GameMemoryAllocator heap) {
    return FUN_00266e00(heap, size);
}
namespace fn_f44852ae {
class ControllerBuffer_270940 {
  public:
    ControllerBuffer_270940(GameMemoryAllocator heap); // FUN_002708e0
    char pad[0x2c];
};
int __cdecl FUN_00345b90(int);
void __cdecl FUN_00277190(void *);
extern "C" void __cdecl FUN_00273530(unsigned int, unsigned int);
void __cdecl FUN_00276650(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00275d20(unsigned int, unsigned int);
extern "C" void __cdecl FUN_00273500();
extern "C" int __cdecl FUN_00267400();
struct Item_270a50 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
};
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
extern "C" void __cdecl FUN_0026d850(char*);
extern "C" void __cdecl FUN_0026d840(char*);
typedef CoreDriveRegistryEntry CacheEntry;
extern "C" int __cdecl FUN_00270c10(const char *);
extern "C" bool __cdecl FUN_002771b0(const char* path);
extern "C" void __cdecl FUN_00277260(void** result, const char* name, unsigned int options, char* details);
struct Resource_270f90 {
    virtual void unused();
    virtual void release();
    bool FUN_00272b80();  // 0x00272b80: the drive thread's "requests queued" (0x002730c0) through the drive
};
extern "C" void FUN_00270980(char *);
extern "C" bool __cdecl FUN_00270f90(const char *);
extern "C" void __cdecl FUN_00273510();
extern "C" void __cdecl FUN_00276340();
extern "C" void __cdecl FUN_00277050();
extern "C" void __cdecl FUN_00274af0();
extern "C" void __cdecl FUN_0026d830(void*);
class Obj_271230 {
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
void FUN_002710d0(void*, int, int, int, int, int, int, int);
extern "C++" __declspec(nothrow) int __cdecl FUN_00270f10(const char *, void *);
extern "C" void * __cdecl FUN_00276680(unsigned int);
struct InstanceDrive_nv_271410 {
    core::InstanceDrive * FUN_00277110(void *, void *);
};
struct Obj_271530 {
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
};
struct A_271530 {
    Obj_271530* p;
};
extern void __cdecl FUN_00271410(A_271530*, int, int, int);
struct Item_271560 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual signed char v6(); };
extern void __cdecl FUN_002697c0(void*,void*,void*,void*,void*);
extern void __cdecl FUN_00277b70(void*,Item_271560*,int,int,int);
struct Work_271560 { int primary; int secondary; int tertiary; int alternate; char reserved[16]; int data; char rest[0xfc]; };
typedef unsigned int uint_2716c0;
typedef unsigned char byte_2716c0;
extern int __cdecl FUN_002716f0(unsigned int character, char *output, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int state);
extern const unsigned short DAT_004cdb08[];
unsigned int __cdecl FUN_002716c0(const unsigned char *text, unsigned int *length, unsigned int *value);
int __cdecl FUN_002716f0(unsigned int, char *, unsigned int, int, unsigned int *, unsigned int);
int __cdecl FUN_00271870(unsigned int, char *, unsigned int, unsigned int, unsigned int *, unsigned int);


// 0x002708e0 FUN_002708e0 (87 B): matches/0x002708e0.cpp
// sym: ??0ControllerBuffer@fn_f44852ae@@QAE@H@Z
ControllerBuffer::ControllerBuffer(int value) {
    vptr = ((hulk_intptr)DAT_0042b6b0);
    vptr4 = ((hulk_intptr)DAT_0042afa8);
    ref = *(int*)((hulk_intptr)((char*)&DAT_004cdbb0));
    InitBase_002705f0();
    vptr = ((hulk_intptr)DAT_0042b688);
    vptr4 = ((hulk_intptr)DAT_0042b680);
    enabled = 1;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    pad = 0;
    f = value;
    InitBase_002705f0();
}


// 0x00270940 FUN_00270940 (52 B): matches/0x00270940.cpp
// sym: ?FUN_00270940@fn_f44852ae@@YAXPAPAVControllerBuffer_270940@1@W4GameMemoryAllocator@1@@Z
void FUN_00270940(ControllerBuffer_270940** out, GameMemoryAllocator heap) {
    (*(GameMemoryAllocator*)&DAT_004cdbb0) = heap;
    *out = new (heap) ControllerBuffer_270940(heap);
}


// 0x00270980 FUN_00270980 (40 B): equivalent/0x00270980.cpp
// sym: _FUN_00270980
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00270980 @ 0x00270980
// equiv-conv: FUN_00270980 eax
extern "C" void FUN_00270980(char* text) {
    while (*text) {
        *text = (char)FUN_00345b90(*text);
        ++text;
    }
}


// 0x002709b0 FUN_002709b0 (124 B): equivalent/0x002709b0.cpp
// sym: ?FUN_002709b0@fn_f44852ae@@YAHIIII@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002709b0 @ 0x002709b0
// the drive registry (records.h CoreDriveRegistryEntry): every drive unmounted, every source directory cleared
int __cdecl FUN_002709b0(unsigned int first, unsigned int second, unsigned int third, unsigned int fourth)
{
    DAT_0052a124 = third;
    FUN_00277190(((char*)&DAT_0052a10c));
    FUN_00273530(first, fourth);
    FUN_00276650(first, fourth);
    FUN_00275d20(second, fourth);
    FUN_00273500();
    FUN_0026d820(((char*)DAT_0052a0f0));
    for (int i = 0; i < 26; ++i) {
        DAT_00528418[i].drive = 0;
        DAT_00528418[i].details[0] = 0;
    }
    (*(unsigned int*)&DAT_0052a120) = fourth;
    (*(unsigned char*)&DAT_0052a11d) = 1;
    return FUN_00267400();
}


// 0x00270a50 FUN_00270a50 (117 B): matches/0x00270a50.cpp
// sym: _FUN_00270a50
// data: count = DAT_0052a128, items = DAT_00528418 (records.h CoreDriveRegistryEntry), lockdata = DAT_0052a0f0
extern "C" void FUN_00270a50() {
    FUN_0026d850(((char*)DAT_0052a0f0));
    unsigned int i = 0;
    if ((unsigned int)(*(int*)&DAT_0052a128) > 0) {
        CoreDriveRegistryEntry* p = DAT_00528418;
        do {
            Item_270a50* q = (Item_270a50*)p->drive;
            if (q != 0) {
                q->A();
                FUN_0026d840(((char*)DAT_0052a0f0));
                q->D();
                q->B();
                FUN_0026d850(((char*)DAT_0052a0f0));
            }
            ++i;
            ++p;
        } while (i < (unsigned int)(*(int*)&DAT_0052a128));
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}

} // namespace fn_f44852ae

// 0x00270ad0 FUN_00270ad0 (147 B): matches/0x00270ad0.cpp [wrapped: conflict: FUN_00345b90]
// sym: _FUN_00270ad0
namespace fn_00270ad0 {


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif

extern "C++" __declspec(nothrow) char __cdecl FUN_00345b90(int);
extern "C++" __declspec(nothrow) char __cdecl FUN_002771b0(char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0026d850(void*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0026d840(void*);
extern "C" char __cdecl FUN_00270ad0(char* param) {
    char local[17];
    strncpy(local, param, 16);
    local[16] = 0;
    char* p = local;
    char c = *p;
    while (c) {
        *p = FUN_00345b90((int)*p);
        ++p;
        c = *p;
    }
    if (FUN_002771b0(local)) {
        FUN_0026d850(((char*)DAT_0052a0f0));
        strncpy(DAT_0052a10c, local, 16);
        (*(char*)&DAT_0052a11c) = 0;
        FUN_0026d840(((char*)DAT_0052a0f0));
        return 1;
    }
    return 0;
}
} // namespace fn_00270ad0

namespace fn_f44852ae {

// 0x00270b70 FUN_00270b70 (47 B): matches/0x00270b70.cpp
// sym: _FUN_00270b70
extern "C" void __cdecl FUN_00270b70(char* dst) {
    FUN_0026d850(((char*)DAT_0052a0f0));
    char* p = DAT_0052a10c;
    hulk_intptr d = (hulk_intptr)dst - (hulk_intptr)DAT_0052a10c;
    char c;
    do {
        c = *p;
        *(p + d) = c;
        ++p;
    } while (c != 0);
    FUN_0026d840(((char*)DAT_0052a0f0));
}


// 0x00270ba0 FUN_00270ba0 (6 B): matches/0x00270ba0.cpp
// sym: _FUN_00270ba0
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" int FUN_00270ba0(void) {
    return DAT_0052a124;
}


// 0x00270bb0 FUN_00270bb0 (10 B): matches/0x00270bb0.cpp
// sym: ?FUN_00270bb0@fn_f44852ae@@YAXH@Z
void __cdecl FUN_00270bb0(int value) {
    DAT_004cdc00 = value;
}


// 0x00270c10 FUN_00270c10 (103 B): matches/0x00270c10.cpp
// sym: _FUN_00270c10
// data: gCount_270c10 = DAT_0052a128, gEntries_270c10 = DAT_00528418
extern "C" int FUN_00270c10(const char* s) {
    unsigned int n = (*(unsigned int*)&DAT_0052a128);
    int i;
    for (i = 0; i < n; ++i) {
        if (strcmp(s, DAT_00528418[i].name) == 0)
            return i;
    }
    return -1;
}


// 0x00270c80 FUN_00270c80 (182 B): matches/0x00270c80.cpp
// sym: ?FUN_00270c80@fn_f44852ae@@YAEPAPAXPBDI@Z
// the drive registry (records.h CoreDriveRegistryEntry)
unsigned char __cdecl FUN_00270c80(void** result, const char* name, unsigned int options) {
    int index = FUN_00270c10(name);
    *result = 0;
    CacheEntry* entry;
    if (index != -1) {
        entry = &DAT_00528418[index];
        if (entry->drive) {
            *result = entry->drive;
            return 0;
        }
    } else {
        unsigned int count = (*(unsigned int*)&DAT_0052a128);
        if (count >= 26) {
            *result = 0;
            return 1;
        }
        entry = &DAT_00528418[count];
    }
    if (FUN_002771b0(name)) {
        FUN_00277260(result, name, options, entry->details);
        if (*result) {
            if (index == -1) {
                strncpy(entry->name, name, 16);
                entry->terminator = 0;
                (*(unsigned int*)&DAT_0052a128) = (*(unsigned int*)&DAT_0052a128) + 1;
            }
            entry->drive = *result;
        }
    }
    return 1;
}

} // namespace fn_f44852ae

// 0x00270d40 FUN_00270d40 (276 B): matches/0x00270d40.cpp [wrapped: conflict: FUN_002771b0]
// sym: ?FUN_00270d40@fn_00270d40@@YAXPBD0@Z
namespace fn_00270d40 {


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif

int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void*);
void __cdecl FUN_0026d840(void*);
extern "C++" __declspec(nothrow) int __cdecl FUN_00270c10(const char *);
unsigned char __cdecl FUN_002771b0(const char*);
struct Receiver_270d40 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(const char*);
};
// the drive registry (records.h CoreDriveRegistryEntry)
typedef CoreDriveRegistryEntry Entry_270d40;
void __cdecl FUN_00270d40(const char* name, const char* path) {
    char lower[20];
    strncpy(lower, name, 16);
    lower[16] = 0;
    for (char* p = lower; *p; ++p)
        *p = (char)FUN_00345b90((signed char)*p);
    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10(lower);
    if (index == -1) {
        if (FUN_002771b0(lower) && (*(unsigned int*)&DAT_0052a128) < 26) {
            Entry_270d40& entry = DAT_00528418[(*(unsigned int*)&DAT_0052a128)];
            strncpy(entry.name, lower, 16);
            entry.name[16] = 0;
            strncpy(entry.details, path, 256);
            ++(*(unsigned int*)&DAT_0052a128);
            FUN_0026d840(((char*)DAT_0052a0f0));
        }
    } else {
        Entry_270d40& entry = DAT_00528418[index];
        strncpy(entry.details, path, 256);
        Receiver_270d40* receiver = (Receiver_270d40*)entry.drive;
        FUN_0026d840(((char*)DAT_0052a0f0));
        receiver->slot21(path);
    }
}
} // namespace fn_00270d40

namespace fn_f44852ae {

// 0x00270e60 FUN_00270e60 (168 B): equivalent/0x00270e60.cpp
// sym: ?FUN_00270e60@fn_f44852ae@@YAXPBDPAD@Z
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_00270e60 @ 0x00270e60
// the drive registry (records.h CoreDriveRegistryEntry)
void __cdecl FUN_00270e60(const char *key, char *output)
{
    char buffer[17];
    strncpy(buffer, key, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);
    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        output[0] = 0;
    } else {
        const char *source = DAT_00528418[index].details;
        char value;
        do {
            value = *source++;
            *output++ = value;
        } while (value);
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}

} // namespace fn_f44852ae

// 0x00270f10 FUN_00270f10 (119 B): equivalent/0x00270f10.cpp [wrapped: conflict: FUN_0026d840]
// sym: _FUN_00270f10
namespace fn_00270f10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00270f10 @ 0x00270f10

extern "C++" __declspec(nothrow) void FUN_0026d850(void *arg);
extern "C++" __declspec(nothrow) int FUN_0026d840(void *arg);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
#endif

// equiv-conv: FUN_00270980 eax
extern "C++" __declspec(nothrow) void __cdecl FUN_00270980(char *);
unsigned char __cdecl FUN_00270c80(void **result, const char *name, unsigned int options);
extern "C" int __cdecl FUN_00270f10(const char *name, void *argument)
{
    struct Local { void *result; char text[20]; } local;
    FUN_0026d850(((char*)DAT_0052a0f0));
    if (name) {
        strncpy(local.text, name, 16);
        local.text[16] = 0;
        FUN_00270980(local.text);
    } else {
        strncpy(local.text, DAT_0052a10c, 16);
    }
    FUN_00270c80(&local.result, local.text, (unsigned int)(hulk_uintptr)argument);
    FUN_0026d840(((char*)DAT_0052a0f0));
    return local.result != 0;
}
} // namespace fn_00270f10

namespace fn_f44852ae {

// 0x00270f90 FUN_00270f90 (221 B): equivalent/0x00270f90.cpp
// sym: _FUN_00270f90
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 12/12)
// FUN_00270f90 @ 0x00270f90
// equiv-conv: FUN_00270980 eax
extern "C" bool __cdecl FUN_00270f90(const char *name) {
    char buffer[17];
    FUN_0026d850(((char*)DAT_0052a0f0));
    if (name) {
        strncpy(buffer, name, 16);
        buffer[16] = 0;
        FUN_00270980(buffer);
    } else {
        int i = 0;
        char c;
        do {
            c = DAT_0052a10c[i];
            buffer[i++] = c;
        } while (c);
    }
    int index = FUN_00270c10(buffer);
    if (index == -1) {
        FUN_0026d840(((char*)DAT_0052a0f0));
        return false;
    }
    Resource_270f90 *resource = (Resource_270f90 *)DAT_00528418[index].drive;
    if (!resource) {
        FUN_0026d840(((char*)DAT_0052a0f0));
        return false;
    }
    DAT_00528418[index].drive = 0;
    FUN_0026d840(((char*)DAT_0052a0f0));
    while (resource->FUN_00272b80()) {
        thunk_FUN_00270a50();
        FUN_0026d6d0(0);
    }
    resource->release();
    return true;
}


// 0x00271070 FUN_00271070 (89 B): matches/0x00271070.cpp
// sym: ?FUN_00271070@fn_f44852ae@@YAXXZ
// data: gData_271070 = DAT_00528418, gFinal = DAT_0052a0f0, gFlag_271070 = DAT_004cdc04
void __cdecl FUN_00271070() {
    if (DAT_004cdc04) {
        CoreDriveRegistryEntry* p = DAT_00528418;
        int n = 0x1a;
        do {
            if (p->drive != 0)
                FUN_00270f90(p->name);
            ++p;
            --n;
        } while (n != 0);
    }
    FUN_00273510();
    FUN_00276340();
    FUN_00277050();
    FUN_00274af0();
    FUN_0026d830(((char*)DAT_0052a0f0));
    (*(unsigned char*)&DAT_0052a11d) = 0;
}

} // namespace fn_f44852ae

// 0x002710d0 FUN_002710d0 (348 B): equivalent/0x002710d0.cpp [wrapped: conflict: FUN_0026d840]
// sym: ?FUN_002710d0@fn_002710d0@@YAHPAPAUFile_2710d0@1@PBDHHHHHH@Z
inline void* operator new(size_t, void* p) { return p; }
namespace fn_002710d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 14/14)
// FUN_002710d0 @ 0x002710d0

struct Source_2710d0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int status();
};
// the drive registry (records.h CoreDriveRegistryEntry): the entry's drive
struct File_2710d0;
// core::File (0x002764d0 constructs it): a stand-in named by its constructor's address, with its layout (records.h
// CoreFile, 0x168 bytes on the 32-bit build), so that the allocation is the class's size on every target

struct FUN_002764d0 : CoreFile {
 FUN_002764d0(Source_2710d0 *, const char *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned char);
};
struct Work_2710d0 { const char* volatile first; char* volatile second; int key; char gap[16]; char buffer[0x100]; char pad[0x20]; };
extern "C++" __declspec(nothrow) void __cdecl FUN_002697c0(const char *source, char *output, char *workspace, char **suffix, const char **remainder);
extern "C++" __declspec(nothrow) void FUN_0026d850(void *arg);
extern "C++" __declspec(nothrow) int FUN_0026d840(void *arg);
extern "C++" __declspec(nothrow) int __cdecl FUN_00270c10(const char *);
extern "C++" __declspec(nothrow) int __cdecl FUN_00270f10(const char *, void *);
extern "C" void * __cdecl FUN_00275d50(unsigned int);
int __cdecl FUN_002710d0(File_2710d0 **out, const char *input, int a, int b, int c, int d, int e, int f) {
 Work_2710d0 work;
 work.first = 0;
 work.second = 0;
 FUN_002697c0(input, work.buffer, (char *)&work.key, (char **)&work.second, (const char **)&work.first);
 FUN_0026d850(((char*)DAT_0052a0f0));
 int index = FUN_00270c10((const char *)(void *)(&work.key));
 void **slot = index == -1 ? 0 : &DAT_00528418[index].drive;
 if (!slot || !*slot) {
  if ((*(char*)&DAT_004cdc04)) {
   FUN_0026d840(((char*)DAT_0052a0f0));
   FUN_00270f10((const char *)(void *)(&work.key), (void *)(hulk_uintptr)(int)DAT_0052a120);
   FUN_0026d850(((char*)DAT_0052a0f0));
   index = FUN_00270c10((const char *)(void *)(&work.key));
   slot = index >= 0 ? &DAT_00528418[index].drive : 0;
  }
 }
 if (!slot || !*slot) {
  *out = 0;
  return FUN_0026d840(((char*)DAT_0052a0f0));
 }
 const char *selected = work.second;
 int status = ((Source_2710d0 *)*slot)->status();
 if ((signed char)status < 0) selected = work.first;
 HULK_SIZE32(FUN_002764d0, 0x168);
 FUN_002764d0 *result = (FUN_002764d0 *)FUN_00275d50((unsigned int)sizeof(FUN_002764d0));
 if (result) result = new (result) FUN_002764d0((Source_2710d0 *)*slot, selected, a, b, c, d, e, f, 1);
 *out = (File_2710d0 *)result;
 return FUN_0026d840(((char*)DAT_0052a0f0));
}
} // namespace fn_002710d0

namespace fn_f44852ae {

// 0x00271230 FUN_00271230 (62 B): matches/0x00271230.cpp
// sym: _FUN_00271230
extern "C" void FUN_00271230(Obj_271230* p, int a, int b, int c, int d, int e, int f, int g) {
    FUN_002710d0(p, a, b, c, d, e, f, g);
    Obj_271230* q = *(Obj_271230**)p;
    if (q)
        q->f21();
}


// 0x00271410 FUN_00271410 (281 B): equivalent/0x00271410.cpp
// sym: ?FUN_00271410@fn_f44852ae@@YAXPAPAVInstanceDrive@core@@PBDPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 16/16)
// FUN_00271410 @ 0x00271410
// the drive registry (records.h CoreDriveRegistryEntry): the entry's drive
void __cdecl FUN_00271410(core::InstanceDrive **result, const char *name, void *argument)
{
    char buffer[20];
    strncpy(buffer, name, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);

    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10(buffer);
    void **entry = 0;
    if (index != -1 && DAT_00528418[index].drive)
        entry = &DAT_00528418[index].drive;
    if (!entry && (*(char*)&DAT_004cdc04)) {
        FUN_0026d840(((char*)DAT_0052a0f0));
        FUN_00270f10(buffer, (void *)(hulk_uintptr)(int)DAT_0052a120);
        FUN_0026d850(((char*)DAT_0052a0f0));
        index = FUN_00270c10(buffer);
        if (index > -1 && DAT_00528418[index].drive)
            entry = &DAT_00528418[index].drive;
    }
    if (entry) {
        core::InstanceDrive *object = (core::InstanceDrive *)FUN_00276680(0x24);
        if (object)
            object = ((InstanceDrive_nv_271410*)(((core::InstanceDrive*)(object))))->FUN_00277110(*entry, argument);
        *result = object;
    } else {
        *result = 0;
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}


// 0x00271530 FUN_00271530 (42 B): matches/0x00271530.cpp
// sym: _FUN_00271530
extern "C" void __cdecl FUN_00271530(A_271530* a, int b, int c, int d) {
    FUN_00271410(a, b, c, d);
    if (a->p)
        a->p->f22();
}


// 0x00271560 FUN_00271560 (290 B): equivalent/0x00271560.cpp
// sym: _FUN_00271560
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 12/12)
// FUN_00271560 @ 0x00271560
extern "C" void __cdecl FUN_00271560(int* output, hulk_intptr name, int flags, int extra) {
    Work_271560 work;
    work.secondary = 0;
    work.tertiary = 0;
    FUN_002697c0((void*)name,&work.data,&work.alternate,&work.tertiary,&work.secondary);
    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10((const char *)(void *)(&work.alternate));
    void** entry = 0;
    if (index != -1) entry = &DAT_00528418[index].drive;
    if (!entry || !*entry) {
        if ((*(char*)&DAT_004cdc04)) {
            FUN_0026d840(((char*)DAT_0052a0f0));
            FUN_00270f10((const char *)(void *)(&work.alternate),(void *)(hulk_uintptr)(int)DAT_0052a120);
            FUN_0026d850(((char*)DAT_0052a0f0));
            index = FUN_00270c10((const char *)(void *)(&work.alternate));
            entry = index > -1 ? &DAT_00528418[index].drive : 0;
        }
    }
    if (!entry || !*entry) {
        *output = 0;
        FUN_0026d840(((char*)DAT_0052a0f0));
        return;
    }
    Item_271560* item = (Item_271560*)*entry;
    int selected = work.tertiary;
    if (item->v6() < 0) selected = work.secondary;
    FUN_00277b70(output,(Item_271560*)*entry,selected,flags,extra);
    FUN_0026d840(((char*)DAT_0052a0f0));
}


// 0x002716c0 FUN_002716c0 (48 B): matches/0x002716c0.cpp
// sym: ?FUN_002716c0@fn_f44852ae@@YA_NPAEPAI1@Z
bool FUN_002716c0(byte_2716c0* src, unsigned int* length, uint_2716c0* codepoint) {
    if (*src & 0x80)
        return false;
    if (length != 0)
        *length = 1;
    if (codepoint != 0)
        *codepoint = (uint_2716c0)((int)(signed char)*src & 0xff);
    return true;
}


// 0x002716f0 FUN_002716f0 (155 B): equivalent/0x002716f0.cpp
// sym: ?convertCharacter@fn_f44852ae@@YAHIPADIIPAII@Z
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 14/14)
// FUN_002716f0 @ 0x002716f0
int __cdecl convertCharacter(unsigned int character, char *output, unsigned int capacity, unsigned int fallback, unsigned int *written, hulk_uintptr state)
{
    if (capacity == 0)
        return -1;
    if (character <= 0x7f) {
        *output = (char)character;
        *written = 1;
        return 0;
    }
    if (character >= 0xff01 && character <= 0xff5e) {
        *output = (char)(character + 0x20);
        *written = 1;
        return 0;
    }
    if (character == 0x3000) {
        *output = ' ';
        *written = 1;
        return 0;
    }
    if (fallback == 0)
        return -4;
    int result = FUN_002716f0(fallback, output, capacity, 0, written, state);
    return result == -2 ? -6 : result;
}


// 0x00271820 FUN_00271820 (70 B): equivalent/0x00271820.cpp
// sym: _FUN_00271820
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 9/10, incomplete)
// FUN_00271820 @ 0x00271820
extern "C" unsigned int __cdecl FUN_00271820(const unsigned char *text, unsigned int *length, unsigned int *value)
{
    unsigned int character = *text;
    if (character < 0x80)
        return FUN_002716c0(text, length, value);

    if (character <= 0x9f)
        character = DAT_004cdb08[character];

    if (length)
        *length = 1;
    if (value)
        *value = character;
    return ((hulk_uintptr)value & 0xffffff00u) | 1;
}


// 0x00271870 FUN_00271870 (183 B): equivalent/0x00271870.cpp
// sym: ?ConvertWithFallback@fn_f44852ae@@YAHIPADIIPAII@Z
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 18/18)
// FUN_00271870 @ 0x00271870
int __cdecl ConvertWithFallback(hulk_uintptr codepoint, char *output, unsigned int capacity, hulk_uintptr fallback, unsigned int *written, hulk_uintptr flags)
{
    if (capacity == 0)
        return -1;
    if (FUN_002716f0(codepoint, output, capacity, 0, written, flags) == 0)
        return 0;
    if (codepoint >= 0xa0 && codepoint <= 0xff) {
        *output = (char)codepoint;
        *written = 1;
        return 0;
    }
    for (unsigned int i = 0; i < 32; ++i) {
        if (codepoint == ((unsigned short*)&DAT_004cdc08)[i]) {
            *output = (char)(i + 0x80);
            *written = 1;
            return 0;
        }
    }
    if (fallback == 0)
        return -4;
    int result = FUN_00271870(fallback, output, capacity, 0, written, flags);
    return result == -2 ? -6 : result;
}


// 0x00271930 FUN_00271930 (58 B): equivalent/0x00271930.cpp
// sym: ?FUN_00271930@fn_f44852ae@@YAXPADPBDI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00271930 @ 0x00271930
void __cdecl FUN_00271930(char* dest, const char* src, unsigned int size) {
    unsigned int i = 0;
    if (*src) {
        unsigned int limit = size - 1;
        while (i != limit && *src) {
            dest[i] = *src;
            ++i;
            ++src;
        }
    }
    dest[i] = 0;
}

} // namespace fn_f44852ae

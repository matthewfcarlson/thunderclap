// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00277ca0..0x0027a560 (kind game, layer platform/xbox, confidence high), dominant class core::XboxSaveDrive
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fad5a458 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fad5a458 {} using namespace fn_fad5a458;
#include "platform/xbox/core.h"

// ---- declarations shared by the functions below
namespace fn_fad5a458 {
class A_277ce0 {
  public:
    virtual void f();
    virtual void g();
};
class B_277ce0 {
  public:
    A_277ce0* p;
    void target();
};
struct Interface_277d00 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual int slot12(unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);
};
struct Object {
 unsigned int field0;
 unsigned int base;
 unsigned int position;
 unsigned int fieldC;
 unsigned int end;
 unsigned int state;
 int FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);
};
typedef unsigned int U_277d60;
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr,U_277d60);
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,U_277d60);
extern void __cdecl FUN_00279d30(void*,U_277d60,void*,U_277d60,U_277d60);
} // namespace fn_fad5a458
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
#endif
namespace fn_fad5a458 {
struct Reader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual int read(U_277d60,U_277d60,U_277d60,void*,void*,U_277d60,U_277d60*,U_277d60); };
struct State_277d60 { U_277d60 unknown; char* source; U_277d60 total; U_277d60 size; U_277d60 position; U_277d60 skip; U_277d60 sourceSize; U_277d60 unused; U_277d60 alignment; char* buffer; U_277d60 capacity;
int target(Reader* reader,U_277d60 a2,U_277d60 a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9);
};
typedef unsigned char byte_278060;
extern int __stdcall XGetDeviceChanges(void* deviceType, uint* inserted, uint* removed);
extern "C" char DAT_003ea820;
extern "C" int __stdcall XCalculateSignatureBegin(unsigned int);
extern "C" void __stdcall FUN_002120f5(int, unsigned int, unsigned int);
extern "C" void __stdcall FUN_00212143(int, unsigned int);
extern "C" int __stdcall FUN_0020bbc2(int);
extern "C" void __stdcall FUN_00356611(int);
class Obj {
  public:
    char pad[0x2f4];
    struct Slot {
        int handle;
        char pad[0x204];
    } slots[1];
    int Do(int* idx);
};
extern int __cdecl FUN_0026fd50(hulk_intptr, int);
namespace XAPILIB {
void __stdcall XUnmountMU(int,int);
}
struct XboxSaveDrive_278410 { char pad0[0xcc]; char mode; char pad1[6]; signed char slot; signed char letter; char pad2[8]; char mounted; char kind; char pad3[0x215]; int handles[4][130]; void FUN_00278410(); };
extern "C" void __cdecl FUN_002705f0();
extern "C" uint __stdcall XGetDevices(void*);
extern "C" void* __cdecl FUN_0026fd50(void*,int);
extern "C" void* __cdecl FUN_00266e00(int, int);
struct DriveThread_278500 { virtual void action(); void* FUN_002733c0(hulk_uintptr, hulk_uintptr); };
} // namespace fn_fad5a458
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned int);
namespace fn_fad5a458 {
struct FUN_00272d00 : CoreXboxSaveDrive { FUN_00272d00(); };
} // namespace fn_fad5a458
namespace core {
struct XboxSaveDrive_278500 : FUN_00272d00 {
 XboxSaveDrive_278500(const char*, int);
};
}
namespace fn_fad5a458 {
extern "C" char DAT_0042c064[], DAT_0042c058[], DAT_0042c048[], DAT_0042c038[], DAT_0042c028[], DAT_0042c008[], DAT_0042c018[];
} // namespace fn_fad5a458
namespace core {
struct SaveInterface {
    int FUN_0027a370(void* drive, unsigned int key, unsigned int mode, unsigned int start, unsigned int destination,
                     unsigned int count, unsigned int* completed, unsigned int flags);
};
}
namespace core {
struct XboxSaveDrive_2786a0 : CoreXboxSaveDrive {
    int vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start, unsigned int destination,
                 unsigned int count, unsigned int* completed, unsigned int flags);
};
}
namespace fn_fad5a458 {
void __stdcall ReleaseThing(int);
class Obj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
class GlobalObj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
extern int vt0_278740, vt4, vtc, vtbc, vtc0;
extern "C" void FUN_0026d830(int*);
struct Service_2787c0 { void FUN_00278060();  };
struct XboxSaveDrive_2787c0 {  int FUN_002787c0(unsigned int); };
struct XboxSaveDrive_2788c0 { char pad[0xb4]; unsigned int status; char pad2[0x10]; unsigned int mountedCount; char deviceType; char pad3[6]; signed char slot; signed char unit; char pad4[8]; unsigned char mounted; char drive;  void FUN_00278410(); unsigned int FUN_002787c0(unsigned int); bool FUN_002788c0(); };
struct MountRegistry { void FUN_00278060(); unsigned char FUN_002780c0(unsigned int, unsigned int); };
namespace XAPILIB {
unsigned int __stdcall XMountMUA(int, int, char*);
}
struct Obj_2789e0 {
    char pad[0xb4];
    int value;
};
struct XboxSaveDrive_nv_2789e0 {
    int FUN_002787c0(int);
};
typedef unsigned int DWORD;
extern int __stdcall FUN_002109b6(DWORD, int);
extern DWORD __stdcall GetLastError();
class XboxSaveDrive_278a00 {
  public:
    char pad[0xb4];
    int error;
    int TranslateError(DWORD);
    bool Run(DWORD x, int* out);
};
struct XboxSaveDrive_nv_278a40 {
    void* FUN_00278500(const char* name, int heap);
};
typedef unsigned char u8_278a80;
class XboxSaveDrive_278a80 {
  public:
    void FUN_00278740();
    virtual void f0();
    virtual void f1();
    virtual XboxSaveDrive_278a80* f2(u8_278a80);
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
extern "C" void __cdecl FUN_0026b800(char *, int, const char *, int, int, int, int);
extern "C" int __stdcall FUN_003564c0(const char *, char *);
extern "C" void * __cdecl thunk_FUN_00271f20(void *, const void *, unsigned int);
struct Slot_279220 { char path[0x204]; int handle; };
extern int __stdcall FUN_002109b6(const void *, int);
struct AdjBC {
    int vfunc_0_adjbc(const void *name, unsigned int unused, unsigned int block, unsigned int offset, unsigned int size, void *destination, unsigned int extra);
};
class XboxSaveDrive {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual int vfunc_2_adjbc(int);
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual int f10(int, int);
    virtual void f11(int, int);
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual int vfunc_18(const char *, const char *, int *, unsigned char);
    virtual int vfunc_19(int *, const char *);
    virtual void _m_vf20();
    virtual void _m_vf21();
    char _m_pad_4[0xb0];
    unsigned long error;
    Obj_278740* mObj;
    AdjBC reader;
    char _m_pad_bd[0x21];
    unsigned char driveLetter;
    char _m_pad_df[0x11];
    Slot_279220 slots[4];
    int vfunc_1_adjbc();
    void Run();
    void Init();
    void Finish();
    bool FUN_002788c0();
    int FUN_00278d30(const char *, char *, int, char *);
    unsigned long FUN_002787c0(unsigned long errorCode);
    bool FUN_00279490(const void *name, unsigned int block);
};
typedef unsigned char Byte_279d30;
struct Node { unsigned int parent; unsigned int left; unsigned int right; };
struct Tree_279f80 { unsigned int root; Node *nodes; };
typedef unsigned int uint_27a370;
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr position, uint_27a370 size);
struct Stream {
 virtual int transfer(uint_27a370 key, uint_27a370 mode, uint_27a370 block, uint_27a370 offset, uint_27a370 count, uint_27a370 destination, uint_27a370 flags);
 virtual uint_27a370 blockSize();
 virtual uint_27a370 baseOffset(uint_27a370 key);
 int FUN_0027a370(hulk_uintptr unused, uint_27a370 key, uint_27a370 mode, uint_27a370 start, uint_27a370 destination, uint_27a370 count, uint_27a370* completed, uint_27a370 flags);
};


// 0x00277ca0 FUN_00277ca0 (10 B): matches/0x00277ca0.cpp
// sym: ?FUN_00277ca0@fn_fad5a458@@YI_NPAH@Z
bool __fastcall FUN_00277ca0(int* ptr) {
    return *ptr != 0;
}


// 0x00277cb0 FUN_00277cb0 (3 B): matches/0x00277cb0.cpp
// sym: ?FUN_00277cb0@fn_fad5a458@@YIPAXPAPAX@Z
// Same code shape as 0x00088fa0 (propagated; names are from that function)
// core::File's view (records.h CoreFileView): the cement library entry's file
void* __fastcall FUN_00277cb0(void** p) {
    return *p;
}

} // namespace fn_fad5a458

// 0x00277cd0 FUN_00277cd0 (4 B): matches/0x00277cd0.cpp
// sym: ?FUN_00277cd0@C_277cd0@owners@@QAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int owners::C_277cd0::FUN_00277cd0() {
    return value;
}

namespace fn_fad5a458 {

// 0x00277ce0 FUN_00277ce0 (18 B): matches/0x00277ce0.cpp
// sym: ?target@B_277ce0@fn_fad5a458@@QAEXXZ
void B_277ce0::target() {
    A_277ce0* q = p;
    q->g();
    p = 0;
}


// 0x00277d00 FUN_00277d00 (82 B): equivalent/0x00277d00.cpp
// sym: ?FUN_00277d00@Object@fn_fad5a458@@QAEHPAUInterface_277d00@2@IIIIIIPAII@Z @f70145dd03b0 @w4575482bbc53
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00277d00 @ 0x00277d00
int Object::FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f) {
 int status = target->slot12(a,b,c,base+offset,d,e,result,f);
 unsigned int value = *result + offset;
 position = value;
 end = value;
 state = 0;
 return status;
}


// 0x00277d60 FUN_00277d60 (683 B): equivalent/0x00277d60.cpp
// sym: ?target@State_277d60@fn_fad5a458@@QAEHPAUReader@2@IIIIPADIPAII@Z @2ff50b72b51d @w22a5f48e02a1
// STATUS: equivalent (tools/equiv.py level 3: 526 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_00277d60 @ 0x00277d60
int State_277d60::target(Reader* reader,U_277d60 a2,U_277d60 a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9) {
 if(start>size) { *result=requested; return 1; }
 U_277d60 count=requested;
 if(start+requested>size) count=size-start;
 U_277d60 done=total, pos=position, offset=skip, carry=0;
 while(count) {
 hulk_uintptr aligned=FUN_0026fd80(pos,alignment);
 hulk_uintptr room=capacity;
 hulk_uintptr available=sourceSize-aligned;
 if(offset) room-=FUN_0026fd50(offset,alignment);
 if(available<room) room=available;
 hulk_uintptr amount=FUN_0026fd50(room-carry,alignment);
 U_277d60 readResult;
 int status=reader->read(a2,a3,a4,source+aligned+carry,buffer+carry,amount,&readResult,1);
 if(status!=1) return status;
 char* block=buffer-aligned+pos;
 char* end=buffer+room;
 while(count) {
 if(block+4>=end) break;
 U_277d60 packed=*(unsigned short*)block;
 U_277d60 expanded=*(unsigned short*)(block+2);
 U_277d60 length=packed?packed:expanded;
 if(block+4+length>end) break;
 U_277d60 remaining=expanded-offset;
 U_277d60 n=remaining;
 if(n>count) n=count;
 char* temp=offset?end:dest;
 if(!packed) memcpy(temp,block+4,n+offset);
 else FUN_00279d30(block+4,packed,temp,n+offset,expanded);
 if(offset) memcpy(dest,temp+offset,n);
 if(n!=remaining) offset=n;
 else { offset=0; pos+=length+4; block+=length+4; }
 done+=n; dest+=n; count-=n;
 }
 if(count && block!=end) {
 carry=FUN_0026fd50((U_277d60)(end-block),alignment);
 memcpy(buffer,end-carry,carry);
 } else carry=0;
 }
 total=done; position=pos; skip=offset; *result=requested; return 1;
}

} // namespace fn_fad5a458

// 0x00278010 FUN_00278010 (26 B): matches/0x00278010.cpp
// sym: ?FUN_00278010@Obj_278010@owners@@QAEHHHHHHHHHH@Z
int owners::Obj_278010::FUN_00278010(hulk_intptr a, int b, hulk_intptr c, int d, int e, hulk_intptr f, int g, hulk_intptr h, int i) {
    switch (state) {
    case 0:
        return A(((int)a), b, ((int)c), d, e, ((int)f), g, ((int)h), i);
    case 1:
        return B(((int)a), b, ((int)c), d, e, ((int)f), g, ((int)h), i);
    default:
        return 0;
    }
}

namespace fn_fad5a458 {

// 0x00278060 FUN_00278060 (90 B): matches/0x00278060.cpp
// sym: ?FUN_00278060@fn_fad5a458@@YIXPAE@Z
void __fastcall FUN_00278060(byte_278060* state) {
    uint insertedMask;
    uint removedMask;
    int result = XGetDeviceChanges(&DAT_003ea820, &insertedMask, &removedMask);
    if (result != 0) {
        byte_278060 insertedBits = (byte_278060)((((insertedMask >> 12) ^ insertedMask) & 0xf) ^ (insertedMask >> 12));
        byte_278060 removedBits = (byte_278060)((((removedMask >> 12) ^ removedMask) & 0xf) ^ (removedMask >> 12));
        state[0] = state[0] ^ removedBits ^ insertedBits;
        state[1] = state[1] | removedBits | insertedBits;
    }
}

} // namespace fn_fad5a458

// 0x002780c0 FUN_002780c0 (41 B): matches/0x002780c0.cpp
// sym: ?FUN_002780c0@Bits_2780c0@owners@@QAE_NHH@Z
bool owners::Bits_2780c0::FUN_002780c0(int a, int b) {
    if (a < 0 || b < 0)
        return true;
    byte mask = 1;
    mask = (byte)(mask << (a + b * 4));
    return (mask & value) != 0;
}

namespace fn_fad5a458 {

// 0x00278150 FUN_00278150 (36 B): matches/0x00278150.cpp
// sym: ?FUN_00278150@fn_fad5a458@@YAPAHH@Z
int* FUN_00278150(hulk_intptr base) {
    return (int*)(base + 4 + ((base + 0x1fefU) / 0x1fec) * 0x14);
}


// 0x00278180 FUN_00278180 (50 B): matches/0x00278180.cpp
// sym: _FUN_00278180
extern "C" unsigned char __cdecl FUN_00278180(unsigned int a, unsigned int b, unsigned int c) {
    int h = XCalculateSignatureBegin(0);
    if (h == -1)
        return 0;
    FUN_002120f5(h, a, b);
    FUN_00212143(h, c);
    return 1;
}

} // namespace fn_fad5a458

// 0x002781c0 FUN_002781c0 (87 B): matches/0x002781c0.cpp [wrapped: conflict: XCalculateSignatureBegin]
// sym: ?Target@fn_002781c0@@YA_NIH@Z
namespace fn_002781c0 {

extern int __stdcall XCalculateSignatureBegin(int);
extern void __stdcall FUN_002120f5(int, int, int);
extern void __stdcall FUN_00212143(int, int);
bool Target(unsigned int size, int arg) {
    int base = (*(volatile int*)((char*)&DAT_0052c270 + 8));
    base = base << 13;
    unsigned int limit = base + 0x2000;
    if (limit >= size) {
    } else {
    }
    if (!(limit < size))
        limit = size;
    int buf = (*(volatile int*)&DAT_0052c270);
    int sig = XCalculateSignatureBegin(0);
    if (sig == -1)
        return false;
    FUN_002120f5(sig, buf, limit - base - 0x14);
    FUN_00212143(sig, arg);
    return true;
}
} // namespace fn_002781c0


// 0x00278240 core::XboxSaveDrive::vfunc_0_adjc (12 B): matches/0x00278240.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_00278240@@QAEXXZ
namespace fn_00278240 {
// Same code shape as 0x00275e50 (propagated; names are from that function)
// data: g_data_278240 = DAT_0052c250

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
    FUN_0026d850(((char*)&DAT_0052c250));
}
} // namespace fn_00278240


// 0x00278250 core::XboxSaveDrive::vfunc_1_adjc (12 B): matches/0x00278250.cpp [wrapped: conflict: core::File]
// sym: ?vfunc_0_adj4@File@core@fn_00278250@@QAEXXZ
namespace fn_00278250 {
// Same code shape as 0x00275e50 (propagated; names are from that function)
// data: g_data_278250 = DAT_0052c250

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
    FUN_0026d840(((char*)&DAT_0052c250));
}
} // namespace fn_00278250


// 0x00278260 core::XboxSaveDrive::vfunc_6 (7 B): matches/0x00278260.cpp
// sym: ?vfunc_6@XboxSaveDrive@core@@UAEIXZ
// the drive's type (records.h CoreXboxSaveDrive)
unsigned int core::XboxSaveDrive::vfunc_6() {
    return ((CoreXboxSaveDrive*)this)->type;
}


// 0x00278270 core::XboxSaveDrive::vfunc_4 (7 B): matches/0x00278270.cpp
// sym: ?vfunc_4@XboxSaveDrive@core@@UAEPAXXZ
// the drive's name (records.h CoreXboxSaveDrive)
void* core::XboxSaveDrive::vfunc_4() {
    return ((CoreXboxSaveDrive*)this)->name;
}

namespace fn_fad5a458 {

// 0x00278280 core::XboxSaveDrive::vfunc_10 (61 B): matches/0x00278280.cpp
// sym: ?f10@XboxSaveDrive@fn_fad5a458@@UAEHHH@Z
// CloseHandle (the XDK row 0x0020bbc2)
int XboxSaveDrive::f10(int a, int b) {
    f11(a, b);
    if ((*(int*)((char*)&DAT_0052c270 + 4)) == a)
        (*(int*)((char*)&DAT_0052c270 + 12)) = 0;
    FUN_0020bbc2(a);
    --((CoreXboxSaveDrive*)this)->openFiles;
    return 1;
}


// 0x002782c0 core::XboxSaveDrive::vfunc_1_adjbc (6 B): matches/0x002782c0.cpp
// sym: ?vfunc_1_adjbc@XboxSaveDrive@fn_fad5a458@@QAEHXZ
int XboxSaveDrive::vfunc_1_adjbc() {
    return 0x1fec;
}


// 0x002782d0 core::XboxSaveDrive::vfunc_2_adjbc (8 B): matches/0x002782d0.cpp
// sym: ?vfunc_2_adjbc@XboxSaveDrive@fn_fad5a458@@UAEHH@Z
int XboxSaveDrive::vfunc_2_adjbc(int) {
    return 4;
}

} // namespace fn_fad5a458

// 0x002782e0 core::XboxSaveDrive::vfunc_1_adjc0 (6 B): matches/0x002782e0.cpp [wrapped: same definition as 0x002782c0 in this TU]
// sym: ?vfunc_1_adjbc@XboxSaveDrive@fn_002782e0@@QAEHXZ
namespace fn_002782e0 {
// Same code shape as 0x002782c0 (propagated; names are from that function)
class XboxSaveDrive {
  public:
    int vfunc_1_adjbc();
};
int XboxSaveDrive::vfunc_1_adjbc() {
    return 0x1fec;
}
} // namespace fn_002782e0


// 0x002782f0 core::XboxSaveDrive::vfunc_2_adjc0 (8 B): matches/0x002782f0.cpp [wrapped: same definition as 0x002782d0 in this TU]
// sym: ?vfunc_2_adjbc@XboxSaveDrive@fn_002782f0@@UAEHH@Z
namespace fn_002782f0 {
// Same code shape as 0x002782d0 (propagated; names are from that function)
class XboxSaveDrive {
  public:
    virtual void a();
    virtual void b();
    virtual int vfunc_2_adjbc(int);
};
int XboxSaveDrive::vfunc_2_adjbc(int) {
    return 4;
}
} // namespace fn_002782f0

namespace fn_fad5a458 {

// 0x00278300 FUN_00278300 (63 B): matches/0x00278300.cpp
// sym: ?Do@Obj@fn_fad5a458@@QAEHPAH@Z
int Obj::Do(int* idx) {
    int h = slots[*idx].handle;
    if (h != -1) {
        FUN_00356611(h);
        slots[*idx].handle = -1;
    }
    return 1;
}

} // namespace fn_fad5a458

// 0x00278340 core::XboxSaveDrive::vfunc_5 (72 B): matches/0x00278340.cpp
// sym: ?vfunc_5@XboxSaveDrive@core@@UAEHHH@Z
int core::XboxSaveDrive::vfunc_5(hulk_intptr __p0, int param3) { int * param2 = (int *)__p0;

    hulk_intptr base = param3;
    uint q = (uint)(base + 0x1fef) / 0x1fec;
    int* p = (int*)((char*)base + q * 20 + 4);
    int r = FUN_0026fd50((hulk_intptr)p, 0x4000);
    r += 0x8000;
    if (*param2)
        r += 0x4000;
    return r;
}


// 0x002783d0 FUN_002783d0 (63 B): matches/0x002783d0.cpp
// sym: ?FUN_002783d0@Obj_2783d0@owners@@QAEXPAH0@Z
void owners::Obj_2783d0::FUN_002783d0(int* a, int* b) {
    if (flag == 0x55) {
        *a = -1;
        *b = -1;
    } else {
        *a = x - 0x31;
        *b = y - 0x41;
    }
}

namespace fn_fad5a458 {

// 0x00278410 FUN_00278410 (133 B): equivalent/0x00278410.cpp
// sym: ?FUN_00278410@XboxSaveDrive_278410@fn_fad5a458@@QAEXXZ @b03583393748 @wa03f978dd4f2
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 10/10)
// FUN_00278410 @ 0x00278410
void XboxSaveDrive_278410::FUN_00278410() { if(kind == 0x55 || !mounted) return; for(int i=0;i<4;++i) { if(handles[i][0] != -1) { FUN_00356611(handles[i][0]); handles[i][0]=-1; } } if(mode == 0x55) XAPILIB::XUnmountMU(-1,-1); else XAPILIB::XUnmountMU(slot-0x31,letter-0x41); mounted=0; }


// 0x002784c0 FUN_002784c0 (57 B): matches/0x002784c0.cpp
// sym: ?compare@fn_fad5a458@@YGEPBG0@Z
unsigned char __stdcall compare(const unsigned short* a, const unsigned short* b) {
    unsigned short x = *b;
    while (x != 0) {
        if (*a == 0 || *a != x)
            return 0;
        x = *(++b);
        ++a;
    }
    return 1;
}

} // namespace fn_fad5a458

// 0x00278500 FUN_00278500 (407 B): equivalent/0x00278500.cpp
// sym: ??0XboxSaveDrive_278500@core@@QAE@PBDH@Z @5ea07f6a48c8 @w91908c781550
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00278500 @ 0x00278500
core::XboxSaveDrive_278500::XboxSaveDrive_278500(const char* nameArg, int heap) {
 HULK_SIZE32(CoreDriveThread, 0x94);
 *(const void* volatile*)&vftableReader=DAT_0042c008; *(const void* volatile*)&vftableWriter=DAT_0042c018;
 drive.vftable=DAT_0042c064; drive.vftableObject=DAT_0042c058; drive.vftableMutable=DAT_0042c048;
 *(const void* volatile*)&vftableReader=DAT_0042c038; *(const void* volatile*)&vftableWriter=DAT_0042c028;
 openFiles=0; mounted=0; driveLetter=0;
 FUN_002705f0();
 if (!(*(char*)&DAT_0052c280)) {
  uint mask=XGetDevices(&DAT_003ea820);
  (*(unsigned char*)&DAT_0052a228)=(unsigned char)(((mask>>12)&0xf0) | (mask&15));
  (*(unsigned char*)&DAT_0052a229)=0;
  (*(void**)&DAT_0052c270)=FUN_0026fd50(((char*)&DAT_0052a230),32);
 }
 if (!(*(DriveThread_278500**)&DAT_0052c26c)) {
  FUN_0026d820(((char*)&DAT_0052c250));
  DAT_004cdbb0=heap;
  DriveThread_278500* p=(DriveThread_278500*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
  if(p) { drive.driveThread=p->FUN_002733c0((hulk_uintptr)&DAT_0052c250,(hulk_uintptr)(hulk_intptr)heap); (*(void**)&DAT_0052c26c)=drive.driveThread; }
  else {drive.driveThread=0;(*(void**)&DAT_0052c26c)=0;}
 } else { drive.driveThread=(*(void**)&DAT_0052c26c); ((DriveThread_278500*)drive.driveThread)->action(); }
 if(nameArg[0]==((char*)&DAT_004004f8)[0] && nameArg[1]==((char*)&DAT_004004f8)[1] && nameArg[2]==((char*)&DAT_004004f8)[2]) { type=0xc3;mounted=1;driveLetter=0x55; drive.label.buffer[0]=0; }
 else type=0xc7;
 _strncpy(name,nameArg,16);
 terminator=0;
 for(int i=0;i<4;i++) files[i]=(hulk_uintptr)-1;
 slots[0].handle=slots[1].handle=slots[2].handle=slots[3].handle=(hulk_uintptr)-1;
}


// 0x002786a0 core::XboxSaveDrive::vfunc_12 (31 B): matches/0x002786a0.cpp
// sym: ?vfunc_12@XboxSaveDrive_2786a0@core@@QAEHIIIIIIPAII@Z
// The original tail-jumps to the save interface's read 0x0027a370 (ret 0x20: 8 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 8 stack words and the third argument is
// dropped. Declared as such (native14 check 7: with 3 parameters the callee read 5 garbage words and popped 32 bytes).
namespace core {
int XboxSaveDrive_2786a0::vfunc_12(unsigned int key, unsigned int mode, unsigned int unused, unsigned int start,
                            unsigned int destination, unsigned int count, unsigned int* completed, unsigned int flags) {
    return ((SaveInterface*)&vftableReader)->FUN_0027a370(this, key, mode, start, destination, count, completed, flags);
}
}


// 0x002786c0 core::XboxSaveDrive::vfunc_13 (31 B): matches/0x002786c0.cpp [wrapped: conflict: core::SignedWriter]
// sym: ?vfunc_13@XboxSaveDrive_2786c0@core@fn_002786c0@@QAEHIIIIIIPAIII@Z
namespace fn_002786c0 {
// The original tail-jumps to the save interface's write 0x0027a460 (ret 0x24: 9 words) after moving its first two
// arguments up one slot and putting the drive in front: the call has 9 stack words and the third argument is
// dropped. Declared as such (native14 check 7; the 3-parameter spelling byte-matched but read 6 garbage words and
// left the stack 24 bytes off natively).
namespace core {
struct SignedWriter {
    int FUN_0027a460(void* drive, unsigned int handle, unsigned int mode, unsigned int offset, unsigned int destination,
                     unsigned int count, unsigned int* result, unsigned int flags, unsigned int context);
};
// records.h CoreXboxSaveDrive: the core::SignedWriter base at +0xc0
struct XboxSaveDrive_2786c0 : CoreXboxSaveDrive {
    int vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                 unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                 unsigned int context);
};
int XboxSaveDrive_2786c0::vfunc_13(unsigned int handle, unsigned int mode, unsigned int unused, unsigned int offset,
                            unsigned int destination, unsigned int count, unsigned int* result, unsigned int flags,
                            unsigned int context) {
    return ((SignedWriter*)&vftableWriter)->FUN_0027a460(this, handle, mode, offset, destination, count, result, flags, context);
}
} // namespace core
} // namespace fn_002786c0


// 0x002786e0 core::XboxSaveDrive::vfunc_0_adj4 (8 B): equivalent/0x002786e0.cpp [wrapped: conflict: core::XboxSaveDrive]
// sym: ?vfunc_0_adj4@XboxSaveDrive@core@fn_002786e0@@QAEPAV123@E@Z @65ea14c36fbf @w72215fe2e7f6
namespace fn_002786e0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// core::XboxSaveDrive::vfunc_0_adj4 @ 0x002786e0
namespace core {
// core::XboxSaveDrive's core::Object base (+4 of records.h CoreXboxSaveDrive): the deleting destructor 0x00278a80
// on the whole drive
class XboxSaveDrive {
public:
    XboxSaveDrive* FUN_00278a80(unsigned char flags);
    XboxSaveDrive* vfunc_0_adj4(unsigned char flags);
};
XboxSaveDrive* XboxSaveDrive::vfunc_0_adj4(unsigned char flags) {
    XboxSaveDrive* drive = reinterpret_cast<XboxSaveDrive*>(reinterpret_cast<char*>(this) - (hulk_uintptr)&((CoreXboxSaveDrive*)0)->drive.vftableObject);
    return drive->FUN_00278a80(flags);
}
}
} // namespace fn_002786e0


// 0x002786f0 core::XboxSaveDrive::vfunc_2_adjc (8 B): matches/0x002786f0.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ?v2@XboxDrive@fn_002786f0@@WM@AEXH@Z
namespace fn_002786f0 {
#if !defined(HULK_PTR64)
// Same code shape as 0x0026f540 (propagated; names are from that function)
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
// the slot), whose adjustment and target are the invented layout's. Here the thunk is explicit: core::XboxSaveDrive's
// IMutable slot 2 takes the IMutable sub-object, steps back to the drive by that base's offset in records.h
// CoreXboxSaveDrive, and runs the deleting destructor 0x00278a80 (named by its address, so the native link binds it).
// The function is named by its own address: native_mac.TreeDefs finds the vftable slot's definition by that name.
struct Target_2786f0 {
    void* FUN_00278a80(unsigned char flags);
};
struct Thunk_2786f0 {
    void* FUN_002786f0(unsigned char flags);
};
void* Thunk_2786f0::FUN_002786f0(unsigned char flags) {
    char* drive = (char*)this - (hulk_uintptr)&((CoreXboxSaveDrive*)0)->drive.vftableMutable;
    return ((Target_2786f0*)drive)->FUN_00278a80(flags);
}
#endif
} // namespace fn_002786f0


// 0x00278700 core::XboxSaveDrive::vfunc_20 (63 B): matches/0x00278700.cpp
// sym: ?vfunc_20@XboxSaveDrive@core@@UAEHH@Z
int core::XboxSaveDrive::vfunc_20(hulk_intptr __p0) { int * p = (int *)__p0;

    int v = *(int*)((char*)this + *p * 0x208 + 0x2f4);
    if (v != -1) {
        ReleaseThing(v);
        *(int*)((char*)this + *p * 0x208 + 0x2f4) = -1;
    }
    return 1;
}

namespace fn_fad5a458 {

// 0x00278740 FUN_00278740 (115 B): matches/0x00278740.cpp
// sym: ?Run@XboxSaveDrive@fn_fad5a458@@QAEXXZ
void XboxSaveDrive::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vt0_278740;
    *(hulk_intptr*)((char*)this + 4) = (hulk_intptr)&vt4;
    *(hulk_intptr*)((char*)this + 0xc) = (hulk_intptr)&vtc;
    *(hulk_intptr*)((char*)this + 0xbc) = (hulk_intptr)&vtbc;
    *(hulk_intptr*)((char*)this + 0xc0) = (hulk_intptr)&vtc0;
    Init();
    if (*(int*)((char*)mObj + 0x10) == 1) {
        (*(GlobalObj_278740**)&DAT_0052c26c)->V1();
        (*(GlobalObj_278740**)&DAT_0052c26c) = 0;
        FUN_0026d830(((int*)&DAT_0052c250));
        return Finish();
    }
    mObj->V1();
    return Finish();
}


// 0x002787c0 FUN_002787c0 (203 B): equivalent/0x002787c0.cpp
// sym: ?FUN_002787c0@XboxSaveDrive_2787c0@fn_fad5a458@@QAEHI@Z @d2138d0c0304 @w1881c6de4ccf
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 26/26)
// FUN_002787c0 @ 0x002787c0
int XboxSaveDrive_2787c0::FUN_002787c0(unsigned int value) { if(value<=0x11) { switch(value) {case 0:return 0;case 2:case 3:case 15:return 1;case 11:return 5;case 17:return 3;default:return 8;} } switch(value) { case 0x1a:return 11; case 0x1b:case 0x3ed:return 5; case 0x22:return 3; case 0x55:return 0; case 0x70:return 7; case 0x48f: { (*(Service_2787c0*)&DAT_0052a228).FUN_00278060(); unsigned int first; ((owners::Obj_2783d0 *)this)->FUN_002783d0((int *)(&first), (int *)(&value)); return ((owners::Bits_2780c0 *)&((*(Service_2787c0*)&DAT_0052a228)))->FUN_002780c0((int)first, (int)value)?3:4; } default:return 8; } }


// 0x002788c0 FUN_002788c0 (286 B): equivalent/0x002788c0.cpp
// sym: ?FUN_002788c0@XboxSaveDrive_2788c0@fn_fad5a458@@QAE_NXZ @9db53bd45c68 @w3c174c6717c2
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 14/18, incomplete)
// FUN_002788c0 @ 0x002788c0
bool XboxSaveDrive_2788c0::FUN_002788c0() {
 int port = -1, unit = -1;
 if (deviceType != 'U') { port = (int)slot - '1'; unit = (int)this->unit - 'A'; }
 (*(MountRegistry*)&DAT_0052a228).FUN_00278060();
 if (port >= 0 && unit >= 0) {
  unsigned int shift = (port + unit * 4) & 31;
  unsigned char bit = shift < 8 ? (unsigned char)(1 << shift) : 0;
  if ((*(unsigned char*)&DAT_0052a229) & bit) {
   if (mountedCount > 0) {
    (*(MountRegistry*)&DAT_0052a228).FUN_00278060();
    unsigned int first, second;
    ((owners::Obj_2783d0 *)this)->FUN_002783d0((int *)(&second), (int *)(&first));
    status = (*(MountRegistry*)&DAT_0052a228).FUN_002780c0(second, first) ? 3 : 4;
    return false;
   }
   (*(unsigned char*)&DAT_0052a229) &= (unsigned char)~bit;
   FUN_00278410();
  }
 }
 if (!mounted) {
  unsigned int error = XAPILIB::XMountMUA(port, unit, &drive);
  if (error) {
   if (error == 0x70) status = 13;
   else status = FUN_002787c0(error);
   return false;
  }
 }
 mounted = 1;
 status = 0;
 return true;
}


// 0x002789e0 FUN_002789e0 (32 B): matches/0x002789e0.cpp
// sym: ?target@fn_fad5a458@@YI_NPAUObj_2789e0@1@PAXH@Z
bool __fastcall target(Obj_2789e0* self, void*, int arg) {
    int result = ((XboxSaveDrive_nv_2789e0*)(((core::XboxSaveDrive*)(((core::XboxSaveDrive*)(self))))))->FUN_002787c0(arg);
    self->value = result;
    return result == 0;
}


// 0x00278a00 FUN_00278a00 (57 B): matches/0x00278a00.cpp
// sym: ?Run@XboxSaveDrive_278a00@fn_fad5a458@@QAE_NIPAH@Z
bool XboxSaveDrive_278a00::Run(DWORD x, int* out) {
    int r = FUN_002109b6(x, 0);
    *out = r;
    if (r == -1) {
        error = TranslateError(GetLastError());
        return false;
    }
    return true;
}


// 0x00278a40 FUN_00278a40 (60 B): matches/0x00278a40.cpp
// sym: _FUN_00278a40
// data: gLast = DAT_004cdbb0
// core::XboxSaveDrive's constructor (0x00278500: the drive's name, its heap)
extern "C" void __cdecl FUN_00278a40(void** out, const char* name, int heap) {
    HULK_SIZE32(CoreXboxSaveDrive, 0x910);
    DAT_004cdbb0 = heap;
    void* p = FUN_00266e00(heap, (int)sizeof(CoreXboxSaveDrive));
    *out = p ? ((XboxSaveDrive_nv_278a40*)p)->FUN_00278500(name, heap) : 0;
}


// 0x00278a80 core::XboxSaveDrive::vfunc_2 (36 B): matches/0x00278a80.cpp
// sym: ?f2@XboxSaveDrive_278a80@fn_fad5a458@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
XboxSaveDrive_278a80* XboxSaveDrive_278a80::f2(u8_278a80 flag) {
    FUN_00278740();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}

} // namespace fn_fad5a458

// 0x00278ab0 core::XboxSaveDrive::vfunc_17 (147 B): equivalent/0x00278ab0.cpp [wrapped: conflict: core::XboxSaveDrive]
// sym: ?vfunc_17@XboxSaveDrive@core@fn_00278ab0@@QAEHH@Z @d38e12bddb11 @wa39663f0ca0a
namespace fn_00278ab0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::XboxSaveDrive::vfunc_17 @ 0x00278ab0
namespace core { struct XboxSaveDrive { char pad[0xb4]; int result; char more[0x26]; char letter; bool FUN_002788c0(); int FUN_002787c0(int); int vfunc_17(int); }; }
extern "C++" __declspec(nothrow) void __cdecl FUN_0026b800(char *, int, int, int, int, int, int);
extern "C" int __stdcall FUN_003563f0(char *, char *);
int core::XboxSaveDrive::vfunc_17(int value) {
    if (!FUN_002788c0()) return 0;
    char path[4];
    char buffer[0x200];
    path[0] = letter; path[1] = ':'; path[2] = '\\'; path[3] = 0;
    FUN_0026b800(buffer, 2, value, 1, 0, 0x202, 0);
    int error = FUN_003563f0(path, buffer);
    if (error) { result = FUN_002787c0(error); return 0; }
    result = 0;
    return 1;
}
} // namespace fn_00278ab0


// 0x00278b50 FUN_00278b50 (475 B): equivalent/0x00278b50.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?FUN_00278b50@XboxSaveDrive_278b50@fn_00278b50@@QAEXXZ @13cb711d8ec6 @wd90cd4ca3d03
namespace fn_00278b50 {
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 22/28, incomplete)
// FUN_00278b50 @ 0x00278b50
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 22/28, incomplete)
// FUN_00278b50 @ 0x00278b50

namespace XAPILIB { extern "C++" __declspec(nothrow) char* __stdcall XMUNameFromDriveLetter(unsigned int, char*, unsigned int); extern "C++" __declspec(nothrow) hulk_uintptr __stdcall GetLastError(); }
extern "C" int __stdcall FUN_00208b9c(char*, unsigned int*, unsigned int*, unsigned int*);
extern "C" unsigned int __stdcall FUN_00209a8e(char*);
extern "C++" __declspec(nothrow) void __cdecl FUN_0026b800(char*, int, char*, int, int, int, int);
struct XboxSaveDrive_278b50 {
 char pad0[0x60]; unsigned int result, size, count, sector;
 char name[0x41]; char padB1[3]; unsigned int previous;
 char padB8[0x14]; char flagCC; char padCD[6]; char digit, letter;
 char padD5[9]; unsigned char drive;
 void FUN_00278060(); void FUN_00278410(); bool FUN_002788c0();
 unsigned int FUN_002787c0(char*); void FUN_00278b50();
};
struct DiskInfo { char root[4]; unsigned int low, high, last, unused, other; };
void XboxSaveDrive_278b50::FUN_00278b50() {
 sector = 512; size = 0; count = 0;
 int row = 0, col = 0;
 if (drive != 'U') {
  name[0] = 0;
  if (flagCC == 'U') { row = -1; col = -1; }
  else { row = (signed char)digit - '1'; col = (signed char)letter - 'A'; }
  ((XboxSaveDrive_278b50*)&(*(unsigned char*)&DAT_0052a228))->FUN_00278060();
  if (row >= 0 && col >= 0) {
   unsigned int index = row + col * 4;
   unsigned char mask = (unsigned char)(1 << (index & 31));
   if ((*(unsigned char*)&DAT_0052a229) & mask) FUN_00278410();
   if (!((*(unsigned char*)&DAT_0052a228) & mask)) { result = previous = 4; return; }
  }
  if (!FUN_002788c0()) { result = previous; return; }
  char tmp[32];
  char* path = XAPILIB::XMUNameFromDriveLetter(drive,tmp,32);
  unsigned int err = FUN_002787c0(path);
  if (err) { result = err; name[0] = 0; return; }
  for (int i=0;i<0x41;i++) name[i]=0;
  FUN_0026b800(name,1,tmp,2,0,0x41,0);
 }
 DiskInfo info;
 info.root[0]=drive; info.root[1]=':'; info.root[2]='\\'; info.root[3]=0;
 if (!FUN_00208b9c(info.root,&info.low,&info.other,&info.last)) {
  name[0]=0;
  unsigned int err=FUN_002787c0((char*)XAPILIB::GetLastError());
  result=previous=err; return;
 }
 result=previous=0;
 size=info.high ? 0xffffffff : info.low;
 unsigned int sec=FUN_00209a8e(info.root);
 if (sec) sector=sec;
 else sector=512;
 count=size/sector;
}
} // namespace fn_00278b50


// 0x00278d30 FUN_00278d30 (166 B): equivalent/0x00278d30.cpp [wrapped: compile error C2440: 'initializing' : cannot convert from 'unsigned long (__stdcall *)(void)' to 'unsigned int']
// sym: ?FUN_00278d30@XboxSaveDrive_278d30@fn_00278d30@@QAEHPAUResult_278d30@2@PAUSource_278d30@2@HI@Z @01da32721882 @wb6632b52d793
namespace fn_00278d30 {
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// FUN_00278d30 @ 0x00278d30
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
struct Result_278d30 { unsigned state; unsigned char status; };
struct Source_278d30 { char reserved[0x244]; char data[1]; };
extern "C++" __declspec(nothrow) void __cdecl FUN_0026b800(void *, int, void *, int, int, int, int);
struct XboxSaveDrive_278d30 {
 char reserved[0xb4]; unsigned error;
 unsigned FUN_002787c0(unsigned);
 bool FUN_002784c0(void *, unsigned);
 int FUN_00278d30(Result_278d30 *, Source_278d30 *, int, hulk_uintptr);
};
int XboxSaveDrive_278d30::FUN_00278d30(Result_278d30 *result, Source_278d30 *source, int code, hulk_uintptr value) {
 if (code == -1) {
  unsigned err = XAPILIB::GetLastError();
  if (err == 0x12) {
   result->status = 0;
   result->state = 2;
   error = 0;
   return 0;
  }
  error = FUN_002787c0(err);
  return 1;
 }
 void *data = source->data;
 if (FUN_002784c0(data, value)) {
  FUN_0026b800(&result->status, 1, data, 2, 0, 0x101, 0);
  result->state = 3;
  error = 0;
  return 0;
 }
 return 2;
}
} // namespace fn_00278d30


// 0x00278de0 FUN_00278de0 (259 B): equivalent/0x00278de0.cpp [wrapped: conflict: DWORD; GetLastError]
// sym: ?FUN_00278de0@XboxSaveDrive_278de0@fn_00278de0@@QAE_NXZ @a5e968f88534 @wdce41e788bc2
namespace fn_00278de0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_00278de0 @ 0x00278de0

typedef unsigned long DWORD;
extern "C++" __declspec(nothrow) int __stdcall FUN_002109b6(int, int);
extern "C" char __cdecl FUN_002781c0(int, void *);
extern "C" int __stdcall FUN_002101d4(int, hulk_uintptr, int, int);
extern "C" int __stdcall FUN_0021007a(int, hulk_intptr, int, void *, int);
namespace XAPILIB { extern "C++" __declspec(nothrow) hulk_intptr __stdcall GetLastError(); }
struct DataBlock_278de0 { DWORD words[5]; };
struct Scratch_278de0 { DWORD unused; DataBlock_278de0 block; };
struct XboxSaveDrive_278de0 {
 char pad[0xb4];
 int error;
 int FUN_002787c0(hulk_intptr);
 bool FUN_00278de0();
};
bool XboxSaveDrive_278de0::FUN_00278de0() {
 if ((*(int*)((char*)&DAT_0052c270 + 12)) != 2) return true;
 int length = FUN_002109b6((*(int*)((char*)&DAT_0052c270 + 4)), 0);
 if (length == -1) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 Scratch_278de0 scratch;
 if (!FUN_002781c0(length, &scratch.block)) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 unsigned int offset = (*(unsigned int*)((char*)&DAT_0052c270 + 8)) << 13;
 unsigned int end = offset + 8192;
 if (end > (unsigned int)length) end = length;
 DataBlock_278de0 *trailer = (DataBlock_278de0 *)((*(char**)&DAT_0052c270) + end - offset - 20);
 *trailer = scratch.block;
 if (FUN_002101d4((*(int*)((char*)&DAT_0052c270 + 4)), offset, 0, 0) == (int)offset &&
     FUN_0021007a((*(int*)((char*)&DAT_0052c270 + 4)), (hulk_intptr)(*(char**)&DAT_0052c270), end - offset, &scratch, 0)) {
  (*(int*)((char*)&DAT_0052c270 + 12)) = 1;
  return true;
 }
 error = FUN_002787c0(XAPILIB::GetLastError());
 return false;
}
} // namespace fn_00278de0


// 0x00278ef0 FUN_00278ef0 (616 B): equivalent/0x00278ef0.cpp [wrapped: conflict: FUN_00278180; GetLastError; XCalculateSignatureBegin]
// sym: ?FUN_00278ef0@XboxSaveDrive_278ef0@fn_00278ef0@@QAE_NII_N@Z @9a314e988778 @w4b4ba2f21ba2
namespace fn_00278ef0 {
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 25/28, incomplete)
// FUN_00278ef0 @ 0x00278ef0

typedef unsigned int uint_278ef0;
struct XboxSaveDrive_278ef0 { char pad[0xb4]; uint_278ef0 error; bool FUN_00278de0(); uint_278ef0 FUN_002787c0(hulk_uintptr); void FUN_002789e0(hulk_uintptr); bool FUN_00278ef0(uint_278ef0 source, uint_278ef0 length, bool flag); };
namespace XAPILIB { extern "C++" __declspec(nothrow) uint_278ef0 __stdcall XCalculateSignatureBegin(uint_278ef0); extern "C++" __declspec(nothrow) hulk_uintptr __stdcall GetLastError(); }
extern "C++" __declspec(nothrow) void __stdcall FUN_002120f5(uint_278ef0, void *, uint_278ef0);
extern "C++" __declspec(nothrow) void __stdcall FUN_00212143(uint_278ef0, void *);
extern "C++" __declspec(nothrow) uint_278ef0 __stdcall FUN_002101d4(uint_278ef0, hulk_uintptr, uint_278ef0, uint_278ef0);
extern "C++" __declspec(nothrow) uint_278ef0 __stdcall FUN_0021007a(uint_278ef0, void *, uint_278ef0, uint_278ef0 *, uint_278ef0);
extern "C++" __declspec(nothrow) bool __cdecl FUN_00278180(void *, uint_278ef0, void *);
struct Signature { uint_278ef0 word[5]; };
bool XboxSaveDrive_278ef0::FUN_00278ef0(uint_278ef0 source, uint_278ef0 length, bool flag) {
 if (!FUN_00278de0()) return false;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 12)) = 0;
 unsigned char *buffer = (*(unsigned char**)&DAT_0052c270);
 for (uint_278ef0 i=0;i<8192;++i) buffer[i]=0;
 uint_278ef0 remaining=length;
 if (flag) *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=length;
 Signature sig;
 if (length>8192) {
  unsigned char *signBuffer=(*(unsigned char**)&DAT_0052c270);
  uint_278ef0 h=XAPILIB::XCalculateSignatureBegin(0);
  if(h==0xffffffff) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
  FUN_002120f5(h,signBuffer,8172);
  FUN_00212143(h,&sig);
  for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+8172))[j]=sig.word[j];
 }
 if(FUN_002101d4(source,0,0,0)) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
 uint_278ef0 count=0, read;
 while(remaining>8192) {
  if(!FUN_0021007a(source,(*(unsigned char**)&DAT_0052c270),8192,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  if(count==0 && flag) {
   *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=0;
   unsigned char *signBuffer=(*(unsigned char**)&DAT_0052c270);
   uint_278ef0 h=XAPILIB::XCalculateSignatureBegin(0);
   if(h==0xffffffff) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
   FUN_002120f5(h,signBuffer,8172);
   FUN_00212143(h,&sig);
   for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+8172))[j]=sig.word[j];
  }
  remaining-=8192;
  ++count;
 }
 if(remaining) {
  *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=0;
  if(!FUN_00278180((*(unsigned char**)&DAT_0052c270),remaining-20,&sig)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+remaining-20))[j]=sig.word[j];
  if(!FUN_0021007a(source,(*(unsigned char**)&DAT_0052c270),remaining,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  ++count;
 }
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 4))=source;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 8))=count-1;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 12))=1;
 return true;
}
} // namespace fn_00278ef0


// 0x00279160 core::XboxSaveDrive::vfunc_7 (181 B): equivalent/0x00279160.cpp [wrapped: conflict: core::XboxSaveDrive]
// sym: ?vfunc_7@XboxSaveDrive@core@fn_00279160@@QAEHXZ @02402191afa8 @w6c85f774cc78
namespace fn_00279160 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 24/24)
// core::XboxSaveDrive::vfunc_7 @ 0x00279160

namespace core {
struct XboxSaveDrive {
 char reserved0[0x60];
 int state;
 char reserved64[0x50];
 int resultState;
 char reservedB8[0x10];
 int active;
 unsigned char marker;
 char reservedCD[6];
 signed char port;
 signed char unit;
 char reservedD5[9];
 unsigned char mode;
 void FUN_00278b50();
 int vfunc_7();
};
}
int core::XboxSaveDrive::vfunc_7() {
 FUN_00278b50();
 if (mode != 0x55) {
  int portIndex = -1;
  int unitIndex = -1;
  if (marker != 0x55) {
   portIndex = port - 0x31;
   unitIndex = unit - 0x41;
  }
  if (portIndex >= 0 && unitIndex >= 0) {
   unsigned char mask = (unsigned char)(1u << ((portIndex + 4 * unitIndex) & 31));
   if (active != 0) {
    if (((*(unsigned char*)&DAT_0052a229) & mask) != 0) {
     int newState = ((*(unsigned char*)&DAT_0052a228) & mask) ? 3 : 4;
     state = newState;
     resultState = newState;
     return false;
    }
   } else {
    (*(unsigned char*)&DAT_0052a229) &= (unsigned char)~mask;
   }
  }
 }
 return resultState == 0;
}
} // namespace fn_00279160

namespace fn_fad5a458 {

// 0x00279220 core::XboxSaveDrive::vfunc_18 (386 B): equivalent/0x00279220.cpp
// sym: ?vfunc_18@XboxSaveDrive@fn_fad5a458@@UAEHPBD0PAHE@Z @0a268eeea4a3 @w228fdd37b97d
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/16, incomplete)
// core::XboxSaveDrive::vfunc_18 @ 0x00279220
int XboxSaveDrive::vfunc_18(const char *name, const char *source, int *index, unsigned char reuse) {
 if (!FUN_002788c0()) return 0;
 char path[0x208]; char output[0x308];
 path[0]=driveLetter; path[1]=':'; path[2]='\\'; path[3]=0;
 FUN_0026b800(path+4,2,name,1,0,0x202,0);
 int slot=-1;
 if (!reuse && slots[*index].handle!=-1) {
  slot=*index;
  if (slots[slot].handle!=-1) { FUN_00356611(slots[slot].handle); slots[slot].handle=-1; }
 } else {
  for (unsigned i=0;i<4;i++) if (slots[i].handle==-1) { slot=i; break; }
 }
 Slot_279220 *s=&slots[slot];
 s->handle=FUN_003564c0(path,output);
 thunk_FUN_00271f20(s->path,path+4,0x202);
 *index=slot;
 int result=FUN_00278d30(source,output,s->handle,s->path);
 if (result==0) return 1;
 if (result==1) { s->handle=-1; return 0; }
 return vfunc_19(index,source);
}

} // namespace fn_fad5a458

// 0x002793b0 core::XboxSaveDrive::vfunc_19 (220 B): equivalent/0x002793b0.cpp [wrapped: conflict: core::XboxSaveDrive]
// sym: ?vfunc_19@XboxSaveDrive@core@fn_002793b0@@QAEHPAHPAX@Z @0010f0e8e662 @wa1cce2c77227
namespace fn_002793b0 {
// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 14/14)
// core::XboxSaveDrive::vfunc_19 @ 0x002793b0
namespace XAPILIB { unsigned long __stdcall GetLastError(); }
extern "C" int __stdcall FUN_003565ca(int handle, void* data);
namespace core {
struct SaveSlot { char name[0x204]; int handle; };
struct XboxSaveDrive {
    char unused[0xb4];
    int state;
    char reserved[0x38];
    SaveSlot slots[1];
    bool FUN_002788c0();
    int FUN_00278d30(void* result, void* data, int handle, void* name);
    int FUN_002787c0(unsigned long error);
    int vfunc_19(int* index, void* result);
};
int XboxSaveDrive::vfunc_19(int* index, void* result) {
    SaveSlot& slot = slots[*index];
    if (slot.handle == -1) {
        state = 1;
        return 0;
    }
    if (!FUN_002788c0()) return 0;
    char data[0x344];
    for (;;) {
        if (FUN_003565ca(slot.handle, data)) {
            int answer = FUN_00278d30(result, data, slot.handle, slot.name);
            if (answer == 2) continue;
            if (answer == 1) return 0;
            if (answer != 0) state = 0;
            return 1;
        }
        unsigned long error = XAPILIB::GetLastError();
        if (error == 0x12) {
            *(unsigned char*)((char*)result + 4) = 0;
            *(int*)result = 2;
            state = 0;
            return 1;
        }
        state = FUN_002787c0(error);
        return 0;
    }
}
}
} // namespace fn_002793b0


// 0x00279490 FUN_00279490 (409 B): equivalent/0x00279490.cpp [wrapped: compile error in a shared declaration (C2556)]
// sym: ?FUN_00279490@XboxSaveDrive_279490@fn_00279490@@QAE_NII@Z @f0ebfa4a2f8a @w268beb5534e7
namespace fn_00279490 {
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 19/20, incomplete)
// FUN_00279490 @ 0x00279490

typedef unsigned int uint_279490;
struct Header_279490 { uint_279490 word[5]; };
struct XboxSaveDrive_279490 {
 char pad[0xb4];
 uint_279490 error;
 unsigned char FUN_00278de0();
 uint_279490 FUN_002787c0(hulk_uintptr);
 void FUN_002789e0(hulk_uintptr);
 bool FUN_00279490(hulk_uintptr, uint_279490);
};
struct Cache_279490 { char *buffer; uint_279490 file; uint_279490 block; uint_279490 valid; };
extern "C++" __declspec(nothrow) uint_279490 __stdcall FUN_002109b6(uint_279490, uint_279490);
extern "C++" __declspec(nothrow) uint_279490 __stdcall FUN_002101d4(uint_279490, hulk_uintptr, uint_279490, uint_279490);
extern "C" uint_279490 __stdcall FUN_0020ff8d(uint_279490, char *, hulk_uintptr, uint_279490 *, uint_279490);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_002781c0(uint_279490, Header_279490 *);
namespace XAPILIB { extern "C++" __declspec(nothrow) hulk_uintptr __stdcall GetLastError(); }
bool XboxSaveDrive_279490::FUN_00279490(hulk_uintptr file, uint_279490 block) {
 if ((*(Cache_279490*)&DAT_0052c270).valid && (*(Cache_279490*)&DAT_0052c270).file == file && (*(Cache_279490*)&DAT_0052c270).block == block) return true;
 uint_279490 length = FUN_002109b6(file, 0);
 if (length == 0xffffffff) { error = FUN_002787c0(XAPILIB::GetLastError()); return false; }
 if (!FUN_00278de0()) return false;
 hulk_uintptr offset = block << 13;
 hulk_uintptr end = offset + 0x2000;
 if (end >= length) end = length;
 hulk_uintptr amount = end - offset;
 hulk_uintptr footer = end - 20;
 (*(Cache_279490*)&DAT_0052c270).valid = 0;
 uint_279490 bytesRead;
 if (FUN_002101d4(file, offset, 0, 0) != offset ||
     !FUN_0020ff8d(file, (*(Cache_279490*)&DAT_0052c270).buffer, amount, &bytesRead, 0)) {
  error = FUN_002787c0(XAPILIB::GetLastError()); return false;
 }
 hulk_uintptr address = (hulk_uintptr)(*(Cache_279490*)&DAT_0052c270).buffer;
 Header_279490 expected = *(Header_279490 *)(address + footer - offset);
 Header_279490 actual;
 (*(Cache_279490*)&DAT_0052c270).file = file;
 (*(Cache_279490*)&DAT_0052c270).block = block;
 if (!FUN_002781c0(length, &actual)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
 for (int i = 0; i < 5; ++i) if (actual.word[i] != expected.word[i]) { error = 12; return false; }
 (*(Cache_279490*)&DAT_0052c270).valid = 1;
 return true;
}
} // namespace fn_00279490


// 0x00279630 core::XboxSaveDrive::vfunc_9 (1205 B): equivalent/0x00279630.cpp [wrapped: conflict: XAPILIB::GetLastError; core::XboxSaveDrive]
// sym: ?vfunc_9@XboxSaveDrive@core@fn_00279630@@UAEHIIEPAUSaveData@3@IPAI1@Z @20e3daf8bff0 @w3a405b8e730e
namespace fn_00279630 {
// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 80/84, incomplete)
// core::XboxSaveDrive::vfunc_9 @ 0x00279630

typedef unsigned int U_279630; typedef unsigned char B_279630;
struct SaveData { U_279630 data; U_279630 length; };
struct Large { U_279630 low, high; };
 
extern void __cdecl FUN_0026b800(unsigned short *,int,U_279630,int,int,int,int);
extern U_279630 __stdcall FUN_0035618d(const char *,const unsigned short *,U_279630,U_279630,char *,U_279630);
extern U_279630 __stdcall FUN_003563f0(const char *,const unsigned short *);
extern int __stdcall FUN_00208b9c(const char *,Large *,Large *,Large *);
extern U_279630 __stdcall FUN_002109f1(const char *,U_279630,U_279630,U_279630,U_279630,U_279630,U_279630);
extern U_279630 __stdcall FUN_002101d4(U_279630,U_279630,U_279630,U_279630);
extern int __stdcall FUN_00210150(U_279630);
extern int __stdcall FUN_0021007a(U_279630,U_279630,U_279630,U_279630 *,U_279630);
extern void __stdcall FUN_0020bbc2(U_279630);
extern U_279630 __cdecl FUN_00278150(U_279630);
namespace XAPILIB { U_279630 __stdcall GetLastError(); }
namespace core { struct XboxSaveDrive {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual U_279630 vfunc_5(SaveData *,U_279630); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(U_279630,U_279630,B_279630,SaveData *,U_279630,U_279630 *,U_279630 *);
char pad[0xb0]; U_279630 error; char pad2[0x10]; U_279630 count; char pad3[0x12]; B_279630 letter; B_279630 pad4; U_279630 handles[4];
B_279630 FUN_002788c0(); U_279630 FUN_002787c0(U_279630); B_279630 FUN_002789e0(U_279630); B_279630 FUN_00278ef0(U_279630,U_279630,B_279630); B_279630 FUN_00278a00(U_279630,U_279630 *); B_279630 FUN_00279490(U_279630,U_279630);
}; }
int core::XboxSaveDrive::vfunc_9(U_279630 name,U_279630 mode,B_279630 writable,SaveData *data,U_279630 size,U_279630 *out,U_279630 *amount) {
 if(!FUN_002788c0()) return 0;
 char drive[4]; char path[260]; unsigned short title[256];
 drive[0]=letter; drive[1]=':'; drive[2]='\\'; drive[3]=0;
 FUN_0026b800(title,2,name,1,0,0x202,0);
 U_279630 access=writable?0xc0000000:0x80000000; U_279630 share=writable?3:1;
 U_279630 status=FUN_0035618d(drive,title,3,0,path,260);
 if(status!=0 && status!=3) {error=FUN_002787c0(status); return 0;}
 U_279630 pathLength=0; while(path[pathLength]) ++pathLength;
 bool changed=status==3 || (mode!=0 && mode!=1);
 if(mode==3) { if(status!=3) { U_279630 e=FUN_002787c0(FUN_003563f0(drive,title)); error=e; if(e) return 0; } }
 else if(mode==0 && status==3) {FUN_002789e0(status); return 0;}
 U_279630 result;
 do {
 if(changed) {
 Large available,total,freeTotal;
 if(!FUN_00208b9c(drive,&available,&total,&freeTotal)) break;
 U_279630 freeBytes=available.high?0xffffffff:available.low;
 if(freeBytes < vfunc_5(data,size)) {error=7; return 0;}
 if(!FUN_002789e0(FUN_0035618d(drive,title,1,0,path,260))) return 0;
 pathLength=0; while(path[pathLength]) ++pathLength;
 if(data->data) {
 const char *p=(*(const char**)&DAT_004ce26c); char *q=path+pathLength; do { *q++=*p; } while(*p++);
 U_279630 h=FUN_002109f1(path,0xc0000000,3,0,2,0x80,0);
 if(h==0xffffffff) break;
 result=0;
 U_279630 pos=FUN_002101d4(h,data->length,0,0);
 if(pos!=data->length || !FUN_00210150(h) || FUN_002101d4(h,0,0,0)!=0 || !FUN_0021007a(h,data->data,data->length,&result,0)) {FUN_0020bbc2(h); break;}
 FUN_0020bbc2(h);
 }
 }
 const char *p=(*(const char**)&DAT_004ce270); char *q=path+pathLength; do {*q++=*p;} while(*p++);
 U_279630 h=FUN_002109f1(path,0xc0000000,3,0,changed?1:3,0x80,0); *out=h;
 if(h==0xffffffff) break;
 if(changed) {
 U_279630 bytes=FUN_00278150(size);
 if(FUN_002101d4(h,bytes,0,0)!=bytes || !FUN_00210150(*out) || !FUN_00278ef0(*out,bytes,!writable)) {FUN_0020bbc2(*out); break;}
 }
 FUN_0020bbc2(*out);
 h=FUN_002109f1(path,access,share,0,3,0x80,0); *out=h;
 if(h==0xffffffff) {FUN_0020bbc2(h); break;}
 if(!FUN_00278a00(h,&result)) {FUN_0020bbc2(*out); return 0;}
 U_279630 savedSize=result;
 if(changed) {for(U_279630 i=0;i<4;++i) if(handles[i]==0xffffffff) {handles[i]=*out; break;}}
 else {
 bool valid=false;
 if(savedSize>=24) {
 if(!FUN_00279490(*out,0)) {FUN_0020bbc2(*out); return 0;}
 valid=(*(*(U_279630**)&DAT_0052c270)==result);
 }
 if(!valid) {FUN_0020bbc2(*out); (*(U_279630*)((char*)&DAT_0052c270 + 12))=0; error=12; return 0;}
 }
 *amount=savedSize-((savedSize+0x2013)/0x2014)*20-4;
 ++count; error=0; return 1;
 } while(false);
 FUN_002789e0(XAPILIB::GetLastError()); return 0;
}
} // namespace fn_00279630


// 0x00279af0 core::XboxSaveDrive::vfunc_11 (182 B): equivalent/0x00279af0.cpp [wrapped: conflict: XAPILIB::GetLastError; core::XboxSaveDrive]
// sym: ?vfunc_11@XboxSaveDrive@core@fn_00279af0@@UAEHPAXH@Z @e4a5f3dba520 @wec23e7781f11
namespace fn_00279af0 {
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// core::XboxSaveDrive::vfunc_11 @ 0x00279af0

namespace core { struct XboxSaveDrive { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual int vfunc_11(void*, int); char pad[0xb4-4]; int error; char pad2[0xe0-0xb8]; unsigned int slots[4]; bool FUN_002788c0(); bool FUN_00278de0(); bool FUN_00279490(void*, int); int FUN_002787c0(unsigned int); }; }
extern "C++" __declspec(nothrow) int __stdcall FUN_002109b6(void*, int);
namespace XAPILIB { unsigned int __stdcall GetLastError(); }
int core::XboxSaveDrive::vfunc_11(void* handle, int unused) {  // an int: 0 or 1 in all of eax (FileCommitRequest::vfunc_1 passes it on)
    if (!FUN_002788c0() || !FUN_00278de0()) return 0;
    unsigned int i;
    for (i = 0; i < 4; ++i) if (slots[i] == (*(unsigned int*)((char*)&DAT_0052c270 + 4))) break;
    if (i < 4) {
        if (!FUN_00279490(handle, 0)) return 0;
        int result = FUN_002109b6(handle, 0);
        if (result == -1) { error = FUN_002787c0(XAPILIB::GetLastError()); return 0; }
        *(*(int**)&DAT_0052c270) = result;
        (*(int*)((char*)&DAT_0052c270 + 12)) = 2;
        if (!FUN_00278de0()) return 0;
        slots[i] = -1;
    }
    error = 0;
    return 1;
}
} // namespace fn_00279af0

namespace fn_fad5a458 {

// 0x00279bb0 core::XboxSaveDrive::vfunc_0_adjbc (152 B): equivalent/0x00279bb0.cpp
// sym: ?vfunc_0_adjbc@AdjBC@fn_fad5a458@@QAEHPBXIIIIPAXI@Z @8a3261a81c49 @w0602b8ab673f
// STATUS: equivalent (tools/equiv.py level 3: 635 inputs, branch coverage 8/8)
// core::XboxSaveDrive::vfunc_0_adjbc @ 0x00279bb0
int AdjBC::vfunc_0_adjbc(const void *name, unsigned int unused, unsigned int block, unsigned int offset, unsigned int size, void *destination, unsigned int extra)
{
    XboxSaveDrive *drive = (XboxSaveDrive *)((char *)this - 0xbc);
    if (!drive->FUN_002788c0()) return 0;
    int result = FUN_002109b6(name, 0);
    if (result == -1) {
        drive->error = drive->FUN_002787c0(XAPILIB::GetLastError());
        return 0;
    }
    if ((block << 13) < (unsigned int)result) {
        if (!drive->FUN_00279490(name, block)) return 0;
        unsigned char *src = (*(unsigned char**)&DAT_0052c270) + offset;
        memcpy(destination, src, size);
    }
    drive->error = 0;
    return 1;
}

} // namespace fn_fad5a458

// 0x00279c50 core::XboxSaveDrive::vfunc_0_adjc0 (197 B): equivalent/0x00279c50.cpp [wrapped: conflict: XboxSaveDrive]
// sym: ?vfunc_0_adjc0@SaveWriter@fn_00279c50@@QAEHPAXH0IIPBXPAHH@Z @eab393483749 @w27e7c56a8ca7
namespace fn_00279c50 {
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 6/6)
// core::XboxSaveDrive::vfunc_0_adjc0 @ 0x00279c50

typedef unsigned int uint;
extern int __stdcall FUN_002109b6(void*, int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned);
#endif

namespace XAPILIB { extern unsigned long __stdcall GetLastError(); }
struct XboxSaveDrive;
struct SaveWriter {
    int vfunc_0_adjc0(void* path, int unused, void* data, unsigned offset, unsigned length, const void* source, int* result, int unused2);
};
struct XboxSaveDrive {
    char pre[0xb4];
    int error;
    char middle[8];
    SaveWriter writer;
    bool FUN_002788c0();
    int FUN_002787c0(unsigned long);
    bool FUN_00279490(void*, void*);
};
int SaveWriter::vfunc_0_adjc0(void* path, int unused, void* data, unsigned offset, unsigned length, const void* source, int* result, int unused2) {
    XboxSaveDrive* drive = (XboxSaveDrive*)((char*)this - 0xc0);
    if (!drive->FUN_002788c0()) return 0;
    int value = FUN_002109b6(path, 0);
    if (value == -1) {
        drive->error = drive->FUN_002787c0(XAPILIB::GetLastError());
        return 0;
    }
    if (!drive->FUN_00279490(path, data)) return 0;
    (*(int*)((char*)&DAT_0052c270 + 12)) = 0;
    memcpy((*(unsigned char**)&DAT_0052c270) + offset, source, length);
    unsigned n = (unsigned)value + 0x2013;
    unsigned quotient = (unsigned)(((unsigned __int64)n * 0x7fb031e1) >> 44);
    (*(int*)((char*)&DAT_0052c270 + 12)) = 2;
    *result = value - quotient * 20;
    drive->error = 0;
    return 1;
}
} // namespace fn_00279c50

namespace fn_fad5a458 {

// 0x00279d30 FUN_00279d30 (540 B): equivalent/0x00279d30.cpp
// sym: ?FUN_00279d30@fn_fad5a458@@YAPAEPAEI0II@Z @8f2492fee067 @w396fac723073
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 55/56, incomplete)
// FUN_00279d30 @ 0x00279d30
Byte_279d30* __cdecl FUN_00279d30(Byte_279d30* input, unsigned int unused, Byte_279d30* output, unsigned int limit, hulk_uintptr fullSize)
{
    unsigned int written = 0;
    if (!limit) return (Byte_279d30*)fullSize;
    if (limit == fullSize) {
        do {
            unsigned int token = *input++;
            if (token > 15) {
                unsigned int length = token & 15;
                if (!length) {
                    length = 15;
                    while (*input == 0) { length += 255; ++input; }
                    length += *input++;
                }
                unsigned int distance = (token >> 4) | ((unsigned int)*input++ << 4);
                Byte_279d30* source = output - distance;
                int groups = (int)length >> 2;
                unsigned int remainder = length - groups * 4;
                do {
                    for (int i=0; i<4; ++i) *output++ = *source++;
                    written += 4;
                } while (--groups);
                written += remainder;
                while (remainder--) *output++ = *source++;
            } else {
                unsigned int length = token;
                if (!length) {
                    while (*input == 0) { length += 255; ++input; }
                    length += *input++;
                    for (int i=0; i<15; ++i) *output++ = *input++;
                    written += 15;
                }
                do { *output++ = *input++; ++written; } while (--length);
            }
        } while (written < limit);
        return output;
    }
    unsigned int bound = limit;
    do {
        unsigned int token = *input++;
        if (token > 15) {
            unsigned int length = token & 15;
            if (!length) {
                length = 15;
                while (*input == 0) { length += 255; ++input; }
                length += *input++;
            }
            unsigned int distance = (token >> 4) | ((unsigned int)*input++ << 4);
            Byte_279d30* source = output - distance;
            unsigned int remaining = bound - written;
            if ((int)length > (int)remaining) length = remaining;
            if (length) {
                written += length;
                do { *output++ = *source++; } while (--length);
                bound = limit;
            }
        } else {
            unsigned int length = token;
            if (!length) {
                length = 15;
                while (*input == 0) { length += 255; ++input; }
                length += *input++;
            }
            unsigned int remaining = bound - written;
            if ((int)length > (int)remaining) length = remaining;
            do { *output++ = *input++; ++written; } while (--length);
            bound = limit;
        }
    } while (written < bound);
    return input;
}


// 0x00279f80 FUN_00279f80 (205 B): equivalent/0x00279f80.cpp
// sym: ?FUN_00279f80@fn_fad5a458@@YAEIPBEIPAI1PAUTree_279f80@1@@Z @4524f8ddcfdd @w92ded2419651
// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 12/14, incomplete)
// FUN_00279f80 @ 0x00279f80
// equiv-conv: FUN_00279f80 ecx stack stack stack stack stack
unsigned char FUN_00279f80(unsigned int end, const unsigned char *data, unsigned int position, unsigned int *offset, unsigned int *length, Tree_279f80 *tree)
{
    unsigned int current = tree->nodes[tree->root].right;
    unsigned int count = end - position;
    unsigned char aligned = 0;
    *length = 0;
    for (;;) {
        int difference = 0;
        unsigned int matched = 0;
        while (matched < count) {
            difference = (int)data[position + matched] - (int)data[current + matched];
            if (difference != 0) break;
            ++matched;
        }
        if (matched > *length) {
            unsigned int distance = position - current;
            if ((distance & 15) == 0) aligned = 1;
            else { *length = matched; *offset = distance; }
        }
        unsigned int *link = difference < 0 ? &tree->nodes[current].left : &tree->nodes[current].right;
        unsigned int next = *link;
        if (next != 0xffffffffU) { current = next; continue; }
        *link = position;
        tree->nodes[position].parent = current;
        tree->nodes[position].right = 0xffffffffU;
        tree->nodes[position].left = 0xffffffffU;
        return aligned;
    }
}

} // namespace fn_fad5a458

// 0x0027a050 FUN_0027a050 (146 B): equivalent/0x0027a050.cpp [wrapped: compile error C2556: 'unsigned int *fn_fad5a458::FUN_0027a050(unsigned int,const unsigned char *,unsigned int,unsigned int *,unsigned int *)']
// sym: ?FUN_0027a050@fn_0027a050@@YAPAIIPBEIPAI1@Z @2d39a1b9a1cb @w0e3d6cc7d375
namespace fn_0027a050 {
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 15/16, incomplete)
// FUN_0027a050 @ 0x0027a050
// equiv-conv: FUN_0027a050 ecx stack stack stack stack
unsigned int* __cdecl FUN_0027a050(unsigned int distance, const unsigned char* data, unsigned int size, unsigned int* position, unsigned int* length)
{
    *position = 0;
    *length = 0;
    for (unsigned int offset = 0; offset < distance; ++offset) {
        if (((offset - distance) & 15) == 0) continue;
        unsigned int limit = size - offset;
        if (limit == 0) continue;
        unsigned int i = 0;
        do {
            unsigned int next = i + 1;
            if (distance + next - 1 >= size) break;
            if (data[offset + i] != data[distance + i]) break;
            if (next > *length) {
                *length = next;
                *position = offset;
            }
            i = next;
        } while (i < limit);
    }
    *position = distance - *position;
    return position;
}
} // namespace fn_0027a050

namespace fn_fad5a458 {

// 0x0027a0f0 FUN_0027a0f0 (97 B): equivalent/0x0027a0f0.cpp
// sym: ?FUN_0027a0f0@fn_fad5a458@@YAIIIPAE@Z @90480dd28f04 @w66c8812c6783
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 5/6, incomplete)
// FUN_0027a0f0 @ 0x0027a0f0
// equiv-conv: FUN_0027a0f0 ecx eax esi
unsigned int FUN_0027a0f0(unsigned int length, unsigned int tag, unsigned char *output)
{
    if (length <= 15) {
        output[0] = (unsigned char)(length | tag);
        return 1;
    }
    unsigned int remainder = length - 15;
    output[0] = (unsigned char)tag;
    unsigned int index = 1;
    if (remainder > 255) {
        unsigned int zeros = (remainder - 256) / 255 + 1;
        for (unsigned int i = 0; i < zeros; ++i)
            output[1 + i] = 0;
        index = zeros + 1;
        remainder -= zeros * 255;
    }
    output[index] = (unsigned char)remainder;
    return index + 1;
}

} // namespace fn_fad5a458

// 0x0027a160 FUN_0027a160 (522 B): equivalent/0x0027a160.cpp [wrapped: compile error C2440: '=' : cannot convert from 'fn_fad5a458::U_27a160 (__cdecl *)(fn_fad5a458::U_27a160,const unsigned char *,fn_fad5a458::U_]
// sym: ?FUN_0027a160@fn_0027a160@@YAXPBEIPAEPAIIPAUTable_27a160@1@E@Z @0fb4ca9e5fbe @w06414c4ae207
namespace fn_0027a160 {
// STATUS: equivalent (tools/equiv.py level 3: 3074 inputs, branch coverage 23/24, incomplete)
// FUN_0027a160 @ 0x0027a160
// FUN_0027a160 @ 0x0027a160
typedef unsigned int U_27a160;
struct Table_27a160 { U_27a160 size; U_27a160 *entries; };
// equiv-conv: FUN_0027a0f0 ecx eax esi
U_27a160 FUN_0027a0f0(U_27a160 count, U_27a160 tag, unsigned char *dst);
// equiv-conv: FUN_00279f80 ecx stack stack stack stack stack
U_27a160 FUN_00279f80(U_27a160 length, const unsigned char *src, U_27a160 position, U_27a160 *distance, U_27a160 *run, Table_27a160 *table);
// equiv-conv: FUN_0027a050 ecx stack stack stack stack
U_27a160 FUN_0027a050(U_27a160 position, const unsigned char *src, U_27a160 length, U_27a160 *distance, U_27a160 *run);
void __cdecl FUN_0027a160(const unsigned char *src, U_27a160 length, unsigned char *dst, U_27a160 *written, U_27a160 tableSize, Table_27a160 *table, unsigned char fast) {
 table->size=tableSize; table->entries=(U_27a160 *)(table+1);
 table->entries[tableSize*3+2]=0; table->entries[0]=tableSize;
 table->entries[2]=~0U; table->entries[1]=~0U;
 U_27a160 position=0, output=0, start=0, literals=0, distance, run=0, state=~0U;
 if (!length) { *written=0; return; }
 for (;;) {
  if (run>4 && (distance&15)!=0) {
   if (literals) {
    output+=FUN_0027a0f0(literals, state&~255U, dst+output);
    U_27a160 j=0;
    for (;j+4<=literals;j+=4) *(U_27a160 *)(dst+output+j)=*(const U_27a160 *)(src+start+j);
    for (;j<literals;++j) dst[output+j]=src[start+j];
    output+=literals; state=literals;
   }
   output+=FUN_0027a0f0(run, (state&~255U)|((distance<<4)&255), dst+output);
   dst[output++]=(unsigned char)(distance>>4);
   state=run;
   if (fast) position+=run;
   else { U_27a160 remaining=run; if(remaining) do { ++position; state=FUN_00279f80(length,src,position,&distance,&run,table); } while (--remaining); }
   literals=0; start=position;
   if (fast) state=FUN_00279f80(length,src,position,&distance,&run,table);
  } else {
   ++literals; ++position;
   state=FUN_00279f80(length,src,position,&distance,&run,table);
   if (!fast && (unsigned char)state) state=FUN_0027a050(position,src,length,&distance,&run);
  }
  if (position>=length) break;
 }
 if(literals) {
  U_27a160 n=literals; output+=FUN_0027a0f0(n, n&~255U, dst+output);
  U_27a160 j=0;
  for(;j+4<=n;j+=4) *(U_27a160 *)(dst+output+j)=*(const U_27a160 *)(src+start+j);
  for(;j<n;++j) dst[output+j]=src[start+j];
  output+=n;
 }
 *written=output;
}
} // namespace fn_0027a160

namespace fn_fad5a458 {

// 0x0027a370 FUN_0027a370 (233 B): equivalent/0x0027a370.cpp
// sym: ?FUN_0027a370@Stream@fn_fad5a458@@QAEHIIIIIIPAII@Z @38a3b04d22e6 @w78930d5d1ca6
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 14/14)
// FUN_0027a370 @ 0x0027a370
int Stream::FUN_0027a370(hulk_uintptr unused, uint_27a370 key, uint_27a370 mode, uint_27a370 start, uint_27a370 destination, uint_27a370 count, uint_27a370* completed, uint_27a370 flags) {
 uint_27a370 size = blockSize();
 uint_27a370 position = baseOffset(key) + start;
 uint_27a370 block = position / size;
 hulk_uintptr offset = position - FUN_0026fd80(position, size);
 hulk_uintptr amount = size - offset;
 if (amount >= count) amount = count;
 int result = transfer(key, mode, block, offset, amount, destination, flags);
 if (result != 1) return result;
 hulk_uintptr remaining = count - amount;
 ++block;
 hulk_uintptr dest = destination + amount;
 while (remaining >= size) {
  result = transfer(key, mode, block, 0, size, dest, flags);
  if (result != 1) return result;
  remaining -= size;
  ++block;
  dest += size;
 }
 if (remaining != 0) {
  result = transfer(key, mode, block, 0, remaining, dest, flags);
  if (result != 1) return result;
 }
 *completed = count;
 return 1;
}

} // namespace fn_fad5a458

// 0x0027a460 FUN_0027a460 (246 B): equivalent/0x0027a460.cpp [wrapped: conflict: Stream]
// sym: ?process@Stream@fn_0027a460@@QAEHIIIIIIPAIII@Z @373dc5b2c695 @w1e1188523c72
namespace fn_0027a460 {
// STATUS: equivalent (tools/equiv.py level 3: 732 inputs, branch coverage 14/14; run with --inputs 12000)
// FUN_0027a460 @ 0x0027a460
typedef unsigned int uint_27a460;
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr position, uint_27a460 blockSize);
struct Stream {
    virtual int transfer(uint_27a460 handle, uint_27a460 mode, uint_27a460 block, uint_27a460 offset, uint_27a460 count, uint_27a460 destination, uint_27a460 flags, uint_27a460 context);
    virtual uint_27a460 blockSize();
    virtual uint_27a460 baseOffset(uint_27a460 handle);
    int process(hulk_uintptr unused, uint_27a460 handle, uint_27a460 mode, uint_27a460 offset, uint_27a460 destination, uint_27a460 count, uint_27a460* result, uint_27a460 flags, uint_27a460 context);
};
int Stream::process(hulk_uintptr unused, uint_27a460 handle, uint_27a460 mode, uint_27a460 offset, uint_27a460 destination, uint_27a460 count, uint_27a460* result, uint_27a460 flags, uint_27a460 context) {
    uint_27a460 size = blockSize();
    uint_27a460 position = baseOffset(handle) + offset;
    uint_27a460 block = position / size;
    hulk_uintptr start = position - FUN_0026fd80(position, size);
    hulk_uintptr amount = size - start;
    if (amount >= count) amount = count;
    int status = transfer(handle, mode, block, start, amount, destination, flags, context);
    if (status != 1) return status;
    hulk_uintptr remaining = count - amount;
    ++block;
    hulk_uintptr dest = destination + amount;
    while (remaining >= size) {
        status = transfer(handle, mode, block, 0, size, dest, flags, context);
        if (status != 1) return status;
        remaining -= size;
        ++block;
        dest += size;
    }
    if (remaining != 0) {
        status = transfer(handle, mode, block, 0, remaining, dest, flags, context);
        if (status != 1) return status;
    }
    *result = count;
    return 1;
}
} // namespace fn_0027a460


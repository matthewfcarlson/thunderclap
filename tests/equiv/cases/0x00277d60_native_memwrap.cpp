// STATUS: equivalent (tools/equiv.py --wine level 3)
// (integ2, D78, memwrap) fuzzed pointers make memcpy(0, 0xffffffe6, 0x66): an overlap that wraps around address 0, which
// the original's rep movsd copies forward like any other overlap (memfwd).
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
 // (x64t12) the device's read (slot 12): the handle, the file's name, ..., the position, the buffer, the count
 virtual int slot12(unsigned int a, const char* b, unsigned int c, unsigned int offset, void* d, unsigned int e, unsigned int* result, unsigned int f);
};
// (x64t12) core::File's view of its cement library entry (records.h CoreFileView): the library, then its words
struct Object {
 void* field0;
 unsigned int base;
 unsigned int position;
 unsigned int fieldC;
 unsigned int end;
 unsigned int state;
 int FUN_00277d00(Interface_277d00* target, unsigned int a, const char* b, unsigned int c, unsigned int offset, void* d, unsigned int e, unsigned int* result, unsigned int f);
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
struct Reader { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual int read(U_277d60,const char*,U_277d60,U_277d60,void*,U_277d60,U_277d60*,U_277d60); };
// (x64t12) records.h CoreFileView: the library, the entry's offset in the archive (a file position), ..., the shared buffer
struct State_277d60 { void* unknown; U_277d60 source; U_277d60 total; U_277d60 size; U_277d60 position; U_277d60 skip; U_277d60 sourceSize; U_277d60 unused; U_277d60 alignment; char* buffer; U_277d60 capacity;
int target(Reader* reader,U_277d60 a2,const char* a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9);
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
// sym: ?FUN_00277d00@Object@fn_fad5a458@@QAEHPAUInterface_277d00@2@IPBDIIPAXIPAII@Z @f70145dd03b0 @w4575482bbc53 @v98c5ed87d104
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00277d00 @ 0x00277d00
int Object::FUN_00277d00(Interface_277d00* target, unsigned int a, const char* b, unsigned int c, unsigned int offset, void* d, unsigned int e, unsigned int* result, unsigned int f) {
 int status = target->slot12(a,b,c,base+offset,d,e,result,f);
 unsigned int value = *result + offset;
 position = value;
 end = value;
 state = 0;
 return status;
}


// 0x00277d60 FUN_00277d60 (683 B): equivalent/0x00277d60.cpp
// sym: ?target@State_277d60@fn_fad5a458@@QAEHPAUReader@2@IPBDIIPADIPAII@Z @2ff50b72b51d @w22a5f48e02a1
// STATUS: equivalent (tools/equiv.py level 3: 526 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_00277d60 @ 0x00277d60
int State_277d60::target(Reader* reader,U_277d60 a2,const char* a3,U_277d60 a4,U_277d60 start,char* dest,U_277d60 requested,U_277d60* result,U_277d60 a9) {
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
 int status=reader->read(a2,a3,a4,(U_277d60)(source+aligned+carry),buffer+carry,amount,&readResult,1);
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


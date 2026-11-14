// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00334940..0x00335270 (kind game, layer platform/xbox, confidence high), dominant class movie::BinkCallback
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/movie.h"
#define TREE_TU_BEGIN namespace fn_f8921c09 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8921c09 {} using namespace fn_f8921c09;
#include "platform/xbox/movie.h"

// ---- declarations shared by the functions below
namespace fn_f8921c09 {
class Thing_334940 {
  public:
    virtual void F(int);
};
typedef unsigned int U_334960;
} // namespace fn_f8921c09
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
#endif
namespace fn_f8921c09 {
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,U_334960);
extern hulk_uintptr __cdecl FUN_0026fd80(hulk_uintptr,U_334960);
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void read(void*,U_334960,U_334960); virtual void s10(); virtual void seek(U_334960); virtual void tell(U_334960*); virtual void s13(); virtual void s14(); virtual void s15(); virtual U_334960 block(); };
struct State_334960 { char pad[0x3c]; U_334960 limit; U_334960 unused40; U_334960 available; U_334960 unused48; Stream* stream; U_334960 end; U_334960 position; U_334960 consumed; };
class Item {
  public:
    char pad[0x1c];
    void* a;
    void* b;
};
extern "C" void __cdecl check();
struct Owner_334c00 {
// equiv-conv: FUN_00334b00 esi
    void FUN_00334b00();
};
struct State {
    char unused[0x20];
    void *pending;
    char rest[0x5c];
    unsigned char processing;
};
void __cdecl helper(void*, int);
class Obj {
  public:
    virtual void f0();
    virtual void f1();
};
class Thing {
    char a[0x20];

  public:
    Obj* p;
    char b[0x4c - 0x24];
    Obj* q;
    char c[0x80 - 0x50];
    unsigned char flag;
};
void thunk();
struct Device_334fa0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(int);
};
extern void __cdecl FUN_00334960();
extern void __cdecl FUN_00334c70();
extern void __cdecl FUN_00334ef0();
extern void __cdecl FUN_00334f10();
extern void __cdecl FUN_00334c00();
extern void __cdecl FUN_00334f60();
struct State_334fa0 { void (__cdecl *callbacks[6])(); unsigned int reserved[13]; Device_334fa0* device; unsigned int rest[59]; };
extern void __cdecl thunk_FUN_00271230(Device_334fa0**,unsigned int,int,int,int,int,int,int);
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
struct Callback_3350f0 {
    volatile hulk_intptr a;
    volatile int b;
    volatile hulk_intptr c;
    volatile int d;
};
extern void __fastcall helper(Callback_3350f0*);
class IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class NonCopyable : public IRefCount {
  public:
    virtual void vfunc_0();
};
namespace core {
class ControllerXBox {
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
    int refCount;
};
}
typedef unsigned char u8_335160;
extern char refvt_335160, basevt;
void __cdecl cleanup(int, void*);
namespace movie {
class BinkCallback {
  public:
    void* vptr;
    int m;
    void* refptr;
    BinkCallback* vfunc_0(u8_335160 flag);
};
}
// (x64t11) the allocator and core::Object's 0x002705f0 by their own C names (were `Allocate` / `Init`: names the
// native link has no address for)
extern "C" void* FUN_00266e00(int heap, int size);
extern "C" int* __cdecl FUN_002705f0();
// movie::BinkCallback's words (core::Object's vftable and heap, the IFileCompletionCallback
// vftable, f_0c), 0x10 bytes on the 32-bit builds and 0x20 natively
struct Callback_3351a0 {
    hulk_uintptr vtable;
    unsigned int arg;
    hulk_uintptr subVtable;
    unsigned int field;
};


// 0x00334940 FUN_00334940 (27 B): matches/0x00334940.cpp
// sym: _FUN_00334940
// Same code shape as 0x0029c3b0 (propagated; names are from that function)
// data: gThing_334940 = DAT_00555ba8
extern "C" void FUN_00334940() {
    if ((*(Thing_334940**)&DAT_00555ba8))
        (*(Thing_334940**)&DAT_00555ba8)->F(1);
    (*(Thing_334940**)&DAT_00555ba8) = 0;
}


// 0x00334960 FUN_00334960 (406 B): equivalent/0x00334960.cpp
// sym: ?FUN_00334960@fn_f8921c09@@YGIPAUState_334960@1@IPAEI@Z @f573a6aef720 @w66c21271d61b
// STATUS: equivalent (tools/equiv.py level 3: 1382 inputs, branch coverage 16/16)
// FUN_00334960 @ 0x00334960
U_334960 __stdcall FUN_00334960(State_334960* state,U_334960 position,unsigned char* destination,U_334960 remaining) {
 struct Frame { volatile U_334960 block; U_334960 total; unsigned char* destination; U_334960 readSize,capacity; unsigned char* aligned; U_334960 actual; unsigned char scratch[1040]; } f;
 if(position != 0xffffffffU && state->position != position) state->position=position;
 U_334960 initialBlock=state->stream->block(); if(initialBlock>1024) initialBlock=1024; f.block=initialBlock;
 f.aligned=(unsigned char*)FUN_0026fd50((hulk_uintptr)f.scratch,16);
 f.capacity=FUN_0026fd80((hulk_uintptr)(f.scratch+1040)-(hulk_uintptr)f.aligned,initialBlock);
 f.destination=destination; f.total=0;
 U_334960 currentBlock=initialBlock;
 while(remaining) {
 hulk_uintptr start=FUN_0026fd80(state->position,currentBlock);
 hulk_uintptr offset=state->position-start;
 hulk_uintptr count=f.capacity-offset;
 f.readSize=f.capacity;
 if(remaining<f.capacity) { count=remaining; f.readSize=FUN_0026fd50(offset+remaining,f.block); }
 state->stream->seek(start); state->stream->read(f.aligned,f.readSize,1); state->stream->tell(&f.actual);
 if(f.actual-start!=f.readSize) return 0;
 U_334960 total=f.total;
 memcpy(f.destination,f.aligned+offset,count);
 f.destination=f.destination+count; remaining-=count; state->position+=count; state->consumed=state->position; f.total=total+count;
 currentBlock=f.block;
 }
 U_334960 available=state->end-state->consumed; if(available>=state->limit) available=state->limit; state->available=available; return f.total;
}

} // namespace fn_f8921c09

// 0x00334b00 FUN_00334b00 (249 B): equivalent/0x00334b00.cpp [wrapped: conflict: Stream]
// sym: ?FUN_00334b00@Owner_334b00@fn_00334b00@@QAEXXZ @2dcab71b7ac7 @wd90c64559dc5
namespace fn_00334b00 {
// STATUS: equivalent (tools/equiv.py level 3: 11840 inputs, branch coverage 16/16; run with --inputs 12000)
// FUN_00334b00 @ 0x00334b00

extern unsigned int __cdecl FUN_00368660();
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr, unsigned int);
struct GlobalData { char pad[8]; char data; };
struct Owner_334b00;
struct Stream {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void slot3(unsigned int, unsigned int, unsigned int);
 virtual void slot4(); virtual void slot5(unsigned int);
 virtual void slot6(unsigned int *);
 virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual unsigned int slot16(); virtual void slot17();
 virtual void slot18(void *, Owner_334b00 *);
};
struct Owner_334b00 {
 char pad0[0x20]; unsigned int busy;
 char pad24[4]; unsigned int id;
 char pad2c[0x18]; unsigned int previous;
 unsigned int current; Stream *stream;
 unsigned int total; unsigned int offset;
 unsigned int position; unsigned int result;
 hulk_uintptr transfer; char pad64[0xc];
 unsigned int source; unsigned int capacity;
 unsigned int savedId; unsigned int timestamp;
 unsigned char flag; char pad81[3]; unsigned int residue;
 void FUN_00334b00();
};
// equiv-conv: FUN_00334b00 esi
void Owner_334b00::FUN_00334b00() {
 if (flag == 1 || busy != 0) return;
 unsigned int remaining = offset < total ? total - offset : 0;
 hulk_uintptr size = 0x4000;
 if (capacity < size || remaining == 0) {
  previous = current;
  return;
 }
 savedId = id;
 timestamp = FUN_00368660();
 busy = 1;
 if (remaining > size) transfer = size;
 else {
  transfer = remaining;
  size = FUN_0026fd50(remaining, stream->slot16());
 }
 unsigned int oldOffset = offset;
 unsigned int alignment = stream->slot16();
 unsigned int remainder = oldOffset % alignment;
 if (remainder) {
  residue = remainder;
  offset = oldOffset - remainder;
  position -= remainder;
 }
 stream->slot5(offset);
 stream->slot3(source, size, 1);
 stream->slot6(&result);
 if ((*(GlobalData**)&DAT_00555ba8)) stream->slot18(&(*(GlobalData**)&DAT_00555ba8)->data, this);
 else stream->slot18(0, this);
}
} // namespace fn_00334b00

namespace fn_f8921c09 {

// 0x00334c00 FUN_00334c00 (49 B): equivalent/0x00334c00.cpp
// sym: ?target@fn_f8921c09@@YGPAXPAVItem@1@@Z @bd66382acfd2 @w13a6f8514fb8
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_00334c00 @ 0x00334c00
// equiv-conv: FUN_00334b00 esi
void* __stdcall target(Item* p) {
    if (p->a)
        return 0;
    if (p->b) {
        check();
        if (!p->b)
            ((Owner_334c00*)p)->FUN_00334b00();
    } else
        ((Owner_334c00*)p)->FUN_00334b00();
    return p->b;
}


// 0x00334c40 FUN_00334c40 (36 B): equivalent/0x00334c40.cpp
// sym: _FUN_00334c40 @73773fc5af82 @w1569518e9471
// STATUS: equivalent (tools/equiv.py level 3: 2390 inputs, branch coverage 4/4)
// FUN_00334c40 @ 0x00334c40
// equiv-conv: FUN_00334c40 esi
extern "C" void FUN_00334c40(void *state) {
    ((State *)state)->processing = 1;
    while (((State *)state)->pending != 0) {
        thunk_FUN_00270a50();
    }
    ((State *)state)->processing = 0;
}

} // namespace fn_f8921c09

// 0x00334c70 FUN_00334c70 (628 B): equivalent/0x00334c70.cpp [wrapped: macros]
// sym: ?target@fn_00334c70@@YGIPAUState_334c70@1@IIPAEI@Z @06e30ca3e953 @wd24f68a71df5
namespace fn_00334c70 {
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 36/36; Wine build 644 inputs, 35/36)
// FUN_00334c70 @ 0x00334c70
typedef unsigned int U_334c70;
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void read(void*,U_334c70,U_334c70); virtual void s10(); virtual void seek(U_334c70); virtual void tell(U_334c70*); };
struct State_334c70 { char p0[0x1c]; U_334c70 error; U_334c70 idle; U_334c70 bytes; char p28[4]; U_334c70 readTime; U_334c70 totalTime; char p34[8]; U_334c70 capacity; char p40[4]; U_334c70 desired; U_334c70 available; Stream* stream; U_334c70 end; U_334c70 bufferedEnd; U_334c70 position; char p5c[8]; U_334c70 base; U_334c70 limit; hulk_uintptr cursor; U_334c70 other; U_334c70 consumed; char p78[12]; hulk_uintptr skip; };
U_334c70 __cdecl FUN_00368660();
// equiv-conv: FUN_00334c40 esi
extern "C++" void __cdecl FUN_00334c40(void *);
// FUN_00334b00's definition is a member (`Owner_334b00::FUN_00334b00()`, its own note: esi): the Wine build compiles it
// as a thiscall, so clang's call passes the state in ecx (a cdecl call would push it: wine_conv_check check 9). MSVC
// mode keeps the original's register note.
#if defined(__clang__)
struct Owner_334c70 { void FUN_00334b00(); };
#define CALL_334B00(s) (((Owner_334c70*)(s))->FUN_00334b00())
#else
// equiv-conv: FUN_00334b00 esi
void FUN_00334b00(State_334c70*);
#define CALL_334B00(s) FUN_00334b00(s)
#endif
void __cdecl thunk_FUN_00270a50();
U_334c70 __stdcall target(State_334c70* s,U_334c70 unused,U_334c70 position,unsigned char* out,U_334c70 count) {
 if(s->error) return 0;
 U_334c70 start=FUN_00368660(), total=0;
 if(position!=~0u && s->position!=position) {
  if(s->position<position && s->bufferedEnd>=position) {
   U_334c70 delta=position-s->position; s->position=position; s->consumed+=delta; s->available-=delta;
   if(s->cursor>s->limit) s->cursor-=s->capacity;
  } else { FUN_00334c40((State_334c70 *)s); s->bufferedEnd=position; s->position=position; s->consumed=s->capacity; s->available=0; s->other=s->base; s->cursor=s->base; }
 }
 U_334c70 finish;
 if(!s->base) {
  U_334c70 t=FUN_00368660(); s->stream->seek(s->bufferedEnd); s->stream->read(out,count,1); U_334c70 current=position; s->stream->tell(&current);
  U_334c70 n=current-s->bufferedEnd; if(n<count) s->error=1; s->bufferedEnd=current; s->position=current; s->bytes+=n; total=n;
  finish=FUN_00368660(); s->readTime+=finish-t;
 } else {
  while(count && !s->error) {
   if(s->idle) thunk_FUN_00270a50();
   CALL_334B00(s);
   if(s->available) {
    hulk_uintptr n=s->available-s->skip; if(n>count)n=count;
    count-=n; s->position+=s->skip+n; total+=n;
    hulk_uintptr first=s->limit-s->skip-s->cursor;
    if(first<=n) {
     unsigned char* src=(unsigned char*)(s->cursor+s->skip);
     U_334c70 i; for(i=0;i<first/4;i++) ((U_334c70*)out)[i]=((U_334c70*)src)[i]; for(i=first&~3u;i<first;i++)out[i]=src[i];
     s->cursor=s->base; s->available-=s->skip+first; out+=first; n-=first; s->consumed+=s->skip+first; s->skip=0;
    }
    if(n) {
     unsigned char* src=(unsigned char*)(s->cursor+s->skip);
     U_334c70 i; for(i=0;i<n/4;i++) ((U_334c70*)out)[i]=((U_334c70*)src)[i]; for(i=n&~3u;i<n;i++)out[i]=src[i];
     s->cursor+=s->skip+n; s->available-=s->skip+n; out+=n; s->consumed+=s->skip+n; s->skip=0;
    }
   }
  }
  finish=FUN_00368660();
 }
 s->totalTime+=finish-start;
 U_334c70 wanted=s->end-s->position; if(wanted>=s->capacity)wanted=s->capacity; s->desired=wanted;
 if(s->available+0x4000u>s->desired)s->desired=s->available;
 return total;
}
} // namespace fn_00334c70
#undef CALL_334B00

namespace fn_f8921c09 {

// 0x00334ef0 FUN_00334ef0 (21 B): matches/0x00334ef0.cpp
// sym: ?FUN_00334ef0@fn_f8921c09@@YGXHPAX@Z
void __stdcall FUN_00334ef0(int unused, void* p) {
    helper(p, 0x4000);
}

} // namespace fn_f8921c09

// 0x00334f10 FUN_00334f10 (75 B): equivalent/0x00334f10.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: ?FUN_00334f10@fn_00334f10@@YGXPAUState@1@IIII@Z @dab5122554bf @w4a5da39202e6
namespace fn_00334f10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00334f10 @ 0x00334f10
struct State {
    char unused0[0x3c];
    unsigned int value3c;
    char unused1[0x48-0x40];
    unsigned int value48;
    char unused2[0x50-0x4c];
    unsigned int value50;
    char unused3[0x64-0x54];
    unsigned int value64;
    unsigned int value68;
    unsigned int value6c;
    unsigned int value70;
    unsigned int value74;
    char unused4[0x80-0x78];
    unsigned char value80;
    char unused5[3];
    unsigned int value84;
};
extern "C++" unsigned int __cdecl FUN_0026fd80(unsigned int, unsigned int);
void __stdcall FUN_00334f10(State* state, unsigned int base, unsigned int source, unsigned int value, unsigned int unused) {
    unsigned int result = FUN_0026fd80(source, 0x4000);
    state->value64 = base;
    state->value6c = base;
    state->value70 = base;
    state->value68 = base + result;
    state->value84 = 0;
    state->value74 = result;
    state->value50 = value;
    state->value80 = 0;
    state->value3c = result;
    state->value48 = 0;
}
} // namespace fn_00334f10

namespace fn_f8921c09 {

// 0x00334f60 FUN_00334f60 (57 B): matches/0x00334f60.cpp
// sym: ?Run@fn_f8921c09@@YGXPAVThing@1@@Z
void __stdcall Run(Thing* s) {
    s->flag = 1;
    _ReadWriteBarrier();
    while (s->p)
        thunk();
    s->flag = 0;
    _ReadWriteBarrier();
    s->q->f1();
    s->q = 0;
}


// 0x00334fa0 FUN_00334fa0 (107 B): equivalent/0x00334fa0.cpp
// sym: _FUN_00334fa0@12 @6a3c4a602192 @w4a7007ab027d
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00334fa0 @ 0x00334fa0
extern "C" int __stdcall FUN_00334fa0(State_334fa0* state,unsigned int arg,unsigned int unused) {
 unsigned int* words = reinterpret_cast<unsigned int*>(state);
 for(int i=0;i<79;++i) words[i]=0;
 thunk_FUN_00271230(&state->device,arg,0,0,1,0,1,1);
 state->device->v30(1);
 state->callbacks[0]=FUN_00334960;
 state->callbacks[1]=FUN_00334c70;
 state->callbacks[2]=FUN_00334ef0;
 state->callbacks[3]=FUN_00334f10;
 state->callbacks[4]=FUN_00334c00;
 state->callbacks[5]=FUN_00334f60;
 return 1;
}

} // namespace fn_f8921c09

// 0x00335010 movie::BinkCallback::vfunc_3_adj8 (217 B): equivalent/0x00335010.cpp [wrapped: conflict: FUN_00368660]
// sym: ?OnReadComplete@BinkCallback@fn_00335010@@QAEXPAUBinkRequest@2@@Z @8ba10708f5ce @wfd10afdee475
namespace fn_00335010 {
// STATUS: equivalent (tools/equiv.py level 3: 13434 inputs, branch coverage 12/12)
// movie::BinkCallback::vfunc_3_adj8 @ 0x00335010
// movie::BinkCallback::vfunc_3_adj8 @ 0x00335010
struct FileStream_335010 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual int GetBlockSize();
};
int __cdecl FUN_0026fd50(hulk_intptr, int);
int __cdecl FUN_00368660();
struct BinkRequest {
    char pad0[0x1c];
    int failed;
    int busy;
    unsigned int bytesRead;
    int pendingA;
    unsigned int elapsedTotal;
    char pad30[0x4];
    unsigned int elapsedA;
    unsigned int elapsedB;
    char pad3c[0x4];
    unsigned int peak;
    char pad44[0x4];
    unsigned int outstanding;
    FileStream_335010* stream;
    char pad50[0x4];
    int readStart;
    char pad58[0x4];
    int readEnd;
    int buffer;
    unsigned int ringStart;
    unsigned int ringEnd;
    char pad6c[0x4];
    unsigned int ringPos;
    unsigned int remaining;
    int pendingB;
    unsigned int startTime;
    // equiv-conv: FUN_00334b00 esi
    void FUN_00334b00();
};
struct BinkCallback {
    void OnReadComplete(BinkRequest* req);
};
void BinkCallback::OnReadComplete(BinkRequest* req) {
    int count = req->readEnd - req->readStart;
    if (count != 0x4000) {
        int expected = FUN_0026fd50(req->buffer, req->stream->GetBlockSize());
        if (count != expected) {
            req->busy = 0;
            req->failed = 1;
            return;
        }
    }
    req->bytesRead += count;
    req->readStart = req->readEnd;
    req->ringPos += count;
    if (req->ringPos >= req->ringEnd)
        req->ringPos = req->ringStart;
    req->remaining -= count;
    req->outstanding += count;
    if (req->outstanding > req->peak)
        req->peak = req->outstanding;
    req->startTime = FUN_00368660() - req->startTime;
    req->elapsedTotal += req->startTime;
    if (req->pendingB == 0 && req->pendingA == 0)
        req->elapsedA += req->startTime;
    else
        req->elapsedB += req->startTime;
    req->busy = 0;
    req->FUN_00334b00();
}
} // namespace fn_00335010

namespace fn_f8921c09 {

// 0x003350f0 FUN_003350f0 (53 B): matches/0x003350f0.cpp
// sym: ?FUN_003350f0@fn_f8921c09@@YIPAUCallback_3350f0@1@PAU21@@Z
Callback_3350f0* __fastcall FUN_003350f0(Callback_3350f0* p) {
    p->a = ((hulk_intptr)DAT_0042afa8);
    p->b = *(volatile int*)((hulk_intptr)((char*)&DAT_004cdbb0));
    helper(p);
    p->c = ((hulk_intptr)DAT_0042bf6c);
    p->a = ((hulk_intptr)DAT_004342fc);
    p->c = ((hulk_intptr)DAT_004342e8);
    p->d = 0;
    return p;
}


// 0x00335130 movie::BinkCallback::vfunc_0_adj8 (4 B): matches/0x00335130.cpp
// sym: ?vfunc_0@NonCopyable@fn_f8921c09@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void NonCopyable::vfunc_0() {
    ++mRefCount;
}


// 0x00335140 movie::BinkCallback::vfunc_1_adj8 (4 B): matches/0x00335140.cpp
// sym: ?vfunc_1@ControllerXBox@core@fn_f8921c09@@UAEXXZ
// Same code shape as 0x00268590 (propagated; names are from that function)
namespace core {
void ControllerXBox::vfunc_1() {
    --refCount;
}
}

} // namespace fn_f8921c09

// 0x00335150 movie::BinkCallback::vfunc_2_adj8 (8 B): matches/0x00335150.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ?f@BinkCallback@movie@fn_00335150@@W7AEXH@Z
namespace fn_00335150 {
namespace movie {
struct Primary {
    virtual void f(int);
    int x;
};
struct Secondary {
    virtual void f(int);
};
struct __declspec(dllexport) BinkCallback : Primary, Secondary {
    virtual void f(int);
};
} // namespace movie
} // namespace fn_00335150

namespace fn_f8921c09 {

// 0x00335160 movie::BinkCallback::vfunc_0 (63 B): matches/0x00335160.cpp
// sym: ?vfunc_0@BinkCallback@movie@fn_f8921c09@@QAEPAV123@E@Z
movie::BinkCallback* movie::BinkCallback::vfunc_0(u8_335160 flag) {
    movie::BinkCallback* p = this;
    if (p)
        p = (movie::BinkCallback*)((char*)&p->refptr);
    else
        p = (movie::BinkCallback*)0;
    p->vptr = &refvt_335160;
    DAT_004cdbb0 = m;
    vptr = &basevt;
    if (flag & 1)
        cleanup(DAT_004cdbb0, this);
    return this;
}


// 0x003351a0 FUN_003351a0 (93 B): matches/0x003351a0.cpp
// sym: _FUN_003351a0
// data: gResult_3351a0 = DAT_00555ba8, gStored = DAT_004cdbb0
extern "C" void FUN_003351a0(hulk_uintptr arg) {
    (*(volatile unsigned int*)&DAT_004cdbb0) = arg;
    HULK_SIZE32(Callback_3351a0, 0x10);
    Callback_3351a0* p = (Callback_3351a0*)FUN_00266e00((int)arg, (int)sizeof(Callback_3351a0));
    if (p) {
        p->vtable = ((hulk_intptr)DAT_0042afa8);
        p->arg = (*(volatile unsigned int*)&DAT_004cdbb0);
        FUN_002705f0();
        *(volatile hulk_uintptr*)&p->subVtable = ((hulk_intptr)DAT_0042bf6c);
        p->vtable = ((hulk_intptr)DAT_004342fc);
        p->subVtable = ((hulk_intptr)DAT_004342e8);
        p->field = 0;
        (*(volatile void**)&DAT_00555ba8) = p;
    } else
        (*(volatile void**)&DAT_00555ba8) = 0;
}

} // namespace fn_f8921c09

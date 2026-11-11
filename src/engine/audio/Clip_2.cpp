// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00245370..0x00247080 (kind game, layer engine, confidence high), dominant class audio::Clip
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6720d1b {
#define TREE_TU_END }
namespace fn_f6720d1b {} using namespace fn_f6720d1b;
#include "engine/audio.h"
// (ren2) fclose's own name (CRT, C linkage)
extern "C" __declspec(nothrow) int __cdecl fclose(void*);

// ---- declarations shared by the functions below
namespace fn_f6720d1b {
class Stream {
  public:
    virtual void v0();
    virtual int v1();
    virtual void *v2();
    virtual void _m_vf3();
    virtual unsigned int v4();
    virtual void _m_vf5();
    virtual void v6(unsigned int a, unsigned int b, unsigned int c);
    virtual void _m_vf7();
    virtual bool v8(unsigned int *out);
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void v11();
    virtual void v12();
    char (__cdecl *write)(Stream* s, const void* data, unsigned int count);
};
extern "C" void FUN_00245380();
extern "C" Stream *FUN_0025bec0(Stream *s);
extern "C" void *FUN_0025d340(void *a, unsigned int n, int z);
extern "C" bool FUN_0025d070(void *buf, unsigned int done, unsigned int left, int z, unsigned int *x3, unsigned int *x2, unsigned int *x1);
extern "C" void FUN_0025d0f0(void *buf, unsigned int n);
bool FUN_0025d010(void *buf);
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual Entity* vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
class Clip : public Entity {
  public:
    virtual Clip* vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_8();
    char pad[0x28 - sizeof(Entity)];
    int mHandle;
    void cleanup();
};
extern "C" void FUN_0025d300(int);
extern "C" void FUN_00247550(void*, Clip*);
typedef unsigned int u32_245640;
extern void* __cdecl FUN_00247530(void*);
extern u32_245640 clipVftable;
} // namespace fn_f6720d1b
namespace audio {
class Clip_245640 {
  public:
    hulk_uintptr vft;
    char pad[0x24];
    u32_245640 field28;
    void init(void*);
};
}
namespace fn_f6720d1b {
struct Reader {
  public:
    char _m_pad_0[0xc];
    char(__cdecl* getEnd)(Reader*, int*);
    char(__cdecl* getStart)(Reader*, int*);
    char _m_pad_14[0x7c];
    unsigned int line;
    unsigned int position;
    union { unsigned end; unsigned int length; };
    unsigned FUN_00245b70(unsigned index);
};
class Owner_2458f0 {
  public:
    char pad[0x80];
    Reader* r;
    int a, b, c, d, e, diff, h;
    Owner_2458f0* Init(Reader*);
};
struct Table_2459d0 {
    int a, b;
    char(__cdecl* fn)(void*, void*, int, int);
};
class Buffer_2459d0 {
  public:
    virtual void F0();
    virtual void F1();
    char pad[0x7c];
    Table_2459d0* mOther;
    int mStart;
    unsigned int mEnd;
    int mIndex, mPad1, mPad2, mPad3, mDone;
};
struct Parser_245b00 {
    char pad[0x90];
    int line;
};
bool F2(Ctx* c, const char* s, ...);
int vfmt(char* buf, int n, const char* fmt, char* va);
} // namespace fn_f6720d1b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_f6720d1b {
class TextBuffer {
public:
    char pad0[0x94];
    unsigned int start;
    unsigned int end;
};
class Thing_245cd0 {
  public:
    char pad[0x90];
    int line;
    unsigned int index;
    unsigned int limit;
    void Step();
};
class X {
    char pad[0x90];

  public:
    int lines;
    unsigned int pos, end;
    void Skip(unsigned int);
};
struct P_245d40 {
    char pad[0x90];
    int line;
    unsigned pos;
    unsigned end;
};
extern "C" void __cdecl FUN_00245d40(void *);
int __cdecl FUN_00245890(const char*, hulk_intptr);
int __cdecl FUN_00245850(const char*, int);
struct Parser_246340 {
 char pad[0x90];
 unsigned int line;
 unsigned int position;
 unsigned int length;
};
double __cdecl FUN_003458c1(const char* text);
extern "C" int __cdecl FUN_003463c7(int, int, int, int);
extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, void*);
struct File {
    char pad[0x1c];
    void* handle;
};
extern "C" int __cdecl length(const char*);
extern "C" int __cdecl check(const char*, int, int);
struct S {
    char pad[0x1c];
    const char* str;
};
extern int Lookup(int);
extern "C" int __cdecl cmp(const char*, const char*, int);
class Device {
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
    virtual void v10(int, int, int);
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
    virtual void v21();
    virtual int v22();
};
class Node {
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
    virtual void Set(void*);
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual int Check();
};
class Owner {
  public:
    char _m_pad_0[0x1c];
    union { Device* dev; Node* node; };
};
class Interface {
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
    virtual void f11(int);
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
    virtual int f22();
};
extern "C" char DAT_00423f20[];
extern "C" char DAT_00429214[];
struct V {
    virtual void a();
    virtual void b();
};
struct CoreFileStream_2469c0 {
    void** vptr;
    char pad[0x18];
    V* m;
    void f();
};
class Callee {
  public:
};
struct Obj {
  public:
    char _m_pad_0[0x1c];
    union { int data; int n; const char* name; Interface* p; Callee* ptr; int value; };
    bool(__cdecl* fn)(int, int, int);
};
struct Inner_246a10 {
    char pad[0x1c];
    int F1();
    int F2();
};
struct Outer_246a10 {
    char pad[0x1c];
    Inner_246a10* p;
};
struct S_246a40 {
    int Fn();
};
struct A_246a40 {
    char pad[0x1c];
    S_246a40* m;
};
class Inner_246a60 {
  public:
    unsigned int Size();
};
class Outer_246a60 {
  public:
    char pad[0x1c];
    Inner_246a60* inner;
};
extern void* g_vt_246a90[];
class Ref_246a90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Stream_246a90 {
  public:
    void* vptr;
};
class ContentStream_246a90 : public Stream_246a90 {
  public:
    char pad[0x1c - 4];
    Ref_246a90* m;
    ~ContentStream_246a90() throw();
};
struct Buffer {
    char pad[0x1c];
    uint start;
    uint size;
    unsigned char* pos;
    unsigned char valid;
};
} // namespace fn_f6720d1b
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, uint);
#endif
namespace fn_f6720d1b {
struct Buf {
    char pad[0x1c];
    uint a;
    uint b;
    char* cur;
    char flag;
};
struct Obj_246b70 {
    char pad[0x20];
    int a;
    int b;
};
struct O_246b90 {
    char pad[0x20];
    int a;
    int b;
};
extern "C" void __cdecl FUN_00345880();
struct Obj_246c80 {
    char pad[0x1c];
    void* reader;
    char pad2[4];
    unsigned count;
};
typedef bool(__cdecl* ReadFn_246c80)(void*, const void*, unsigned);
class Writer_246cc0 {
public:
    char pad0[0x1c];
    Stream* stream;
    char pendingSpace;
    char pad21[7];
    char flag28;
    char FUN_00246c80();
    char Write(const void* data, unsigned int count);
};
struct LineSink {
    char pad00[0x20];
    char gotLine;         // 0x20
    char pad21[7];
    char keepNewline;     // 0x28
    bool FUN_00246cc0(const char* text, hulk_intptr length);
};
struct X_246da0 {
    unsigned int a;
    unsigned char b;
    X_246da0(hulk_uintptr, unsigned char);
};
class B_246f00;
class A_246f00 {
  public:
    char helper(int, int);
    B_246f00* mP;
    unsigned char mFlag;
    char f(int a, int b, char c, int d);
};
class B_246f00 {
  public:
    int pad[2];
    char (*mFn)(B_246f00*, int, int, int);
};
struct Writer {
    int unused;
    int(__cdecl* write)(Writer*, const char*, int);
};

} // namespace fn_f6720d1b

// 0x00245370 audio::Clip::vfunc_3 (5 B): matches/0x00245370.cpp
// sym: ?vfunc_3@Clip@audio@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool audio::Clip::vfunc_3(void* __p0) {
    return true;
}

namespace fn_f6720d1b {

// 0x00245380 FUN_00245380 (1 B): matches/0x00245380.cpp
// sym: _FUN_00245380
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00245380() {}


// 0x00245390 FUN_00245390 (452 B): equivalent/0x00245390.cpp
// sym: ?FUN_00245390@fn_f6720d1b@@YAPAXPAVStream@1@P6AXXZ@Z @101d217764cc @w918194cedff6
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 34/36, incomplete)
// FUN_00245390 @ 0x00245390
void *FUN_00245390(Stream *s, void (*pump)())
{
    if (!pump)
        pump = FUN_00245380;

    if (s->v1() == 0) {
        s->v0();
        while (s->v1() == 1) {
            s->v11();
            pump();
        }
        if (s->v1() != 2) {
            s->v12();
            return 0;
        }
    }

    s = FUN_0025bec0(s);
    if (s->v1() == 0) {
        s->v0();
        while (s->v1() == 1) {
            s->v11();
            pump();
        }
        if (s->v1() != 2) {
            s->v12();
            return 0;
        }
    }

    unsigned int total = s->v4();
    if (total == 0) {
        s->v12();
        return 0;
    }
    void *buf = FUN_0025d340(s->v2(), total, 0);
    if (!buf) {
        s->v12();
        return 0;
    }
    unsigned int left = total;
    unsigned int x1, x2, x3, got;
    while (left != 0) {
        if (FUN_0025d070(buf, total - left, left, 0, &x3, &x2, &x1)) {
            s->v6(x3, x2, x1);
            while (!s->v8(&got)) {
                s->v11();
                pump();
            }
            FUN_0025d0f0(buf, got);
            while (!FUN_0025d010(buf))
                pump();
            left -= got;
        } else {
            pump();
        }
    }
    s->v12();
    return buf;
}


// 0x00245570 audio::Clip::vfunc_8 (6 B): matches/0x00245570.cpp
// sym: _FUN_00245570
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00245570() {
    return &(*(int*)&DAT_004e5f18);
}


// 0x002455a0 audio::Clip::vfunc_2 (59 B): matches/0x002455a0.cpp
// sym: ?vfunc_2@Clip@fn_f6720d1b@@UAEPAV12@H@Z
Clip* Clip::vfunc_2(int flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042918c);
    if (mHandle)
        FUN_0025d300(mHandle);
    cleanup();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e5f18), this);
    return this;
}

} // namespace fn_f6720d1b

// 0x002455e0 FUN_002455e0 (92 B): matches/0x002455e0.cpp [wrapped: conflict: audio::ClipType]
// sym: ??0ClipType@audio@fn_002455e0@@QAE@XZ
namespace fn_002455e0 {
struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_002672f0(const char*, int, int);
namespace audio {
class FUN_00243310 {
  public:
    virtual void FUN_002455d0();
    FUN_00243310(const Pair*, const Pair*, int, int, int);
};
class ClipType : public FUN_00243310 {
  public:
    virtual void FUN_002455d0();
    ClipType();
};
} // namespace audio
audio::ClipType::ClipType()
    : FUN_00243310(&FUN_002672f0("Data_Clip", 0, 0), &FUN_002672f0("Clip", 0, 0), 0x1000000, (int)sizeof(AudioClip), 8) { HULK_SIZE32(AudioClip, 0x30); }
} // namespace fn_002455e0


// 0x00245640 audio::ClipType::vfunc_2 (53 B): matches/0x00245640.cpp
// sym: ?vfunc_2@ClipType@audio@@UAEPAXXZ
// data: allocatorGlobal = DAT_004e5f18
 // namespace audio
void* audio::ClipType::vfunc_2() {
    Clip_245640* p = (Clip_245640*)FUN_00247530(((char*)&DAT_004e5f18));
    if (p != 0) {
        p->init(((char*)&DAT_004e5f18));
        p->vft = (hulk_uintptr)&clipVftable;
        p->field28 = 0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00245720 FUN_00245720 (206 B): equivalent/0x00245720.cpp [wrapped: conflict: audio::Clip]
// sym: ?target@fn_00245720@@YA_NPAPAUClip@audio@1@PAXPBD1@Z @000f5feb8518 @wd8596531800e
inline void* __cdecl operator new(size_t,void* p) { return p; }
namespace fn_00245720 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_00245720 @ 0x00245720

struct Key_245720 { unsigned a,b; };

struct FUN_00244ea0 {
 virtual void retain();
 virtual void release();
 char pad[36];
 FUN_00244ea0(char* = ((char*)&DAT_004e5f18));
 void FUN_00245040(Key_245720*);
};
namespace audio { struct Clip: FUN_00244ea0 {
 virtual void retain();
 virtual void release();
 void* data;
}; }
extern "C" void __cdecl FUN_0025ca90(Key_245720*, const char*);
extern audio::Clip* __cdecl FUN_00244fa0(Key_245720*,char*);
extern void* __cdecl FUN_00247530(char*);
extern "C" void* __cdecl FUN_0025cab0(void*,const char*,int,int);
extern void* __cdecl FUN_00245390(void*,void*);
bool __cdecl target(audio::Clip** out, void* source, const char* name, void* option) {
 Key_245720 key;
 FUN_0025ca90(&key,name);
 *out=FUN_00244fa0(&key,((char*)((char*)&DAT_004e5f18->type.body.key)));
 if(*out) {
  (*out)->retain();
  if((*out)->data) return true;
 } else {
  void* memory=FUN_00247530(((char*)&DAT_004e5f18));
  audio::Clip* clip=memory ? new(memory) audio::Clip:0;
  if(clip) clip->data=0;
  *out=clip;
  (*out)->retain();
  (*out)->FUN_00245040(&key);
 }
 void* stream=FUN_0025cab0(source,name,0,2);
 void* data=FUN_00245390(stream,option);
 if(data) { (*out)->data=data; return true; }
 (*out)->release();
 *out=0;
 return false;
}
} // namespace fn_00245720

namespace fn_f6720d1b {

// 0x00245850 FUN_00245850 (56 B): matches/0x00245850.cpp
// sym: ?FUN_00245850@fn_f6720d1b@@YAHPADH@Z
int FUN_00245850(char* digits, int length) {
    int value = 0;
    int place = 1;
    char* p;
    for (p = digits + length - 1; p >= digits; --p) {
        value += (*p - 0x30) * place;
        place *= 10;
    }
    return value;
}


// 0x00245890 FUN_00245890 (58 B): matches/0x00245890.cpp
// sym: ?FUN_00245890@fn_f6720d1b@@YAHHH@Z
int FUN_00245890(hulk_intptr digits, hulk_intptr length) {
    int value = 0;
    int place = 1;
    char* p = (char*)(digits + 1);
    char* q = (char*)(digits + length - 1);
    while (q >= p) {
        value += (*q - 0x30) * place;
        place *= 10;
        --q;
    }
    return -value;
}


// 0x002458f0 FUN_002458f0 (138 B): matches/0x002458f0.cpp
// sym: ?Init@Owner_2458f0@fn_f6720d1b@@QAEPAV12@PAUReader@2@@Z
Owner_2458f0* Owner_2458f0::Init(Reader* rd) {
    r = rd;
    a = 0;
    b = 0;
    c = 0;
    d = 1;
    e = 0;
    h = 0;
    int end = 0;
    int start = 0;
    if (rd->getStart(rd, &start) && rd->getEnd(rd, &end))
        diff = end - start;
    else
        diff = 0;
    return this;
}


// 0x002459d0 FUN_002459d0 (103 B): matches/0x002459d0.cpp
// sym: ?F0@Buffer_2459d0@fn_f6720d1b@@UAEXXZ
void Buffer_2459d0::F0() {
    int n = mEnd + mStart;
    char* p = (char*)this + (n & 0x7f);
    Table_2459d0* q = mOther;
    if (q->fn(q, p, 1, 1)) {
        ++mDone;
        if (mEnd < 0x80)
            ++mEnd;
        else {
            mStart = (mStart + 1) & 0x7f;
            ++mIndex;
        }
    }
}


// 0x00245b00 FUN_00245b00 (98 B): matches/0x00245b00.cpp
// sym: ?Err@fn_f6720d1b@@YA_NPAUParser_245b00@1@PAUCtx@1@PBDZZ
bool Err(Parser_245b00* p, Ctx* c, const char* fmt, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    vfmt(buf, 0x1000, fmt, va);
#else
    vfmt(buf, 0x1000, fmt, (char*)&fmt + 4);
#endif
    F2(c, buf);
    F2(c, "\nError Line: [%d]\n", p->line);
    return false;
}

} // namespace fn_f6720d1b

// 0x00245b70 FUN_00245b70 (132 B): equivalent/0x00245b70.cpp
// sym: ?FUN_00245b70@RingReader_245b70@owners@@QAEEI@Z @57e12cb94f83 @w9caf367954d5
// STATUS: equivalent (tools/equiv.py level 3: 1792 inputs, branch coverage 12/12)
// FUN_00245b70 @ 0x00245b70
unsigned char owners::RingReader_245b70::FUN_00245b70(unsigned int index)
{
    if (index >= limit)
        return 0;
    if (index < base)
        return 0;
    if (index >= windowStart && index < windowLen + base)
        return buf[(windowStart - base + index) & 0x7f];
    while (index < windowStart || index >= windowLen + base)
        FUN_002459d0();
    return buf[(index - base + windowStart) & 0x7f];
}

namespace fn_f6720d1b {

// 0x00245c50 FUN_00245c50 (102 B): equivalent/0x00245c50.cpp
// sym: ?FUN_00245c50@fn_f6720d1b@@YA_NPAVTextBuffer@1@PBD@Z @ef527fb187f3 @w6f914f07ce11
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00245c50 @ 0x00245c50
bool __cdecl FUN_00245c50(TextBuffer* buf, const char* text) {
    unsigned int cur = buf->start;
    unsigned int i = cur;
    hulk_uintptr len = strlen(text);
    while (i - cur < len) {
        if (cur >= buf->end)
            return false;
        if (((char)((owners::RingReader_245b70 *)buf)->FUN_00245b70(i)) != *text)
            return false;
        cur = buf->start;
        i++;
        text++;
    }
    return true;
}


// 0x00245cd0 FUN_00245cd0 (43 B): matches/0x00245cd0.cpp
// sym: ?Step@Thing_245cd0@fn_f6720d1b@@QAEXXZ
void Thing_245cd0::Step() {
    unsigned int i = index;
    if (i < limit) {
        if (((char)((owners::RingReader_245b70 *)this)->FUN_00245b70(i)) == 10)
            ++line;
        ++index;
    }
}


// 0x00245d00 FUN_00245d00 (62 B): matches/0x00245d00.cpp
// sym: ?Skip@X@fn_f6720d1b@@QAEXI@Z
void X::Skip(unsigned int n) {
    while (n) {
        if (pos < end) {
            if (((char)((owners::RingReader_245b70 *)this)->FUN_00245b70(pos)) == '\n')
                ++lines;
            ++pos;
        }
        --n;
    }
}


// 0x00245d40 FUN_00245d40 (103 B): matches/0x00245d40.cpp
// sym: _FUN_00245d40
extern "C" void FUN_00245d40(void * p) {
    while (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
        char c = ((char)((owners::RingReader_245b70 *)(((P_245d40 *)p)))->FUN_00245b70((unsigned int)(((P_245d40 *)p)->pos)));
        if (c != 9 && c != 32 && c != 10 && c != 13)
            return;
        if (((P_245d40 *)p)->pos < ((P_245d40 *)p)->end) {
            if (((char)((owners::RingReader_245b70 *)(((P_245d40 *)p)))->FUN_00245b70((unsigned int)(((P_245d40 *)p)->pos))) == 10)
                ((P_245d40 *)p)->line++;
            ((P_245d40 *)p)->pos++;
        }
    }
}


// 0x00246100 FUN_00246100 (282 B): equivalent/0x00246100.cpp
// sym: _FUN_00246100 @79ae925442a9 @w076001dd7e94
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 18/18)
// FUN_00246100 @ 0x00246100
extern "C" int __cdecl FUN_00246100(Reader* r) {
 char buffer[128];
 char* out = buffer;
 FUN_00245d40((Reader *)r);
 if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '-') {
  *out = ((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position));
  if (r->position < r->length) {
   if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 while (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) >= '0') {
  if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) > '9') break;
  *out = ((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position));
  if (r->position < r->length) {
   if (((signed char)((owners::RingReader_245b70 *)r)->FUN_00245b70(r->position)) == '\n') ++r->line;
   ++r->position;
  }
  ++out;
 }
 *out = 0;
 hulk_intptr size = out-buffer;
 if (buffer[0] == '-') return FUN_00245890(buffer,size);
 return FUN_00245850(buffer,size);
}


// 0x00246220 FUN_00246220 (171 B): equivalent/0x00246220.cpp
// sym: ?FUN_00246220@fn_f6720d1b@@YA_NPAUReader@1@PAI@Z @6fad24cce309 @w04165b81f28e
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 20/20)
// FUN_00246220 @ 0x00246220
bool __cdecl FUN_00246220(Reader* reader, unsigned* result) {
 FUN_00245d40((Reader *)reader);
 unsigned value = 0;
 if (reader->position >= reader->end) return false;
 for (;;) {
  signed char ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
  if (ch == 9 || ch == 32 || ch == 10 || ch == 13) {
   *result = value; return true;
  }
  if (reader->position >= reader->end) {
   *result = value; return true;
  }
  ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
  if (ch < '0' || ch > '9') {
   *result = 0; return false;
  }
  value = value * 10 + ch - '0';
  if (reader->position < reader->end) {
   ch = ((signed char)((owners::RingReader_245b70 *)reader)->FUN_00245b70((unsigned int)(reader->position)));
   if (ch == 10) ++reader->line;
   ++reader->position;
  }
 }
}


// 0x00246340 FUN_00246340 (236 B): equivalent/0x00246340.cpp
// sym: ?FUN_00246340@fn_f6720d1b@@YANPAUParser_246340@1@@Z @3f11c25b3053 @w2f81b351cc1a
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 18/18)
// FUN_00246340 @ 0x00246340
double __cdecl FUN_00246340(Parser_246340* parser) {
 char buffer[128];
 char* out = buffer;
 FUN_00245d40((Parser_246340 *)parser);
 if (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '-' ||
     (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) >= '0' && ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) <= '9') ||
     ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '.') {
   do {
     *out = ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position));
     if (parser->position < parser->length) {
       if (((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '\n') ++parser->line;
       ++parser->position;
     }
     ++out;
   } while ((((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) >= '0' && ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) <= '9') || ((signed char)((owners::RingReader_245b70 *)parser)->FUN_00245b70(parser->position)) == '.');
 }
 *out = 0;
 return FUN_003458c1(buffer);
}


// 0x00246560 FUN_00246560 (232 B): equivalent/0x00246560.cpp
// sym: ?FUN_00246560@fn_f6720d1b@@YAIPAUReader@1@PADIPBD@Z @7971427a1595 @waf2e32febc0f
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 26/26)
// FUN_00246560 @ 0x00246560
unsigned __cdecl FUN_00246560(Reader* reader, char* output, unsigned capacity, const char* delimiters) {
 bool quoted = false;
 unsigned result = reader->position;
 if (result < reader->end) {
  char* limit = output + capacity - 1;
  while ((hulk_uintptr)output < (hulk_uintptr)limit) {
   result = reader->FUN_00245b70(reader->position);
   unsigned char ch = (unsigned char)result;
   if (ch == '"') quoted = !quoted;
   else {
    const char* p = delimiters;
    while (*p) {
     if (ch == (unsigned char)*p) {
      if (!quoted) {
       *output = 0;
       result = reader->position;
       if (result < reader->end) {
        if ((unsigned char)reader->FUN_00245b70(result) == '\n') ++reader->line;
        result = reader->position + 1;
        reader->position = result;
       }
       return result;
      }
      break;
     }
     ++p;
    }
   }
   *output++ = ch;
   result = reader->position;
   if (result < reader->end) {
    result = reader->FUN_00245b70(result);
    if ((unsigned char)result == '\n') ++reader->line;
    ++reader->position;
   }
   if (reader->position >= reader->end) break;
  }
 }
 *output = 0;
 return result;
}


// 0x00246750 FUN_00246750 (35 B): matches/0x00246750.cpp
// sym: ?FUN_00246750@fn_f6720d1b@@YAHPAUObj@1@HH@Z
int __cdecl FUN_00246750(Obj* o, int a, int b) {
    return FUN_003463c7(a, b, 1, o->n) == 1;
}


// 0x00246780 FUN_00246780 (35 B): matches/0x00246780.cpp
// sym: ?Read@fn_f6720d1b@@YA_NPAUFile@1@PAXI@Z
bool __cdecl Read(File* f, void* p, unsigned int n) {
    return fread(p, n, 1, f->handle) == 1;
}

} // namespace fn_f6720d1b

// 0x002467b0 FUN_002467b0 (36 B): matches/0x002467b0.cpp [wrapped: conflict: Stream]
// sym: ??1StdStream@fn_002467b0@@UAE@XZ
namespace fn_002467b0 {
struct Stream {
    virtual ~Stream() {}
    char pad[0x18];
};
struct StdStream : Stream {
    void* file;
    unsigned char owns;
    ~StdStream();
};
StdStream::~StdStream() {
    if (owns)
        fclose(file);
}
} // namespace fn_002467b0

namespace fn_f6720d1b {

// 0x002467e0 FUN_002467e0 (83 B): matches/0x002467e0.cpp
// sym: ?FUN_002467e0@fn_f6720d1b@@YADPAUS@1@PAH@Z
char __cdecl FUN_002467e0(S* s, int* out) {
    int n = length(s->str);
    if (check(s->str, 0, 2))
        return 0;
    *out = length(s->str) - n;
    return check(s->str, n, 0) == 0;
}


// 0x00246840 FUN_00246840 (33 B): matches/0x00246840.cpp
// sym: ?Find@fn_f6720d1b@@YA_NPAUObj@1@PAH@Z
bool Find(Obj* obj, int* out) {
    int r = Lookup(obj->value);
    if (r == -1)
        return false;
    *out = r;
    return true;
}


// 0x00246870 FUN_00246870 (29 B): matches/0x00246870.cpp
// sym: ?FUN_00246870@fn_f6720d1b@@YAHPAUObj@1@PBD@Z
int __cdecl FUN_00246870(Obj* obj, const char* s) {
    return cmp(obj->name, s, 0) == 0;
}


// 0x00246890 FUN_00246890 (37 B): matches/0x00246890.cpp
// sym: ?FUN_00246890@fn_f6720d1b@@YA_NPAVOwner@1@H@Z
bool FUN_00246890(Owner* owner, int arg) {
    owner->dev->v10(arg, 1, 1);
    return owner->dev->v22() == 0;
}

} // namespace fn_f6720d1b

// 0x002468c0 FUN_002468c0 (80 B): equivalent/0x002468c0.cpp [wrapped: conflict: Stream]
// sym: ?FUN_002468c0@fn_002468c0@@YAIPAUObject@1@PAXI1@Z @1ed7e1588dcc @wdc998c3c4485
namespace fn_002468c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002468c0 @ 0x002468c0
struct Stream { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(void*, unsigned int, void*); virtual void slot10(); virtual void slot11(); virtual void slot12(void**); virtual void slot13(); virtual void slot14(); virtual unsigned int slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual int slot22(); }; struct Object { char pad[0x1c]; Stream* stream; }; unsigned int __cdecl FUN_002468c0(Object* obj, void* source, unsigned int length, void* destination) { Object* saved = obj; saved->stream->slot12((void**)&obj); unsigned int limit = saved->stream->slot15(); if ((hulk_uintptr)obj + length > limit) return limit & 0xffffff00; saved->stream->slot9(source, length, destination); return saved->stream->slot22() == 0; }
} // namespace fn_002468c0


// 0x00246910 FUN_00246910 (65 B): matches/0x00246910.cpp [wrapped: conflict: Stream]
// sym: ?FUN_00246910@fn_00246910@@YA_NPAUWrap@1@PAH@Z
namespace fn_00246910 {
class Stream {
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
    virtual void f12(int*);
    virtual void f13();
    virtual void f14();
    virtual int GetPos();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual int Good();
};
struct Wrap {
    char pad[0x1c];
    Stream* stream;
};
bool FUN_00246910(Wrap* w, int* result) {
    int pos = w->stream->GetPos();
    int n = 0;
    w->stream->f12(&n);
    *result = pos - n;
    return w->stream->Good() == 0;
}
} // namespace fn_00246910

namespace fn_f6720d1b {

// 0x00246960 FUN_00246960 (33 B): matches/0x00246960.cpp
// sym: ?FUN_00246960@fn_f6720d1b@@YAHPAVOwner@1@PAX@Z
int __cdecl FUN_00246960(Owner* o, void* p) {
    o->node->Set(p);
    return !o->node->Check();
}


// 0x00246990 FUN_00246990 (33 B): matches/0x00246990.cpp
// sym: ?FUN_00246990@fn_f6720d1b@@YAHPAUObj@1@H@Z
int FUN_00246990(Obj* o, int n) {
    o->p->f11(n);
    return o->p->f22() == 0;
}


// 0x002469c0 FUN_002469c0 (25 B): matches/0x002469c0.cpp
// sym: ?f@CoreFileStream_2469c0@fn_f6720d1b@@QAEXXZ
void CoreFileStream_2469c0::f() {
    vptr = (void**)((hulk_intptr)DAT_00429214);
    m->b();
    vptr = (void**)((hulk_intptr)DAT_00423f20);
}


// 0x002469e0 FUN_002469e0 (3 B): matches/0x002469e0.cpp
// sym: _FUN_002469e0
extern "C" bool FUN_002469e0() {
    return false;
}


// 0x002469f0 FUN_002469f0 (30 B): matches/0x002469f0.cpp
// sym: _FUN_002469f0
extern "C" void FUN_002469f0(Obj* o, void* a, void* b, void* c) {
    ((owners::X_2647e0 *)(o->ptr))->FUN_002647e0((hulk_intptr)a, (hulk_intptr)b, 1, (hulk_intptr)c);
}


// 0x00246a10 FUN_00246a10 (37 B): matches/0x00246a10.cpp
// sym: _FUN_00246a10
extern "C" bool FUN_00246a10(Outer_246a10* self, int* out) {
    int x = self->p->F1();
    int y = self->p->F2();
    *out = y - x;
    return true;
}


// 0x00246a40 FUN_00246a40 (21 B): matches/0x00246a40.cpp
// sym: _FUN_00246a40
extern "C" bool FUN_00246a40(A_246a40* a, int* b) {
    S_246a40* sub = a->m;
    int r = sub->Fn();
    *b = r;
    return true;
}


// 0x00246a60 FUN_00246a60 (40 B): matches/0x00246a60.cpp
// sym: _FUN_00246a60
extern "C" bool FUN_00246a60(Outer_246a60* self, unsigned int value) {
    unsigned int n = self->inner->Size();
    if (value >= n) {
        ((owners::S_264510 *)(self->inner))->FUN_00264510((unsigned)(value - n));
        return true;
    }
    return false;
}


// 0x00246a90 FUN_00246a90 (25 B): matches/0x00246a90.cpp
// sym: ??1ContentStream_246a90@fn_f6720d1b@@QAE@XZ
ContentStream_246a90::~ContentStream_246a90() throw() {
    Ref_246a90* r = m;
    vptr = g_vt_246a90;
    r->Release();
    vptr = g_vt2;
}


// 0x00246ab0 FUN_00246ab0 (76 B): matches/0x00246ab0.cpp
// sym: _FUN_00246ab0
extern "C" bool __cdecl FUN_00246ab0(Buffer* b, const void* src, uint count) {
    if (!b->valid)
        return false;
    if (b->start + b->size - (hulk_uintptr)b->pos < count)
        return false;
    memcpy(b->pos, src, count);
    b->pos += count;
    return true;
}


// 0x00246b00 FUN_00246b00 (76 B): matches/0x00246b00.cpp
// sym: _FUN_00246b00
extern "C" bool __cdecl FUN_00246b00(Buf* p, void* dst, uint n) {
    if (p->flag)
        return false;
    if (p->a + p->b - (hulk_uintptr)p->cur < n)
        return false;
    memcpy(dst, p->cur, n);
    p->cur += n;
    return true;
}


// 0x00246b50 FUN_00246b50 (24 B): matches/0x00246b50.cpp
// sym: _FUN_00246b50
extern "C" char FUN_00246b50(int* p, int* out) {
    *out = *(int*)((char*)p + 0x20) - *(int*)((char*)p + 0x24) + *(int*)((char*)p + 0x1c);
    return 1;
}


// 0x00246b70 FUN_00246b70 (21 B): matches/0x00246b70.cpp
// sym: _FUN_00246b70
extern "C" bool FUN_00246b70(Obj_246b70* p, int* out) {
    *out = p->b - p->a;
    return true;
}


// 0x00246b90 FUN_00246b90 (17 B): matches/0x00246b90.cpp
// sym: _FUN_00246b90
extern "C" char __cdecl FUN_00246b90(O_246b90* p, int x) {
    p->b = p->a + x;
    return 1;
}


// 0x00246bb0 FUN_00246bb0 (35 B): matches/0x00246bb0.cpp
// sym: _FUN_00246bb0
extern "C" bool __cdecl FUN_00246bb0(unsigned int a, unsigned int b, unsigned int index) {
    volatile char buffer[0x1004];
    buffer[index & 0xfff] = 0;
    return true;
}


// 0x00246be0 FUN_00246be0 (35 B): matches/0x00246be0.cpp
// sym: _FUN_00246be0
// Same code shape as 0x00246bb0 (propagated; names are from that function)
extern "C" bool __cdecl FUN_00246be0(unsigned int a, unsigned int b, unsigned int index) {
    volatile char buffer[0x1004];
    buffer[index & 0xfff] = 0;
    return true;
}


// 0x00246c20 FUN_00246c20 (3 B): matches/0x00246c20.cpp
// sym: _FUN_00246c20
extern "C" char FUN_00246c20() {
    return 1;
}


// 0x00246c30 FUN_00246c30 (3 B): matches/0x00246c30.cpp
// sym: _FUN_00246c30
extern "C" bool FUN_00246c30() {
    return false;
}


// 0x00246c50 FUN_00246c50 (6 B): matches/0x00246c50.cpp
// sym: _FUN_00246c50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00246c50() {
    return &(*(int*)&DAT_004cc0cc);
}


// 0x00246c60 FUN_00246c60 (27 B): matches/0x00246c60.cpp
// sym: ?FUN_00246c60@fn_f6720d1b@@YA_NPAUObj@1@HH@Z
bool __cdecl FUN_00246c60(Obj* p, int a, int b) {
    p->fn(p->data, a, b);
    return true;
}


// 0x00246c80 FUN_00246c80 (55 B): matches/0x00246c80.cpp
// sym: ?FUN_00246c80@fn_f6720d1b@@YI_NPAUObj_246c80@1@@Z
bool __fastcall FUN_00246c80(Obj_246c80* self) {
    unsigned i = 0;
    if (self->count > 0) {
        do {
            void* r = self->reader;
            if (!((ReadFn_246c80*)r)[1](r, (const void*)((hulk_intptr)DAT_004cc0c8), 4))
                return false;
            ++i;
        } while (i < self->count);
    }
    return true;
}


// 0x00246cc0 FUN_00246cc0 (103 B): equivalent/0x00246cc0.cpp
// sym: ?Write@Writer_246cc0@fn_f6720d1b@@QAEDPBXI@Z @7f549f8ef3b2 @w2f0b4d5905a5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00246cc0 @ 0x00246cc0
char Writer_246cc0::Write(const void* data, unsigned int count) {
    if (count == 0)
        return 1;
    if (pendingSpace) {
        if (flag28) {
            if (!FUN_00246c80())
                return 0;
        } else {
            char space = 0x20;
            if (!stream->write(stream, &space, 1))
                return 0;
        }
        pendingSpace = 0;
    }
    return stream->write(stream, data, count);
}


// 0x00246d30 FUN_00246d30 (106 B): matches/0x00246d30.cpp
// sym: ?FUN_00246d30@fn_f6720d1b@@YA_NPAULineSink@1@PBDH@Z
// FUN_00246d30 @ 0x00246d30
// Splits text on '\n', feeding each line to the sink.
bool FUN_00246d30(LineSink* sink, const char* text, int length)
{
    const char* end = text + length;
    const char* cur = text;
    const char* lineStart = text;
    while (cur < end) {
        if (*cur == '\n') {
            if (sink->keepNewline) {
                cur++;
                if (!sink->FUN_00246cc0(lineStart, cur - lineStart))
                    return false;
            } else {
                if (!sink->FUN_00246cc0(lineStart, cur - lineStart))
                    return false;
                cur++;
            }
            lineStart = cur;
            sink->gotLine = 1;
        } else {
            cur++;
        }
    }
    return sink->FUN_00246cc0(lineStart, cur - lineStart);
}


// 0x00246da0 FUN_00246da0 (18 B): matches/0x00246da0.cpp
// sym: ??0X_246da0@fn_f6720d1b@@QAE@IE@Z
X_246da0::X_246da0(hulk_uintptr p, unsigned char q) : a(p), b(q) {}

} // namespace fn_f6720d1b

// 0x00246e00 FUN_00246e00 (67 B): matches/0x00246e00.cpp [wrapped: conflict: Stream]
// sym: ?ReverseRead@Stream@fn_00246e00@@QAEDPADH@Z
namespace fn_00246e00 {
struct VTable {
    void* a;
    void* b;
    char(__cdecl* Read)(VTable*, char*, int, int);
};
class Stream {
  public:
    VTable* v;
    char ReverseRead(char* p, int n);
};
char Stream::ReverseRead(char* p, int n) {
    VTable* t = v;
    if (t->Read(t, p, n, 1)) {
        char* end = p + n - 1;
        char* q = p;
        if (q < end) {
            do {
                char c = *end;
                char d = *q;
                *q = c;
                ++q;
                *end = d;
                --end;
            } while (q < end);
        }
        return 1;
    }
    return 0;
}
} // namespace fn_00246e00


// 0x00246e50 FUN_00246e50 (105 B): equivalent/0x00246e50.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Run@Wrapper_246e50@fn_00246e50@@QAEEPAEH@Z @1e0b6e5a3e58 @wc6351f250002
namespace fn_00246e50 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 8/8)
// FUN_00246e50 @ 0x00246e50
struct Inner_246e50;
typedef unsigned char (__cdecl *ProcessFn)(Inner_246e50* self, unsigned char* data, int length);
struct Inner_246e50 {
    int unused;
    ProcessFn process;     // 0x04
};

static void ReverseBytes(unsigned char* first, unsigned char* last)
{
    while (first < last) {
        unsigned char a = *last;
        unsigned char b = *first;
        *first = a;
        first++;
        *last = b;
        last--;
    }
}

struct Wrapper_246e50 {
    Inner_246e50* inner;
    unsigned char Run(unsigned char* data, int length);
};

// Reverses the buffer, lets the inner object process it, then reverses it back.
unsigned char Wrapper_246e50::Run(unsigned char* data, int length)
{
    unsigned char* last = data + length - 1;
    ReverseBytes(data, last);
    unsigned char result = inner->process(inner, data, length);
    ReverseBytes(data, last);
    return result;
}
} // namespace fn_00246e50

namespace fn_f6720d1b {

// 0x00246f00 FUN_00246f00 (60 B): matches/0x00246f00.cpp
// sym: ?f@A_246f00@fn_f6720d1b@@QAEDHHDH@Z
char A_246f00::f(int a, int b, char c, int d) {
    if (c && mFlag) {
        return helper(a, b);
    }
    B_246f00* p = mP;
    return p->mFn(p, a, b, d);
}


// 0x00246f50 FUN_00246f50 (88 B): matches/0x00246f50.cpp
// sym: ?FUN_00246f50@fn_f6720d1b@@YAHPAUWriter@1@PBDZZ
int __cdecl FUN_00246f50(Writer* w, const char* fmt, ...) {
    char buf[1024];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    _vsnprintf(buf, 1024, fmt, va);
#else
    _vsnprintf(buf, 1024, fmt, (char*)&fmt + 4);
#endif
    buf[1023] = 0;
    return w->write(w, buf, strlen(buf));
}

} // namespace fn_f6720d1b

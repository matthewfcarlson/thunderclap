// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fa9c0..0x001fb3f0 (kind game, layer game, confidence high), dominant class MyFileStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa90982c {
#define TREE_TU_END }
namespace fn_fa90982c {} using namespace fn_fa90982c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa90982c {
extern int gameVftable;
extern int creatorVftable;
class Ref_1faa60 {
  public:
    virtual void Release(int);
};
class CGameDataHandler_1faa60 {
  public:
    int* vptr;
    Ref_1faa60* mRef;
    void f();
};
class Ref_1fad80 {
  public:
    virtual void A();
    virtual void Release();
};
struct File_1fada0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Read(void* buf, int len, int one);
    virtual void v4();
    virtual void v5();
    virtual void GetPos(int* out);
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
    virtual void Sync();
};
} // namespace fn_fa90982c
inline void* operator new(size_t, void* p) throw() {
    return p;
}
namespace fn_fa90982c {
extern void* vGDH[];
extern "C" void* __cdecl FUN_0008d690(unsigned int) throw();
struct Inner_1fae80 {
    Inner_1fae80() throw();
};
struct CGameDataHandler_1fae80 {
    void* vf;
    Inner_1fae80* p4;
    int p8, pc, p10, p14, p18, p1c, p20, p24, p28, p2c, p30;
    CGameDataHandler_1fae80() throw();
};
struct MyFileStream_1faf70 {
    virtual void v0();
    int a, b, c;
};
struct Failure {
    void Fail();
};
struct Helper_1faf70 {
    int x, y, z;
    void Init();
    bool Try(MyFileStream_1faf70*, int, Failure*, void*, int);
    void Close();
};
struct Obj_1faf70 {
    int pad;
    Failure* y;
    bool Target(hulk_intptr arg);
};
struct Obj_1fb1e0 {
    void* a;
    int b, c, d;
};
struct Stream {
    bool Open(Obj_1fb1e0*, const char*);
    void Close();
};
struct Manager_1fb1e0 {
    void Add(void*, int);
};
struct Owner_1fb1e0 {
    char pad[4];
    Stream* stream;
    void Fn();
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern const char filename[];
extern char MyFileStream_vftable[];
extern char DataHandlerRawLoader_vftable[];

} // namespace fn_fa90982c

// 0x001fa9c0 MyBufferStream::vfunc_1 (5 B): matches/0x001fa9c0.cpp
// sym: ?vfunc_1@MyBufferStream@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool MyBufferStream::vfunc_1(void* __p0) {
    return true;
}

namespace fn_fa90982c {

// 0x001fa9d0 MyBufferStream::vfunc_2 (1 B): matches/0x001fa9d0.cpp
// sym: ?FUN_001fa9d0@fn_fa90982c@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fa9d0() {}

} // namespace fn_fa90982c

// 0x001fa9e0 MyBufferStream::vfunc_3 (66 B): equivalent/0x001fa9e0.cpp [wrapped: conflict: MyBufferStream]
// sym: ?vfunc_3@MyBufferStream@fn_001fa9e0@@UAEXPAXI@Z
namespace fn_001fa9e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2462 inputs, branch coverage 4/4)
// MyBufferStream::vfunc_3 @ 0x001fa9e0
typedef unsigned char byte;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void * __cdecl memcpy(void *, const void *, unsigned int);
#endif

struct Stream_1fa9e0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(void *, unsigned int); virtual void vfunc_4(); };
struct MyBufferStream : Stream_1fa9e0 { byte *data; int length; int position; virtual void vfunc_3(void *destination, unsigned int count); };
void MyBufferStream::vfunc_3(void *destination, unsigned int count) {
    int available = length - position;
    if ((int)(position + count) > length) count = available;
    if ((int)count > 0) {
        memcpy(destination, data + position, count);
        position += count;
    }
}
} // namespace fn_001fa9e0


// 0x001faa30 MyBufferStream::vfunc_4 (18 B): matches/0x001faa30.cpp
// sym: ?vfunc_4@MyBufferStream@@UAE_NXZ
bool MyBufferStream::vfunc_4() {
    return this->f_0c < this->f_08;
}

namespace fn_fa90982c {

// 0x001faa60 FUN_001faa60 (30 B): matches/0x001faa60.cpp
// sym: ?f@CGameDataHandler_1faa60@fn_fa90982c@@QAEXXZ
void CGameDataHandler_1faa60::f() {
    vptr = &gameVftable;
    if (mRef)
        mRef->Release(1);
    vptr = &creatorVftable;
}

} // namespace fn_fa90982c

// 0x001faa80 FUN_001faa80 (121 B): matches/0x001faa80.cpp [wrapped: conflict: MyBufferStream]
// sym: ?FUN_001faa80@Loader_1faa80@fn_001faa80@@QAE_NHH@Z
namespace fn_001faa80 {
// FUN_001faa80 @ 0x001faa80
class MyBufferStream {
public:
    virtual void v0();
    int arg0;
    int arg1;
    int zero;
    MyBufferStream(int a, int b) : arg0(a), arg1(b), zero(0) {}
};

struct StreamLoader {
    char data[0xc];
    void FUN_00337870();
    void FUN_00337890();
    bool FUN_00337a30(MyBufferStream* stream, const char* name, hulk_intptr owner, void* self, int flag);
};

class Resource_1faa80 {
public:
    void FUN_003375a0();
};

class Loader_1faa80 {
public:
    char pad0[4];
    Resource_1faa80* res;
    bool FUN_001faa80(int a, int b);
};

bool Loader_1faa80::FUN_001faa80(int a, int b) {
    MyBufferStream stream(a, b);
    StreamLoader loader;
    loader.FUN_00337870();
    if (loader.FUN_00337a30(&stream, "buffer", (hulk_intptr)res, this, 0)) {
        loader.FUN_00337890();
        return true;
    }
    res->FUN_003375a0();
    loader.FUN_00337890();
    return false;
}
} // namespace fn_001faa80


// 0x001fab00 FUN_001fab00 (106 B): equivalent/0x001fab00.cpp [wrapped: conflict: MyBufferStream]
// sym: ?Load@Loader_1fab00@fn_001fab00@@QAE_NUArgSlot_1fab00@2@@Z
namespace fn_001fab00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fab00 @ 0x001fab00
class MyBufferStream {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool vfunc_4();
    void* buffer;
    int size;
    int position;
    MyBufferStream(void* b, int s) : buffer(b), size(s), position(0) {}
};

struct Converter;
struct Loader_1fab00;

// The two stack argument words double as a tiny scoped object whose first word
// is overwritten with a vptr after it has been read.
struct ArgSlot_1fab00 {
    void* word0;
    int word1;
    void FUN_00337c00();
    void FUN_00337c10();
};

extern "C" bool __stdcall FUN_00337c20(MyBufferStream* stream, const char* name, Converter* converter, Loader_1fab00* loader);

struct Loader_1fab00 {
    char pad00[4];
    Converter* converter;   // 0x04
    bool Load(ArgSlot_1fab00 args);
};

bool Loader_1fab00::Load(ArgSlot_1fab00 args)
{
    MyBufferStream stream(args.word0, args.word1);
    args.FUN_00337c00();
    if (FUN_00337c20(&stream, "buffer", converter, this)) {
        args.FUN_00337c10();
        return true;
    }
    args.FUN_00337c10();
    return false;
}
} // namespace fn_001fab00


// 0x001fab70 CGameDataHandler::vfunc_1 (194 B): matches/0x001fab70.cpp [wrapped: conflict: CGameDataHandler]
// sym: ?vfunc_1@CGameDataHandler@fn_001fab70@@UAE_NPAUReq_1fab70@2@@Z
namespace fn_001fab70 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int strcmp(const char*, const char*);
#endif

struct Item_1fab70 {
    virtual void a();
    virtual void b(void* p);
};
struct List_1fab70 {
    virtual void a();
    virtual void b();
    virtual int Count();
    virtual const char* Get(int i);
};
struct Req_1fab70 {
    int pad;
    char* d;
};
class CGameDataHandler {
  public:
    virtual void vfunc_0();
    virtual bool vfunc_1(Req_1fab70* r);
    int pad;
    int n;
    List_1fab70* lists[1];
};
bool CGameDataHandler::vfunc_1(Req_1fab70* r) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lists[i]->Count(); j++) {
            char* d = r->d;
            if (strcmp(d + 4, lists[i]->Get(j)) == 0) {
                ((Item_1fab70*)lists[i])->b(r);
                return true;
            }
        }
    }
    return true;
}
} // namespace fn_001fab70


// 0x001fac40 FUN_001fac40 (17 B): matches/0x001fac40.cpp
// sym: ?FUN_001fac40@C_1fac40@owners@@QAEXH@Z
void owners::C_1fac40::FUN_001fac40(hulk_intptr x) {
    items[count] = ((int)x);
    ++count;
}


// 0x001fac60 FUN_001fac60 (30 B): matches/0x001fac60.cpp
// sym: ?FUN_001fac60@X_1fac60@owners@@QAEXXZ
void owners::X_1fac60::FUN_001fac60() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
}


// 0x001faca0 CDataHandlerObject::vfunc_2 (50 B): matches/0x001faca0.cpp [wrapped: conflict: CDataHandlerObject]
// sym: ?vfunc_2@CDataHandlerObject@fn_001faca0@@UAEPAXE@Z
namespace fn_001faca0 {
void __cdecl DestroyMember(void*);
void __cdecl DeleteObject(void*);
extern char CDataHandlerObject_vftable;
extern char IRefCount_vftable_1faca0;

class CDataHandlerObject {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void* vfunc_2(unsigned char flag);
    char pad[8];
};

void* CDataHandlerObject::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)&CDataHandlerObject_vftable;
    DestroyMember(*(void**)((char*)this + 12));
    *(void**)this = (void*)&IRefCount_vftable_1faca0;
    if (flag & 1) {
        DeleteObject(this);
    }
    return this;
}
} // namespace fn_001faca0


// 0x001fad00 MyFileStream::vfunc_1 (121 B): matches/0x001fad00.cpp [wrapped: conflict: MyFileStream]
// sym: ?vfunc_1@MyFileStream@fn_001fad00@@UAE_NUW_1fad00@2@@Z
namespace fn_001fad00 {
struct Iface_1fad00 {
    virtual void s0();
    virtual void Release();
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
    virtual void s14();
    virtual int Get15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void Call21();
    virtual int Get22();
    virtual bool Ok23();
};
struct W_1fad00 {
    int v;
    W_1fad00(const W_1fad00& o) { v = o.v; }
};
void __cdecl Init(Iface_1fad00** pp, W_1fad00 w, int a, int b, int c, int d, int e, int f);
class MyFileStream {
  public:
    virtual void vfunc_0();
    virtual bool vfunc_1(W_1fad00 x);
    Iface_1fad00* mIface;
    int mA;
    int mB;
};
bool MyFileStream::vfunc_1(W_1fad00 x) {
    Iface_1fad00** pp = &mIface;
    Init(pp, x, 0, 0, 1, 0, 1, 1);
    (*pp)->Call21();
    if ((*pp)->Ok23() && (*pp)->Get15() && (*pp)->Get22() == 0) {
        mB = (*pp)->Get15();
        mA = 0;
        return true;
    }
    (*pp)->Release();
    *pp = 0;
    return false;
}
} // namespace fn_001fad00


// 0x001fad80 MyFileStream::vfunc_2 (24 B): matches/0x001fad80.cpp
// sym: ?vfunc_2@MyFileStream@@UAEXXZ
// Same code shape as 0x000b3ef0 (propagated; names are from that function)
void MyFileStream::vfunc_2() {
    if ((*(Ref_1fad80 * *)&this->f_04)) {
        (*(Ref_1fad80 * *)&this->f_04)->Release();
        (*(Ref_1fad80 * *)&this->f_04) = 0;
    }
}


// 0x001fada0 MyFileStream::vfunc_3 (117 B): matches/0x001fada0.cpp
// sym: ?vfunc_3@MyFileStream@@UAEHPAXH@Z
int MyFileStream::vfunc_3(void* __p0, int len) { void * buf = (void *)__p0;

    int n = this->f_0c - this->f_08;
    if (n < len)
        len = n;
    int p0;
    (*(File_1fada0 * *)&this->f_04)->GetPos(&p0);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    (*(File_1fada0 * *)&this->f_04)->Read(buf, len, 1);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    int p1;
    (*(File_1fada0 * *)&this->f_04)->GetPos(&p1);
    (*(File_1fada0 * *)&this->f_04)->Sync();
    this->f_08 += p1 - p0;
    return p1 - p0;
}


// 0x001fae20 MyFileStream::vfunc_4 (26 B): matches/0x001fae20.cpp [wrapped: conflict: MyFileStream]
// sym: ?vfunc_4@MyFileStream@fn_001fae20@@UAE_NXZ
namespace fn_001fae20 {
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
    virtual bool f23();
};
class MyFileStream : public Stream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    void* mStream;
    int mPos;
    int mEnd;
    virtual bool vfunc_4();
};
bool MyFileStream::vfunc_4() {
    if (!mStream)
        return false;
    if (mPos >= mEnd)
        return false;
    return ((Stream*)mStream)->f23();
}
} // namespace fn_001fae20


// 0x001fae40 MyFileStream::vfunc_0 (31 B): matches/0x001fae40.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001fae40@@UAEPAV123@E@Z
namespace fn_001fae40 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class Stream_1fae40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public Stream_1fae40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001fae40


// 0x001fae60 MyBufferStream::vfunc_0 (31 B): matches/0x001fae60.cpp [wrapped: conflict: MyBufferStream]
// sym: ?vfunc_0@MyBufferStream@fn_001fae60@@UAEPAXI@Z
void operator delete(void*);
namespace fn_001fae60 {
extern void* g_vftable[];

class Stream_1fae60 {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~Stream_1fae60();
    int mRefCount;
};
class MyBufferStream : public Stream_1fae60 {
  public:
    virtual void* vfunc_0(unsigned int flags);
};
void* MyBufferStream::vfunc_0(unsigned int flags) {
    *(void**)this = g_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_001fae60

namespace fn_fa90982c {

// 0x001fae80 FUN_001fae80 (81 B): matches/0x001fae80.cpp
// sym: ??0CGameDataHandler_1fae80@fn_fa90982c@@QAE@XZ
CGameDataHandler_1fae80::CGameDataHandler_1fae80() throw() {
    vf = vGDH;
    void* m = FUN_0008d690(0x5110);
    Inner_1fae80* i;
    if (m)
        i = new (m) Inner_1fae80;
    else
        i = 0;
    p4 = i;
    _ReadWriteBarrier();
    p8 = 0;
    pc = 0;
    p10 = 0;
    p14 = 0;
    p18 = 0;
    p1c = 0;
    p20 = 0;
    p24 = 0;
    p28 = 0;
    p2c = 0;
    p30 = 0;
}

} // namespace fn_fa90982c

// 0x001faee0 CGameDataHandler::vfunc_0 (50 B): matches/0x001faee0.cpp [wrapped: conflict: CGameDataHandler]
// sym: ?vfunc_0@CGameDataHandler@fn_001faee0@@UAEPAV12@E@Z
namespace fn_001faee0 {
class CGameDataHandler;
class DataHandler {
  public:
    class ObjectCreator {
      public:
        virtual CGameDataHandler* vfunc_0(unsigned char);
        virtual void vfunc_1();
    };
};
class Ref_1faee0 {
  public:
    virtual void Release(int);
};
extern void* gGameVtable;
extern void* gBaseVtable;
class CGameDataHandler : public DataHandler::ObjectCreator {
  public:
    virtual CGameDataHandler* vfunc_0(unsigned char);
    virtual void vfunc_1();
    Ref_1faee0* mRef;
};
void thunk_FUN_00267090(CGameDataHandler*);
CGameDataHandler* CGameDataHandler::vfunc_0(unsigned char flags) {
    *(void**)this = &gGameVtable;
    if (mRef)
        mRef->Release(1);
    *(void**)this = &gBaseVtable;
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001faee0


// 0x001faf20 FUN_001faf20 (76 B): matches/0x001faf20.cpp [wrapped: conflict: MyFileStream]
// sym: ?Open@Owner_1faf20@fn_001faf20@@QAE_NH@Z
namespace fn_001faf20 {
extern "C" char DAT_0042502c[];
struct MyFileStream {
    hulk_intptr v;
    int a;
    int b;
    int c;
};
class Stream {
  public:
    bool Try(MyFileStream* s, int x);
    void Close();
};
class Owner_1faf20 {
  public:
    char pad[4];
    Stream* stream;
    bool Open(int x);
};
bool Owner_1faf20::Open(int x) {
    MyFileStream local;
    local.v = 0;
    local.a = 0;
    local.b = 0;
    local.c = 0;
    local.v = ((hulk_intptr)DAT_0042502c);
    if (stream->Try(&local, x))
        return true;
    stream->Close();
    return false;
}
} // namespace fn_001faf20

namespace fn_fa90982c {

// 0x001faf70 FUN_001faf70 (121 B): matches/0x001faf70.cpp
// sym: ?Target@Obj_1faf70@fn_fa90982c@@QAE_NH@Z
bool Obj_1faf70::Target(hulk_intptr arg) {
    Helper_1faf70 h;
    MyFileStream_1faf70 fs;
    fs.a = 0;
    fs.b = 0;
    fs.c = 0;
    h.Init();
    if (h.Try(&fs, arg, y, this, 0)) {
        h.Close();
        return true;
    }
    y->Fail();
    h.Close();
    return false;
}

} // namespace fn_fa90982c

// 0x001faff0 FUN_001faff0 (95 B): matches/0x001faff0.cpp [wrapped: conflict: MyFileStream]
// sym: ?Fn@Host_1faff0@fn_001faff0@@QAEDPAX@Z
namespace fn_001faff0 {
class Host_1faff0;
class MyFileStream {
  public:
    virtual void vf();
    int a, b, c;
    MyFileStream() : a(0), b(0), c(0) {}
};
class Wrapper_1faff0 {
  public:
    int dummy;
    MyFileStream stream;
    void Init() throw();
    void Close() throw();
    char Read(MyFileStream*, void*, int, Host_1faff0*) throw();
};
class Host_1faff0 {
  public:
    int x, y;
    char Fn(void* p);
};
char Host_1faff0::Fn(void* p) {
    Wrapper_1faff0 s;
    s.Init();
    if (s.Read(&s.stream, p, y, this)) {
        s.Close();
        return 1;
    }
    s.Close();
    return 0;
}
} // namespace fn_001faff0


// 0x001fb140 content::LoadInventory::DynamicCaster<CDataHandlerObject>::vfunc_0 (30 B): matches/0x001fb140.cpp [wrapped: conflict: CDataHandlerObject]
// sym: ?vfunc_0@CDataHandlerObject@fn_001fb140@@UAEPAXPAX@Z
namespace fn_001fb140 {
extern char DAT_0048d5bc;
extern char DAT_004c84c0;
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
class CDataHandlerObject {
  public:
    virtual void* vfunc_0(void* p);
};
void* CDataHandlerObject::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, (const void*)&DAT_0048d5bc, (const void*)&DAT_004c84c0, 0);
}
} // namespace fn_001fb140


// 0x001fb190 DataHandlerRawLoader::vfunc_2 (31 B): matches/0x001fb190.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001fb190@@UAEPAV123@E@Z
namespace fn_001fb190 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_1fb190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_1fb190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_001fb190

namespace fn_fa90982c {

// 0x001fb1e0 FUN_001fb1e0 (125 B): matches/0x001fb1e0.cpp
// sym: ?Fn@Owner_1fb1e0@fn_fa90982c@@QAEXXZ
// data: gManager_1fb1e0 = DAT_00527c58
void Owner_1fb1e0::Fn() {
    Obj_1fb1e0 local;
    local.a = MyFileStream_vftable;
    local.b = 0;
    local.c = 0;
    local.d = 0;
    if (!stream->Open(&local, "scripts/all_defs.dhd"))
        stream->Close();
    char* p = (char*)Alloc(0x18);
    if (p) {
        *(int*)(p + 4) = 0;
        *(int*)(p + 8) = 0x60000a00;
        *(int*)(p + 12) = 0;
        *(int*)(p + 16) = 0;
        *(void**)p = DataHandlerRawLoader_vftable;
        *(void**)(p + 20) = this;
    } else
        p = 0;
    (*(Manager_1fb1e0**)&DAT_00527c58)->Add(p, 0x60000a00);
}

} // namespace fn_fa90982c

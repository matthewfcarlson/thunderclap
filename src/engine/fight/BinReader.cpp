// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023b830..0x0023c2c0 (kind game, layer engine, confidence high), dominant class fight::BinReader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f1775e11 {
#define TREE_TU_END }
namespace fn_f1775e11 {} using namespace fn_f1775e11;
namespace fn_f1775e11 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned);
#endif
namespace fn_f1775e11 {
extern void* hulk_at_003f6098;
struct Obj_23b880 {
    void** vf;
    char pad[4];
    struct Ref_23b880* p;
};
struct Ref_23b880 {
    virtual void a();
    virtual void b();
};
class Delegate_23b8a0 {
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
    virtual int f24();
};
class DataReader_23b8a0 {
  public:
    char pad[8];
    Delegate_23b8a0* sub;
};
class ReaderInner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, int);
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
class Inner_23b8e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned int*);
    virtual void f7(unsigned int*);
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
extern void* refVtable_23b920;
struct Obj_23b920 {
    void** vf;
    char pad[4];
    struct Ref_23b920* p;
};
struct Ref_23b920 {
    virtual void a();
    virtual void b();
};
typedef unsigned int u32_23b950;
struct DataReader_23b950 {
    char pad[8];
    struct Helper_23b950* member;
};
struct Helper_23b950 {
    u32_23b950 call_002647e0(u32_23b950, u32_23b950, u32_23b950, u32_23b950);
};
class Helper_23b970 {
  public:
    unsigned int f1_00263fc0();
    unsigned int f2_00263fb0();
};
class Inner_23b9c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class Reader_23ba10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class BinReader {
  public:
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void vg();
    virtual void vh();
    virtual char vi(int, int, int, int);
    virtual void vj();
    virtual char vk(int, int, int);
    virtual void vl();
    virtual void vm();
    virtual void vn();
    virtual void vo();
    virtual void vp();
    virtual void vq();
    virtual void vr();
    virtual void vs();
    virtual void vt();
    char pad[8];
    unsigned char mode;
    char vfunc_6(int, int, int, int, int);
};
class Reader_23ba60 {
  public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
};
extern "C" char DAT_00428744[];
class Reader {
  public:
    virtual void Init();
};
class IFileDataReader_23baa0 {
  public:
    void* vf;
    int x;
    Reader* reader;
    IFileDataReader_23baa0(Reader* r);
};
class Inner_23bad0 {
  public:
    virtual void f0();
    virtual void f1();
};
class IFileDataReader {
  public:
    virtual void f0();
    virtual void f1();
    virtual IFileDataReader* v2(unsigned int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int pad;
    Inner_23bad0* inner;
};
extern int hulk_at_00428744;
extern int vtRef_23bad0;
extern void cleanup_00263f30(IFileDataReader*);
class Arg_23bb00 {
  public:
    virtual void Init();
};
extern int hulk_at_00428760;
class StreamDataReader {
  public:
    hulk_intptr vf;
    int a;
    Arg_23bb00* p;
    int q;
    StreamDataReader(Arg_23bb00* x, int y);
};
struct Stream {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Write(void* p, unsigned n);
};
struct BinReader_23bb90 {
    char p0[8];
    Stream* s;
    char p1;
    char sw;
    char p1b[0x12];
    unsigned remain;
    char p2[4];
    char buf[8];
    char pend;
    void Flush();
};
struct Rd_23bcb0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Read(char* buf, unsigned n);
};
class Source_23bd20 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, unsigned int);
};
class Stream_23bd90 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int Read(void*, int);
};
struct ThisCall_0023bb90 {
    void FUN_0023bb90();
};
} // namespace fn_f1775e11
namespace fight {
struct BinReader_nv_23c100 {
    void helper_0023bb90();
};
}
namespace fn_f1775e11 {
class Stream_23c110 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Read(void*, int);
};
} // namespace fn_f1775e11
namespace fight {
struct BinReader_nv_23c110 {
    void Prep_0023bb90();
};
}
namespace fight {
struct Reader_23c170 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
};
}
namespace fight {
struct BinReader_nv_23c170 {
    void init_0023bb90();
};
}
namespace fn_f1775e11 {
class Stream_23c1f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Read(void*, int);
};
struct BinReader_nv_23c1f0 {
    void Update_0023bb90();
};

} // namespace fn_f1775e11

// 0x0023b830 fight::BufferDataReader::vfunc_4 (62 B): matches/0x0023b830.cpp
// sym: ?vfunc_4@BufferDataReader@fight@@UAEHHH@Z
int fight::BufferDataReader::vfunc_4(hulk_intptr __p0, int __p1) { void * dst = (void *)__p0; unsigned int n = (unsigned int)__p1;

    unsigned available = this->f_10 - this->f_14;
    if (available < n)
        n = available;
    memcpy(dst, (*(char * *)&this->f_08) + this->f_14, n);
    this->f_14 += n;
    return (int)(n);
}


// 0x0023b870 fight::BufferDataReader::vfunc_5 (10 B): matches/0x0023b870.cpp
// sym: ?vfunc_5@BufferDataReader@fight@@UAE_NXZ
// Same code shape as 0x0023a430 (propagated; names are from that function)
bool fight::BufferDataReader::vfunc_5() {
    return this->f_14 >= this->f_10;
}

namespace fn_f1775e11 {

// 0x0023b880 FUN_0023b880 (25 B): matches/0x0023b880.cpp
// sym: ?target@fn_f1775e11@@YIXPAUObj_23b880@1@@Z
// Same code shape as 0x000af0d0 (propagated; names are from that function)
void __fastcall target(Obj_23b880* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&hulk_at_003f6098;
}

} // namespace fn_f1775e11

// 0x0023b8a0 fight::IFileDataReader::vfunc_3 (8 B): matches/0x0023b8a0.cpp
// sym: ?vfunc_3@IFileDataReader@fight@@UAEIXZ
// Same code shape as 0x0023a460 (propagated; names are from that function)
unsigned int fight::IFileDataReader::vfunc_3() {
    return (unsigned int)((*(Delegate_23b8a0 * *)&this->f_08)->f24());
}


// 0x0023b8b0 fight::IFileDataReader::vfunc_4 (39 B): matches/0x0023b8b0.cpp
// sym: ?vfunc_4@IFileDataReader@fight@@UAEHHH@Z
int fight::IFileDataReader::vfunc_4(hulk_intptr a, int b) {
    (*(ReaderInner * *)&this->f_08)->f3(a, b, 1);
    (*(ReaderInner * *)&this->f_08)->f21();
    return b;
}


// 0x0023b8e0 fight::IFileDataReader::vfunc_5 (64 B): matches/0x0023b8e0.cpp
// sym: ?vfunc_5@IFileDataReader@fight@@UAE_NXZ
bool fight::IFileDataReader::vfunc_5() {
    unsigned int b, a;
    (*(Inner_23b8e0 * *)&this->f_08)->f21();
    (*(Inner_23b8e0 * *)&this->f_08)->f6(&a);
    (*(Inner_23b8e0 * *)&this->f_08)->f7(&b);
    (*(Inner_23b8e0 * *)&this->f_08)->f21();
    return a >= b;
}

namespace fn_f1775e11 {

// 0x0023b920 FUN_0023b920 (25 B): matches/0x0023b920.cpp
// sym: ?target@fn_f1775e11@@YIXPAUObj_23b920@1@@Z
// Same code shape as 0x000af0d0 (propagated; names are from that function)
void __fastcall target(Obj_23b920* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&refVtable_23b920;
}

} // namespace fn_f1775e11

// 0x0023b940 fight::StreamDataReader::vfunc_3 (4 B): matches/0x0023b940.cpp
// sym: ?vfunc_3@StreamDataReader@fight@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int fight::StreamDataReader::vfunc_3() {
    return this->f_0c;
}


// 0x0023b950 fight::StreamDataReader::vfunc_4 (29 B): matches/0x0023b950.cpp
// sym: ?vfunc_4@StreamDataReader@fight@@UAEHHH@Z
int fight::StreamDataReader::vfunc_4(hulk_intptr __p0, int __p1) { u32_23b950 a = (u32_23b950)__p0; u32_23b950 b = (u32_23b950)__p1;

    (*(struct Helper_23b950 * *)&this->f_08)->call_002647e0(a, b, 1, 1);
    return (int)(b);
}


// 0x0023b970 fight::StreamDataReader::vfunc_5 (30 B): matches/0x0023b970.cpp
// sym: ?vfunc_5@StreamDataReader@fight@@UAE_NXZ
bool fight::StreamDataReader::vfunc_5() {
    unsigned int a = (*(Helper_23b970 * *)&this->f_08)->f1_00263fc0();
    unsigned int b = (*(Helper_23b970 * *)&this->f_08)->f2_00263fb0();
    return b <= a;
}


// 0x0023b990 FUN_0023b990 (25 B): matches/0x0023b990.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??1BinReader_23b990@fn_0023b990@@UAE@XZ
namespace fn_0023b990 {
class Reader {
  public:
    virtual void f();
    virtual void g();
};
class BinReader_23b990 {
  public:
    virtual void f();
    virtual ~BinReader_23b990();
    void Fin_00232c30();
    int pad4;
    Reader* reader;
};
void BinReader_23b990::f() {}
BinReader_23b990::~BinReader_23b990() {
    reader->g();
    Fin_00232c30();
}
} // namespace fn_0023b990


// 0x0023b9b0 fight::BinReader::vfunc_3 (4 B): matches/0x0023b9b0.cpp
// sym: ?vfunc_3@BinReader@fight@@UAEEXZ
unsigned char fight::BinReader::vfunc_3() {
    return *(unsigned char*)((char*)this + 0xC);
}


// 0x0023b9c0 fight::BinReader::vfunc_18 (8 B): matches/0x0023b9c0.cpp
// sym: ?vfunc_18@BinReader@fight@@UAEXXZ
// Same code shape as 0x0023b410 (propagated; names are from that function)
void fight::BinReader::vfunc_18() {
    (*(Inner_23b9c0 * *)&this->f_08)->f3();
}

namespace fn_f1775e11 {

// 0x0023b9d0 fight::BinReader::vfunc_19 (3 B): matches/0x0023b9d0.cpp
// sym: ?GetZero@fn_f1775e11@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f1775e11

// 0x0023ba10 fight::BinReader::vfunc_4 (8 B): matches/0x0023ba10.cpp
// sym: ?vfunc_4@BinReader@fight@@UAEXXZ
void fight::BinReader::vfunc_4() {
    (*(Reader_23ba10 * *)&this->f_08)->f();
}

namespace fn_f1775e11 {

// 0x0023ba20 fight::BinReader::vfunc_6 (56 B): matches/0x0023ba20.cpp
// sym: ?vfunc_6@BinReader@fn_f1775e11@@QAEDHHHHH@Z
char BinReader::vfunc_6(int p2, int p3, int p4, int p5, int p6) {
    if (mode)
        return vk(p2, p3, p4);
    else
        return vi(p2, p3, p5, p6);
}

} // namespace fn_f1775e11

// 0x0023ba60 fight::BinReader::vfunc_15 (7 B): matches/0x0023ba60.cpp
// sym: ?vfunc_15@BinReader@fight@@UAE_JXZ
 // namespace fight
__int64 fight::BinReader::vfunc_15() {
    return (__int64)(*(unsigned long long*)((char*)this + 0x18));
}


// 0x0023ba80 fight::DataReader::vfunc_2 (31 B): matches/0x0023ba80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0023ba80@@UAEPAV123@E@Z
namespace fn_0023ba80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class LoadObject_23ba80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public LoadObject_23ba80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0023ba80

namespace fn_f1775e11 {

// 0x0023baa0 FUN_0023baa0 (33 B): matches/0x0023baa0.cpp
// sym: ??0IFileDataReader_23baa0@fn_f1775e11@@QAE@PAVReader@1@@Z
IFileDataReader_23baa0::IFileDataReader_23baa0(Reader* r) {
    x = 0;
    vf = (void*)((hulk_intptr)DAT_00428744);
    reader = r;
    r->Init();
}


// 0x0023bad0 fight::IFileDataReader::vfunc_2 (45 B): matches/0x0023bad0.cpp
// sym: ?v2@IFileDataReader@fn_f1775e11@@UAEPAV12@I@Z
IFileDataReader* IFileDataReader::v2(unsigned int flags) {
    Inner_23bad0* p = inner;
    *(volatile hulk_intptr*)this = (hulk_intptr)&hulk_at_00428744;
    p->f1();
    *(volatile hulk_intptr*)this = (hulk_intptr)&vtRef_23bad0;
    if (flags & 1)
        cleanup_00263f30(this);
    return this;
}


// 0x0023bb00 FUN_0023bb00 (40 B): matches/0x0023bb00.cpp
// sym: ??0StreamDataReader@fn_f1775e11@@QAE@PAVArg_23bb00@1@H@Z
StreamDataReader::StreamDataReader(Arg_23bb00* x, int y) {
    a = 0;
    vf = (hulk_intptr)&hulk_at_00428760;
    q = y;
    p = x;
    p->Init();
}

} // namespace fn_f1775e11

// 0x0023bb30 fight::StreamDataReader::vfunc_2 (45 B): matches/0x0023bb30.cpp [wrapped: conflict: StreamDataReader]
// sym: ?vfunc_2@StreamDataReader@fn_0023bb30@@UAEPAV12@H@Z
namespace fn_0023bb30 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_00428760[];
class DataReader_23bb30 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
};
class StreamDataReader : public DataReader_23bb30 {
  public:
    virtual void D();
    virtual void E();
    virtual void F();
    int pad;
    DataReader_23bb30* mObj;
    virtual StreamDataReader* vfunc_2(int);
};
extern void Destroy_00263f30(StreamDataReader*);
StreamDataReader* StreamDataReader::vfunc_2(int flags) {
    DataReader_23bb30* p = mObj;
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_00428760);
    p->B();
    ((hulk_intptr*)this)[0] = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        Destroy_00263f30(this);
    return this;
}
} // namespace fn_0023bb30


// 0x0023bb60 fight::BinReader::vfunc_2 (46 B): matches/0x0023bb60.cpp [wrapped: conflict: BinReader]
// sym: ??_GBinReader@fn_0023bb60@@UAEPAXI@Z
namespace fn_0023bb60 {
class Obj_23bb60 {
  public:
    virtual void a();
    virtual void b();
};
class BinReader {
  public:
    virtual void Fna_00038290();
    virtual void Fnb_000382a0();
    virtual ~BinReader();
    virtual void f3_0023b9b0();
    virtual void f4_0023ba10();
    virtual bool f5_0023c040(int, int, void*);
    virtual char f6_0023ba20(int, int, int, int, int);
    virtual bool f7_0023bf10(int, int, void*);
    virtual bool f8_0023be00(int, int, void*, int);
    virtual char f9_0023bd20(int, int, void*);
    virtual bool f10_0023bcb0(int, int, void*);
    virtual bool f11_0023bc50(int, int, void*);
    virtual char f12_0023bd90(int, int, void*);
    virtual void f13_0023c0e0();
    virtual void f14_0023c100();
    virtual void f15_0023ba60();
    virtual hulk_intptr f16_0023c110(int, int);
    virtual void f17_0023c170();
    virtual void f18_0023b9c0();
    virtual void f19();
    char pad[4];
    Obj_23bb60* obj;
    void helper_00232c30();
};
BinReader::~BinReader() {
    obj->b();
    helper_00232c30();
}
} // namespace fn_0023bb60

namespace fn_f1775e11 {

// 0x0023bb90 FUN_0023bb90 (119 B): matches/0x0023bb90.cpp
// sym: ?Flush@BinReader_23bb90@fn_f1775e11@@QAEXXZ
void BinReader_23bb90::Flush() {
    if (pend) {
        unsigned junk;
        while (remain > 0) {
            unsigned n = remain;
            if (n > 4)
                n = 4;
            s->Write(&junk, n);
            remain -= n;
        }
        s->Write(buf, 8);
        if (sw) {
            char* a = &buf[0];
            char* b = a + 7;
            while (a < b) {
                char t = *a;
                *a = *b;
                a++;
                *b = t;
                b--;
            }
        }
        pend = 0;
    }
}

} // namespace fn_f1775e11

// 0x0023bc50 fight::BinReader::vfunc_11 (81 B): equivalent/0x0023bc50.cpp [wrapped: conflict: Stream; fight::BinReader]
// sym: ?vfunc_11@BinReader@fight@fn_0023bc50@@QAE_NHHPAE@Z @e358e26296b8 @w5a68f91e3153
namespace fn_0023bc50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::BinReader::vfunc_11 @ 0x0023bc50
struct Stream { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int read(void *, unsigned int); }; namespace fight { struct BinReader { void *vptr; char pad4[4]; Stream *stream; char padC[4]; int status; char pad14[12]; unsigned int remaining; bool vfunc_11(int a, int b, unsigned char *out); }; } bool fight::BinReader::vfunc_11(int a, int b, unsigned char *out) { status = -1; unsigned int value = *out; unsigned int count = remaining; if (count > 4) count = 4; int result = stream->read(&value, count); remaining -= count; *out = value != 0; return result == 4; }
} // namespace fn_0023bc50


// 0x0023bcb0 fight::BinReader::vfunc_10 (104 B): matches/0x0023bcb0.cpp
// sym: ?vfunc_10@BinReader@fight@@UAE_NHHPAX@Z
bool fight::BinReader::vfunc_10(int a, int b, void* __p2) { char * buf = (char *)__p2;

    int* q = &this->f_10;
    *q = -1;
    unsigned n = this->f_20;
    if (n > 4)
        n = 4;
    int r = (*(Rd_23bcb0 * *)&this->f_08)->Read(buf, n);
    this->f_20 -= n;
    bool ok = r == 4;
    if (this->f_0d) {
        char* hi = buf + 3;
        char* lo = buf;
        if (lo < hi) {
            do {
                char t = *lo;
                *lo = *hi;
                lo++;
                *hi = t;
                hi--;
            } while (lo < hi);
        }
    }
    return ok;
}


// 0x0023bd20 fight::BinReader::vfunc_9 (104 B): matches/0x0023bd20.cpp
// sym: ?vfunc_9@BinReader@fight@@UAEDHHPAX@Z
char fight::BinReader::vfunc_9(int x, int y, void* __p2) { char * buf = (char *)__p2;

    (*(volatile int *)&this->f_10) = -1;
    unsigned int n = (*(volatile unsigned int *)&this->f_20);
    if (n > 4)
        n = 4;
    int r = (*(Source_23bd20 * *)&this->f_08)->Read(buf, n);
    (*(volatile unsigned int *)&this->f_20) = (*(volatile unsigned int *)&this->f_20) - n;
    char result = (r == 4);
    if (this->f_0d) {
        char* a = buf;
        char* b = buf + 3;
        while (a < b) {
            char t = *a;
            *a = *b;
            *b = t;
            ++a;
            --b;
        }
    }
    return result;
}


// 0x0023bd90 fight::BinReader::vfunc_12 (100 B): matches/0x0023bd90.cpp
// sym: ?vfunc_12@BinReader@fight@@UAEDHHPAX@Z
char fight::BinReader::vfunc_12(int a, int b, void* __p2) { int * out = (int *)__p2;

    unsigned n = this->f_20;
    if (n > 4)
        n = 4;
    int got = (*(Stream_23bd90 * *)&this->f_08)->Read(&this->f_10, n);
    this->f_20 -= n;
    char ok = got == 4;
    if ((*(unsigned char *)&this->f_0d)) {
        unsigned char* p = (unsigned char*)&this->f_10;
        unsigned char* q = p + 3;
        if (p < q) {
            do {
                unsigned char t = *p;
                *p = *q;
                *q = t;
                ++p;
                --q;
            } while (p < q);
        }
    }
    *out = this->f_10;
    return ok;
}


// 0x0023be00 fight::BinReader::vfunc_8 (261 B): equivalent/0x0023be00.cpp [wrapped: conflict: Stream; fight::BinReader]
// sym: ?vfunc_8@BinReader@fight@fn_0023be00@@UAE_NHHPADH@Z @5dc3d1e95732 @wb6fec5ef90af
namespace fn_0023be00 {
// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 22/22)
// fight::BinReader::vfunc_8 @ 0x0023be00

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*,const void*,unsigned);
#endif

void* __cdecl FUN_00238190(int);
void* __cdecl FUN_00266e00(void*, unsigned);
extern "C" void __cdecl FUN_00267090(void*);
struct Stream {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual unsigned read(void*,unsigned);
};
namespace fight {
struct BinReader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual bool vfunc_8(int,int,char*,int);
 virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual bool vfunc_12(int,int,int*);
 char pad4[4]; Stream* stream; char padc[4]; int length; char pad14[12]; unsigned remaining;
};
bool BinReader::vfunc_8(int a,int b,char* output,int capacity) {
 if(length<0 && !vfunc_12(a,b,&length)) return false;
 bool success=true;
 if(length>0) {
 unsigned padded=((unsigned)length+3)&~3u;
 char* buffer=(char*)FUN_00266e00(FUN_00238190(1),padded+1);
 unsigned count=remaining;
 if(padded<count) count=padded;
 unsigned actual=stream->read(buffer,count);
 remaining-=count;
 success=actual==padded;
 if(output && capacity>0) {
 int copy=length<capacity?length:capacity;
 memcpy(output,buffer,(unsigned)copy);
 int end=length<capacity-1?length:capacity-1;
 output[end]=0;
 }
 FUN_00267090(buffer);
 } else if(output && capacity>0) output[0]=0;
 length=-1;
 return success;
}
}
} // namespace fn_0023be00


// 0x0023bf10 fight::BinReader::vfunc_7 (298 B): equivalent/0x0023bf10.cpp [wrapped: conflict: FUN_00266e00; Stream; fight::BinReader]
// sym: ?vfunc_7@BinReader@fight@fn_0023bf10@@UAE_NIIPAUValue_23bf10@3@@Z @b4982b75e445 @w1e0a9b9dc262
namespace fn_0023bf10 {
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/16, incomplete)
// fight::BinReader::vfunc_7 @ 0x0023bf10
struct Stream {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual int FUN_read(void*, unsigned);
};
struct Value_23bf10 { void FUN_0027af60(unsigned, unsigned); void FUN_0027b040(const char*); };
extern "C" void* __cdecl FUN_00238190(int);
extern "C" char* __cdecl FUN_00266e00(void*, hulk_uintptr);
extern "C" void __cdecl FUN_00267090(void*);
namespace fight {
struct BinReader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual bool vfunc_7(unsigned a, unsigned b, Value_23bf10* out);
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(unsigned,unsigned,unsigned*);
 char pad4[4]; Stream* stream; char padc; unsigned char reverse; unsigned char binary; char padf; int length; char pad14[12]; unsigned remaining;
};
bool BinReader::vfunc_7(unsigned a, unsigned b, Value_23bf10* out) {
 if(binary) {
  union { unsigned words[2]; unsigned char bytes[8]; } data;
  unsigned amount=remaining; if(amount>8) amount=8;
  int n=stream->FUN_read(&data,amount);
  bool ok=n==8;
  remaining-=amount;
  if(reverse) { for(int i=0;i<4;++i) { unsigned char t=data.bytes[i]; data.bytes[i]=data.bytes[7-i]; data.bytes[7-i]=t; } }
  out->FUN_0027af60(data.words[0],data.words[1]);
  return ok;
 }
 vfunc_12(a,b,&a);
 bool ok=true;
 if(length>0) {
  unsigned rounded=(unsigned(length)+3)&~3u;
  char* buf=FUN_00266e00(FUN_00238190(1),rounded+1);
  unsigned amount=remaining; if(rounded<amount) amount=rounded;
  int n=stream->FUN_read(buf,amount);
  remaining-=amount;
  ok=unsigned(n)==rounded;
  buf[length]=0;
  out->FUN_0027b040(buf);
  FUN_00267090(buf);
 } else { out->FUN_0027b040(0); }
 length=-1;
 return ok;
}
}
} // namespace fn_0023bf10


// 0x0023c040 fight::BinReader::vfunc_5 (159 B): equivalent/0x0023c040.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@BinReader@fight@fn_0023c040@@UAE_NHHPAE@Z @6eff0e2cce87 @w833617046cb4
namespace fn_0023c040 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 17/19, incomplete)
// fight::BinReader::vfunc_5 @ 0x0023c040
// fight::BinReader::vfunc_5 @ 0x0023c040: read a 12-byte record (three words), byte-swapping if needed
struct Stream {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int read(void *buf, unsigned int n);
};

namespace fight {

struct BinReader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2, unsigned char *buf);
    char pad04[4];
    Stream *stream;
    char padc;
    char swapBytes;
    char pade[2];
    int length;
    char pad14[0xc];
    unsigned int remaining;
};

static void reverse4(unsigned char *p)
{
    unsigned char *lo = p;
    unsigned char *hi = p + 3;
    while (lo < hi) {
        unsigned char t = *hi;
        *hi = *lo;
        *lo = t;
        lo++;
        hi--;
    }
}

bool BinReader::vfunc_5(int a1, int a2, unsigned char *buf)
{
    length = -1;
    unsigned int want = remaining;
    if (want > 12)
        want = 12;
    unsigned int got = stream->read(buf, want);
    remaining -= want;
    bool ok = got == 12;
    if (swapBytes) {
        reverse4(buf);
        if (swapBytes) {
            reverse4(buf + 4);
            if (swapBytes)
                reverse4(buf + 8);
        }
    }
    return ok;
}

}
} // namespace fn_0023c040


// 0x0023c0e0 fight::BinReader::vfunc_13 (26 B): equivalent/0x0023c0e0.cpp
// sym: ?vfunc_13@BinReader@fight@@UAEHXZ @40cfbabb1fb9 @w6ecc57449679
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// fight::BinReader::vfunc_13 @ 0x0023c0e0
int fight::BinReader::vfunc_13() {
    ((ThisCall_0023bb90*)(this))->FUN_0023bb90();
    return (this->f_28 | this->f_2c) != 0;
}


// 0x0023c100 fight::BinReader::vfunc_14 (16 B): matches/0x0023c100.cpp
// sym: ?vfunc_14@BinReader@fight@@UAE_JXZ
 // namespace fight
__int64 fight::BinReader::vfunc_14() {
    ((BinReader_nv_23c100*)this)->helper_0023bb90();
    return (__int64)(*(unsigned long long*)((char*)this + 0x28));
}


// 0x0023c110 fight::BinReader::vfunc_16 (90 B): matches/0x0023c110.cpp
// sym: ?vfunc_16@BinReader@fight@@UAE_JHH@Z
 // namespace fight
__int64 fight::BinReader::vfunc_16(int , int ) {
    ((BinReader_nv_23c110*)this)->Prep_0023bb90();
    this->f_18 = this->f_28;
    this->f_1c = this->f_2c;
    (*(Stream_23c110 * *)&this->f_08)->Read((*(char (*)[4])&this->f_20), 4);
    if (this->f_0d) {
        unsigned char* p = (unsigned char*)(*(char (*)[4])&this->f_20);
        unsigned char* q = p + 3;
        if (p < q)
            do {
                unsigned char t = *p;
                *p = *q;
                ++p;
                *q = t;
                --q;
            } while (p < q);
    }
    this->f_28 = 0;
    this->f_2c = 0;
    (*(char *)&this->f_30) = 1;
    return (__int64)(*(__int64*)&this->f_18);
}


// 0x0023c170 fight::BinReader::vfunc_17 (25 B): matches/0x0023c170.cpp
// sym: ?vfunc_17@BinReader@fight@@UAEXXZ
 // namespace fight
void fight::BinReader::vfunc_17() {
    ((BinReader_nv_23c170*)this)->init_0023bb90();
    this->f_18 = 0;
    this->f_1c = 0;
    (*(int *)&this->f_20) = 0;
    this->f_30 = 1;
}


// 0x0023c1c0 fight::BufferDataReader::vfunc_3 (4 B): matches/0x0023c1c0.cpp
// sym: ?vfunc_3@BufferDataReader@fight@@UAEIXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
unsigned int fight::BufferDataReader::vfunc_3() {
    return this->f_0c;
}


// 0x0023c1d0 fight::BufferDataReader::vfunc_2 (31 B): matches/0x0023c1d0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0023c1d0@@UAEPAV123@E@Z
namespace fn_0023c1d0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class DataReader_23c1d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public DataReader_23c1d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0023c1d0


// 0x0023c1f0 FUN_0023c1f0 (99 B): matches/0x0023c1f0.cpp
// sym: ?FUN_0023c1f0@BinReader@fight@@QAEXXZ
void fight::BinReader::FUN_0023c1f0() {
    int x;
    (*(Stream_23c1f0 * *)&this->f_08)->Read(&x, 4);
    char y[4] = {0, 0, 0, 0};
    (*(Stream_23c1f0 * *)&this->f_08)->Read(y, 4);
    signed char k = y[0];
    this->f_0c = k & 1;
    int t = k;
    (*(unsigned char *)&this->f_0d) = ((unsigned int)t >> 1) & 1;
    (*(unsigned char *)&this->f_0e) = ((unsigned int)t >> 2) & 1;
    ((BinReader_nv_23c1f0*)this)->Update_0023bb90();
}


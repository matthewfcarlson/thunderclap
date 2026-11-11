// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00262e60..0x002634c0 (kind game, layer engine, confidence high), dominant class audio::HalRsdFileStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe2967ee {
#define TREE_TU_END }
namespace fn_fe2967ee {} using namespace fn_fe2967ee;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fe2967ee {
extern "C" char DAT_0042adc0[];
struct Stream {
    void* vptr;
    int arg;
    char pad[20];
    int field;
};
extern "C" Stream* __cdecl FUN_00247530(void*);
struct V {
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
    virtual void run();
};
class C_262ec0 {
    char pad[0x10];
};
extern void __fastcall f(void*);
class Device_262ee0 {
  public:
    virtual void f0();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void f1(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int Get();
};
} // namespace fn_fe2967ee
namespace audio {
class HalStream_262f20 { public: virtual void vfunc_0(); virtual int vfunc_1(); };
}
namespace fn_fe2967ee {
typedef unsigned int u32_262f70;
extern "C" u32_262f70 __cdecl FUN_0024c2c0(void*);
extern "C" u8 __cdecl FUN_0024c2b0(u32_262f70);
extern "C" u32_262f70 __cdecl FUN_0024c2f0(void*);
class Inner_262fc0 {
  public:
    void call();
};
struct Dev_262fe0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Read(int a, unsigned n, int b);
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
    virtual void Sync(unsigned* g);
};
void G1(unsigned*, int);
extern "C" void FUN_0026d890(unsigned*);
extern "C" void FUN_0026d880(unsigned*);
class HalRsdFileStream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned vfunc_7(int a, int b, unsigned n);
    char pad[0x20 - 4];
    Dev_262fe0* mDev;
    char pad2[0x2c - 0x24];
    unsigned mAvail;
    char pad3[0x3c - 0x30];
    unsigned mLen;
};
class HalStream_263050 {
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
};
class Device_263050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, unsigned, int);
};
class Device_2630c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int Get();
};
class Obj_2630c0 {
  public:
    char pad[0x20];
    Device_2630c0* dev;
    char p24[8];
    int result;
    int base;
    int value;
    int delta;
    char p3c[8];
    int state;
};
} // namespace fn_fe2967ee
namespace audio {
struct StreamHelper {};
}
namespace fn_fe2967ee {
extern "C" void* __fastcall FUN_0023fb00(audio::StreamHelper*);
void __cdecl thunk_FUN_002710d0(void**, void*, int, int, int, int, int, int);
struct Item_263300 {
    char pad[0x20];
    Item_263300* F(unsigned char);
};
void __cdecl FUN_00247550(void*, Item_263300*);
} // namespace fn_fe2967ee
namespace audio {
class Obj_263420 {
  public:
    virtual void f0();
    virtual void f1();
};
}
namespace audio {
struct Aux_263420 {
    void f();
};
}
namespace fn_fe2967ee {
void FUN_00247550(void*, void*);


// 0x00262e60 FUN_00262e60 (49 B): matches/0x00262e60.cpp
// sym: _FUN_00262e60
extern "C" Stream* __cdecl FUN_00262e60(int param) {
    Stream* p = FUN_00247530(((char*)&DAT_004e7b08));
    Stream* result = 0;
    if (p) {
        p->field = 0;
        p->vptr = (void*)((hulk_intptr)DAT_0042adc0);
        p->arg = param;
        result = p;
    }
    ((V*)result)->run();
    return result;
}


// 0x00262ec0 FUN_00262ec0 (20 B): matches/0x00262ec0.cpp
// sym: ?target@fn_fe2967ee@@YIXPAVC_262ec0@1@@Z
void __fastcall target(C_262ec0* self) {
    f((char*)self + 0x10);
    f((char*)self + 4);
}

} // namespace fn_fe2967ee

// 0x00262ee0 audio::HalRsdFileStream::vfunc_5 (52 B): matches/0x00262ee0.cpp
// sym: ?vfunc_5@HalRsdFileStream@audio@@UAEXH@Z
void audio::HalRsdFileStream::vfunc_5(int amount) {
    int end = this->f_34;
    if (!end)
        end = (*(Device_262ee0 * *)&this->f_20)->Get();
    int off = (end - (*(int *)&this->f_2c)) + amount;
    (*(int *)&this->f_2c) = end - off;
    (*(Device_262ee0 * *)&this->f_20)->f1(this->f_30 + off);
}


// 0x00262f20 audio::HalRsdFileStream::vfunc_1 (36 B): equivalent/0x00262f20.cpp
// sym: ?vfunc_1@HalRsdFileStream@audio@@UAEHXZ
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 9/9)
// audio::HalRsdFileStream::vfunc_1 @ 0x00262f20
int audio::HalRsdFileStream::vfunc_1() { switch (this->f_44) { case 0: return 0; case 1: case 3: return 1; case 4: case 5: case 6: return 2; default: return 3; } }


// 0x00262f60 audio::HalRsdFileStream::vfunc_2 (4 B): matches/0x00262f60.cpp
// sym: ?vfunc_2@HalRsdFileStream@audio@@UAEPAXXZ
// Same code shape as 0x00091d20 (propagated; names are from that function)
void* audio::HalRsdFileStream::vfunc_2() {
    return (void*)((char*)this + 0x28);
}


// 0x00262f70 audio::HalRsdFileStream::vfunc_3 (41 B): matches/0x00262f70.cpp
// sym: ?vfunc_3@HalRsdFileStream@audio@@UAEHXZ
 // namespace audio
int audio::HalRsdFileStream::vfunc_3() {
    void* p = (char*)this + 0x28;
    u32_262f70 x = FUN_0024c2c0(p);
    if (FUN_0024c2b0(x))
        return (int)(FUN_0024c2f0(p));
    return (int)(0x800);
}


// 0x00262fa0 audio::HalRsdFileStream::vfunc_9 (32 B): matches/0x00262fa0.cpp
// sym: ?vfunc_9@HalRsdFileStream@audio@@UAEPAXH@Z
void* audio::HalRsdFileStream::vfunc_9(int index) {
    if (!(*(char * *)&this->f_24))
        return (void*)((char*)((hulk_intptr)((char*)&DAT_0042ae14)));
    return (void*)((*(char * *)&this->f_24) + index * 16 + 0xa4);
}


// 0x00262fc0 audio::HalRsdFileStream::vfunc_10 (8 B): matches/0x00262fc0.cpp
// sym: ?vfunc_10@HalRsdFileStream@audio@@UAEXXZ
// Same code shape as 0x002226e0 (propagated; names are from that function)
void audio::HalRsdFileStream::vfunc_10() {
    ((Inner_262fc0*)((char*)this + 0x10))->call();
}


// 0x00262fd0 audio::HalRsdFileStream::vfunc_4 (4 B): matches/0x00262fd0.cpp
// sym: ?vfunc_4@HalRsdFileStream@audio@@UAEIXZ
// Same code shape as 0x000862b0 (propagated; names are from that function)
unsigned int audio::HalRsdFileStream::vfunc_4() {
    return *(unsigned int*)((char*)this + 0x2c);
}

namespace fn_fe2967ee {

// 0x00262fe0 audio::HalRsdFileStream::vfunc_7 (109 B): matches/0x00262fe0.cpp
// sym: ?vfunc_7@HalRsdFileStream@fn_fe2967ee@@UAEIHHI@Z
unsigned HalRsdFileStream::vfunc_7(int a, int b, unsigned n) {
    if (mAvail < n)
        mLen = mAvail;
    else
        mLen = n;
    if (mLen > 0) {
        G1(&n, 0);
        mDev->Read(a, mLen, b);
        mDev->Sync(&n);
        FUN_0026d890(&n);
        FUN_0026d880(&n);
    }
    return mLen;
}

} // namespace fn_fe2967ee

// 0x00263050 audio::HalRsdFileStream::vfunc_6 (72 B): matches/0x00263050.cpp
// sym: ?vfunc_6@HalRsdFileStream@audio@@UAEXHHI@Z
void audio::HalRsdFileStream::vfunc_6(int a, int b, unsigned int n) {
    if (this->f_2c < n)
        this->f_3c = this->f_2c;
    else
        this->f_3c = n;
    if (this->f_3c > 0) {
        (*(Device_263050 * *)&this->f_20)->v3(a, this->f_3c, b);
        this->f_44 = 5;
        return;
    }
    this->f_44 = 6;
}


// 0x002630a0 audio::HalRsdFileStream::vfunc_8 (32 B): matches/0x002630a0.cpp
// sym: ?vfunc_8@HalRsdFileStream@audio@@UAE_NPAX@Z
bool audio::HalRsdFileStream::vfunc_8(void* __p0) { int * out = (int *)__p0;

    if ((*(int *)&this->f_44) == 5)
        return false;
    *out = (*(int *)&this->f_3c);
    (*(int *)&this->f_44) = 4;
    return true;
}

namespace fn_fe2967ee {

// 0x002630c0 FUN_002630c0 (61 B): matches/0x002630c0.cpp
// sym: ?FUN@fn_fe2967ee@@YIXPAVObj_2630c0@1@@Z
void __fastcall FUN(Obj_2630c0* self) {
    int n = self->value;
    if (n == 0)
        n = self->dev->Get();
    self->result = n - self->delta - 0x800;
    self->dev->f5(self->base + self->delta + 0x800);
    self->state = 4;
}

} // namespace fn_fe2967ee

// 0x00263160 FUN_00263160 (136 B): equivalent/0x00263160.cpp [wrapped: conflict: audio::HalRsdFileStream]
// sym: ??0HalRsdFileStream@audio@fn_00263160@@QAE@PBD0HHHPAHH@Z
namespace fn_00263160 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00263160 @ 0x00263160
struct Text_263160 {
    char data[12];
    void FUN_00240170(const char *s);
    void FUN_0023fac0();
    void FUN_00240190(const char *s);
};

namespace audio {
class HalRsdFileStream {
public:
    HalRsdFileStream(const char *name, const char *path, int a3, int a4, int a5, int *a6, int a7);
    virtual void v0();
    Text_263160 name;
    Text_263160 path;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    unsigned char hasF28;
    char pad41[3];
    int f44;
};

HalRsdFileStream::HalRsdFileStream(const char *nameArg, const char *pathArg, int a3, int a4, int a5, int *a6, int a7)
{
    name.FUN_00240170(nameArg);
    path.FUN_0023fac0();
    f1c = a7;
    f30 = a3;
    f38 = a5;
    f44 = 0;
    f34 = a4;
    f3c = 0;
    f20 = 0;
    f2c = 0;
    f24 = 0;
    if (a6 == 0) {
        hasF28 = 0;
    } else {
        hasF28 = 1;
        f28 = *a6;
    }
    path.FUN_00240190(pathArg);
}
}
} // namespace fn_00263160


// 0x002631f0 FUN_002631f0 (146 B): equivalent/0x002631f0.cpp [wrapped: conflict: FUN_00247530; audio::HalRsdFileStream]
// sym: ?FUN_002631f0@fn_002631f0@@YAPAVHalRsdFileStream@audio@1@PBD0HHHPAHH@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_002631f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002631f0 @ 0x002631f0
// equiv-map: ??0Text@@QAE@PBDH@Z = 0x0023fc40
// equiv-map: ??1Text@@QAE@XZ = 0x00240060
// equiv-map: ??0HalRsdFileStream@audio@@QAE@ABUText@@0HHHPAHH@Z = 0x00263160



struct Text {
    char data[12];
    Text(const char *s, int flag) throw();
    ~Text() throw();
};

namespace audio {
class HalRsdFileStream {
public:
    HalRsdFileStream(const Text &name, const Text &path, int a3, int a4, int a5, int *a6, int a7) throw();
    virtual void v0();
    char body[0x44];
};
}

void *FUN_00247530(void *pool) throw();

audio::HalRsdFileStream *__cdecl FUN_002631f0(const char *name, const char *path, int a3, int a4, int a5, int *a6, int a7)
{
    void *mem = FUN_00247530(((char*)&DAT_004e7b98));
    if (mem == 0)
        return 0;
    return new (mem) audio::HalRsdFileStream(Text(name, 2), Text(path, 2), a3, a4, a5, a6, a7);
}
} // namespace fn_002631f0


// 0x002632c0 audio::HalRsdFileStream::vfunc_0 (62 B): equivalent/0x002632c0.cpp
// sym: ?vfunc_0@HalRsdFileStream@audio@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// audio::HalRsdFileStream::vfunc_0 @ 0x002632c0
// audio::HalRsdFileStream::vfunc_0 @ 0x002632c0
void audio::HalRsdFileStream::vfunc_0() {
    if ((*(void * *)&this->f_20) == 0) {
        int saved = this->f_1c;
        audio::StreamHelper* helper = (audio::StreamHelper*)((char*)this + 4);
        void* result = FUN_0023fb00(helper);
        thunk_FUN_002710d0(&(*(void * *)&this->f_20), result, 0, 0, saved, 0, 1, 1);
    }
    (*(int *)&this->f_44) = 1;
}

namespace fn_fe2967ee {

// 0x00263300 FUN_00263300 (46 B): matches/0x00263300.cpp
// sym: ?F@Item_263300@fn_fe2967ee@@QAEPAU12@E@Z
Item_263300* Item_263300::F(unsigned char flags) {
    ((owners::Str_240060 *)(((Item_263300*)((char*)this + 0x10))))->FUN_00240060();
    ((owners::Str_240060 *)(((Item_263300*)((char*)this + 4))))->FUN_00240060();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e7b98), this);
    return this;
}

} // namespace fn_fe2967ee

// 0x00263420 audio::HalRsdFileStream::vfunc_12 (70 B): matches/0x00263420.cpp
// sym: ?vfunc_12@HalRsdFileStream@audio@@UAEXXZ
void audio::HalRsdFileStream::vfunc_12() {
    if ((*(Obj_263420 * *)&this->f_20))
        (*(Obj_263420 * *)&this->f_20)->f1();
    if ((*(void * *)&this->f_24))
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e7b50))), (*(void * *)&this->f_24));
    ((audio::Aux_263420*)((char*)this + 0x10))->f();
    ((audio::Aux_263420*)((char*)this + 4))->f();
    FUN_00247550((void*)((hulk_intptr)((char*)&DAT_004e7b98)), this);
}

namespace fn_fe2967ee {

// 0x00263470 FUN_00263470 (1 B): matches/0x00263470.cpp
// sym: ?FUN_00263470@fn_fe2967ee@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00263470() {}

} // namespace fn_fe2967ee

// 0x00263480 FUN_00263480 (42 B): matches/0x00263480.cpp [wrapped: conflict: FUN_00263480]
// sym: _FUN_00263480
namespace fn_00263480 {
extern "C" int __cdecl FUN_0024c1c0(void*);
extern "C" void __cdecl FUN_0024c330(int, int, int, int, int);
struct S_263480 {
    char pad[4];
    int a;
    int b;
    int c;
    int d;
};
extern "C" void __cdecl FUN_00263480(hulk_intptr p1, S_263480* p2) {
    int x = FUN_0024c1c0(&p2->a);
    FUN_0024c330(p1, x, p2->d, p2->b, p2->c);
}
} // namespace fn_00263480


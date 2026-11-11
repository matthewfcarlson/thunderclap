// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00250960..0x00250d90 (kind game, layer engine, confidence high), dominant class audio::SeqEventExpression
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbd591a0 {
#define TREE_TU_END }
namespace fn_fbd591a0 {} using namespace fn_fbd591a0;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fbd591a0 {
class Obj_250960 {
  public:
    char pad[8];
    char* Get();
};
extern "C" char DAT_00429c8c[];
class SeqEvent_2509c0 {
  public:
    SeqEvent_2509c0();
};
class Text_2509c0 {
  public:
};
class SeqEventExpression : public SeqEvent_2509c0 {
  public:
    hulk_intptr vptr;
    char pad[4];
    Text_2509c0 text;
    SeqEventExpression();
};
} // namespace fn_fbd591a0
namespace audio {
class SeqEventNestTrack_2509f0 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[4];
};
}
namespace fn_fbd591a0 {
extern "C" bool __cdecl FUN_0025bce0(void*, void*);
struct Temp_250a80 {
    char bytes[12];
    void init_0023fac0();
};
extern "C" void FUN_002613b0(int, Temp_250a80*, int);
class SeqAction_250ad0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_250ae0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
typedef unsigned __int64 U64;
} // namespace fn_fbd591a0
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int);
namespace fn_fbd591a0 {
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char data[12];
};
class FUN_002605e0 {
  public:
    virtual void v();
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
};
class SeqEventExpressionType_250b20 : public FUN_002605e0 {
  public:
    SeqEventExpressionType_250b20();
    virtual void v();
};
typedef unsigned int u32_250ba0;
extern "C" void* __cdecl FUN_00247530(void*);
extern int hulk_at_00429c8c;
class NameObj_250ba0 {
  public:
};
class NestTrack_250ba0 {
  public:
    hulk_uintptr vf;
    char pad[4];
    NameObj_250ba0 name;
    void init_0025fd00();
};
struct Stm_250c10 {
    char pad[0x24];
    int depth;
};
extern bool Match_00246f50(Stm_250c10*, const char*, ...);
extern "C" bool FUN_0024e600(Stm_250c10**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_250c10**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventExpression_250c10 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_250c10**);
};
extern "C" void* __cdecl allocate(void*);
} // namespace fn_fbd591a0
namespace audio {
class SeqActionExpression_250cd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[4];
    audio::SeqEventExpression* owner;
    int val;
    SeqActionExpression_250cd0(audio::SeqEventExpression* p) : owner(p), val(0) {}
    static void* operator new(size_t) { return allocate(&bss); }
};
}
namespace audio {
class Engine {
  public:
    void send_0025dc20(SeqActionExpression_250cd0*);
};
}
namespace audio {
class SeqEvent_250cd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
}

namespace fn_fbd591a0 {

// 0x00250960 FUN_00250960 (4 B): matches/0x00250960.cpp
// sym: ?Get@Obj_250960@fn_fbd591a0@@QAEPADXZ
char* Obj_250960::Get() {
    return pad + 8;
}

// 0x00250990 audio::SeqEventExpressionType::vfunc_0 (5 B): not yet verified
// 0x002509a0 audio::SeqEventExpressionType::vfunc_1 (5 B): not yet verified

// 0x002509b0 FUN_002509b0 (6 B): matches/0x002509b0.cpp
// sym: _FUN_002509b0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002509b0() {
    return &(*(int*)&DAT_004e6b18);
}


// 0x002509c0 FUN_002509c0 (33 B): matches/0x002509c0.cpp
// sym: ??0SeqEventExpression@fn_fbd591a0@@QAE@XZ
// data: expr = DAT_00429ca4
SeqEventExpression::SeqEventExpression() {
    vptr = ((hulk_intptr)DAT_00429c8c);
    ((owners::String_23fc40 *)&text)->FUN_0023fc40(DAT_00429ca4, (hulk_intptr)2);
}

} // namespace fn_fbd591a0

// 0x002509f0 audio::SeqEventExpression::vfunc_0 (52 B): matches/0x002509f0.cpp
// sym: ?vfunc_0@SeqEventNestTrack_2509f0@audio@@UAEHPAX@Z
// Same code shape as 0x0024e590 (propagated; names are from that function)
int audio::SeqEventNestTrack_2509f0::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8))
            return 1;
    }
    return 0;
}

namespace fn_fbd591a0 {

// 0x00250a30 audio::SeqEventExpression::vfunc_3 (6 B): matches/0x00250a30.cpp
// sym: _FUN_00250a30
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00250a30() {
    return &(*(int*)&DAT_004e6b18);
}

} // namespace fn_fbd591a0

// 0x00250a40 audio::SeqActionExpression::vfunc_6 (34 B): matches/0x00250a40.cpp
// sym: ?vfunc_6@SeqActionExpression@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionExpression::vfunc_6(hulk_intptr ) {
    int i = this->f_0c;
    --i;
    if (i != 0) {
        i -= 3;
        if (i != 0) {
            --i;
            if (i == 0)
                this->f_0c = 0;
            return;
        }
    }
    this->f_0c = 2;
}


// 0x00250a70 audio::SeqActionExpression::vfunc_2 (10 B): matches/0x00250a70.cpp
// sym: ?vfunc_2@SeqActionExpression@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionExpression::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00250a80 audio::SeqActionExpression::vfunc_1 (69 B): matches/0x00250a80.cpp
// sym: ?vfunc_1@SeqActionExpression@audio@@UAEXPAX@Z
void audio::SeqActionExpression::vfunc_1(void* __p0) { hulk_intptr p = (hulk_intptr)__p0;

    Temp_250a80 t;
    t.init_0023fac0();
    FUN_002613b0(*(int*)(p + 0x3c) + 0x5c, &t, this->f_08 + 8);
    this->f_0c = 0;
    ((owners::Str_240060 *)&t)->FUN_00240060();
}


// 0x00250ad0 audio::SeqActionExpression::vfunc_3 (10 B): matches/0x00250ad0.cpp
// sym: ?vfunc_3@SeqActionExpression@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionExpression::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00250ae0 audio::SeqActionExpression::vfunc_4 (10 B): matches/0x00250ae0.cpp
// sym: ?vfunc_4@SeqActionExpression@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionExpression::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00250af0 audio::SeqActionExpression::vfunc_5 (6 B): matches/0x00250af0.cpp
// sym: ?vfunc_5@SeqActionExpression@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionExpression::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fbd591a0 {

// 0x00250b20 FUN_00250b20 (86 B): matches/0x00250b20.cpp
// sym: ??0SeqEventExpressionType_250b20@fn_fbd591a0@@QAE@XZ
SeqEventExpressionType_250b20::SeqEventExpressionType_250b20()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("$Exp", 0), FUN_002672f0("SeqEventExpression", 0, 0), (int)sizeof(AudioSeqEventExpression), (int)__alignof(AudioSeqEventExpression)) { HULK_SIZE32(AudioSeqEventExpression, 0x14); }

} // namespace fn_fbd591a0

// 0x00250b80 audio::SeqEventExpressionType::vfunc_2 (30 B): matches/0x00250b80.cpp
// sym: ??_GSeqEventExpressionType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventExpressionType::~SeqEventExpressionType() {}


// 0x00250ba0 audio::SeqEventExpressionType::vfunc_3 (56 B): matches/0x00250ba0.cpp
// sym: ?vfunc_3@SeqEventExpressionType@audio@@UAEPAXXZ
// Same code shape as 0x0024e6f0 (propagated; names are from that function)
// data: gName_250ba0 = DAT_00429ca4, gPool_250ba0 = DAT_004e6b18
void* audio::SeqEventExpressionType::vfunc_3() {
    NestTrack_250ba0* p = (NestTrack_250ba0*)FUN_00247530(((char*)&DAT_004e6b18));
    if (p) {
        p->init_0025fd00();
        p->vf = (hulk_uintptr)&hulk_at_00429c8c;
        ((owners::String_23fc40 *)&(p->name))->FUN_0023fc40(DAT_00429ca4, (hulk_intptr)2);
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00250be0 audio::SeqEventExpression::vfunc_4 (45 B): matches/0x00250be0.cpp [wrapped: conflict: SeqEventExpression]
// sym: ?v4@SeqEventExpression@fn_00250be0@@UAEPAV12@H@Z
namespace fn_00250be0 {

class Helper_250be0 {
  public:
    void Fn_00240060();
};
class SeqEventExpression {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventExpression* v4(int);
    virtual void v5();
    void Fn_0025fd10();
    char pad[8];
};
extern "C" void __cdecl FUN_00247550(void*, void*);
SeqEventExpression* SeqEventExpression::v4(int x) {
    ((Helper_250be0*)((char*)this + 8))->Fn_00240060();
    this->Fn_0025fd10();
    if (x & 1)
        FUN_00247550(((char*)&DAT_004e6b18), this);
    return this;
}
} // namespace fn_00250be0

namespace fn_fbd591a0 {

// 0x00250c10 audio::SeqEventExpression::vfunc_1 (111 B): matches/0x00250c10.cpp
// sym: ?vfunc_1@SeqEventExpression_250c10@fn_fbd591a0@@QAEHPAPAUStm_250c10@2@@Z
// data: sClose = DAT_004298dc, sName_00429b00 = DAT_00429b00, sOpen = DAT_004298f4
int SeqEventExpression_250c10::vfunc_1(Stm_250c10** p) {
    if (SeqEvent::v1(p)) {
        if (Match_00246f50(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (FUN_0024e600(p, DAT_00429b00, (char*)this + 8)) {
                (*p)->depth--;
                Stm_250c10* s = *p;
                if (Match_00246f50(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}

} // namespace fn_fbd591a0

// 0x00250ca0 audio::SeqActionExpression::vfunc_0 (36 B): matches/0x00250ca0.cpp [wrapped: conflict: audio::SeqActionExpression]
// sym: ?vfunc_0@SeqActionExpression@audio@fn_00250ca0@@UAEPAV123@H@Z
namespace fn_00250ca0 {

class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
namespace audio {
class SeqActionExpression : public SeqAction {
  public:
    virtual SeqActionExpression* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
extern void* hulk_at_004298fc[];
audio::SeqActionExpression* audio::SeqActionExpression::vfunc_0(int x) {
    *(void**)this = hulk_at_004298fc;
    if (x & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6ad0), this);
    return this;
}
} // namespace fn_00250ca0


// 0x00250cd0 audio::SeqEventExpression::vfunc_2 (66 B): matches/0x00250cd0.cpp
// sym: ?vfunc_2@SeqEventExpression@audio@@UAEXH@Z
 // namespace audio
void audio::SeqEventExpression::vfunc_2(hulk_intptr __p0) { audio::Engine * e = (audio::Engine *)__p0;

    e->send_0025dc20(new audio::SeqActionExpression_250cd0(this));
}


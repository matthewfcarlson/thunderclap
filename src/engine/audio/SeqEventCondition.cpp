// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0024fc30..0x00250080 (kind game, layer engine, confidence high), dominant class audio::SeqEventCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f150b671 {
#define TREE_TU_END }
namespace fn_f150b671 {} using namespace fn_f150b671;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f150b671 {
struct SeqEventCondition_nv_24fc60 {
    bool Base0_0025fd20(void*);
    bool Base1_002607c0(void*);
};
extern "C" bool FUN_0025bce0(void*, void*);
class SeqEvent_24fd90 {
  public:
    char vfunc_1_0025fd40(int*);
};
class SeqEventContainer_24fd90 {
  public:
    char vfunc_1_00260840(int*);
};
extern "C" char Parse(const char*, const char*, ...);
extern "C" char Expr_0024e600(int*, const char*, char*);
extern void* hulk_at_00429b1c[];
class SeqEvent_24fe70 {
  public:
    void* vptr;
    ~SeqEvent_24fe70() throw();
};
class SeqEventContainer : public SeqEvent_24fe70 {
  public:
    SeqEventContainer();
    char _m_pad_4[0x4];
    int m8;
    int mc;
    int m10;
};
class SeqEventCondition : public SeqEventContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventCondition* vfunc_4(unsigned char);
    virtual void v5();
};
class A_24fee0 {
  public:
    void Fnf_00240060();
};
class SeqEventCondition_24fee0 {
  public:
    void Fnf_002607a0();
};
void __cdecl f47550_00247550(void*, SeqEventCondition*);
extern void* __cdecl alloc(void*);
} // namespace fn_f150b671
inline void* operator new(size_t, void* heap) {
    return alloc(heap);
}
namespace audio {
class SeqCommandCondition_24ff10 {
  public:
    virtual void f0() {}
    virtual void f1() {}
    char pad[4];
    audio::SeqEventCondition* owner;
    int value;
    SeqCommandCondition_24ff10(audio::SeqEventCondition* p) : owner(p), value(-1) {}
};
}
namespace audio {
class Receiver {
  public:
    void send_0025dba0(SeqCommandCondition_24ff10*);
};
}

// 0x0024fc30 audio::SeqEventConditionType::vfunc_0 (5 B): not yet verified
// 0x0024fc40 audio::SeqEventConditionType::vfunc_1 (5 B): not yet verified
namespace fn_f150b671 {

// 0x0024fc50 FUN_0024fc50 (6 B): matches/0x0024fc50.cpp
// sym: _FUN_0024fc50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024fc50() {
    return &(*(int*)&DAT_004e68f8);
}

} // namespace fn_f150b671

// 0x0024fc60 audio::SeqEventCondition::vfunc_0 (64 B): matches/0x0024fc60.cpp
// sym: ?vfunc_0@SeqEventCondition@audio@@UAEHPAX@Z
int audio::SeqEventCondition::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((SeqEventCondition_nv_24fc60*)this)->Base0_0025fd20(arg) && ((SeqEventCondition_nv_24fc60*)this)->Base1_002607c0(arg) && FUN_0025bce0(arg, (char*)&this->f_14))
        return 1;
    return 0;
}

namespace fn_f150b671 {

// 0x0024fca0 audio::SeqEventCondition::vfunc_3 (6 B): matches/0x0024fca0.cpp
// sym: _FUN_0024fca0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024fca0() {
    return &(*(int*)&DAT_004e68f8);
}

} // namespace fn_f150b671

// 0x0024fd10 FUN_0024fd10 (86 B): matches/0x0024fd10.cpp [wrapped: conflict: audio::SeqEventConditionType]
// sym: ??0SeqEventConditionType@audio@fn_0024fd10@@QAE@XZ
namespace fn_0024fd10 {
// data: name1 = DAT_00429aec, name2 = DAT_00429ae4

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
class FUN_00240060 {
    char pad[12];

  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
namespace audio {
class FUN_002605e0 {
  public:
    virtual void V();
    FUN_002605e0(FUN_00240060*, const __int64*, int, int) throw();
};
class SeqEventConditionType : public FUN_002605e0 {
  public:
    virtual void V();
    SeqEventConditionType() throw();
};
} // namespace audio
audio::SeqEventConditionType::SeqEventConditionType() throw()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40(DAT_00429ae4, 0), &(__int64 const&)FUN_002672f0(DAT_00429aec, 0, 0), (int)sizeof(AudioSeqEventCondition), (int)__alignof(AudioSeqEventCondition)) { HULK_SIZE32(AudioSeqEventCondition, 0x20); }
} // namespace fn_0024fd10


// 0x0024fd70 audio::SeqEventConditionType::vfunc_2 (30 B): matches/0x0024fd70.cpp
// sym: ??_GSeqEventConditionType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventConditionType::~SeqEventConditionType() {}


// 0x0024fd90 audio::SeqEventCondition::vfunc_1 (119 B): matches/0x0024fd90.cpp
// sym: ?vfunc_1@SeqEventCondition@audio@@UAEHPAX@Z
int audio::SeqEventCondition::vfunc_1(void* __p0) { int * p = (int *)__p0;

    if (((SeqEvent_24fd90*)this)->vfunc_1_0025fd40(p) && Parse((const char*)*(hulk_intptr*)p, "\n[\n")) {
        ++*(int*)((char*)*(hulk_intptr*)p + 0x24);
        if (((SeqEventContainer_24fd90*)this)->vfunc_1_00260840(p) && Expr_0024e600(p, "mExpression", (char*)&this->f_14)) {
            --*(int*)((char*)*(hulk_intptr*)p + 0x24);
            p = (int*)*(hulk_intptr*)p;
            if (Parse((const char*)p, "]\n"))
                return 1;
        }
    }
    return 0;
}


// 0x0024fe30 audio::SeqCommandCondition::vfunc_1 (36 B): matches/0x0024fe30.cpp [wrapped: conflict: audio::SeqCommand; audio::SeqCommandCondition]
// sym: ?vfunc_1@SeqCommandCondition@audio@fn_0024fe30@@UAEPAV123@H@Z
namespace fn_0024fe30 {

extern "C" char DAT_00429ac8[];
namespace audio {
class SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommand* vfunc_1(int);
};
class SeqCommandCondition : public SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommandCondition* vfunc_1(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
audio::SeqCommandCondition* audio::SeqCommandCondition::vfunc_1(int arg) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00429ac8);
    if (arg & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e68b0), this);
    return this;
}
} // namespace fn_0024fe30

namespace fn_f150b671 {

// 0x0024fe70 FUN_0024fe70 (29 B): matches/0x0024fe70.cpp
// sym: ??0SeqEventContainer@fn_f150b671@@QAE@XZ
SeqEventContainer::SeqEventContainer() {
    SeqEvent_24fe70::~SeqEvent_24fe70();
    int* q = &m8;
    *q = 0;
    vptr = hulk_at_00429b1c;
    _ReadWriteBarrier();
    mc = 0;
    m10 = 0;
}

} // namespace fn_f150b671

// 0x0024fe90 audio::SeqEventContainer::vfunc_4 (30 B): matches/0x0024fe90.cpp
// sym: ??_GSeqEventContainer@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventContainer::~SeqEventContainer() {}


// 0x0024feb0 FUN_0024feb0 (44 B): equivalent/0x0024feb0.cpp [wrapped: conflict: audio::SeqEventCondition]
// sym: ??0SeqEventCondition@audio@fn_0024feb0@@QAE@XZ @a8b5497ff94b @w7514f2ddd10f
namespace fn_0024feb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024feb0 @ 0x0024feb0

struct Part { void FUN_0023fc40(const void *, int); };
struct FUN_0025fd00 { virtual void dummy(); FUN_0025fd00(); char pad04[4]; };
namespace audio {
struct SeqEventCondition : FUN_0025fd00 {
    int field08;
    int field0c;
    int field10;
    Part part14;
    SeqEventCondition();
    virtual void dummy();
};
}
audio::SeqEventCondition::SeqEventCondition() {
    field08 = 0;
    field0c = 0;
    field10 = 0;
    part14.FUN_0023fc40(((unsigned char*)&DAT_00429b50), 2);
}
} // namespace fn_0024feb0

namespace fn_f150b671 {

// 0x0024fee0 audio::SeqEventCondition::vfunc_4 (45 B): matches/0x0024fee0.cpp
// sym: ?vfunc_4@SeqEventCondition@fn_f150b671@@UAEPAV12@E@Z
// data: gBss_24fee0 = DAT_004e68f8
SeqEventCondition* SeqEventCondition::vfunc_4(unsigned char flag) {
    ((A_24fee0*)((char*)&this->m10))->Fnf_00240060();
    ((SeqEventCondition_24fee0*)this)->Fnf_002607a0();
    if (flag & 1)
        f47550_00247550(((char*)&DAT_004e68f8), this);
    return this;
}

} // namespace fn_f150b671

// 0x0024ff10 audio::SeqEventCondition::vfunc_2 (66 B): matches/0x0024ff10.cpp
// sym: ?vfunc_2@SeqEventCondition@audio@@UAEXH@Z
 // namespace audio
void audio::SeqEventCondition::vfunc_2(hulk_intptr __p0) { Receiver * r = (Receiver *)__p0;

    r->send_0025dba0(new (&bss) SeqCommandCondition_24ff10(this));
}


// 0x0024ff60 audio::SeqCommandCondition::vfunc_0 (198 B): equivalent/0x0024ff60.cpp [wrapped: conflict: audio::SeqCommand; audio::SeqCommandCondition]
// sym: ?vfunc_0@SeqCommandCondition@audio@fn_0024ff60@@UAEIPAUContext@23@@Z @5a823d56f97a @wda20728ff822
namespace fn_0024ff60 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 14/14)
// audio::SeqCommandCondition::vfunc_0 @ 0x0024ff60

namespace audio {
struct Context;
struct Node { virtual void slot0(); virtual void slot1(); virtual void slot2(Context*); void* next; };
struct Data_24ff60 { char pad[12]; void* first; char pad2[4]; char expression[1]; };
struct Temp_24ff60 { char bytes[12]; void FUN_0023fac0(); bool FUN_00240380(const char*); void FUN_00240060(); };
struct Source_24ff60 { char pad[0x5c]; char value[1]; };
struct SeqCommandCondition;
struct Context { char pad[0x3c]; Source_24ff60* source; int state; unsigned int FUN_0025dbd0(SeqCommandCondition*); };
struct SeqCommand { virtual unsigned int vfunc_0(Context*); virtual void vfunc_1(); char pad[4]; Data_24ff60* data; };
struct SeqCommandCondition : SeqCommand { Node* current; virtual unsigned int vfunc_0(Context*); };
}
extern "C" void __cdecl FUN_002613b0(void*, audio::Temp_24ff60*, void*);
unsigned int audio::SeqCommandCondition::vfunc_0(Context* context) {
 unsigned int state = context->state;
 if(state != 0 && state != 4) return state - 4;
 if(current == (Node*)-1) {
  Temp_24ff60 temp;
  temp.FUN_0023fac0();
  FUN_002613b0(context->source->value, &temp, data->expression);
  if(temp.FUN_00240380(DAT_00429b50)) {
   void* first = data->first;
   current = first ? (Node*)((char*)first - 4) : 0;
  } else current = 0;
  temp.FUN_00240060();
 }
 if(!current) return context->FUN_0025dbd0(this);
 current->slot2(context);
 void* next = current->next;
 current = next ? (Node*)((char*)next - 4) : 0;
 return (hulk_uintptr)current;
}
} // namespace fn_0024ff60


// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00254a50..0x00254e50 (kind game, layer engine, confidence high), dominant class audio::SeqEventLogicRepeat
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f524576d {
#define TREE_TU_END }
namespace fn_f524576d {} using namespace fn_f524576d;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f524576d {
extern "C" char DAT_0042a3e4[];
struct SeqEventContainer_254c20 {
    SeqEventContainer_254c20();
};
struct SeqEventLogicRepeat : SeqEventContainer_254c20 {
    char pad[8];
    int a[5];
    SeqEventLogicRepeat();
};
struct Seq {
    char pad[12];
    volatile int count;
    int unused;
    int a;
    int b;
};
class SeqCommand_254c80 {
  public:
    virtual void f();
};
class SeqCommandLogicRepeat_254c80 : public SeqCommand_254c80 {
  public:
    virtual void f();
    char pad[4];
    Seq* seq;
    int zero;
    hulk_intptr val;
    int count;
    SeqCommandLogicRepeat_254c80(Seq*);
};
} // namespace fn_f524576d
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_f524576d {
extern "C" void* __cdecl FUN_00247530(void*);
struct SeqEventContainer_254d80 {
    virtual void f0();
    SeqEventContainer_254d80() throw();
    int b4;
};
struct Init_254d80 {
    int m8, mc, m10, m14, m18;
    Init_254d80() throw() {
        m8 = 0;
        mc = 0;
        m10 = 0;
        _ReadWriteBarrier();
        m14 = 1;
        m18 = 1;
    }
};
struct SeqEventLogicRepeat_254d80 : SeqEventContainer_254d80, Init_254d80 {
    SeqEventLogicRepeat_254d80() throw() {}
    virtual void f0();
};
struct SeqEventLogicRepeat_254dd0;
struct SeqCommandLogicRepeat_nv_254dd0 {
    void* FUN_00254c80(SeqEventLogicRepeat_254dd0*);
};
struct Receiver {  };
struct SeqEventLogicRepeat_254dd0 {
    void vfunc_2(Receiver* receiver);
};

// 0x00254a50 audio::SeqEventLogicRepeatType::vfunc_0 (5 B): not yet verified
// 0x00254a60 audio::SeqEventLogicRepeatType::vfunc_1 (5 B): not yet verified

// 0x00254a70 FUN_00254a70 (6 B): matches/0x00254a70.cpp
// sym: _FUN_00254a70
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00254a70() {
    return &(*(int*)&DAT_004e73a8);
}

} // namespace fn_f524576d

// 0x00254a80 audio::SeqEventLogicRepeat::vfunc_0 (81 B): matches/0x00254a80.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventContainer; audio::SeqEventLogicRepeat]
// sym: ?vfunc_0@SeqEventLogicRepeat@audio@fn_00254a80@@UAEHPAX@Z
namespace fn_00254a80 {
namespace audio {
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
class SeqEventContainer : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
class SeqEventLogicRepeat : public SeqEventContainer {
  public:
    char pad[0x10];
    int a;
    int b;
    virtual int vfunc_0(void*);
};
} // namespace audio
extern "C" char __cdecl FUN_0025abd0(void*, int*);
int audio::SeqEventLogicRepeat::vfunc_0(void* p) {
    if ((char)SeqEvent::vfunc_0(p)) {
        if ((char)SeqEventContainer::vfunc_0(p)) {
            if (FUN_0025abd0(p, &a)) {
                if (FUN_0025abd0(p, &b)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
} // namespace fn_00254a80

namespace fn_f524576d {

// 0x00254ae0 audio::SeqEventLogicRepeat::vfunc_3 (6 B): matches/0x00254ae0.cpp
// sym: _FUN_00254ae0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00254ae0() {
    return &(*(int*)&DAT_004e73a8);
}

} // namespace fn_f524576d

// 0x00254b10 FUN_00254b10 (86 B): equivalent/0x00254b10.cpp [wrapped: conflict: audio::SeqEventLogicRepeatType]
// sym: ?FUN_00254b10@SeqEventLogicRepeatType@audio@fn_00254b10@@QAEPAU123@XZ
namespace fn_00254b10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254b10 @ 0x00254b10
struct Value { unsigned int lo, hi; };
extern "C" Value __cdecl FUN_002672f0(const char*, int, int);
struct Descriptor {
    char bytes[20];
    Descriptor* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventLogicRepeatType {
    void* vtable;
    void FUN_002605e0(Descriptor*, Value*, int, int);
    SeqEventLogicRepeatType* FUN_00254b10();
};
}
extern "C" char DAT_0042a3a0[];
audio::SeqEventLogicRepeatType* audio::SeqEventLogicRepeatType::FUN_00254b10() {
    HULK_SIZE32(AudioSeqEventLogicRepeat, 0x1c);
    Value value = FUN_002672f0("SeqEventLogicRepeat", 0, 0);
    Descriptor desc;
    FUN_002605e0(desc.FUN_0023fc40("||:", 0), &value, (int)sizeof(AudioSeqEventLogicRepeat), (int)__alignof(AudioSeqEventLogicRepeat));
    desc.FUN_00240060();
    vtable = DAT_0042a3a0;
    return this;
}
} // namespace fn_00254b10


// 0x00254b70 audio::SeqEventLogicRepeatType::vfunc_2 (30 B): matches/0x00254b70.cpp
// sym: ??_GSeqEventLogicRepeatType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventLogicRepeatType::~SeqEventLogicRepeatType() {}


// 0x00254b90 audio::SeqEventLogicRepeat::vfunc_1 (141 B): equivalent/0x00254b90.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventContainer; audio::SeqEventLogicRepeat]
// sym: ?vfunc_1@SeqEventLogicRepeat@audio@fn_00254b90@@UAEDPAUArchive_254b90@3@@Z
namespace fn_00254b90 {
// STATUS: equivalent (tools/equiv.py level 3: 1543 inputs, branch coverage 12/12)
// audio::SeqEventLogicRepeat::vfunc_1 @ 0x00254b90
// audio::SeqEventLogicRepeat::vfunc_1: write the event (base fields, then min/max repeat counts) to a text stream
struct Writer_254b90 {
    char pad00[0x24];
    int indent;
};

struct Archive_254b90 {
    Writer_254b90* writer;
};

char FUN_00246f50(Writer_254b90* writer, const char* fmt, ...);
extern "C" char FUN_0024eb60(Archive_254b90* ar, const char* name, unsigned int* value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    char pad04[4];
};

class SeqEventContainer : public SeqEvent {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    char pad08[12];
};

class SeqEventLogicRepeat : public SeqEventContainer {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    unsigned int minTimes;
    unsigned int maxTimes;
};

char SeqEventLogicRepeat::vfunc_1(Archive_254b90* ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!SeqEventContainer::vfunc_1(ar))
        return 0;
    if (!FUN_0024eb60(ar, "mMinTimes", &minTimes))
        return 0;
    if (!FUN_0024eb60(ar, "mMaxTimes", &maxTimes))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00254b90

namespace fn_f524576d {

// 0x00254c20 FUN_00254c20 (40 B): matches/0x00254c20.cpp
// sym: ??0SeqEventLogicRepeat@fn_f524576d@@QAE@XZ
SeqEventLogicRepeat::SeqEventLogicRepeat() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    a[4] = 1;
    *(void**)this = (void*)((hulk_intptr)DAT_0042a3e4);
}

} // namespace fn_f524576d

// 0x00254c50 audio::SeqEventLogicRepeat::vfunc_4 (35 B): matches/0x00254c50.cpp [wrapped: conflict: audio::SeqEventLogicRepeat]
// sym: ?vfunc_4@SeqEventLogicRepeat@audio@fn_00254c50@@UAEPAV123@H@Z
namespace fn_00254c50 {

namespace audio { class SeqEventLogicRepeat {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventLogicRepeat* vfunc_4(int);
    virtual void f5();
}; }
struct ThisCall_002607a0 {
    void FUN_002607a0();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqEventLogicRepeat* audio::SeqEventLogicRepeat::vfunc_4(int flag) {
    ((ThisCall_002607a0*)(this))->FUN_002607a0();
    if (flag & 1)
        FUN_00247550(((char*)&DAT_004e73a8), this);
    return this;
}
} // namespace fn_00254c50

namespace fn_f524576d {

// 0x00254c80 FUN_00254c80 (86 B): matches/0x00254c80.cpp
// sym: ??0SeqCommandLogicRepeat_254c80@fn_f524576d@@QAE@PAUSeq@1@@Z
SeqCommandLogicRepeat_254c80::SeqCommandLogicRepeat_254c80(Seq* s) {
    seq = s;
    zero = 0;
    int index = s->a;
    hulk_intptr result;
    if (index == -1)
        result = ((hulk_intptr)s | index);
    else
        result = FUN_000113e0(index, s->b);
    val = result;
    volatile int* p = &seq->count;
    int x = *p;
    count = x ? x - 4 : 0;
}

} // namespace fn_f524576d

// 0x00254ce0 audio::SeqCommandLogicRepeat::vfunc_1 (36 B): matches/0x00254ce0.cpp [wrapped: conflict: audio::SeqCommandLogicRepeat]
// sym: ?vfunc_1@SeqCommandLogicRepeat@audio@fn_00254ce0@@UAEPAV123@H@Z
namespace fn_00254ce0 {

class SeqCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
namespace audio { class SeqCommandLogicRepeat : public SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommandLogicRepeat* vfunc_1(int);
}; }
extern int hulk_at_00429ac8;
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqCommandLogicRepeat* audio::SeqCommandLogicRepeat::vfunc_1(int x) {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00429ac8;
    if (x & 1)
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e7360))), this);
    return this;
}
} // namespace fn_00254ce0


// 0x00254d10 audio::SeqCommandLogicRepeat::vfunc_0 (107 B): equivalent/0x00254d10.cpp [wrapped: conflict: audio::SeqCommandLogicRepeat]
// sym: ?vfunc_0@SeqCommandLogicRepeat@audio@fn_00254d10@@UAEXPAUContext@3@@Z
namespace fn_00254d10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// audio::SeqCommandLogicRepeat::vfunc_0 @ 0x00254d10
struct Link_254d10 {
    Link_254d10* next;
};

class Command_254d10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Update(void* context);
    Link_254d10 link;             // 0x04
};

struct CommandList_254d10 {
    char pad00[0xc];
    Link_254d10* first;           // 0x0c
};

namespace audio { class SeqCommandLogicRepeat; }

struct Context {
    void FUN_0025dbd0(audio::SeqCommandLogicRepeat* self);
};

namespace audio {

class SeqCommandLogicRepeat {
public:
    virtual void vfunc_0(Context* context);
    virtual void vfunc_1();
    char pad04[4];
    CommandList_254d10* list;     // 0x08
    unsigned int count;    // 0x0c
    unsigned int limit;    // 0x10
    Command_254d10* current;      // 0x14
};

}

void audio::SeqCommandLogicRepeat::vfunc_0(Context* context)
{
    if (current == 0) {
        context->FUN_0025dbd0(this);
        return;
    }
    current->Update(context);
    Link_254d10* next = current->link.next;
    current = next ? reinterpret_cast<Command_254d10*>(reinterpret_cast<char*>(next) - 4) : 0;
    if (current == 0) {
        unsigned int n = limit;
        if (n != 0xffffffff)
            count++;
        if (count < n) {
            Link_254d10* head = list->first;
            current = head ? reinterpret_cast<Command_254d10*>(reinterpret_cast<char*>(head) - 4) : 0;
        }
    }
}
} // namespace fn_00254d10


// 0x00254d80 audio::SeqEventLogicRepeatType::vfunc_3 (73 B): matches/0x00254d80.cpp
// sym: ?vfunc_3@SeqEventLogicRepeatType@audio@@UAEPAXXZ
// data: gPool_254d80 = DAT_004e73a8
void* audio::SeqEventLogicRepeatType::vfunc_3() {
    SeqEventLogicRepeat_254d80* r = (SeqEventLogicRepeat_254d80*)FUN_00247530(((char*)&DAT_004e73a8));
    if (r)
        return (void*)(new (r) SeqEventLogicRepeat_254d80);
    return (void*)(0);
}

namespace fn_f524576d {

// 0x00254dd0 audio::SeqEventLogicRepeat::vfunc_2 (58 B): equivalent/0x00254dd0.cpp
// sym: ?vfunc_2@SeqEventLogicRepeat_254dd0@fn_f524576d@@QAEXPAUReceiver@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// audio::SeqEventLogicRepeat::vfunc_2 @ 0x00254dd0
void SeqEventLogicRepeat_254dd0::vfunc_2(Receiver* receiver) {
    audio::SeqCommandLogicRepeat* helper = (audio::SeqCommandLogicRepeat*)FUN_00247530(((char*)((char*)&DAT_004e7360)));
    if (helper) ((owners::Queue_25dba0 *)receiver)->FUN_0025dba0((int *)(((SeqCommandLogicRepeat_nv_254dd0*)(((audio::SeqCommandLogicRepeat*)(helper))))->FUN_00254c80(this)));
    else ((owners::Queue_25dba0 *)receiver)->FUN_0025dba0((int *)0);
}

} // namespace fn_f524576d

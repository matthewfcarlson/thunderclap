// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// clang-flags: -fexceptions -fcxx-exceptions   (gx2, D22: kept until its --wine proof passes again; docs/native-build.md "gx2")
// object 0x0026de20..0x0026efc0 (kind game, layer engine, confidence high), dominant class core::DebugConsole
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f42a2f23 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f42a2f23 {} using namespace fn_f42a2f23;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f42a2f23 {
struct Event_26de40 {
 unsigned type, a;
 union { unsigned b; unsigned char keyFlags[4]; };
 unsigned c,d,kind;
 unsigned char flags[4];
};
struct ReceiverA {
 virtual void key(unsigned);
 virtual void keyState(unsigned,bool,bool,bool);
};
struct ReceiverB {
 virtual void action0(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action1(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action2(unsigned,unsigned,unsigned,unsigned,bool,bool,bool);
 virtual void action3(unsigned,unsigned,unsigned,unsigned,bool,bool,bool,bool);
};
struct Queue_26de40 {
 char pad[0x9c]; ReceiverB* receiverB; ReceiverA* receiverA; char pad2[8];
 Event_26de40 events[256]; unsigned writeIndex,readIndex;
 void FUN_0026de40();
};
extern int __cdecl FUN_0026eee0(unsigned long *);
extern int __cdecl FUN_0026eef0(unsigned long *);
extern int __cdecl FUN_0026ef00(unsigned long *, int *);
struct Obj_26e0e0 {
    char pad10[0x10];
    char field10[1];
    char pad68[0x68 - 0x11];
    char field68[1];
    char padC0[0xc0 - 0x69];
    int state;
};
void cleanup_0026eef0(void*);
typedef unsigned int uint_26e140;
} // namespace fn_f42a2f23
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, uint_26e140);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, uint_26e140);
#endif
namespace fn_f42a2f23 {
struct Entry_26e140 { char data[0x108]; uint_26e140 length; Entry_26e140* next; };
struct Allocator { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Entry_26e140* allocate(uint_26e140); };
int __cdecl FUN_0026ef40(void*, const void*, uint_26e140, int);
struct Handler_26e140 {
 char pad0[0x68]; char buffer[0x58]; int state; Allocator* allocator; Entry_26e140* head;
 void FUN_0026e0e0(); 
 void target(const void* source, uint_26e140 length);
};
struct Item_26e240 { unsigned int words[7]; };
struct Queue_26e240 {
    char pad[0xac];
    Item_26e240 items[256];
    unsigned int writeIndex;
    unsigned int readIndex;
    void FUN_0026e240(const Item_26e240 *item);
};
class IB_26e340 {
  public:
    void helper_0026d280();
};
class ConsoleClient_26e340 : public core::IRefCount, public IB_26e340 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26e360;
extern void __fastcall Init_0026e0e0(void*);
class ConsoleClient {
  public:
    hulk_uintptr a, b, c;
    void Run();
};
struct Node {
    char pad[16];
    Node* next;
};
class Thing {
  public:
    void helper_0026e140(void*, int);
    void FUN_0026e400(int);
};
class C_26e430 {
    char pad[0x68];

  public:
    void f(int);
    void next_0026e140(void*, int);
};
extern void __cdecl helper_0026ef40(void*, void*, int, int);
struct S_26e430 {
    int a, b;
};
typedef unsigned int U_26e470;
} // namespace fn_f42a2f23
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, U_26e470);
#endif
namespace fn_f42a2f23 {
struct Message {
    int kind;
    int first;
    int second;
};
struct Handler {
  public:
    void FUN_0026e140(Message* message, int size);
    void FUN_0026e4d0(int first, int second);
    void FUN_0026e140(void* data, int size);
    void FUN_0026e500(int value);
};
struct Packet {
    int kind;
    int first;
    int second;
    int third;
};
struct Sender {
    void FUN_0026e140(Packet*, int);
    void FUN_0026e530(int first, int second, int third);
};
} // namespace fn_f42a2f23
extern "C" char* _strncpy(char*, const char*, unsigned int);
namespace fn_f42a2f23 {
class Obj_26e5a0 {
  public:
    void Target(unsigned int a, char* src, unsigned int b, unsigned int d);
    void Send_0026e140(void* p, int n);
};
class Helper_26e750 {
  public:
    void run_0026e140(void*, unsigned int);
};
struct Target {
    void Fnf_0026e140(int*, int);
};
class Helper_26e7c0 {
  public:
    void run_0026e140(void*, int);
};
class Helper_26e800 {
  public:
    void call_0026e140(void*, unsigned int);
};
struct Args {
    int a;
    int b;
    char rest[20];
};
class Obj {
  public:
    char _m_pad_0[0xa0];
    int flag;
    char _m_pad_a4[0x130];
    Node* head;
    void Remove(Node* node);
    void Empty_0026e0e0();
    void Fn(int x);
    void Go_0026e240(Args*);
};
struct Event_26e920 {
    int kind;
    int value;
    unsigned char a, b, c;
    char unused[16];
};
struct Obj_26e920 {
    char pad[0xa0];
    int active;
    void FUN_0026e240(Event_26e920*);
    void FUN_0026e920(int value, unsigned char a, unsigned char b, unsigned char c);
};
struct Msg_26e970 {
    int type;
    int a;
    int b;
    int c;
    int d;
    int e;
    char f0, f1, f2, f3;
};
class C_26e970 {
  public:
    char pad[0x9c];
    void* h;
    void Send_0026e240(Msg_26e970* m);
    void Fn(int a, int b, int c, int d, char e, char f, char g, char h2, char i);
};
struct Obj_26e9e0 { virtual void FUN_0026e9e0_slot0(); };
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
struct ConsoleClient_nv_26e9e0 {
    void* FUN_0026e2a0(int, int);
};
struct C_26ed70 {
    void Fnf_0026eab0();
};
typedef unsigned char u8_26ee30;
extern void __cdecl release_00266f00(int, void*);
class DebugConsole_26ee30 {
  public:
    void cleanup_0026e650();
    virtual void f0();
    virtual void f1();
    virtual DebugConsole_26ee30* f2(u8_26ee30);
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

} // namespace fn_f42a2f23

// 0x0026de20 core::DebugConsole::vfunc_10 (13 B): matches/0x0026de20.cpp
// sym: ?vfunc_10@DebugConsole@core@@UAEXH@Z
void core::DebugConsole::vfunc_10(int value) {
    this->f_a0 = value;
}


// 0x0026de30 core::DebugConsole::vfunc_11 (13 B): matches/0x0026de30.cpp
// sym: ?vfunc_11@DebugConsole@core@@UAEXH@Z
void core::DebugConsole::vfunc_11(int value) {
    this->f_9c = value;
}

namespace fn_f42a2f23 {

// 0x0026de40 FUN_0026de40 (423 B): equivalent/0x0026de40.cpp
// sym: ?FUN_0026de40@Queue_26de40@fn_f42a2f23@@QAEXXZ @4688285f56c0 @wb208838e2380
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 54/54)
// FUN_0026de40 @ 0x0026de40
void Queue_26de40::FUN_0026de40() {
 while(writeIndex != readIndex) {
  Event_26de40& e=events[readIndex];
  readIndex=(readIndex+1)&255;
  switch(e.type) {
   case 0: if(receiverA) receiverA->key(e.a); break;
   case 1: if(receiverA) receiverA->keyState(e.a,e.keyFlags[0]!=0,e.keyFlags[1]!=0,e.keyFlags[2]!=0); break;
   case 2:
    if(receiverB) switch(e.kind) {
     case 0: receiverB->action3(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0,e.flags[3]!=0); break;
     case 1: receiverB->action1(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
     case 2: receiverB->action2(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
     case 3: receiverB->action0(e.a,e.b,e.c,e.d,e.flags[0]!=0,e.flags[1]!=0,e.flags[2]!=0); break;
    }
    break;
  }
 }
}

} // namespace fn_f42a2f23

// 0x0026e030 FUN_0026e030 (171 B): equivalent/0x0026e030.cpp
// sym: ?FUN_0026e030@Device_26e030@owners@@QAEXXZ @69f70f9586c4 @we6efff489215
// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 8/8; run with --inputs 12000)
// FUN_0026e030 @ 0x0026e030
void owners::Device_26e030::FUN_0026e030() {
    if (active) return;
    for (int i = 0; i < 22; ++i) second[i] = 0;
    for (int j = 0; j < 22; ++j) first[j] = 0;
    int mode = 0x100b;
    if (FUN_0026eee0(first) < 0) {
        active = 0;
        return;
    }
    if (FUN_0026eee0(second) < 0) {
        FUN_0026eef0(second);
        active = 0;
        return;
    }
    if (FUN_0026ef00(first, &mode) < 0) {
        FUN_0026eef0(first);
        FUN_0026eef0(second);
        active = 0;
        return;
    }
    active = 1;
}

namespace fn_f42a2f23 {

// 0x0026e0e0 FUN_0026e0e0 (81 B): matches/0x0026e0e0.cpp
// sym: ?target@fn_f42a2f23@@YIXPAUObj_26e0e0@1@@Z
void __fastcall target(Obj_26e0e0* self) {
    int x = self->state;
    if (x == 3) {
        cleanup_0026eef0(&self->field68);
        self->state = 0;
    } else if (x == 1 || x == 2) {
        cleanup_0026eef0(&self->field10);
        cleanup_0026eef0(&self->field68);
        self->state = 0;
    }
}


// 0x0026e140 FUN_0026e140 (184 B): equivalent/0x0026e140.cpp
// sym: ?target@Handler_26e140@fn_f42a2f23@@QAEXPBXI@Z @112f7d5874fa @wa6e28de50dee
// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 9/10, incomplete)
// FUN_0026e140 @ 0x0026e140
void Handler_26e140::target(const void* source, uint_26e140 length) {
 if (state == 3) {
  if (FUN_0026ef40(buffer, source, length, 0) < 0) { FUN_0026e0e0(); ((owners::Device_26e030 *)this)->FUN_0026e030(); }
  return;
 }
 Entry_26e140* item = allocator->allocate(length);
 memset(item, 0, 0x110);
 memcpy(item, source, length);
 item->length = length;
 if (!head) { head = item; return; }
 Entry_26e140* tail = head;
 while (tail->next) tail = tail->next;
 tail->next = item;
}

} // namespace fn_f42a2f23

// 0x0026e200 FUN_0026e200 (37 B): matches/0x0026e200.cpp
// sym: ?FUN_0026e200@X_26e200@owners@@QAE_NPAX@Z
bool owners::X_26e200::FUN_0026e200(void* p) {
    hulk_intptr i = mHead;
    while (i != 0) {
        if (i == (hulk_intptr)p)
            return true;
        i = *(int*)(i + 0x10);
    }
    return false;
}

namespace fn_f42a2f23 {

// 0x0026e240 FUN_0026e240 (86 B): equivalent/0x0026e240.cpp
// sym: ?FUN_0026e240@Queue_26e240@fn_f42a2f23@@QAEXPBUItem_26e240@2@@Z @656fd239fc06 @w24dda51a830d
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_0026e240 @ 0x0026e240
void Queue_26e240::FUN_0026e240(const Item_26e240 *item) {
    unsigned int index = writeIndex;
    if (index == 255 ? readIndex == 0 : readIndex - index == 1)
        return;
    items[index] = *item;
    writeIndex = (writeIndex + 1) & 255;
}

} // namespace fn_f42a2f23

// 0x0026e2a0 FUN_0026e2a0 (133 B): matches/0x0026e2a0.cpp [wrapped: helper definitions (8 out-of-line function bodies)]
// sym: ??0ConsoleClient@fn_0026e2a0@@QAE@HH@Z
namespace fn_0026e2a0 {

void Hook_002705f0();
void PoolInit_002702a0(void* pool, int a, int b, int c, int d, const char* name, int e);

class ConsoleClient_26e2a0 {
  public:
    ConsoleClient_26e2a0();
    virtual void f0();
};

class Obj_26e2a0 {
  public:
    Obj_26e2a0();
    virtual void g0();
    int mId;
};

class RefC : public Obj_26e2a0 {
  public:
    RefC();
    virtual void g1();
    int mRef;
};

class ConsoleClient : public ConsoleClient_26e2a0, public RefC {
  public:
    ConsoleClient(int a, int b);
    virtual void f1();
    char pad[0xb0];
    int m0;
    int mPool;
    int m1;
    char pad2[0x108];
    int m2;
};

ConsoleClient_26e2a0::ConsoleClient_26e2a0() {}
void ConsoleClient_26e2a0::f0() {}
Obj_26e2a0::Obj_26e2a0() {
    mId = DAT_004cdbb0;
    Hook_002705f0();
}
void Obj_26e2a0::g0() {}
RefC::RefC() {
    mRef = 1;
    Hook_002705f0();
}
void RefC::g1() {}
void ConsoleClient::f1() {}

ConsoleClient::ConsoleClient(int a, int b) {
    m0 = 0;
    mPool = 0;
    m1 = 0;
    m2 = 0;
    PoolInit_002702a0(&mPool, 0x110, 0x80, 1, a, "ConsoleClient::mInitContentTxBufferPool", 4);
    Hook_002705f0();
}
} // namespace fn_0026e2a0


// 0x0026e330 core::ConsoleClient::vfunc_0 (4 B): matches/0x0026e330.cpp
// sym: ?vfunc_0@ConsoleClient@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::ConsoleClient::vfunc_0() {
    ++this->f_0c;
}

namespace fn_f42a2f23 {

// 0x0026e340 core::ConsoleClient::vfunc_1 (8 B): matches/0x0026e340.cpp
// sym: ?vfunc_1@ConsoleClient_26e340@fn_f42a2f23@@UAEXXZ
// Same code shape as 0x0026d270 (propagated; names are from that function)
void ConsoleClient_26e340::vfunc_1() {
    IB_26e340::helper_0026d280();
}

} // namespace fn_f42a2f23

// 0x0026e350 core::ConsoleClient::vfunc_0_adj4 (8 B): matches/0x0026e350.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_2@ConsoleClient@fn_0026e350@@W3AEXXZ
namespace fn_0026e350 {
class Primary_26e350 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

class Secondary {
  public:
    virtual void vfunc_2() = 0;
};

class ConsoleClient : public Primary_26e350, public Secondary {
  public:
    ConsoleClient();
    void vfunc_2();
};

ConsoleClient::ConsoleClient() {}
void ConsoleClient::vfunc_2() {
    int x = 0;
}
} // namespace fn_0026e350

namespace fn_f42a2f23 {

// 0x0026e360 FUN_0026e360 (54 B): matches/0x0026e360.cpp
// sym: ?Run@ConsoleClient@fn_f42a2f23@@QAEXXZ
// data: gSaved = DAT_004cdbb0, gState_26e360 = DAT_005283b0
void ConsoleClient::Run() {
    a = ((hulk_intptr)DAT_0042b47c);
    b = ((hulk_intptr)DAT_0042b474);
    Init_0026e0e0((void*)(this));
    (*(u32_26e360*)&DAT_004cdbb0) = c;
    b = ((hulk_intptr)DAT_0042af64);
    a = ((hulk_intptr)DAT_003f6098);
    (*(u32_26e360*)&DAT_005283b0) = 0;
}


// 0x0026e3c0 FUN_0026e3c0 (57 B): matches/0x0026e3c0.cpp
// sym: ?Remove@Obj@fn_f42a2f23@@QAEXPAUNode@2@@Z
void Obj::Remove(Node* node) {
    Node** p = &head;
    if (*p) {
        do {
            if (*p == node) {
                *p = (*p)->next;
                break;
            }
            p = &(*p)->next;
        } while (*p);
    }
    if (!head)
        Empty_0026e0e0();
}


// 0x0026e400 FUN_0026e400 (37 B): matches/0x0026e400.cpp
// sym: ?FUN_0026e400@Thing@fn_f42a2f23@@QAEXH@Z
void Thing::FUN_0026e400(int x) {
    int a[2];
    a[0] = 0;
    a[1] = x;
    helper_0026e140(a, 8);
}


// 0x0026e430 FUN_0026e430 (64 B): matches/0x0026e430.cpp
// sym: ?f@C_26e430@fn_f42a2f23@@QAEXH@Z
void C_26e430::f(int p) {
    S_26e430 s;
    s.a = 8;
    s.b = p;
    helper_0026ef40(pad + 0x68, &s, 8, 0);
    next_0026e140(&s, 8);
}

} // namespace fn_f42a2f23

// 0x0026e470 FUN_0026e470 (89 B): matches/0x0026e470.cpp
// sym: ?FUN_0026e470@C_26e470@owners@@QAEXIPAD@Z
void owners::C_26e470::FUN_0026e470(hulk_uintptr a, char* s) {
    char b[0x108];
    *(U_26e470*)b = 1;
    *(U_26e470*)(b + 4) = ((U_26e470)a);
    strncpy(b + 8, s, 0x100);
    b[0x107] = 0;
    helper(b, 0x108);
}

namespace fn_f42a2f23 {

// 0x0026e4d0 FUN_0026e4d0 (45 B): matches/0x0026e4d0.cpp
// sym: ?FUN_0026e4d0@Handler@fn_f42a2f23@@QAEXHH@Z
void Handler::FUN_0026e4d0(int first, int second) {
    Message message;
    message.kind = 2;
    message.first = first;
    message.second = second;
    FUN_0026e140(&message, 12);
}


// 0x0026e500 FUN_0026e500 (37 B): matches/0x0026e500.cpp
// sym: ?FUN_0026e500@Handler@fn_f42a2f23@@QAEXH@Z
void Handler::FUN_0026e500(int value) {
    int args[2];
    args[0] = 3;
    args[1] = value;
    FUN_0026e140(args, 8);
}


// 0x0026e530 FUN_0026e530 (53 B): matches/0x0026e530.cpp
// sym: ?FUN_0026e530@Sender@fn_f42a2f23@@QAEXHHH@Z
void Sender::FUN_0026e530(int first, int second, int third) {
    Packet packet;
    packet.kind = 4;
    packet.first = first;
    packet.second = second;
    packet.third = third;
    FUN_0026e140(&packet, 16);
}

} // namespace fn_f42a2f23

// 0x0026e570 FUN_0026e570 (45 B): matches/0x0026e570.cpp [wrapped: merged class would differ: Packet: size 16 vs 12]
// sym: ?FUN_0026e570@Handler@fn_0026e570@@QAEXHH@Z
namespace fn_0026e570 {
struct Packet {
    int type;
    int first;
    int second;
};
struct Handler {
    void FUN_0026e140(Packet*, int);
    void FUN_0026e570(int first, int second);
};
void Handler::FUN_0026e570(int first, int second) {
    Packet packet;
    packet.type = 5;
    packet.first = first;
    packet.second = second;
    FUN_0026e140(&packet, 12);
}
} // namespace fn_0026e570

namespace fn_f42a2f23 {

// 0x0026e5a0 FUN_0026e5a0 (84 B): matches/0x0026e5a0.cpp
// sym: ?Target@Obj_26e5a0@fn_f42a2f23@@QAEXIPADII@Z
void Obj_26e5a0::Target(unsigned int a, char* src, unsigned int b, unsigned int d) {
    struct Buf {
        unsigned int h;
        unsigned int a;
        unsigned int b;
        unsigned int d;
        char s[83];
        char z;
    } buf;
    buf.a = a;
    buf.b = b;
    buf.h = 6;
    buf.d = d;
    _strncpy(buf.s, src, 0x54);
    buf.z = 0;
    Send_0026e140(&buf, 100);
}

} // namespace fn_f42a2f23

// 0x0026e600 FUN_0026e600 (68 B): matches/0x0026e600.cpp [wrapped: conflict: strncpy]
// sym: ?Target@Obj_26e600@fn_0026e600@@QAEXIPAD@Z
namespace fn_0026e600 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif

class Obj_26e600 {
  public:
    void Helper_0026e140(void*, unsigned int);
    void Target(unsigned int, char*);
};
void Obj_26e600::Target(unsigned int id, char* message) {
    struct Local {
        unsigned int a;
        unsigned int b;
        char text[83];
        char end;
    } local;
    local.a = 7;
    local.b = id;
    strncpy(local.text, message, 0x54);
    local.end = 0;
    Helper_0026e140(&local, 0x5c);
}
} // namespace fn_0026e600


// 0x0026e650 FUN_0026e650 (124 B): equivalent/0x0026e650.cpp [wrapped: conflict: core::BaseObject; core::DebugConsole; core::IRefCount]
// sym: ??1DebugConsole@core@fn_0026e650@@QAE@XZ @72e65e0a3b95 @wc5857990b35a
namespace fn_0026e650 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026e650 @ 0x0026e650

namespace core {
struct IRefCount { virtual void dummy_0026e6d0(); ~IRefCount() throw() {} };
struct BaseObject { virtual void dummy(); ~BaseObject() throw() {} };
struct Handler_26e650 { virtual void slot0(); virtual void slot1(); char pad[0x60]; char data[8]; void FUN_0026e140(void *, int); void FUN_0026e3c0(void *); };
struct DebugConsole : IRefCount, BaseObject { int value; char pad[0x98]; Handler_26e650 *handler; ~DebugConsole() throw(); };
}
struct Registration_26e650 { int size; core::DebugConsole *object; };
void __cdecl FUN_0026ef40(void *, Registration_26e650 *, int, int);
core::DebugConsole::~DebugConsole() throw() {
    core::Handler_26e650 *h = handler;
    Registration_26e650 reg = { 8, this };
    FUN_0026ef40(h->data, &reg, 8, 0);
    h->FUN_0026e140(&reg, 8);
    handler->FUN_0026e3c0(this);
    handler->slot1();
    DAT_004cdbb0 = value;
}
} // namespace fn_0026e650


// 0x0026e6d0 core::DebugConsole::vfunc_0 (4 B): matches/0x0026e6d0.cpp
// sym: ?vfunc_0@DebugConsole@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::DebugConsole::vfunc_0() {
    ++this->f_0c;
}


// 0x0026e6e0 core::DebugConsole::vfunc_1 (26 B): matches/0x0026e6e0.cpp [wrapped: conflict: core::DebugConsole; core::IRefCount]
// sym: ?vfunc_1@DebugConsole@core@fn_0026e6e0@@UAEXXZ
namespace fn_0026e6e0 {
extern "C" void _ReadWriteBarrier();
namespace core {
class IRefCount {
  public:
    virtual void tick(int);
    int filler;
    int count;
    inline void step() {
        if (--count == 0) {
            count = 1500;
            _ReadWriteBarrier();
            tick(1);
        }
    }
};
class DebugConsole {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    IRefCount ref;
};
void DebugConsole::vfunc_1() {
    ref.step();
}
} // namespace core
} // namespace fn_0026e6e0


// 0x0026e700 core::DebugConsole::vfunc_0_adj4 (8 B): matches/0x0026e700.cpp [wrapped: conflict: core::DebugConsole; core::IDebugConsole; core::IRefCount]
// sym: ?vfunc_2@DebugConsole@core@fn_0026e700@@W3AEXI@Z
namespace fn_0026e700 {
namespace core {
struct IDebugConsole {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned);
};
struct IRefCount {
    virtual void vfunc_2(unsigned);
};
struct DebugConsole : IDebugConsole, IRefCount {
    virtual void vfunc_2(unsigned);
};
extern void work(unsigned);
void DebugConsole::vfunc_2(unsigned flags) {
    work(flags);
}
DebugConsole instance;
} // namespace core
} // namespace fn_0026e700


// 0x0026e750 core::DebugConsole::vfunc_4 (59 B): matches/0x0026e750.cpp
// sym: ?vfunc_4@DebugConsole@core@@UAEXI@Z
void core::DebugConsole::vfunc_4(unsigned int p) {
    struct Data {
        unsigned int a, b, c;
    } d;
    d.a = 2;
    d.b = (hulk_uintptr)this;
    d.c = p;
    (*(Helper_26e750 * *)&this->f_a4)->run_0026e140(&d, 12);
    this->f_94 = p;
}


// 0x0026e790 core::DebugConsole::vfunc_5 (37 B): matches/0x0026e790.cpp
// sym: ?vfunc_5@DebugConsole@core@@UAEXXZ
 // namespace core
void core::DebugConsole::vfunc_5() {
    int a[2];
    a[1] = (hulk_intptr)this;
    a[0] = 3;
    (*(Target * *)&this->f_a4)->Fnf_0026e140(a, 8);
}


// 0x0026e7c0 core::DebugConsole::vfunc_6 (55 B): matches/0x0026e7c0.cpp
// sym: ?vfunc_6@DebugConsole@core@@UAEXHH@Z
void core::DebugConsole::vfunc_6(int a, int b) {
    int local[4];
    local[0] = 4;
    local[1] = (hulk_intptr)this;
    local[2] = a;
    local[3] = b;
    (*(Helper_26e7c0 * *)&this->f_a4)->run_0026e140(local, 16);
}


// 0x0026e800 core::DebugConsole::vfunc_7 (59 B): matches/0x0026e800.cpp
// sym: ?vfunc_7@DebugConsole@core@@UAEXH@Z
void core::DebugConsole::vfunc_7(int param) {
    int local[3];
    local[0] = 5;
    local[1] = (hulk_intptr)this;
    local[2] = param;
    (*(Helper_26e800 * *)&this->f_a4)->call_0026e140(local, 12);
    this->f_98 = param;
}


// 0x0026e8a0 core::DebugConsole::vfunc_9 (68 B): matches/0x0026e8a0.cpp [wrapped: conflict: core::DebugConsole]
// sym: ?vfunc_9@DebugConsole@core@fn_0026e8a0@@UAEXPBD@Z
namespace fn_0026e8a0 {
extern "C" char* __cdecl _strncpy(char*, const char*, unsigned int);
struct ConsoleImpl {
    void FUN_0026e140(void*, int);
};
namespace core {
struct DebugConsole {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(const char*);
    virtual void vfunc_10();
    virtual void vfunc_11();
    char pad[0xa0];
    ConsoleImpl* impl;
};
} // namespace core
void core::DebugConsole::vfunc_9(const char* text) {
    ConsoleImpl* destination = impl;
    struct Message {
        int type;
        core::DebugConsole* owner;
        char text[84];
    } message;
    message.type = 7;
    message.owner = this;
    _strncpy(message.text, text, 84);
    message.text[83] = 0;
    destination->FUN_0026e140(&message, 92);
}
} // namespace fn_0026e8a0

namespace fn_f42a2f23 {

// 0x0026e8f0 FUN_0026e8f0 (44 B): matches/0x0026e8f0.cpp
// sym: ?Fn@Obj@fn_f42a2f23@@QAEXH@Z
void Obj::Fn(int x) {
    Args a;
    if (flag) {
        a.a = 0;
        a.b = x;
        Go_0026e240(&a);
    }
}


// 0x0026e920 FUN_0026e920 (68 B): matches/0x0026e920.cpp
// sym: ?FUN_0026e920@Obj_26e920@fn_f42a2f23@@QAEXHEEE@Z
void Obj_26e920::FUN_0026e920(int value, unsigned char a, unsigned char b, unsigned char c) {
    if (active) {
        Event_26e920 event;
        event.kind = 1;
        event.value = value;
        event.a = a;
        event.b = b;
        event.c = c;
        FUN_0026e240(&event);
    }
}


// 0x0026e970 FUN_0026e970 (109 B): matches/0x0026e970.cpp
// sym: ?Fn@C_26e970@fn_f42a2f23@@QAEXHHHHDDDDD@Z
void C_26e970::Fn(int a, int b, int c, int d, char e, char f, char g, char h2, char i) {
    if (h) {
        Msg_26e970 m;
        m.a = a;
        m.b = b;
        m.c = c;
        m.d = d;
        m.e = (int)e;
        m.f0 = f;
        m.f1 = g;
        m.f2 = h2;
        m.type = 2;
        m.f3 = i;
        Send_0026e240(&m);
    }
}


// 0x0026e9e0 FUN_0026e9e0 (97 B): equivalent/0x0026e9e0.cpp
// sym: ?target@fn_f42a2f23@@YAXPAPAUObj_26e9e0@1@HH@Z @1b55fcac8f14 @w6a92ac48092a
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 4/4)
// FUN_0026e9e0 @ 0x0026e9e0
void __cdecl target(Obj_26e9e0** result, hulk_intptr value, int other) {
    if ((*(Obj_26e9e0**)&DAT_005283b0)) {
        (*(Obj_26e9e0**)&DAT_005283b0)->FUN_0026e9e0_slot0();
        *result = (*(Obj_26e9e0**)&DAT_005283b0);
        return;
    }
    HULK_SIZE32(CoreConsoleClient, 0x1d8);
    DAT_004cdbb0 = value;
    core::ConsoleClient* created = (core::ConsoleClient*)FUN_00266e00(value, (hulk_intptr)sizeof(CoreConsoleClient));
    if (created) (*(Obj_26e9e0**)&DAT_005283b0) = (Obj_26e9e0*)((ConsoleClient_nv_26e9e0*)(((core::ConsoleClient*)(created))))->FUN_0026e2a0(value, other);
    else (*(Obj_26e9e0**)&DAT_005283b0) = 0;
    *result = (*(Obj_26e9e0**)&DAT_005283b0);
}

} // namespace fn_f42a2f23

// 0x0026ea50 core::ConsoleClient::vfunc_2 (81 B): matches/0x0026ea50.cpp [wrapped: conflict: ConsoleClient]
// sym: ?vfunc_2@ConsoleClient@fn_0026ea50@@QAEPAV12@E@Z
namespace fn_0026ea50 {

extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_0042b474[];
extern "C" char DAT_0042b47c[];
typedef unsigned int u32_26ea50;
extern "C++" __declspec(nothrow) void __fastcall init_console_0026e0e0(void*);
extern "C++" __declspec(nothrow) void cleanup_console_00266f00(u32_26ea50, void*);
class ConsoleClient {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    const void* vftableObject;              // records.h CoreConsoleClient +0x04
    u32_26ea50 field8;
    ConsoleClient* vfunc_2(unsigned char);
};
ConsoleClient* ConsoleClient::vfunc_2(unsigned char flag) {
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042b47c);
    *(hulk_uintptr*)&this->vftableObject = ((hulk_intptr)DAT_0042b474);
    init_console_0026e0e0((void*)(this));
    *(u32_26ea50*)((hulk_intptr)((char*)&DAT_004cdbb0)) = field8;
    *(hulk_uintptr*)&this->vftableObject = ((hulk_intptr)DAT_0042af64);
    *(u32_26ea50*)((hulk_intptr)DAT_005283b0) = 0;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        cleanup_console_00266f00(*(u32_26ea50*)((hulk_intptr)((char*)&DAT_004cdbb0)), this);
    return this;
}
} // namespace fn_0026ea50

namespace fn_f42a2f23 {

// 0x0026ed70 FUN_0026ed70 (16 B): matches/0x0026ed70.cpp
// sym: ?FUN_0026ed70@fn_f42a2f23@@YAXXZ
void FUN_0026ed70() {
    if ((*(C_26ed70**)&DAT_005283b0))
        (*(C_26ed70**)&DAT_005283b0)->Fnf_0026eab0();
}

} // namespace fn_f42a2f23

// 0x0026ed80 FUN_0026ed80 (164 B): equivalent/0x0026ed80.cpp [wrapped: conflict: core::DebugConsole; core::IDebugConsole; core::Object; core::RefCount]
// sym: ?FUN_0026ed80@DebugConsole@core@fn_0026ed80@@QAEPAU123@PAXE@Z @6b6550590e62 @w91eb9048e71a
namespace fn_0026ed80 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026ed80 @ 0x0026ed80

void FUN_002705f0();
void FUN_0026e9e0(void *, void *, unsigned int);
namespace core {
struct Object { virtual void obj(); int initialValue; };
struct RefCount : Object { virtual void obj(); int enabled; };
struct IDebugConsole { virtual void debug() HULK_PURE64; };
struct ConsoleOwner { char pad[0x1d4]; void *console; void FUN_0026e030(); };
struct DebugConsole : IDebugConsole, RefCount {
void debug(); void obj();
void *previous;
unsigned char state; char pad15[0x87];
int value9c; int valuea0; ConsoleOwner *owner;
unsigned char mode; char padA9[0x1c03];
int value1cac; int value1cb0;
DebugConsole *FUN_0026ed80(void *, unsigned char);
};
}
core::DebugConsole *core::DebugConsole::FUN_0026ed80(void *arg, unsigned char flag) {
this->IDebugConsole::IDebugConsole();
this->Object::Object();
initialValue = DAT_004cdbb0;
FUN_002705f0();
this->RefCount::RefCount();
enabled = 1;
FUN_002705f0();
this->DebugConsole::DebugConsole();
value9c = 0; valuea0 = 0; mode = flag;
value1cac = 0; value1cb0 = 0; state = 0;
FUN_002705f0();
FUN_0026e9e0(&owner, arg, mode);
previous = owner->console;
owner->console = this;
owner->FUN_0026e030();
return this;
}
} // namespace fn_0026ed80

namespace fn_f42a2f23 {

// 0x0026ee30 core::DebugConsole::vfunc_2 (36 B): matches/0x0026ee30.cpp
// sym: ?f2@DebugConsole_26ee30@fn_f42a2f23@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
DebugConsole_26ee30* DebugConsole_26ee30::f2(u8_26ee30 flag) {
    cleanup_0026e650();
    if (flag & 1)
        release_00266f00(DAT_004cdbb0, this);
    return this;
}


// 0x0026eea0 FUN_0026eea0 (1 B): matches/0x0026eea0.cpp
// sym: _FUN_0026eea0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0026eea0() {}


// 0x0026eeb0 FUN_0026eeb0 (1 B): matches/0x0026eeb0.cpp
// sym: _FUN_0026eeb0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0026eeb0() {}


// 0x0026eed0 FUN_0026eed0 (3 B): matches/0x0026eed0.cpp
// sym: ?vfunc_2@ParamValue@fn_f42a2f23@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char ParamValue::vfunc_2() {
    return 0;
}


// 0x0026eee0 FUN_0026eee0 (3 B): matches/0x0026eee0.cpp
// sym: ?GetZero@fn_f42a2f23@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f42a2f23

// 0x0026eef0 FUN_0026eef0 (3 B): matches/0x0026eef0.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026eef0@@YAIXZ
namespace fn_0026eef0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026eef0


// 0x0026ef00 FUN_0026ef00 (3 B): matches/0x0026ef00.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef00@@YAIXZ
namespace fn_0026ef00 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef00


// 0x0026ef10 FUN_0026ef10 (3 B): matches/0x0026ef10.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef10@@YAIXZ
namespace fn_0026ef10 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef10


// 0x0026ef20 FUN_0026ef20 (3 B): matches/0x0026ef20.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef20@@YAIXZ
namespace fn_0026ef20 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef20


// 0x0026ef30 FUN_0026ef30 (3 B): matches/0x0026ef30.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef30@@YAIXZ
namespace fn_0026ef30 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef30


// 0x0026ef40 FUN_0026ef40 (3 B): matches/0x0026ef40.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef40@@YAIXZ
namespace fn_0026ef40 {
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef40


// 0x0026ef50 FUN_0026ef50 (3 B): matches/0x0026ef50.cpp [wrapped: same definition as 0x0026eee0 in this TU]
// sym: ?GetZero@fn_0026ef50@@YAIXZ
namespace fn_0026ef50 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_0026ef50


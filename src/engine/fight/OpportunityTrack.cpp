// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00236e00..0x00237b70 (kind game, layer engine, confidence high), dominant class fight::OpportunityTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c81acf {
#define TREE_TU_END }
namespace fn_f6c81acf {} using namespace fn_f6c81acf;
namespace fn_f6c81acf { extern "C" char DAT_00427ff0[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f6c81acf {
class Obj_236e00 {
  public:
    int value;
    Obj_236e00();
};
class Ref_236ec0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder_236ec0 {
  public:
    Ref_236ec0* p;
    void Clear();
};
class OpportunityAction_236ee0 {
  public:
    virtual void f0();
    virtual void f1(void*);
    OpportunityAction_236ee0* next;
};
class Owner_236ee0 {
  public:
    OpportunityAction_236ee0* head;
    void run(void*);
};
class Item_236f40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual char Match(int, int, int);
    Item_236f40* next;
    int type;
};
class Owner_236f40 {
  public:
    Item_236f40* head;
    char Run(int, int, int);
};
class Ref_236fd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void Release(int);
};
class Holder_236fd0 {
  public:
    Ref_236fd0* p;
    void Clear();
};
struct OpportunityAction_nv_236ff0 {
    void Link_002344a0(fight::OpportunityAction*);
};
class List {
  public:
    fight::OpportunityAction* head;
    int Add(fight::OpportunityAction* n);
};
typedef unsigned __int64 Token_237050;
struct Stream { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual bool ready(); virtual Token_237050 token(); void FUN_00232c90(); };
struct Registry_237050;
struct OpportunityAction_237050 { OpportunityAction_237050* next; virtual void v0(); virtual void v1(); virtual void v2(); virtual bool parse(Token_237050, Registry_237050*, Stream*); void FUN_002344a0(OpportunityAction_237050*); };
struct Factory_237050 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual OpportunityAction_237050* create(); };
struct Registry_237050 { Factory_237050* FUN_00236790(Token_237050); };
void __cdecl FUN_00232cc0(Stream*, const char*, ...);
int __cdecl FUN_00238190(int);
extern "C" int __cdecl FUN_00266da0(int);
struct List_237050 { OpportunityAction_237050* head; bool FUN_00237050(Registry_237050*, Stream*, int); };
class Obj_237160 {
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
    virtual bool Check();
    virtual long long Pair();
    virtual void v15();
    virtual void Act(int, int);
    virtual void Done();
};
class Owner_237160 {
  public:
    bool Target(int a, int b, int c, Obj_237160* obj);
    void Work_00237050(int, Obj_237160*, int);
};
class B_237260 {
  public:
    int x;
};
class A_237260 {
  public:
    char pad[0x18];
    B_237260 val;
    B_237260* GetPtr();
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5bf4;
class CCondition_2372b0 {
  public:
    virtual int vfunc_0(int);
};
extern float hulk_at_003f3388;
struct SubA_237330 {
    void* v;
    void Fin_00236fd0() throw();
};
struct SubB_237330 {
    void* v;
    void Fin_00234150() throw();
};
class Track_237330 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class OpportunityTrack_237330 : public Track_237330 {
  public:
    char pad[0x18 - 4];
    SubB_237330 b;
    char pad2[0x28 - 0x1c];
    SubA_237330 a;
    ~OpportunityTrack_237330() throw();
};
extern int hulk_at_004e5c00;
extern void(__cdecl* hulk_at_004e5bfc)(int, int, int, int*, int*);
struct Receiver_2373e0 {
    void run_00231ad0(int, int, int);
};
extern void* g_vftable_00427ff0[];
struct T1 {
    void Fini_00236fd0();
};
struct T2 {
    void Fini_00234150();
};
class Track_237430 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class OpportunityTrack_237430 : public Track_237430 {
  public:
    char pad4[0x14];
    T2 a18;
    char pad19[0x28 - 0x19];
    T1 a28;
    OpportunityTrack_237430* vfunc_5(unsigned char flags);
};
class RefObj_237470 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_237470 {
  public:
    Action_237470();
    virtual void f0();
    char pad[0x18];
};
class OpportunityAction : public Action_237470 {
  public:
    OpportunityAction(RefObj_237470* a, int b, int c, int d, RefObj_237470* e, int f, int g, int h, RefObj_237470* i);
    virtual void f0();
    RefObj_237470* m1c;
    int m20;
    int m24;
    int m28;
    RefObj_237470* m2c;
    int m30;
    int m34;
    int m38;
    RefObj_237470* m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
};
class Ref_237530 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_237530 {
    void* vf;
    void Dtor_002326a0() throw();
};
struct OpportunityAction_237530 : Action_237530 {
    char pad[0x18];
    Ref_237530* p1c;
    void* p20;
    char pad2[8];
    Ref_237530* p2c;
    char pad3[0xc];
    Ref_237530* p3c;
    char pad4[0xc];
    Ref_237530* p4c;
    void Dtor2() throw();
};
class CStageCondition_2376f0;
class ParamValue_2376f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_2376f0 : public ParamValue_2376f0 {
  public:
    int pad;
};
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class CStageCondition_237770;
class ParamValue_237770 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_237770 : public ParamValue_237770 {
  public:
    int pad;
};
extern int hulk_at_0049850c;
void* __cdecl FUN_0008d690(unsigned size);
struct Sub_2379e0 { int w[3]; };
class Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void Call(void*);
    Node* next;
    void* FUN_00237470(void* a1, void* self, float a, float b, int f18, int f24, Sub_2379e0* sub, void* a2, void* a3);
};
class Owner_236f10 {
  public:
    Node* head;
    void Walk(void*);
};
class OpportunityTrack {
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
    virtual void* vfunc_10(void* a1, void* a2, void* a3);
    char pad[8];
    float start;
    float end;
    float peak;
    int f18;
    char pad2[8];
    int f24;
    Sub_2379e0 sub;
};
class TrackFactoryCasterTemplate_237ab0 {
  public:
    virtual bool Cast_002377c0(void*);
};
class Target {
  public:
    void Method_002367c0(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_237ab0*);
} // namespace fn_f6c81acf
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f6c81acf {
class TrackFactoryTemplate_237ae0 {
  public:
    TrackFactoryTemplate_237ae0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" void FUN_00237870();
typedef unsigned int u32_237b20;
struct Grapple_237b20 {
    hulk_uintptr ctor_002372c0();
};
extern void* __cdecl Alloc_0008d690(hulk_uintptr);
extern int hulk_at_004280c8;


// 0x00236e00 FUN_00236e00 (9 B): matches/0x00236e00.cpp
// sym: ??0Obj_236e00@fn_f6c81acf@@QAE@XZ
Obj_236e00::Obj_236e00() {
    value = 0;
}


// 0x00236ec0 FUN_00236ec0 (24 B): matches/0x00236ec0.cpp
// sym: ?Clear@Holder_236ec0@fn_f6c81acf@@QAEXXZ
void Holder_236ec0::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}


// 0x00236ee0 FUN_00236ee0 (36 B): matches/0x00236ee0.cpp
// sym: ?run@Owner_236ee0@fn_f6c81acf@@QAEXPAX@Z
void Owner_236ee0::run(void* arg) {
    for (OpportunityAction_236ee0* p = head; p != 0; p = p->next)
        p->f1(arg);
}


// 0x00236f10 FUN_00236f10 (36 B): matches/0x00236f10.cpp
// sym: ?Walk@Owner_236f10@fn_f6c81acf@@QAEXPAX@Z
void Owner_236f10::Walk(void* arg) {
    for (Node* p = head; p; p = p->next)
        p->Call(arg);
}


// 0x00236f40 FUN_00236f40 (118 B): matches/0x00236f40.cpp
// sym: ?Run@Owner_236f40@fn_f6c81acf@@QAEDHHH@Z
char Owner_236f40::Run(int a, int b, int c) {
    Item_236f40* n = head;
    bool active = true;
    bool invert = false;
    char result = 1;
    if (n) {
        do {
            int t = n->type;
            switch (t) {
            case 0:
                if (!result) {
                    if (active)
                        return 0;
                } else if (!active)
                    return 1;
                result = n->Match(a, b, c);
                if (invert)
                    result = (result == 0);
                active = true;
                invert = false;
                break;
            case 1:
                active = false;
                break;
            case 2:
                invert = !invert;
                break;
            }
            n = n->next;
        } while (n);
    }
    return result;
}


// 0x00236fd0 FUN_00236fd0 (24 B): matches/0x00236fd0.cpp
// sym: ?Clear@Holder_236fd0@fn_f6c81acf@@QAEXXZ
// Same code shape as 0x00236ec0 (propagated; names are from that function)
void Holder_236fd0::Clear() {
    if (p)
        p->Release(1);
    p = 0;
}


// 0x00236ff0 FUN_00236ff0 (84 B): matches/0x00236ff0.cpp
// sym: ?Add@List@fn_f6c81acf@@QAEHPAVOpportunityAction@fight@@@Z
int List::Add(fight::OpportunityAction* n) {
    if (!n)
        return -1;
    fight::OpportunityAction* last = 0;
    fight::OpportunityAction* p = head;
    int count = 0;
    while (p) {
        last = p;
        p = (*(fight::OpportunityAction * *)&p->f_04);
        ++count;
    }
    ((OpportunityAction_nv_236ff0*)(n))->Link_002344a0(p);
    if (last)
        ((OpportunityAction_nv_236ff0*)(last))->Link_002344a0(n);
    else
        head = n;
    return count;
}


// 0x00237050 FUN_00237050 (267 B): equivalent/0x00237050.cpp
// sym: ?FUN_00237050@List_237050@fn_f6c81acf@@QAE_NPAURegistry_237050@2@PAUStream@2@H@Z @49880a58c742 @wd360de17a055
// STATUS: equivalent (tools/equiv.py level 3: 9801 inputs, branch coverage 21/22, incomplete)
// FUN_00237050 @ 0x00237050
bool List_237050::FUN_00237050(Registry_237050* registry, Stream* stream, int index) {
 OpportunityAction_237050* current=head; OpportunityAction_237050* previous=0; int i=0;
 while(current && index>=0 && i<index) { previous=current; current=current->next; ++i; }
 while(stream->ready()) {
  Token_237050 token=stream->token();
  Factory_237050* factory=registry ? registry->FUN_00236790(token) : 0;
  if(!factory) { FUN_00232cc0(stream,"Unrecognized condition."); stream->FUN_00232c90(); }
  else {
   int state=FUN_00266da0(FUN_00238190(2));
   OpportunityAction_237050* node=factory->create();
   if(node->parse(token,registry,stream)) {
    node->FUN_002344a0(current);
    if(previous) previous->FUN_002344a0(node); else head=node;
    previous=node;
   }
   FUN_00266da0(state);
  }
 }
 return true;
}


// 0x00237160 FUN_00237160 (87 B): matches/0x00237160.cpp
// sym: ?Target@Owner_237160@fn_f6c81acf@@QAE_NHHHPAVObj_237160@2@@Z
bool Owner_237160::Target(int a, int b, int c, Obj_237160* obj) {
    if (!obj->Check())
        return false;
    unsigned long long v = (unsigned long long)obj->Pair();
    if ((unsigned int)v != (unsigned int)a)
        return false;
    if ((unsigned int)(v >> 32) != (unsigned int)b)
        return false;
    obj->Act(a, b);
    Work_00237050(c, obj, -1);
    obj->Done();
    return true;
}

} // namespace fn_f6c81acf

// 0x00237230 FUN_00237230 (12 B): matches/0x00237230.cpp
// sym: ?FUN_00237230@Obj_237230@owners@@QAEDH@Z
char owners::Obj_237230::FUN_00237230(int x) {
    value = x;
    return 1;
}


// 0x00237240 FUN_00237240 (12 B): matches/0x00237240.cpp
// sym: ?FUN_00237240@Obj_237240@owners@@QAEDH@Z
char owners::Obj_237240::FUN_00237240(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}


// 0x00237250 FUN_00237250 (12 B): matches/0x00237250.cpp
// sym: ?FUN_00237250@Obj_237250@owners@@QAE_NH@Z
bool owners::Obj_237250::FUN_00237250(int v) {
    value = v;
    return true;
}

namespace fn_f6c81acf {

// 0x00237260 FUN_00237260 (4 B): matches/0x00237260.cpp
// sym: ?GetPtr@A_237260@fn_f6c81acf@@QAEPAVB_237260@2@XZ
B_237260* A_237260::GetPtr() {
    return &val;
}

} // namespace fn_f6c81acf

// 0x00237270 FUN_00237270 (12 B): matches/0x00237270.cpp
// sym: ?FUN_00237270@C_237270@owners@@QAEDH@Z
char owners::C_237270::FUN_00237270(int x) {
    *(int*)((char*)this + 0x24) = x;
    return 1;
}


// 0x00237280 FUN_00237280 (4 B): matches/0x00237280.cpp
// sym: ?FUN_00237280@Obj_237280@owners@@QAEPADXZ
char* owners::Obj_237280::FUN_00237280() {
    return (char*)((char*)pad + 0x28);
}

namespace fn_f6c81acf {

// 0x00237290 FUN_00237290 (19 B): matches/0x00237290.cpp
// sym: ?FUN_00237290@fn_f6c81acf@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00237290() {
    FUN_00234810(((char*)&DAT_004e5bf4), ((char*)&DAT_004e5bf8));
}

} // namespace fn_f6c81acf

// 0x002372b0 fight::OpportunityTrack::vfunc_0 (16 B): matches/0x002372b0.cpp
// sym: ?vfunc_0@OpportunityTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::OpportunityTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5bf4;
    return p[index];
}


// 0x002372c0 FUN_002372c0 (69 B): matches/0x002372c0.cpp [wrapped: conflict: fight::OpportunityTrack]
// sym: ??0OpportunityTrack@fight@fn_002372c0@@QAE@XZ
namespace fn_002372c0 {
namespace fight {
class Base {
  public:
    Base();
    virtual void f();
    char pad[4];
    int flag;
};
class PartA {
  public:
    PartA();
    char pad[12];
};
class PartB {
  public:
    PartB();
};
class OpportunityTrack : public Base {
  public:
    OpportunityTrack();
    virtual void f();
    int a;
    float b;
    int c;
    PartA d;
    int e;
    PartB g;
};
OpportunityTrack::OpportunityTrack() : Base(), a(0), b(-1.0f), c(0), d(), e(0), g() {
    flag = 1;
}
} // namespace fight
} // namespace fn_002372c0


// 0x00237310 fight::OpportunityTrack::vfunc_6 (4 B): matches/0x00237310.cpp
// sym: ?vfunc_6@OpportunityTrack@fight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg fight::OpportunityTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00237320 fight::OpportunityTrack::vfunc_7 (7 B): matches/0x00237320.cpp
// sym: ?vfunc_7@OpportunityTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::OpportunityTrack::vfunc_7() {
    return hulk_at_003f3388;
}

namespace fn_f6c81acf {

// 0x00237330 FUN_00237330 (33 B): matches/0x00237330.cpp
// sym: ??1OpportunityTrack_237330@fn_f6c81acf@@QAE@XZ
OpportunityTrack_237330::~OpportunityTrack_237330() throw() {
    vptr = (void**)DAT_00427ff0;
    a.Fin_00236fd0();
    b.Fin_00234150();
    Fin_00236d60();
}

} // namespace fn_f6c81acf

// 0x002373a0 fight::OpportunityAction::vfunc_3 (53 B): matches/0x002373a0.cpp
// sym: ?vfunc_3@OpportunityAction@fight@@UAE_NHH@Z
bool fight::OpportunityAction::vfunc_3(hulk_intptr value, hulk_intptr unused) {
    hulk_intptr adjusted = value - 1;
    this->f_40 = adjusted;
    this->f_44 = adjusted;
    if (hulk_at_004e5bfc)
        hulk_at_004e5bfc(this->f_1c, this->f_3c, hulk_at_004e5c00, &this->f_40, &this->f_44);
    return true;
}


// 0x002373e0 fight::OpportunityAction::vfunc_4 (43 B): matches/0x002373e0.cpp
// sym: ?vfunc_4@OpportunityAction@fight@@UAEXXZ
// data: zero_2373e0 = DAT_003f32e0
void fight::OpportunityAction::vfunc_4() {
    if (this->f_28 < (*(float*)&DAT_003f32e0) && (*(Receiver_2373e0 * *)&this->f_4c))
        (*(Receiver_2373e0 * *)&this->f_4c)->run_00231ad0(this->f_38, this->f_3c, this->f_30);
}

namespace fn_f6c81acf {

// 0x00237430 fight::OpportunityTrack::vfunc_5 (54 B): matches/0x00237430.cpp
// sym: ?vfunc_5@OpportunityTrack_237430@fn_f6c81acf@@QAEPAV12@E@Z
OpportunityTrack_237430* OpportunityTrack_237430::vfunc_5(unsigned char flags) {
    vptr = ((void**)DAT_00427ff0);
    a28.Fini_00236fd0();
    a18.Fini_00234150();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00237470 FUN_00237470 (179 B): matches/0x00237470.cpp
// sym: ??0OpportunityAction@fn_f6c81acf@@QAE@PAVRefObj_237470@1@HHH0HHH0@Z
OpportunityAction::OpportunityAction(RefObj_237470* a, int b, int c, int d, RefObj_237470* e, int f, int g, int h,
                                     RefObj_237470* i) {
    m24 = c;
    m28 = d;
    m1c = 0;
    m20 = 0;
    m2c = 0;
    m30 = f;
    m34 = g;
    m38 = h;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    if (a)
        a->AddRef();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = b;
    if (e)
        e->AddRef();
    if (m2c)
        m2c->Release();
    m2c = e;
    if (i)
        i->AddRef();
    if (m3c)
        m3c->Release();
    m3c = i;
}


// 0x00237530 FUN_00237530 (89 B): matches/0x00237530.cpp
// sym: ?Dtor2@OpportunityAction_237530@fn_f6c81acf@@QAEXXZ
void OpportunityAction_237530::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p4c) {
        p4c->Release();
        p4c = 0;
    }
    if (p3c) {
        p3c->Release();
        p3c = 0;
    }
    if (p2c) {
        p2c->Release();
        p2c = 0;
    }
    if (p20)
        p20 = 0;
    if (p1c) {
        p1c->Release();
        p1c = 0;
    }
    Action_237530::Dtor_002326a0();
}

} // namespace fn_f6c81acf

// 0x00237590 fight::OpportunityAction::vfunc_5 (278 B): equivalent/0x00237590.cpp [wrapped: conflict: fight::OpportunityAction]
// sym: ?vfunc_5@OpportunityAction@fight@fn_00237590@@UAE_NHM@Z @fea86490945e @wc2a3d60f4042
namespace fn_00237590 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 30/30)
// fight::OpportunityAction::vfunc_5 @ 0x00237590
struct Result_237590;
struct Query_237590 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual Result_237590* s8(int, int);
};
struct Gate_237590 { bool FUN_00236f40(int, int, int); };
struct Result_237590 { void FUN_00231ad0(Result_237590**, int, int); };
extern void __cdecl FUN_00018840(Result_237590**, Result_237590*);
namespace fight {
struct OpportunityAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, float);
 char pad[0x18]; int actor; char pad20[4]; float limit; float trigger;
 Query_237590* query; int mode; Gate_237590* gate; Result_237590** current; int context; int acquireEvent; int executeEvent; float elapsed; Result_237590* result;
};
bool OpportunityAction::vfunc_5(int event, float delta) {
 float a=limit, b=trigger;
 if(acquireEvent==event) {
  if(!result && (a<0.0f || elapsed<=a) && query) {
   if(gate->FUN_00236f40(actor,context,0)) {
    Result_237590* r=query->s8(context,0);
    if(r && r!=*current) FUN_00018840(&result,r);
   }
  }
  elapsed=delta+elapsed;
 }
 if(executeEvent==event && b>=0.0f && result && elapsed>=b) {
  result->FUN_00231ad0(current,context,mode);
  return false;
 }
 if(!(a<0.0f) && !(elapsed<=a) && !result) return false;
 return true;
}
}
} // namespace fn_00237590


// 0x002376d0 fight::ParamFloatConstRange<fight::OpportunityTrack>::vfunc_6 (26 B): matches/0x002376d0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VOpportunityTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::OpportunityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::OpportunityTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))(b);
}


// 0x002376f0 fight::ParamFloatConstRange<fight::OpportunityTrack>::vfunc_2 (11 B): matches/0x002376f0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VOpportunityTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::OpportunityTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f6c81acf {

// 0x00237720 fight::ParamBranch<fight::OpportunityTrack>::vfunc_6 (12 B): matches/0x00237720.cpp
// sym: ?vfunc_6@ParamBranch@fn_f6c81acf@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_f6c81acf

// 0x00237750 fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_6 (26 B): matches/0x00237750.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VOpportunityTrack@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<fight::OpportunityTrack>*)a)->*(*(bool (fight::ParamIntConstRange<fight::OpportunityTrack>::**)(int))&this->f_10))(b);
}


// 0x00237770 fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_2 (11 B): matches/0x00237770.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VOpportunityTrack@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x002377a0 fight::ParamConditionGroup<fight::OpportunityTrack>::vfunc_6 (12 B): matches/0x002377a0.cpp [wrapped: same definition as 0x00237720 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_002377a0@@UAEXPAX@Z
namespace fn_002377a0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_002377a0


// 0x002377c0 fight::TrackFactoryCasterTemplate<fight::OpportunityTrack>::vfunc_0 (36 B): matches/0x002377c0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VOpportunityTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::OpportunityTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x002377f0 fight::ParamFloatConstRange<fight::OpportunityTrack>::vfunc_0 (30 B): matches/0x002377f0.cpp
// sym: ??_G?$ParamFloatConstRange@VOpportunityTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::OpportunityTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::OpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2377f0)
#endif


// 0x00237810 fight::ParamBranch<fight::OpportunityTrack>::vfunc_0 (30 B): matches/0x00237810.cpp
// sym: ??_G?$ParamBranch@VOpportunityTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::OpportunityTrack>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<fight::OpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237810)
#endif


// 0x00237830 fight::ParamIntConstRange<fight::OpportunityTrack>::vfunc_0 (30 B): matches/0x00237830.cpp
// sym: ??_G?$ParamIntConstRange@VOpportunityTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<fight::OpportunityTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<fight::OpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237830)
#endif


// 0x00237850 fight::ParamConditionGroup<fight::OpportunityTrack>::vfunc_0 (30 B): matches/0x00237850.cpp
// sym: ??_G?$ParamConditionGroup@VOpportunityTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamConditionGroup<fight::OpportunityTrack>::~ParamConditionGroup() {}
#if defined(HULK_PTR64)
template class fight::ParamConditionGroup<fight::OpportunityTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x237850)
#endif

namespace fn_f6c81acf {

// 0x002379e0 fight::OpportunityTrack::vfunc_10 (138 B): equivalent/0x002379e0.cpp
// sym: ?vfunc_10@OpportunityTrack@fn_f6c81acf@@UAEPAXPAX00@Z @5055f2e746bf @w061700de61cc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::OpportunityTrack::vfunc_10 @ 0x002379e0
void* OpportunityTrack::vfunc_10(void* a1, void* a2, void* a3) {
    float rise = end - start;
    float fall = peak - start;
    if (!(fall < 0.0f)) {
    } else if (peak >= 0.0f) {
        fall = 0.0f;
    }
    Node* n = (Node*)FUN_0008d690(0x50);
    if (!n) return 0;
    return n->FUN_00237470(a1, this, rise, fall, f18, f24, &sub, a2, a3);
}

} // namespace fn_f6c81acf

// 0x00237a70 fight::OpportunityAction::vfunc_2 (30 B): matches/0x00237a70.cpp
// sym: ??_GOpportunityAction@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::OpportunityAction::~OpportunityAction() {}

namespace fn_f6c81acf {

// 0x00237ab0 FUN_00237ab0 (38 B): matches/0x00237ab0.cpp
// sym: _FUN_00237ab0
extern "C" void FUN_00237ab0(Target* target, const char* name) {
    TrackFactoryCasterTemplate_237ab0 caster;
    target->Method_002367c0(FUN_00236ac0(name, &caster));
}

} // namespace fn_f6c81acf

// 0x00237ae0 fight::TrackFactoryCasterTemplate<fight::OpportunityTrack>::vfunc_1 (60 B): matches/0x00237ae0.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VOpportunityTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::OpportunityTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_237ae0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_237ae0* t = new (mem) TrackFactoryTemplate_237ae0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_00237870();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x00237b20 fight::TrackFactoryTemplate<fight::OpportunityTrack>::vfunc_5 (24 B): matches/0x00237b20.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VOpportunityTrack@fight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f850 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<fight::OpportunityTrack>::vfunc_5() {
    Grapple_237b20* p = (Grapple_237b20*)Alloc_0008d690(0x2c);
    if (p)
        return (void*)(p->ctor_002372c0());
    return (void*)(0);
}

namespace fn_f6c81acf {

// 0x00237b40 fight::TrackFactoryTemplate<fight::OpportunityTrack>::vfunc_2 (43 B): matches/0x00237b40.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f6c81acf@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004280c8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f6c81acf

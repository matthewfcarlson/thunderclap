// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023c2c0..0x0023c500 (kind game, layer engine, confidence high), dominant class fight::Reference
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f8469354 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8469354 {} using namespace fn_f8469354;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f8469354 {
extern "C" char DAT_00428824[];
struct ThisCall_00232e90 {
    void AllocRef(int);
};
void __fastcall InitSub(void* p);
class Reference_23c2c0 {
  public:
    virtual void f();
    char pad[0x24];
    Reference_23c2c0* init();
};
struct Node {
    char pad0[0x10];
    int type;
    char pad14[0x14];
    Node* next;
};
struct Owner_23c300 {
    char pad0[0x28];
    Node* first;
};
class Branch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7();
};
namespace fight {
class Reference : public Branch {
  public:
    virtual int vfunc_8(unsigned int a, unsigned int b);
    virtual void _m_vf9();
    char _m_pad_4[0x24];
    Reference *child;
    void vfunc_7();
    char FUN_002333f0(unsigned int a, unsigned int b);
};
}
struct Helper_23c330 {
    void f(int, int);
};
namespace fight {
extern Reference *DAT_004e5c40;
}


// 0x0023c2c0 FUN_0023c2c0 (28 B): matches/0x0023c2c0.cpp
// sym: ?init@Reference_23c2c0@fn_f8469354@@QAEPAV12@XZ
Reference_23c2c0* Reference_23c2c0::init() {
    ((ThisCall_00232e90*)(this))->AllocRef(4);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428824);
    InitSub((char*)this + 0x28);
    return this;
}


// 0x0023c300 FUN_0023c300 (46 B): matches/0x0023c300.cpp
// sym: ?target@fn_f8469354@@YIPAUNode@1@PAUOwner_23c300@1@@Z
Node* __fastcall target(Owner_23c300* self) {
    Node* p = self->first;
    int n = 0;
    if (p != 0) {
        do {
            if (p->type != 4)
                return p;
            ++n;
            if (n > 0x100 || p == (Node*)self)
                return 0;
            p = p->next;
        } while (p != 0);
    }
    return p;
}


// 0x0023c330 fight::Reference::vfunc_7 (23 B): matches/0x0023c330.cpp
// sym: ?vfunc_7@Reference@fight@fn_f8469354@@UAEXXZ
void fight::Reference::vfunc_7() {
    ((Helper_23c330*)((char*)this + 0x28))->f(0, 0);
    Branch::vfunc_7();
}

} // namespace fn_f8469354

// 0x0023c350 fight::Reference::vfunc_5 (19 B): matches/0x0023c350.cpp [wrapped: conflict: fight::Reference]
// sym: ?vfunc_5@Reference@fight@fn_0023c350@@UAEXXZ
namespace fn_0023c350 {
// Same code shape as 0x002319a0 (propagated; names are from that function)
class Branch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5();
};
namespace fight { class Reference : public Branch {
    char pad[0x24];

  public:
    void vfunc_5();
}; }
struct Helper_23c350 {
    void run(fight::Reference*);
};
void fight::Reference::vfunc_5() {
    Branch::vfunc_5();
    ((Helper_23c350*)((char*)this + 0x28))->run(this);
}
} // namespace fn_0023c350


// 0x0023c370 fight::Reference::vfunc_6 (20 B): matches/0x0023c370.cpp [wrapped: conflict: fight::Reference]
// sym: ?vfunc_6@Reference@fight@fn_0023c370@@UAEXXZ
namespace fn_0023c370 {
// Same code shape as 0x002319c0 (propagated; names are from that function)
struct Part_23c370 {
    void run(void*);
};
class Branch {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6();
};
namespace fight { class Reference : public Branch {
    char pad[0x24];
    Part_23c370 part;

  public:
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void vfunc_6();
    virtual void k();
    virtual void l();
    virtual void m();
}; }
void fight::Reference::vfunc_6() {
    part.run(this);
    Branch::vfunc_6();
}
} // namespace fn_0023c370

namespace fn_f8469354 {

// 0x0023c390 fight::Reference::vfunc_8 (119 B): equivalent/0x0023c390.cpp
// sym: ?vfunc_8@Reference@fight@fn_f8469354@@UAEHII@Z
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// fight::Reference::vfunc_8 @ 0x0023c390
namespace fight {
int Reference::vfunc_8(unsigned int a, unsigned int b)
{
    if (DAT_004e5c40 == 0) {
        DAT_004e5c40 = this;
    } else if (DAT_004e5c40 == this) {
        DAT_004e5c40 = 0;
        return 0;
    }
    if (FUN_002333f0(a, b) && child != 0) {
        int result = child->vfunc_8(a, b);
        if (DAT_004e5c40 == this)
            DAT_004e5c40 = 0;
        return result;
    }
    if (DAT_004e5c40 == this)
        DAT_004e5c40 = 0;
    return 0;
}
}

} // namespace fn_f8469354

// 0x0023c410 fight::Reference::vfunc_9 (192 B): equivalent/0x0023c410.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?vfunc_9@Reference@fight@fn_0023c410@@UAE_NPAUContext@3@PAUObject@3@K@Z
namespace fn_0023c410 {
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 12/12)
// fight::Reference::vfunc_9 @ 0x0023c410

typedef unsigned __int64 Key_23c410;
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual bool slot13(); virtual Key_23c410 slot14(); virtual void slot15(); virtual void slot16(unsigned long low,unsigned long high); virtual void slot17();
};
struct Context { char pad[0x28]; unsigned long value; };
struct Links_23c410 { void FUN_00236ec0(); void FUN_00237160(unsigned long low,unsigned long high,unsigned long value,Object* obj); };
struct Binding_23c410 { void FUN_002340b0(unsigned long low,unsigned long high,Object* obj); };
namespace fight {
struct Reference {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(Context*,Object*,unsigned long);
 char pad[0x14]; Links_23c410 links; char pad2[0xf]; Binding_23c410 binding;
 void FUN_00233c50(Context*,Object*,unsigned long);
 void FUN_002337c0(Context*,Object*,int);
};
bool Reference::vfunc_9(Context* context,Object* object,unsigned long arg) {
 if (!object->slot13()) return false;
 Key_23c410 key=object->slot14();
 if ((unsigned long)key != (*(unsigned long*)&DAT_004e5b10) || (unsigned long)(key>>32)!=(*(unsigned long*)((char*)&DAT_004e5b10 + 4))) return false;
 object->slot16((*(unsigned long*)&DAT_004e5b10),(*(unsigned long*)((char*)&DAT_004e5b10 + 4)));
 FUN_00233c50(context,object,arg);
 binding.FUN_002340b0((*(unsigned long*)&DAT_004e5b98),(*(unsigned long*)&DAT_004e5b9c),object);
 links.FUN_00236ec0();
 if (object->slot13()) {
  key=object->slot14();
  if ((unsigned long)key==(*(unsigned long*)&DAT_004e5b20) && (unsigned long)(key>>32)==(*(unsigned long*)((char*)&DAT_004e5b20 + 4)))
   links.FUN_00237160((*(unsigned long*)&DAT_004e5b20),(*(unsigned long*)((char*)&DAT_004e5b20 + 4)),context->value,object);
 }
 FUN_002337c0(context,object,-1);
 object->slot17();
 return true;
}
}
} // namespace fn_0023c410


// 0x0023c4d0 fight::Reference::vfunc_2 (46 B): matches/0x0023c4d0.cpp [wrapped: conflict: fight::Reference]
// sym: ?vfunc_2@Reference@fight@fn_0023c4d0@@UAEPAV123@H@Z
namespace fn_0023c4d0 {
extern "C" char DAT_00428824[];
class Elem_23c4d0 {
  public:
    void Fn();
};
namespace fight { class Reference {
  public:
    virtual void A();
    virtual void B();
    virtual Reference* vfunc_2(int);
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual void J();
    char pad[0x28 - 4];
    void Init();
}; }
extern void __cdecl FUN_00263f30(fight::Reference*);
fight::Reference* fight::Reference::vfunc_2(int flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428824);
    ((Elem_23c4d0*)((char*)this + 0x28))->Fn();
    Init();
    if (flag & 1)
        FUN_00263f30(this);
    return this;
}
} // namespace fn_0023c4d0


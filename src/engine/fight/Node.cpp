// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00231980..0x00231e00 (kind game, layer engine, confidence high), dominant class fight::Node
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fef6e889 {
#define TREE_TU_END }
namespace fn_fef6e889 {} using namespace fn_fef6e889;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fef6e889 {
class Branch {
  public:
    void vfunc_7_002331f0();
};
class Aux_231980 {
  public:
    void Fnf_00239e10();
};
class Node : public Branch {
    char pad[0x28 - sizeof(Branch)];

  public:
    void vfunc_7();
};
struct Node_nv_2319e0 {
    char helper_002333f0(hulk_uintptr, unsigned int);
};
struct Item_231a00 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Test(int, int);
    int a[3];
    int type;
    Item_231a00* Next_00232fc0();
    hulk_intptr target(hulk_intptr);
};


// 0x00231980 fight::Node::vfunc_7 (19 B): matches/0x00231980.cpp
// sym: ?vfunc_7@Node@fn_fef6e889@@QAEXXZ
void Node::vfunc_7() {
    ((Aux_231980*)((char*)this + 0x28))->Fnf_00239e10();
    Branch::vfunc_7_002331f0();
}

} // namespace fn_fef6e889

// 0x002319a0 fight::Node::vfunc_5 (19 B): matches/0x002319a0.cpp [wrapped: merged class would differ: Node: array bound 0x28 - sizeof ( Branch )]
// sym: ?vfunc_5@Node@fn_002319a0@@UAEXXZ
namespace fn_002319a0 {
class Branch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5();
};
class Node : public Branch {
    char pad[0x24];

  public:
    void vfunc_5();
};
struct Helper_2319a0 {
    void run_00239e30(Node*);
};
void Node::vfunc_5() {
    Branch::vfunc_5();
    ((Helper_2319a0*)((char*)this + 0x28))->run_00239e30(this);
}
} // namespace fn_002319a0


// 0x002319c0 fight::Node::vfunc_6 (20 B): matches/0x002319c0.cpp [wrapped: conflict: Node]
// sym: ?vfunc_6@Node@fn_002319c0@@UAEXXZ
namespace fn_002319c0 {
struct Part_2319c0 {
    void run_00239e60(void*);
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
class Node : public Branch {
    char pad[0x24];
    Part_2319c0 part;

  public:
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void vfunc_6();
    virtual void k();
    virtual void l();
    virtual void m();
};
void Node::vfunc_6() {
    part.run_00239e60(this);
    Branch::vfunc_6();
}
} // namespace fn_002319c0


// 0x002319e0 fight::Node::vfunc_8 (30 B): matches/0x002319e0.cpp
// sym: ?vfunc_8@Node@fight@@UAEIII@Z
hulk_uintptr fight::Node::vfunc_8(hulk_uintptr a, unsigned int b) {
    if (((Node_nv_2319e0*)this)->helper_002333f0(a, b))
        return (hulk_uintptr)this;
    return 0;
}

namespace fn_fef6e889 {

// 0x00231a00 FUN_00231a00 (57 B): matches/0x00231a00.cpp
// sym: ?target@Item_231a00@fn_fef6e889@@QAEHH@Z
hulk_intptr Item_231a00::target(hulk_intptr param) {
    Item_231a00* p = Next_00232fc0();
    while (p) {
        if (p->type != 2) {
            int r = p->Test(param, 0);
            if (r)
                return r;
        }
        p = p->Next_00232fc0();
    }
    return 0;
}

} // namespace fn_fef6e889

// 0x00231a40 FUN_00231a40 (142 B): matches/0x00231a40.cpp [wrapped: merged class would differ: Node: array bound 0x28 - sizeof ( Branch )]
// sym: ?Run@Owner_231a40@fn_00231a40@@QAEEHH@Z
namespace fn_00231a40 {
class Node {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Match(int, int);
    virtual int Check(int, int, int);
    Node* next;
    int mode;
};
extern int __cdecl FUN_00238190(int);
extern "C" int __cdecl FUN_00266da0(int);
class Owner_231a40 {
  public:
    char pad[0x28];
    Node* nodes;
    unsigned char Run(hulk_intptr, hulk_intptr);
};
unsigned char Owner_231a40::Run(hulk_intptr a, hulk_intptr b) {
    int t = FUN_00238190(3);
    t = FUN_00266da0(t);
    Node* n = nodes;
    unsigned char result = 0;
    if (n) {
        do {
            if (n->mode == 0) {
                if (n->Match(a, b) == a) {
                    result = 1;
                    break;
                }
            } else if (n->mode == 3) {
                int matched = n->Match(a, b);
                if (matched == a && n->Check((hulk_intptr)this, matched, b) == 0) {
                    result = 1;
                    break;
                }
            }
            n = n->next;
        } while (n);
    }
    FUN_00266da0(t);
    return result;
}
} // namespace fn_00231a40


// 0x00231c50 fight::Node::vfunc_9 (230 B): equivalent/0x00231c50.cpp [wrapped: conflict: fight::Node]
// sym: ?vfunc_9@Node@fight@fn_00231c50@@UAE_NPAUContext@3@PAUSource_231c50@3@I@Z @d88aca11d3d0 @w5e255316d4c8
namespace fn_00231c50 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 18/18)
// fight::Node::vfunc_9 @ 0x00231c50

typedef unsigned __int64 Key_231c50;
struct Source_231c50 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
 virtual bool s13(); virtual Key_231c50 s14(); virtual void s15(); virtual void s16(unsigned int,unsigned int); virtual void s17();
};
struct Context { char pad[0x28]; unsigned int value; };
struct ListA_231c50 { char pad[16]; void FUN_00236ec0(); void FUN_00237160(unsigned int,unsigned int,unsigned int,Source_231c50*); };
struct ListB { char pad[16]; void FUN_00239e10(); void FUN_0023a020(unsigned int,unsigned int,unsigned int,Source_231c50*); };
namespace fight { struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(Context*,Source_231c50*,unsigned int);
 char pad[0x14]; ListA_231c50 a; ListB b;
 void FUN_00233c50(Context*,Source_231c50*,unsigned int);
 void FUN_002337c0(Context*,Source_231c50*,int);
}; }
bool fight::Node::vfunc_9(Context* context,Source_231c50* source,unsigned int arg) {
 if (!source->s13()) return false;
 Key_231c50 key=source->s14();
 if ((unsigned int)key!=(*(unsigned int*)&DAT_004e5b70) || (unsigned int)(key>>32)!=(*(unsigned int*)((char*)&DAT_004e5b70 + 4))) return false;
 source->s16((*(unsigned int*)&DAT_004e5b70),(*(unsigned int*)((char*)&DAT_004e5b70 + 4)));
 FUN_00233c50(context,source,arg);
 a.FUN_00236ec0();
 if(source->s13()) {
 key=source->s14();
 if((unsigned int)key==(*(unsigned int*)&DAT_004e5b20) && (unsigned int)(key>>32)==(*(unsigned int*)((char*)&DAT_004e5b20 + 4))) a.FUN_00237160((*(unsigned int*)&DAT_004e5b20),(*(unsigned int*)((char*)&DAT_004e5b20 + 4)),context->value,source);
 }
 b.FUN_00239e10();
 if(source->s13()) {
 key=source->s14();
 if((unsigned int)key==(*(unsigned int*)&DAT_004e5ba0) && (unsigned int)(key>>32)==(*(unsigned int*)&DAT_004e5ba4)) b.FUN_0023a020((*(unsigned int*)&DAT_004e5ba0),(*(unsigned int*)&DAT_004e5ba4),context->value,source);
 }
 FUN_002337c0(context,source,-1);
 source->s17();
 return true;
}
} // namespace fn_00231c50


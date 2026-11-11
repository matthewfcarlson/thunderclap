// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00295c40..0x002980b0 (kind game, layer engine, confidence high), dominant class pure3d::scenegraph::Scenegraph
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/engine/pure3d/scenegraph.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9b7dd8c {
#define TREE_TU_END }
namespace fn_f9b7dd8c {} using namespace fn_f9b7dd8c;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f9b7dd8c {
class B_295c40 {
  public:
    B_295c40();
    virtual void f();
};
class C_295c40 : public B_295c40 {
  public:
    C_295c40();
    int pad[3];
    int a;
    int b;
};
extern "C" char DAT_0042d1ec[];
typedef unsigned int u32_295c70;
class Base_295c70 {
  public:
    hulk_uintptr vf;
    char pad[4];
    void Init_0027b070();
};
class Child_295c70 {
  public:
    void Copy_0027af70(void*);
};
class Thing_295c70 : public Base_295c70 {
  public:
    char pad8[8];
    u32_295c70 a;
    u32_295c70 b;
    Thing_295c70* Run(void* src);
};
struct Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void F(int a, unsigned m, int b, int c);
    virtual unsigned int count();
    virtual Node* child(unsigned int index);
    char _m_pad_4[0xc];
    int flags;
    Node* parent;
};
struct X_295d20 {
    char pad[0x14];
    unsigned value;
};
class pddiObject_295e50 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_295e50 : public pddiObject_295e50 {};
class pddiBaseShader_295e50 : public pddiShader_295e50 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_295e50 : public pddiBaseShader_295e50 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class ParamValue_295f10 {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern "C" char DAT_0042d23c[];
class Base_295f30 {
  public:
    Base_295f30();
    char pad[16];
};
class LeafNode : public Base_295f30 {
  public:
    int x;
    int y;
    LeafNode();
};
class ParamValue_295fa0 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Node_295fc0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class LeafNode_295fc0 : public Node_295fc0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
} // namespace fn_f9b7dd8c
extern "C" void _ReadWriteBarrier();
namespace fn_f9b7dd8c {
class LeafNode_295fd0 {
  public:
    virtual void Dummy();
    char pad[0x10 - 4];
    int m10;
    int m14;
    int m18;
    LeafNode_295fd0();
};
class DrawableNode_295fd0 : public LeafNode_295fd0 {
  public:
    DrawableNode_295fd0();
};
class Obj_296060 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual bool h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
};
class DrawableNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(int, int);
    char p[12];
    unsigned char flags;
    char q[7];
    DrawableNode* child;
    void vfunc_8(int, int, int);
};
class Child_2960b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void vfunc_9();
};
struct Ctor_002a3480 {
    Ctor_002a3480();
};
class Scenegraph : public Ctor_002a3480 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    Scenegraph();
};
struct Device {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(int); virtual void vfunc_16(int); virtual void vfunc_17(); virtual int vfunc_18(int);
};
struct Child {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(int, int, int);
};
class Obj_2961c0 {
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
};
class CJumpTrack {
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
    virtual void f24();
    virtual void f25();
    virtual hulk_uintptr vfunc_26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    char pad[0x40 - 4];
    unsigned int m;
};
typedef unsigned int u32_2961e0;
class B_2961e0 {
  public:
    virtual u32_2961e0 a0();
    virtual u32_2961e0 a1();
    virtual u32_2961e0 a2();
    virtual u32_2961e0 a3();
    virtual u32_2961e0 a4();
    virtual u32_2961e0 a5();
    virtual u32_2961e0 a6();
    virtual u32_2961e0 a7();
    virtual u32_2961e0 a8();
    virtual u32_2961e0 a9();
    virtual u32_2961e0 a10();
    virtual u32_2961e0 a11();
    virtual u32_2961e0 a12();
    virtual u32_2961e0 a13();
    virtual u32_2961e0 a14();
    virtual u32_2961e0 a15(u32_2961e0, u32_2961e0, u32_2961e0, u32_2961e0, u32_2961e0);
};
class A_2961e0 {
  public:
    char pad[0x40];
    B_2961e0* p;
    hulk_uintptr f(u32_2961e0 a, u32_2961e0 b, u32_2961e0 c, u32_2961e0 d);
};
struct Visitor {
    virtual unsigned char accepts(Node* node);
};
class Visitor_296290 {
  public:
    virtual void a();
    virtual void b();
};
class Item_296290 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int type();
};
class ShaderCallbackVisitor {
  public:
    virtual void V();
    void* mThing;
    ShaderCallbackVisitor(void* p);
};
class Node_296310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int Type();
    char pad[0x18 - 4];
    Node_296310* child;
};
class Callback_296310 {
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
    virtual void f13(int);
    virtual void f14();
};
class pure3d_scenegraph_Traversal_Visitor {
  public:
    int pad;
    int callback;
};
extern void* hulk_at_0042d1ec[];
class Entity_296570 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class Node_296570 : public Entity_296570 {
  public:
    Node_296570* vfunc_5(signed char flags);
};
} // namespace fn_f9b7dd8c
namespace pure3d { namespace scenegraph {
struct Node_2965a0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(void*, void*);
};
} }
namespace fn_f9b7dd8c {
class Child_2965e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool f7();
};
class Obj_296620 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int, int);
};
class Item_296740 {
  public:
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
    virtual void k(int, int, int, int);
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o(void*);
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
};
class Node_2967a0 {
public:
    virtual void v0();
    virtual void Release();
};
} // namespace fn_f9b7dd8c
namespace pure3d { namespace scenegraph {
class Obj_296850 {
  public:
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
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual bool check();
};
} }
namespace pure3d { namespace scenegraph {
class Item_296850 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual bool check();
};
} }
namespace fn_f9b7dd8c {
class Child_296930 {
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
};
class Callback_296930 {
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
};
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000004();
};
struct Owner {
    char pad[0xa8];
    Item *item;
    void FUN_00296970(Item *replacement);
};
class Obj_2969f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool f7();
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
    virtual bool f22();
};
struct Obj_296aa0 {
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
};
extern void* Node_296b20_vftable[];
class Node_296b20 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class LeafNode_296b20 : public Node_296b20 {
  public:
    LeafNode_296b20* vfunc_5(signed char flags);
};
extern "C" char DAT_0042d28c[];
class Ref_296b50 {
  public:
    virtual void f();
    virtual void Release() throw();
};
struct DrawableNode_nv_296b50 {
    void Finish_0027afd0();
};
class Item_296b80 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_296b80 {
    char pad[0x18];

  public:
    Item_296b80* item;
    void Set(Item_296b80* p);
};
extern void* g_vftable_0042d2dc[];
class Ref_296bb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_296bb0 {
  public:
    void* vptr;
    void Fin_002a35f0();
};
class Obj_296bb0 : public Base_296bb0 {
  public:
    char pad[60];
    Ref_296bb0* m;
    ~Obj_296bb0();
};
class RefCounted_296be0 {
public:
    virtual void AddRef() throw();
    virtual void Release() throw();
};
struct Scene;
} // namespace fn_f9b7dd8c
namespace pure3d { namespace scenegraph {
class ShaderCallbackVisitor_296be0 {
public:
    ShaderCallbackVisitor_296be0(RefCounted_296be0 *p) throw() : shader(p) {
        if (shader != 0)
            shader->AddRef();
    }
    virtual ~ShaderCallbackVisitor_296be0() throw() {
        if (shader != 0)
            shader->Release();
    }
    RefCounted_296be0 *shader;
};
} }
namespace fn_f9b7dd8c {
void __cdecl FUN_00296220(Scene *scene, pure3d::scenegraph::ShaderCallbackVisitor_296be0 *v) throw();
extern "C" char DAT_0042d330[];
class Ref_296c50 {
  public:
    virtual void f0();
    virtual void Release();
};
struct Callback_296c50 {
    void* vt;
    Ref_296c50* result;
};
extern void FUN_00296220(Ref_296c50*, Callback_296c50*);
} // namespace fn_f9b7dd8c
namespace pure3d { namespace scenegraph {
struct BoundingVolumeUpdater_296cb0 { virtual void vfunc_0(); unsigned char flag; char pad[3]; float bounds[6]; };
} }
namespace fn_f9b7dd8c {
struct Sphere_296cb0 { float x,y,z,r; };
struct Bounds_296cb0 { float v[6]; Sphere_296cb0* FUN_000a8890(Sphere_296cb0* out); };
void __cdecl FUN_00296220(void* root, pure3d::scenegraph::BoundingVolumeUpdater_296cb0* updater);
extern int hulk_at_0042d28c, vt2;
extern void Free_00263f30(void*);
class Ref_296fd0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_296fd0 {
  public:
    void* vptr;
    void Fini_0027afd0();
};
class D : public Root_296fd0 {
  public:
    char p[0x14];
    Ref_296fd0* a18;
    D* vfunc2(unsigned char f);
};
class Child_297010 {
  public:
    virtual void Destroy();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual Child_297010* Get();
};
class Obj_297010 {
  public:
    hulk_intptr vptr;
    int x[5];
    Child_297010* c;
    Obj_297010* Build(Obj_297010*);
};
class Base_297010 {
  public:
    void Init_0027b070();
};
class Name_297010 {
  public:
    void Copy_0027af70(Name_297010*);
};
class Helper_297080 {
  public:
    hulk_intptr run_00297010(pure3d::scenegraph::DrawableNode*);
};
extern void* __cdecl alloc_00263ea0(int);
extern "C" char DAT_0042d348[];
class Obj_297150 {
  public:
    hulk_intptr v;
    int a;
    int b;
    int c;
    int d;
    Obj_297150();
};
} // namespace fn_f9b7dd8c
void* operator new(size_t);
namespace fn_f9b7dd8c {
class Base_2972e0 {
  public:
    Base_2972e0();
    virtual void f0();
    int pad[3];
};
class Mid_2972e0 : public Base_2972e0 {
  public:
    Mid_2972e0() {
        m10 = 6;
        m14 = 0;
    }
    int m10, m14;
};
class BranchNode : public Mid_2972e0 {
  public:
    BranchNode(unsigned int n);
    virtual void g0();
    int m18;
    int** m1c;
    int** m20;
};
struct Helper_2973b0 {
    hulk_intptr Fnf_002971f0(pure3d::scenegraph::BranchNode*);
};
extern "C" void* __cdecl thunk_FUN_0008d690(int);
extern "C" char DAT_0042d3bc[];
typedef unsigned int u32_297460;
struct Base_297460 {
    void Init_002972e0(u32_297460);
};
struct Part_297460 {
    void Init_0022b980();
    char pad[0x40];
};
extern int hulk_at_0042d3bc;
class Ref_2974a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class BranchNode_2974a0 {
  public:
    void* vptr;
    ~BranchNode_2974a0() throw();
};
class TransformNode_2974a0 : public BranchNode_2974a0 {
  public:
    char pa8[164];
    Ref_2974a0* aa8;
    ~TransformNode_2974a0() throw();
};
class Helper_2974d0 {
  public:
    hulk_intptr call_002973d0(pure3d::scenegraph::TransformNode*);
};
extern int hulk_at_0042d414;
class Ref_297590 {
  public:
    virtual void f0();
    virtual void Release();
};
class BranchNode_297590 {
  public:
    void* vptr;
    ~BranchNode_297590() throw();
};
class VisibilityNode_297590 : public BranchNode_297590 {
  public:
    char p2c[40];
    Ref_297590* a2c;
    ~VisibilityNode_297590() throw();
};
class Other_2975c0 {
  public:
    hulk_intptr helper_00297500(pure3d::scenegraph::VisibilityNode*);
};
class Ref_297600 {
  public:
    virtual void f0();
    virtual void f1();
};
class TransformNode {
  public:
    virtual void _m_vf0();
    virtual void f1();
    char _m_pad_4[0x24];
    Part_297460 a;
    Part_297460 b;
    union { u32_297460 field; Ref_297600* ref; };
    TransformNode* Init(u32_297460);
    TransformNode* vfunc_2(unsigned int p);
    void helper_00297350();
};
void __cdecl thunk_FUN_00267090(TransformNode*);
void *thunk_FUN_0008d690(unsigned int size);
struct Name_297680 {
    char data[8];
    void FUN_0027b040(const char *s);
};
struct Reader_297680 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};
struct Stream_297680 {
    char pad0[0x284];
    Reader_297680 *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
    char *FUN_000f9600(char *out);
};
class ObjectLoader_297680 {
public:
    virtual void v0();
    virtual void v1();
};
class FrameController_297680 {
public:
    virtual void v0();
    virtual void v1();
};
class FrameControllerLoader_297680 : public ObjectLoader_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(FrameController_297680 **out, unsigned __int64 *id, Stream_297680 *s, void *ctx);
};
class SceneGraphTransformAnimationController_297680 : public FrameController_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void *target);
};
class SceneGraphVisibilityAnimationController_297680 : public FrameController_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void *target);
};
class Node_297680 {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void AddChild(Node_297680 *child);
    char pad04[4];
    Name_297680 name;
};
class NodeA_297680 : public Node_297680 {
public:
    char pad[0x28 - 0x10];
    NodeA_297680 *FUN_002972e0(int v);
};
class NodeB_297680 : public Node_297680 {
public:
    char pad[0xb0 - 0x10];
    NodeB_297680 *FUN_00297460(int v);
    hulk_intptr FUN_001a4990();
    void FUN_00296970(SceneGraphTransformAnimationController_297680 *c);
};
class NodeC_297680 : public Node_297680 {
public:
    char pad[0x28 - 0x10];
    bool flag28;
    char pad29[0x30 - 0x29];
    NodeC_297680 *FUN_00297560(int v);
    void FUN_00296ae0(SceneGraphVisibilityAnimationController_297680 *c);
};
class DrawableHierarchy_297680 {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual DrawableHierarchy_297680 *h4();
};
struct DrawableNode_nv_297680 {
    pure3d::scenegraph::DrawableNode *FUN_00295fd0();
    void FUN_00296b80(DrawableHierarchy_297680 *h);
};
struct HolderName_297680 {
    char pad[8];
    Name_297680 name;
};
struct Registry_297680 {
    ObjectLoader_297680 *FUN_00265310(int id);
};
DrawableHierarchy_297680 *FUN_000c0de0(void *ctx, char *name);
class SceneLoader_297680;
struct Frame_297680 {
    union {
        int x;
        FrameController_297680 *fc;
    };
    SceneLoader_297680 *self;
    unsigned __int64 id;
    char name[0x100];
};
class SceneLoader_297680 {
public:
    Node_297680 *FUN_00297680(Stream_297680 *s, void *ctx);
};


// 0x00295c40 FUN_00295c40 (32 B): matches/0x00295c40.cpp
// sym: ??0C_295c40@fn_f9b7dd8c@@QAE@XZ
C_295c40::C_295c40() {
    a = 6;
    b = 0;
}

} // namespace fn_f9b7dd8c

// 0x00295c60 pure3d::scenegraph::Node::vfunc_7 (3 B): matches/0x00295c60.cpp
// sym: ?vfunc_7@Node@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::Node::vfunc_7() {
    return true;
}

namespace fn_f9b7dd8c {

// 0x00295c70 FUN_00295c70 (48 B): matches/0x00295c70.cpp
// sym: ?Run@Thing_295c70@fn_f9b7dd8c@@QAEPAV12@PAX@Z
Thing_295c70* Thing_295c70::Run(void* src) {
    Init_0027b070();
    vf = ((hulk_intptr)DAT_0042d1ec);
    a = ((u32_295c70*)src)[4];
    b = ((u32_295c70*)src)[5];
    ((Child_295c70*)((char*)this + 8))->Copy_0027af70((char*)src + 8);
    return this;
}


// 0x00295cb0 pure3d::scenegraph::Node::vfunc_10 (110 B): matches/0x00295cb0.cpp
// sym: ?F@Node@fn_f9b7dd8c@@UAEXHIHH@Z
void Node::F(int a, unsigned m, int b, int c) {
    if (b == 1 && parent) {
        if ((char)a == 1) {
            if ((char)c == 1) {
                if ((flags & m) == m)
                    return;
            }
        } else if ((char)c == 1) {
            if ((flags & ~m) == m)
                return;
        }
        parent->F(a, m, 1, c);
    }
    if ((char)a == 1) {
        flags |= m;
        return;
    }
    flags &= ~m;
}


// 0x00295d20 pure3d::scenegraph::Node::vfunc_13 (4 B): matches/0x00295d20.cpp
// sym: ?target@fn_f9b7dd8c@@YIIPAUX_295d20@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_295d20* self) {
    return self->value;
}

} // namespace fn_f9b7dd8c

// 0x00295d30 pure3d::scenegraph::Node::vfunc_14 (10 B): matches/0x00295d30.cpp
// sym: ?vfunc_14@Node@scenegraph@pure3d@@UAEXH@Z
void pure3d::scenegraph::Node::vfunc_14(int value) {
    *(int*)((char*)this + 0x14) = value;
}


// 0x00295d40 pure3d::scenegraph::Node::vfunc_15 (190 B): equivalent/0x00295d40.cpp [wrapped: conflict: pure3d::scenegraph::Node]
// sym: ?vfunc_15@Node@scenegraph@pure3d@fn_00295d40@@UAEPAU1234@HHHII@Z @ef76b628e89d @wad14330d1716
namespace fn_00295d40 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 22/22)
// pure3d::scenegraph::Node::vfunc_15 @ 0x00295d40

namespace pure3d { namespace scenegraph {
struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual unsigned int vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual unsigned int vfunc_11(); virtual Node* vfunc_12(unsigned int); virtual void vfunc_13(); virtual void vfunc_14(); virtual Node* vfunc_15(int,int,int,unsigned int,unsigned int); virtual void vfunc_16(); virtual void vfunc_17();
 int field4; int key1; int key2; int field16; Node* parent;
};
Node* Node::vfunc_15(int a,int b,int direction,unsigned int mask,unsigned int match) {
 unsigned int flags=vfunc_5();
 if ((mask & flags) && key1==a && key2==b) {
  if ((*(unsigned int*)&DAT_0052cb98)==match) return this;
  ++(*(unsigned int*)&DAT_0052cb98);
 }
 if(direction==1) {
  if(parent) return parent->vfunc_15(a,b,1,mask,match);
 } else if(direction==2) {
  unsigned int index=0;
  if(vfunc_11()>0) {
   do {
    Node* child=vfunc_12(index);
    if(child) { Node* result=child->vfunc_15(a,b,2,mask,match); if(result) return result; }
    ++index;
   } while(index<vfunc_11());
  }
 }
 return 0;
}
}}
} // namespace fn_00295d40


// 0x00295e00 pure3d::scenegraph::Node::vfunc_16 (20 B): matches/0x00295e00.cpp
// sym: ?vfunc_16@Node@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::Node::vfunc_16() {
    if ((*(pure3d::scenegraph::Node * *)&this->f_14))
        return (void*)((*(pure3d::scenegraph::Node * *)&this->f_14)->vfunc_16());
    return (void*)(((float*)&DAT_004c9f38));
}


// 0x00295e20 pure3d::scenegraph::Node::vfunc_17 (22 B): matches/0x00295e20.cpp
// sym: ?vfunc_17@Node@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::Node::vfunc_17() {
    this->f_10 &= ~4;
    if ((*(pure3d::scenegraph::Node * *)&this->f_14))
        return (void*)((*(pure3d::scenegraph::Node * *)&this->f_14)->vfunc_17());
    extern float one;
    return (void*)(&one);
}


// 0x00295e40 pure3d::scenegraph::BranchNode::vfunc_3 (3 B): matches/0x00295e40.cpp
// sym: ?vfunc_3@BranchNode@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::BranchNode::vfunc_3() {
    return true;
}


// 0x00295e50 pure3d::scenegraph::BranchNode::vfunc_5 (6 B): matches/0x00295e50.cpp
// sym: ?vfunc_5@BranchNode@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::scenegraph::BranchNode::vfunc_5() {
    return 1;
}

namespace fn_f9b7dd8c {

// 0x00295e60 pure3d::scenegraph::BranchNode::vfunc_11 (4 B): matches/0x00295e60.cpp
// sym: ?FUN_00295e60@fn_f9b7dd8c@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_00295e60(hulk_intptr object) {
    return *(int*)(object + 0x18);
}

} // namespace fn_f9b7dd8c

// 0x00295e70 pure3d::scenegraph::TransformNode::vfunc_3 (3 B): matches/0x00295e70.cpp
// sym: ?vfunc_3@TransformNode@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::TransformNode::vfunc_3() {
    return true;
}


// 0x00295e80 pure3d::scenegraph::TransformNode::vfunc_5 (6 B): matches/0x00295e80.cpp
// sym: ?vfunc_5@TransformNode@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int pure3d::scenegraph::TransformNode::vfunc_5() {
    return 2;
}


// 0x00295e90 pure3d::scenegraph::TransformNode::vfunc_16 (4 B): matches/0x00295e90.cpp
// sym: ?vfunc_16@TransformNode@scenegraph@pure3d@@UAEPAXXZ
// Same code shape as 0x00091d20 (propagated; names are from that function)
void* pure3d::scenegraph::TransformNode::vfunc_16() {
    return (void*)((char*)this + 0x28);
}


// 0x00295ea0 pure3d::scenegraph::TransformNode::vfunc_17 (74 B): matches/0x00295ea0.cpp [wrapped: conflict: pure3d::scenegraph::Node; pure3d::scenegraph::TransformNode]
// sym: ?vfunc_17@TransformNode@scenegraph@pure3d@fn_00295ea0@@UAEPAUMat@234@XZ
namespace fn_00295ea0 {
namespace pure3d {
namespace scenegraph {
struct Mat {
    unsigned int v[16];
    void combine_0022ca90(Mat*, Mat*);
};
class Node {
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
    virtual Mat* vfunc_17();
    char pad[12];
    union {
        unsigned int flags;
        unsigned char flagByte;
    };
    Node* other;
    char pad2[16];
    Mat local;
    Mat world;
};
class TransformNode : public Node {
  public:
    Mat* vfunc_17();
};
} // namespace scenegraph
} // namespace pure3d
pure3d::scenegraph::Mat* pure3d::scenegraph::TransformNode::vfunc_17() {
    if (flagByte & 4) {
        if (other) {
            Mat* m = other->vfunc_17();
            world.combine_0022ca90(&local, m);
            flags &= ~4;
        } else {
            unsigned int f = flags;
            world = local;
            flags = f & ~4;
        }
    }
    return &world;
}
} // namespace fn_00295ea0


// 0x00295f00 pure3d::scenegraph::VisibilityNode::vfunc_3 (3 B): matches/0x00295f00.cpp
// sym: ?vfunc_3@VisibilityNode@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::VisibilityNode::vfunc_3() {
    return true;
}


// 0x00295f10 pure3d::scenegraph::VisibilityNode::vfunc_5 (6 B): matches/0x00295f10.cpp
// sym: ?vfunc_5@VisibilityNode@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x00055210 (propagated; names are from that function)
int pure3d::scenegraph::VisibilityNode::vfunc_5() {
    return 4;
}

namespace fn_f9b7dd8c {

// 0x00295f30 FUN_00295f30 (32 B): matches/0x00295f30.cpp
// sym: ??0LeafNode@fn_f9b7dd8c@@QAE@XZ
LeafNode::LeafNode() : Base_295f30() {
    x = 6;
    y = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042d23c);
}

} // namespace fn_f9b7dd8c

// 0x00295f50 FUN_00295f50 (54 B): matches/0x00295f50.cpp [wrapped: conflict: LeafNode]
// sym: ??0LeafNode@fn_00295f50@@QAE@ABV01@@Z
namespace fn_00295f50 {
class Entity_295f50 {
  public:
    Entity_295f50();
    virtual void f0();
    int pad;
};
class Part {
  public:
    void Copy_0027af70(const Part&);
    char x[8];
};
class Node : public Entity_295f50 {
  public:
    Node(const Node& other) : Entity_295f50() {
        a = other.a;
        b = other.b;
        p.Copy_0027af70(other.p);
    }
    virtual void g();
    Part p;
    int a, b;
};
class LeafNode : public Node {
  public:
    LeafNode(const LeafNode&);
    virtual void h();
};
LeafNode::LeafNode(const LeafNode& other) : Node(other) {}
} // namespace fn_00295f50


// 0x00295fa0 pure3d::scenegraph::LeafNode::vfunc_5 (6 B): matches/0x00295fa0.cpp
// sym: ?vfunc_5@LeafNode@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x00234f10 (propagated; names are from that function)
int pure3d::scenegraph::LeafNode::vfunc_5() {
    return 8;
}

namespace fn_f9b7dd8c {

// 0x00295fb0 pure3d::scenegraph::LeafNode::vfunc_11 (3 B): matches/0x00295fb0.cpp
// sym: ?GetZero@fn_f9b7dd8c@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x00295fc0 pure3d::scenegraph::LeafNode::vfunc_12 (5 B): matches/0x00295fc0.cpp
// sym: ?vfunc_0@LeafNode_295fc0@fn_f9b7dd8c@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int LeafNode_295fc0::vfunc_0(int) {
    return 0;
}


// 0x00295fd0 FUN_00295fd0 (33 B): matches/0x00295fd0.cpp
// sym: ??0DrawableNode_295fd0@fn_f9b7dd8c@@QAE@XZ
DrawableNode_295fd0::DrawableNode_295fd0() : LeafNode_295fd0() {
    m14 = 0;
    m18 = 0;
    m10 = 6;
    *(hulk_intptr*)this = (hulk_intptr)vt;
    _ReadWriteBarrier();
}

} // namespace fn_f9b7dd8c

// 0x00296000 pure3d::scenegraph::DrawableNode::vfunc_3 (3 B): matches/0x00296000.cpp
// sym: ?vfunc_3@DrawableNode@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::DrawableNode::vfunc_3() {
    return true;
}


// 0x00296030 pure3d::scenegraph::DrawableNode::vfunc_5 (6 B): matches/0x00296030.cpp
// sym: ?vfunc_5@DrawableNode@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x00274850 (propagated; names are from that function)
int pure3d::scenegraph::DrawableNode::vfunc_5() {
    return (int)(0x10);
}


// 0x00296040 pure3d::scenegraph::DrawableNode::vfunc_6 (23 B): matches/0x00296040.cpp
// sym: ?vfunc_6@DrawableNode@scenegraph@pure3d@@UAEXHH@Z
void pure3d::scenegraph::DrawableNode::vfunc_6(hulk_intptr x, hulk_intptr y) {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(void * *)&this->f_18))
        ((pure3d::scenegraph::DrawableNode*)(*(void * *)&this->f_18))->vfunc_6(x, y);
}


// 0x00296060 pure3d::scenegraph::DrawableNode::vfunc_7 (28 B): matches/0x00296060.cpp
// sym: ?vfunc_7@DrawableNode@scenegraph@pure3d@@UAE_NXZ
bool pure3d::scenegraph::DrawableNode::vfunc_7() {
    if (((*(unsigned char *)&this->f_10) & 1) == 0 && (*(Obj_296060 * *)&this->f_18) != 0 && !(*(Obj_296060 * *)&this->f_18)->h())
        return false;
    return true;
}

namespace fn_f9b7dd8c {

// 0x00296080 pure3d::scenegraph::DrawableNode::vfunc_8 (33 B): matches/0x00296080.cpp
// sym: ?vfunc_8@DrawableNode@fn_f9b7dd8c@@QAEXHHH@Z
void DrawableNode::vfunc_8(int a, int b, int c) {
    if ((flags & 1) == 0 && child)
        child->vfunc_8(b, c);
}

} // namespace fn_f9b7dd8c

// 0x002960b0 pure3d::scenegraph::DrawableNode::vfunc_9 (17 B): matches/0x002960b0.cpp
// sym: ?vfunc_9@DrawableNode@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::DrawableNode::vfunc_9() {
    (*(unsigned int *)&this->f_10) &= 1;
    if ((*(Child_2960b0 * *)&this->f_18))
        (*(Child_2960b0 * *)&this->f_18)->vfunc_9();
}

namespace fn_f9b7dd8c {

// 0x002960d0 FUN_002960d0 (4 B): matches/0x002960d0.cpp
// sym: ?FUN_002960d0@fn_f9b7dd8c@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
hulk_intptr __fastcall FUN_002960d0(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x002960e0 FUN_002960e0 (25 B): matches/0x002960e0.cpp
// sym: ??0Scenegraph@fn_f9b7dd8c@@QAE@XZ
Scenegraph::Scenegraph() : Ctor_002a3480() {
    vptr = &scenegraph_vftable;
    field40 = 0;
}

} // namespace fn_f9b7dd8c

// 0x00296100 pure3d::scenegraph::Scenegraph::vfunc_5 (6 B): matches/0x00296100.cpp
// sym: ?vfunc_5@Scenegraph@scenegraph@pure3d@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int pure3d::scenegraph::Scenegraph::vfunc_5() {
    return 2;
}


// 0x00296110 pure3d::scenegraph::Scenegraph::vfunc_3 (3 B): matches/0x00296110.cpp
// sym: ?vfunc_3@Scenegraph@scenegraph@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::scenegraph::Scenegraph::vfunc_3() {
    return true;
}


// 0x00296120 pure3d::scenegraph::Scenegraph::vfunc_6 (17 B): matches/0x00296120.cpp [wrapped: merged class would differ: Scenegraph: empty base]
// sym: ?f6@Scenegraph@fn_00296120@@UAEXII@Z
namespace fn_00296120 {
typedef unsigned int u32_296120;
class Scenegraph {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(u32_296120, u32_296120);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x40 - 4];
    Scenegraph* mChild;
};
void Scenegraph::f6(u32_296120 a, u32_296120 b) {
    if (mChild)
        mChild->f6(a, b);
}
} // namespace fn_00296120


// 0x00296140 pure3d::scenegraph::Scenegraph::vfunc_7 (17 B): matches/0x00296140.cpp
// sym: ?vfunc_7@Scenegraph@scenegraph@pure3d@@UAEDXZ
char pure3d::scenegraph::Scenegraph::vfunc_7() {
    if ((*(pure3d::scenegraph::Scenegraph * *)&this->f_40))
        return (char)((*(pure3d::scenegraph::Scenegraph * *)&this->f_40)->vfunc_7());
    return (char)(true);
}


// 0x00296160 pure3d::scenegraph::Scenegraph::vfunc_8 (81 B): equivalent/0x00296160.cpp
// sym: ?vfunc_8@Scenegraph@scenegraph@pure3d@@UAEXHH@Z @46b4e25d587c @w72bc518a835a
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 2/2)
// pure3d::scenegraph::Scenegraph::vfunc_8 @ 0x00296160
void pure3d::scenegraph::Scenegraph::vfunc_8(hulk_intptr a, int b) {
 if ((*(Child *volatile *)&this->f_40)) {
  (*(*(Device***)&DAT_0052c2ac))->vfunc_15(0);
  void **savedTable = *(void ***)(*(Child *volatile *)&this->f_40);
  typedef void (Child::*Method)(int, int, int);
  ((*(Child *volatile *)&this->f_40)->*(*(Method*)&savedTable[8]))((*(*(Device***)&DAT_0052c2ac))->vfunc_18(0), a, b);
  (*(*(Device***)&DAT_0052c2ac))->vfunc_16(0);
 }
}


// 0x002961c0 pure3d::scenegraph::Scenegraph::vfunc_9 (15 B): matches/0x002961c0.cpp
// sym: ?vfunc_9@Scenegraph@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::Scenegraph::vfunc_9() {
    if ((*(Obj_2961c0 * *)&this->f_40))
        (*(Obj_2961c0 * *)&this->f_40)->f9();
}

namespace fn_f9b7dd8c {

// 0x002961d0 FUN_002961d0 (4 B): matches/0x002961d0.cpp
// sym: ?vfunc_26@CJumpTrack@fn_f9b7dd8c@@UAEIXZ
// Same code shape as 0x00069100 (propagated; names are from that function)
hulk_uintptr CJumpTrack::vfunc_26() {
    return m;
}


// 0x002961e0 FUN_002961e0 (55 B): matches/0x002961e0.cpp
// sym: ?f@A_2961e0@fn_f9b7dd8c@@QAEIIIII@Z
// data: gState_2961e0 = DAT_0052cb98
hulk_uintptr A_2961e0::f(u32_2961e0 a, u32_2961e0 b, u32_2961e0 c, u32_2961e0 d) {
    if (p) {
        (*(int*)&DAT_0052cb98) = 0;
        return p->a15(a, b, 2, c, d);
    }
    return 0;
}


// 0x00296220 FUN_00296220 (76 B): matches/0x00296220.cpp
// sym: ?FUN_00296220@fn_f9b7dd8c@@YAXPAUNode@1@PAUVisitor@1@@Z
void __cdecl FUN_00296220(Node* node, Visitor* visitor) {
    if (node && visitor->accepts(node) == 1) {
        unsigned int n = node->count();
        for (unsigned int i = 0; i < n; ++i)
            FUN_00296220(node->child(i), visitor);
    }
}

} // namespace fn_f9b7dd8c

// 0x00296290 pure3d::scenegraph::DrawableCounter::vfunc_0 (30 B): matches/0x00296290.cpp
// sym: ?vfunc_0@DrawableCounter@scenegraph@pure3d@@UAE_NPAX@Z
bool pure3d::scenegraph::DrawableCounter::vfunc_0(void* __p0) { Visitor_296290 * p = (Visitor_296290 *)__p0;

    if (p && ((Item_296290*)p)->type() == 16)
        ++this->f_04;
    return true;
}

namespace fn_f9b7dd8c {

// 0x002962d0 FUN_002962d0 (30 B): matches/0x002962d0.cpp
// sym: ??0ShaderCallbackVisitor@fn_f9b7dd8c@@QAE@PAX@Z
ShaderCallbackVisitor::ShaderCallbackVisitor(void* p) : mThing(p) {
    if (p)
        ((ShaderCallbackVisitor*)p)->V();
}

} // namespace fn_f9b7dd8c

// 0x00296310 pure3d::scenegraph::ShaderCallbackVisitor::vfunc_0 (63 B): matches/0x00296310.cpp
// sym: ?vfunc_0@ShaderCallbackVisitor@scenegraph@pure3d@@UAE_NPAX@Z
bool pure3d::scenegraph::ShaderCallbackVisitor::vfunc_0(void* __p0) { Node_296310 * p = (Node_296310 *)__p0;

    if (p) {
        if (p->Type() == 0x10 && p->child) {
            Callback_296310* c = (Callback_296310*)p->child;
            if (this->f_04)
                c->f13(this->f_04);
            else
                c->f14();
        }
    }
    return true;
}

namespace fn_f9b7dd8c {

// 0x00296570 pure3d::scenegraph::Node::vfunc_2 (36 B): matches/0x00296570.cpp
// sym: ?vfunc_5@Node_296570@fn_f9b7dd8c@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Node_296570* Node_296570::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042d1ec;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9b7dd8c

// 0x002965a0 pure3d::scenegraph::BranchNode::vfunc_6 (60 B): equivalent/0x002965a0.cpp
// sym: ?vfunc_6@BranchNode@scenegraph@pure3d@@UAEXHH@Z @c5b52a0a66c0 @wdc626214fefd
// STATUS: equivalent (tools/equiv.py level 3: 18240 inputs, branch coverage 6/6)
// pure3d::scenegraph::BranchNode::vfunc_6 @ 0x002965a0
void pure3d::scenegraph::BranchNode::vfunc_6(hulk_intptr __p0, hulk_intptr __p1) { void * a = (void *)__p0; void * b = (void *)__p1;

    if (!((*(char (*)[20])&this->f_04)[12] & 1)) {
        for (unsigned int i = 0; i < this->f_18; ++i)
            (*(Node_2965a0 ** *)&this->f_1c)[i]->vfunc_6(a,b);
    }
}


// 0x002965e0 pure3d::scenegraph::BranchNode::vfunc_7 (52 B): matches/0x002965e0.cpp
// sym: ?vfunc_7@BranchNode@scenegraph@pure3d@@UAE_NXZ
bool pure3d::scenegraph::BranchNode::vfunc_7() {
    if (((*(unsigned char *)&this->f_10) & 1) == 0) {
        uint i = 0;
        if ((*(uint *)&this->f_18) > 0) {
            do {
                if (!(*(Child_2965e0 ** *)&this->f_1c)[i]->f7())
                    return false;
                ++i;
            } while (i < (*(uint *)&this->f_18));
        }
    }
    return true;
}


// 0x00296620 pure3d::scenegraph::BranchNode::vfunc_8 (69 B): matches/0x00296620.cpp
// sym: ?vfunc_8@BranchNode@scenegraph@pure3d@@UAEXHHH@Z
void pure3d::scenegraph::BranchNode::vfunc_8(hulk_intptr a, int b, int c) {
    if (((*(unsigned int *)&this->f_10) & 1) == 0) {
        for (unsigned int i = 0; i < this->f_18; ++i)
            (*(Obj_296620 ** *)&this->f_1c)[i]->f8(a, b, c);
        (*(unsigned int *)&this->f_10) &= 0xfffffff9;
    }
}


// 0x00296670 pure3d::scenegraph::BranchNode::vfunc_9 (44 B): matches/0x00296670.cpp
// sym: ?vfunc_9@BranchNode@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::BranchNode::vfunc_9() {
    (*(unsigned int *)&this->f_10) &= 0xfffffffe;
    for (unsigned int i = 0; i < this->f_18; ++i) {
        struct Child {
            virtual void a();
            virtual void b();
            virtual void c();
            virtual void d();
            virtual void e();
            virtual void f();
            virtual void g();
            virtual void h();
            virtual void i();
            virtual void call();
        };
        ((Child*)(*(void ** *)&this->f_1c)[i])->call();
    }
}


// 0x002966a0 pure3d::scenegraph::BranchNode::vfunc_10 (118 B): equivalent/0x002966a0.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::Node]
// sym: ?vfunc_10@BranchNode@scenegraph@pure3d@fn_002966a0@@UAEXHIHH@Z @1267047345fe @w318a447f3ae0
namespace fn_002966a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2424 inputs, branch coverage 14/14)
// pure3d::scenegraph::BranchNode::vfunc_10 @ 0x002966a0
namespace pure3d {
namespace scenegraph {

class Node {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void vfunc_10(int a, unsigned int mask, int mode, int d);
};

class BranchNode : public Node {
public:
    virtual void vfunc_10(int a, unsigned int mask, int mode, int d);
    char pad04[0x10 - 4];
    unsigned int flags;
    char pad14[4];
    unsigned int childCount;
    Node **children;
};

void BranchNode::vfunc_10(int a, unsigned int mask, int mode, int d)
{
    if (mode == 2) {
        bool skip;
        if ((unsigned char)a == 1) {
            if ((unsigned char)d == 1)
                skip = (flags & mask) == mask;
            else
                skip = false;
        } else {
            skip = (unsigned char)d == 1 && (flags & mask) == 0;
        }
        if (skip)
            return;
        for (unsigned int i = 0; i < childCount; i++)
            children[i]->vfunc_10(a, mask, 2, d);
    }
    Node::vfunc_10(a, mask, mode, d);
}

}
}
} // namespace fn_002966a0


// 0x00296720 pure3d::scenegraph::BranchNode::vfunc_12 (23 B): matches/0x00296720.cpp
// sym: ?vfunc_12@BranchNode@scenegraph@pure3d@@UAEII@Z
unsigned int pure3d::scenegraph::BranchNode::vfunc_12(unsigned int i) {
    if (i < this->f_18)
        return (*(unsigned int * *)&this->f_1c)[i];
    return 0;
}


// 0x00296740 pure3d::scenegraph::BranchNode::vfunc_18 (88 B): matches/0x00296740.cpp
// sym: ?vfunc_18@BranchNode@scenegraph@pure3d@@UAEXPAX@Z
void pure3d::scenegraph::BranchNode::vfunc_18(void* __p0) { Item_296740 * item = (Item_296740 *)__p0;

    if (item) {
        Item_296740** slot = (*(Item_296740 ** *)&this->f_1c) + (*(int *)&this->f_18);
        item->a();
        Item_296740* old = *slot;
        if (old)
            old->b();
        *slot = item;
        ++(*(int *)&this->f_18);
        item->o(this);
        item->k(1, 2, 1, 1);
        item->k(1, 6, 2, 1);
    }
}


// 0x002967a0 pure3d::scenegraph::BranchNode::vfunc_19 (107 B): equivalent/0x002967a0.cpp
// sym: ?vfunc_19@BranchNode@scenegraph@pure3d@@UAEXH@Z @433f599da965 @w7a1d6531c24b
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 12/12)
// pure3d::scenegraph::BranchNode::vfunc_19 @ 0x002967a0
void pure3d::scenegraph::BranchNode::vfunc_19(hulk_intptr __p0) { Node_2967a0 * child = (Node_2967a0 *)__p0;

    int i = (int)this->f_18 - 1;
    if (i < 0)
        return;
    Node_2967a0** list = (*(Node_2967a0 ** *)&this->f_1c);
    while (list[i] != child) {
        i--;
        if (i < 0)
            return;
    }
    if (list[i] != 0) {
        list[i]->Release();
        list[i] = 0;
    }
    for (unsigned int j = i + 1; j < this->f_18; j++) {
        (*(Node_2967a0 ** *)&this->f_1c)[j - 1] = (*(Node_2967a0 ** *)&this->f_1c)[j];
        (*(Node_2967a0 ** *)&this->f_1c)[j] = 0;
    }
    this->f_18--;
}


// 0x00296810 pure3d::scenegraph::TransformNode::vfunc_6 (53 B): equivalent/0x00296810.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::Node; pure3d::scenegraph::TransformNode]
// sym: ?vfunc_6@TransformNode@scenegraph@pure3d@fn_00296810@@UAEXHH@Z @f61e040dd704 @wf0971b3181c5
namespace fn_00296810 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::scenegraph::TransformNode::vfunc_6 @ 0x00296810
namespace pure3d { namespace scenegraph {
struct Node {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int, int);
};
struct BranchNode : Node { void vfunc_6(int, int); };
struct TransformNode : BranchNode {
    char beforeFlags[0x10 - 4];
    unsigned char flags;
    char beforeChild[0xa8 - 0x11];
    Node* child;
    void vfunc_6(int a, int b);
};
void TransformNode::vfunc_6(int a, int b) {
    if ((flags & 1) == 0) {
        if (child) child->vfunc_6(a, b);
        BranchNode::vfunc_6(a, b);
    }
}
}}
} // namespace fn_00296810


// 0x00296850 pure3d::scenegraph::TransformNode::vfunc_7 (81 B): matches/0x00296850.cpp
// sym: ?vfunc_7@TransformNode@scenegraph@pure3d@@UAE_NXZ
 // namespace pure3d
bool pure3d::scenegraph::TransformNode::vfunc_7() {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(struct Obj_296850 * *)&this->f_a8) && !(*(struct Obj_296850 * *)&this->f_a8)->check())
        return false;
    if (!((*(unsigned char *)&this->f_10) & 1)) {
        for (unsigned i = 0; i < this->f_18; ++i)
            if (!((Item_296850*)(*(void ** *)&this->f_1c)[i])->check())
                return false;
    }
    return true;
}


// 0x002968b0 pure3d::scenegraph::TransformNode::vfunc_8 (128 B): matches/0x002968b0.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::TransformNode]
// sym: ?vfunc_8@TransformNode@scenegraph@pure3d@fn_002968b0@@UAEXHHH@Z
namespace fn_002968b0 {
// pure3d::scenegraph::TransformNode::vfunc_8 @ 0x002968b0
// 0x002968b0: TransformNode::vfunc_8: draw the branch under this node's transform

struct Matrix {
    float m[16];
    void FUN_0022ca90(Matrix* a, Matrix* b);
};

struct Part_2968b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetActive(int a, int b);
    char pad04[0xc];
    char ready;
    char FUN_00284ae0();
};

struct Device_2968b0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void PopMatrix(int a);
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void PushMatrix(int a, Matrix* m);
};

struct Context {
    Device_2968b0* device;
};

namespace pure3d {
namespace scenegraph {

class BranchNode {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void vfunc_8(int a, int b, int c);
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual Matrix* Transform();
    char pad04[0xc];
    unsigned char flags;
    char pad11[0x97];
    Part_2968b0* part;
};

class TransformNode : public BranchNode {
public:
    virtual void vfunc_8(int a, int b, int c);
};

void TransformNode::vfunc_8(int a, int b, int c)
{
    Matrix m;
    if (flags & 1)
        return;
    if (part != 0) {
        if (!part->FUN_00284ae0())
            part->SetActive(0, 1);
    }
    m.FUN_0022ca90(Transform(), (Matrix*)a);
    (*(Context**)&DAT_0052c2ac)->device->PushMatrix(0, &m);
    BranchNode::vfunc_8(a, b, c);
    (*(Context**)&DAT_0052c2ac)->device->PopMatrix(0);
}

}
}
} // namespace fn_002968b0


// 0x00296930 pure3d::scenegraph::TransformNode::vfunc_9 (59 B): matches/0x00296930.cpp
// sym: ?vfunc_9@TransformNode@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::TransformNode::vfunc_9() {
    if ((*(Callback_296930 * *)&this->f_a8))
        (*(Callback_296930 * *)&this->f_a8)->f23();
    (*(unsigned int *)&this->f_10) &= 0xfffffffe;
    for (unsigned int i = 0; i < this->f_18; ++i)
        (*(Child_296930 ** *)&this->f_1c)[i]->f9();
}

namespace fn_f9b7dd8c {

// 0x00296970 FUN_00296970 (56 B): equivalent/0x00296970.cpp
// sym: ?FUN_00296970@Owner@fn_f9b7dd8c@@QAEXPAUItem@2@@Z @94c39abfa189 @w0dccd3106ab8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00296970 @ 0x00296970
void Owner::FUN_00296970(Item *replacement) {
    if (replacement) replacement->FUN_00000000();
    if (item) item->FUN_00000004();
    item = replacement;
    if (replacement) ((owners::C_2a77c0 *)replacement)->FUN_002a77c0((hulk_intptr)(Owner *)this);
}

} // namespace fn_f9b7dd8c

// 0x002969b0 pure3d::scenegraph::VisibilityNode::vfunc_6 (50 B): equivalent/0x002969b0.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::Node; pure3d::scenegraph::VisibilityNode]
// sym: ?vfunc_6@VisibilityNode@scenegraph@pure3d@fn_002969b0@@UAEXHH@Z @671b9441c5c9 @w9a2565a7bcc4
namespace fn_002969b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::scenegraph::VisibilityNode::vfunc_6 @ 0x002969b0
namespace pure3d { namespace scenegraph {
struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int,int);
};
struct BranchNode : Node { char pad[8]; void vfunc_6(int,int); };
struct VisibilityNode : BranchNode { char pad2[0x2c - sizeof(BranchNode)]; Node* child; void vfunc_6(int,int); };
void VisibilityNode::vfunc_6(int a,int b) {
 if (!(*((unsigned char*)this + 0x10) & 1)) {
  if (child) child->vfunc_6(a,b);
  BranchNode::vfunc_6(a,b);
 }
}
}}
} // namespace fn_002969b0


// 0x002969f0 pure3d::scenegraph::VisibilityNode::vfunc_7 (81 B): matches/0x002969f0.cpp
// sym: ?vfunc_7@VisibilityNode@scenegraph@pure3d@@UAE_NXZ
bool pure3d::scenegraph::VisibilityNode::vfunc_7() {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(Obj_2969f0 * *)&this->f_2c) && !(*(Obj_2969f0 * *)&this->f_2c)->f22())
        return false;
    if (!((*(unsigned char *)&this->f_10) & 1)) {
        for (unsigned i = 0; i < this->f_18; ++i)
            if (!(*(Obj_2969f0 ** *)&this->f_1c)[i]->f7())
                return false;
    }
    return true;
}


// 0x00296a50 pure3d::scenegraph::VisibilityNode::vfunc_8 (69 B): matches/0x00296a50.cpp [wrapped: merged class would differ: VisibilityNode: field flags: Field(+0x30 unsigned char flags) vs Field(+0x10 unsigned char flags)]
// sym: ?f8@VisibilityNode@fn_00296a50@@UAEXHHH@Z
namespace fn_00296a50 {
class Child_296a50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
    bool check_00284ae0();
};
class BranchNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int, int);
};
class VisibilityNode : public BranchNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int, int);
    char pad[0x0c];
    unsigned char flags;
    char pad2[0x17];
    unsigned char enabled;
    char pad3[0x3];
    Child_296a50* child;
};
void VisibilityNode::f8(int a, int b, int c) {
    if (!(flags & 1)) {
        if (child && !child->check_00284ae0())
            child->f6(0, 1);
        if (enabled == 1)
            BranchNode::f8(a, b, c);
    }
}
} // namespace fn_00296a50


// 0x00296aa0 pure3d::scenegraph::VisibilityNode::vfunc_9 (56 B): matches/0x00296aa0.cpp
// sym: ?vfunc_9@VisibilityNode@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::VisibilityNode::vfunc_9() {
    if ((*(Obj_296aa0 * *)&this->f_2c))
        (*(Obj_296aa0 * *)&this->f_2c)->f23();
    (*(unsigned int *)&this->f_10) &= 0xfffffffe;
    for (unsigned i = 0; i < this->f_18; ++i)
        (*(Obj_296aa0 ** *)&this->f_1c)[i]->f9();
}


// 0x00296ae0 FUN_00296ae0 (50 B): equivalent/0x00296ae0.cpp [wrapped: conflict: Owner]
// sym: ?FUN_00296ae0@Owner@fn_00296ae0@@QAEXPAUItem@2@@Z @c87270f4a767 @w9ad196e16fb4
namespace fn_00296ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00296ae0 @ 0x00296ae0
struct Owner;
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000004();
};
struct Owner {
    char pad[0x2c];
    Item* item;
    void FUN_00296ae0(Item* value);
};
void Owner::FUN_00296ae0(Item* value) {
    if (value) value->FUN_00000000();
    if (item) item->FUN_00000004();
    item = value;
    if (value) ((owners::Thing_2a7cf0 *)value)->FUN_002a7cf0((hulk_intptr)(Owner *)this);
}
} // namespace fn_00296ae0

namespace fn_f9b7dd8c {

// 0x00296b20 pure3d::scenegraph::LeafNode::vfunc_2 (36 B): matches/0x00296b20.cpp
// sym: ?vfunc_5@LeafNode_296b20@fn_f9b7dd8c@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
LeafNode_296b20* LeafNode_296b20::vfunc_5(signed char flags) {
    *(void***)this = Node_296b20_vftable;
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9b7dd8c

// 0x00296b50 FUN_00296b50 (42 B): matches/0x00296b50.cpp
// sym: ?FUN_00296b50@DrawableNode@scenegraph@pure3d@@QAEXXZ
void pure3d::scenegraph::DrawableNode::FUN_00296b50() {
    *(void**)this = (void*)((hulk_intptr)DAT_0042d28c);
    _ReadWriteBarrier();
    if ((*(Ref_296b50 * *)&this->f_18)) {
        (*(Ref_296b50 * *)&this->f_18)->Release();
        (*(Ref_296b50 * *)&this->f_18) = 0;
    }
    *(void**)this = (void*)((hulk_intptr)DAT_0042d1ec);
    ((DrawableNode_nv_296b50*)this)->Finish_0027afd0();
}

namespace fn_f9b7dd8c {

// 0x00296b80 FUN_00296b80 (38 B): matches/0x00296b80.cpp
// sym: ?Set@Owner_296b80@fn_f9b7dd8c@@QAEXPAVItem_296b80@2@@Z
// Same code shape as 0x00059d00 (propagated; names are from that function)
void Owner_296b80::Set(Item_296b80* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x00296bb0 FUN_00296bb0 (36 B): matches/0x00296bb0.cpp
// sym: ??1Obj_296bb0@fn_f9b7dd8c@@QAE@XZ
Obj_296bb0::~Obj_296bb0() {
    vptr = g_vftable_0042d2dc;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_002a35f0();
}

} // namespace fn_f9b7dd8c

// 0x00296be0 pure3d::scenegraph::Scenegraph::vfunc_13 (111 B): equivalent/0x00296be0.cpp
// sym: ?vfunc_13@Scenegraph@scenegraph@pure3d@@UAEXPAX@Z @7a253ea7b863 @wec2ae0f7e7cd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// pure3d::scenegraph::Scenegraph::vfunc_13 @ 0x00296be0
void pure3d::scenegraph::Scenegraph::vfunc_13(void* __p0) { RefCounted_296be0 * newShader = (RefCounted_296be0 *)__p0;

    if (newShader != 0)
        newShader->AddRef();
    if ((*(RefCounted_296be0 * *)&this->f_10) != 0)
        (*(RefCounted_296be0 * *)&this->f_10)->Release();
    (*(RefCounted_296be0 * *)&this->f_10) = newShader;
    if ((*(Scene * *)&this->f_40) != 0) {
        pure3d::scenegraph::ShaderCallbackVisitor_296be0 visitor(newShader);
        FUN_00296220((*(Scene * *)&this->f_40), &visitor);
    }
}


// 0x00296c50 pure3d::scenegraph::Scenegraph::vfunc_14 (88 B): matches/0x00296c50.cpp
// sym: ?vfunc_14@Scenegraph@scenegraph@pure3d@@UAEXXZ
void pure3d::scenegraph::Scenegraph::vfunc_14() {
    if ((*(Ref_296c50 * *)&this->f_10)) {
        (*(Ref_296c50 * *)&this->f_10)->Release();
        (*(Ref_296c50 * *)&this->f_10) = 0;
    }
    if ((*(Ref_296c50 * *)&this->f_40)) {
        Callback_296c50 c;
        c.vt = (void*)((hulk_intptr)DAT_0042d330);
        c.result = 0;
        FUN_00296220((*(Ref_296c50 * *)&this->f_40), &c);
        c.vt = (void*)((hulk_intptr)DAT_0042d330);
        if (c.result)
            ((class Ref_296c50*)c.result)->Release();
    }
}


// 0x00296cb0 pure3d::scenegraph::Scenegraph::vfunc_12 (235 B): equivalent/0x00296cb0.cpp
// sym: ?vfunc_12@Scenegraph@scenegraph@pure3d@@UAEXXZ @fa6c2af766e6 @w3790d160bc1c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::scenegraph::Scenegraph::vfunc_12 @ 0x00296cb0
void pure3d::scenegraph::Scenegraph::vfunc_12() {
 if((*(void * *)&this->f_40)) {
 BoundingVolumeUpdater_296cb0 updater; updater.flag=0;
 for(int i=0;i<6;++i) updater.bounds[i]=0.0f;
 FUN_00296220((*(void * *)&this->f_40),&updater);
 Bounds_296cb0 copy;
 for(int j=0;j<6;++j) copy.v[j]=updater.bounds[j];
 (*(Bounds_296cb0 *)&this->f_14)=copy;
 Sphere_296cb0* result=(*(Bounds_296cb0 *)&this->f_14).FUN_000a8890(reinterpret_cast<Sphere_296cb0*>(&copy));
 (*(Sphere_296cb0 *)&this->f_2c).x=result->x; (*(Sphere_296cb0 *)&this->f_2c).y=result->y; (*(Sphere_296cb0 *)&this->f_2c).z=result->z; (*(Sphere_296cb0 *)&this->f_2c).r=result->r;
 } else {
 for(int k=0;k<6;++k) (*(Bounds_296cb0 *)&this->f_14).v[k]=0.0f;
 (*(Sphere_296cb0 *)&this->f_2c).x=0.0f; (*(Sphere_296cb0 *)&this->f_2c).y=0.0f; (*(Sphere_296cb0 *)&this->f_2c).z=0.0f; (*(Sphere_296cb0 *)&this->f_2c).r=0.0f;
 }
}


// 0x00296de0 pure3d::scenegraph::DrawableCounter::vfunc_1 (31 B): matches/0x00296de0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00296de0@@UAEPAV123@E@Z
namespace fn_00296de0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class Visitor_296de0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0042d324[];
namespace pure3d {
class NonCopyable : public Visitor_296de0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0042d324;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00296de0


// 0x00296e00 pure3d::scenegraph::ShaderCallbackVisitor::vfunc_1 (43 B): matches/0x00296e00.cpp [wrapped: conflict: pure3d::scenegraph::ShaderCallbackVisitor]
// sym: ?vfunc_1@ShaderCallbackVisitor@scenegraph@pure3d@fn_00296e00@@UAEPAU1234@E@Z
namespace fn_00296e00 {
typedef unsigned char byte_296e00;
struct Visitor_296e00 {
    virtual void v0();
    virtual void v1();
};
namespace pure3d {
namespace scenegraph {
struct ShaderCallbackVisitor : Visitor_296e00 {
    void* mThing;
    virtual void vfunc_0();
    virtual ShaderCallbackVisitor* vfunc_1(byte_296e00);
};
extern void* hulk_at_0042d330;
void thunk_FUN_00267090(ShaderCallbackVisitor*);
ShaderCallbackVisitor* ShaderCallbackVisitor::vfunc_1(byte_296e00 param) {
    *(void**)this = &hulk_at_0042d330;
    if (mThing)
        ((Visitor_296e00*)mThing)->v1();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace scenegraph
} // namespace pure3d
} // namespace fn_00296e00


// 0x00296e30 pure3d::scenegraph::BoundingVolumeUpdater::vfunc_1 (31 B): matches/0x00296e30.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00296e30@@UAEPAV123@E@Z
namespace fn_00296e30 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class Visitor_296e30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_0042d33c[];
namespace pure3d {
class NonCopyable : public Visitor_296e30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_0042d33c;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00296e30


// 0x00296e50 pure3d::scenegraph::BoundingVolumeUpdater::vfunc_0 (232 B): equivalent/0x00296e50.cpp [wrapped: conflict: pure3d::scenegraph::BoundingVolumeUpdater]
// sym: ?vfunc_0@BoundingVolumeUpdater@scenegraph@pure3d@fn_00296e50@@UAE_NPAUNode@4@@Z @f0d7628c10c0 @wdd5f87f761cf
namespace fn_00296e50 {
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// pure3d::scenegraph::BoundingVolumeUpdater::vfunc_0 @ 0x00296e50
struct Matrix;
struct Vec_296e50 { float x,y,z; void FUN_0022d210(Matrix*); };
struct Bounds_296e50 { Vec_296e50 low,high; void FUN_000a87f0(Vec_296e50*); void FUN_000f6e90(Bounds_296e50*); };
struct Drawable { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void refresh(); char pad[16]; Bounds_296e50 bounds; };
struct Node { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual int type(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual Matrix* matrix(); char pad[20]; Drawable* drawable; char pad2[12]; unsigned char active; };
namespace pure3d { namespace scenegraph { struct BoundingVolumeUpdater { virtual bool vfunc_0(Node*); virtual void vfunc_1(); unsigned char initialized; char pad[3]; Bounds_296e50 bounds; }; 
bool BoundingVolumeUpdater::vfunc_0(Node* node) {
 if (!node) return true;
 if (node->type()==4) return node->active!=0;
 if (node->type()==16) {
 Drawable* d=node->drawable;
 if(d) {
 Matrix* m=node->matrix();
 d->refresh();
 Bounds_296e50 b=d->bounds;
 b.low.FUN_0022d210(m);
 b.high.FUN_0022d210(m);
 if(initialized==1) { bounds.FUN_000a87f0(&b.low); bounds.FUN_000a87f0(&b.high); }
 else { bounds.FUN_000f6e90(&b); initialized=1; }
 }
 }
 return true;
}
} }
} // namespace fn_00296e50

namespace fn_f9b7dd8c {

// 0x00296fd0 pure3d::scenegraph::DrawableNode::vfunc_2 (63 B): matches/0x00296fd0.cpp
// sym: ?vfunc2@D@fn_f9b7dd8c@@QAEPAV12@E@Z
D* D::vfunc2(unsigned char f) {
    vptr = &hulk_at_0042d28c;
    _ReadWriteBarrier();
    if (a18) {
        a18->Release();
        a18 = 0;
    }
    vptr = &vt2;
    Fini_0027afd0();
    if (f & 1)
        Free_00263f30(this);
    return this;
}


// 0x00297010 FUN_00297010 (104 B): matches/0x00297010.cpp
// sym: ?Build@Obj_297010@fn_f9b7dd8c@@QAEPAV12@PAV12@@Z
Obj_297010* Obj_297010::Build(Obj_297010* src) {
    ((Base_297010*)this)->Init_0027b070();
    vptr = ((hulk_intptr)DAT_0042d1ec);
    x[3] = src->x[3];
    x[4] = src->x[4];
    ((Name_297010*)((char*)this + 8))->Copy_0027af70((Name_297010*)((char*)src + 8));
    vptr = ((hulk_intptr)DAT_0042d28c);
    c = 0;
    if (src->c) {
        Child_297010* p = src->c->Get();
        if (p)
            p->Destroy();
        if (c)
            c->Release();
        c = p;
    }
    return this;
}

} // namespace fn_f9b7dd8c

// 0x00297080 pure3d::scenegraph::DrawableNode::vfunc_4 (31 B): matches/0x00297080.cpp
// sym: ?vfunc_4@DrawableNode@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::DrawableNode::vfunc_4() {
    void* p = alloc_00263ea0(0x20);
    if (p)
        return (void*)(((Helper_297080*)p)->run_00297010(this));
    return (void*)(0);
}


// 0x002970a0 pure3d::scenegraph::Scenegraph::vfunc_2 (57 B): matches/0x002970a0.cpp [wrapped: merged class would differ: Scenegraph: empty base]
// sym: ?vfunc_2@Scenegraph@fn_002970a0@@UAEPAV12@E@Z
namespace fn_002970a0 {
extern "C" char DAT_0042d2dc[];
class Obj_2970a0 {
  public:
    virtual void a();
    virtual void b();
};
class Scenegraph {
  public:
    virtual void v0();
    virtual void v1();
    virtual Scenegraph* vfunc_2(unsigned char);
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
    virtual void v13();
    virtual void v14();
    char pad[0x3c];
    Obj_2970a0* volatile mObj;
    void cleanup_002a35f0();
};
void __cdecl thunk_00263f30(Scenegraph*);
Scenegraph* Scenegraph::vfunc_2(unsigned char flag) {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_0042d2dc);
    Obj_2970a0* p = mObj;
    if (p) {
        p->b();
        mObj = 0;
    }
    cleanup_002a35f0();
    if (flag & 1)
        thunk_00263f30(this);
    return this;
}
} // namespace fn_002970a0


// 0x002970e0 FUN_002970e0 (75 B): matches/0x002970e0.cpp [wrapped: merged class would differ: Scenegraph: empty base]
// sym: ??0Scenegraph@fn_002970e0@@QAE@PAUInput@1@@Z
namespace fn_002970e0 {
class Node {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Source {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Node* Get();
};
struct Input {
    char pad[0x40];
    Source* source;
};
class DrawableHierarchy_2970e0 {
  public:
    DrawableHierarchy_2970e0(Input*);
    virtual void vf();
    char pad[0x3c];
};
class Scenegraph : public DrawableHierarchy_2970e0 {
  public:
    Scenegraph(Input*);
    virtual void vf();
    Node* node;
};
Scenegraph::Scenegraph(Input* src) : DrawableHierarchy_2970e0(src) {
    node = 0;
    if (src->source) {
        Node* p = src->source->Get();
        if (p)
            p->AddRef();
        if (node)
            node->Release();
        node = p;
    }
}
} // namespace fn_002970e0

namespace fn_f9b7dd8c {

// 0x00297150 FUN_00297150 (27 B): matches/0x00297150.cpp
// sym: ??0Obj_297150@fn_f9b7dd8c@@QAE@XZ
Obj_297150::Obj_297150() {
    a = 0;
    b = 0x120100;
    c = 0;
    d = 0;
    v = ((hulk_intptr)DAT_0042d348);
}

} // namespace fn_f9b7dd8c

// 0x00297170 pure3d::scenegraph::ScenegraphLoader::vfunc_2 (31 B): matches/0x00297170.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_00297170@@UAEPAV123@E@Z
namespace fn_00297170 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_297170 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_297170 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00297170


// 0x002971f0 FUN_002971f0 (229 B): equivalent/0x002971f0.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::Node]
// sym: ?FUN_002971f0@BranchNode@scenegraph@pure3d@fn_002971f0@@QAEPAU1234@PBU1234@@Z @fc3d72d92018 @w6ddb59ab8b57
inline void* operator new(size_t, void* p) { return p; }
namespace fn_002971f0 {
// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 12/12)
// FUN_002971f0 @ 0x002971f0
typedef unsigned int uint;

extern "C" void* __cdecl FUN_0008d6d0(uint);
struct Item_2971f0 {
 virtual void AddRef(); virtual void Release(); virtual void v2(); virtual void v3(); virtual Item_2971f0* Clone(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void Configure(int,int,int,int); virtual void v11(); virtual void v12(); virtual void v13(); virtual void SetParent(void*);
};
struct Small_2971f0 { uint a,b; void FUN_0027af70(const Small_2971f0*); };
namespace pure3d { namespace scenegraph {
struct Node {
 virtual void v0();
 uint field4; Small_2971f0 small; uint field10,field14;
 void FUN_0027b070();
};
struct BranchNode: Node {
 virtual void v0();
 uint count; Item_2971f0** items; Item_2971f0** end;
 BranchNode* FUN_002971f0(const BranchNode* source);
};
}}
pure3d::scenegraph::BranchNode* pure3d::scenegraph::BranchNode::FUN_002971f0(const BranchNode* source) {
 FUN_0027b070();
 new(this) Node;
 field10=source->field10; field14=source->field14;
 small.FUN_0027af70(&source->small);
 new(this) BranchNode;
 count=0;
 uint size=source->count*4;
 if(source->count>0) { items=(Item_2971f0**)FUN_0008d6d0(size); if(items) end=(Item_2971f0**)((char*)items+size); else {items=0;end=0;} }
 else {items=0;end=0;}
 for(uint i=0;i<source->count;++i) {
 items[i]=0;
 Item_2971f0* item=source->items[i]->Clone();
 if(item) {
 Item_2971f0** slot=items+count;
 item->AddRef();
 if(*slot) (*slot)->Release();
 *slot=item; ++count;
 item->SetParent(this);
 item->Configure(1,2,1,1);
 item->Configure(1,6,2,1);
 }
 }
 return this;
}
} // namespace fn_002971f0

namespace fn_f9b7dd8c {

// 0x002972e0 FUN_002972e0 (102 B): matches/0x002972e0.cpp
// sym: ??0BranchNode@fn_f9b7dd8c@@QAE@I@Z
BranchNode::BranchNode(unsigned int n) {
    m18 = 0;
    if (n > 0) {
        m1c = (int**)operator new(n * 4);
        if (m1c)
            m20 = m1c + n;
        else {
            m1c = 0;
            m20 = 0;
        }
    } else {
        m1c = 0;
        m20 = 0;
    }
    for (unsigned int i = 0; i < n; i++)
        m1c[i] = 0;
}

} // namespace fn_f9b7dd8c

// 0x00297350 FUN_00297350 (84 B): matches/0x00297350.cpp [wrapped: conflict: D]
// sym: ??1D@fn_00297350@@QAE@XZ
namespace fn_00297350 {
extern int hulk_at_0042d364, vt2;
extern void Free_0008d340(void*);
class Ref_297350 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_297350 {
  public:
    void* vptr;
    ~Root_297350() throw();
};
class D : public Root_297350 {
  public:
    char p[0x14];
    unsigned n;
    Ref_297350** arr;
    ~D() throw();
};
D::~D() throw() {
    vptr = &hulk_at_0042d364;
    for (unsigned i = 0; i < n; i++) {
        Ref_297350** pp = &arr[i];
        Ref_297350* r = *pp;
        if (r) {
            r->Release();
            *pp = 0;
        }
    }
    if (arr)
        Free_0008d340(arr);
    vptr = &vt2;
}
} // namespace fn_00297350


// 0x002973b0 pure3d::scenegraph::BranchNode::vfunc_4 (31 B): matches/0x002973b0.cpp
// sym: ?vfunc_4@BranchNode@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::BranchNode::vfunc_4() {
    Helper_2973b0* p = (Helper_2973b0*)thunk_FUN_0008d690(0x28);
    if (p)
        return (void*)(p->Fnf_002971f0(this));
    return (void*)(0);
}


// 0x002973d0 FUN_002973d0 (132 B): equivalent/0x002973d0.cpp [wrapped: conflict: pure3d::scenegraph::BranchNode; pure3d::scenegraph::TransformNode]
// sym: ??0TransformNode@scenegraph@pure3d@fn_002973d0@@QAE@ABV0123@@Z @a723c9d103d0 @w22afc52b84c0
namespace fn_002973d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002973d0 @ 0x002973d0
struct Matrix {
    float m[16];
};

class Child_2973d0;
namespace pure3d {
namespace scenegraph {

class TransformNode;

// equiv-map: ??0BranchNode@scenegraph@pure3d@@QAE@ABV012@@Z = 0x002971f0
class BranchNode {
public:
    BranchNode(const BranchNode &source) throw();
    virtual void v0();
    virtual void v1();
    char pad04[0x24];
};

class Child_2973d0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Child_2973d0 *Clone();
    void FUN_002a77c0(TransformNode *parent);
};

class TransformNode : public BranchNode {
public:
    Matrix local;
    Matrix world;
    Child_2973d0 *child;
    TransformNode(const TransformNode &source) throw();
    virtual void v0();
};

TransformNode::TransformNode(const TransformNode &source) throw() : BranchNode(source)
{
    child = 0;
    local = source.local;
    world = source.world;
    if (source.child != 0) {
        Child_2973d0 *clone = source.child->Clone();
        if (clone != 0)
            clone->AddRef();
        if (child != 0)
            child->Release();
        child = clone;
        if (clone != 0)
            clone->FUN_002a77c0(this);
    }
}

}
}
} // namespace fn_002973d0

namespace fn_f9b7dd8c {

// 0x00297460 FUN_00297460 (51 B): matches/0x00297460.cpp
// sym: ?Init@TransformNode@fn_f9b7dd8c@@QAEPAV12@I@Z
TransformNode* TransformNode::Init(u32_297460 arg) {
    ((Base_297460*)this)->Init_002972e0(arg);
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042d3bc);
    field = 0;
    a.Init_0022b980();
    b.Init_0022b980();
    return this;
}


// 0x002974a0 FUN_002974a0 (42 B): matches/0x002974a0.cpp
// sym: ??1TransformNode_2974a0@fn_f9b7dd8c@@QAE@XZ
TransformNode_2974a0::~TransformNode_2974a0() throw() {
    vptr = &hulk_at_0042d3bc;
    _ReadWriteBarrier();
    if (aa8) {
        aa8->Release();
        aa8 = 0;
    }
}

} // namespace fn_f9b7dd8c

// 0x002974d0 pure3d::scenegraph::TransformNode::vfunc_4 (34 B): matches/0x002974d0.cpp
// sym: ?vfunc_4@TransformNode@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::TransformNode::vfunc_4() {
    void* p = alloc_00263ea0(0xb0);
    if (p)
        return (void*)(((Helper_2974d0*)p)->call_002973d0(this));
    return (void*)(0);
}


// 0x00297500 FUN_00297500 (93 B): equivalent/0x00297500.cpp [wrapped: conflict: VisibilityNode]
// sym: ??0VisibilityNode@fn_00297500@@QAE@PAU01@@Z @4ded69796c84 @w29d88180d3e7
namespace fn_00297500 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00297500 @ 0x00297500
struct VisibilityNode;
struct Resource {
    virtual void addRef();
    virtual void release();
    virtual void reserved2();
    virtual void reserved3();
    virtual Resource* clone();
};
struct BranchNode_297500 {};
struct VisibilityNode : BranchNode_297500 {
    virtual void reserved0();
    char pad[0x24];
    unsigned char visible;
    char pad2[3];
    Resource* resource;
    VisibilityNode* FUN_002971f0(VisibilityNode* other);
    VisibilityNode(VisibilityNode* other);
};
VisibilityNode::VisibilityNode(VisibilityNode* other)
    : BranchNode_297500((FUN_002971f0(other), BranchNode_297500())) {
    visible = other->visible;
    resource = 0;
    if (other->resource) {
        Resource* copy = other->resource->clone();
        if (copy) copy->addRef();
        if (resource) resource->release();
        resource = copy;
        if (copy) ((owners::Thing_2a7cf0 *)copy)->FUN_002a7cf0((hulk_intptr)(VisibilityNode *)this);
    }
}
} // namespace fn_00297500


// 0x00297560 FUN_00297560 (36 B): matches/0x00297560.cpp [wrapped: merged class would differ: VisibilityNode: field enabled: Field(+0x48 unsigned char enabled) vs Field(+0x28 unsigned char enabled)]
// sym: ?Init@VisibilityNode@fn_00297560@@QAEPAV12@H@Z
namespace fn_00297560 {
extern void* VisibilityNode_vftable;
class VisibilityNode {
  public:
    char pad[0x28];
    unsigned char enabled;
    int value;
    VisibilityNode* FUN_002972e0(int);
    VisibilityNode* Init(int);
};
VisibilityNode* VisibilityNode::Init(int x) {
    FUN_002972e0(x);
    *(void**)this = &VisibilityNode_vftable;
    enabled = 1;
    value = 0;
    return this;
}
} // namespace fn_00297560

namespace fn_f9b7dd8c {

// 0x00297590 FUN_00297590 (36 B): matches/0x00297590.cpp
// sym: ??1VisibilityNode_297590@fn_f9b7dd8c@@QAE@XZ
VisibilityNode_297590::~VisibilityNode_297590() throw() {
    vptr = &hulk_at_0042d414;
    _ReadWriteBarrier();
    if (a2c) {
        a2c->Release();
        a2c = 0;
    }
}

} // namespace fn_f9b7dd8c

// 0x002975c0 pure3d::scenegraph::VisibilityNode::vfunc_4 (31 B): matches/0x002975c0.cpp
// sym: ?vfunc_4@VisibilityNode@scenegraph@pure3d@@UAEPAXXZ
void* pure3d::scenegraph::VisibilityNode::vfunc_4() {
    void* p = alloc_00263ea0(0x30);
    if (p)
        return (void*)(((Other_2975c0*)p)->helper_00297500(this));
    return (void*)(0);
}


// 0x002975e0 pure3d::scenegraph::BranchNode::vfunc_2 (30 B): matches/0x002975e0.cpp
// sym: ??_GBranchNode@scenegraph@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::scenegraph::BranchNode::~BranchNode() {}

namespace fn_f9b7dd8c {

// 0x00297600 pure3d::scenegraph::TransformNode::vfunc_2 (63 B): matches/0x00297600.cpp
// sym: ?vfunc_2@TransformNode@fn_f9b7dd8c@@QAEPAV12@I@Z
TransformNode* TransformNode::vfunc_2(unsigned int p) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0042d3bc);
    Ref_297600* r = *(Ref_297600* volatile*)&ref;
    if (r) {
        r->f1();
        ref = 0;
    }
    helper_00297350();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f9b7dd8c

// 0x00297640 pure3d::scenegraph::VisibilityNode::vfunc_2 (57 B): matches/0x00297640.cpp [wrapped: conflict: VisibilityNode]
// sym: ?vfunc_2@VisibilityNode@fn_00297640@@UAEPAV12@E@Z
namespace fn_00297640 {
extern "C" void _ReadWriteBarrier();
class Ref_297640 {
  public:
    virtual void a();
    virtual void b();
};
extern int vt_297640;
class VisibilityNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual VisibilityNode* vfunc_2(unsigned char);
    char pad[0x28];
    Ref_297640* member;
    void cleanup_00297350();
};
void thunk_00263f30(VisibilityNode*);
VisibilityNode* VisibilityNode::vfunc_2(unsigned char flag) {
    *(void**)this = &vt_297640;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    cleanup_00297350();
    if (flag & 1)
        thunk_00263f30(this);
    return this;
}
} // namespace fn_00297640

namespace fn_f9b7dd8c {

// 0x00297680 FUN_00297680 (1277 B): equivalent/0x00297680.cpp
// sym: ?FUN_00297680@SceneLoader_297680@fn_f9b7dd8c@@QAEPAVNode_297680@2@PAUStream_297680@2@PAX@Z @bcb98329b581 @w331239085155
// STATUS: equivalent (tools/equiv.py level 3: 20136 inputs, branch coverage 49/51, incomplete)
// FUN_00297680 @ 0x00297680
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
Node_297680 *SceneLoader_297680::FUN_00297680(Stream_297680 *s, void *ctx)
{
    Frame_297680 f;
    f.self = this;
    Node_297680 *node = 0;
    int id = s->FUN_00266c30();

    switch (id) {
    case 0x12010b: {
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        s->FUN_00266a30();
        node = FUN_00297680(s, ctx);
        s->FUN_00266be0();
        return node;
    }
    case 0x12010c: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x28);
        NodeA_297680 *a = 0;
        if (mem)
            a = ((NodeA_297680 *)mem)->FUN_002972e0(f.x);
        a->name.FUN_0027b040(f.name);
        node = a;
        while (s->FUN_002669f0()) {
            s->FUN_00266a30();
            node->AddChild(FUN_00297680(s, ctx));
            s->FUN_00266be0();
        }
        return node;
    }
    case 0x12010d: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0xb0);
        NodeB_297680 *b = 0;
        if (mem)
            b = ((NodeB_297680 *)mem)->FUN_00297460(f.x);
        b->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0((void *)b->FUN_001a4990(), 0x10, 4, 1);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() != 0x121201) {
                b->AddChild(FUN_00297680(s, ctx));
            } else {
                FrameControllerLoader_297680 *fl =
                    dynamic_cast<FrameControllerLoader_297680 *>((*(Registry_297680**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->v0();
                f.fc = 0;
                fl->v5(&f.fc, &f.id, s, ctx);
                if (f.fc) {
                    SceneGraphTransformAnimationController_297680 *tc =
                        dynamic_cast<SceneGraphTransformAnimationController_297680 *>(f.fc);
                    if (tc) {
                        tc->v5(b);
                        b->FUN_00296970(tc);
                    } else if (f.fc) {
                        f.fc->v1();
                        f.fc = 0;
                    }
                }
                fl->v1();
            }
            s->FUN_00266be0();
        }
        return b;
    }
    case 0x12010e: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x30);
        NodeC_297680 *c = 0;
        if (mem)
            c = ((NodeC_297680 *)mem)->FUN_00297560(f.x);
        c->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        c->flag28 = (f.x != 0);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() != 0x121201) {
                c->AddChild(FUN_00297680(s, ctx));
            } else {
                FrameControllerLoader_297680 *fl =
                    dynamic_cast<FrameControllerLoader_297680 *>((*(Registry_297680**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->v0();
                f.fc = 0;
                fl->v5(&f.fc, &f.id, s, ctx);
                if (f.fc) {
                    SceneGraphVisibilityAnimationController_297680 *vc =
                        dynamic_cast<SceneGraphVisibilityAnimationController_297680 *>(f.fc);
                    if (vc) {
                        vc->v5(c);
                        c->FUN_00296ae0(vc);
                    } else if (f.fc) {
                        f.fc->v1();
                        f.fc = 0;
                    }
                }
                fl->v1();
            }
            s->FUN_00266be0();
        }
        return c;
    }
    case 0x12010f: {
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        bool flag = ((hulk_intptr)f.self != 0);
        s->FUN_000f9600(f.name);
        void *mem = thunk_FUN_0008d690(0x20);
        pure3d::scenegraph::DrawableNode *h = 0;
        if (mem)
            h = ((DrawableNode_nv_297680*)(((pure3d::scenegraph::DrawableNode *)mem)))->FUN_00295fd0();
        ((HolderName_297680 *)h)->name.FUN_0027b040(f.name);
        s->FUN_000f9600(f.name);
        DrawableHierarchy_297680 *dh = FUN_000c0de0(ctx, f.name);
        if (dh && flag == 1)
            dh = dh->h4();
        ((DrawableNode_nv_297680*)(h))->FUN_00296b80(dh);
        return (Node_297680 *)h;
    }
    default:
        return 0;
    }
}

} // namespace fn_f9b7dd8c

// 0x00297ba0 FUN_00297ba0 (862 B): equivalent/0x00297ba0.cpp [wrapped: conflict: FUN_000c0de0; Node; pure3d::DrawableContainer; pure3d::DrawableHierarchy]
// sym: ?FUN_00297ba0@SceneLoader_297ba0@fn_00297ba0@@QAEPAVNode@2@PAUStream@2@PAX@Z @a3205ec08339 @w1be330bb790c
namespace fn_00297ba0 {
// STATUS: equivalent (tools/equiv.py level 3: 3075 inputs, branch coverage 37/37)
// FUN_00297ba0 @ 0x00297ba0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);

struct Name_297ba0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
    char *FUN_000f9600(char *out);
};

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
    virtual void AddChild(Node *child);
    char pad04[4];
    Name_297ba0 name;
};

class NodeA_297ba0 : public Node {
public:
    char pad[0x28 - 0x10];
    NodeA_297ba0 *FUN_002972e0(int v);
};

class NodeB_297ba0 : public Node {
public:
    char pad[0xb0 - 0x10];
    NodeB_297ba0 *FUN_00297460(int v);
    hulk_intptr FUN_001a4990();
};

class NodeC_297ba0 : public Node {
public:
    char pad[0x28 - 0x10];
    bool flag28;
    char pad29[0x30 - 0x29];
    NodeC_297ba0 *FUN_00297560(int v);
};

namespace pure3d {
class DrawableHierarchy {
public:
    virtual void h0();
    virtual void h1();
};
class DrawableContainer : public DrawableHierarchy {
public:
    virtual void c0();
};
}

struct Holder_297ba0 {
    char pad00[0x18];
    void *child18;
    Holder_297ba0 *FUN_00295fd0();
    char pad1c[4];
    char name8[0];
    void FUN_00296b80(pure3d::DrawableHierarchy *h);
};

struct HolderName_297ba0 {
    char pad[8];
    Name_297ba0 name;
};

pure3d::DrawableHierarchy *FUN_000c0de0(void *ctx, char *name);

struct Frame_297ba0 {
    int x;
    char name[0x100];
};

class SceneLoader_297ba0 {
public:
    Node *FUN_00297ba0(Stream *s, void *ctx);
};

Node *SceneLoader_297ba0::FUN_00297ba0(Stream *s, void *ctx)
{
    Frame_297ba0 f;
    Node *node = 0;
    int id = s->FUN_00266c30();

    switch (id - 0x120101) {
    case 0: {
        s->FUN_00266a30();
        node = FUN_00297ba0(s, ctx);
        s->FUN_00266be0();
        return node;
    }
    case 1: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x28);
        NodeA_297ba0 *a = 0;
        if (mem)
            a = ((NodeA_297ba0 *)mem)->FUN_002972e0(f.x);
        a->name.FUN_0027b040(f.name);
        node = a;
        break;
    }
    case 2: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0xb0);
        NodeB_297ba0 *b = 0;
        if (mem)
            b = ((NodeB_297ba0 *)mem)->FUN_00297460(f.x);
        b->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0((void *)b->FUN_001a4990(), 0x10, 4, 1);
        node = b;
        break;
    }
    case 3: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x30);
        NodeC_297ba0 *c = 0;
        if (mem)
            c = ((NodeC_297ba0 *)mem)->FUN_00297560(f.x);
        c->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        c->flag28 = (f.x != 0);
        node = c;
        break;
    }
    case 6: {
        void *mem = thunk_FUN_0008d690(0x20);
        Holder_297ba0 *h = 0;
        if (mem)
            h = ((Holder_297ba0 *)mem)->FUN_00295fd0();
        s->FUN_000f9600(f.name);
        ((HolderName_297ba0 *)h)->name.FUN_0027b040(f.name);
        s->FUN_000f9600(f.name);
        pure3d::DrawableHierarchy *dh = FUN_000c0de0(ctx, f.name);
        h->FUN_00296b80(dh);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() == 0x12010a) {
                s->reader->FUN_002647e0(&f.x, 1, 4, 1);
                dynamic_cast<pure3d::DrawableContainer *>(dh);
            }
            s->FUN_00266be0();
        }
        return (Node *)h;
    }
    default:
        return 0;
    case 4:
    case 5:
        return 0;
    }

    while (s->FUN_002669f0()) {
        s->FUN_00266a30();
        node->AddChild(FUN_00297ba0(s, ctx));
        s->FUN_00266be0();
    }
    return node;
}
} // namespace fn_00297ba0


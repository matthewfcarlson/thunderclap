// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002742f0..0x00274350 (kind game, layer engine, confidence high), dominant class core::FileCancelRequest
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f18422f1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f18422f1 {} using namespace fn_f18422f1;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f18422f1 {
struct P_2742f0;
struct Sub_2742f0 {
    virtual void a();
    virtual void b();
};
struct Inner_2742f0 {
    void run_00272b70(P_2742f0* p, int v);
};
struct P_2742f0 {
    int x;
    Sub_2742f0 s;
    int a;
    Inner_2742f0* i;
    int c;
    int d;
};
class pddiObject_274330 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_274330 : public pddiObject_274330 {};
class pddiBaseShader_274330 : public pddiShader_274330 {
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
class d3dShader_274330 : public pddiBaseShader_274330 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_f18422f1

// 0x002742f0 core::FileCancelRequest::vfunc_1 (59 B): matches/0x002742f0.cpp
// sym: ?vfunc_1@FileCancelRequest@core@@UAEHXZ
int core::FileCancelRequest::vfunc_1() {
    (*(P_2742f0 * *)&this->f_08)->i->run_00272b70((*(P_2742f0 * *)&this->f_08), (*(P_2742f0 * *)&this->f_08)->c);
    (*(P_2742f0 * *)&this->f_08)->s.a();
    (*(P_2742f0 * *)&this->f_08)->d = 0;
    (*(P_2742f0 * *)&this->f_08)->s.b();
    return 1;
}


// 0x00274330 core::FileCancelRequest::vfunc_4 (6 B): matches/0x00274330.cpp
// sym: ?vfunc_4@FileCancelRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::FileCancelRequest::vfunc_4() {
    return 1;
}


// 0x00274340 core::FileCancelRequest::vfunc_6 (6 B): matches/0x00274340.cpp
// sym: ?vfunc_6@FileCancelRequest@core@@UAEHXZ
// Same code shape as 0x00234fa0 (propagated; names are from that function)
int core::FileCancelRequest::vfunc_6() {
    return 9;
}


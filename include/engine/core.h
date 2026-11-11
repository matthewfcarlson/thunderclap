// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_CORE_H
#define TREE_ENGINE_CORE_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "compat/ptr.h"
#include "common.h"
TREE_TU_BEGIN
void __cdecl Init();
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned char vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
extern "C" void FUN_0026d830(void*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
TREE_TU_END
extern "C" void _ReadWriteBarrier();
TREE_TU_BEGIN
extern void* vDrive[];
extern void* vD4[];
extern void* vDc[];
extern void* vSafe[];
extern void* vBase[];
class IBase {
  public:
    virtual void w0();
    virtual void w1();
    virtual void v2(int);
};
void FUN_002702a0(void** out, int a, int b, int c, int d, hulk_intptr e, int f);
extern void* vFileCompletion;
extern void* vRequest;
extern "C" char DAT_0042b9bc[];
extern void* request_vftable[];
extern "C" char DAT_0042b9dc[];
void FinishInit();
extern "C" void InitMore();
TREE_TU_END
#endif

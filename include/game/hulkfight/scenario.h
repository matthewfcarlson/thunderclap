// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_GAME_HULKFIGHT_SCENARIO_H
#define TREE_GAME_HULKFIGHT_SCENARIO_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
TREE_TU_BEGIN
extern "C" void FUN_00234810(void*, void*);
void thunk_FUN_00267090(void*);
extern char DAT_00491ca8;
extern char DAT_0049850c;
TREE_TU_END
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
void* __cdecl operator new(size_t size);
void* operator new(size_t) HULK_NEW_THROW;
TREE_TU_BEGIN
struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
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
TREE_TU_END
#endif

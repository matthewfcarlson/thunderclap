// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
#ifndef TREE_ENGINE_OM_H
#define TREE_ENGINE_OM_H
#ifndef TREE_TU_BEGIN
#define TREE_TU_BEGIN
#define TREE_TU_END
#endif
#include "common.h"
TREE_TU_BEGIN
extern void* corevt[];
extern void cleanup(void*);
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
TREE_TU_END
#endif

#include "decls/data/engine/core.h"

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
class IRefCount {
  public:
    virtual void F();
};
void FUN_00364780() {
    (*(IRefCount**)&DAT_004cdb4c) = (IRefCount*)((hulk_intptr)DAT_003f6098);
}
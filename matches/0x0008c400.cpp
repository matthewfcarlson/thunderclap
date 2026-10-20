#include "compat/ptr.h"
extern "C" char DAT_004004f4[];
class CMemoryCardManager {
  public:
    void* vtable;
    int x;
    void* field8;
};
void __cdecl thunk_FUN_00267090(void*);
void __fastcall target(CMemoryCardManager* self) {
    void* value = self->field8;
    self->vtable = (void*)((hulk_intptr)DAT_004004f4);
    thunk_FUN_00267090(value);
    self->field8 = 0;
}
#include "compat/ptr.h"
class Chunk {
  public:
    char pad[0x28];
    int field;
    void Init(int);
};
extern int vtable_23b540;
Chunk* __fastcall Build(Chunk* self) {
    self->Init(3);
    *(hulk_intptr*)self = (hulk_intptr)&vtable_23b540;
    self->field = 0;
    return self;
}
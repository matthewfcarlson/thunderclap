#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" char DAT_0042a850[];
struct Inner_25cc70 {
    void Setup();
};
void Register(void*, void*);
class OmHalStream {
  public:
    hulk_intptr vf;
    char pad[0x1b8];
    Inner_25cc70 inner;
    OmHalStream* Init(unsigned char flag);
};
OmHalStream* OmHalStream::Init(unsigned char flag) {
    vf = ((hulk_intptr)DAT_0042a850);
    inner.Setup();
    if (flag & 1)
        Register((void*)((hulk_intptr)DAT_004e7808), this);
    return this;
}

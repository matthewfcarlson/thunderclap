#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

extern "C" char DAT_0042a850[];
struct Inner_25cc70 {
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
    ((owners::Str_240060 *)&inner)->FUN_00240060();
    if (flag & 1)
        Register((void*)((hulk_intptr)DAT_004e7808), this);
    return this;
}

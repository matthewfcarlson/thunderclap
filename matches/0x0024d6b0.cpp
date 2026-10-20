#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_00429440[];
struct ListenerEffectXBoxType_nv_24d6b0 {
    void FUN_002584d0(void*, void*, void*, int);
};
class X_24d6b0 {
  public:
    int m;
    X_24d6b0();
};
X_24d6b0::X_24d6b0() {
    ((ListenerEffectXBoxType_nv_24d6b0*)(((audio::ListenerEffectXBoxType*)this)))->FUN_002584d0((void*)((int)DAT_004e6338), (void*)((int)DAT_004e6330), (void*)0x30, 4);
    m = ((int)DAT_00429440);
}
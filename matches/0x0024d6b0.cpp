#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

extern "C" char DAT_00429440[];
struct ListenerEffectXBoxType_nv_24d6b0 {
    void FUN_002584d0(void*, void*, void*, int);
};
class TypeT_24d6b0 {
  public:
    hulk_intptr m;
    TypeT_24d6b0();
};
TypeT_24d6b0::TypeT_24d6b0() {
    HULK_SIZE32(OmMetaTypeAttribScalarFloat, 0x30);
    ((ListenerEffectXBoxType_nv_24d6b0*)(((audio::ListenerEffectXBoxType*)(((audio::ListenerEffectXBoxType*)this)))))->FUN_002584d0((void*)((hulk_intptr)DAT_004e6338), (void*)((hulk_intptr)DAT_004e6330), (void*)sizeof(OmMetaTypeAttribScalarFloat), (int)__alignof(OmMetaTypeAttribScalarFloat));
    m = ((hulk_intptr)DAT_00429440);
}
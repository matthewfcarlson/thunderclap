#include "decls/data/engine/audio.h"
// data: gTarget = DAT_004e6ed8

extern "C" int __cdecl atexit(void (*)(void));
extern "C" void __cdecl FUN_003644d0();
class SeqEventVarVolumeType_3606d0 {
  public:
    void FUN_002528b0();
};
void __cdecl FUN_003606d0() {
    (*(SeqEventVarVolumeType_3606d0*)&DAT_004e6ed8).FUN_002528b0();
    atexit(FUN_003644d0);
}

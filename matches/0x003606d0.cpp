#include "decls/data/engine/audio.h"
// data: gTarget = DAT_004e6ed8

extern "C" int __cdecl atexit(void (*)(void));
extern "C" void __cdecl FUN_003644d0();
class SeqEventVarVolumeType_3606d0 {
  public:
    void Run();
};
void __cdecl FUN_003606d0() {
    (*(SeqEventVarVolumeType_3606d0*)&DAT_004e6ed8).Run();
    atexit(FUN_003644d0);
}
